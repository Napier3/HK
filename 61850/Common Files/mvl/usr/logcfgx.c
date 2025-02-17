/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,       */
/*          2000 - 2003, All Rights Reserved                            */
/*                                                                      */
/* MODULE NAME : logcfgx.c                                              */
/* PRODUCT(S)  :                                                        */
/*                                                                      */
/* MODULE DESCRIPTION :    This module processes each value parsed in   */
/*                         the logcfg.xml file .  The logcfg.xml file   */
/*                         assigns Log File Attributes and              */
/*                         Miscellaneous Control Flags as well as       */
/*                         Memory Use Logging and various Log Masks     */
/*                         to enable specific logging required.         */
/*                                                                      */
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :                            */
/*                                                                      */
/* MODIFICATION LOG :                                                   */
/*  Date     Who   Rev          Comments                                */
/* --------  ---  ------  --------------------------------------------  */
/* 08/13/04  JRB    28    Use thread-safe sx_parseEx_mt.		*/
/*			  Ignore value of TimeEnable element.		*/
/*			  Del unneeded system includes.			*/
/* 04/17/04  MDE    27    Added MI_LOG_DISCOVERY			*/
/* 02/27/04  MDE    26    Added ACSE_LOG_DIB				*/
/* 01/12/04  EJV    25    Rem S_SEC_ENABLED def from SOCK_LOG_... masks.*/
/* 12/12/03  JRB    24    Init all 5 members of SX_ELEMENT structs.	*/
/* 12/10/03  MDE    23    Support MAP30_ACSE security			*/
/* 10/23/03  JRB    22    If !defined DEBUG_SISCO, logcfgx just return err*/
/* 09/02/03  EJV    21    Added Security and Sem LogMasks		*/
/*                        Added COSP_LOG_..., COPP_LOG_... masks	*/
/*			  FLOW logging: use elem names (not funcs names)*/
/*			  Added more info to logs.			*/
/*			  Elim repeating code: use new sx_get_string_...*/
/* 04/08/03  JRB    20    Fix action for input NoReallocSmaller=ON.	*/
/* 04/25/02  MDE    19    Added MMS REQ, RESP, IND, CONF		*/
/* 03/21/02  MDE    18    Added MILOG_ADDR, MILOG_CFG  			*/
/* 02/27/02  GLB    17    Changed ascii_t_.. to asciiTo..               */
/* 01/10/02  GLB    16    Added sx_pop to implement optional/mandatory  */
/* 11/05/01  GLB    15    Added ICFG_.. logging                         */
/* 08/01/01  RKR    14    Put ifdefs around MI and ADLC header files    */
/* 06/21/01  ASK    13    Added MI Logging functions                    */
/* 05/25/01  GLB    12    Removed getFileSize                           */
/* 05/11/01  JRB    11    Use new sx_parseEx. Del logCfgParse &         */
/*                        LOG_DEC_CTRL (not used for anything useful).  */
/*                        Del LogSystem, _lpIncNextBuf: never used.     */
/*                        Configured "LogFileName" value was NOT saved. */
/*                        Del // comments.                              */
/*                        Only copy configured params from tmp_sLogCtrl */
/*                        (other params may no longer be valid).        */
/* 03/15/01  JRB    10    Added USER_LOG_... masks                      */
/* 03/10/01  GLB    09    Use only system funtions: malloc, calloc, free*/
/* 03/10/01  GLB    08    Added SX_LOG_... masks                        */
/* 01/24/01  JRB    07    Was clearing CLNP_LOG_IND(REQ)                */
/*                        when should have cleared CLSNS_LOG_IND(REQ).  */
/*                        Do NOT set SX_LOG_DEBUG. Only user should.    */
/*                        Use _stricmp.                                  */
/* 01/09/01  GLB    06    Change logBufParse to logCfgParse             */
/* 01/04/01  EJV    05    Don't use O_TEXT in open() on non _WIN32 sys. */
/*                        Changed _getFileSize to use stat().           */
/* 02/01/00  GLB    04    Added check for SUIC masks, ACSE_ ...         */
/* 02/01/00  GLB    03    Added log messages for masks not checked      */                         
/* 11/30/00  RKR    02    Commented out adlc_usr.h                      */
/* 09/00/00  GLB    01    Module created from existing log_cfg.c        */
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "smem.h"
#include "mvl_acse.h"
#include "mvl_log.h"

#if defined (ICCP_LITE)
#include "mi_log.h"
#endif

#if defined (ICFG)
#include "icfg.h"
#endif

#include "suicacse.h"

#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
#include "adlc_usr.h"
#endif

#include "smp_usr.h"

#include "str_util.h"
#include "slog.h"

#include "sx_defs.h"
#include "sx_log.h"

#include "ssec.h"
#include "sslelog.h"
#include "sock_log.h"

/******** Control bit set/clear macros *********/

#define M_SET_CTRL(a)      {tmp_sLogCtrl.logCtrl |=  (a);}
#define M_CLR_CTRL(a)      {tmp_sLogCtrl.logCtrl &= ~(a);}

#define M_SET_FILE_CTRL(a) {tmp_sLogCtrl.fc.ctrl |=  (a);}
#define M_CLR_FILE_CTRL(a) {tmp_sLogCtrl.fc.ctrl &= ~(a);}

#define M_SET_MEM_CTRL(a)  {tmp_sLogCtrl.mc.ctrl |=  (a);}
#define M_CLR_MEM_CTRL(a)  {tmp_sLogCtrl.mc.ctrl &= ~(a);}

#if defined(DEBUG_SISCO)	/* most of this file only valid if this defined*/
/* See very end for what to do if !defined(DEBUG_SISCO)	*/
/************************************************************************/
/* Buffers to save file names.                                          */
/************************************************************************/
static ST_CHAR  log_file_name [256];
static ST_CHAR  memlog_file_name [256];
static LOG_CTRL tmp_sLogCtrl;

static ST_BOOLEAN debug_parsing;	/* set if parse function runs	*/
					/* 2nd time with debugging ON	*/

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of      */
/* __FILE__ strings.                                                    */

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/

static ST_VOID _logStart_SFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _sxLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sxLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sxLogDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sxLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sxLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sxLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _logControl_SFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _logFileAttributes_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _logFileEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _logFileSize_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _logFileName_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _logMemoryAttributes_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _logMemoryEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _logMemoryItems_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memoryFileName_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memoryFileDump_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _miscControlFlags_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _timeEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _destroyOldFile_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _setbuf_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _msgHeader_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _wipe_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _wrap_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _hardFlush_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _headerCr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _headerFilename_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _headerLogType_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _userLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _userLogClient_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _userLogServer_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _securityLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _secLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _secLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _secLogData_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _secLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _ssleLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _ssleLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _ssleLogData_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _ssleLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _semaphoreLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _gsLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _gsLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _asn1LogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _asn1LogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _asn1LogDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _asn1LogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _mmsLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogReq_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogResp_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogInd_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogConf_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogRt_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogRtaa_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mmsLogAa_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _mvlLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvlLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvlLogAcse_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvlLogAcsedata_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvluLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvluLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _mvluLogTiming_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _acseLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseLogDib_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseLogDec_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _coppLogDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _coppLogDecHex_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _coppLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _coppLogEncHex_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _cospLogDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _cospLogDecHex_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _cospLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _cospLogEncHex_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _acseNerrPrint_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseIndPrint_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseCnfPrint_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseDecPrint_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _acseAbortPrint_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _tp4LogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _tp4LogFlowup_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _tp4LogFlowdown_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _clnpLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clnpLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clnpLogReq_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clnpLogInd_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clnpLogEncDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clnpLogLlcEncDec_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clsnsLogReq_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _clsnsLogInd_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _socketLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sockLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sockLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sockLogTx_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _sockLogRx_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _adlcLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogIo_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogHexio_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogSm_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogHexsm_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogUser_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _adlcLogHexuser_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _miLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLogAddr_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLoguAutoDiscovery_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _miLogCfg_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _smpLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _smpLogReq_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _smpLogInd_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _icfgLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _icfgLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _icfgLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _memLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memLogCalloc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memLogMalloc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memLogRealloc_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memLogFree_EFun (SX_DEC_CTRL *sxDecCtrl);

