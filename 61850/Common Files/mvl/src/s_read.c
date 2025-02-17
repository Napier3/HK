/*******************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	1994 - 1996, All Rights Reserved		        */
/*									*/
/* MODULE NAME : s_read.c    						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	NONE								*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 12/12/02  JRB     23    Add net_info arg to mvl_get_va_asn1_data &	*/
/*			   prep_.. functions to elim use of		*/
/*			   mvl_curr_net_info global var.		*/
/* 07/24/02  JRB     22    Use mvl_send_resp_i like ALL responses.	*/
/* 07/09/02  MDE     21    Add maxpend_ind support			*/
/* 02/25/02  MDE     20    Now get max PDU size from mvl_cfg_info	*/
/* 09/21/01  JRB     19    Alloc global bufs only once at startup.	*/
/* 03/30/01  MDE     18    Changed MSMEM_ENC_INFO to MSMEM_ENC_OS_INFO	*/
/* 10/25/00  JRB     17    Del u_mvl funct ptrs. Call functs directly.	*/
/*			   Control with #ifdefs.			*/
/* 06/19/00  JRB     16    Free rdCtrl->vaCtrlTbl on error.		*/
/* 05/15/00  MDE     15    Added MMS statistics				*/
/* 03/10/00  JRB     14    Copy va_scope to appropriate structures.	*/
/* 01/21/00  MDE     13    Now use MEM_SMEM for dynamic memory		*/
/* 11/22/99  JRB     12    mvlas_read_resp: del indCtrl from link list	*/
/* 09/13/99  MDE     11    Added SD_CONST modifiers			*/
/* 04/07/99  MDE     10    Logging improvements				*/
/* 01/15/99  JRB     09    IF (u_mvl_get_nvl_fun != NULL) call it,	*/
/*			   ELSE call "mvl_find_nvl".			*/
/* 12/11/98  MDE     08    Removed scope references from VA		*/
/* 11/16/98  MDE     07    Renamed internal functions (prefix '_')	*/
/* 11/10/98  MDE     06    Moved 'mvl_get_va_asn1_data' to mvl_var.c	*/
/* 06/15/98  MDE     05    Changes to allow compile under C++		*/
/* 05/15/98  JRB     04    Chg mvl_process.. arg to (MVL_IND_PEND *).	*/
/* 05/15/98  JRB     03    Call u_mvl_read_ind direct (no funct ptr).	*/
/* 02/10/98  MDE     02    Removed NEST_RT_TYPES, always support AA,	*/
/*			   added 'u_mvl_rd_ind_start' and 		*/
/*         		   'u_mvl_rd_resp_sent', other			*/
/* 09/10/97  MDE     01    MMS-LITE V4.0 Release			*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mvl_acse.h"
#include "mvl_log.h"


/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif



/************************************************************************/
/************************************************************************/

ST_RET (*u_mvl_rd_ind_start) (MVL_IND_PEND *indCtrl);
ST_VOID (*u_mvl_rd_resp_sent) (MVL_IND_PEND *indCtrl);

/************************************************************************/
/************************************************************************/
/* Internal functions							*/

static ST_RET prep_lov_rd_ctrl (READ_REQ_INFO *read_info, 
				MVLAS_READ_CTRL *rdCtrlOut);
static ST_RET prep_nvl_rd_ctrl (MVL_NET_INFO *net_info, READ_REQ_INFO *read_info, 
				MVLAS_READ_CTRL *rdCtrlOut);
static ST_RET prep_read_resp (MVL_NET_INFO *net_info, MVLAS_READ_CTRL *rdCtrl,
                          READ_RESP_INFO **resp_info_out, 
                          ST_UCHAR *asn1_buf, ST_INT asn1_buf_size);

/************************************************************************/
/************************************************************************/
/*			_mvl_process_read_ind				*/
/************************************************************************/

