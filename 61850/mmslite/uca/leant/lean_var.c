/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	2005-2005 All Rights Reserved					*/
/*									*/
/* MODULE NAME : lean_var.c						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	Global variables used by the stack components are placed here,	*/
/*	so that when they are referenced, the linker is NOT forced	*/
/*	to pull in a lot of code.					*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	None								*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 12/13/06  JRB     05    hPktSock moved here (avail on any system).	*/
/* 08/18/06  JRB     04    Init *_debug_sel with appropriate *_ERR.	*/
/* 05/24/05  EJV     03    Moved xxxLogMaskMapCtrl from logcfgx.c	*/
/* 02/01/05  JRB     02    Remove DEBUG_SISCO around *_debug_sel so old	*/
/*			   apps link without problems.			*/
/* 01/24/05  JRB     01    Created.					*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "acse2usr.h"		/* for ACSE_LOG_xxx */
#include "acse2log.h"
#include "tp4_log.h"
#include "clnp_log.h"

/************************************************************************/
/* Global Variables for ACSE, COPP, COSP layer logging.			*/
/************************************************************************/
ST_UINT acse_debug_sel = ACSE_LOG_ERR;

#if defined(DEBUG_SISCO)
SD_CONST ST_CHAR *SD_CONST _acse_err_logstr = "ACSE_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _acse_enc_logstr = "ACSE_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _acse_dec_logstr = "ACSE_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _acse_dib_logstr = "ACSE_LOG_DIB";

SD_CONST ST_CHAR *SD_CONST _copp_err_logstr	= "COPP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _copp_dec_logstr	= "COPP_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _copp_dec_hex_logstr	= "COPP_LOG_DEC_HEX";
SD_CONST ST_CHAR *SD_CONST _copp_enc_logstr	= "COPP_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _copp_enc_hex_logstr	= "COPP_LOG_ENC_HEX";

SD_CONST ST_CHAR *SD_CONST _cosp_err_logstr	= "COSP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _cosp_dec_logstr	= "COSP_LOG_DEC";
SD_CONST ST_CHAR *SD_CONST _cosp_dec_hex_logstr	= "COSP_LOG_DEC_HEX";
SD_CONST ST_CHAR *SD_CONST _cosp_enc_logstr	= "COSP_LOG_ENC";
SD_CONST ST_CHAR *SD_CONST _cosp_enc_hex_logstr	= "COSP_LOG_ENC_HEX";