static ST_VOID _memAllocDbgCtrl_SFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memFillEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _memHeapCheck_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _checkListEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _findNodeEnable_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _trackPrevFree_EFun (SX_DEC_CTRL *sxDecCtrl);
extern ST_BOOLEAN m_track_prev_free;    /* so secret it's not in any header file*/
static ST_VOID _listDebugSel_EFun (SX_DEC_CTRL *sxDecCtrl);
static ST_VOID _noReallocSmaller_EFun (SX_DEC_CTRL *sxDecCtrl);

/************************************************************************/
/************************************************************************/
/************************************************************************/

SX_ELEMENT logStartElements[] = 
{
  {"LOG_CFG",               SX_ELF_CSTART|SX_ELF_CEND, _logStart_SFun, NULL, 0}
};

SX_ELEMENT sxLogMaskElements[] = 
{
  {"SX_LOG_NERR",           SX_ELF_CEND|SX_ELF_OPT,    _sxLogNerr_EFun, NULL, 0},
  {"SX_LOG_DEC",            SX_ELF_CEND|SX_ELF_OPT,    _sxLogDec_EFun, NULL, 0},
  {"SX_LOG_ENC",            SX_ELF_CEND|SX_ELF_OPT,    _sxLogEnc_EFun, NULL, 0},
  {"SX_LOG_FLOW",           SX_ELF_CEND|SX_ELF_OPT,    _sxLogFlow_EFun, NULL, 0},
  {"SX_LOG_DEBUG",          SX_ELF_CEND|SX_ELF_OPT,    _sxLogDebug_EFun, NULL, 0}
};

