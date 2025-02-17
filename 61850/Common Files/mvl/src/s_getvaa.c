/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	1994 - 2002, All Rights Reserved		        */
/*									*/
/* MODULE NAME : s_getvaa.c    						*/
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
/* 06/29/04  JRB     17    Improve NERR log msg.			*/
/* 03/13/03  JRB     16    Use mvl_type_ctrl_find.			*/
/* 02/25/02  MDE     15    Now get max PDU size from mvl_cfg_info	*/
/* 01/02/02  JRB     14    Converted to use ASN1R (re-entrant ASN1)	*/
/* 09/21/01  JRB     13    Alloc global bufs only once at startup.	*/
/* 10/25/00  JRB     12    Del u_mvl funct ptrs. Call functs directly.	*/
/*			   Control with #ifdefs.			*/
/* 01/21/00  MDE     11    Now use MEM_SMEM for dynamic memory		*/
/* 09/13/99  MDE     10    Added SD_CONST modifiers			*/
/* 04/07/99  MDE     09    Logging improvements				*/
/* 12/11/98  MDE     08    Removed scope references from VA		*/
/* 12/11/98  MDE     07    Now use 'va_to_free' as manufactured flag	*/
/* 11/16/98  MDE     06    Renamed internal functions (prefix '_')	*/
/* 08/06/98  JRB     05    Use mmsl_max_msg_size to encode type_spec.	*/
/* 06/15/98  MDE     04    Changes to allow compile under C++		*/
/* 05/14/98  JRB     03    Use MVL_IND_PEND. Add mplas resp function.	*/
/* 02/10/98  MDE     02    Removed NEST_RT_TYPES, use _mvl_call_get_va	*/
/* 09/10/97  MDE     01    MMS-LITE V4.0 Release			*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"
#include "mms_pvmd.h"
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
/*			_mvl_process_getvaa_ind				*/
/* A 'Get Variable Access Attributes' indication has been received, 	*/
/* process it and respond						*/
/************************************************************************/

ST_VOID _mvl_process_getvaa_ind (MVL_IND_PEND *indCtrl)
  {
  indCtrl->u.getvar.req_info =
        (GETVAR_REQ_INFO *) indCtrl->event->u.mms.dec_rslt.data_ptr;

  u_mvl_getvar_ind (indCtrl);
  }

/************************************************************************/
/*			mvlas_getvar_resp				*/
/************************************************************************/
ST_VOID mvlas_getvar_resp (MVL_IND_PEND *indCtrl)
  {
GETVAR_REQ_INFO  *req_info;
GETVAR_RESP_INFO  resp_info;
MVL_VAR_ASSOC *va;
ST_RET rc;
#if defined(MVL_DYN_ASN1_TYPES)
ST_UCHAR *asn1_buf;
ST_INT asn1_len;
ST_UCHAR *asn1_start;
#endif
ASN1_ENC_CTXT localEncCtx;	/* For readability, use "aCtx" to access this.*/
ASN1_ENC_CTXT *aCtx = &localEncCtx;
MVL_TYPE_CTRL *type_ctrl = NULL;

  req_info = indCtrl->u.getvar.req_info;

#if defined(MVL_DYN_ASN1_TYPES)
  asn1_buf = M_MALLOC (MSMEM_ASN1_DATA_ENC, mvl_cfg_info->max_msg_size);
#endif

  rc = SD_FAILURE;
  if (req_info->req_tag == 0)  /* Object Name */
    {
    va = _mvl_objname_to_va (MMSOP_GET_VAR, &req_info->name, 
                                     NULL,
          		       	     SD_FALSE,
          		       	     NULL,
          		       	     NULL);

    if (va)
      {
      resp_info.mms_deletable = SD_FALSE;
      resp_info.address_pres = SD_FALSE;

#if !defined(MVL_DYN_ASN1_TYPES)
  /* DEBUG: this code doesn't work with dynamic type creation because	*/
  /*        "asn1_len" & "asn1" never set in mvl_type_ctrl.		*/
  /* Here we assume that the ASN.1 is available and we can just return	*/
  /* it. This is good for systems with few types.			*/
      resp_info.type_spec.len  = mvl_type_ctrl[va->type_id].asn1_len;
      resp_info.type_spec.data = mvl_type_ctrl[va->type_id].asn1;
      rc = SD_SUCCESS;
#else
  /* We will derive the ASN.1 directly from the runtime type.		*/
  /* This takes a bit more code, but if we have Lot's of types we can	*/
  /* save space.							*/

#ifdef _MVL_TYPE_CTRL_use_one_device_
      type_ctrl = mvl_type_ctrl_find (va->type_id, type_ctrl);	/* find type	*/
#else
      type_ctrl = mvl_type_ctrl_find (va->type_id);	/* find type	*/
#endif

      asn1r_strt_asn1_bld (aCtx, asn1_buf, mvl_cfg_info->max_msg_size);
      rc = ms_runtime_to_asn1 (aCtx, type_ctrl->rt, type_ctrl->num_rt);
      if (rc == SD_SUCCESS)
        {
        asn1_start = aCtx->asn1r_field_ptr+1;
        asn1_len = (asn1_buf + mvl_cfg_info->max_msg_size) - asn1_start;

        resp_info.type_spec.len  = asn1_len;
        resp_info.type_spec.data = asn1_start;
        }
      else
        {
        MVL_LOG_NERR1 ("GetVarAccAttrib : VarName='%s'. Could not create ASN.1 from RUNTIME. Probably MMS msgsize to small.",
				req_info->name.obj_name.vmd_spec);
        }
#endif

#if defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)
      if (va->va_to_free)
        u_mvl_free_va (MMSOP_GET_VAR, va, _mvl_curr_net_info);
#endif	/* defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)	*/
      }
    else
      {
      MVL_LOG_NERR1 ("GetVarAccAttrib : Variable Association '%s' not found", 
				req_info->name.obj_name.vmd_spec);
      }
    } /* End 'if object (variable name) */

  if (rc != SD_SUCCESS)
    _mplas_err_resp (indCtrl,3,0);	/* resource, other	*/
  else
    {
    indCtrl->u.getvar.resp_info = &resp_info;
    mplas_getvar_resp (indCtrl);
    }

#if defined(MVL_DYN_ASN1_TYPES)
  M_FREE (MSMEM_ASN1_DATA_ENC, asn1_buf);
#endif
  }

/************************************************************************/
/*			mplas_getvar_resp				*/
/************************************************************************/
ST_VOID mplas_getvar_resp (MVL_IND_PEND *indCtrl)
  {
ST_RET rc;

  rc = mpl_getvar_resp (indCtrl->event->u.mms.dec_rslt.id,
                        indCtrl->u.getvar.resp_info);
  _mvl_send_resp_i (indCtrl, rc);
  }
