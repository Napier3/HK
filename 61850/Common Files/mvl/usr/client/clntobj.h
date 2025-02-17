/*  This file created from input file '..\..\mvl\usr\client\clntobj.odf'
    Leaf Access Parameter (LAP) File: 'Not Used'
	Created Fri Jun 15 18:37:57 2007
*/

#ifndef FOUNDRY_OUTPUT_HEADER_INCLUDED
#define FOUNDRY_OUTPUT_HEADER_INCLUDED

#include "mvl_uca.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/* MVL Type Control Information */
#ifndef _MVL_TYPE_CTRL_use_one_device_
	extern MVL_TYPE_CTRL *mvl_type_ctrl;
#else
	extern MVL_TYPE_CTRL *g_mvl_type_ctrl;
#endif

extern ST_INT mvl_num_types;

/************************************************************************/


/* MVL Type ID's */
#define BOOLEAN_TYPEID		0
#define INT8_TYPEID		1
#define INT16_TYPEID		2
#define INT32_TYPEID		3
#define INT128_TYPEID		4
#define INT8U_TYPEID		5
#define INT16U_TYPEID		6
#define INT32U_TYPEID		7
#define FLOAT32_TYPEID		8
#define FLOAT64_TYPEID		9
#define ENUMERATED8_TYPEID		10
#define ENUMERATED16_TYPEID		11
#define OCTET_STRING8_TYPEID		12
#define OCTET_STRING64_TYPEID		13
#define VISIBLE_STRING255_TYPEID		14
#define VISIBLE_STRING64_TYPEID		15
#define VISIBLE_STRING97_TYPEID		16
#define UTC_TM_TYPEID		17
#define CODED_ENUM2_TYPEID		18
#define UNICODE_STRING255_TYPEID		19
#define TimeStamp_TYPEID		20
#define EntryTime_TYPEID		21
#define Quality_TYPEID		22
#define IDENT_TYPEID		23
#define BOOL_TYPEID		24
#define B2_TYPEID		25
#define D_TYPEID		26
#define DB_TYPEID		27
#define F_TYPEID		28
#define FF_TYPEID		29
#define HL_TYPEID		30
#define HHL_TYPEID		31
#define LL_TYPEID		32
#define LLL_TYPEID		33
#define I_TYPEID		34
#define FI_TYPEID		35
#define O_TYPEID		36
#define Q_TYPEID		37
#define R_TYPEID		38
#define FR_TYPEID		39
#define S_TYPEID		40
#define T_TYPEID		41
#define FT_TYPEID		42
#define PP_TYPEID		43
#define U_TYPEID		44
#define VSTR8_TYPEID		45
#define VSTR16_TYPEID		46
#define VSTR32_TYPEID		47
#define VSTR64_TYPEID		48
#define VSTR65_TYPEID		49
#define VSTR128_TYPEID		50
#define BSTR1_TYPEID		51
#define BSTR2_TYPEID		52
#define BSTR8_TYPEID		53
#define BSTR10_TYPEID		54
#define BSTR16_TYPEID		55
#define BSTR32_TYPEID		56
#define VBSTR8_TYPEID		57
#define VBSTR16_TYPEID		58
#define VBSTR32_TYPEID		59
#define INT8S_TYPEID		60
#define INT16S_TYPEID		61
#define INT32S_TYPEID		62
#define FLT32_TYPEID		63
#define FLT64_TYPEID		64
#define BTIME4_TYPEID		65
#define BTIME6_TYPEID		66
#define ENUM8_TYPEID		67
#define ENUM16_TYPEID		68
#define MAG_TYPEID		69
#define ANG_TYPEID		70
#define ACCRPTENA_TYPEID		71
#define ACCRS_TYPEID		72
#define ACCSET_TYPEID		73
#define ACTTAGARR_TYPEID		74
#define ANCESTRY_TYPEID		75
#define ANFMT_TYPEID		76
#define BUFTIM_TYPEID		77
#define CID_TYPEID		78
#define CKTID_TYPEID		79
#define CKTPHS_TYPEID		80
#define CLASS_TYPEID		81
#define COMMADR_TYPEID		82
#define COMMREV_TYPEID		83
#define CONTCURRTG_TYPEID		84
#define COUNT_TYPEID		85
#define CRIRPT_TYPEID		86
#define DATSETNAM_TYPEID		87
#define DESTAE_TYPEID		88
#define DEVFCT_TYPEID		89
#define DEVMDLS_TYPEID		90
#define DOW_TYPEID		91
#define DOWSCHED_TYPEID		92
#define ENABLE_TYPEID		93
#define ENCOPT_TYPEID		94
#define ENROLL_TYPEID		95
#define EORBDESC_TYPEID		96
#define EVACON_TYPEID		97
#define EVACNS_TYPEID		98
#define EVACRI_TYPEID		99
#define EVAFCT_TYPEID		100
#define EVAPAR_TYPEID		101
#define EVTENA_TYPEID		102
#define FLTCURDUR_TYPEID		103
#define FLTCURRTG_TYPEID		104
#define FRZENA_TYPEID		105
#define FRZPD_TYPEID		106
#define FWDPWRHA_TYPEID		107
#define HWREV_TYPEID		108
#define HZRTG_TYPEID		109
#define INDAT_TYPEID		110
#define INTGPD_TYPEID		111
#define LINLENM_TYPEID		112
#define LOC_TYPEID		113
#define LOGENA_TYPEID		114
#define LOGENR_TYPEID		115
#define LOGNAM_TYPEID		116
#define LOGSIZE_TYPEID		117
#define LOGWRP_TYPEID		118
#define MAC_TYPEID		119
#define MDL_TYPEID		120
#define MED_TYPEID		121
#define MXREF_TYPEID		122
#define MXTYP_TYPEID		123
#define NAME_TYPEID		124
#define NEWTIM_TYPEID		125
#define NUMBITS_TYPEID		126
#define NUMPLS_TYPEID		127
#define NUMSMP_TYPEID		128
#define NUMUNIT_TYPEID		129
#define OFFDUR_TYPEID		130
#define OLDTIM_TYPEID		131
#define ONDUR_TYPEID		132
#define OPERDEV_TYPEID		133
#define OPTFLDS_TYPEID		134
#define OUTDAT_TYPEID		135
#define OVRST_TYPEID		136
#define OWN_TYPEID		137
#define PRO_TYPEID		138
#define PWRHA_TYPEID		139
#define QURPTENA_TYPEID		140
#define RBEPD_TYPEID		141
#define RPTENA_TYPEID		142
#define RPTID_TYPEID		143
#define RVSPWRHA_TYPEID		144
#define SBOENA_TYPEID		145
#define SETTIMOUT_TYPEID		146
#define SEQNUM_TYPEID		147
#define SERNUM_TYPEID		148
#define SFTREV_TYPEID		149
#define SMPRATE_TYPEID		150
#define TAGD_TYPEID		151
#define TAGID_TYPEID		152
#define TAGOWN_TYPEID		153
#define TAGTYP_TYPEID		154
#define TEMPRAT_TYPEID		155
#define TEMPRTG_TYPEID		156
#define TIMOFFRZ_TYPEID		157
#define TIMRPTENA_TYPEID		158
#define TRGOPS_TYPEID		159
#define TRGS_TYPEID		160
#define UNITVARRTG_TYPEID		161
#define UNKPWRHA_TYPEID		162
#define USEST_TYPEID		163
#define VARRTG_TYPEID		164
#define VARTG_TYPEID		165
#define VND_TYPEID		166
#define VRTG_TYPEID		167
#define WRNLEV_TYPEID		168
#define WRNST_TYPEID		169
#define PHSTAR_TYPEID		170
#define SBO_TYPEID		171
#define STNUM_TYPEID		172
#define HOLDTIM_TYPEID		173
#define BACKTIM_TYPEID		174
#define PHSID_TYPEID		175
#define DNA_TYPEID		176
#define USERST_TYPEID		177
#define RTYP_BOOL_TYPEID		178
#define RTYP_BTIME6_TYPEID		179
#define RTYP_BSTR6_TYPEID		180
#define RTYP_BSTR8_TYPEID		181
#define RTYP_BSTR9_TYPEID		182
#define RTYP_BVSTR6_TYPEID		183
#define RTYP_BVSTR8_TYPEID		184
#define RTYP_BVSTR10_TYPEID		185
#define RTYP_INT8U_TYPEID		186
#define RTYP_INT16U_TYPEID		187
#define RTYP_OSTR8_TYPEID		188
#define RTYP_VSTR32_TYPEID		189
#define RTYP_VSTR65_TYPEID		190
#define RTYP_INT32U_TYPEID		191
#define I16_TYPEID		192
#define UTF8VSTRING13_TYPEID		193
#define Originator_TYPEID		194
#define SBOw_BOOL_TYPEID		195
#define Cancel_BOOL_TYPEID		196
#define SBOw_INT_TYPEID		197
#define Cancel_INT_TYPEID		198
#define SBOw_INTU_TYPEID		199
#define Cancel_INTU_TYPEID		200


