/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1995-2004, All Rights Reserved					*/
/*									*/
/* MODULE NAME : acse2enc.c						*/
/* PRODUCT(S)  :							*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	ACSE Encode Functions.						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------  */
/* 09/17/04  JRB    30     a_abort_req: don't access acse_conn after	*/
/*			   copp_u_abort_req (it may have been freed).	*/
/* 08/06/04  EJV    29     Added typecast (ST_UCHAR *) ...password.	*/
/* 03/04/04  JRB    28     Mov thisFil.. after incs, they may define DEBUG_..*/
/*			   Del logging of A-DATA.req (use MVL or COPP)	*/
/* 12/18/03  JRB    27	   If MOSI, use cosp_buf, DON't use acse_buf.	*/
/*			   Use ASN1_ENC_PTR, ASN1_ENC_LEN macros.	*/
/* 10/21/03  JRB    26     Add a_get_event_handles_unix.		*/
/* 08/20/03  EJV    25	   Chg cosp_msgsize to fit larger User Data	*/
/*  			   ACSE_AUTH_ENABLED code wo/define.		*/
/*			   Added security functions.			*/
/*			   Added param to tp4_connect .			*/
/*			   Fix the ACSE Auth encode.			*/
/* 06/17/03  EJV    24	   Added _acse_dib_logstr.			*/
/* 10/22/02  ASK    23	   Wrap ifdef TP0_ENABLED around inet_ntoa calls*/
/* 10/14/02  ASK    22     Added encoding for abort diagnostic.		*/
/* 08/26/02  ASK    21	   Added password mechanism encoding in		*/ 
/*			   a_associate_req and a_associate rsp.		*/
/* 07/16/02  JRB    20     Add tp0_sock.h for sockets/IP defs.		*/
/* 06/26/02  JRB    19     associate_req: Log calling/called address.	*/
/* 01/22/02  JRB    18     Add args to copp_initialize (same as MAP30..)*/
/*			   Del a_set_msgsize (no longer needed).	*/
/* 01/02/02  JRB    17     Converted to use ASN1R (re-entrant ASN1)	*/
/* 06/22/01  JRB    16     Fix a_release_rsp handling of STATE_RESP_COLL*/
/*			   state per ISO 8650 (was kluged before).	*/
/* 03/15/01  JRB    15     Use new SMEM allocation functions.		*/
/* 01/04/01  EJV    14     a_get_event_handles used only on _WIN32	*/
/* 09/24/99  JRB    13     a_get_event_handles not used on		*/
/*                         DOS, QNX or VXWORKS				*/
/* 09/13/99  MDE    12     Added SD_CONST modifiers			*/
/* 08/05/99  JRB    11     Add "a_get_event_handles" function for MOSI.	*/
/* 10/08/98  MDE    10     Migrated to updated SLOG interface		*/
/* 08/13/98  JRB    09     Lint cleanup.				*/
/* 07/10/98  JRB    08     Del *_obj_id, use acse2var.c			*/
/* 03/23/98  NAV    07     Free buffers on termination			*/
/* 02/16/98  JRB    06     Del or "#if out" unused locals.		*/
/* 11/10/97  JRB    05     Chg cosp_buf to (ST_UCHAR *).		*/
/* 09/22/97  JRB    04     acse_msgsize MUST be set before copp_init.	*/
/*			   a_data_req (MOSI): check for buffer overflow	*/
/* 09/04/97  JRB    03     Pass SPDU msgsize arg to tp4_initialize.	*/ 
/* 07/31/97  JRB    02     copp_bind & a_associate_req set "tp_type"	*/
/*			   in tp4_addr. New TP4 needs it.		*/
/* 06/09/97  JRB    01     If !MOSI, on A-ASSOCIATE.rsp-, just set	*/
/*			   state=STATE_IDLE. Don't free as did on 3/7/97*/
/* 05/27/97  JRB   7.00    MMSEASE 7.0 release.				*/
/* 05/02/97  JRB    24     wr_* functs now ret void, so don't check.	*/
/* 04/09/97  JRB    23     a_associate_req return (0L) for any error.	*/
/* 03/19/97  JRB    22     Add MOSI "CALLING" support.			*/
/* 03/19/97  JRB    21     Encode AARQ in a_associate_req: need for MOSI*/
/*			   In a_release_req, chg handling if send fails.*/
/*			   Use acse_free_conn to free conn ctrl struct.	*/
/*			   Improve logging.				*/
/*			   Improve release collision handling.		*/
/* 03/07/97  JRB    20     Always send result-source-diag on AARE.	*/
/*			   Rechecked spec, and this is MANDATORY.	*/
/* 03/07/97  JRB    19     If !MOSI, free acse_conn on negative		*/
/*			   A-Associate.rsp (MOSI frees in COSP).	*/
/* 03/07/97  JRB    18     Use new "acse_free_con" to free acse_conn.	*/
/* 03/07/97  JRB    17     Added MOSI support.				*/
/* 02/11/97  JRB    16     In a_release_rsp, if send fails, don't free	*/
/*			   acse_conn and don't change state.		*/
/* 01/23/97  JRB    15     Init acse_debug_sel in copp_initialize.	*/
/* 11/18/96  JRB    14     Del acse_dummyfun call. Funct is gone now.	*/
/* 11/15/96  JRB    13     Don't initialize globals.			*/
/*			   Move acse_debug_sel global here.		*/
/* 08/19/96  MDE    12     Add dummy a_buffers_avail for Reduced Stack	*/
/* 08/14/96  JRB    11     Add a_buffers_avail function.		*/
/* 07/19/96  JRB    10     Change DEBUG_MMS to DEBUG_SISCO.		*/
/* 07/15/96  JRB    09     Only free acse_conn->aarq_apdu.user_info.ptr	*/
/*			   if len != 0 (wasn't alloc'd otherwise).	*/
/* 05/02/96  JRB    08     Add STATE_TP4CONN_WAIT.			*/
/* 04/23/96  MDE    07     Fixed minor warning              		*/
/* 04/18/96  JRB    06     a_associate_req return acse_conn_id or NULL	*/
/*			   on error, instead of just SD_SUCCESS or error.	*/
/*			   if (acse_conn->state == STATE_AARE_WAIT)	*/
/*			   in a_abort_req, set to STATE_AARE_ABANDON.	*/
/* 03/26/96  MDE    05     Added REDUCED_STACK support			*/
/* 03/11/96  JRB    04     Move acse_msgsize here & use for acse_buf.	*/
/* 03/07/96  JRB    03     Handle aarq_apdu->user_info.len = 0.		*/
/* 01/19/96  JRB    02     Cast constant chars to ST_UCHAR.		*/
/* 10/30/95  JRB    01     Created					*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "asn1defs.h"
#include "acse2.h"
#if defined (MOSI)
#include "cosp_usr.h"
#include "copp_usr.h"
#endif	/* MOSI	*/
#include "tp4api.h"
#include "tp0_sock.h"

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