ST_VOID _mvl_process_read_ind (MVL_IND_PEND *indCtrl)
  {
READ_REQ_INFO   *read_info;
MVLAS_READ_CTRL *rdCtrl;
ST_RET rc;

  rdCtrl = &indCtrl->u.rd;
  read_info = (READ_REQ_INFO *) indCtrl->event->u.mms.dec_rslt.data_ptr;
  rdCtrl->var_acc_tag = read_info->va_spec.var_acc_tag;

  rc = SD_SUCCESS;
  if (u_mvl_rd_ind_start)
    {
    rc = (*u_mvl_rd_ind_start) (indCtrl);
    _mvl_curr_usr_ind_ctrl = indCtrl->usr_ind_ctrl;
    }

  if (rc == SD_SUCCESS)
    {
    if (rdCtrl->var_acc_tag == VAR_ACC_NAMEDLIST)
      rc = prep_nvl_rd_ctrl (indCtrl->event->net_info, read_info, rdCtrl);
    else
      rc = prep_lov_rd_ctrl (read_info, rdCtrl);
    }

  if (rc == SD_SUCCESS)
    {
    u_mvl_read_ind (indCtrl);
    }
  else  
    {
    _mplas_err_resp (indCtrl,7,2);
    }
  }

/************************************************************************/
/*			prep_lov_rd_ctrl				*/
/************************************************************************/