/************************************************************************/

/************************************************************************/


/*	Common Strings Index Defines	*/

#ifndef USE_RT_TYPE_2

#define FO_ORCAT_STRING_INDEX	 1
#define FO_ORIDENT_STRING_INDEX	 2
#define FO_CTLVAL_STRING_INDEX	 3
#define FO_OPERTM_STRING_INDEX	 4
#define FO_ORIGIN_STRING_INDEX	 5
#define FO_CTLNUM_STRING_INDEX	 6
#define FO_T_STRING_INDEX	 7
#define FO_TEST_STRING_INDEX	 8
#define FO_CHECK_STRING_INDEX	 9
#endif


/************************************************************************/
/* TYPEDEFS for MMS TYPES	                                              */
/************************************************************************/

/* Use ":CF", "-notypedefs" in the ODF file to not include this line */
#define USE_MMS_TYPEDEFS

#if defined (USE_MMS_TYPEDEFS)

typedef ST_BOOLEAN BOOLEAN_TDEF;

typedef ST_INT8 INT8_TDEF;

typedef ST_INT16 INT16_TDEF;

typedef ST_INT32 INT32_TDEF;

typedef ST_INT32 INT128_TDEF;

typedef ST_UINT8 INT8U_TDEF;

typedef ST_UINT16 INT16U_TDEF;