ST_UINT acse_msgsize;
ST_UINT acse_debug_sel;

#ifdef DEBUG_SISCO
SD_CONST ST_CHAR *SD_CONST _acse_err_logstr = "ACSE_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _acse_enc_logstr = "ACSE_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _acse_dec_logstr = "ACSE_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _acse_dib_logstr = "ACSE_LOG_DIB";

SD_CONST ST_CHAR *SD_CONST _copp_err_logstr = "COPP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _copp_dec_logstr = "COPP_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _copp_dec_hex_logstr = "COPP_LOG_DEC_HEX";
SD_CONST ST_CHAR *SD_CONST _copp_enc_logstr = "COPP_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _copp_enc_hex_logstr = "COPP_LOG_ENC_HEX";

SD_CONST ST_CHAR *SD_CONST _cosp_err_logstr = "COSP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _cosp_dec_logstr = "COSP_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _cosp_dec_hex_logstr = "COSP_LOG_DEC_HEX";
SD_CONST ST_CHAR *SD_CONST _cosp_enc_logstr = "COSP_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _cosp_enc_hex_logstr = "COSP_LOG_ENC_HEX";
#endif

/* Buffer for building init, release, and abort reqests.	*/
#if defined (MOSI)
ST_UINT cosp_msgsize;
ST_UCHAR *cosp_buf;	/* Buffer containing "acse_buf" + COSP&COPP headers.*/
static ST_VOID acse_encode_user_info (ASN1_ENC_CTXT *aCtx, ACSE_CONN *acse_conn, BUFFER *user_info);
#else	/* !MOSI	*/
static ST_UCHAR *acse_buf;
#endif	/* !MOSI	*/

#define TP4_EOT		1	/* for tp4_data calls.		*/

/************************************************************************/
/* copp_initialize							*/
/* Save "msg_size". Pass "max_conns" to tp4_initialize.			*/
/************************************************************************/
ST_RET copp_initialize (ST_INT max_conns, ST_UINT msg_size)
  {
ST_RET ret;

  acse_msgsize = msg_size;	/* Save msg size in global.		*/

  /* Always enable error logging.	*/
  acse_debug_sel |= (ACSE_LOG_ERR | COPP_LOG_ERR | COSP_LOG_ERR);

  if (acse_msgsize == 0)
    {			/* ACSE user must call a_set_msgsize first.	*/
    ACSELOG_ERR0 ("ACSE-ERROR: msg size not set");
    return (E_ACSE_INVALID_PARAM);	/* Invalid Parameter		*/
    }
#if defined(MOSI)
  cosp_msgsize = max(acse_msgsize, COSP_MAX_UDATA_CON) + MAX_COSP_COPP_HEADER;
  cosp_buf = (ST_UCHAR *) M_MALLOC (MSMEM_STARTUP, cosp_msgsize);

  ret = tp4_initialize (max_conns, cosp_msgsize);
#else	/* !MOSI	*/
  acse_buf = (ST_UCHAR *) M_MALLOC (MSMEM_STARTUP, acse_msgsize);
  ret = tp4_initialize (max_conns, acse_msgsize);
#endif	/* !MOSI	*/
  return (ret);
  }

/************************************************************************/
/* copp_terminate							*/
/************************************************************************/
ST_RET copp_terminate (ST_VOID)
  {

#ifdef MOSI
  if (cosp_buf)
    M_FREE (MSMEM_STARTUP, cosp_buf);
#else
  if(acse_buf)
    M_FREE (MSMEM_STARTUP, acse_buf);
#endif 

  return (tp4_terminate ());
  }

/************************************************************************/
/* copp_event								*/
/************************************************************************/
ST_BOOLEAN copp_event (ST_INT  nSelPipe)
  {
	  //tp4_event == tp0_event
	return (tp4_event (nSelPipe));
  }