SX_ELEMENT logElements[] = 
{
  {"SxLogMasks",            SX_ELF_CSTART|SX_ELF_OPT,  _sxLogMasks_SFun, NULL, 0},
  {"LogControl",            SX_ELF_CSTART,             _logControl_SFun, NULL, 0},
  {"UserLogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _userLogMasks_SFun, NULL, 0},
  {"SecurityLogMasks",      SX_ELF_CSTART|SX_ELF_OPT,  _securityLogMasks_SFun, NULL, 0},
  {"SemaphoreLogMasks",     SX_ELF_CSTART|SX_ELF_OPT,  _semaphoreLogMasks_SFun, NULL, 0},
  {"Asn1LogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _asn1LogMasks_SFun, NULL, 0},
  {"MmsLogMasks",           SX_ELF_CSTART|SX_ELF_OPT,  _mmsLogMasks_SFun, NULL, 0},
  {"MvlLogMasks",           SX_ELF_CSTART|SX_ELF_OPT,  _mvlLogMasks_SFun, NULL, 0},
  {"AcseLogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _acseLogMasks_SFun, NULL, 0},
  {"Tp4LogMasks",           SX_ELF_CSTART|SX_ELF_OPT,  _tp4LogMasks_SFun, NULL, 0},
  {"ClnpLogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _clnpLogMasks_SFun, NULL, 0},
  {"SocketLogMasks",        SX_ELF_CSTART|SX_ELF_OPT,  _socketLogMasks_SFun, NULL, 0},
  {"AdlcLogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _adlcLogMasks_SFun, NULL, 0},
  {"SmpLogMasks",           SX_ELF_CSTART|SX_ELF_OPT,  _smpLogMasks_SFun, NULL, 0},
  {"IcfgLogMasks",          SX_ELF_CSTART|SX_ELF_OPT,  _icfgLogMasks_SFun, NULL, 0},
  {"MiLogMasks",            SX_ELF_CSTART|SX_ELF_OPT,  _miLogMasks_SFun, NULL, 0},
  {"MemLogMasks",           SX_ELF_CSTART|SX_ELF_OPT,  _memLogMasks_SFun, NULL, 0},
  {"MemAllocDbgCtrl",       SX_ELF_CSTART|SX_ELF_OPT,  _memAllocDbgCtrl_SFun, NULL, 0}
};

SX_ELEMENT logControlElements[] = 
{
  {"LogFileAttributes",     SX_ELF_CSTART,  _logFileAttributes_SFun, NULL, 0},
  {"LogMemoryAttributes",   SX_ELF_CSTART,  _logMemoryAttributes_SFun, NULL, 0},
  {"MiscControlFlags",      SX_ELF_CSTART,  _miscControlFlags_SFun, NULL, 0}
};

SX_ELEMENT logFileAttributesElements[] = 
{
  {"LogFileEnable",         SX_ELF_CEND,    _logFileEnable_EFun, NULL, 0},
  {"LogFileSize",           SX_ELF_CEND,    _logFileSize_EFun, NULL, 0},
  {"LogFileName",           SX_ELF_CEND,    _logFileName_EFun, NULL, 0}
};

SX_ELEMENT logMemoryAttribElements[] = 
{
  {"LogMemoryEnable",       SX_ELF_CEND,    _logMemoryEnable_EFun, NULL, 0},
  {"LogMemoryItems",        SX_ELF_CEND,    _logMemoryItems_EFun, NULL, 0},
  {"MemoryFileName",        SX_ELF_CEND,    _memoryFileName_EFun, NULL, 0},
  {"MemoryFileDump",        SX_ELF_CEND,    _memoryFileDump_EFun, NULL, 0}
};

SX_ELEMENT miscControlFlagsElements[] = 
{
  {"TimeEnable",            SX_ELF_CEND,    _timeEnable_EFun, NULL, 0},
  {"DestroyOldFile",        SX_ELF_CEND,    _destroyOldFile_EFun, NULL, 0},
  {"Setbuf",                SX_ELF_CEND,    _setbuf_EFun, NULL, 0},
  {"MsgHeader",             SX_ELF_CEND,    _msgHeader_EFun, NULL, 0},
  {"Wipe",                  SX_ELF_CEND,    _wipe_EFun, NULL, 0},
  {"Wrap",                  SX_ELF_CEND,    _wrap_EFun, NULL, 0},
  {"HardFlush",             SX_ELF_CEND,    _hardFlush_EFun, NULL, 0},
  {"HeaderCr",              SX_ELF_CEND,    _headerCr_EFun, NULL, 0},
  {"HeaderFilename",        SX_ELF_CEND,    _headerFilename_EFun, NULL, 0},
  {"HeaderLogType",         SX_ELF_CEND,    _headerLogType_EFun, NULL, 0}
};

SX_ELEMENT userLogMaskElements[] = 
{
  {"USER_LOG_CLIENT",       SX_ELF_CEND|SX_ELF_OPT,   _userLogClient_EFun, NULL, 0},
  {"USER_LOG_SERVER",       SX_ELF_CEND|SX_ELF_OPT,   _userLogServer_EFun, NULL, 0}
};

SX_ELEMENT securityLogMaskElements[] = 
{
  {"SEC_LOG_NERR",          SX_ELF_CEND|SX_ELF_OPT,   _secLogNerr_EFun, NULL, 0},
  {"SEC_LOG_FLOW",          SX_ELF_CEND|SX_ELF_OPT,   _secLogFlow_EFun, NULL, 0},
  {"SEC_LOG_DATA",          SX_ELF_CEND|SX_ELF_OPT,   _secLogData_EFun, NULL, 0},
  {"SEC_LOG_DEBUG",         SX_ELF_CEND|SX_ELF_OPT,   _secLogDebug_EFun, NULL, 0},
  {"SSLE_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,   _ssleLogNerr_EFun, NULL, 0},
  {"SSLE_LOG_FLOW",         SX_ELF_CEND|SX_ELF_OPT,   _ssleLogFlow_EFun, NULL, 0},
  {"SSLE_LOG_DATA",         SX_ELF_CEND|SX_ELF_OPT,   _ssleLogData_EFun, NULL, 0},
  {"SSLE_LOG_DEBUG",        SX_ELF_CEND|SX_ELF_OPT,   _ssleLogDebug_EFun, NULL, 0}
};

SX_ELEMENT semaphoreLogMaskElements[] = 
{
  {"GS_LOG_NERR",          SX_ELF_CEND|SX_ELF_OPT,    _gsLogNerr_EFun, NULL, 0},
  {"GS_LOG_FLOW",          SX_ELF_CEND|SX_ELF_OPT,    _gsLogFlow_EFun, NULL, 0}
};

SX_ELEMENT asn1LogMaskElements[] = 
{
  {"ASN1_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,    _asn1LogNerr_EFun, NULL, 0},
  {"ASN1_LOG_DEC",          SX_ELF_CEND|SX_ELF_OPT,    _asn1LogDec_EFun, NULL, 0},
  {"ASN1_LOG_ENC",          SX_ELF_CEND|SX_ELF_OPT,    _asn1LogEnc_EFun, NULL, 0}
};

SX_ELEMENT miLogMaskElements[] = 
{
  {"MI_LOG_NERR",           SX_ELF_CEND|SX_ELF_OPT,    _miLogNerr_EFun, NULL, 0},
  {"MI_LOG_FLOW",           SX_ELF_CEND|SX_ELF_OPT,    _miLogFlow_EFun, NULL, 0},
  {"MI_LOG_DEBUG",          SX_ELF_CEND|SX_ELF_OPT,    _miLogDebug_EFun, NULL, 0},
  {"MI_LOG_CFG",            SX_ELF_CEND|SX_ELF_OPT,    _miLogCfg_EFun, NULL, 0},
  {"MI_LOG_ADDR",           SX_ELF_CEND|SX_ELF_OPT,    _miLogAddr_EFun, NULL, 0},
  {"MI_LOG_DISCOVERY",	    SX_ELF_CEND|SX_ELF_OPT,    _miLoguAutoDiscovery_EFun, NULL, 0}


};

SX_ELEMENT mmsLogMaskElements[] = 
{
  {"MMS_LOG_REQ",           SX_ELF_CEND|SX_ELF_OPT,    _mmsLogReq_EFun, NULL, 0},
  {"MMS_LOG_RESP",          SX_ELF_CEND|SX_ELF_OPT,    _mmsLogResp_EFun, NULL, 0},
  {"MMS_LOG_IND",           SX_ELF_CEND|SX_ELF_OPT,    _mmsLogInd_EFun, NULL, 0},
  {"MMS_LOG_CONF",          SX_ELF_CEND|SX_ELF_OPT,    _mmsLogConf_EFun, NULL, 0},
  {"MMS_LOG_NERR",          SX_ELF_CEND|SX_ELF_OPT,    _mmsLogNerr_EFun, NULL, 0},
  {"MMS_LOG_DEC",           SX_ELF_CEND|SX_ELF_OPT,    _mmsLogDec_EFun, NULL, 0},
  {"MMS_LOG_ENC",           SX_ELF_CEND|SX_ELF_OPT,    _mmsLogEnc_EFun, NULL, 0},
  {"MMS_LOG_RT",            SX_ELF_CEND|SX_ELF_OPT,    _mmsLogRt_EFun, NULL, 0},
  {"MMS_LOG_RTAA",          SX_ELF_CEND|SX_ELF_OPT,    _mmsLogRtaa_EFun, NULL, 0},
  {"MMS_LOG_AA",            SX_ELF_CEND|SX_ELF_OPT,    _mmsLogAa_EFun, NULL, 0}
};

SX_ELEMENT mvlLogMaskElements[] = 
{
  {"MVLLOG_NERR",           SX_ELF_CEND|SX_ELF_OPT,    _mvlLogNerr_EFun, NULL, 0},
  {"MVLLOG_ACSE",           SX_ELF_CEND|SX_ELF_OPT,    _mvlLogAcse_EFun, NULL, 0},
  {"MVLLOG_ACSEDATA",       SX_ELF_CEND|SX_ELF_OPT,    _mvlLogAcsedata_EFun, NULL, 0},
  {"MVLULOG_FLOW",          SX_ELF_CEND|SX_ELF_OPT,    _mvluLogFlow_EFun, NULL, 0},
  {"MVLULOG_DEBUG",         SX_ELF_CEND|SX_ELF_OPT,    _mvluLogDebug_EFun, NULL, 0},
  {"MVLULOG_TIMING",        SX_ELF_CEND|SX_ELF_OPT,    _mvluLogTiming_EFun, NULL, 0}
};

SX_ELEMENT acseLogMaskElements[] = 
{
  {"ACSE_LOG_DIB",          SX_ELF_CEND|SX_ELF_OPT,    _acseLogDib_EFun, NULL, 0},
  {"ACSE_LOG_ENC",          SX_ELF_CEND|SX_ELF_OPT,    _acseLogEnc_EFun, NULL, 0},
  {"ACSE_LOG_DEC",          SX_ELF_CEND|SX_ELF_OPT,    _acseLogDec_EFun, NULL, 0},
  {"COPP_LOG_DEC",          SX_ELF_CEND|SX_ELF_OPT,    _coppLogDec_EFun, NULL, 0},
  {"COPP_LOG_DEC_HEX",      SX_ELF_CEND|SX_ELF_OPT,    _coppLogDecHex_EFun, NULL, 0},
  {"COPP_LOG_ENC",          SX_ELF_CEND|SX_ELF_OPT,    _coppLogEnc_EFun, NULL, 0},
  {"COPP_LOG_ENC_HEX",      SX_ELF_CEND|SX_ELF_OPT,    _coppLogEncHex_EFun, NULL, 0},
  {"COSP_LOG_DEC",          SX_ELF_CEND|SX_ELF_OPT,    _cospLogDec_EFun, NULL, 0},
  {"COSP_LOG_DEC_HEX",      SX_ELF_CEND|SX_ELF_OPT,    _cospLogDecHex_EFun, NULL, 0},
  {"COSP_LOG_ENC",          SX_ELF_CEND|SX_ELF_OPT,    _cospLogEnc_EFun, NULL, 0},
  {"COSP_LOG_ENC_HEX",      SX_ELF_CEND|SX_ELF_OPT,    _cospLogEncHex_EFun, NULL, 0},
  /* osiul.lib logging */
  {"ACSE_NERR_PRINT",       SX_ELF_CEND|SX_ELF_OPT,    _acseNerrPrint_EFun, NULL, 0},
  {"ACSE_IND_PRINT",        SX_ELF_CEND|SX_ELF_OPT,    _acseIndPrint_EFun, NULL, 0},
  {"ACSE_CNF_PRINT",        SX_ELF_CEND|SX_ELF_OPT,    _acseCnfPrint_EFun, NULL, 0},
  {"ACSE_DEC_PRINT",        SX_ELF_CEND|SX_ELF_OPT,    _acseDecPrint_EFun, NULL, 0},
  {"ACSE_ABORT_PRINT",      SX_ELF_CEND|SX_ELF_OPT,    _acseAbortPrint_EFun, NULL, 0}
};

SX_ELEMENT tp4LogMaskElements[] = 
{
  {"TP4_LOG_FLOWUP",        SX_ELF_CEND|SX_ELF_OPT,    _tp4LogFlowup_EFun, NULL, 0},
  {"TP4_LOG_FLOWDOWN",      SX_ELF_CEND|SX_ELF_OPT,    _tp4LogFlowdown_EFun, NULL, 0}
};

SX_ELEMENT clnpLogMaskElements[] = 
{
  {"CLNP_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,    _clnpLogNerr_EFun, NULL, 0},
  {"CLNP_LOG_REQ",          SX_ELF_CEND|SX_ELF_OPT,    _clnpLogReq_EFun, NULL, 0},
  {"CLNP_LOG_IND",          SX_ELF_CEND|SX_ELF_OPT,    _clnpLogInd_EFun, NULL, 0},
  {"CLNP_LOG_ENC_DEC",      SX_ELF_CEND|SX_ELF_OPT,    _clnpLogEncDec_EFun, NULL, 0},
  {"CLNP_LOG_LLC_ENC_DEC",  SX_ELF_CEND|SX_ELF_OPT,    _clnpLogLlcEncDec_EFun, NULL, 0},
  {"CLSNS_LOG_REQ",         SX_ELF_CEND|SX_ELF_OPT,    _clsnsLogReq_EFun, NULL, 0},
  {"CLSNS_LOG_IND",         SX_ELF_CEND|SX_ELF_OPT,    _clsnsLogInd_EFun, NULL, 0}
};

SX_ELEMENT socketLogMaskElements[] = 
{
  {"SOCK_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,    _sockLogNerr_EFun, NULL, 0},
  {"SOCK_LOG_FLOW",         SX_ELF_CEND|SX_ELF_OPT,    _sockLogFlow_EFun, NULL, 0},
  {"SOCK_LOG_TX",           SX_ELF_CEND|SX_ELF_OPT,    _sockLogTx_EFun, NULL, 0},
  {"SOCK_LOG_RX",           SX_ELF_CEND|SX_ELF_OPT,    _sockLogRx_EFun, NULL, 0}
};

SX_ELEMENT adlcLogMaskElements[] = 
{
  {"ADLC_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,    _adlcLogNerr_EFun, NULL, 0},
  {"ADLC_LOG_FLOW",         SX_ELF_CEND|SX_ELF_OPT,    _adlcLogFlow_EFun, NULL, 0},
  {"ADLC_LOG_IO",           SX_ELF_CEND|SX_ELF_OPT,    _adlcLogIo_EFun, NULL, 0},
  {"ADLC_LOG_HEXIO",        SX_ELF_CEND|SX_ELF_OPT,    _adlcLogHexio_EFun, NULL, 0},
  {"ADLC_LOG_SM",           SX_ELF_CEND|SX_ELF_OPT,    _adlcLogSm_EFun, NULL, 0},
  {"ADLC_LOG_HEXSM",        SX_ELF_CEND|SX_ELF_OPT,    _adlcLogHexsm_EFun, NULL, 0},
  {"ADLC_LOG_USER",         SX_ELF_CEND|SX_ELF_OPT,    _adlcLogUser_EFun, NULL, 0},
  {"ADLC_LOG_HEXUSER",      SX_ELF_CEND|SX_ELF_OPT,    _adlcLogHexuser_EFun, NULL, 0}
};


SX_ELEMENT smpLogMaskElements[] = 
{
  {"SMP_LOG_REQ",           SX_ELF_CEND|SX_ELF_OPT,    _smpLogReq_EFun, NULL, 0},
  {"SMP_LOG_IND",           SX_ELF_CEND|SX_ELF_OPT,    _smpLogInd_EFun, NULL, 0}
};

SX_ELEMENT icfgLogMaskElements[] = 
{
  {"ICFG_LOG_FLOW",         SX_ELF_CEND|SX_ELF_OPT,    _icfgLogFlow_EFun, NULL, 0},
  {"ICFG_LOG_NERR",         SX_ELF_CEND|SX_ELF_OPT,    _icfgLogNerr_EFun, NULL, 0}
};

SX_ELEMENT memLogMaskElements[] = 
{
  {"MEM_LOG_CALLOC",        SX_ELF_CEND|SX_ELF_OPT,    _memLogCalloc_EFun, NULL, 0},
  {"MEM_LOG_MALLOC",        SX_ELF_CEND|SX_ELF_OPT,    _memLogMalloc_EFun, NULL, 0},
  {"MEM_LOG_REALLOC",       SX_ELF_CEND|SX_ELF_OPT,    _memLogRealloc_EFun, NULL, 0},
  {"MEM_LOG_FREE",          SX_ELF_CEND|SX_ELF_OPT,    _memLogFree_EFun, NULL, 0}
};

SX_ELEMENT memAllocElements[] = 
{
  {"MemFillEnable",         SX_ELF_CEND|SX_ELF_OPT,    _memFillEnable_EFun, NULL, 0},
  {"MemHeapCheck",          SX_ELF_CEND|SX_ELF_OPT,    _memHeapCheck_EFun, NULL, 0},
  {"CheckListEnable",       SX_ELF_CEND|SX_ELF_OPT,    _checkListEnable_EFun, NULL, 0},
  {"FindNodeEnable",        SX_ELF_CEND|SX_ELF_OPT,    _findNodeEnable_EFun, NULL, 0},
  {"TrackPrevFree",         SX_ELF_CEND|SX_ELF_OPT,    _trackPrevFree_EFun, NULL, 0},
  {"ListDebugSel",          SX_ELF_CEND|SX_ELF_OPT,    _listDebugSel_EFun, NULL, 0},
  {"NoReallocSmaller",      SX_ELF_CEND|SX_ELF_OPT,    _noReallocSmaller_EFun, NULL, 0}
};

/************************************************************************/
/*                                logcfgx                               */
/************************************************************************/

ST_RET logcfgx (ST_CHAR *logFileName)
  {
ST_RET rc;
ST_UINT sx_debug_sel_save;
ST_CHAR *savedFileName;

  savedFileName = sLogCtrl->fc.fileName;

  /* Copy original "sLogCtrl" to temporary struct which may be modified */
  /* by the configuration.                                              */
  /* This prevents logging control changes while there may be logging.  */
  memcpy (&tmp_sLogCtrl, sLogCtrl, sizeof (LOG_CTRL));

  rc = sx_parseEx_mt (logFileName, 
          sizeof (logStartElements)/sizeof(SX_ELEMENT), 
                  logStartElements, NULL, NULL, NULL);
  if (rc != SD_SUCCESS)
    {
    /* Config failed: Do not modify "sLogCtrl".                         */
    /* Turn on cfg logging and parse file again.                        */
    sx_debug_sel_save = sx_debug_sel;

    sx_debug_sel |= SX_LOG_DEC | SX_LOG_ENC | SX_LOG_FLOW | SX_LOG_DEBUG;
    debug_parsing = SD_TRUE;
    SXLOG_ERR0 ("Error: Trying again w/debug on ... ");
    rc = sx_parseEx_mt (logFileName, 
          sizeof (logStartElements)/sizeof(SX_ELEMENT), 
                  logStartElements, NULL, NULL, NULL);

    debug_parsing = SD_FALSE;
    sx_debug_sel = sx_debug_sel_save;
    }
  else    /* rc == SD_SUCCESS */
    {
    /* Config successful: Save new settings in "sLogCtrl".              */
    /* CRITICAL: only copy elements in tmp_sLogCtrl that may have been  */
    /*           modified by configuration (DON'T copy state, fp, etc.) */
    sLogCtrl->logCtrl         = tmp_sLogCtrl.logCtrl;
    sLogCtrl->fc.ctrl         = tmp_sLogCtrl.fc.ctrl;
    sLogCtrl->fc.fileName     = tmp_sLogCtrl.fc.fileName;
    sLogCtrl->fc.maxSize      = tmp_sLogCtrl.fc.maxSize;
    sLogCtrl->mc.ctrl         = tmp_sLogCtrl.mc.ctrl;
    sLogCtrl->mc.dumpFileName = tmp_sLogCtrl.mc.dumpFileName;
    sLogCtrl->mc.maxItems     = tmp_sLogCtrl.mc.maxItems;

    /* Config can't change "state" or "fp", so if log file was open,    */
    /* and filename changed, close the log file and clear state.        */
    if (sLogCtrl->fc.state & FIL_STATE_OPEN)
      {                 /* log file already opened  */
#ifdef _WIN32   /* Filenames NOT case sensitive on Windows  */
      if (_stricmp (savedFileName, sLogCtrl->fc.fileName) != 0)
#else
      if (strcmp (savedFileName, sLogCtrl->fc.fileName) != 0)
#endif
        {   /* NEW log file name different from OLD.    */
        fclose (sLogCtrl->fc.fp);           /* close it */
        sLogCtrl->fc.state &= ~(FIL_STATE_OPEN);    /* clear state  */
        /* NOTE: this msg will log to the new file.     */
        SLOGALWAYS1 ("See the file '%s' for messages logged before or during Logging config",
              savedFileName);
        }
      }

    /* NOTE: this msg will log to the new file.     */
    SLOGALWAYS0 ("Logging config complete");
    }

  return (rc);
  }

/************************************************************************/
/************************************************************************/
/*                           _logStart_SFun                             */
/************************************************************************/

static ST_VOID _logStart_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  LOG_CFG");

  if (sxDecCtrl->reason == SX_ELEMENT_START)
    {
    SX_PUSH (logElements);
    }

  if (sxDecCtrl->reason == SX_ELEMENT_END)
    {
    while (sxDecCtrl->itemStackLevel > 0)
      sx_pop (sxDecCtrl);
    }
  }

/************************************************************************/
/************************************************************************/
/*                           _sxLogMasks_SFun                           */
/************************************************************************/

static ST_VOID _sxLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  SxLogMasks");
  SX_PUSH (sxLogMaskElements);
  }

/************************************************************************/
/*                           _sxLogNerr_EFun                            */
/************************************************************************/

static ST_VOID _sxLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SX_LOG_NERR");
  if (!debug_parsing)
    rc = sx_get_string_OnOff_mask (sxDecCtrl, &sx_debug_sel, SX_LOG_NERR, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _sxLogDec_EFun                            */
/************************************************************************/

static ST_VOID _sxLogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SX_LOG_DEC");
  if (!debug_parsing)
    rc = sx_get_string_OnOff_mask (sxDecCtrl, &sx_debug_sel, SX_LOG_DEC, SX_ERR_CONVERT);
 }

/************************************************************************/
/*                            _sxLogEnc_EFun                            */
/************************************************************************/

static ST_VOID _sxLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SX_LOG_ENC");
  if (!debug_parsing)
    rc = sx_get_string_OnOff_mask (sxDecCtrl, &sx_debug_sel, SX_LOG_ENC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _sxLogFlow_EFun                           */
/************************************************************************/

static ST_VOID _sxLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SX_LOG_FLOW");
  if (!debug_parsing)
    rc = sx_get_string_OnOff_mask (sxDecCtrl, &sx_debug_sel, SX_LOG_FLOW, SX_ERR_CONVERT);
 }

/************************************************************************/
/*                           _sxLogDebug_EFun                           */
/************************************************************************/

static ST_VOID _sxLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SX_LOG_DEBUG");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sx_debug_sel, SX_LOG_DEBUG, SX_ERR_CONVERT);
  }

/************************************************************************/
/************************************************************************/
/*                           _logControl_SFun                           */
/************************************************************************/

static ST_VOID _logControl_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  LogControl");
  SX_PUSH (logControlElements);
  }

/************************************************************************/
/*                       _logFileAttributes_SFun                        */
/************************************************************************/

static ST_VOID _logFileAttributes_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  LogFileAttributes");
  SX_PUSH (logFileAttributesElements);
  }

/************************************************************************/
/*                         _logFileEnable_EFun                          */
/************************************************************************/

static ST_VOID _logFileEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  LogFileEnable");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_CTRL (LOG_FILE_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_CTRL (LOG_FILE_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: LogFileEnable Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                            _logFileSize_EFun                         */
/************************************************************************/

static ST_VOID _logFileSize_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

ST_ULONG uLongInt = 0;

  SXLOG_CFLOW0 ("SX DEC: found  LogFileSize");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (asciiToUlong(str,&uLongInt) != SD_SUCCESS)
    {
    log_printf ("\n LogFileSize Data Conversion Error");
    SXLOG_ERR0 ("ERROR: LogFileSize Data Conversion Error (ST_ULONG decimal number expected)");
    sxDecCtrl->errCode = SD_FAILURE;
    }
  else
    {
    tmp_sLogCtrl.fc.maxSize = uLongInt;    /* Size of the circular log file */
    }
  }
 
/************************************************************************/
/*                            _logFileName_EFun                         */
/************************************************************************/

static ST_VOID _logFileName_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  LogFileName");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (str != NULL)
    {                       
    if (strlen (str) < sizeof (log_file_name))
      {
      strcpy (log_file_name, str);
      tmp_sLogCtrl.fc.fileName = log_file_name;
      }
    else         
      {
      SXLOG_ERR1 ("ERROR: LogFileName Conversion Error (string too long, max %s bytes expected)",
                  sizeof (log_file_name)-1);
      sxDecCtrl->errCode = SX_ERR_CONVERT;
      }
    }
  else
    {
    SXLOG_ERR0 ("ERROR: LogFileName Conversion Error (file name not present)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/************************************************************************/
/*                        _logMemoryAttributes_SFun                     */
/************************************************************************/

static ST_VOID _logMemoryAttributes_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  LogMemoryAttributes");
  SX_PUSH (logMemoryAttribElements);
  }

/************************************************************************/
/*                      _logMemoryEnable_EFun                           */
/************************************************************************/

static ST_VOID _logMemoryEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  LogMemoryEnable");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_CTRL (LOG_MEM_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_CTRL (LOG_MEM_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: LogMemoryEnable Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                            _logMemoryItems_EFun                      */
/************************************************************************/

static ST_VOID _logMemoryItems_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

ST_ULONG uLongInt = 0;

  SXLOG_CFLOW0 ("SX DEC: found  LogMemoryItems");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (asciiToUlong(str,&uLongInt) != SD_SUCCESS)
    {
    SXLOG_ERR0 ("ERROR: LogMemoryItems Data Conversion Error (ST_ULONG decimal number expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  else
    {
    tmp_sLogCtrl.mc.maxItems = uLongInt;    /* Size of the circular log file    */
    }
  }

/************************************************************************/
/*                         _memoryFileName_EFun                         */
/************************************************************************/

static ST_VOID _memoryFileName_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  MemoryFileName");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (str != NULL)
    {                       
    if (strlen (str) < sizeof (memlog_file_name))
      {
      strcpy (memlog_file_name, str);
      tmp_sLogCtrl.mc.dumpFileName = memlog_file_name;
      }
    else         
      {
      SXLOG_ERR1 ("ERROR: MemoryFileName Conversion Error (string too long, max %s bytes expected)",
                  sizeof (memlog_file_name)-1);
      sxDecCtrl->errCode = SX_ERR_CONVERT;
      }
    }
  else
    {
    SXLOG_ERR0 ("ERROR: MemoryFileName Conversion Error (file name not present)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                            _memoryFileDump_EFun                      */
/************************************************************************/

static ST_VOID _memoryFileDump_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  MemoryFileDump");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_MEM_CTRL (MEM_CTRL_AUTODUMP_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_MEM_CTRL (MEM_CTRL_AUTODUMP_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: MemoryFileDump Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/************************************************************************/
/*                         _miscControlFlags_SFun                       */
/************************************************************************/

static ST_VOID _miscControlFlags_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MiscControlFlags");
  SX_PUSH (miscControlFlagsElements);
  }

/************************************************************************/
/*                          _timeEnable_EFun                            */
/************************************************************************/

static ST_VOID _timeEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  TimeEnable");

  /* NOTE: this function used to chk for a string = "TimeDate" or	*/
  /*     "ElapsedTime", but now the string is ignored.			*/

  M_SET_CTRL (LOG_TIME_EN);       /* Enable Time Stamp logging    */
 }

/************************************************************************/
/*                           _destroyOldFile_EFun                       */
/************************************************************************/

static ST_VOID _destroyOldFile_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  DestroyOldFile");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_NO_APPEND);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_NO_APPEND);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: DestroyOldFile Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                           _setbuf_EFun                               */
/************************************************************************/

static ST_VOID _setbuf_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  Setbuf");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_SETBUF_EN);  /* Setbuf is requested       */
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_SETBUF_EN);  /* Setbuf is requested       */
    }
  else
    {
    SXLOG_ERR0 ("ERROR: Setbuf Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                           _msgHeader_EFun                            */
/************************************************************************/

static ST_VOID _msgHeader_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  MsgHeader");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_MSG_HDR_EN);
    M_SET_MEM_CTRL (MEM_CTRL_MSG_HDR_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_MSG_HDR_EN);
    M_CLR_MEM_CTRL (MEM_CTRL_MSG_HDR_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: MsgHeader Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                             _wipe_EFun                               */
/************************************************************************/

static ST_VOID _wipe_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  Wipe");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_WIPE_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_WIPE_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: NoWipe Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                               _wrap_EFun                             */
/************************************************************************/

static ST_VOID _wrap_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  Wrap");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_WRAP_EN);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_WRAP_EN);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: wrap Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
}

/************************************************************************/
/*                            _hardFlush_EFun                           */
/************************************************************************/

static ST_VOID _hardFlush_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  HardFlush");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_SET_FILE_CTRL (FIL_CTRL_HARD_FLUSH);  /* Hard flush is requested  */
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_CLR_FILE_CTRL (FIL_CTRL_HARD_FLUSH);  /* Hard flush is requested  */
    }
  else
    {
    SXLOG_ERR0 ("ERROR: HardFlush Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                           _headerCr_EFun                             */
/************************************************************************/

static ST_VOID _headerCr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  HeaderCr");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_CLR_CTRL (LOG_NO_HEADER_CR);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_SET_CTRL (LOG_NO_HEADER_CR);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: HeaderCr Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }

  }

/************************************************************************/
/*                           _headerFilename_EFun                       */
/************************************************************************/

static ST_VOID _headerFilename_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  HeaderFilename");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_CLR_CTRL (LOG_FILENAME_SUPPRESS);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_SET_CTRL (LOG_FILENAME_SUPPRESS);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: HeaderFileName Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }
  }

/************************************************************************/
/*                            _headerLogType_EFun                       */
/************************************************************************/

static ST_VOID _headerLogType_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;
ST_CHAR *str;
ST_INT strLen;

  SXLOG_CFLOW0 ("SX DEC: found  HeaderLogType");
  rc = sx_get_string_ptr (sxDecCtrl, &str, &strLen);
  if (rc != SD_SUCCESS)
    return;

  if (!_stricmp (str, "ON"))
    {
    M_CLR_CTRL (LOG_LOGTYPE_SUPPRESS);
    }
  else if (!_stricmp (str, "OFF"))
    {
    M_SET_CTRL (LOG_LOGTYPE_SUPPRESS);
    }
  else
    {
    SXLOG_ERR0 ("ERROR: HeaderLogType Data Conversion Error (ON/OFF expected)");
    sxDecCtrl->errCode = SX_ERR_CONVERT;
    }

  }

/************************************************************************/
/************************************************************************/
/*                           _userLogMasks_SFun                         */
/************************************************************************/

static ST_VOID _userLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  UserLogMasks");
  SX_PUSH (userLogMaskElements);
  }

/************************************************************************/
/*                         _userLogClient_EFun                          */
/************************************************************************/

static ST_VOID _userLogClient_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  USER_LOG_CLIENT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &user_debug_sel, USER_LOG_CLIENT, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _userLogServer_EFun                       */
/************************************************************************/

static ST_VOID _userLogServer_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;

  SXLOG_CFLOW0 ("SX DEC: found  USER_LOG_SERVER");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &user_debug_sel, USER_LOG_SERVER, SX_ERR_CONVERT);
 }

/************************************************************************/
/************************************************************************/
/*                          _securityLogMasks_SFun                      */
/************************************************************************/

static ST_VOID _securityLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  SecurityLogMasks");
  SX_PUSH (securityLogMaskElements);
  }