typedef ST_UINT32 INT32U_TDEF;

typedef ST_FLOAT FLOAT32_TDEF;

typedef ST_DOUBLE FLOAT64_TDEF;

typedef ST_INT8 ENUMERATED8_TDEF;

typedef ST_INT16 ENUMERATED16_TDEF;

typedef struct     /* OVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[8];
  }  OCTET_STRING8_TDEF;  /* Octetstring */

typedef struct     /* OVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[64];
  }  OCTET_STRING64_TDEF;  /* Octetstring */

typedef ST_CHAR VISIBLE_STRING255_TDEF[256];  /* Visible String */

typedef ST_CHAR VISIBLE_STRING64_TDEF[65];  /* Visible String */

typedef ST_CHAR VISIBLE_STRING97_TDEF[98];  /* Visible String */

typedef struct
  {
  ST_UINT32 secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 fraction;
  ST_UINT32 qflags;
  } UTC_TM_TDEF;

typedef ST_UCHAR CODED_ENUM2_TDEF[1];  /* Bitstring */

typedef ST_CHAR UNICODE_STRING255_TDEF[512];

typedef struct
  {
  ST_UINT32 secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 fraction;
  ST_UINT32 qflags;
  } TimeStamp_TDEF;

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } EntryTime_TDEF;

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[2];
  }  Quality_TDEF;  /* Bitstring */

typedef ST_CHAR IDENT_TDEF[66];  /* Visible String */

typedef ST_BOOLEAN BOOL_TDEF;

typedef ST_UCHAR B2_TDEF[1];  /* Bitstring */

typedef ST_CHAR D_TDEF[33];  /* Visible String */

typedef ST_UINT16 DB_TDEF;

typedef ST_FLOAT F_TDEF;

typedef ST_FLOAT FF_TDEF;

typedef ST_INT16 HL_TDEF;

typedef ST_INT16 HHL_TDEF;

typedef ST_INT16 LL_TDEF;

typedef ST_INT16 LLL_TDEF;

typedef ST_INT16 I_TDEF;

typedef ST_INT16 FI_TDEF;

typedef ST_FLOAT O_TDEF;

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[2];
  }  Q_TDEF;  /* Bitstring */

