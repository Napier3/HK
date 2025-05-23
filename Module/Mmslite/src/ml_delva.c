/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER	*****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*		       1997 All Rights Reserved				*/
/*									*/
/* MODULE NAME : ml_delva.c						*/
/* PRODUCT(S)  : MMS-EASE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION	LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     03    Remove "thisFileName"                    	*/
/* 09/13/99  MDE     02    Added SD_CONST modifiers			*/
/* 06/09/97  MDE     01    Created from existing MLOG source		*/
/************************************************************************/


#include "glbtypes.h"
#include "sysincs.h"

#ifndef MMS_LITE
#include "mms_usr.h"		/* to access MMS fucntions, variables   */
#else
#include "mmsdefs.h"
#endif
#include "mloguser.h"

/************************************************************************/
/************************************************************************/
/* m_log_delvar_req                                                     */
/************************************************************************/


ST_VOID m_log_delvar_req (DELVAR_REQ_INFO *info)
  {
OBJECT_NAME *obj_ptr;
ST_INT j;

  switch (info->scope)
    {
    case 0 :
      MLOG_CALWAYS1 ("Scope of Delete = %d, Specific",info->scope);
      break;
    case 1 :
      MLOG_CALWAYS1 ("Scope of Delete = %d, AA-specific",info->scope);
      break;
    case 2 :
      MLOG_CALWAYS1 ("Scope of Delete = %d, Domain",info->scope);
      break;
    case 3 :
      MLOG_CALWAYS1 ("Scope of Delete = %d, VMD",info->scope);
      break;
    }
  if ( info->dname_pres )
    {
    MLOG_CALWAYS1 ("Domain Name : %s ", info->dname);
    }
  else
    {
    MLOG_CALWAYS0 ("Domain Name : Not Present ");
    }
  if ( info->vnames_pres )
    {
    MLOG_CALWAYS1 ("Variable Names : %d ", info->num_of_vnames);
    obj_ptr = (OBJECT_NAME *) (info + 1);
    for (j = 0; j < info->num_of_vnames; j++)
      {
      m_log_objname (obj_ptr);
      obj_ptr++;
      }
    }
  else
    {
    MLOG_CALWAYS0 ("Variable Names : Not Present ");
    }

  }


/************************************************************************/
/* m_log_delvar_resp                                                 */
/************************************************************************/


ST_VOID m_log_delvar_resp (DELVAR_RESP_INFO *info)
  {
  MLOG_CALWAYS1 ("Number Matched : %ld",info->num_matched);
  MLOG_CALWAYS1 ("Number Deleted : %ld",info->num_deleted);
  }