static ST_RET prep_lov_rd_ctrl (READ_REQ_INFO *read_info, 
				MVLAS_READ_CTRL *rdCtrl)
  {
MVLAS_RD_VA_CTRL *vaCtrl;
VARIABLE_LIST *vl;
MVL_VAR_ASSOC *va;
ST_INT num_var;
ST_INT i;   
ST_BOOLEAN alt_access_pres;
ST_BOOLEAN alt_access_done;

  /* This is a list of variables */
  /* Simply ignore the 'spec_in_result' parameter for now		*/

  /* Allocate the read control data structures */
  num_var = read_info->va_spec.num_of_variables;
  rdCtrl->vaCtrlTbl = (MVLAS_RD_VA_CTRL *) M_CALLOC (MSMEM_GEN, num_var, 
					sizeof(MVLAS_RD_VA_CTRL));
  vaCtrl = rdCtrl->vaCtrlTbl;
  rdCtrl->numVar = num_var;

  /* Prepare to process each variable in the list			*/
  vl = (VARIABLE_LIST *) (read_info + 1);
  for (i = 0; i < num_var; ++i, ++vl, ++vaCtrl)
    {
  /* These are done by the 'chk_calloc' call */
  /*  vaCtrl->va = NULL;		     */
  /*  vaCtrl->alt_access_pres = SD_FALSE;    */
    vaCtrl->acc_rslt_tag = ACC_RSLT_SUCCESS;


    alt_access_pres = vl->alt_access_pres;
    if (alt_access_pres)  /* no alternate access support now	*/
      {
#if !defined(MVL_AA_SUPP)
      mvl_log_err ("Read Indication : Alternate Access not supported");
      continue;
#else
  /* now create the AA, given the ASN.1 spec				*/
      if (ms_asn1_to_aa (vl->alt_access.data, vl->alt_access.len, 
             	         &vaCtrl->alt_acc))
        {
        mvl_log_err ("Read Indication : ASN.1 -> AA failure");
        continue;
        }
      vaCtrl->alt_access_pres = SD_TRUE;
#endif
      }

    switch (vl->var_spec.var_spec_tag)
      {
      case VA_SPEC_NAMED :
        va = _mvl_objname_to_va (MMSOP_READ, &vl->var_spec.vs.name, 
	    		        &vaCtrl->va_scope,
	    		        alt_access_pres,
	    		        &vaCtrl->alt_acc,
	    		        &alt_access_done);

        if (alt_access_pres && alt_access_done)
          {
          M_FREE (MSMEM_GEN, vaCtrl->alt_acc.aa);
          vaCtrl->alt_access_pres = SD_FALSE;
          alt_access_pres = SD_FALSE;
          }

        if (!va)  /* could not find variable association	*/
      	  {
#if defined(MVL_AA_SUPP)
          if (alt_access_pres)
            {
            M_FREE (MSMEM_GEN, vaCtrl->alt_acc.aa);
            vaCtrl->alt_access_pres = SD_FALSE;
            }
#endif
          MVL_LOG_NERR1 ("Read ind : Variable Association '%s' not found", 
				vl->var_spec.vs.name.obj_name.vmd_spec);
          continue;
    	  }

        vaCtrl->va = va;
        va->usr_ind_ctrl = _mvl_curr_usr_ind_ctrl;
      break;
    
      default :
        mvl_log_err ("Read: Invalid VarSpecTag");
        M_FREE (MSMEM_GEN, rdCtrl->vaCtrlTbl);
        return (MVL_ERR_VA_SPEC);
      break;
      }
    }
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			prep_nvl_rd_ctrl				*/
/************************************************************************/

static ST_RET prep_nvl_rd_ctrl (MVL_NET_INFO *net_info, READ_REQ_INFO *read_info, 
				MVLAS_READ_CTRL *rdCtrl)
  {
MVL_NVLIST_CTRL *nvList;
MVLAS_RD_VA_CTRL *vaCtrl;
ST_INT i;
ST_INT num_var;

/* search for the NVL */
#if defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)
  nvList = u_mvl_get_nvl (MMSOP_READ, &read_info->va_spec.vl_name, 
				 net_info);
#else	/* default	*/
  nvList = mvl_find_nvl (&read_info->va_spec.vl_name);
#endif	/* default	*/

  if (!nvList)
    {  
    mvl_log_err ("Read NVL : NamedVariableList not found");
    return (MVL_ERR_NVL_NOT_FOUND);
    }
  rdCtrl->nvList = nvList;

/* Found the named variable list, create the response */
  num_var = nvList->num_of_entries;
  rdCtrl->vaCtrlTbl = (MVLAS_RD_VA_CTRL *) M_CALLOC (MSMEM_GEN, num_var, 
					sizeof(MVLAS_RD_VA_CTRL));
  vaCtrl = rdCtrl->vaCtrlTbl;
  rdCtrl->numVar = num_var;

  for (i = 0; i < num_var; ++i, ++vaCtrl)
    {
  /* These are done by the 'chk_calloc' call */
  /*  vaCtrl->va = NULL;		     */
  /*  vaCtrl->alt_access_pres = NULL;	     */
    vaCtrl->va = nvList->entries[i];
    memcpy (&vaCtrl->va_scope, &nvList->va_scope[i], sizeof(MVL_SCOPE));
    vaCtrl->acc_rslt_tag = ACC_RSLT_SUCCESS;
    vaCtrl->va->usr_ind_ctrl = _mvl_curr_usr_ind_ctrl;
    }
  return (SD_SUCCESS);
  }

/************************************************************************/
/************************************************************************/
/*				mvlas_read_resp				*/
/************************************************************************/

ST_RET mvlas_read_resp (MVL_IND_PEND *indCtrl)
  {
MVLAS_READ_CTRL *rdCtrl;
MVL_COMM_EVENT *event;
MVL_NET_INFO *net_info; 
READ_RESP_INFO  *resp_info;
ST_UCHAR *asn1_buf;
ST_RET rc;

  event = indCtrl->event;
  net_info = indCtrl->event->net_info;
  rdCtrl = &indCtrl->u.rd;

  asn1_buf = M_MALLOC (MSMEM_ASN1_DATA_ENC, mvl_cfg_info->max_msg_size);
  rc = prep_read_resp (net_info, rdCtrl, &resp_info, asn1_buf, mvl_cfg_info->max_msg_size);

  if (rc == SD_SUCCESS)
    {
    /* Build the read response 				*/
    rc = mpl_read_resp (event->u.mms.dec_rslt.id, resp_info);

  /* Log the response */
    MVL_LOG_RESP (MMSOP_READ, resp_info);

   /* The process functions allocate the response buffer		*/
    M_FREE (MSMEM_ENC_OS_INFO, resp_info);
    }

#if defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)
  if (rdCtrl->nvList)	/* For NVL, this was allocated by prep_nvl_...	*/
    u_mvl_free_nvl (MMSOP_READ, rdCtrl->nvList, event->net_info);
#endif	/* defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)	*/

  if (u_mvl_rd_resp_sent)
    (*u_mvl_rd_resp_sent) (indCtrl);

  M_FREE (MSMEM_ASN1_DATA_ENC, asn1_buf);
  M_FREE (MSMEM_GEN, rdCtrl->vaCtrlTbl);

  /* NOTE: This funct frees indCtrl. DO NOT use after this.	*/
  /* NOTE: if rc != SD_SUCCESS, this funct sends error resp.	*/
  _mvl_send_resp_i (indCtrl, rc);

  return (SD_SUCCESS);
  }

/************************************************************************/
/*			prep_read_resp					*/
/************************************************************************/

static ST_RET prep_read_resp (MVL_NET_INFO *net_info, MVLAS_READ_CTRL *rdCtrl,
                          READ_RESP_INFO **resp_info_out, 
                          ST_UCHAR *asn1_buf, ST_INT asn1_buf_size) 
  {
MVLAS_RD_VA_CTRL *vaCtrl;
MVL_VAR_ASSOC *va;
READ_RESP_INFO  *resp_info;
ACCESS_RESULT   *ar_ptr;
ST_UCHAR *asn1_start;
ST_INT asn1_len;
ST_INT asn1_buf_left;
ST_INT num_var;
ST_INT i;   

/* This is a list of variables 						*/
/* Simply ignore the 'spec_in_result' parameter for now			*/

  num_var = rdCtrl->numVar;
  resp_info = 
    (READ_RESP_INFO  *) M_CALLOC (MSMEM_ENC_OS_INFO, 1, sizeof (READ_RESP_INFO) + 
                      		    (num_var * sizeof (ACCESS_RESULT)));
  *resp_info_out = resp_info;

/* Create a read response info struct	*/
  resp_info->va_spec_pres = 0;  
  resp_info->num_of_acc_result = num_var;  
  resp_info->acc_rslt_list = (ACCESS_RESULT *) (resp_info+1);  

  ar_ptr = resp_info->acc_rslt_list;
  asn1_start = asn1_buf;
  asn1_buf_left = asn1_buf_size;
  vaCtrl = rdCtrl->vaCtrlTbl;
  for (i = 0; i < num_var; ++i, ++ar_ptr, ++vaCtrl)
    {
  /* Assume that it will fail, for ease of coding */
    ar_ptr->acc_rslt_tag = ACC_RSLT_FAILURE;
    ar_ptr->failure = ARE_TYPE_INCONSISTENT;

    va = vaCtrl->va;
    if (va == NULL)
      continue;

/* Sanity check, because foundry can generate configured variables w/o	*/
/* the data pointer initialized.					*/
    if (va->data == NULL)
      { 
      MVL_LOG_NERR1 ("Read Indication : va '%s' data is NULL", va->name);
      continue;
      }

    if (vaCtrl->acc_rslt_tag == ACC_RSLT_SUCCESS)
      {
      if (mvl_get_va_asn1_data (net_info,
				va, vaCtrl->alt_access_pres, &vaCtrl->alt_acc, 
				asn1_start, asn1_buf_left, &asn1_len) ==
                                                                 SD_SUCCESS)
        {
        ar_ptr->acc_rslt_tag = ACC_RSLT_SUCCESS; 
        ar_ptr->va_data.len = asn1_len;
        ar_ptr->va_data.data = asn1_start;
      
        asn1_buf_left -= asn1_len;   /* adjust buffer control variables	*/
        asn1_start += asn1_len;
        }
      }
    else
      ar_ptr->failure = vaCtrl->failure;

    if (vaCtrl->acc_rslt_tag == ACC_RSLT_SUCCESS)
      ++mvl_mms_statistics.serverVarRdOk;
    else
      ++mvl_mms_statistics.serverVarRdErr;

  /* The user needs to free a manufactured NVL and the associated VA's	*/
  /* in the 'u_mvl_free_va_fun'; here just free manufactured variables	*/
  /* associated with a list of variables.				*/
#if defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)
    if (rdCtrl->var_acc_tag == VAR_ACC_VARLIST)
      {
      if (vaCtrl->va && vaCtrl->va->va_to_free != NULL)
        u_mvl_free_va (MMSOP_READ, va, net_info);
      }
#endif	/* defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)	*/

#if defined(MVL_AA_SUPP)
    if (vaCtrl->alt_access_pres) /* if we calloc'd this AA, free it	*/
      M_FREE (MSMEM_GEN, vaCtrl->alt_acc.aa);
#endif
    }

  return (SD_SUCCESS);
  }