typedef ST_UINT32 R_TDEF;

typedef ST_UINT32 FR_TDEF;

typedef ST_FLOAT S_TDEF;

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } T_TDEF;

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } FT_TDEF;

typedef ST_BOOLEAN PP_TDEF;

typedef ST_INT16 U_TDEF;

typedef ST_CHAR VSTR8_TDEF[9];  /* Visible String */

typedef ST_CHAR VSTR16_TDEF[17];  /* Visible String */

typedef ST_CHAR VSTR32_TDEF[33];  /* Visible String */

typedef ST_CHAR VSTR64_TDEF[65];  /* Visible String */

typedef ST_CHAR VSTR65_TDEF[66];  /* Visible String */

typedef ST_CHAR VSTR128_TDEF[129];  /* Visible String */

typedef ST_UCHAR BSTR1_TDEF[1];  /* Bitstring */

typedef ST_UCHAR BSTR2_TDEF[1];  /* Bitstring */

typedef ST_UCHAR BSTR8_TDEF[1];  /* Bitstring */

typedef ST_UCHAR BSTR10_TDEF[2];  /* Bitstring */

typedef ST_UCHAR BSTR16_TDEF[2];  /* Bitstring */

typedef ST_UCHAR BSTR32_TDEF[4];  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[1];
  }  VBSTR8_TDEF;  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[2];
  }  VBSTR16_TDEF;  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[4];
  }  VBSTR32_TDEF;  /* Bitstring */

typedef ST_INT8 INT8S_TDEF;

typedef ST_INT16 INT16S_TDEF;

typedef ST_INT32 INT32S_TDEF;

typedef ST_FLOAT FLT32_TDEF;

typedef ST_DOUBLE FLT64_TDEF;

typedef ST_INT32  BTIME4_TDEF;  /* Btime4 is one ST_INT32 */

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } BTIME6_TDEF;

typedef ST_INT8 ENUM8_TDEF;

typedef ST_INT16 ENUM16_TDEF;

typedef ST_INT32 MAG_TDEF;

typedef ST_INT32 ANG_TDEF;

typedef ST_BOOLEAN ACCRPTENA_TDEF;

typedef ST_BOOLEAN ACCRS_TDEF;

typedef ST_CHAR ACCSET_TDEF[17];  /* Visible String */

typedef ST_UCHAR ACTTAGARR_TDEF[1];  /* Bitstring */

typedef ST_CHAR ANCESTRY_TDEF[33];  /* Visible String */

typedef ST_CHAR ANFMT_TDEF[7];  /* Visible String */

typedef ST_UINT32 BUFTIM_TDEF;

typedef ST_INT32 CID_TDEF;

typedef ST_CHAR CKTID_TDEF[33];  /* Visible String */

typedef ST_INT8 CKTPHS_TDEF;

typedef ST_CHAR CLASS_TDEF[33];  /* Visible String */

typedef ST_CHAR COMMADR_TDEF[17];  /* Visible String */

typedef ST_CHAR COMMREV_TDEF[9];  /* Visible String */

typedef ST_CHAR CONTCURRTG_TDEF[17];  /* Visible String */

typedef ST_UINT16 COUNT_TDEF;

typedef ST_BOOLEAN CRIRPT_TDEF;

typedef ST_CHAR DATSETNAM_TDEF[17];  /* Visible String */

typedef ST_CHAR DESTAE_TDEF[33];  /* Visible String */

typedef ST_UINT16 DEVFCT_TDEF;

typedef ST_CHAR DEVMDLS_TDEF[129];  /* Visible String */

typedef ST_INT8 DOW_TDEF;

typedef ST_INT32  DOWSCHED_TDEF[6];

typedef ST_BOOLEAN ENABLE_TDEF;

typedef ST_UCHAR ENCOPT_TDEF[1];  /* Bitstring */

typedef ST_CHAR ENROLL_TDEF[33];  /* Visible String */

typedef ST_CHAR EORBDESC_TDEF[65];  /* Visible String */

typedef ST_CHAR EVACON_TDEF[33];  /* Visible String */

typedef ST_CHAR EVACNS_TDEF[33];  /* Visible String */