#if !defined (MOSI)	/* see copp_enc.c for MOSI bind functs.		*/
/************************************************************************/
/* copp_bind								*/
/************************************************************************/
ST_RET copp_bind (ST_LONG user_bind_id, PRES_ADDR *pres_addr, 
	ST_INT sharable, ST_INT max_conns)
  {
TP4_ADDR tp4_addr;

  ACSELOG_ENC1 ("COPP-Bind   Req.  user_bind_id =%9ld", user_bind_id);

#if !defined(REDUCED_STACK)
  /* Copy tsel and nsap from pres_addr to tp4_addr struct	*/
  tp4_addr.tp_type = pres_addr->tp_type;
  tp4_addr.tp4_sel_len = pres_addr->tsel_len;
  memcpy (tp4_addr.tp4_sel, pres_addr->tsel, pres_addr->tsel_len);
  tp4_addr.net_addr_len = pres_addr->nsap_len;
  memcpy (tp4_addr.net_addr, pres_addr->nsap, pres_addr->nsap_len);
#else
  tp4_addr.adlcAddr = pres_addr->adlcAddr;
#endif

  /* Call tp4_bind.	*/
  return (tp4_bind (user_bind_id, &tp4_addr, sharable, max_conns));
  }

/************************************************************************/
/* copp_unbind								*/
/************************************************************************/
ST_RET copp_unbind (ST_LONG copp_bind_id)
  {
  ACSELOG_ENC1 ("COPP-Unbind Req.                          copp_bind_id =%9ld", copp_bind_id);
  return (tp4_unbind (copp_bind_id));
  }
#endif	/* !MOSI	*/