/************************************************************************/
/*                          _secLogNerr_EFun                            */
/************************************************************************/

static ST_VOID _secLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SEC_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sec_debug_sel, SEC_LOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _secLogFlow_EFun                            */
/************************************************************************/

static ST_VOID _secLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SEC_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sec_debug_sel, SEC_LOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _secLogData_EFun                            */
/************************************************************************/

static ST_VOID _secLogData_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SEC_LOG_DATA");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sec_debug_sel, SEC_LOG_DATA, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _secLogDebug_EFun                            */
/************************************************************************/

static ST_VOID _secLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SEC_LOG_DEBUG");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sec_debug_sel, SEC_LOG_DEBUG, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _ssleLogNerr_EFun                            */
/************************************************************************/

static ST_VOID _ssleLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_UINT *pSslDebugSel;
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SSLE_LOG_NERR");
#if defined(MAP30_ACSE)
  pSslDebugSel = ssleGetDebugSel();
#else
  pSslDebugSel = &ssle_debug_sel;
#endif
  rc = sx_get_string_OnOff_mask (sxDecCtrl, pSslDebugSel, SSLE_LOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _ssleLogFlow_EFun                            */
/************************************************************************/

static ST_VOID _ssleLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_UINT *pSslDebugSel;
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SSLE_LOG_FLOW");
#if defined(MAP30_ACSE)
  pSslDebugSel = ssleGetDebugSel();
#else
  pSslDebugSel = &ssle_debug_sel;
#endif
  rc = sx_get_string_OnOff_mask (sxDecCtrl, pSslDebugSel, SSLE_LOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _ssleLogDebug_EFun                          */
/************************************************************************/

static ST_VOID _ssleLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_UINT *pSslDebugSel;
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SSLE_LOG_DEBUG");
#if defined(MAP30_ACSE)
  pSslDebugSel = ssleGetDebugSel();
#else
  pSslDebugSel = &ssle_debug_sel;
#endif
  rc = sx_get_string_OnOff_mask (sxDecCtrl, pSslDebugSel, SSLE_LOG_DEBUG, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _ssleLogData_EFun                           */
/************************************************************************/

static ST_VOID _ssleLogData_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(S_SEC_ENABLED)
ST_UINT *pSslDebugSel;
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SSLE_LOG_DATA");
#if defined(MAP30_ACSE)
  pSslDebugSel = ssleGetDebugSel();
#else
  pSslDebugSel = &ssle_debug_sel;
#endif
  rc = sx_get_string_OnOff_mask (sxDecCtrl, pSslDebugSel, SSLE_LOG_DATA, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/************************************************************************/
/*                          _semaphoreLogMasks_SFun                     */
/************************************************************************/

static ST_VOID _semaphoreLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  SemaphoreLogMasks");
  SX_PUSH (semaphoreLogMaskElements);
  }

/************************************************************************/
/*                          _gsLogNerr_EFun                            */
/************************************************************************/

static ST_VOID _gsLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  GS_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &gs_debug_sel, GS_LOG_NERR, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _gsLogFlow_EFun                            */
/************************************************************************/

static ST_VOID _gsLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  GS_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &gs_debug_sel, GS_LOG_FLOW, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _asn1LogMasks_SFun                          */
/************************************************************************/

static ST_VOID _asn1LogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  Asn1LogMasks");
  SX_PUSH (asn1LogMaskElements);
  }

/************************************************************************/
/*                               _asn1LogNerr_EFun                      */
/************************************************************************/

static ST_VOID _asn1LogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ASN1_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &asn1_debug_sel, ASN1_LOG_NERR, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                               _asn1LogDec_EFun                       */
/************************************************************************/

static ST_VOID _asn1LogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ASN1_LOG_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &asn1_debug_sel, ASN1_LOG_DEC, SX_ERR_CONVERT);
 }