typedef ST_CHAR EVACRI_TDEF[33];  /* Visible String */

typedef ST_CHAR EVAFCT_TDEF[33];  /* Visible String */

typedef ST_CHAR EVAPAR_TDEF[33];  /* Visible String */

typedef ST_BOOLEAN EVTENA_TDEF;

typedef ST_UINT16 FLTCURDUR_TDEF;

typedef ST_INT16 FLTCURRTG_TDEF;

typedef ST_BOOLEAN FRZENA_TDEF;

typedef ST_UINT32 FRZPD_TDEF;

typedef ST_FLOAT FWDPWRHA_TDEF[31];

typedef ST_CHAR HWREV_TDEF[9];  /* Visible String */

typedef ST_CHAR HZRTG_TDEF[33];  /* Visible String */

typedef ST_CHAR INDAT_TDEF[66];  /* Visible String */

typedef ST_UINT32 INTGPD_TDEF;

typedef ST_UINT16 LINLENM_TDEF;

typedef ST_CHAR LOC_TDEF[129];  /* Visible String */

typedef ST_BOOLEAN LOGENA_TDEF;

typedef ST_CHAR LOGENR_TDEF[33];  /* Visible String */

typedef ST_CHAR LOGNAM_TDEF[33];  /* Visible String */

typedef ST_UINT16 LOGSIZE_TDEF;

typedef ST_BOOLEAN LOGWRP_TDEF;

typedef ST_UINT8 MAC_TDEF;

typedef ST_CHAR MDL_TDEF[33];  /* Visible String */

typedef ST_INT8 MED_TDEF;

typedef ST_INT8 MXREF_TDEF;

typedef ST_INT8 MXTYP_TDEF;

typedef ST_CHAR NAME_TDEF[33];  /* Visible String */

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } NEWTIM_TDEF;

typedef ST_UINT16 NUMBITS_TDEF;

typedef ST_UINT16 NUMPLS_TDEF;

typedef ST_UINT16 NUMSMP_TDEF;

typedef ST_CHAR NUMUNIT_TDEF[33];  /* Visible String */

typedef ST_UINT32 OFFDUR_TDEF;

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } OLDTIM_TDEF;

typedef ST_UINT32 ONDUR_TDEF;

typedef ST_UCHAR OPERDEV_TDEF[1];  /* Bitstring */

typedef ST_UCHAR OPTFLDS_TDEF[2];  /* Bitstring */

typedef ST_CHAR OUTDAT_TDEF[66];  /* Visible String */

typedef ST_BOOLEAN OVRST_TDEF;

typedef ST_CHAR OWN_TDEF[33];  /* Visible String */

typedef ST_INT8 PRO_TDEF;

typedef ST_FLOAT PWRHA_TDEF[31];

typedef ST_BOOLEAN QURPTENA_TDEF;

typedef ST_UINT32 RBEPD_TDEF;

typedef ST_BOOLEAN RPTENA_TDEF;

typedef ST_CHAR RPTID_TDEF[66];  /* Visible String */

typedef ST_FLOAT RVSPWRHA_TDEF[31];

typedef ST_BOOLEAN SBOENA_TDEF;

typedef ST_UINT8 SETTIMOUT_TDEF;

typedef ST_UINT32 SEQNUM_TDEF;

typedef ST_CHAR SERNUM_TDEF[33];  /* Visible String */

typedef ST_CHAR SFTREV_TDEF[9];  /* Visible String */

typedef ST_UINT16 SMPRATE_TDEF;

typedef ST_CHAR TAGD_TDEF[129];  /* Visible String */

typedef ST_UINT8 TAGID_TDEF;

typedef ST_CHAR TAGOWN_TDEF[33];  /* Visible String */

typedef ST_UCHAR TAGTYP_TDEF[1];  /* Bitstring */

typedef ST_CHAR TEMPRAT_TDEF[17];  /* Visible String */

typedef ST_CHAR TEMPRTG_TDEF[17];  /* Visible String */

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } TIMOFFRZ_TDEF;

typedef ST_BOOLEAN TIMRPTENA_TDEF;

typedef ST_UCHAR TRGOPS_TDEF[1];  /* Bitstring */

typedef ST_UINT16 TRGS_TDEF;