/************************************************************************/
/* a_associate_req							*/
/************************************************************************/
ST_LONG a_associate_req (
	ST_LONG copp_bind_id,	/* ACSE's bind ID received in u_copp_bind_cnf*/
	ST_LONG user_conn_id,	/* USER's connection ID			*/
	AARQ_APDU *aarq_apdu,   /* AARQ_APDU info			*/
	ST_INT idx
	)	
{
#if !defined (MOSI)
TP4_ADDR tp4_addr;
#endif	/* !MOSI	*/
ACSE_CONN *acse_conn;
AE_TITLE *ae_title;
ST_UCHAR version1_bit_str = BIT_VERSION1;	/* Bit 0 of bitstr (high bit) set	*/
ST_UCHAR auth_bit_str = BIT_AUTHENTICATION;		

ST_UCHAR *msg_ptr;
ST_UINT msg_len;
ASN1_ENC_CTXT localEncCtx;	/* For readability, use "aCtx" to access this.*/
ASN1_ENC_CTXT *aCtx = &localEncCtx;
ST_INT j;

  /* Allocate connection tracking structure "acse_conn".		*/
  acse_conn = &acse_conn_table[idx];

  acse_conn->idx = idx;	
  acse_conn->copp_state = 0;
  acse_conn->cosp_state = 0;	
  acse_conn->cosp_cn_len = 0;
  /* Save USER's connection ID. Use it in calls to user functions.	*/
  acse_conn->user_conn_id = user_conn_id;

  /* save the encryption info */
  acse_conn->encrypt_ctrl = aarq_apdu->encrypt_ctrl;

  ACSELOG_ENC2 ("A-ASSOCIATE.req:  acse_conn_id =0x%08X  user_conn_id =%4ld",
    acse_conn, acse_conn->user_conn_id);
  ACSELOG_ENC0C ("DST (CALLED) ADDRESS:");
  if (aarq_apdu->called_ae_title.AP_title_pres)
    {
    for (j = 0; j < aarq_apdu->called_ae_title.AP_title.num_comps; ++j)
      {			/* Verbose but gets the job done.	*/
      ACSELOG_ENC2C ("  AP_title.comps[%d] = %d",
        j, aarq_apdu->called_ae_title.AP_title.comps[j]);
      }
    }
  if (aarq_apdu->called_ae_title.AE_qual_pres)
    {
    ACSELOG_ENC1C ("  AE_qual = %ld", aarq_apdu->called_ae_title.AE_qual);
    }
  ACSELOG_ENC0C ("  PSEL:");
  ACSELOG_ENCH  (aarq_apdu->called_paddr.psel_len, aarq_apdu->called_paddr.psel);
  ACSELOG_ENC0C ("  SSEL:");
  ACSELOG_ENCH  (aarq_apdu->called_paddr.ssel_len, aarq_apdu->called_paddr.ssel);
  ACSELOG_ENC0C ("  TSEL:");
  ACSELOG_ENCH  (aarq_apdu->called_paddr.tsel_len, aarq_apdu->called_paddr.tsel);
  if (aarq_apdu->called_paddr.tp_type == TP_TYPE_TCP)
    {
    struct in_addr sin_addr;	/* inet_ntoa needs this addr format*/
    sin_addr.s_addr = aarq_apdu->called_paddr.netAddr.ip;
    ACSELOG_ENC0C ("  IP ADDR:");
#if defined(TP0_ENABLED)
    ACSELOG_ENC1C ("  %s", inet_ntoa (sin_addr));
#endif
    if (aarq_apdu->encrypt_ctrl.encryptMode == S_SEC_ENCRYPT_SSL)
      ACSELOG_ENC1C ("  Encryption: SSL, port=%d", aarq_apdu->encrypt_ctrl.u.ssl.port);
    else
      ACSELOG_ENC0C ("  Encryption: None");
    if (aarq_apdu->auth_info.auth_pres)
      {
      if (aarq_apdu->auth_info.mech_type == ACSE_AUTH_MECH_MACE_CERT)
        ACSELOG_ENC0C ("  Authentication: MACE");
      else if (aarq_apdu->auth_info.mech_type == ACSE_AUTH_MECH_PASSWORD)
        ACSELOG_ENC0C ("  Authentication: password");
      else
        ACSELOG_ENC0C ("  Authentication: other");
      }
    else
      ACSELOG_ENC0C ("  Authentication: None");
    }
  else
    {
    ACSELOG_ENC0C ("  NSAP:");
    ACSELOG_ENCH  (aarq_apdu->called_paddr.nsap_len, aarq_apdu->called_paddr.netAddr.nsap);
    }

  ACSELOG_ENC0C ("SRC (CALLING) ADDRESS:");
  if (aarq_apdu->calling_ae_title.AP_title_pres)
    {
    for (j = 0; j < aarq_apdu->calling_ae_title.AP_title.num_comps; ++j)
      {			/* Verbose but gets the job done.	*/
      ACSELOG_ENC2C ("  AP_title.comps[%d] = %d",
        j, aarq_apdu->calling_ae_title.AP_title.comps[j]);
      }
    }
  if (aarq_apdu->calling_ae_title.AE_qual_pres)
    {
    ACSELOG_ENC1C ("  AE_qual = %ld", aarq_apdu->calling_ae_title.AE_qual);
    }
  /* NOTE: aarq_apdu->calling_paddr is NOT logged because caller may	*/
  /*       not set it, and even if they do, it is not used. The address	*/
  /*       passed to "copp_bind" is used as the calling_paddr.		*/

  /* Begin encoding request.						*/
#if defined (MOSI)
  asn1r_strt_asn1_bld (aCtx, cosp_buf,cosp_msgsize);
#else
  asn1r_strt_asn1_bld (aCtx, acse_buf,acse_msgsize);
#endif
    
  asn1r_strt_constr (aCtx);			/* Start AARQ APDU constructor	*/
  /* Write user_info.							*/
  if (aarq_apdu->user_info.len)
    {
    asn1r_strt_constr (aCtx);
#if defined (MOSI)
    /* PCI's must be set before any encoding.				*/
    acse_conn->pciacse = 1;
    acse_conn->pcimms = 3;
    acse_encode_user_info (aCtx, acse_conn, &aarq_apdu->user_info);
#else	/* !MOSI	*/
    asn1r_wr_octstr (aCtx, aarq_apdu->user_info.ptr, aarq_apdu->user_info.len);
    /* No P-Contexts in this implementation, so skip transfer-syntax	*/
    /* and p-context-id.						*/
#endif	/* !MOSI	*/
    asn1r_fin_constr (aCtx, AARQ_user_info,CTX,DEF);
    }
  
  if(aarq_apdu->auth_info.auth_pres == SD_TRUE)
    {
    if(aarq_apdu->auth_info.mech_type == ACSE_AUTH_MECH_PASSWORD)
      {
      ACSELOG_ENC0C ("  Authentication: password");
      /* Write the password value */
      asn1r_strt_constr (aCtx);	  
      asn1r_wr_octstr (aCtx, (ST_UCHAR *) aarq_apdu->auth_info.u.pw_auth.password, 
      		     strlen(aarq_apdu->auth_info.u.pw_auth.password)); /* Strip off the NULL */
      asn1r_fin_prim (aCtx, 0,CTX); 
      asn1r_fin_constr (aCtx, AARQ_CALLING_auth_value,CTX,DEF);
  
      /* Write the mechanism name (password in this case) */
      asn1r_wr_objid (aCtx, a_auth_password_obj_id.comps, a_auth_password_obj_id.num_comps);
      asn1r_fin_prim (aCtx, AARQ_mechanism_name, CTX);
      }
    else
      {
      if (aarq_apdu->auth_info.mech_type == ACSE_AUTH_MECH_MACE_CERT)
        ACSELOG_ENC0C ("Authentication: MACE");
      else
        ACSELOG_ENC0C ("Authentication: other");
      asn1r_strt_constr (aCtx);	  
      asn1r_strt_constr (aCtx);				/* Authentication-value	*/
      asn1r_strt_constr (aCtx);				/* Single ASN.1 Type 	*/
      asn1r_wr_octstr (aCtx, aarq_apdu->auth_info.u.other_auth.auth_value.ptr, 
      		     	     aarq_apdu->auth_info.u.other_auth.auth_value.len);
      asn1r_fin_constr (aCtx, 0, CTX, SD_FALSE); 	/* Single ASN.1 Type 	*/
      asn1r_fin_constr (aCtx, 2, CTX, SD_FALSE); 	/* Authentication-value	*/
      asn1r_fin_constr (aCtx, AARQ_CALLING_auth_value,CTX,DEF);
  
      /* Write the mechanism name */
      asn1r_wr_objid (aCtx, aarq_apdu->auth_info.u.other_auth.mech_id.comps, aarq_apdu->auth_info.u.other_auth.mech_id.num_comps);
      asn1r_fin_prim (aCtx, AARQ_mechanism_name, CTX);
      }
  
    /* Let's encode the authentication present bit to enable security */
    asn1r_wr_bitstr (aCtx, &auth_bit_str, 1);
    asn1r_fin_prim (aCtx, AARQ_acse_requirements, CTX);
    } 

  /* Write CALLING AE Title (i.e. AP_title, AE_qual, AP_inv_id, AE_inv_id).*/
  ae_title = &aarq_apdu->calling_ae_title;

  if (ae_title->AE_inv_id_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AE_inv_id);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLING_AE_inv_id,CTX,DEF);
    }
    
  if (ae_title->AP_inv_id_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AP_inv_id);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLING_AP_inv_id,CTX,DEF);
    }
    
  if (ae_title->AE_qual_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AE_qual);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLING_AE_qual,CTX,DEF);
    }
    
  if (ae_title->AP_title_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_objid (aCtx, ae_title->AP_title.comps, ae_title->AP_title.num_comps);
    asn1r_fin_prim (aCtx, OBJ_ID_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLING_AP_title,CTX,DEF);
    }


  /* Write CALLED AE Title (i.e. AP_title, AE_qual, AP_inv_id, AE_inv_id).*/
  ae_title = &aarq_apdu->called_ae_title;

  if (ae_title->AE_inv_id_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AE_inv_id);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLED_AE_inv_id,CTX,DEF);
    }
    
  if (ae_title->AP_inv_id_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AP_inv_id);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLED_AP_inv_id,CTX,DEF);
    }
    
  if (ae_title->AE_qual_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_i32 (aCtx, ae_title->AE_qual);
    asn1r_fin_prim (aCtx, INT_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLED_AE_qual,CTX,DEF);
    }
    
  if (ae_title->AP_title_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_objid (aCtx, ae_title->AP_title.comps, ae_title->AP_title.num_comps);
    asn1r_fin_prim (aCtx, OBJ_ID_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_CALLED_AP_title,CTX,DEF);
    }

  /* Write ASO Context Name.						*/
  if (aarq_apdu->ASO_context_name_pres)
    {
    asn1r_strt_constr (aCtx);
    asn1r_wr_objid (aCtx, aarq_apdu->ASO_context_name.comps, aarq_apdu->ASO_context_name.num_comps);
    asn1r_fin_prim (aCtx, OBJ_ID_CODE,UNI);
    asn1r_fin_constr (aCtx, AARQ_ASO_context_name,CTX,DEF);
    }

  /* Write protocol_version.						*/
  asn1r_wr_bitstr (aCtx, &version1_bit_str, 1);
  asn1r_fin_prim (aCtx, AARQ_protocol_version, CTX);

  asn1r_fin_constr (aCtx, TAG_AARQ,APP,DEF);	/* Finish AARQ APDU	*/

  msg_ptr = ASN1_ENC_PTR (aCtx);	/* point to beginning of PDU.	*/
  msg_len = ASN1_ENC_LEN (aCtx);