/************************************************************************/
/*                             _asn1LogEnc_EFun                         */
/************************************************************************/

static ST_VOID _asn1LogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_BOOLEAN rc;

  SXLOG_CFLOW0 ("SX DEC: found  ASN1_LOG_ENC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &asn1_debug_sel, ASN1_LOG_ENC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _mmsLogMasks_SFun                           */
/************************************************************************/

static ST_VOID _mmsLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MmsLogMasks");
  SX_PUSH (mmsLogMaskElements);
  }

/************************************************************************/
/*                            _mmsLogReq_EFun                          */
/************************************************************************/

static ST_VOID _mmsLogReq_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_REQ");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_REQ, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogResp_EFun                          */
/************************************************************************/

static ST_VOID _mmsLogResp_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_RESP");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_RESP, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogInd_EFun                          */
/************************************************************************/

static ST_VOID _mmsLogInd_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_IND");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_IND, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogConf_EFun                          */
/************************************************************************/

static ST_VOID _mmsLogConf_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_CONF");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_CONF, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogNerr_EFun                          */
/************************************************************************/

static ST_VOID _mmsLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_NERR, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _mmsLogDec_EFun                            */
/************************************************************************/

static ST_VOID _mmsLogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_DEC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogEnc_EFun                           */
/************************************************************************/