LOGCFGX_VALUE_MAP acseLogMaskMaps[] =
  {
    {"ACSE_LOG_ERR",	ACSE_LOG_ERR,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "ACSE Error"},
    {"ACSE_LOG_ENC",	ACSE_LOG_ENC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "ACSE Encode"},
    {"ACSE_LOG_DEC",	ACSE_LOG_DEC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "ACSE Decode"},
    {"ACSE_LOG_DIB",	ACSE_LOG_DIB,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "DIB"},
    {"COPP_LOG_ERR",	COPP_LOG_ERR,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COPP Error"},
    {"COPP_LOG_DEC",	COPP_LOG_DEC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COPP Decode"},
    {"COPP_LOG_DEC_HEX",COPP_LOG_DEC_HEX, &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COPP Decode Hex"},
    {"COPP_LOG_ENC",	COPP_LOG_ENC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COPP Encode"},
    {"COPP_LOG_ENC_HEX",COPP_LOG_ENC_HEX, &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COPP Encode Hex"},
    {"COSP_LOG_ERR",	COSP_LOG_ERR,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COSP Error"},
    {"COSP_LOG_DEC",	COSP_LOG_DEC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COSP Decode"},
    {"COSP_LOG_DEC_HEX",COSP_LOG_DEC_HEX, &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COSP Decode Hex"},
    {"COSP_LOG_ENC",	COSP_LOG_ENC,	  &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COSP Encode"},
    {"COSP_LOG_ENC_HEX",COSP_LOG_ENC_HEX, &acse_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "COSP Encode Hex"}
  };

LOGCFG_VALUE_GROUP acseLogMaskMapCtrl =
  {
  {NULL,NULL},
  "ACSE",
  sizeof(acseLogMaskMaps)/sizeof(LOGCFGX_VALUE_MAP),
  acseLogMaskMaps
  };
#endif  /* DEBUG_SISCO */

/************************************************************************/
/* Global Variables for TP4 layer logging.				*/
/************************************************************************/
ST_UINT tp4_debug_sel = TP4_LOG_ERR;

#if defined(DEBUG_SISCO)
SD_CONST ST_CHAR *SD_CONST _tp4_err_logstr	= "TP4_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _tp4_flowup_logstr	= "TP4_LOG_FLOWUP";
SD_CONST ST_CHAR *SD_CONST _tp4_flowdown_logstr	= "TP4_LOG_FLOWDOWN";

LOGCFGX_VALUE_MAP tp4LogMaskMaps[] =
  {
    {"TP4_LOG_ERR",	 TP4_LOG_ERR,	   &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Error"},
    {"TP4_LOG_FLOWUP",	 TP4_LOG_FLOWUP,   &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Flow Up"},
    {"TP4_LOG_FLOWDOWN", TP4_LOG_FLOWDOWN, &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Flow Down"},
    /* for TP0 use different names in xml file */
    {"TP_LOG_ERR",	 TP4_LOG_ERR,	   &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Error"},
    {"TP_LOG_FLOWUP",	 TP4_LOG_FLOWUP,   &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Flow Up"},
    {"TP_LOG_FLOWDOWN",	 TP4_LOG_FLOWDOWN, &tp4_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Flow Down"}
  };

LOGCFG_VALUE_GROUP tp4LogMaskMapCtrl =
  {
  {NULL,NULL},
  "TP4",
  sizeof(tp4LogMaskMaps)/sizeof(LOGCFGX_VALUE_MAP),
  tp4LogMaskMaps
  };
#endif  /* DEBUG_SISCO */

/************************************************************************/
/* Global Variables for CLNP layer logging.				*/
/************************************************************************/
ST_UINT clnp_debug_sel = CLNP_LOG_ERR;

#if defined(DEBUG_SISCO)
SD_CONST ST_CHAR *SD_CONST _clnp_err_logstr	= "CLNP_LOG_ERR";
SD_CONST ST_CHAR *SD_CONST _clnp_nerr_logstr	= "CLNP_LOG_NERR";
SD_CONST ST_CHAR *SD_CONST _clnp_req_logstr	= "CLNP_LOG_REQ";
SD_CONST ST_CHAR *SD_CONST _clnp_ind_logstr	= "CLNP_LOG_IND";
SD_CONST ST_CHAR *SD_CONST _clnp_enc_dec_logstr	= "CLNP_LOG_ENC_DEC";
SD_CONST ST_CHAR *SD_CONST _clnp_llc_enc_dec_logstr = "CLNP_LOG_LLC_ENC_DEC";
SD_CONST ST_CHAR *SD_CONST _clsns_req_logstr	= "CLSNS_LOG_REQ";
SD_CONST ST_CHAR *SD_CONST _clsns_ind_logstr	= "CLSNS_LOG_IND";

LOGCFGX_VALUE_MAP clnpLogMaskMaps[] =
  {
    {"CLNP_LOG_ERR",	     CLNP_LOG_ERR,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Error"},
    {"CLNP_LOG_NERR",	     CLNP_LOG_NERR,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "Notice"},
    {"CLNP_LOG_REQ",	     CLNP_LOG_REQ,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "CLNP Request"},
    {"CLNP_LOG_IND",	     CLNP_LOG_IND,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "CLNP Indication"},
    {"CLNP_LOG_ENC_DEC",     CLNP_LOG_ENC_DEC,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "EncodeDecode"},
    {"CLNP_LOG_LLC_ENC_DEC", CLNP_LOG_LLC_ENC_DEC, &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "EncodeDecode"},
    {"CLSNS_LOG_REQ",	     CLSNS_LOG_REQ,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "CLSNS Request"},
    {"CLSNS_LOG_IND",	     CLSNS_LOG_IND,	   &clnp_debug_sel, _LOGCFG_DATATYPE_UINT_MASK, "CLSNS Indication"}
  };

LOGCFG_VALUE_GROUP clnpLogMaskMapCtrl =
  {
  {NULL,NULL},
  "CLNP",
  sizeof(clnpLogMaskMaps)/sizeof(LOGCFGX_VALUE_MAP),
  clnpLogMaskMaps
  };
#endif  /* DEBUG_SISCO */

/************************************************************************/
/* hPktSock is used in LINUX subnetwork code (see clnp_linux.c) and it	*/
/* may be used on new systems.						*/
/************************************************************************/
int hPktSock = -1;	/* Packet Socket handle: initialized to invalid value*/