#if ! (defined(REDUCED_STACK) || defined(MOSI) )
  /* Fastbyte Presentation and Session (2 bytes).			*/
  *(--msg_ptr) = 0x01;		/* Short-CP mode = BER			*/
  *(--msg_ptr) = (ST_UCHAR) 0xE8;	/* Short-SCN, SI = 11101, 0 params	*/
  msg_len+=2;	/* adjust len	*/
#endif	/* ! (defined(REDUCED_STACK) || defined(MOSI) )	*/
  if (msg_len > acse_msgsize)
    return (0L);

#if defined (MOSI)
  acse_conn->apdu_ptr = msg_ptr;
  acse_conn->apdu_len = msg_len;
  /* Send AARQ APDU via P-CONNECT.req					*/
  if (copp_con_req (copp_bind_id, acse_conn, &aarq_apdu->called_paddr) != SD_SUCCESS)
    {
    acse_free_con (acse_conn);		/* Dump conn tracking struct	*/
    return (0L);
    }
  acse_conn->state = STATE_AARE_WAIT;	/* Waiting for AARE-apdu	*/
#else	/* !MOSI	*/
  /* Save AARQ APDU (in save_buf) to send when tp4 connection		*/
  /* established (see tp4_connect_cnf).					*/
  acse_conn->save_buf.len = msg_len;
  acse_conn->save_buf.ptr = (ST_UCHAR *) M_MALLOC (MSMEM_ACSE_DATA, msg_len);
  memcpy (acse_conn->save_buf.ptr, msg_ptr, msg_len);

  /* Send Transport connect request.					*/
  /* The connection ID is just a pointer to "acse_conn" cast to a ST_LONG.	*/
  /* Copy tsel and nsap from aarq_apdu->called_paddr to tp4_addr	*/
#if !defined(REDUCED_STACK)
  tp4_addr.tp_type = aarq_apdu->called_paddr.tp_type;
  tp4_addr.tp4_sel_len = aarq_apdu->called_paddr.tsel_len;
  memcpy (tp4_addr.tp4_sel, aarq_apdu->called_paddr.tsel,
          aarq_apdu->called_paddr.tsel_len);
  tp4_addr.net_addr_len = aarq_apdu->called_paddr.nsap_len;
  memcpy (tp4_addr.net_addr, aarq_apdu->called_paddr.nsap,
          aarq_apdu->called_paddr.nsap_len);
#else
  tp4_addr.adlcAddr = aarq_apdu->called_paddr.adlcAddr;
#endif

  if (tp4_connect (copp_bind_id, (ST_LONG) acse_conn,
                   &tp4_addr, 0, NULL, NULL) != SD_SUCCESS)
    {
    acse_free_con (acse_conn);		/* Dump conn tracking struct	*/
    return (0L);
    }
  acse_conn->state = STATE_TP4CONN_WAIT;	/* Waiting for TP4 connection*/
#endif	/* !MOSI	*/
  return ((ST_LONG)acse_conn);
  }

/************************************************************************/
/* a_associate_rsp							*/
/************************************************************************/
ST_RET a_associate_rsp (
	ST_LONG acse_conn_id,	/* ACSE's connection ID			*/
	ST_LONG user_conn_id,	/* USER's connection ID			*/
	AARE_APDU *info)	/* AARE_APDU info			*/
  {
  return (SD_SUCCESS);
  }