static ST_VOID _mmsLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_ENC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_ENC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                                _mmsLogRt_EFun                        */
/************************************************************************/

static ST_VOID _mmsLogRt_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_RT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_RT, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _mmsLogRtaa_EFun                           */
/************************************************************************/

static ST_VOID _mmsLogRtaa_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_RTAA");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_RTAA, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mmsLogAa_EFun                            */
/************************************************************************/

static ST_VOID _mmsLogAa_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MMS_LOG_AA");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mms_debug_sel, MMS_LOG_AA, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                         _mvlLogMasks_SFun                            */
/************************************************************************/

static ST_VOID _mvlLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MvlLogMasks");
  SX_PUSH (mvlLogMaskElements);
  }

/************************************************************************/
/*                           _mvlLogNerr_EFun                           */
/************************************************************************/

static ST_VOID _mvlLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLLOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLLOG_NERR, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _mvlLogAcse_EFun                          */
/************************************************************************/

static ST_VOID _mvlLogAcse_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLLOG_ACSE");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLLOG_ACSE, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _mvlLogAcsedata_EFun                        */
/************************************************************************/

static ST_VOID _mvlLogAcsedata_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLLOG_ACSEDATA");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLLOG_ACSEDATA, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _mvluLogFlow_EFun                          */
/************************************************************************/

