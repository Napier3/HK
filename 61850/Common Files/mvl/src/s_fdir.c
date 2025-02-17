/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	1994 - 1996, All Rights Reserved		        */
/*									*/
/* MODULE NAME : s_fdir.c    						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	_mvl_process_fdir_ind						*/
/*	mplas_fdir_resp							*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 09/21/01  JRB     11    Alloc global bufs only once at startup.	*/
/* 03/30/01  MDE     10    Changed MSMEM_ENC_INFO to MSMEM_ENC_OS_INFO	*/
/* 09/13/00  JRB     09    Compute resp_info size (don't use const).	*/
/* 01/21/00  MDE     08    Now use MEM_SMEM for dynamic memory		*/
/* 09/13/99  MDE     07    Added SD_CONST modifiers			*/
/* 04/01/99  MDE     06    Changes to decode buffer allocation scheme   */
/* 11/16/98  MDE     05    Renamed internal functions (prefix '_')	*/
/* 09/21/98  MDE     04    Minor lint cleanup				*/
/* 06/15/98  MDE     03    Changes to allow compile under C++		*/
/* 05/14/98  JRB     02    Use MVL_IND_PEND. Add mvlas resp function.	*/
/* 09/10/97  MDE     01    MMS-LITE V4.0 Release			*/
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
/************************************************************************/
/*			_mvl_process_fdir_ind				*/
/* A fdir indication has been received, process it and respond	*/
/************************************************************************/

ST_VOID _mvl_process_fdir_ind (MVL_IND_PEND *indCtrl)
  {
FDIR_REQ_INFO *req_info;
FILE_NAME *fs_fname;	/* ptr to array of FILE_NAME for "fs"	*/
FILE_NAME *ca_fname;	/* ptr to array of FILE_NAME for "ca"	*/
MVLAS_FDIR_CTRL *fdir;

  fdir = &indCtrl->u.fdir;

  req_info = (FDIR_REQ_INFO *) indCtrl->event->u.mms.dec_rslt.data_ptr;

  /* fs_fname array is right after req_info			*/
  fs_fname = (FILE_NAME *)(req_info + 1);
  /* ca_fname array is right after fs_fname array		*/
  ca_fname = fs_fname + req_info->num_of_fs_fname;

  if (req_info->filespec_pres)
    {
    if (_mvl_concat_filename (fdir->fs_filename, req_info->num_of_fs_fname, 
                      fs_fname, sizeof (fdir->fs_filename)))
      {
      _mplas_err_resp (indCtrl,11,3);	/* File name syntax error	*/
      return;
      }
    }
  else
    fdir->fs_filename[0] = 0;

  if (req_info->cont_after_pres)
    {
    if (_mvl_concat_filename (fdir->ca_filename, req_info->num_of_ca_fname, 
                      ca_fname, sizeof (fdir->ca_filename)))
      {
      _mplas_err_resp (indCtrl,11,3);	/* File name syntax error	*/
      return;
      }
    }
  else
    fdir->ca_filename[0] = 0;

  u_mvl_fdir_ind (indCtrl);
  }

/************************************************************************/
/*			mplas_fdir_resp				*/
/************************************************************************/
ST_VOID mplas_fdir_resp (MVL_IND_PEND *indCtrl)
  {
ST_RET rc;
FDIR_RESP_INFO *resp_info;
ST_UINT resp_size;	/* size of "resp_info"	*/
FDIR_DIR_ENT *fdir_entry;
FILE_NAME *fname;
ST_INT j;
MVL_FDIR_RESP_INFO *mvl_resp_info;

  mvl_resp_info = indCtrl->u.fdir.resp_info;

/* Compute size needed for "resp_info".					*/
/* NOTE: num_of_fname is always 1, so total_num_of_fname = num_dir_ent.	*/
  resp_size = sizeof (FDIR_RESP_INFO)
	        + (mvl_resp_info->num_dir_ent * sizeof (FDIR_DIR_ENT))
		+ (mvl_resp_info->num_dir_ent * sizeof (FILE_NAME));
  resp_info = (FDIR_RESP_INFO *) M_CALLOC (MSMEM_ENC_OS_INFO, 1, resp_size);
     
  resp_info->num_dir_ent = mvl_resp_info->num_dir_ent;
  resp_info->more_follows = mvl_resp_info->more_follows;
  for (j = 0,  fdir_entry = (FDIR_DIR_ENT *) (resp_info + 1);
       j < resp_info->num_dir_ent;  j++)
    {
    fdir_entry->fsize = mvl_resp_info->dir_ent[j].fsize;
    fdir_entry->mtimpres = mvl_resp_info->dir_ent[j].mtimpres;
    fdir_entry->mtime = mvl_resp_info->dir_ent[j].mtime;
    fdir_entry->num_of_fname = 1;	/* we always use 1	*/

    fname = (FILE_NAME *) (fdir_entry + 1);
    fname->fn_len = strlen (mms_string(&mvl_resp_info->dir_ent[j].filename));
    fname->fname = mms_string(&mvl_resp_info->dir_ent[j].filename);

    /* always 1 fname, so point after it to get to next fdir_entry.	*/
    fdir_entry = (FDIR_DIR_ENT *) (fname + 1);
    }

  /* Build a File Directory response 					*/
  rc = mpl_fdir_resp (indCtrl->event->u.mms.dec_rslt.id, resp_info);
  _mvl_send_resp_i (indCtrl, rc);

  M_FREE (MSMEM_ENC_OS_INFO, resp_info);
  }