/************************************************************************/
/* a_release_req							*/
/************************************************************************/
ST_RET a_release_req (
	ST_LONG acse_conn_id,	/* ACSE's connection ID			*/
	RLRQ_APDU *info)	/* RLRQ_APDU info			*/
  {
ST_UCHAR *msg_ptr;
ST_UINT msg_len;
ACSE_CONN *acse_conn;
ASN1_ENC_CTXT localEncCtx;	/* For readability, use "aCtx" to access this.*/
ASN1_ENC_CTXT *aCtx = &localEncCtx;

  acse_conn = (ACSE_CONN *)acse_conn_id;

  ACSELOG_ENC2 ("A-RELEASE.req:    acse_conn_id =0x%08X  user_conn_id =%4ld",
    acse_conn, acse_conn->user_conn_id);

  if (acse_conn == NULL)
    return (E_ACSE_INVALID_CONN_ID);	/* Invalid acse_conn_id		*/

  if (acse_conn->state != STATE_ASSOCIATED)
    return (E_ACSE_INVALID_STATE);	/* Invalid state for this operation*/

  /* Everything looks OK. Go ahead and encode request and send it.	*/
#if defined (MOSI)
  asn1r_strt_asn1_bld (aCtx, cosp_buf,cosp_msgsize);
#else
  asn1r_strt_asn1_bld (aCtx, acse_buf,acse_msgsize);
#endif
    
  asn1r_strt_constr (aCtx);		/* Start RLRQ APDU constructor		*/
  /* Write user_info.							*/
  if (info->user_info.len)
    {
    asn1r_strt_constr (aCtx);
#if defined (MOSI)
    acse_encode_user_info (aCtx, acse_conn, &info->user_info);
#else	/* !MOSI	*/
    asn1r_wr_octstr (aCtx, info->user_info.ptr, info->user_info.len);
    /* No P-Contexts in this implementation, so skip transfer-syntax	*/
    /* and p-context-id.						*/
#endif	/* !MOSI	*/
    asn1r_fin_constr (aCtx, RLRQ_user_info,CTX,DEF);
    }
  
  /* Write Release Reason.						*/
  if (info->reason_pres)
    {
    asn1r_wr_i16 (aCtx, info->reason);
    asn1r_fin_prim (aCtx, RLRQ_reason,CTX);
    }
    
  asn1r_fin_constr (aCtx, TAG_RLRQ,APP,DEF);	/* Finish RLRQ APDU	*/
  msg_ptr = ASN1_ENC_PTR (aCtx);	/* point to beginning of PDU.	*/
  msg_len = ASN1_ENC_LEN (aCtx);
  if (msg_len > acse_msgsize)
    return (E_ACSE_BUFFER_OVERFLOW);

#if defined(MOSI)
  acse_conn->apdu_ptr = msg_ptr;
  acse_conn->apdu_len = msg_len;
  /* Send RLRQ APDU via P-RELEASE.req					*/
  if (copp_rel_req (acse_conn) != SD_SUCCESS)
    return (E_ACSE_SEND_ERR);
#else	/* !MOSI	*/
  /* Send RLRQ APDU via T-DATA.req					*/
  if (tp4_data (acse_conn->tp4_conn_id, TP4_EOT, msg_len, (ST_CHAR *) msg_ptr) != SD_SUCCESS)
    return (E_ACSE_SEND_ERR);
#endif	/* !MOSI	*/
  acse_conn->state = STATE_RLRE_WAIT;
  
  return (SD_SUCCESS);
  }

/************************************************************************/
/* a_release_rsp							*/
/************************************************************************/
ST_RET a_release_rsp (
	ST_LONG acse_conn_id,	/* ACSE's connection ID			*/
	RLRE_APDU *info)	/* RLRE_APDU info			*/
  {
  return (SD_SUCCESS);
  }

/************************************************************************/
/* a_abort_req								*/
/************************************************************************/
ST_RET a_abort_req (
	ST_LONG acse_conn_id,	/* ACSE's connection ID			*/
	ABRT_APDU *info)	/* ABRT_APDU info			*/
  {
ST_UCHAR *msg_ptr;
ST_UINT msg_len;
ACSE_CONN *acse_conn;
ASN1_ENC_CTXT localEncCtx;	/* For readability, use "aCtx" to access this.*/
ASN1_ENC_CTXT *aCtx = &localEncCtx;

  acse_conn = (ACSE_CONN *)acse_conn_id;

  ACSELOG_ENC2 ("A-ABORT.req:      acse_conn_id =0x%08X  user_conn_id =%4ld",
    acse_conn, acse_conn->user_conn_id);

  if (acse_conn == NULL)
    return (E_ACSE_INVALID_CONN_ID);	/* Invalid acse_conn_id		*/

  if (acse_conn->state == STATE_IDLE)	/* Waiting for T-DISCONNECT	*/
    return (E_ACSE_INVALID_STATE);	/* Invalid state for this operation*/

#ifndef MOSI
  if (acse_conn->state == STATE_TP4CONN_WAIT)
    {
    /* Don't free struct now. When get response, don't pass up to user	*/
    /* and free acse_conn then.						*/
    acse_conn->state = STATE_AARE_ABANDON;
    return (SD_SUCCESS);
    }

  if (acse_conn->state == STATE_AARE_WAIT)
    {
    /* Don't free struct now. When get response, don't pass up to user	*/
    /* and free acse_conn then.						*/
    acse_conn->state = STATE_AARE_ABANDON;
    return (SD_SUCCESS);
    }
#endif	/* !MOSI	*/

  /* Everything looks OK. Go ahead and encode request and send it.	*/
#if defined (MOSI)
  asn1r_strt_asn1_bld (aCtx, cosp_buf,cosp_msgsize);
#else
  asn1r_strt_asn1_bld (aCtx, acse_buf,acse_msgsize);
#endif
    
  asn1r_strt_constr (aCtx);		/* Start ABRT APDU constructor		*/
  /* Write user_info.							*/
  if (info->user_info.len)
    {
    asn1r_strt_constr (aCtx);
#if defined (MOSI)
    acse_encode_user_info (aCtx, acse_conn, &info->user_info);
#else	/* !MOSI	*/
    asn1r_wr_octstr (aCtx, info->user_info.ptr, info->user_info.len);
    /* No P-Contexts in this implementation, so skip transfer-syntax	*/
    /* and p-context-id.						*/
#endif	/* !MOSI	*/
    asn1r_fin_constr (aCtx, ABRT_user_info,CTX,DEF);
    }
  
  /* Write Abort Diagnostic.						*/
  if(info->diagnostic_pres == SD_TRUE)
    {
    asn1r_wr_i16 (aCtx, info->diagnostic);
    asn1r_fin_prim (aCtx, ABRT_diagnostic,CTX);
    }

  /* Write Abort Source.						*/
  asn1r_wr_i16 (aCtx, info->source);
  asn1r_fin_prim (aCtx, ABRT_source,CTX);
    
  asn1r_fin_constr (aCtx, TAG_ABRT,APP,DEF);	/* Finish ABRT APDU	*/
  msg_ptr = ASN1_ENC_PTR (aCtx);	/* point to beginning of PDU.	*/
  msg_len = ASN1_ENC_LEN (aCtx);
  if (msg_len > acse_msgsize)
    return (E_ACSE_BUFFER_OVERFLOW);

#if defined(MOSI)
  /* Send P-U-Abort Request.						*/
  acse_conn->apdu_ptr = msg_ptr;
  acse_conn->apdu_len = msg_len;
  acse_conn->state = STATE_IDLE;	/* COSP will free acse_conn.	*/
  if (copp_u_abort_req (acse_conn) != SD_SUCCESS)
    return (E_ACSE_SEND_ERR);
  /* CRITICAL: DO NOT access acse_conn after abort. It may have been	*/
  /*     freed by cosp_u_abort_req (called from copp_u_abort_req).	*/
#else	/* !MOSI	*/
  /* Send Transport Disconnect request.					*/
  tp4_disconnect (acse_conn->tp4_conn_id, msg_len, (ST_CHAR *) msg_ptr);
  acse_free_con (acse_conn);		/* Dump conn tracking struct	*/
#endif	/* !MOSI	*/
  
  return (SD_SUCCESS);
  }