static ST_VOID _mvluLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLULOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLULOG_FLOW, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _mvluLogDebug_EFun                          */
/************************************************************************/

static ST_VOID _mvluLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLULOG_DEBUG");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLULOG_DEBUG, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _mvlLogTiming_EFun                          */
/************************************************************************/

static ST_VOID _mvluLogTiming_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MVLULOG_TIMING");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mvl_debug_sel, MVLULOG_TIMING, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                             _acseLogMasks_SFun                       */
/************************************************************************/

static ST_VOID _acseLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  AcseLogMasks");
  SX_PUSH (acseLogMaskElements);
  }

/************************************************************************/
/*                           _acseLogDib_EFun                           */
/************************************************************************/

static ST_VOID _acseLogDib_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_LOG_DIB");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, ACSE_LOG_DIB, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _acseLogEnc_EFun                           */
/************************************************************************/

static ST_VOID _acseLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_LOG_ENC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, ACSE_LOG_ENC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                             _acseLogDec_EFun                         */
/************************************************************************/

static ST_VOID _acseLogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_LOG_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, ACSE_LOG_DEC, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _coppLogDec_EFun                         */
/************************************************************************/

static ST_VOID _coppLogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COPP_LOG_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COPP_LOG_DEC, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _coppLogDecHex_EFun                      */
/************************************************************************/

static ST_VOID _coppLogDecHex_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COPP_LOG_DEC_HEX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COPP_LOG_DEC_HEX, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _coppLogEnc_EFun                         */
/************************************************************************/

static ST_VOID _coppLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COPP_LOG_ENC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COPP_LOG_ENC, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _coppLogEncHex_EFun                      */
/************************************************************************/

static ST_VOID _coppLogEncHex_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COPP_LOG_ENC_HEX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COPP_LOG_ENC_HEX, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _cospLogDec_EFun                         */
/************************************************************************/

static ST_VOID _cospLogDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COSP_LOG_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COSP_LOG_DEC, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _cospLogDecHex_EFun                      */
/************************************************************************/

static ST_VOID _cospLogDecHex_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COSP_LOG_DEC_HEX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COSP_LOG_DEC_HEX, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _cospLogEnc_EFun                         */
/************************************************************************/

static ST_VOID _cospLogEnc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COSP_LOG_ENC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COSP_LOG_ENC, SX_ERR_CONVERT);
}

/************************************************************************/
/*                             _cospLogEncHex_EFun                      */
/************************************************************************/

static ST_VOID _cospLogEncHex_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  COSP_LOG_ENC_HEX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &acse_debug_sel, COSP_LOG_ENC_HEX, SX_ERR_CONVERT);
}

/************************************************************************/
/*                          _acseNerrPrint_EFun                         */
/************************************************************************/

static ST_VOID _acseNerrPrint_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(MAP30_ACSE)
ST_RET  rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_NERR_PRINT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &s_debug_sel, ACSE_NERR_PRINT,  SX_ERR_CONVERT);
#endif
}

/************************************************************************/
/*                         _acseIndPrint_EFun                           */
/************************************************************************/

static ST_VOID _acseIndPrint_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(MAP30_ACSE)
ST_RET  rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_IND_PRINT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &s_debug_sel, ACSE_IND_PRINT, SX_ERR_CONVERT);
#endif
}

/************************************************************************/
/*                              _acseCnfPrint_EFun                      */
/************************************************************************/

static ST_VOID _acseCnfPrint_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(MAP30_ACSE)
ST_RET  rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_CNF_PRINT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &s_debug_sel, ACSE_CNF_PRINT, SX_ERR_CONVERT);
#endif
}

/************************************************************************/
/*                           _acseDecPrint_EFun                         */
/************************************************************************/

static ST_VOID _acseDecPrint_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(MAP30_ACSE)
ST_RET  rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_DEC_PRINT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &s_debug_sel, ACSE_DEC_PRINT, SX_ERR_CONVERT);
#endif
}

/************************************************************************/
/*                         _acseAbortPrint_EFun                         */
/************************************************************************/

static ST_VOID _acseAbortPrint_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined(MAP30_ACSE)
ST_RET  rc;

  SXLOG_CFLOW0 ("SX DEC: found  ACSE_ABORT_PRINT");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &s_debug_sel, ACSE_ABORT_PRINT, SX_ERR_CONVERT);
#endif
}

/************************************************************************/
/************************************************************************/
/*                         _tp4LogMasks_SFun                            */
/************************************************************************/

static ST_VOID _tp4LogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  Tp4LogMasks");
  SX_PUSH (tp4LogMaskElements);
  }

/************************************************************************/
/*                         _tp4LogFlowup_EFun                           */
/************************************************************************/

static ST_VOID _tp4LogFlowup_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  TP4_LOG_FLOWUP");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &tp4_debug_sel, TP4_LOG_FLOWUP, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _tp4LogFlowdown_EFun                        */
/************************************************************************/

static ST_VOID _tp4LogFlowdown_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  TP4_LOG_FLOWDOWN");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &tp4_debug_sel, TP4_LOG_FLOWDOWN, SX_ERR_CONVERT);
#endif
 }

/************************************************************************/
/*                           _clnpLogMasks_SFun                         */
/************************************************************************/

static ST_VOID _clnpLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  ClnpLogMasks");
  SX_PUSH (clnpLogMaskElements);
  }

/************************************************************************/
/*                            _clnpLogNerr_EFun                         */
/************************************************************************/

static ST_VOID _clnpLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLNP_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLNP_LOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                              _clnpLogReq_EFun                        */
/************************************************************************/

static ST_VOID _clnpLogReq_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLNP_LOG_REQ");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLNP_LOG_REQ, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                            _clnpLogInd_EFun                          */
/************************************************************************/

static ST_VOID _clnpLogInd_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLNP_LOG_IND");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLNP_LOG_IND, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                            _clnpLogEncDec_EFun                       */
/************************************************************************/

static ST_VOID _clnpLogEncDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLNP_LOG_ENC_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLNP_LOG_ENC_DEC, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                             _clnpLogLlcEncDec_EFun                   */
/************************************************************************/

static ST_VOID _clnpLogLlcEncDec_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLNP_LOG_LLC_ENC_DEC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLNP_LOG_LLC_ENC_DEC, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _clsnsLogReq_EFun                           */
/************************************************************************/

static ST_VOID _clsnsLogReq_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLSNS_LOG_REQ");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLSNS_LOG_REQ, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                           _clsnsLogInd_EFun                          */
/************************************************************************/

static ST_VOID _clsnsLogInd_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CLSNS_LOG_IND");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &clnp_debug_sel, CLSNS_LOG_IND, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/************************************************************************/
/*                         _socketLogMasks_SFun                         */
/************************************************************************/

static ST_VOID _socketLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {                        
  SXLOG_CFLOW0 ("SX DEC: found  SocketLogMasks");
  SX_PUSH (socketLogMaskElements);
  }

/************************************************************************/
/*                          _sockLogNerr_EFun                           */
/************************************************************************/

static ST_VOID _sockLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SOCK_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sock_debug_sel, SOCK_LOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _sockLogFlow_EFun                           */
/************************************************************************/

