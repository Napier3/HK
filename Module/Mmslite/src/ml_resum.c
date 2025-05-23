/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER	*****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*		       1997 All Rights Reserved				*/
/*									*/
/* MODULE NAME : ml_resum.c						*/
/* PRODUCT(S)  : MMS-EASE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION	LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     04    Remove "thisFileName"                    	*/
/* 10/14/03  JRB     03    Del unnecessary casts.			*/
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
/* m_log_resume_req                                                     */
/************************************************************************/


ST_VOID m_log_resume_req (RESUME_REQ_INFO *info)
  {
EXTERN_INFO ext;

  MLOG_CALWAYS1 ("Program Invocation Name : %s", info->piname);
  MLOG_CALWAYS0 ("Resume Argument : ");

  if (info->resume_arg_pres)
    {
    if (info->resume_arg_type == ARG_TYPE_ENCODED)
      {
      MLOG_CALWAYS0 ("ENCODED Resume ARG");
#if 1
      if (!ms_decode_extern (info->resume_arg, info->resume_arg_len,&ext))
        {
        MLOG_CALWAYS0 ("Resume Argument Follows:");
        m_log_external (&ext);
        }
      else
        {
        MLOG_CALWAYS0 ("EXTERNAL Decode Error Follows:");
        MLOG_ALWAYSH (info->resume_arg_len, info->resume_arg);
        }
#else
      MLOG_ALWAYSH (info->resume_arg_len, info->resume_arg);
#endif
      }
    else
      {
      MLOG_CALWAYS1 ("Resume Argument : %s", info->resume_arg);
      }
    }
  else
    {
    MLOG_CALWAYS0 ("Resume Argument : Not Present");
    }

  }