/************************************************************************/
/* a_data_req - Send A-Data req.					*/
/************************************************************************/
ST_RET a_data_req (
	ST_LONG acse_conn_id,	/* ACSE's ID for this connection	*/
	ST_UINT data_len,
	ST_UCHAR *data)
  {
ACSE_CONN *acse_conn;

  acse_conn = (ACSE_CONN *)acse_conn_id;
  
#if defined(MOSI)
  if (data_len > acse_msgsize)
    {		/* Should never happen if ACSE user code is correct.	*/
    ACSELOG_ERR2 ("ACSE-ERROR: A-DATA.req: data len (%d) > max (%d)",
      data_len, acse_msgsize);
    return (E_ACSE_BUFFER_OVERFLOW);
    }
  /* Just copy data to end of "cosp_buf" & set apdu_ptr, apdu_len.	*/
  /* copp_data_req will add COPP encoding in front of this data.	*/
  acse_conn->apdu_ptr = cosp_buf + cosp_msgsize - data_len;
  acse_conn->apdu_len = data_len;
  memcpy (acse_conn->apdu_ptr, data, data_len);

  return (copp_data_req (acse_conn));
#else	/* !MOSI	*/
  return (tp4_data (acse_conn->tp4_conn_id, TP4_EOT, data_len,(ST_CHAR *)data));
#endif	/* !MOSI	*/
  }

#if defined (MOSI)
/************************************************************************/
/* acse_encode_user_info						*/
/************************************************************************/
static ST_VOID acse_encode_user_info (ASN1_ENC_CTXT *aCtx, ACSE_CONN *acse_conn, BUFFER *user_info)
  {
  asn1r_strt_constr (aCtx);			/* start EXTERNAL		*/
  asn1r_strt_constr (aCtx);			/* start single-ASN1-type	*/
  asn1r_wr_octstr (aCtx, user_info->ptr, user_info->len);
  asn1r_fin_constr (aCtx, 0,CTX,DEF);		/* finish single-ASN1-type	*/
  asn1r_wr_i8 (aCtx, acse_conn->pcimms);		/* PCI for MMS		*/
  asn1r_fin_prim (aCtx, INT_CODE,UNI);

  /* NOTE:  Transfer-syntax-name (OPTIONAL) not sent. Saves few bytes.	*/

  asn1r_fin_constr (aCtx, EXTERN_CODE,UNI,DEF);	/* finish EXTERNAL		*/
  return;
  }

#endif	/* MOSI	*/

#if !defined (MOSI)
/************************************************************************/
/*                      acse_free_con					*/
/*----------------------------------------------------------------------*/
/* This function will free the pointer to connection info.		*/
/* For MOSI, a slightly different "acse_free_con" function is		*/
/* defined in COSP????.c						*/
/************************************************************************/
ST_VOID acse_free_con (ACSE_CONN *acse_conn)
  {
  if (acse_conn->save_buf.len)
    M_FREE (MSMEM_ACSE_DATA, acse_conn->save_buf.ptr);
  M_FREE (MSMEM_ACSE_CONN, acse_conn);
  }
#endif	/* !MOSI	*/

/************************************************************************/
/* a_buffers_avail - Buffers available for sending A-Data req.		*/
/* This function returns the number of buffers available for sending	*/
/* A-Data.  This may be used, for example, when sending Information	*/
/* Reports, to make sure there are always enough buffers for sending	*/
/* responses to incoming requests.					*/
/*									*/
/* Parameters:								*/
/*	ST_LONG acse_conn_id	ACSE Connection ID			*/
/*									*/
/* Return:								*/
/*	ST_INT			# of ACSE transmit buffers available	*/
/************************************************************************/