static ST_VOID _sockLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SOCK_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sock_debug_sel, SOCK_LOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _sockLogTx_EFun                             */
/************************************************************************/

static ST_VOID _sockLogTx_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SOCK_LOG_TX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sock_debug_sel, SOCK_LOG_TX, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _sockLogRx_EFun                             */
/************************************************************************/

static ST_VOID _sockLogRx_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if !defined(MAP30_ACSE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SOCK_LOG_RX");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &sock_debug_sel, SOCK_LOG_RX, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/************************************************************************/
/*                         _adlcLogMasks_SFun                           */
/************************************************************************/

static ST_VOID _adlcLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {                        
  SXLOG_CFLOW0 ("SX DEC: found  AdlcLogMasks");
  SX_PUSH (adlcLogMaskElements);
  }

/************************************************************************/
/*                           _adlcLogNerr_EFun                          */
/************************************************************************/

static ST_VOID _adlcLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_NERR, SX_ERR_CONVERT);
#endif
  }
  
/************************************************************************/
/*                           _adlcLogFlow_EFun                          */
/************************************************************************/

static ST_VOID _adlcLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                           _adlcLogIo_EFun                            */
/************************************************************************/

static ST_VOID _adlcLogIo_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_IO");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_IO, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                         _adlcLogHexio_EFun                           */
/************************************************************************/

static ST_VOID _adlcLogHexio_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_HEXIO");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_HEXIO, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                            _adlcLogSm_EFun                           */
/************************************************************************/

static ST_VOID _adlcLogSm_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_SM");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_SM, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                         _adlcLogHexsm_EFun                           */
/************************************************************************/

static ST_VOID _adlcLogHexsm_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_HEXSM");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_HEXSM, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                           _adlcLogUser_EFun                          */
/************************************************************************/

static ST_VOID _adlcLogUser_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_USER");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_USER, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                            _adlcLogHexuser_EFun                      */
/************************************************************************/

static ST_VOID _adlcLogHexuser_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if (defined (ADLC_SLAVE) || defined (ADLC_MASTER))
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ADLC_LOG_HEXUSER");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &adlc_debug_sel, ADLC_MASK_LOG_HEXUSER, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                               _miLogMasks_SFun                       */
/************************************************************************/

static ST_VOID _miLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MiLogMasks");
  SX_PUSH (miLogMaskElements);
  }

/************************************************************************/
/*                              _miLogNerr_EFun                         */
/************************************************************************/

static ST_VOID _miLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, MILOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                              _miLogFlow_EFun                         */
/************************************************************************/

static ST_VOID _miLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, MILOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                              _miLogDebug_EFun                        */
/************************************************************************/

static ST_VOID _miLogDebug_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_DEBUG");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, MILOG_DEBUG, SX_ERR_CONVERT);
#endif
  }


/************************************************************************/
/*                              _miLogAddr_EFun                        */
/************************************************************************/

static ST_VOID _miLogAddr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_ADDR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, MILOG_ADDR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                              _miLoguAutoDiscovery_EFun               */
/************************************************************************/

static ST_VOID _miLoguAutoDiscovery_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_DISCOVERY");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, 
  				 MILOG_DISCOVERY, SX_ERR_CONVERT);
#endif
  }


/************************************************************************/
/*                              _miLogCfg_EFun 	                        */
/************************************************************************/

static ST_VOID _miLogCfg_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICCP_LITE)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MI_LOG_CFG");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &mi_debug_sel, MILOG_CFG, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                          _smpLogMasks_SFun                           */
/************************************************************************/

static ST_VOID _smpLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  SmpLogMasks");
  SX_PUSH (smpLogMaskElements);
  }

/************************************************************************/
/*                             _smpLogReq_EFun                          */
/************************************************************************/

static ST_VOID _smpLogReq_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (UCA_SMP)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SMP_LOG_REQ");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &smp_debug_sel, SMP_LOG_REQ, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                            _smpLogInd_EFun                           */
/************************************************************************/

static ST_VOID _smpLogInd_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (UCA_SMP)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  SMP_LOG_IND");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &smp_debug_sel, SMP_LOG_IND, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*          		_icfgLogMasks_SFun                              */
/************************************************************************/

static ST_VOID _icfgLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  IcfgLogMasks");
  SX_PUSH (icfgLogMaskElements);
  }

/************************************************************************/
/*                      _icfgLogFlow_EFun                               */
/************************************************************************/

static ST_VOID _icfgLogFlow_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICFG)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ICFG_LOG_FLOW");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &icfg_debug_sel, ICFG_LOG_FLOW, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                      _icfgLogNerr_EFun                               */
/************************************************************************/

static ST_VOID _icfgLogNerr_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
#if defined (ICFG)
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ICFG_LOG_NERR");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &icfg_debug_sel, ICFG_LOG_NERR, SX_ERR_CONVERT);
#endif
  }

/************************************************************************/
/*                         _memLogMasks_SFun                            */
/************************************************************************/

static ST_VOID _memLogMasks_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MemLogMasks");
  SX_PUSH (memLogMaskElements);
  }

/************************************************************************/
/*                          _memLogCalloc_EFun                          */
/************************************************************************/

static ST_VOID _memLogCalloc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MEM_LOG_CALLOC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &chk_debug_en, MEM_LOG_CALLOC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                               _memLogMalloc_EFun                     */
/************************************************************************/

static ST_VOID _memLogMalloc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MEM_LOG_MALLOC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &chk_debug_en, MEM_LOG_MALLOC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                              _memLogRealloc_EFun                     */
/************************************************************************/

static ST_VOID _memLogRealloc_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MEM_LOG_REALLOC");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &chk_debug_en, MEM_LOG_REALLOC, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                               _memLogFree_EFun                       */
/************************************************************************/

static ST_VOID _memLogFree_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MEM_LOG_FREE");
  rc = sx_get_string_OnOff_mask (sxDecCtrl, &chk_debug_en, MEM_LOG_FREE, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _memAllocDbgCtrl_SFun                      */
/************************************************************************/

static ST_VOID _memAllocDbgCtrl_SFun (SX_DEC_CTRL *sxDecCtrl)
  {
  SXLOG_CFLOW0 ("SX DEC: found  MemAllocDbgCtrl");
  SX_PUSH (memAllocElements);
  }


/************************************************************************/
/*                             _memFillEnable_EFun                      */
/************************************************************************/

static ST_VOID _memFillEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MemFillEnable");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_fill_en, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                          _memHeapCheck_EFun                          */
/************************************************************************/

static ST_VOID _memHeapCheck_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  MemHeapCheck");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_heap_check_enable, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _checkListEnable_EFun                     */
/************************************************************************/

static ST_VOID _checkListEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  CheckListEnable");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_check_list_enable, SX_ERR_CONVERT);
  }

/************************************************************************/
/*          			_findNodeEnable_EFun                	*/
/************************************************************************/

static ST_VOID _findNodeEnable_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  FindNodeEnable");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_find_node_enable, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                           _trackPrevFree_EFun                        */
/************************************************************************/

static ST_VOID _trackPrevFree_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  TrackPrevFree");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_track_prev_free, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                            _listDebugSel_EFun                        */
/************************************************************************/

static ST_VOID _listDebugSel_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  ListDebugSel");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &list_debug_sel, SX_ERR_CONVERT);
  }

/************************************************************************/
/*                             _noReallocSmaller_EFun                   */
/************************************************************************/

static ST_VOID _noReallocSmaller_EFun (SX_DEC_CTRL *sxDecCtrl)
  {
ST_RET rc;

  SXLOG_CFLOW0 ("SX DEC: found  NoReallocSmaller");
  rc = sx_get_string_OnOff_bool (sxDecCtrl, &m_no_realloc_smaller, SX_ERR_CONVERT);
  }
#else	/* !DEBUG_SISCO	*/
/************************************************************************/
/*                                logcfgx                               */
/* This function replaces the "normal" function if !defined DEBUG_SISCO.*/
/* It ALWAYS returns an error.						*/
/************************************************************************/
ST_RET logcfgx (ST_CHAR *logFileName)
  {
  return (SD_FAILURE);
  }
#endif	/* !DEBUG_SISCO	*/