typedef ST_CHAR UNITVARRTG_TDEF[33];  /* Visible String */

typedef ST_FLOAT UNKPWRHA_TDEF[31];

typedef ST_BOOLEAN USEST_TDEF;

typedef ST_CHAR VARRTG_TDEF[17];  /* Visible String */

typedef ST_CHAR VARTG_TDEF[17];  /* Visible String */

typedef ST_CHAR VND_TDEF[33];  /* Visible String */

typedef ST_CHAR VRTG_TDEF[17];  /* Visible String */

typedef ST_UINT16 WRNLEV_TDEF;

typedef ST_BOOLEAN WRNST_TDEF;

typedef ST_INT8 PHSTAR_TDEF;

typedef ST_CHAR SBO_TDEF[66];  /* Visible String */

typedef ST_UINT32 STNUM_TDEF;

typedef ST_UINT32 HOLDTIM_TDEF;

typedef ST_UINT32 BACKTIM_TDEF;

typedef ST_UINT16 PHSID_TDEF;

typedef ST_UCHAR DNA_TDEF[8];  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[16];
  }  USERST_TDEF;  /* Bitstring */

typedef ST_BOOLEAN RTYP_BOOL_TDEF;

typedef struct
  {
  ST_INT32 btime6_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 btime6_days;
  } RTYP_BTIME6_TDEF;

typedef ST_UCHAR RTYP_BSTR6_TDEF[1];  /* Bitstring */

typedef ST_UCHAR RTYP_BSTR8_TDEF[1];  /* Bitstring */

typedef ST_UCHAR RTYP_BSTR9_TDEF[2];  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[1];
  }  RTYP_BVSTR6_TDEF;  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[1];
  }  RTYP_BVSTR8_TDEF;  /* Bitstring */

typedef struct     /* BVstring */
  {
  ST_INT16 len_1;
  ST_UCHAR data_1[2];
  }  RTYP_BVSTR10_TDEF;  /* Bitstring */

typedef ST_UINT8 RTYP_INT8U_TDEF;

typedef ST_UINT16 RTYP_INT16U_TDEF;

typedef ST_UCHAR RTYP_OSTR8_TDEF[8];  /* Octetstring */

typedef ST_CHAR RTYP_VSTR32_TDEF[33];  /* Visible String */

typedef ST_CHAR RTYP_VSTR65_TDEF[66];  /* Visible String */

typedef ST_UINT32 RTYP_INT32U_TDEF;

typedef ST_INT16 I16_TDEF;

typedef ST_CHAR UTF8VSTRING13_TDEF[28];

typedef struct
  {
  ST_INT8 orCat;
  struct     /* OVstring */
    {
    ST_INT16 len_1;
    ST_UCHAR data_1[64];
    } orIdent;
  } Originator_TDEF;

typedef struct
  {
  ST_BOOLEAN ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  ST_UCHAR Check[1];
  } SBOw_BOOL_TDEF;

typedef struct
  {
  ST_BOOLEAN ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  } Cancel_BOOL_TDEF;

typedef struct
  {
  ST_INT32 ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  ST_UCHAR Check[1];
  } SBOw_INT_TDEF;

typedef struct
  {
  ST_INT32 ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  } Cancel_INT_TDEF;

typedef struct
  {
  ST_INT32 ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  ST_UCHAR Check[1];
  } SBOw_INTU_TDEF;

typedef struct
  {
  ST_INT32 ctlVal;
  ST_UINT32 operTm_secs;  /* UTC Time is struct of three ST_UINT32 */
  ST_UINT32 operTm_fraction;
  ST_UINT32 operTm_qflags;
  struct
    {
    ST_INT8 orCat;
    struct     /* OVstring */
      {
      ST_INT16 len_1;
      ST_UCHAR data_1[64];
      } orIdent;
    } origin;
  ST_UINT8 ctlNum;
  ST_INT32 T_ms;  /* Btime6 is two ST_INT32 */
  ST_INT32 T_days;
  ST_BOOLEAN Test;
  } Cancel_INTU_TDEF;

/************************************************************************/
#endif /* if defined (USE_MMS_TYPEDEFS) */
/************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* #ifndef FOUNDRY_OUTPUT_HEADER_INCLUDED */