#if defined(LEAN_T) ||  defined(REDUCED_STACK)

ST_INT a_buffers_avail (
	ST_LONG acse_conn_id)	/* ACSE's ID for this connection	*/
  {
#if defined(LEAN_T)
ACSE_CONN *acse_conn;

  acse_conn = (ACSE_CONN *)acse_conn_id;
  
  return (tp4_buffers_avail (acse_conn->tp4_conn_id));
#endif

#if defined(REDUCED_STACK)
  return (2);
#endif
  }

#endif

#if defined (MOSI)			/* Only MOSI uses events.	*/
#if !defined(_WIN32)
/************************************************************************/
/*			a_get_event_handles_unix			*/
/* Returns a pointer to an array of handles and sets			*/
/* (*pNumEntries) equal to the number of entries.			*/
/* NOTE: The TP4_ENABLED option currently only works on "linux".	*/
/************************************************************************/
#if defined(TP4_ENABLED)
#if defined(linux)
extern int hPktSock;
#else
#error TP4 not supported on this platform
#endif
#endif
#if defined(TP0_ENABLED)
extern int pipe_to_main;	/* DEBUG: move to include	*/
#endif
int *a_get_event_handles_unix (ST_INT *pNumEntries)
  {
static int fd_array [2];
ST_INT NumEntries = 0;

#if defined(TP4_ENABLED)
  fd_array[NumEntries++] = hPktSock;
#endif
#if defined(TP0_ENABLED)
  fd_array[NumEntries++] = pipe_to_main;
#endif
  *pNumEntries = NumEntries;
  return (fd_array);
  }
#endif  /* !defined(_WIN32) */
#endif	/* MOSI	*/

  
	/*------------------------------------------------------*/
	/* 		Security functions 			*/
	/*------------------------------------------------------*/

/********************************************************************************/
/*			a_get_security_info					*/
/*------------------------------------------------------------------------------*/
/* Returns pointers to encryption control and partner's authentication info	*/
/* from the specified channel info. This functions should be called after	*/
/* connection indication was received to retrieve the security informations.	*/
/* After the connection terminates call the s_free_part_security_info() to free	*/
/* the allocated auth_value buf and cleanup the channel info.			*/
/* Parameters:									*/
/*   ST_LONG		  acse_conn_id	indirect ptr to access security info	*/
/*   S_SEC_PARAMS        *secParams	pointer where to  ret security info.	*/
/* Return:									*/
/*   ST_RET		SD_SUCCESS	if get operation succeeded, otherwise	*/
/*			SD_FAILURE	or other error.				*/
/********************************************************************************/
ST_RET a_get_security_info (ST_LONG acse_conn_id, S_SEC_SPARAMS *secParams)
{
ST_RET     ret = SD_SUCCESS;
ACSE_CONN *acse_conn;

  secParams->authInfo = NULL;		/* local auth info not stored		*/
  secParams->partAuthInfo = NULL;	/* partner auth info			*/
  secParams->encryptCtrl = NULL;	/* connection encryption info		*/

  if (acse_conn_id)
    {
    acse_conn= (ACSE_CONN *) acse_conn_id;
    if (acse_conn)
      {
      secParams->partAuthInfo = &acse_conn->part_auth_info;
      secParams->encryptCtrl = &acse_conn->encrypt_ctrl;
      }
    }
  else
    ret = SD_FAILURE;			/* cc should be valid in this call	*/

  return (ret);  
}

/********************************************************************************/
/*			a_free_security_info					*/
/*------------------------------------------------------------------------------*/
/* Releases authentication info resources.					*/
/* Parameters:									*/
/*   ACSE_AUTH_INFO	*authInfo	ptr to free the security resources	*/
/* Return:									*/
/*   ST_RET		SD_SUCCESS	if free operation succeeded		*/
/*			SD_FAILURE      otherwise				*/
/********************************************************************************/
ST_RET a_free_security_info (ACSE_AUTH_INFO *authInfo)
{
ST_RET ret = SD_SUCCESS;

  if (authInfo)
    {
    /* clear authentication info */
    /* if there is an existing auth_value buf pointer then we have to free it	*/
    if (authInfo->auth_pres && authInfo->mech_type != ACSE_AUTH_MECH_PASSWORD)
      if (authInfo->u.other_auth.auth_value.buf)
        {
        chk_free (authInfo->u.other_auth.auth_value.buf);
        authInfo->u.other_auth.auth_value.buf = NULL;
        authInfo->u.other_auth.auth_value.ptr = NULL;
        authInfo->u.other_auth.auth_value.len = 0;
        }
    authInfo->auth_pres = SD_FALSE;
    }
  
  return (ret);  
}


/********************************************************************************/
/*			a_free_part_security_info				*/
/*------------------------------------------------------------------------------*/
/* Releases partner authentication resources and resets the field in ACSE_CONN.	*/
/* Parameters:									*/
/*   ST_LONG		acse_conn_id	indirect ptr to access security info	*/
/* Return:									*/
/*   ST_RET		SD_SUCCESS	if free operation succeeded		*/
/*			SD_FAILURE      otherwise				*/
/********************************************************************************/
ST_RET a_free_part_security_info (ST_LONG acse_conn_id)
{
ST_RET     ret = SD_SUCCESS;
ACSE_CONN *acse_conn;

  if (acse_conn_id)
    {
    acse_conn= (ACSE_CONN *) acse_conn_id;
    if (acse_conn)
      ret = a_free_security_info (&acse_conn->part_auth_info);
    }
  return (ret);  
}

