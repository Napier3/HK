/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1998 - 1998, All Rights Reserved				*/
/*									*/
/* MODULE NAME : s_defvl.c						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	_mvl_process_defvlist_ind					*/
/*	mvlas_defvlist_resp						*/
/*	mplas_defvlist_resp						*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------	*/
/* 09/21/01  JRB     12    Alloc global bufs only once at startup.	*/
/* 01/21/00  MDE     11    Now use MEM_SMEM for dynamic memory		*/
/* 09/13/99  MDE     10    Added SD_CONST modifiers			*/
/* 01/20/99  JRB     09    Use new mvl_nvl_add (simpler, more efficient)*/
/* 01/14/99  JRB     08    BUG FIX: Increment variable_list in loop.	*/
/* 12/11/98  MDE     07    Removed scope references from VA		*/
/* 11/16/98  MDE     06    Allow use of manufactured variables		*/
/* 11/16/98  MDE     05    Renamed internal functions (prefix '_')	*/
/* 07/09/98  JRB     04    Set altAcc=NULL (no alternate access).	*/
/* 06/15/98  MDE     03    Changes to allow compile under C++		*/
/* 06/05/98  MDE     02    Moved 'mvl_insert_nvlist' elsewhere 		*/
/* 04/14/98  JRB     01    MMS-LITE V4.0 Release			*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"
#include "mms_pfil.h"
#include "mvl_defs.h"
#include "mvl_log.h"

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/*			_mvl_process_defvlist_ind				*/
/* A "defvlist" indication has been received, process it and respond	*/
/************************************************************************/

ST_VOID _mvl_process_defvlist_ind (MVL_IND_PEND *indCtrl)
  {
  indCtrl->u.defvlist.req_info =
        (DEFVLIST_REQ_INFO *) indCtrl->event->u.mms.dec_rslt.data_ptr;

  u_mvl_defvlist_ind (indCtrl);
  }

/************************************************************************/
/*			mvlas_defvlist_resp				*/
/* Most of this code doesn't care whether the Named Variable List is	*/
/* VMD-specific, Dom-specific, etc.					*/
/************************************************************************/
ST_VOID mvlas_defvlist_resp (MVL_IND_PEND *indCtrl)
  {
MVL_NVLIST_CTRL *nvlist_ctrl;	/* alloc, fill in, & then copy to list	*/
ST_INT j;
VARIABLE_LIST *variable_list;
DEFVLIST_REQ_INFO *req_info = indCtrl->u.defvlist.req_info;
OBJECT_NAME *tmp_obj_array;

  if (req_info->num_of_variables <= 0)
    {
    _mplas_err_resp (indCtrl,4,0);	/* Service error , other	*/
    return;
    }

  variable_list = (VARIABLE_LIST *) (req_info + 1);
  
  /* Create temporary obj array from var list to pass to mvl_nvl_add.	*/
  tmp_obj_array = M_MALLOC (MSMEM_GEN, req_info->num_of_variables * sizeof (OBJECT_NAME));
  for (j = 0;  j < req_info->num_of_variables;  j++, variable_list++)
    memcpy (&tmp_obj_array [j], &variable_list->var_spec.vs.name, sizeof (OBJECT_NAME));

  /* NOTE: Use "obj_name.vmd_spec" for an object of any scope,		*/
  /* because "obj_name" is a union of identical type objects.		*/
  nvlist_ctrl = mvl_nvl_add (&req_info->vl_name, indCtrl->event->net_info,
                    req_info->num_of_variables, tmp_obj_array,
                    SD_TRUE);	/* copy name because it is volatile	*/

  M_FREE (MSMEM_GEN, tmp_obj_array);	/* free temporary object array.	*/

  if (nvlist_ctrl == NULL)
    {			   		/* Failed.			*/
    _mplas_err_resp (indCtrl,4,0);	/* Service error, other	*/
    return;
    }

  nvlist_ctrl->mms_deletable = SD_TRUE;	/* MMS spec requires this*/
  nvlist_ctrl->altAcc = NULL;		/* Don't support alternate access*/

  mplas_defvlist_resp (indCtrl);
  }


/************************************************************************/
/*			mplas_defvlist_resp				*/
/************************************************************************/
ST_VOID mplas_defvlist_resp (MVL_IND_PEND *indCtrl)
  {
ST_RET rc;

  /* Build a "defvlist" response (no response info).			*/
  rc = mpl_defvlist_resp (indCtrl->event->u.mms.dec_rslt.id);
  _mvl_send_resp_i (indCtrl, rc);
  }

