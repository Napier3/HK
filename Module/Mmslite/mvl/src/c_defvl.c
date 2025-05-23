/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1998 - 1998, All Rights Reserved				*/
/*									*/
/* MODULE NAME : c_defvl.c						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	mvl_defvlist							*/
/*	mvla_defvlist							*/
/*	_mvl_process_defvlist_conf					*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------	*/
/* 04/09/07  MDE     14    Enhanced filtered logging 			*/
/* 11/01/01  JRB     13    mvl_wait_req_done now returns ST_RET.	*/
/* 09/21/01  JRB     12    Alloc global bufs only once at startup.	*/
/* 03/07/01  JRB     11    Del LOCK on sync functs: caused deadlocks.	*/
/* 03/08/00  JRB     10    Del #ifdef MVL_REQ_BUF_ENABLED: not used.	*/
/* 			   Del mvl_free_req_ctrl call. User must call.	*/
/*			   Del invoke_id, numpend_req: see mvl_send_req.*/
/* 01/21/00  MDE     09    Now use MEM_SMEM for dynamic memory		*/
/* 01/21/00  MDE     08    Use '_mvl_get_req_buf' for MVL_REQ_BUF_EN..	*/
/* 11/19/99  NAV     07	   Add #ifdef MVL_REQ_BUF_ENABLED		*/
/* 10/20/99  NAV     06    Add maxpend_req support to aynsc functions	*/
/* 09/13/99  MDE     05    Added SD_CONST modifiers			*/
/* 11/17/98  MDE     04    Now use MVL_ERR_COMM_SERVE_ACTIVE error code	*/
/*			   Use MVL_SYNC_REQ_INTERFACE			*/
/* 11/16/98  MDE     03    Renamed internal functions (prefix '_')	*/
/* 06/15/98  MDE     02    Changes to allow compile under C++		*/
/* 03/27/98  JRB     01    MMS-LITE V4.0 Release			*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "glbsem.h"

#include "mmsdefs.h"
#include "mms_pvmd.h"
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
/*			mvl_defvlist					*/
/************************************************************************/

#if defined(MVL_SYNC_REQ_INTERFACE)

ST_RET mvl_defvlist (
	MVL_NET_INFO  *net_info,
	DEFVLIST_REQ_INFO *req_info,
	MVL_REQ_PEND **req_out)
  {
ST_RET rc;

  if (_mvl_comm_serve_active == SD_TRUE)
    {
    MVL_LOG_NERR0 ("Error: mvl_comm_serv active");
    return (MVL_ERR_COMM_SERVE_ACTIVE);
    }

  rc = mvla_defvlist (net_info, req_info, req_out);
  if (rc == SD_SUCCESS)
    rc = mvl_wait_req_done (*req_out);
  return (rc);
  }                                  

#endif

/************************************************************************/
/*			mvla_defvlist					*/
/************************************************************************/

ST_RET mvla_defvlist (
	MVL_NET_INFO  *net_info,
	DEFVLIST_REQ_INFO *req_info,
	MVL_REQ_PEND **req_out)
  {
ST_RET rc;
MVL_REQ_PEND *req_pend;

  *req_out = req_pend = _mvl_get_req_ctrl (net_info, MMSOP_DEF_VLIST);
  if (!req_pend)
    return (MVL_ERR_REQ_CONTROL);

  S_LOCK_COMMON_RESOURCES ();
  rc = _mvla_send_defvlist (net_info, req_info, req_pend);
  S_UNLOCK_COMMON_RESOURCES ();
  return (rc);
   
  }                                  

/************************************************************************/
/*			_mvl_send_defvlist				*/
/************************************************************************/

ST_RET _mvla_send_defvlist (MVL_NET_INFO  *net_info,
			    DEFVLIST_REQ_INFO *req_info,
			    MVL_REQ_PEND *req_pend)
  {
ST_RET rc;

  /* Build a defvlist request               */
  rc = mpl_defvlist (req_info);
  if (rc == SD_SUCCESS)
    mpl_req_log (req_pend, req_info);

  rc = _mvl_send_req (net_info, req_pend, rc);
  return (rc);
  }

/************************************************************************/
/*			_mvl_process_defvlist_conf			*/
/************************************************************************/

ST_VOID _mvl_process_defvlist_conf (MVL_REQ_PEND *req_pend)
  {
  /* Nothing to do. Common code takes care of setting req_pend->result.	*/
  }

