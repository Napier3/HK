
/************************************************************************/
/*  This file created from input file '..\..\mvl\usr\client\clntobj.odf'
    Leaf Access Parameter (LAP) File: 'Not Used'
	Created Fri Jun 15 18:37:57 2007
*/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mvl_acse.h"
#include "clntobj.h"

#include "client.h"	/* User Specified */

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__; 
#endif


/************************************************************************/
#ifndef _MVL_TYPE_CTRL_use_one_device_
MVL_TYPE_CTRL *mvl_type_ctrl;
#else
MVL_TYPE_CTRL *g_mvl_type_ctrl;
#endif

ST_INT mvl_num_types;
MVL_VMD_CTRL mvl_vmd;

/************************************************************************/

/* Alignment Table:               */
/*  {                             */
/*  0x0000,    ARRSTRT_ALGN   00  */
/*  0x0000,    ARREND_ALGN    01  */
/*  0x0000,    STRSTRT_ALGN   02  */
/*  0x0000,    STREND_ALGN    03  */
/*  0x0000,    INT8_ALGN      04  */
/*  0x0001,    INT16_ALGN     05  */
/*  0x0003,    INT32_ALGN     06  */
/*  0x0007,    INT64_ALGN     07  */
/*  0x0003,    FLOAT_ALGN     08  */
/*  0x0007,    DOUBLE_ALGN    09  */
/*  0x0000,    OCT_ALGN       10  */
/*  0x0000,    BOOL_ALGN      11  */
/*  0x0000,    BCD1_ALGN      12  */
/*  0x0001,    BCD2_ALGN      13  */
/*  0x0003,    BCD4_ALGN      14  */
/*  0x0000,    BIT_ALGN       15  */
/*  0x0000     VIS_ALGN       16  */
/*  };                            */

/************************************************************************/


/*	Common Strings Table	*/
ST_INT numMvlRtNames;
#ifdef USE_RT_TYPE_2
ST_CHAR mvlCompName_ [] = "";
ST_CHAR mvlCompName_orCat [] = "orCat";
ST_CHAR mvlCompName_orIdent [] = "orIdent";
ST_CHAR mvlCompName_ctlVal [] = "ctlVal";
ST_CHAR mvlCompName_operTm [] = "operTm";
ST_CHAR mvlCompName_origin [] = "origin";
ST_CHAR mvlCompName_ctlNum [] = "ctlNum";
ST_CHAR mvlCompName_T [] = "T";
ST_CHAR mvlCompName_Test [] = "Test";
ST_CHAR mvlCompName_Check [] = "Check";
#else	/* !USE_RT_TYPE_2	*/
SD_CONST ST_CHAR *SD_CONST foMvlRtNames[] =
  {
  "",
  "orCat",
  "orIdent",
  "ctlVal",
  "operTm",
  "origin",
  "ctlNum",
  "T",
  "Test",
  "Check"
  };

ST_CHAR **mvlRtNames;
ST_INT maxMvlRtNames;
#endif	/* !USE_RT_TYPE_2	*/

/************************************************************************/

/* MMS OBJECT INITIALIZATION */

#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_VOID mvl_init_type_ctrl (MVL_TYPE_CTRL **pp_mvl_type_ctrl);
#else
ST_VOID mvl_init_type_ctrl ();
#endif

static ST_VOID mvl_init_vmd_vars (ST_VOID);
static ST_VOID mvl_init_dom_vars (ST_VOID);
static ST_VOID mvl_init_aa_vars (ST_VOID);
static ST_VOID mvl_init_vmd_varLists (ST_VOID);
static ST_VOID mvl_init_dom_varLists (ST_VOID);
static ST_VOID mvl_init_aa_varLists (ST_VOID);
static ST_VOID mvl_init_journals (ST_VOID);

ST_VOID mvl_init_mms_objs ()
  {
ST_INT i;
static ST_BOOLEAN _mvlInitMmsObjsCalled = SD_FALSE;

/* Make sure called ONLY once (from mvl_start_acse)	*/
  assert (_mvlInitMmsObjsCalled == SD_FALSE);
  _mvlInitMmsObjsCalled = SD_TRUE;

/* Make sure conn_ctrl allocated (by mvl_start_acse)	*/
  assert (mvl_calling_conn_ctrl || mvl_called_conn_ctrl);

/* Set up the AA Control structures */
  for (i = 0; i < mvl_cfg_info->num_called; ++i)
    mvl_called_conn_ctrl[i].aa_objs = (MVL_AA_OBJ_CTRL *) M_CALLOC (MSMEM_STARTUP, 1, sizeof(MVL_AA_OBJ_CTRL));
  for (i = 0; i < mvl_cfg_info->num_calling; ++i)
    mvl_calling_conn_ctrl[i].aa_objs = (MVL_AA_OBJ_CTRL *) M_CALLOC (MSMEM_STARTUP, 1, sizeof(MVL_AA_OBJ_CTRL));

#ifndef _MVL_TYPE_CTRL_use_one_device_
  mvl_init_type_ctrl ();
#endif

  mvl_init_vmd_vars ();
  mvl_init_dom_vars ();
  mvl_init_aa_vars ();
  mvl_init_vmd_varLists ();
  mvl_init_dom_varLists ();
  mvl_init_aa_varLists ();
  mvl_init_journals ();
  }
/************************************************************************/

/* VMD WIDE NAMED VARIABLE ASSOCIATION INITIALIZATION */

static ST_VOID mvl_init_vmd_vars ()
  {
MVL_VAR_ASSOC **ppva;

  mvl_vmd.max_num_var_assoc = 0 + MVL_NUM_DYN_VMD_VARS;
  mvl_vmd.num_var_assoc = 0;
  if (mvl_vmd.max_num_var_assoc != 0)
    mvl_vmd.var_assoc_tbl = ppva = (MVL_VAR_ASSOC **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_VMD_VARS, sizeof (MVL_VAR_ASSOC *));
  }
/************************************************************************/

/* DOMAIN VARIABLE INITIALIZATION */
static ST_VOID mvl_init_dom_vars ()
  {
MVL_DOM_CTRL **ppdom;

  mvl_vmd.num_dom = 0;
  mvl_vmd.max_num_dom = 0 + MVL_NUM_DYN_DOMS;
  mvl_vmd.dom_tbl = ppdom = (MVL_DOM_CTRL **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_DOMS, sizeof (MVL_DOM_CTRL *));
  }

/************************************************************************/

/* AA VARIABLE INITIALIZATION */
static ST_VOID mvl_init_aa_vars ()
  {
MVL_AA_OBJ_CTRL *aa;
MVL_VAR_ASSOC **ppva;
ST_INT i;
ST_INT j;

/* Do AA specific variables */
  i = 0;
  for (j = 0; j < mvl_cfg_info->num_called; ++j, ++i)
    {
    aa = (MVL_AA_OBJ_CTRL *) mvl_called_conn_ctrl[j].aa_objs;
    aa->foundry_objects = SD_TRUE;
    aa->max_num_var_assoc = 0 + MVL_NUM_DYN_AA_VARS;
    aa->num_var_assoc = 0;
#if (0 + MVL_NUM_DYN_AA_VARS)
    aa->var_assoc_tbl = ppva = (MVL_VAR_ASSOC **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_AA_VARS, sizeof (MVL_VAR_ASSOC *));
#endif
    }
  for (j = 0; j < mvl_cfg_info->num_calling; ++j, ++i)
    {
    aa = (MVL_AA_OBJ_CTRL *) mvl_calling_conn_ctrl[j].aa_objs;
    aa->foundry_objects = SD_TRUE;
    aa->max_num_var_assoc = 0 + MVL_NUM_DYN_AA_VARS;
    aa->num_var_assoc = 0;
#if (0 + MVL_NUM_DYN_AA_VARS)
    aa->var_assoc_tbl = ppva = (MVL_VAR_ASSOC **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_AA_VARS, sizeof (MVL_VAR_ASSOC *));
#endif
    }
  }

/************************************************************************/

/* NAMED VARIABLE LIST INITIALIZATION */

static ST_VOID mvl_init_vmd_varLists ()
  {
MVL_NVLIST_CTRL **ppvl;

/* Do VMD wide variable lists */
  mvl_vmd.max_num_nvlist = 0 + MVL_NUM_DYN_VMD_NVLS;
  mvl_vmd.num_nvlist = 0;
  if (mvl_vmd.max_num_nvlist != 0)
    mvl_vmd.nvlist_tbl = ppvl = (MVL_NVLIST_CTRL **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_VMD_NVLS, sizeof (MVL_NVLIST_CTRL *));
  }
/************************************************************************/

/* DOMAIN VARIABLE LIST INITIALIZATION */
static ST_VOID mvl_init_dom_varLists ()
  {
  }

/************************************************************************/

/* AA VARIABLE LIST INITIALIZATION */
static ST_VOID mvl_init_aa_varLists ()
  {
MVL_AA_OBJ_CTRL *aa;
MVL_NVLIST_CTRL **ppvl;
ST_INT i;


/* Now do AA specific Variable Lists */
  for (i = 0; i < mvl_cfg_info->num_called; ++i)
    {
    aa = (MVL_AA_OBJ_CTRL *) mvl_called_conn_ctrl[i].aa_objs;
    aa->foundry_objects = SD_TRUE;
    aa->max_num_nvlist = 0 + MVL_NUM_DYN_AA_NVLS;
    aa->num_nvlist = 0;
#if (0 + MVL_NUM_DYN_AA_NVLS)
    aa->nvlist_tbl = ppvl = (MVL_NVLIST_CTRL **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_AA_NVLS, sizeof (MVL_NVLIST_CTRL *));
#endif
    }
  for (i = 0; i < mvl_cfg_info->num_calling; ++i)
    {
    aa = (MVL_AA_OBJ_CTRL *) mvl_calling_conn_ctrl[i].aa_objs;
    aa->foundry_objects = SD_TRUE;
    aa->max_num_nvlist = 0 + MVL_NUM_DYN_AA_NVLS;
    aa->num_nvlist = 0;
#if (0 + MVL_NUM_DYN_AA_NVLS)
    aa->nvlist_tbl = ppvl = (MVL_NVLIST_CTRL **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_AA_NVLS, sizeof (MVL_NVLIST_CTRL *));
#endif
    }
  }

/************************************************************************/

/* JOURNAL INITIALIZATION */
static ST_VOID mvl_init_journals ()
  {
MVL_JOURNAL_CTRL **ppjou;

  /* initialize VMD_SPEC journals */

  mvl_vmd.max_num_jou = 0 + MVL_NUM_DYN_JOUS;
  mvl_vmd.num_jou = 0;
  if (mvl_vmd.max_num_jou != 0)
    mvl_vmd.jou_tbl = ppjou = (MVL_JOURNAL_CTRL **) M_CALLOC (MSMEM_STARTUP, 0 + MVL_NUM_DYN_JOUS, sizeof (MVL_JOURNAL_CTRL *));
  }

/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_VOID mvl_init_type_ctrl (MVL_TYPE_CTRL **pp_mvl_type_ctrl)
{
	MVL_TYPE_CTRL *mvl_type_ctrl;
#else
ST_VOID mvl_init_type_ctrl ()
{
	static ST_BOOLEAN _mvlInitTypeCtrlCalled = SD_FALSE;

	if (_mvlInitTypeCtrlCalled == SD_TRUE)
		return;
	_mvlInitTypeCtrlCalled = SD_TRUE;

#endif


#ifndef USE_RT_TYPE_2
  maxMvlRtNames = 10;
  numMvlRtNames = 10;
  mvlRtNames = foMvlRtNames;
#endif
  if (_mvlu_num_dyn_types == 0)
    _mvlu_num_dyn_types = MVLU_NUM_DYN_TYPES;

  mvl_num_types = 201 + _mvlu_num_dyn_types;
  mvl_type_ctrl = (MVL_TYPE_CTRL *) M_CALLOC (MSMEM_STARTUP, 201 + _mvlu_num_dyn_types, sizeof(MVL_TYPE_CTRL));
#if defined USR_SUPPLIED_RT
  u_mvl_start_init_rt_tbl (201, 277);
#endif

/* BOOLEAN : :T */
/*
  mvl_type_ctrl[BOOLEAN_TYPEID].tdl = 
  "Bool";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BOOLEAN_TYPEID].asn1_len = 2;
  mvl_type_ctrl[BOOLEAN_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[BOOLEAN_TYPEID].num_rt = 1;
  mvl_type_ctrl[BOOLEAN_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BOOLEAN_TYPEID].rt = u_mvl_get_rt_tbl (BOOLEAN_TYPEID, 1);
#else
  mvl_type_ctrl[BOOLEAN_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BOOLEAN_TYPEID].type_name, "BOOLEAN");

/* INT8 : -128 to 127 */
/*
  mvl_type_ctrl[INT8_TYPEID].tdl = 
  "Byte";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT8_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[INT8_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT8_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT8_TYPEID].rt = u_mvl_get_rt_tbl (INT8_TYPEID, 1);
#else
  mvl_type_ctrl[INT8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT8_TYPEID].type_name, "INT8");

/* INT16 : -32,768 to 32,767 */
/*
  mvl_type_ctrl[INT16_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT16_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[INT16_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT16_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT16_TYPEID].rt = u_mvl_get_rt_tbl (INT16_TYPEID, 1);
#else
  mvl_type_ctrl[INT16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT16_TYPEID].type_name, "INT16");

/* INT32 : -2,147,483,648 to 2,147,483,647 */
/*
  mvl_type_ctrl[INT32_TYPEID].tdl = 
  "Long";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT32_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT32_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[INT32_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT32_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT32_TYPEID].rt = u_mvl_get_rt_tbl (INT32_TYPEID, 1);
#else
  mvl_type_ctrl[INT32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT32_TYPEID].type_name, "INT32");

/* INT128 : -2**127 to (2**127)-1 Good luck */
/*
  mvl_type_ctrl[INT128_TYPEID].tdl = 
  "Long";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT128_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT128_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[INT128_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT128_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT128_TYPEID].rt = u_mvl_get_rt_tbl (INT128_TYPEID, 1);
#else
  mvl_type_ctrl[INT128_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT128_TYPEID].type_name, "INT128");

/* INT8U : 0 to 255 */
/*
  mvl_type_ctrl[INT8U_TYPEID].tdl = 
  "Ubyte";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT8U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT8U_TYPEID].asn1 = "\x86\x01\x08";
#endif
  mvl_type_ctrl[INT8U_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT8U_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT8U_TYPEID].rt = u_mvl_get_rt_tbl (INT8U_TYPEID, 1);
#else
  mvl_type_ctrl[INT8U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT8U_TYPEID].type_name, "INT8U");

/* INT16U : 0 to 65,535 */
/*
  mvl_type_ctrl[INT16U_TYPEID].tdl = 
  "Ushort";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT16U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT16U_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[INT16U_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT16U_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT16U_TYPEID].rt = u_mvl_get_rt_tbl (INT16U_TYPEID, 1);
#else
  mvl_type_ctrl[INT16U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT16U_TYPEID].type_name, "INT16U");

/* INT32U : 0 to 4,294,967,295 */
/*
  mvl_type_ctrl[INT32U_TYPEID].tdl = 
  "Ulong";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT32U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT32U_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[INT32U_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT32U_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT32U_TYPEID].rt = u_mvl_get_rt_tbl (INT32U_TYPEID, 1);
#else
  mvl_type_ctrl[INT32U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT32U_TYPEID].type_name, "INT32U");

/* FLOAT32 : Range of values IEEE 754 single */
/*
  mvl_type_ctrl[FLOAT32_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLOAT32_TYPEID].asn1_len = 8;
  mvl_type_ctrl[FLOAT32_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[FLOAT32_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLOAT32_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLOAT32_TYPEID].rt = u_mvl_get_rt_tbl (FLOAT32_TYPEID, 1);
#else
  mvl_type_ctrl[FLOAT32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLOAT32_TYPEID].type_name, "FLOAT32");

/* FLOAT64 : Range of values IEEE 754 double */
/*
  mvl_type_ctrl[FLOAT64_TYPEID].tdl = 
  "Double";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLOAT64_TYPEID].asn1_len = 8;
  mvl_type_ctrl[FLOAT64_TYPEID].asn1 = "\xa7\x06\x02\x01\x40\x02\x01\x0b";
#endif
  mvl_type_ctrl[FLOAT64_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLOAT64_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLOAT64_TYPEID].rt = u_mvl_get_rt_tbl (FLOAT64_TYPEID, 1);
#else
  mvl_type_ctrl[FLOAT64_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLOAT64_TYPEID].type_name, "FLOAT64");

/* ENUMERATED8 : signed enumeration8-bits */
/*
  mvl_type_ctrl[ENUMERATED8_TYPEID].tdl = 
  "Byte";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENUMERATED8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENUMERATED8_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[ENUMERATED8_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENUMERATED8_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENUMERATED8_TYPEID].rt = u_mvl_get_rt_tbl (ENUMERATED8_TYPEID, 1);
#else
  mvl_type_ctrl[ENUMERATED8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENUMERATED8_TYPEID].type_name, "ENUMERATED8");

/* ENUMERATED16 : signed enumeration16-bits */
/*
  mvl_type_ctrl[ENUMERATED16_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENUMERATED16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENUMERATED16_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[ENUMERATED16_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENUMERATED16_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENUMERATED16_TYPEID].rt = u_mvl_get_rt_tbl (ENUMERATED16_TYPEID, 1);
#else
  mvl_type_ctrl[ENUMERATED16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENUMERATED16_TYPEID].type_name, "ENUMERATED16");

/* OCTET_STRING8 : Maximum 8 Octets */
/*
  mvl_type_ctrl[OCTET_STRING8_TYPEID].tdl = 
  "OVstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OCTET_STRING8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OCTET_STRING8_TYPEID].asn1 = "\x89\x01\xf8";
#endif
  mvl_type_ctrl[OCTET_STRING8_TYPEID].num_rt = 1;
  mvl_type_ctrl[OCTET_STRING8_TYPEID].data_size = 10;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OCTET_STRING8_TYPEID].rt = u_mvl_get_rt_tbl (OCTET_STRING8_TYPEID, 1);
#else
  mvl_type_ctrl[OCTET_STRING8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OCTET_STRING8_TYPEID].type_name, "OCTET_STRING8");

/* OCTET_STRING64 : Maximum 64 Octets */
/*
  mvl_type_ctrl[OCTET_STRING64_TYPEID].tdl = 
  "OVstring64";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OCTET_STRING64_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OCTET_STRING64_TYPEID].asn1 = "\x89\x01\xc0";
#endif
  mvl_type_ctrl[OCTET_STRING64_TYPEID].num_rt = 1;
  mvl_type_ctrl[OCTET_STRING64_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OCTET_STRING64_TYPEID].rt = u_mvl_get_rt_tbl (OCTET_STRING64_TYPEID, 1);
#else
  mvl_type_ctrl[OCTET_STRING64_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OCTET_STRING64_TYPEID].type_name, "OCTET_STRING64");

/* VISIBLE_STRING255 : Maximum 255 characters */
/*
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].tdl = 
  "Vstring255";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].asn1_len = 4;
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].asn1 = "\x8a\x02\xff\x01";
#endif
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].num_rt = 1;
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].data_size = 256;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].rt = u_mvl_get_rt_tbl (VISIBLE_STRING255_TYPEID, 1);
#else
  mvl_type_ctrl[VISIBLE_STRING255_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VISIBLE_STRING255_TYPEID].type_name, "VISIBLE_STRING255");

/* VISIBLE_STRING64 : Maximum 64 characters */
/*
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].tdl = 
  "Vstring64";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].asn1 = "\x8a\x01\xc0";
#endif
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].num_rt = 1;
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].data_size = 65;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].rt = u_mvl_get_rt_tbl (VISIBLE_STRING64_TYPEID, 1);
#else
  mvl_type_ctrl[VISIBLE_STRING64_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VISIBLE_STRING64_TYPEID].type_name, "VISIBLE_STRING64");

/* VISIBLE_STRING97 : Maximum 97 characters */
/*
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].tdl = 
  "Vstring97";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].asn1 = "\x8a\x01\x9f";
#endif
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].num_rt = 1;
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].data_size = 98;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].rt = u_mvl_get_rt_tbl (VISIBLE_STRING97_TYPEID, 1);
#else
  mvl_type_ctrl[VISIBLE_STRING97_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VISIBLE_STRING97_TYPEID].type_name, "VISIBLE_STRING97");

/* UTC_TM : Used by TimeStamp */
/*
  mvl_type_ctrl[UTC_TM_TYPEID].tdl = 
  "Utctime";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[UTC_TM_TYPEID].asn1_len = 2;
  mvl_type_ctrl[UTC_TM_TYPEID].asn1 = "\x91\x00";
#endif
  mvl_type_ctrl[UTC_TM_TYPEID].num_rt = 1;
  mvl_type_ctrl[UTC_TM_TYPEID].data_size = 12;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[UTC_TM_TYPEID].rt = u_mvl_get_rt_tbl (UTC_TM_TYPEID, 1);
#else
  mvl_type_ctrl[UTC_TM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[UTC_TM_TYPEID].type_name, "UTC_TM");

/* CODED_ENUM2 : 2 bits - 4 values */
/*
  mvl_type_ctrl[CODED_ENUM2_TYPEID].tdl = 
  "Bstring2";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CODED_ENUM2_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CODED_ENUM2_TYPEID].asn1 = "\x84\x01\x02";
#endif
  mvl_type_ctrl[CODED_ENUM2_TYPEID].num_rt = 1;
  mvl_type_ctrl[CODED_ENUM2_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CODED_ENUM2_TYPEID].rt = u_mvl_get_rt_tbl (CODED_ENUM2_TYPEID, 1);
#else
  mvl_type_ctrl[CODED_ENUM2_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CODED_ENUM2_TYPEID].type_name, "CODED_ENUM2");

/* UNICODE_STRING255 : Maximum 255 Unicode */
/*
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].tdl = 
  "UTF8Vstring255";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].asn1_len = 4;
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].asn1 = "\x90\x02\xff\x01";
#endif
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].num_rt = 1;
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].data_size = 512;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].rt = u_mvl_get_rt_tbl (UNICODE_STRING255_TYPEID, 1);
#else
  mvl_type_ctrl[UNICODE_STRING255_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[UNICODE_STRING255_TYPEID].type_name, "UNICODE_STRING255");

/* TimeStamp : UTC Time */
/*
  mvl_type_ctrl[TimeStamp_TYPEID].tdl = 
  "<UTC_TM>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TimeStamp_TYPEID].asn1_len = 2;
  mvl_type_ctrl[TimeStamp_TYPEID].asn1 = "\x91\x00";
#endif
  mvl_type_ctrl[TimeStamp_TYPEID].num_rt = 1;
  mvl_type_ctrl[TimeStamp_TYPEID].data_size = 12;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TimeStamp_TYPEID].rt = u_mvl_get_rt_tbl (TimeStamp_TYPEID, 1);
#else
  mvl_type_ctrl[TimeStamp_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TimeStamp_TYPEID].type_name, "TimeStamp");

/* EntryTime :  8.1 Section 8.1.3.7 */
/*
  mvl_type_ctrl[EntryTime_TYPEID].tdl = 
  "Btime6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EntryTime_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EntryTime_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[EntryTime_TYPEID].num_rt = 1;
  mvl_type_ctrl[EntryTime_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EntryTime_TYPEID].rt = u_mvl_get_rt_tbl (EntryTime_TYPEID, 1);
#else
  mvl_type_ctrl[EntryTime_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EntryTime_TYPEID].type_name, "EntryTime");

/* Quality : Quality */
/*
  mvl_type_ctrl[Quality_TYPEID].tdl = 
  "BVstring13";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Quality_TYPEID].asn1_len = 3;
  mvl_type_ctrl[Quality_TYPEID].asn1 = "\x84\x01\xf3";
#endif
  mvl_type_ctrl[Quality_TYPEID].num_rt = 1;
  mvl_type_ctrl[Quality_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Quality_TYPEID].rt = u_mvl_get_rt_tbl (Quality_TYPEID, 1);
#else
  mvl_type_ctrl[Quality_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Quality_TYPEID].type_name, "Quality");

/* IDENT :  */
/*
  mvl_type_ctrl[IDENT_TYPEID].tdl = 
  "Vstring65";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[IDENT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[IDENT_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[IDENT_TYPEID].num_rt = 1;
  mvl_type_ctrl[IDENT_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[IDENT_TYPEID].rt = u_mvl_get_rt_tbl (IDENT_TYPEID, 1);
#else
  mvl_type_ctrl[IDENT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[IDENT_TYPEID].type_name, "IDENT");

/* BOOL : generalboolean */
/*
  mvl_type_ctrl[BOOL_TYPEID].tdl = 
  "Bool";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BOOL_TYPEID].asn1_len = 2;
  mvl_type_ctrl[BOOL_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[BOOL_TYPEID].num_rt = 1;
  mvl_type_ctrl[BOOL_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BOOL_TYPEID].rt = u_mvl_get_rt_tbl (BOOL_TYPEID, 1);
#else
  mvl_type_ctrl[BOOL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BOOL_TYPEID].type_name, "BOOL");

/* B2 : GeneralDoubleBit */
/*
  mvl_type_ctrl[B2_TYPEID].tdl = 
  "Bstring2";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[B2_TYPEID].asn1_len = 3;
  mvl_type_ctrl[B2_TYPEID].asn1 = "\x84\x01\x02";
#endif
  mvl_type_ctrl[B2_TYPEID].num_rt = 1;
  mvl_type_ctrl[B2_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[B2_TYPEID].rt = u_mvl_get_rt_tbl (B2_TYPEID, 1);
#else
  mvl_type_ctrl[B2_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[B2_TYPEID].type_name, "B2");

/* D : generaldescriptioncomponent */
/*
  mvl_type_ctrl[D_TYPEID].tdl = 
  "VString32";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[D_TYPEID].asn1_len = 3;
  mvl_type_ctrl[D_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[D_TYPEID].num_rt = 1;
  mvl_type_ctrl[D_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[D_TYPEID].rt = u_mvl_get_rt_tbl (D_TYPEID, 1);
#else
  mvl_type_ctrl[D_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[D_TYPEID].type_name, "D");

/* DB : Deadband */
/*
  mvl_type_ctrl[DB_TYPEID].tdl = 
  "UShort";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DB_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DB_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[DB_TYPEID].num_rt = 1;
  mvl_type_ctrl[DB_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DB_TYPEID].rt = u_mvl_get_rt_tbl (DB_TYPEID, 1);
#else
  mvl_type_ctrl[DB_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DB_TYPEID].type_name, "DB");

/* F : Generalizedfloatingpoint */
/*
  mvl_type_ctrl[F_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[F_TYPEID].asn1_len = 8;
  mvl_type_ctrl[F_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[F_TYPEID].num_rt = 1;
  mvl_type_ctrl[F_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[F_TYPEID].rt = u_mvl_get_rt_tbl (F_TYPEID, 1);
#else
  mvl_type_ctrl[F_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[F_TYPEID].type_name, "F");

/* FF : FrozenFloatingPointvalue */
/*
  mvl_type_ctrl[FF_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FF_TYPEID].asn1_len = 8;
  mvl_type_ctrl[FF_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[FF_TYPEID].num_rt = 1;
  mvl_type_ctrl[FF_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FF_TYPEID].rt = u_mvl_get_rt_tbl (FF_TYPEID, 1);
#else
  mvl_type_ctrl[FF_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FF_TYPEID].type_name, "FF");

/* HL : HighLimit */
/*
  mvl_type_ctrl[HL_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[HL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[HL_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[HL_TYPEID].num_rt = 1;
  mvl_type_ctrl[HL_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[HL_TYPEID].rt = u_mvl_get_rt_tbl (HL_TYPEID, 1);
#else
  mvl_type_ctrl[HL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[HL_TYPEID].type_name, "HL");

/* HHL : HighHighLimit */
/*
  mvl_type_ctrl[HHL_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[HHL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[HHL_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[HHL_TYPEID].num_rt = 1;
  mvl_type_ctrl[HHL_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[HHL_TYPEID].rt = u_mvl_get_rt_tbl (HHL_TYPEID, 1);
#else
  mvl_type_ctrl[HHL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[HHL_TYPEID].type_name, "HHL");

/* LL : lowlimit */
/*
  mvl_type_ctrl[LL_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LL_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[LL_TYPEID].num_rt = 1;
  mvl_type_ctrl[LL_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LL_TYPEID].rt = u_mvl_get_rt_tbl (LL_TYPEID, 1);
#else
  mvl_type_ctrl[LL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LL_TYPEID].type_name, "LL");

/* LLL : lowlowlimit */
/*
  mvl_type_ctrl[LLL_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LLL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LLL_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[LLL_TYPEID].num_rt = 1;
  mvl_type_ctrl[LLL_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LLL_TYPEID].rt = u_mvl_get_rt_tbl (LLL_TYPEID, 1);
#else
  mvl_type_ctrl[LLL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LLL_TYPEID].type_name, "LLL");

/* I : Generalizedicomponenttype */
/*
  mvl_type_ctrl[I_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[I_TYPEID].asn1_len = 3;
  mvl_type_ctrl[I_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[I_TYPEID].num_rt = 1;
  mvl_type_ctrl[I_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[I_TYPEID].rt = u_mvl_get_rt_tbl (I_TYPEID, 1);
#else
  mvl_type_ctrl[I_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[I_TYPEID].type_name, "I");

/* FI : frozenicomponenttype */
/*
  mvl_type_ctrl[FI_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FI_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FI_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[FI_TYPEID].num_rt = 1;
  mvl_type_ctrl[FI_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FI_TYPEID].rt = u_mvl_get_rt_tbl (FI_TYPEID, 1);
#else
  mvl_type_ctrl[FI_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FI_TYPEID].type_name, "FI");

/* O : Offset */
/*
  mvl_type_ctrl[O_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[O_TYPEID].asn1_len = 8;
  mvl_type_ctrl[O_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[O_TYPEID].num_rt = 1;
  mvl_type_ctrl[O_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[O_TYPEID].rt = u_mvl_get_rt_tbl (O_TYPEID, 1);
#else
  mvl_type_ctrl[O_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[O_TYPEID].type_name, "O");

/* Q : Generalizedqualitybitstringtype */
/*
  mvl_type_ctrl[Q_TYPEID].tdl = 
  "Bvstring16";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Q_TYPEID].asn1_len = 3;
  mvl_type_ctrl[Q_TYPEID].asn1 = "\x84\x01\xf0";
#endif
  mvl_type_ctrl[Q_TYPEID].num_rt = 1;
  mvl_type_ctrl[Q_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Q_TYPEID].rt = u_mvl_get_rt_tbl (Q_TYPEID, 1);
#else
  mvl_type_ctrl[Q_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Q_TYPEID].type_name, "Q");

/* R : runningcount */
/*
  mvl_type_ctrl[R_TYPEID].tdl = 
  "ULong";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[R_TYPEID].asn1_len = 3;
  mvl_type_ctrl[R_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[R_TYPEID].num_rt = 1;
  mvl_type_ctrl[R_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[R_TYPEID].rt = u_mvl_get_rt_tbl (R_TYPEID, 1);
#else
  mvl_type_ctrl[R_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[R_TYPEID].type_name, "R");

/* FR : frozenrunningcount */
/*
  mvl_type_ctrl[FR_TYPEID].tdl = 
  "ULong";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FR_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[FR_TYPEID].num_rt = 1;
  mvl_type_ctrl[FR_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FR_TYPEID].rt = u_mvl_get_rt_tbl (FR_TYPEID, 1);
#else
  mvl_type_ctrl[FR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FR_TYPEID].type_name, "FR");

/* S : scale */
/*
  mvl_type_ctrl[S_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[S_TYPEID].asn1_len = 8;
  mvl_type_ctrl[S_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[S_TYPEID].num_rt = 1;
  mvl_type_ctrl[S_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[S_TYPEID].rt = u_mvl_get_rt_tbl (S_TYPEID, 1);
#else
  mvl_type_ctrl[S_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[S_TYPEID].type_name, "S");

/* T : GeneralizedTimeStamp */
/*
  mvl_type_ctrl[T_TYPEID].tdl = 
  "Btime6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[T_TYPEID].asn1_len = 3;
  mvl_type_ctrl[T_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[T_TYPEID].num_rt = 1;
  mvl_type_ctrl[T_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[T_TYPEID].rt = u_mvl_get_rt_tbl (T_TYPEID, 1);
#else
  mvl_type_ctrl[T_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[T_TYPEID].type_name, "T");

/* FT : frozentimestamp */
/*
  mvl_type_ctrl[FT_TYPEID].tdl = 
  "Btime6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FT_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[FT_TYPEID].num_rt = 1;
  mvl_type_ctrl[FT_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FT_TYPEID].rt = u_mvl_get_rt_tbl (FT_TYPEID, 1);
#else
  mvl_type_ctrl[FT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FT_TYPEID].type_name, "FT");

/* PP : PseudoPoint */
/*
  mvl_type_ctrl[PP_TYPEID].tdl = 
  "Bool";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[PP_TYPEID].asn1_len = 2;
  mvl_type_ctrl[PP_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[PP_TYPEID].num_rt = 1;
  mvl_type_ctrl[PP_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[PP_TYPEID].rt = u_mvl_get_rt_tbl (PP_TYPEID, 1);
#else
  mvl_type_ctrl[PP_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[PP_TYPEID].type_name, "PP");

/* U : Enumeratevalue */
/*
  mvl_type_ctrl[U_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[U_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[U_TYPEID].num_rt = 1;
  mvl_type_ctrl[U_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[U_TYPEID].rt = u_mvl_get_rt_tbl (U_TYPEID, 1);
#else
  mvl_type_ctrl[U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[U_TYPEID].type_name, "U");

/* VSTR8 : VisibleString8-variablelength */
/*
  mvl_type_ctrl[VSTR8_TYPEID].tdl = 
  "Vstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR8_TYPEID].asn1 = "\x8a\x01\xf8";
#endif
  mvl_type_ctrl[VSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR8_TYPEID].data_size = 9;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR8_TYPEID].rt = u_mvl_get_rt_tbl (VSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR8_TYPEID].type_name, "VSTR8");

/* VSTR16 : VisibleString16-variablelength */
/*
  mvl_type_ctrl[VSTR16_TYPEID].tdl = 
  "Vstring16";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR16_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[VSTR16_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR16_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR16_TYPEID].rt = u_mvl_get_rt_tbl (VSTR16_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR16_TYPEID].type_name, "VSTR16");

/* VSTR32 : VisbleString32-variablelength */
/*
  mvl_type_ctrl[VSTR32_TYPEID].tdl = 
  "Vstring32";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR32_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR32_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[VSTR32_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR32_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR32_TYPEID].rt = u_mvl_get_rt_tbl (VSTR32_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR32_TYPEID].type_name, "VSTR32");

/* VSTR64 : VisibleString64-variablelength */
/*
  mvl_type_ctrl[VSTR64_TYPEID].tdl = 
  "Vstring64";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR64_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR64_TYPEID].asn1 = "\x8a\x01\xc0";
#endif
  mvl_type_ctrl[VSTR64_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR64_TYPEID].data_size = 65;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR64_TYPEID].rt = u_mvl_get_rt_tbl (VSTR64_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR64_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR64_TYPEID].type_name, "VSTR64");

/* VSTR65 : VisibleString65-variablelength */
/*
  mvl_type_ctrl[VSTR65_TYPEID].tdl = 
  "Vstring65";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR65_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR65_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[VSTR65_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR65_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR65_TYPEID].rt = u_mvl_get_rt_tbl (VSTR65_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR65_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR65_TYPEID].type_name, "VSTR65");

/* VSTR128 : VisibleString128-variablelength */
/*
  mvl_type_ctrl[VSTR128_TYPEID].tdl = 
  "Vstring128";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VSTR128_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VSTR128_TYPEID].asn1 = "\x8a\x01\x80";
#endif
  mvl_type_ctrl[VSTR128_TYPEID].num_rt = 1;
  mvl_type_ctrl[VSTR128_TYPEID].data_size = 129;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VSTR128_TYPEID].rt = u_mvl_get_rt_tbl (VSTR128_TYPEID, 1);
#else
  mvl_type_ctrl[VSTR128_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VSTR128_TYPEID].type_name, "VSTR128");

/* BSTR1 : Twobitbistring */
/*
  mvl_type_ctrl[BSTR1_TYPEID].tdl = 
  "Bstring1";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR1_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR1_TYPEID].asn1 = "\x84\x01\x01";
#endif
  mvl_type_ctrl[BSTR1_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR1_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR1_TYPEID].rt = u_mvl_get_rt_tbl (BSTR1_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR1_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR1_TYPEID].type_name, "BSTR1");

/* BSTR2 : Twobitbistring */
/*
  mvl_type_ctrl[BSTR2_TYPEID].tdl = 
  "Bstring2";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR2_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR2_TYPEID].asn1 = "\x84\x01\x02";
#endif
  mvl_type_ctrl[BSTR2_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR2_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR2_TYPEID].rt = u_mvl_get_rt_tbl (BSTR2_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR2_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR2_TYPEID].type_name, "BSTR2");

/* BSTR8 : Bitstring-8 */
/*
  mvl_type_ctrl[BSTR8_TYPEID].tdl = 
  "Bstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR8_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[BSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR8_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR8_TYPEID].rt = u_mvl_get_rt_tbl (BSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR8_TYPEID].type_name, "BSTR8");

/* BSTR10 : Bitstring-10 */
/*
  mvl_type_ctrl[BSTR10_TYPEID].tdl = 
  "Bstring10";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR10_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR10_TYPEID].asn1 = "\x84\x01\x0a";
#endif
  mvl_type_ctrl[BSTR10_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR10_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR10_TYPEID].rt = u_mvl_get_rt_tbl (BSTR10_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR10_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR10_TYPEID].type_name, "BSTR10");

/* BSTR16 : Bitstring-16 */
/*
  mvl_type_ctrl[BSTR16_TYPEID].tdl = 
  "Bstring16";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR16_TYPEID].asn1 = "\x84\x01\x10";
#endif
  mvl_type_ctrl[BSTR16_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR16_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR16_TYPEID].rt = u_mvl_get_rt_tbl (BSTR16_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR16_TYPEID].type_name, "BSTR16");

/* BSTR32 : Bitstring-32 */
/*
  mvl_type_ctrl[BSTR32_TYPEID].tdl = 
  "Bstring32";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BSTR32_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BSTR32_TYPEID].asn1 = "\x84\x01\x20";
#endif
  mvl_type_ctrl[BSTR32_TYPEID].num_rt = 1;
  mvl_type_ctrl[BSTR32_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BSTR32_TYPEID].rt = u_mvl_get_rt_tbl (BSTR32_TYPEID, 1);
#else
  mvl_type_ctrl[BSTR32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BSTR32_TYPEID].type_name, "BSTR32");

/* VBSTR8 : VariablelengthBitstring-8 */
/*
  mvl_type_ctrl[VBSTR8_TYPEID].tdl = 
  "Bvstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VBSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VBSTR8_TYPEID].asn1 = "\x84\x01\xf8";
#endif
  mvl_type_ctrl[VBSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[VBSTR8_TYPEID].data_size = 3;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VBSTR8_TYPEID].rt = u_mvl_get_rt_tbl (VBSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[VBSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VBSTR8_TYPEID].type_name, "VBSTR8");

/* VBSTR16 : VariablelengthBitstring-16 */
/*
  mvl_type_ctrl[VBSTR16_TYPEID].tdl = 
  "Bvstring16";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VBSTR16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VBSTR16_TYPEID].asn1 = "\x84\x01\xf0";
#endif
  mvl_type_ctrl[VBSTR16_TYPEID].num_rt = 1;
  mvl_type_ctrl[VBSTR16_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VBSTR16_TYPEID].rt = u_mvl_get_rt_tbl (VBSTR16_TYPEID, 1);
#else
  mvl_type_ctrl[VBSTR16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VBSTR16_TYPEID].type_name, "VBSTR16");

/* VBSTR32 : VariablelengthBitstring-32 */
/*
  mvl_type_ctrl[VBSTR32_TYPEID].tdl = 
  "Bvstring32";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VBSTR32_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VBSTR32_TYPEID].asn1 = "\x84\x01\xe0";
#endif
  mvl_type_ctrl[VBSTR32_TYPEID].num_rt = 1;
  mvl_type_ctrl[VBSTR32_TYPEID].data_size = 6;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VBSTR32_TYPEID].rt = u_mvl_get_rt_tbl (VBSTR32_TYPEID, 1);
#else
  mvl_type_ctrl[VBSTR32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VBSTR32_TYPEID].type_name, "VBSTR32");

/* INT8S : SignedInteger-8 */
/*
  mvl_type_ctrl[INT8S_TYPEID].tdl = 
  "Byte";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT8S_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT8S_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[INT8S_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT8S_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT8S_TYPEID].rt = u_mvl_get_rt_tbl (INT8S_TYPEID, 1);
#else
  mvl_type_ctrl[INT8S_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT8S_TYPEID].type_name, "INT8S");

/* INT16S : SignedInteger-16 */
/*
  mvl_type_ctrl[INT16S_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT16S_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT16S_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[INT16S_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT16S_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT16S_TYPEID].rt = u_mvl_get_rt_tbl (INT16S_TYPEID, 1);
#else
  mvl_type_ctrl[INT16S_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT16S_TYPEID].type_name, "INT16S");

/* INT32S : SignedInteger-32 */
/*
  mvl_type_ctrl[INT32S_TYPEID].tdl = 
  "Long";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INT32S_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INT32S_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[INT32S_TYPEID].num_rt = 1;
  mvl_type_ctrl[INT32S_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INT32S_TYPEID].rt = u_mvl_get_rt_tbl (INT32S_TYPEID, 1);
#else
  mvl_type_ctrl[INT32S_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INT32S_TYPEID].type_name, "INT32S");

/* FLT32 : 32bitfloatingpoint */
/*
  mvl_type_ctrl[FLT32_TYPEID].tdl = 
  "Float";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLT32_TYPEID].asn1_len = 8;
  mvl_type_ctrl[FLT32_TYPEID].asn1 = "\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[FLT32_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLT32_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLT32_TYPEID].rt = u_mvl_get_rt_tbl (FLT32_TYPEID, 1);
#else
  mvl_type_ctrl[FLT32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLT32_TYPEID].type_name, "FLT32");

/* FLT64 : 64bitfloatingpoint */
/*
  mvl_type_ctrl[FLT64_TYPEID].tdl = 
  "Double";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLT64_TYPEID].asn1_len = 8;
  mvl_type_ctrl[FLT64_TYPEID].asn1 = "\xa7\x06\x02\x01\x40\x02\x01\x0b";
#endif
  mvl_type_ctrl[FLT64_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLT64_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLT64_TYPEID].rt = u_mvl_get_rt_tbl (FLT64_TYPEID, 1);
#else
  mvl_type_ctrl[FLT64_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLT64_TYPEID].type_name, "FLT64");

/* BTIME4 : Binarytimeofday */
/*
  mvl_type_ctrl[BTIME4_TYPEID].tdl = 
  "Btime4";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BTIME4_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BTIME4_TYPEID].asn1 = "\x8c\x01\x00";
#endif
  mvl_type_ctrl[BTIME4_TYPEID].num_rt = 1;
  mvl_type_ctrl[BTIME4_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BTIME4_TYPEID].rt = u_mvl_get_rt_tbl (BTIME4_TYPEID, 1);
#else
  mvl_type_ctrl[BTIME4_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BTIME4_TYPEID].type_name, "BTIME4");

/* BTIME6 : Binarytimeofdaytomsec */
/*
  mvl_type_ctrl[BTIME6_TYPEID].tdl = 
  "Btime6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BTIME6_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BTIME6_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[BTIME6_TYPEID].num_rt = 1;
  mvl_type_ctrl[BTIME6_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BTIME6_TYPEID].rt = u_mvl_get_rt_tbl (BTIME6_TYPEID, 1);
#else
  mvl_type_ctrl[BTIME6_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BTIME6_TYPEID].type_name, "BTIME6");

/* ENUM8 : signed enumeration8-bits */
/*
  mvl_type_ctrl[ENUM8_TYPEID].tdl = 
  "Byte";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENUM8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENUM8_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[ENUM8_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENUM8_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENUM8_TYPEID].rt = u_mvl_get_rt_tbl (ENUM8_TYPEID, 1);
#else
  mvl_type_ctrl[ENUM8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENUM8_TYPEID].type_name, "ENUM8");

/* ENUM16 : signed enumeration16-bits */
/*
  mvl_type_ctrl[ENUM16_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENUM16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENUM16_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[ENUM16_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENUM16_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENUM16_TYPEID].rt = u_mvl_get_rt_tbl (ENUM16_TYPEID, 1);
#else
  mvl_type_ctrl[ENUM16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENUM16_TYPEID].type_name, "ENUM16");

/* MAG : Magnitude */
/*
  mvl_type_ctrl[MAG_TYPEID].tdl = 
  "<INT32S>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MAG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MAG_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[MAG_TYPEID].num_rt = 1;
  mvl_type_ctrl[MAG_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MAG_TYPEID].rt = u_mvl_get_rt_tbl (MAG_TYPEID, 1);
#else
  mvl_type_ctrl[MAG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MAG_TYPEID].type_name, "MAG");

/* ANG : Angle */
/*
  mvl_type_ctrl[ANG_TYPEID].tdl = 
  "<INT32S>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ANG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ANG_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[ANG_TYPEID].num_rt = 1;
  mvl_type_ctrl[ANG_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ANG_TYPEID].rt = u_mvl_get_rt_tbl (ANG_TYPEID, 1);
#else
  mvl_type_ctrl[ANG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ANG_TYPEID].type_name, "ANG");

/* ACCRPTENA : AccumulatorReportEnable */
/*
  mvl_type_ctrl[ACCRPTENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ACCRPTENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[ACCRPTENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[ACCRPTENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[ACCRPTENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ACCRPTENA_TYPEID].rt = u_mvl_get_rt_tbl (ACCRPTENA_TYPEID, 1);
#else
  mvl_type_ctrl[ACCRPTENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ACCRPTENA_TYPEID].type_name, "ACCRPTENA");

/* ACCRS : AccumulatorReset */
/*
  mvl_type_ctrl[ACCRS_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ACCRS_TYPEID].asn1_len = 2;
  mvl_type_ctrl[ACCRS_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[ACCRS_TYPEID].num_rt = 1;
  mvl_type_ctrl[ACCRS_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ACCRS_TYPEID].rt = u_mvl_get_rt_tbl (ACCRS_TYPEID, 1);
#else
  mvl_type_ctrl[ACCRS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ACCRS_TYPEID].type_name, "ACCRS");

/* ACCSET : AccumulatorSetting */
/*
  mvl_type_ctrl[ACCSET_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ACCSET_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ACCSET_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[ACCSET_TYPEID].num_rt = 1;
  mvl_type_ctrl[ACCSET_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ACCSET_TYPEID].rt = u_mvl_get_rt_tbl (ACCSET_TYPEID, 1);
#else
  mvl_type_ctrl[ACCSET_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ACCSET_TYPEID].type_name, "ACCSET");

/* ACTTAGARR : Accumulatortagarray */
/*
  mvl_type_ctrl[ACTTAGARR_TYPEID].tdl = 
  "<BSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ACTTAGARR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ACTTAGARR_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[ACTTAGARR_TYPEID].num_rt = 1;
  mvl_type_ctrl[ACTTAGARR_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ACTTAGARR_TYPEID].rt = u_mvl_get_rt_tbl (ACTTAGARR_TYPEID, 1);
#else
  mvl_type_ctrl[ACTTAGARR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ACTTAGARR_TYPEID].type_name, "ACTTAGARR");

/* ANCESTRY : Ancestry */
/*
  mvl_type_ctrl[ANCESTRY_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ANCESTRY_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ANCESTRY_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[ANCESTRY_TYPEID].num_rt = 1;
  mvl_type_ctrl[ANCESTRY_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ANCESTRY_TYPEID].rt = u_mvl_get_rt_tbl (ANCESTRY_TYPEID, 1);
#else
  mvl_type_ctrl[ANCESTRY_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ANCESTRY_TYPEID].type_name, "ANCESTRY");

/* ANFMT : AnalogFormat */
/*
  mvl_type_ctrl[ANFMT_TYPEID].tdl = 
  "Vstring6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ANFMT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ANFMT_TYPEID].asn1 = "\x8a\x01\xfa";
#endif
  mvl_type_ctrl[ANFMT_TYPEID].num_rt = 1;
  mvl_type_ctrl[ANFMT_TYPEID].data_size = 7;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ANFMT_TYPEID].rt = u_mvl_get_rt_tbl (ANFMT_TYPEID, 1);
#else
  mvl_type_ctrl[ANFMT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ANFMT_TYPEID].type_name, "ANFMT");

/* BUFTIM : Buffertime */
/*
  mvl_type_ctrl[BUFTIM_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BUFTIM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BUFTIM_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[BUFTIM_TYPEID].num_rt = 1;
  mvl_type_ctrl[BUFTIM_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BUFTIM_TYPEID].rt = u_mvl_get_rt_tbl (BUFTIM_TYPEID, 1);
#else
  mvl_type_ctrl[BUFTIM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BUFTIM_TYPEID].type_name, "BUFTIM");

/* CID : CanonicalID */
/*
  mvl_type_ctrl[CID_TYPEID].tdl = 
  "<INT32S>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CID_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CID_TYPEID].asn1 = "\x85\x01\x20";
#endif
  mvl_type_ctrl[CID_TYPEID].num_rt = 1;
  mvl_type_ctrl[CID_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CID_TYPEID].rt = u_mvl_get_rt_tbl (CID_TYPEID, 1);
#else
  mvl_type_ctrl[CID_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CID_TYPEID].type_name, "CID");

/* CKTID : CircuitID */
/*
  mvl_type_ctrl[CKTID_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CKTID_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CKTID_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[CKTID_TYPEID].num_rt = 1;
  mvl_type_ctrl[CKTID_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CKTID_TYPEID].rt = u_mvl_get_rt_tbl (CKTID_TYPEID, 1);
#else
  mvl_type_ctrl[CKTID_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CKTID_TYPEID].type_name, "CKTID");

/* CKTPHS : CircuitPhases */
/*
  mvl_type_ctrl[CKTPHS_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CKTPHS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CKTPHS_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[CKTPHS_TYPEID].num_rt = 1;
  mvl_type_ctrl[CKTPHS_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CKTPHS_TYPEID].rt = u_mvl_get_rt_tbl (CKTPHS_TYPEID, 1);
#else
  mvl_type_ctrl[CKTPHS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CKTPHS_TYPEID].type_name, "CKTPHS");

/* CLASS : Classidentifier */
/*
  mvl_type_ctrl[CLASS_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CLASS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CLASS_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[CLASS_TYPEID].num_rt = 1;
  mvl_type_ctrl[CLASS_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CLASS_TYPEID].rt = u_mvl_get_rt_tbl (CLASS_TYPEID, 1);
#else
  mvl_type_ctrl[CLASS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CLASS_TYPEID].type_name, "CLASS");

/* COMMADR : Communicationaddress */
/*
  mvl_type_ctrl[COMMADR_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[COMMADR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[COMMADR_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[COMMADR_TYPEID].num_rt = 1;
  mvl_type_ctrl[COMMADR_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[COMMADR_TYPEID].rt = u_mvl_get_rt_tbl (COMMADR_TYPEID, 1);
#else
  mvl_type_ctrl[COMMADR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[COMMADR_TYPEID].type_name, "COMMADR");

/* COMMREV : Communicationrevision */
/*
  mvl_type_ctrl[COMMREV_TYPEID].tdl = 
  "<VSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[COMMREV_TYPEID].asn1_len = 3;
  mvl_type_ctrl[COMMREV_TYPEID].asn1 = "\x8a\x01\xf8";
#endif
  mvl_type_ctrl[COMMREV_TYPEID].num_rt = 1;
  mvl_type_ctrl[COMMREV_TYPEID].data_size = 9;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[COMMREV_TYPEID].rt = u_mvl_get_rt_tbl (COMMREV_TYPEID, 1);
#else
  mvl_type_ctrl[COMMREV_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[COMMREV_TYPEID].type_name, "COMMREV");

/* CONTCURRTG : Continuouscurrentrating */
/*
  mvl_type_ctrl[CONTCURRTG_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CONTCURRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[CONTCURRTG_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[CONTCURRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[CONTCURRTG_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CONTCURRTG_TYPEID].rt = u_mvl_get_rt_tbl (CONTCURRTG_TYPEID, 1);
#else
  mvl_type_ctrl[CONTCURRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CONTCURRTG_TYPEID].type_name, "CONTCURRTG");

/* COUNT : count */
/*
  mvl_type_ctrl[COUNT_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[COUNT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[COUNT_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[COUNT_TYPEID].num_rt = 1;
  mvl_type_ctrl[COUNT_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[COUNT_TYPEID].rt = u_mvl_get_rt_tbl (COUNT_TYPEID, 1);
#else
  mvl_type_ctrl[COUNT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[COUNT_TYPEID].type_name, "COUNT");

/* CRIRPT : criticalreport */
/*
  mvl_type_ctrl[CRIRPT_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[CRIRPT_TYPEID].asn1_len = 2;
  mvl_type_ctrl[CRIRPT_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[CRIRPT_TYPEID].num_rt = 1;
  mvl_type_ctrl[CRIRPT_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[CRIRPT_TYPEID].rt = u_mvl_get_rt_tbl (CRIRPT_TYPEID, 1);
#else
  mvl_type_ctrl[CRIRPT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[CRIRPT_TYPEID].type_name, "CRIRPT");

/* DATSETNAM : Datasetname */
/*
  mvl_type_ctrl[DATSETNAM_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DATSETNAM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DATSETNAM_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[DATSETNAM_TYPEID].num_rt = 1;
  mvl_type_ctrl[DATSETNAM_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DATSETNAM_TYPEID].rt = u_mvl_get_rt_tbl (DATSETNAM_TYPEID, 1);
#else
  mvl_type_ctrl[DATSETNAM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DATSETNAM_TYPEID].type_name, "DATSETNAM");

/* DESTAE : destinationAEname */
/*
  mvl_type_ctrl[DESTAE_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DESTAE_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DESTAE_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[DESTAE_TYPEID].num_rt = 1;
  mvl_type_ctrl[DESTAE_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DESTAE_TYPEID].rt = u_mvl_get_rt_tbl (DESTAE_TYPEID, 1);
#else
  mvl_type_ctrl[DESTAE_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DESTAE_TYPEID].type_name, "DESTAE");

/* DEVFCT : devicefunction */
/*
  mvl_type_ctrl[DEVFCT_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DEVFCT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DEVFCT_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[DEVFCT_TYPEID].num_rt = 1;
  mvl_type_ctrl[DEVFCT_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DEVFCT_TYPEID].rt = u_mvl_get_rt_tbl (DEVFCT_TYPEID, 1);
#else
  mvl_type_ctrl[DEVFCT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DEVFCT_TYPEID].type_name, "DEVFCT");

/* DEVMDLS : devicemodelname */
/*
  mvl_type_ctrl[DEVMDLS_TYPEID].tdl = 
  "<VSTR128>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DEVMDLS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DEVMDLS_TYPEID].asn1 = "\x8a\x01\x80";
#endif
  mvl_type_ctrl[DEVMDLS_TYPEID].num_rt = 1;
  mvl_type_ctrl[DEVMDLS_TYPEID].data_size = 129;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DEVMDLS_TYPEID].rt = u_mvl_get_rt_tbl (DEVMDLS_TYPEID, 1);
#else
  mvl_type_ctrl[DEVMDLS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DEVMDLS_TYPEID].type_name, "DEVMDLS");

/* DOW : Dayoftheweek */
/*
  mvl_type_ctrl[DOW_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DOW_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DOW_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[DOW_TYPEID].num_rt = 1;
  mvl_type_ctrl[DOW_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DOW_TYPEID].rt = u_mvl_get_rt_tbl (DOW_TYPEID, 1);
#else
  mvl_type_ctrl[DOW_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DOW_TYPEID].type_name, "DOW");

/* DOWSCHED : Dayoftheweekschedule */
/*
  mvl_type_ctrl[DOWSCHED_TYPEID].tdl = 
  "[6:<BTIME4>]";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DOWSCHED_TYPEID].asn1_len = 10;
  mvl_type_ctrl[DOWSCHED_TYPEID].asn1 = "\xa1\x08\x81\x01\x06\xa2\x03\x8c\x01\x00";
#endif
  mvl_type_ctrl[DOWSCHED_TYPEID].num_rt = 3;
  mvl_type_ctrl[DOWSCHED_TYPEID].data_size = 24;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DOWSCHED_TYPEID].rt = u_mvl_get_rt_tbl (DOWSCHED_TYPEID, 3);
#else
  mvl_type_ctrl[DOWSCHED_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DOWSCHED_TYPEID].type_name, "DOWSCHED");

/* ENABLE : enable */
/*
  mvl_type_ctrl[ENABLE_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENABLE_TYPEID].asn1_len = 2;
  mvl_type_ctrl[ENABLE_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[ENABLE_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENABLE_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENABLE_TYPEID].rt = u_mvl_get_rt_tbl (ENABLE_TYPEID, 1);
#else
  mvl_type_ctrl[ENABLE_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENABLE_TYPEID].type_name, "ENABLE");

/* ENCOPT : encodingoptions */
/*
  mvl_type_ctrl[ENCOPT_TYPEID].tdl = 
  "<BSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENCOPT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENCOPT_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[ENCOPT_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENCOPT_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENCOPT_TYPEID].rt = u_mvl_get_rt_tbl (ENCOPT_TYPEID, 1);
#else
  mvl_type_ctrl[ENCOPT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENCOPT_TYPEID].type_name, "ENCOPT");

/* ENROLL : enrollname */
/*
  mvl_type_ctrl[ENROLL_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ENROLL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ENROLL_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[ENROLL_TYPEID].num_rt = 1;
  mvl_type_ctrl[ENROLL_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ENROLL_TYPEID].rt = u_mvl_get_rt_tbl (ENROLL_TYPEID, 1);
#else
  mvl_type_ctrl[ENROLL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ENROLL_TYPEID].type_name, "ENROLL");

/* EORBDESC :  */
/*
  mvl_type_ctrl[EORBDESC_TYPEID].tdl = 
  "<VSTR64>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EORBDESC_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EORBDESC_TYPEID].asn1 = "\x8a\x01\xc0";
#endif
  mvl_type_ctrl[EORBDESC_TYPEID].num_rt = 1;
  mvl_type_ctrl[EORBDESC_TYPEID].data_size = 65;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EORBDESC_TYPEID].rt = u_mvl_get_rt_tbl (EORBDESC_TYPEID, 1);
#else
  mvl_type_ctrl[EORBDESC_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EORBDESC_TYPEID].type_name, "EORBDESC");

/* EVACON : evaluationconditionname */
/*
  mvl_type_ctrl[EVACON_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVACON_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EVACON_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[EVACON_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVACON_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVACON_TYPEID].rt = u_mvl_get_rt_tbl (EVACON_TYPEID, 1);
#else
  mvl_type_ctrl[EVACON_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVACON_TYPEID].type_name, "EVACON");

/* EVACNS : evaluationconditionname */
/*
  mvl_type_ctrl[EVACNS_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVACNS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EVACNS_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[EVACNS_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVACNS_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVACNS_TYPEID].rt = u_mvl_get_rt_tbl (EVACNS_TYPEID, 1);
#else
  mvl_type_ctrl[EVACNS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVACNS_TYPEID].type_name, "EVACNS");

/* EVACRI : evaluationcriterianame */
/*
  mvl_type_ctrl[EVACRI_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVACRI_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EVACRI_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[EVACRI_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVACRI_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVACRI_TYPEID].rt = u_mvl_get_rt_tbl (EVACRI_TYPEID, 1);
#else
  mvl_type_ctrl[EVACRI_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVACRI_TYPEID].type_name, "EVACRI");

/* EVAFCT : evaluationfunctionname */
/*
  mvl_type_ctrl[EVAFCT_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVAFCT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EVAFCT_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[EVAFCT_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVAFCT_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVAFCT_TYPEID].rt = u_mvl_get_rt_tbl (EVAFCT_TYPEID, 1);
#else
  mvl_type_ctrl[EVAFCT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVAFCT_TYPEID].type_name, "EVAFCT");

/* EVAPAR : evaluationparametersname */
/*
  mvl_type_ctrl[EVAPAR_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVAPAR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[EVAPAR_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[EVAPAR_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVAPAR_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVAPAR_TYPEID].rt = u_mvl_get_rt_tbl (EVAPAR_TYPEID, 1);
#else
  mvl_type_ctrl[EVAPAR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVAPAR_TYPEID].type_name, "EVAPAR");

/* EVTENA : eventenable */
/*
  mvl_type_ctrl[EVTENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[EVTENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[EVTENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[EVTENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[EVTENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[EVTENA_TYPEID].rt = u_mvl_get_rt_tbl (EVTENA_TYPEID, 1);
#else
  mvl_type_ctrl[EVTENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[EVTENA_TYPEID].type_name, "EVTENA");

/* FLTCURDUR : Faultcurrentduration */
/*
  mvl_type_ctrl[FLTCURDUR_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLTCURDUR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FLTCURDUR_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[FLTCURDUR_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLTCURDUR_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLTCURDUR_TYPEID].rt = u_mvl_get_rt_tbl (FLTCURDUR_TYPEID, 1);
#else
  mvl_type_ctrl[FLTCURDUR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLTCURDUR_TYPEID].type_name, "FLTCURDUR");

/* FLTCURRTG : Placeholder */
/*
  mvl_type_ctrl[FLTCURRTG_TYPEID].tdl = 
  "<INT16S>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FLTCURRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FLTCURRTG_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[FLTCURRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[FLTCURRTG_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FLTCURRTG_TYPEID].rt = u_mvl_get_rt_tbl (FLTCURRTG_TYPEID, 1);
#else
  mvl_type_ctrl[FLTCURRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FLTCURRTG_TYPEID].type_name, "FLTCURRTG");

/* FRZENA : freezeenable */
/*
  mvl_type_ctrl[FRZENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FRZENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[FRZENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[FRZENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[FRZENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FRZENA_TYPEID].rt = u_mvl_get_rt_tbl (FRZENA_TYPEID, 1);
#else
  mvl_type_ctrl[FRZENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FRZENA_TYPEID].type_name, "FRZENA");

/* FRZPD : freezeperiod */
/*
  mvl_type_ctrl[FRZPD_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FRZPD_TYPEID].asn1_len = 3;
  mvl_type_ctrl[FRZPD_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[FRZPD_TYPEID].num_rt = 1;
  mvl_type_ctrl[FRZPD_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FRZPD_TYPEID].rt = u_mvl_get_rt_tbl (FRZPD_TYPEID, 1);
#else
  mvl_type_ctrl[FRZPD_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FRZPD_TYPEID].type_name, "FRZPD");

/* FWDPWRHA : ForwardPowerharmonics */
/*
  mvl_type_ctrl[FWDPWRHA_TYPEID].tdl = 
  "[31:<FLT32>]";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[FWDPWRHA_TYPEID].asn1_len = 15;
  mvl_type_ctrl[FWDPWRHA_TYPEID].asn1 =
  "\xa1\x0d\x81\x01\x1f\xa2\x08\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[FWDPWRHA_TYPEID].num_rt = 3;
  mvl_type_ctrl[FWDPWRHA_TYPEID].data_size = 124;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[FWDPWRHA_TYPEID].rt = u_mvl_get_rt_tbl (FWDPWRHA_TYPEID, 3);
#else
  mvl_type_ctrl[FWDPWRHA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[FWDPWRHA_TYPEID].type_name, "FWDPWRHA");

/* HWREV : HardwareRevision */
/*
  mvl_type_ctrl[HWREV_TYPEID].tdl = 
  "<VSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[HWREV_TYPEID].asn1_len = 3;
  mvl_type_ctrl[HWREV_TYPEID].asn1 = "\x8a\x01\xf8";
#endif
  mvl_type_ctrl[HWREV_TYPEID].num_rt = 1;
  mvl_type_ctrl[HWREV_TYPEID].data_size = 9;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[HWREV_TYPEID].rt = u_mvl_get_rt_tbl (HWREV_TYPEID, 1);
#else
  mvl_type_ctrl[HWREV_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[HWREV_TYPEID].type_name, "HWREV");

/* HZRTG : Hertzrating */
/*
  mvl_type_ctrl[HZRTG_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[HZRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[HZRTG_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[HZRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[HZRTG_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[HZRTG_TYPEID].rt = u_mvl_get_rt_tbl (HZRTG_TYPEID, 1);
#else
  mvl_type_ctrl[HZRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[HZRTG_TYPEID].type_name, "HZRTG");

/* INDAT : InputDataName */
/*
  mvl_type_ctrl[INDAT_TYPEID].tdl = 
  "<IDENT>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INDAT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INDAT_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[INDAT_TYPEID].num_rt = 1;
  mvl_type_ctrl[INDAT_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INDAT_TYPEID].rt = u_mvl_get_rt_tbl (INDAT_TYPEID, 1);
#else
  mvl_type_ctrl[INDAT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INDAT_TYPEID].type_name, "INDAT");

/* INTGPD : IntegrityPeriod */
/*
  mvl_type_ctrl[INTGPD_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[INTGPD_TYPEID].asn1_len = 3;
  mvl_type_ctrl[INTGPD_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[INTGPD_TYPEID].num_rt = 1;
  mvl_type_ctrl[INTGPD_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[INTGPD_TYPEID].rt = u_mvl_get_rt_tbl (INTGPD_TYPEID, 1);
#else
  mvl_type_ctrl[INTGPD_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[INTGPD_TYPEID].type_name, "INTGPD");

/* LINLENM : Linelengthinmeters */
/*
  mvl_type_ctrl[LINLENM_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LINLENM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LINLENM_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[LINLENM_TYPEID].num_rt = 1;
  mvl_type_ctrl[LINLENM_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LINLENM_TYPEID].rt = u_mvl_get_rt_tbl (LINLENM_TYPEID, 1);
#else
  mvl_type_ctrl[LINLENM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LINLENM_TYPEID].type_name, "LINLENM");

/* LOC : Location */
/*
  mvl_type_ctrl[LOC_TYPEID].tdl = 
  "<VSTR128>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOC_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LOC_TYPEID].asn1 = "\x8a\x01\x80";
#endif
  mvl_type_ctrl[LOC_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOC_TYPEID].data_size = 129;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOC_TYPEID].rt = u_mvl_get_rt_tbl (LOC_TYPEID, 1);
#else
  mvl_type_ctrl[LOC_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOC_TYPEID].type_name, "LOC");

/* LOGENA : Logenable */
/*
  mvl_type_ctrl[LOGENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOGENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[LOGENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[LOGENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOGENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOGENA_TYPEID].rt = u_mvl_get_rt_tbl (LOGENA_TYPEID, 1);
#else
  mvl_type_ctrl[LOGENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOGENA_TYPEID].type_name, "LOGENA");

/* LOGENR : Logenroll */
/*
  mvl_type_ctrl[LOGENR_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOGENR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LOGENR_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[LOGENR_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOGENR_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOGENR_TYPEID].rt = u_mvl_get_rt_tbl (LOGENR_TYPEID, 1);
#else
  mvl_type_ctrl[LOGENR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOGENR_TYPEID].type_name, "LOGENR");

/* LOGNAM : Logname */
/*
  mvl_type_ctrl[LOGNAM_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOGNAM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LOGNAM_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[LOGNAM_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOGNAM_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOGNAM_TYPEID].rt = u_mvl_get_rt_tbl (LOGNAM_TYPEID, 1);
#else
  mvl_type_ctrl[LOGNAM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOGNAM_TYPEID].type_name, "LOGNAM");

/* LOGSIZE : Logsize */
/*
  mvl_type_ctrl[LOGSIZE_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOGSIZE_TYPEID].asn1_len = 3;
  mvl_type_ctrl[LOGSIZE_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[LOGSIZE_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOGSIZE_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOGSIZE_TYPEID].rt = u_mvl_get_rt_tbl (LOGSIZE_TYPEID, 1);
#else
  mvl_type_ctrl[LOGSIZE_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOGSIZE_TYPEID].type_name, "LOGSIZE");

/* LOGWRP : LogWrapped */
/*
  mvl_type_ctrl[LOGWRP_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[LOGWRP_TYPEID].asn1_len = 2;
  mvl_type_ctrl[LOGWRP_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[LOGWRP_TYPEID].num_rt = 1;
  mvl_type_ctrl[LOGWRP_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[LOGWRP_TYPEID].rt = u_mvl_get_rt_tbl (LOGWRP_TYPEID, 1);
#else
  mvl_type_ctrl[LOGWRP_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[LOGWRP_TYPEID].type_name, "LOGWRP");

/* MAC : MediumAccessControl */
/*
  mvl_type_ctrl[MAC_TYPEID].tdl = 
  "<INT8U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MAC_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MAC_TYPEID].asn1 = "\x86\x01\x08";
#endif
  mvl_type_ctrl[MAC_TYPEID].num_rt = 1;
  mvl_type_ctrl[MAC_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MAC_TYPEID].rt = u_mvl_get_rt_tbl (MAC_TYPEID, 1);
#else
  mvl_type_ctrl[MAC_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MAC_TYPEID].type_name, "MAC");

/* MDL : Modelname */
/*
  mvl_type_ctrl[MDL_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MDL_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MDL_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[MDL_TYPEID].num_rt = 1;
  mvl_type_ctrl[MDL_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MDL_TYPEID].rt = u_mvl_get_rt_tbl (MDL_TYPEID, 1);
#else
  mvl_type_ctrl[MDL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MDL_TYPEID].type_name, "MDL");

/* MED : mediatype */
/*
  mvl_type_ctrl[MED_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MED_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MED_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[MED_TYPEID].num_rt = 1;
  mvl_type_ctrl[MED_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MED_TYPEID].rt = u_mvl_get_rt_tbl (MED_TYPEID, 1);
#else
  mvl_type_ctrl[MED_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MED_TYPEID].type_name, "MED");

/* MXREF : Measurementreference */
/*
  mvl_type_ctrl[MXREF_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MXREF_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MXREF_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[MXREF_TYPEID].num_rt = 1;
  mvl_type_ctrl[MXREF_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MXREF_TYPEID].rt = u_mvl_get_rt_tbl (MXREF_TYPEID, 1);
#else
  mvl_type_ctrl[MXREF_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MXREF_TYPEID].type_name, "MXREF");

/* MXTYP : MeasurementType */
/*
  mvl_type_ctrl[MXTYP_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[MXTYP_TYPEID].asn1_len = 3;
  mvl_type_ctrl[MXTYP_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[MXTYP_TYPEID].num_rt = 1;
  mvl_type_ctrl[MXTYP_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[MXTYP_TYPEID].rt = u_mvl_get_rt_tbl (MXTYP_TYPEID, 1);
#else
  mvl_type_ctrl[MXTYP_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[MXTYP_TYPEID].type_name, "MXTYP");

/* NAME : ownername */
/*
  mvl_type_ctrl[NAME_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NAME_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NAME_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[NAME_TYPEID].num_rt = 1;
  mvl_type_ctrl[NAME_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NAME_TYPEID].rt = u_mvl_get_rt_tbl (NAME_TYPEID, 1);
#else
  mvl_type_ctrl[NAME_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NAME_TYPEID].type_name, "NAME");

/* NEWTIM : newesttime */
/*
  mvl_type_ctrl[NEWTIM_TYPEID].tdl = 
  "<BTIME6>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NEWTIM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NEWTIM_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[NEWTIM_TYPEID].num_rt = 1;
  mvl_type_ctrl[NEWTIM_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NEWTIM_TYPEID].rt = u_mvl_get_rt_tbl (NEWTIM_TYPEID, 1);
#else
  mvl_type_ctrl[NEWTIM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NEWTIM_TYPEID].type_name, "NEWTIM");

/* NUMBITS : numberofbits */
/*
  mvl_type_ctrl[NUMBITS_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NUMBITS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NUMBITS_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[NUMBITS_TYPEID].num_rt = 1;
  mvl_type_ctrl[NUMBITS_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NUMBITS_TYPEID].rt = u_mvl_get_rt_tbl (NUMBITS_TYPEID, 1);
#else
  mvl_type_ctrl[NUMBITS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NUMBITS_TYPEID].type_name, "NUMBITS");

/* NUMPLS : numberofpulses */
/*
  mvl_type_ctrl[NUMPLS_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NUMPLS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NUMPLS_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[NUMPLS_TYPEID].num_rt = 1;
  mvl_type_ctrl[NUMPLS_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NUMPLS_TYPEID].rt = u_mvl_get_rt_tbl (NUMPLS_TYPEID, 1);
#else
  mvl_type_ctrl[NUMPLS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NUMPLS_TYPEID].type_name, "NUMPLS");

/* NUMSMP : numberofsamples */
/*
  mvl_type_ctrl[NUMSMP_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NUMSMP_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NUMSMP_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[NUMSMP_TYPEID].num_rt = 1;
  mvl_type_ctrl[NUMSMP_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NUMSMP_TYPEID].rt = u_mvl_get_rt_tbl (NUMSMP_TYPEID, 1);
#else
  mvl_type_ctrl[NUMSMP_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NUMSMP_TYPEID].type_name, "NUMSMP");

/* NUMUNIT : numberofunits */
/*
  mvl_type_ctrl[NUMUNIT_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[NUMUNIT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[NUMUNIT_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[NUMUNIT_TYPEID].num_rt = 1;
  mvl_type_ctrl[NUMUNIT_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[NUMUNIT_TYPEID].rt = u_mvl_get_rt_tbl (NUMUNIT_TYPEID, 1);
#else
  mvl_type_ctrl[NUMUNIT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[NUMUNIT_TYPEID].type_name, "NUMUNIT");

/* OFFDUR : Offduration */
/*
  mvl_type_ctrl[OFFDUR_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OFFDUR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OFFDUR_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[OFFDUR_TYPEID].num_rt = 1;
  mvl_type_ctrl[OFFDUR_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OFFDUR_TYPEID].rt = u_mvl_get_rt_tbl (OFFDUR_TYPEID, 1);
#else
  mvl_type_ctrl[OFFDUR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OFFDUR_TYPEID].type_name, "OFFDUR");

/* OLDTIM : Oldesttime */
/*
  mvl_type_ctrl[OLDTIM_TYPEID].tdl = 
  "<BTIME6>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OLDTIM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OLDTIM_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[OLDTIM_TYPEID].num_rt = 1;
  mvl_type_ctrl[OLDTIM_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OLDTIM_TYPEID].rt = u_mvl_get_rt_tbl (OLDTIM_TYPEID, 1);
#else
  mvl_type_ctrl[OLDTIM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OLDTIM_TYPEID].type_name, "OLDTIM");

/* ONDUR : Onduration */
/*
  mvl_type_ctrl[ONDUR_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[ONDUR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[ONDUR_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[ONDUR_TYPEID].num_rt = 1;
  mvl_type_ctrl[ONDUR_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[ONDUR_TYPEID].rt = u_mvl_get_rt_tbl (ONDUR_TYPEID, 1);
#else
  mvl_type_ctrl[ONDUR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[ONDUR_TYPEID].type_name, "ONDUR");

/* OPERDEV : Operatedevice */
/*
  mvl_type_ctrl[OPERDEV_TYPEID].tdl = 
  "<B2>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OPERDEV_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OPERDEV_TYPEID].asn1 = "\x84\x01\x02";
#endif
  mvl_type_ctrl[OPERDEV_TYPEID].num_rt = 1;
  mvl_type_ctrl[OPERDEV_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OPERDEV_TYPEID].rt = u_mvl_get_rt_tbl (OPERDEV_TYPEID, 1);
#else
  mvl_type_ctrl[OPERDEV_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OPERDEV_TYPEID].type_name, "OPERDEV");

/* OPTFLDS : Optionalfields */
/*
  mvl_type_ctrl[OPTFLDS_TYPEID].tdl = 
  "<BSTR10>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OPTFLDS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OPTFLDS_TYPEID].asn1 = "\x84\x01\x0a";
#endif
  mvl_type_ctrl[OPTFLDS_TYPEID].num_rt = 1;
  mvl_type_ctrl[OPTFLDS_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OPTFLDS_TYPEID].rt = u_mvl_get_rt_tbl (OPTFLDS_TYPEID, 1);
#else
  mvl_type_ctrl[OPTFLDS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OPTFLDS_TYPEID].type_name, "OPTFLDS");

/* OUTDAT : outputdatasetname */
/*
  mvl_type_ctrl[OUTDAT_TYPEID].tdl = 
  "<IDENT>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OUTDAT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OUTDAT_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[OUTDAT_TYPEID].num_rt = 1;
  mvl_type_ctrl[OUTDAT_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OUTDAT_TYPEID].rt = u_mvl_get_rt_tbl (OUTDAT_TYPEID, 1);
#else
  mvl_type_ctrl[OUTDAT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OUTDAT_TYPEID].type_name, "OUTDAT");

/* OVRST : Overflowstatus */
/*
  mvl_type_ctrl[OVRST_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OVRST_TYPEID].asn1_len = 2;
  mvl_type_ctrl[OVRST_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[OVRST_TYPEID].num_rt = 1;
  mvl_type_ctrl[OVRST_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OVRST_TYPEID].rt = u_mvl_get_rt_tbl (OVRST_TYPEID, 1);
#else
  mvl_type_ctrl[OVRST_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OVRST_TYPEID].type_name, "OVRST");

/* OWN : Owner */
/*
  mvl_type_ctrl[OWN_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[OWN_TYPEID].asn1_len = 3;
  mvl_type_ctrl[OWN_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[OWN_TYPEID].num_rt = 1;
  mvl_type_ctrl[OWN_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[OWN_TYPEID].rt = u_mvl_get_rt_tbl (OWN_TYPEID, 1);
#else
  mvl_type_ctrl[OWN_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[OWN_TYPEID].type_name, "OWN");

/* PRO : enumeratedprotocolid */
/*
  mvl_type_ctrl[PRO_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[PRO_TYPEID].asn1_len = 3;
  mvl_type_ctrl[PRO_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[PRO_TYPEID].num_rt = 1;
  mvl_type_ctrl[PRO_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[PRO_TYPEID].rt = u_mvl_get_rt_tbl (PRO_TYPEID, 1);
#else
  mvl_type_ctrl[PRO_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[PRO_TYPEID].type_name, "PRO");

/* PWRHA : powerharmonics */
/*
  mvl_type_ctrl[PWRHA_TYPEID].tdl = 
  "[31:<FLT32>]";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[PWRHA_TYPEID].asn1_len = 15;
  mvl_type_ctrl[PWRHA_TYPEID].asn1 =
  "\xa1\x0d\x81\x01\x1f\xa2\x08\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[PWRHA_TYPEID].num_rt = 3;
  mvl_type_ctrl[PWRHA_TYPEID].data_size = 124;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[PWRHA_TYPEID].rt = u_mvl_get_rt_tbl (PWRHA_TYPEID, 3);
#else
  mvl_type_ctrl[PWRHA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[PWRHA_TYPEID].type_name, "PWRHA");

/* QURPTENA : qualityreportenable */
/*
  mvl_type_ctrl[QURPTENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[QURPTENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[QURPTENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[QURPTENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[QURPTENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[QURPTENA_TYPEID].rt = u_mvl_get_rt_tbl (QURPTENA_TYPEID, 1);
#else
  mvl_type_ctrl[QURPTENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[QURPTENA_TYPEID].type_name, "QURPTENA");

/* RBEPD : reportperiod */
/*
  mvl_type_ctrl[RBEPD_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RBEPD_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RBEPD_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[RBEPD_TYPEID].num_rt = 1;
  mvl_type_ctrl[RBEPD_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RBEPD_TYPEID].rt = u_mvl_get_rt_tbl (RBEPD_TYPEID, 1);
#else
  mvl_type_ctrl[RBEPD_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RBEPD_TYPEID].type_name, "RBEPD");

/* RPTENA : Reportenable */
/*
  mvl_type_ctrl[RPTENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RPTENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[RPTENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[RPTENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[RPTENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RPTENA_TYPEID].rt = u_mvl_get_rt_tbl (RPTENA_TYPEID, 1);
#else
  mvl_type_ctrl[RPTENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RPTENA_TYPEID].type_name, "RPTENA");

/* RPTID : ReportID */
/*
  mvl_type_ctrl[RPTID_TYPEID].tdl = 
  "<VSTR65>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RPTID_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RPTID_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[RPTID_TYPEID].num_rt = 1;
  mvl_type_ctrl[RPTID_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RPTID_TYPEID].rt = u_mvl_get_rt_tbl (RPTID_TYPEID, 1);
#else
  mvl_type_ctrl[RPTID_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RPTID_TYPEID].type_name, "RPTID");

/* RVSPWRHA : reversepowerharmonics */
/*
  mvl_type_ctrl[RVSPWRHA_TYPEID].tdl = 
  "[31:<FLT32>]";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RVSPWRHA_TYPEID].asn1_len = 15;
  mvl_type_ctrl[RVSPWRHA_TYPEID].asn1 =
  "\xa1\x0d\x81\x01\x1f\xa2\x08\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[RVSPWRHA_TYPEID].num_rt = 3;
  mvl_type_ctrl[RVSPWRHA_TYPEID].data_size = 124;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RVSPWRHA_TYPEID].rt = u_mvl_get_rt_tbl (RVSPWRHA_TYPEID, 3);
#else
  mvl_type_ctrl[RVSPWRHA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RVSPWRHA_TYPEID].type_name, "RVSPWRHA");

/* SBOENA : SBOenable */
/*
  mvl_type_ctrl[SBOENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SBOENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[SBOENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[SBOENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[SBOENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SBOENA_TYPEID].rt = u_mvl_get_rt_tbl (SBOENA_TYPEID, 1);
#else
  mvl_type_ctrl[SBOENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SBOENA_TYPEID].type_name, "SBOENA");

/* SETTIMOUT : SBOSelectTimeout */
/*
  mvl_type_ctrl[SETTIMOUT_TYPEID].tdl = 
  "<INT8U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SETTIMOUT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SETTIMOUT_TYPEID].asn1 = "\x86\x01\x08";
#endif
  mvl_type_ctrl[SETTIMOUT_TYPEID].num_rt = 1;
  mvl_type_ctrl[SETTIMOUT_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SETTIMOUT_TYPEID].rt = u_mvl_get_rt_tbl (SETTIMOUT_TYPEID, 1);
#else
  mvl_type_ctrl[SETTIMOUT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SETTIMOUT_TYPEID].type_name, "SETTIMOUT");

/* SEQNUM : Sequencenumber */
/*
  mvl_type_ctrl[SEQNUM_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SEQNUM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SEQNUM_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[SEQNUM_TYPEID].num_rt = 1;
  mvl_type_ctrl[SEQNUM_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SEQNUM_TYPEID].rt = u_mvl_get_rt_tbl (SEQNUM_TYPEID, 1);
#else
  mvl_type_ctrl[SEQNUM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SEQNUM_TYPEID].type_name, "SEQNUM");

/* SERNUM : Serialnumber */
/*
  mvl_type_ctrl[SERNUM_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SERNUM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SERNUM_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[SERNUM_TYPEID].num_rt = 1;
  mvl_type_ctrl[SERNUM_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SERNUM_TYPEID].rt = u_mvl_get_rt_tbl (SERNUM_TYPEID, 1);
#else
  mvl_type_ctrl[SERNUM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SERNUM_TYPEID].type_name, "SERNUM");

/* SFTREV : SoftwareRevisionNumber */
/*
  mvl_type_ctrl[SFTREV_TYPEID].tdl = 
  "<VSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SFTREV_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SFTREV_TYPEID].asn1 = "\x8a\x01\xf8";
#endif
  mvl_type_ctrl[SFTREV_TYPEID].num_rt = 1;
  mvl_type_ctrl[SFTREV_TYPEID].data_size = 9;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SFTREV_TYPEID].rt = u_mvl_get_rt_tbl (SFTREV_TYPEID, 1);
#else
  mvl_type_ctrl[SFTREV_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SFTREV_TYPEID].type_name, "SFTREV");

/* SMPRATE : samplerate */
/*
  mvl_type_ctrl[SMPRATE_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SMPRATE_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SMPRATE_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[SMPRATE_TYPEID].num_rt = 1;
  mvl_type_ctrl[SMPRATE_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SMPRATE_TYPEID].rt = u_mvl_get_rt_tbl (SMPRATE_TYPEID, 1);
#else
  mvl_type_ctrl[SMPRATE_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SMPRATE_TYPEID].type_name, "SMPRATE");

/* TAGD : tagdescription */
/*
  mvl_type_ctrl[TAGD_TYPEID].tdl = 
  "<VSTR128>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TAGD_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TAGD_TYPEID].asn1 = "\x8a\x01\x80";
#endif
  mvl_type_ctrl[TAGD_TYPEID].num_rt = 1;
  mvl_type_ctrl[TAGD_TYPEID].data_size = 129;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TAGD_TYPEID].rt = u_mvl_get_rt_tbl (TAGD_TYPEID, 1);
#else
  mvl_type_ctrl[TAGD_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TAGD_TYPEID].type_name, "TAGD");

/* TAGID : tagID */
/*
  mvl_type_ctrl[TAGID_TYPEID].tdl = 
  "<INT8U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TAGID_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TAGID_TYPEID].asn1 = "\x86\x01\x08";
#endif
  mvl_type_ctrl[TAGID_TYPEID].num_rt = 1;
  mvl_type_ctrl[TAGID_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TAGID_TYPEID].rt = u_mvl_get_rt_tbl (TAGID_TYPEID, 1);
#else
  mvl_type_ctrl[TAGID_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TAGID_TYPEID].type_name, "TAGID");

/* TAGOWN : tagowner */
/*
  mvl_type_ctrl[TAGOWN_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TAGOWN_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TAGOWN_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[TAGOWN_TYPEID].num_rt = 1;
  mvl_type_ctrl[TAGOWN_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TAGOWN_TYPEID].rt = u_mvl_get_rt_tbl (TAGOWN_TYPEID, 1);
#else
  mvl_type_ctrl[TAGOWN_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TAGOWN_TYPEID].type_name, "TAGOWN");

/* TAGTYP : tagtypepermitted */
/*
  mvl_type_ctrl[TAGTYP_TYPEID].tdl = 
  "<BSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TAGTYP_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TAGTYP_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[TAGTYP_TYPEID].num_rt = 1;
  mvl_type_ctrl[TAGTYP_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TAGTYP_TYPEID].rt = u_mvl_get_rt_tbl (TAGTYP_TYPEID, 1);
#else
  mvl_type_ctrl[TAGTYP_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TAGTYP_TYPEID].type_name, "TAGTYP");

/* TEMPRAT : temperaturerating */
/*
  mvl_type_ctrl[TEMPRAT_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TEMPRAT_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TEMPRAT_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[TEMPRAT_TYPEID].num_rt = 1;
  mvl_type_ctrl[TEMPRAT_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TEMPRAT_TYPEID].rt = u_mvl_get_rt_tbl (TEMPRAT_TYPEID, 1);
#else
  mvl_type_ctrl[TEMPRAT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TEMPRAT_TYPEID].type_name, "TEMPRAT");

/* TEMPRTG : temperaturerating */
/*
  mvl_type_ctrl[TEMPRTG_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TEMPRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TEMPRTG_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[TEMPRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[TEMPRTG_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TEMPRTG_TYPEID].rt = u_mvl_get_rt_tbl (TEMPRTG_TYPEID, 1);
#else
  mvl_type_ctrl[TEMPRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TEMPRTG_TYPEID].type_name, "TEMPRTG");

/* TIMOFFRZ : timeoffreeze */
/*
  mvl_type_ctrl[TIMOFFRZ_TYPEID].tdl = 
  "<BTIME6>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TIMOFFRZ_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TIMOFFRZ_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[TIMOFFRZ_TYPEID].num_rt = 1;
  mvl_type_ctrl[TIMOFFRZ_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TIMOFFRZ_TYPEID].rt = u_mvl_get_rt_tbl (TIMOFFRZ_TYPEID, 1);
#else
  mvl_type_ctrl[TIMOFFRZ_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TIMOFFRZ_TYPEID].type_name, "TIMOFFRZ");

/* TIMRPTENA : Timestampreportenable */
/*
  mvl_type_ctrl[TIMRPTENA_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TIMRPTENA_TYPEID].asn1_len = 2;
  mvl_type_ctrl[TIMRPTENA_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[TIMRPTENA_TYPEID].num_rt = 1;
  mvl_type_ctrl[TIMRPTENA_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TIMRPTENA_TYPEID].rt = u_mvl_get_rt_tbl (TIMRPTENA_TYPEID, 1);
#else
  mvl_type_ctrl[TIMRPTENA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TIMRPTENA_TYPEID].type_name, "TIMRPTENA");

/* TRGOPS : Triggeroptions */
/*
  mvl_type_ctrl[TRGOPS_TYPEID].tdl = 
  "<BSTR8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TRGOPS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TRGOPS_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[TRGOPS_TYPEID].num_rt = 1;
  mvl_type_ctrl[TRGOPS_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TRGOPS_TYPEID].rt = u_mvl_get_rt_tbl (TRGOPS_TYPEID, 1);
#else
  mvl_type_ctrl[TRGOPS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TRGOPS_TYPEID].type_name, "TRGOPS");

/* TRGS : numberoftriggers */
/*
  mvl_type_ctrl[TRGS_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[TRGS_TYPEID].asn1_len = 3;
  mvl_type_ctrl[TRGS_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[TRGS_TYPEID].num_rt = 1;
  mvl_type_ctrl[TRGS_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[TRGS_TYPEID].rt = u_mvl_get_rt_tbl (TRGS_TYPEID, 1);
#else
  mvl_type_ctrl[TRGS_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[TRGS_TYPEID].type_name, "TRGS");

/* UNITVARRTG : Unitvarrating */
/*
  mvl_type_ctrl[UNITVARRTG_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[UNITVARRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[UNITVARRTG_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[UNITVARRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[UNITVARRTG_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[UNITVARRTG_TYPEID].rt = u_mvl_get_rt_tbl (UNITVARRTG_TYPEID, 1);
#else
  mvl_type_ctrl[UNITVARRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[UNITVARRTG_TYPEID].type_name, "UNITVARRTG");

/* UNKPWRHA : Unkownharmonicdirection */
/*
  mvl_type_ctrl[UNKPWRHA_TYPEID].tdl = 
  "[31:<FLT32>]";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[UNKPWRHA_TYPEID].asn1_len = 15;
  mvl_type_ctrl[UNKPWRHA_TYPEID].asn1 =
  "\xa1\x0d\x81\x01\x1f\xa2\x08\xa7\x06\x02\x01\x20\x02\x01\x08";
#endif
  mvl_type_ctrl[UNKPWRHA_TYPEID].num_rt = 3;
  mvl_type_ctrl[UNKPWRHA_TYPEID].data_size = 124;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[UNKPWRHA_TYPEID].rt = u_mvl_get_rt_tbl (UNKPWRHA_TYPEID, 3);
#else
  mvl_type_ctrl[UNKPWRHA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[UNKPWRHA_TYPEID].type_name, "UNKPWRHA");

/* USEST : utilizationstatus */
/*
  mvl_type_ctrl[USEST_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[USEST_TYPEID].asn1_len = 2;
  mvl_type_ctrl[USEST_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[USEST_TYPEID].num_rt = 1;
  mvl_type_ctrl[USEST_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[USEST_TYPEID].rt = u_mvl_get_rt_tbl (USEST_TYPEID, 1);
#else
  mvl_type_ctrl[USEST_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[USEST_TYPEID].type_name, "USEST");

/* VARRTG : Varsrating */
/*
  mvl_type_ctrl[VARRTG_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VARRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VARRTG_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[VARRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[VARRTG_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VARRTG_TYPEID].rt = u_mvl_get_rt_tbl (VARRTG_TYPEID, 1);
#else
  mvl_type_ctrl[VARRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VARRTG_TYPEID].type_name, "VARRTG");

/* VARTG : VARsrating */
/*
  mvl_type_ctrl[VARTG_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VARTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VARTG_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[VARTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[VARTG_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VARTG_TYPEID].rt = u_mvl_get_rt_tbl (VARTG_TYPEID, 1);
#else
  mvl_type_ctrl[VARTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VARTG_TYPEID].type_name, "VARTG");

/* VND : VendorID */
/*
  mvl_type_ctrl[VND_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VND_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VND_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[VND_TYPEID].num_rt = 1;
  mvl_type_ctrl[VND_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VND_TYPEID].rt = u_mvl_get_rt_tbl (VND_TYPEID, 1);
#else
  mvl_type_ctrl[VND_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VND_TYPEID].type_name, "VND");

/* VRTG : voltagerating */
/*
  mvl_type_ctrl[VRTG_TYPEID].tdl = 
  "<VSTR16>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[VRTG_TYPEID].asn1_len = 3;
  mvl_type_ctrl[VRTG_TYPEID].asn1 = "\x8a\x01\xf0";
#endif
  mvl_type_ctrl[VRTG_TYPEID].num_rt = 1;
  mvl_type_ctrl[VRTG_TYPEID].data_size = 17;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[VRTG_TYPEID].rt = u_mvl_get_rt_tbl (VRTG_TYPEID, 1);
#else
  mvl_type_ctrl[VRTG_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[VRTG_TYPEID].type_name, "VRTG");

/* WRNLEV : logwarninglevel */
/*
  mvl_type_ctrl[WRNLEV_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[WRNLEV_TYPEID].asn1_len = 3;
  mvl_type_ctrl[WRNLEV_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[WRNLEV_TYPEID].num_rt = 1;
  mvl_type_ctrl[WRNLEV_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[WRNLEV_TYPEID].rt = u_mvl_get_rt_tbl (WRNLEV_TYPEID, 1);
#else
  mvl_type_ctrl[WRNLEV_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[WRNLEV_TYPEID].type_name, "WRNLEV");

/* WRNST : warningstatus */
/*
  mvl_type_ctrl[WRNST_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[WRNST_TYPEID].asn1_len = 2;
  mvl_type_ctrl[WRNST_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[WRNST_TYPEID].num_rt = 1;
  mvl_type_ctrl[WRNST_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[WRNST_TYPEID].rt = u_mvl_get_rt_tbl (WRNST_TYPEID, 1);
#else
  mvl_type_ctrl[WRNST_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[WRNST_TYPEID].type_name, "WRNST");

/* PHSTAR : PhaseTarget */
/*
  mvl_type_ctrl[PHSTAR_TYPEID].tdl = 
  "<ENUM8>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[PHSTAR_TYPEID].asn1_len = 3;
  mvl_type_ctrl[PHSTAR_TYPEID].asn1 = "\x85\x01\x08";
#endif
  mvl_type_ctrl[PHSTAR_TYPEID].num_rt = 1;
  mvl_type_ctrl[PHSTAR_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[PHSTAR_TYPEID].rt = u_mvl_get_rt_tbl (PHSTAR_TYPEID, 1);
#else
  mvl_type_ctrl[PHSTAR_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[PHSTAR_TYPEID].type_name, "PHSTAR");

/* SBO :  */
/*
  mvl_type_ctrl[SBO_TYPEID].tdl = 
  "<VSTR65>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SBO_TYPEID].asn1_len = 3;
  mvl_type_ctrl[SBO_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[SBO_TYPEID].num_rt = 1;
  mvl_type_ctrl[SBO_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SBO_TYPEID].rt = u_mvl_get_rt_tbl (SBO_TYPEID, 1);
#else
  mvl_type_ctrl[SBO_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SBO_TYPEID].type_name, "SBO");

/* STNUM :  */
/*
  mvl_type_ctrl[STNUM_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[STNUM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[STNUM_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[STNUM_TYPEID].num_rt = 1;
  mvl_type_ctrl[STNUM_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[STNUM_TYPEID].rt = u_mvl_get_rt_tbl (STNUM_TYPEID, 1);
#else
  mvl_type_ctrl[STNUM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[STNUM_TYPEID].type_name, "STNUM");

/* HOLDTIM :  */
/*
  mvl_type_ctrl[HOLDTIM_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[HOLDTIM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[HOLDTIM_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[HOLDTIM_TYPEID].num_rt = 1;
  mvl_type_ctrl[HOLDTIM_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[HOLDTIM_TYPEID].rt = u_mvl_get_rt_tbl (HOLDTIM_TYPEID, 1);
#else
  mvl_type_ctrl[HOLDTIM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[HOLDTIM_TYPEID].type_name, "HOLDTIM");

/* BACKTIM :  */
/*
  mvl_type_ctrl[BACKTIM_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[BACKTIM_TYPEID].asn1_len = 3;
  mvl_type_ctrl[BACKTIM_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[BACKTIM_TYPEID].num_rt = 1;
  mvl_type_ctrl[BACKTIM_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[BACKTIM_TYPEID].rt = u_mvl_get_rt_tbl (BACKTIM_TYPEID, 1);
#else
  mvl_type_ctrl[BACKTIM_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[BACKTIM_TYPEID].type_name, "BACKTIM");

/* PHSID :  */
/*
  mvl_type_ctrl[PHSID_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[PHSID_TYPEID].asn1_len = 3;
  mvl_type_ctrl[PHSID_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[PHSID_TYPEID].num_rt = 1;
  mvl_type_ctrl[PHSID_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[PHSID_TYPEID].rt = u_mvl_get_rt_tbl (PHSID_TYPEID, 1);
#else
  mvl_type_ctrl[PHSID_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[PHSID_TYPEID].type_name, "PHSID");

/* DNA :  */
/*
  mvl_type_ctrl[DNA_TYPEID].tdl = 
  "Bstring64";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[DNA_TYPEID].asn1_len = 3;
  mvl_type_ctrl[DNA_TYPEID].asn1 = "\x84\x01\x40";
#endif
  mvl_type_ctrl[DNA_TYPEID].num_rt = 1;
  mvl_type_ctrl[DNA_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[DNA_TYPEID].rt = u_mvl_get_rt_tbl (DNA_TYPEID, 1);
#else
  mvl_type_ctrl[DNA_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[DNA_TYPEID].type_name, "DNA");

/* USERST :  */
/*
  mvl_type_ctrl[USERST_TYPEID].tdl = 
  "BVstring128";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[USERST_TYPEID].asn1_len = 3;
  mvl_type_ctrl[USERST_TYPEID].asn1 = "\x84\x01\x80";
#endif
  mvl_type_ctrl[USERST_TYPEID].num_rt = 1;
  mvl_type_ctrl[USERST_TYPEID].data_size = 18;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[USERST_TYPEID].rt = u_mvl_get_rt_tbl (USERST_TYPEID, 1);
#else
  mvl_type_ctrl[USERST_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[USERST_TYPEID].type_name, "USERST");

/* RTYP_BOOL : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BOOL_TYPEID].tdl = 
  "<BOOL>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BOOL_TYPEID].asn1_len = 2;
  mvl_type_ctrl[RTYP_BOOL_TYPEID].asn1 = "\x83\x00";
#endif
  mvl_type_ctrl[RTYP_BOOL_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BOOL_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BOOL_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BOOL_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BOOL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BOOL_TYPEID].type_name, "RTYP_BOOL");

/* RTYP_BTIME6 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].tdl = 
  "<BTIME6>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].asn1 = "\x8c\x01\x01";
#endif
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BTIME6_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BTIME6_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BTIME6_TYPEID].type_name, "RTYP_BTIME6");

/* RTYP_BSTR6 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].tdl = 
  "Bstring6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].asn1 = "\x84\x01\x06";
#endif
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BSTR6_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BSTR6_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BSTR6_TYPEID].type_name, "RTYP_BSTR6");

/* RTYP_BSTR8 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].tdl = 
  "Bstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].asn1 = "\x84\x01\x08";
#endif
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BSTR8_TYPEID].type_name, "RTYP_BSTR8");

/* RTYP_BSTR9 : Client needs for writing OptFlds */
/*
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].tdl = 
  "Bstring9";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].asn1 = "\x84\x01\x09";
#endif
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BSTR9_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BSTR9_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BSTR9_TYPEID].type_name, "RTYP_BSTR9");

/* RTYP_BVSTR6 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].tdl = 
  "Bvstring6";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].asn1 = "\x84\x01\xfa";
#endif
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].data_size = 3;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BVSTR6_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BVSTR6_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BVSTR6_TYPEID].type_name, "RTYP_BVSTR6");

/* RTYP_BVSTR8 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].tdl = 
  "Bvstring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].asn1 = "\x84\x01\xf8";
#endif
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].data_size = 3;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BVSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BVSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BVSTR8_TYPEID].type_name, "RTYP_BVSTR8");

/* RTYP_BVSTR10 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].tdl = 
  "Bvstring10";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].asn1 = "\x84\x01\xf6";
#endif
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_BVSTR10_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_BVSTR10_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_BVSTR10_TYPEID].type_name, "RTYP_BVSTR10");

/* RTYP_INT8U : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_INT8U_TYPEID].tdl = 
  "<INT8U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_INT8U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_INT8U_TYPEID].asn1 = "\x86\x01\x08";
#endif
  mvl_type_ctrl[RTYP_INT8U_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_INT8U_TYPEID].data_size = 1;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_INT8U_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_INT8U_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_INT8U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_INT8U_TYPEID].type_name, "RTYP_INT8U");

/* RTYP_INT16U : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_INT16U_TYPEID].tdl = 
  "<INT16U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_INT16U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_INT16U_TYPEID].asn1 = "\x86\x01\x10";
#endif
  mvl_type_ctrl[RTYP_INT16U_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_INT16U_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_INT16U_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_INT16U_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_INT16U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_INT16U_TYPEID].type_name, "RTYP_INT16U");

/* RTYP_OSTR8 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].tdl = 
  "Ostring8";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].asn1 = "\x89\x01\x08";
#endif
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].data_size = 8;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_OSTR8_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_OSTR8_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_OSTR8_TYPEID].type_name, "RTYP_OSTR8");

/* RTYP_VSTR32 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].tdl = 
  "<VSTR32>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].asn1 = "\x8a\x01\xe0";
#endif
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].data_size = 33;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_VSTR32_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_VSTR32_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_VSTR32_TYPEID].type_name, "RTYP_VSTR32");

/* RTYP_VSTR65 : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].tdl = 
  "<VSTR65>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].asn1 = "\x8a\x01\xbf";
#endif
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].data_size = 66;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_VSTR65_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_VSTR65_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_VSTR65_TYPEID].type_name, "RTYP_VSTR65");

/* RTYP_INT32U : UCAreporttypes */
/*
  mvl_type_ctrl[RTYP_INT32U_TYPEID].tdl = 
  "<INT32U>";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[RTYP_INT32U_TYPEID].asn1_len = 3;
  mvl_type_ctrl[RTYP_INT32U_TYPEID].asn1 = "\x86\x01\x20";
#endif
  mvl_type_ctrl[RTYP_INT32U_TYPEID].num_rt = 1;
  mvl_type_ctrl[RTYP_INT32U_TYPEID].data_size = 4;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[RTYP_INT32U_TYPEID].rt = u_mvl_get_rt_tbl (RTYP_INT32U_TYPEID, 1);
#else
  mvl_type_ctrl[RTYP_INT32U_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[RTYP_INT32U_TYPEID].type_name, "RTYP_INT32U");

/* I16 : Single 16-bit signed integer */
/*
  mvl_type_ctrl[I16_TYPEID].tdl = 
  "Short";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[I16_TYPEID].asn1_len = 3;
  mvl_type_ctrl[I16_TYPEID].asn1 = "\x85\x01\x10";
#endif
  mvl_type_ctrl[I16_TYPEID].num_rt = 1;
  mvl_type_ctrl[I16_TYPEID].data_size = 2;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[I16_TYPEID].rt = u_mvl_get_rt_tbl (I16_TYPEID, 1);
#else
  mvl_type_ctrl[I16_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[I16_TYPEID].type_name, "I16");

/* UTF8VSTRING13 : variable len Unicode UTF8 string */
/*
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].tdl = 
  "UTF8Vstring13";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].asn1_len = 3;
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].asn1 = "\x90\x01\xf3";
#endif
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].num_rt = 1;
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].data_size = 28;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].rt = u_mvl_get_rt_tbl (UTF8VSTRING13_TYPEID, 1);
#else
  mvl_type_ctrl[UTF8VSTRING13_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[UTF8VSTRING13_TYPEID].type_name, "UTF8VSTRING13");

/* Originator : Originator */
/*
  mvl_type_ctrl[Originator_TYPEID].tdl = 
  "{(orCat)<ENUMERATED8>,(orIdent)<OCTET_STRING64>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Originator_TYPEID].asn1_len = 34;
  mvl_type_ctrl[Originator_TYPEID].asn1 = "\xa2\x20\xa1\x1e\x30\x0c\x80\x05\x6f\x72\x43\
\x61\x74\xa1\x03\x85\x01\x08\x30\x0e\x80\x07\x6f\x72\x49\x64\x65\x6e\x74\
\xa1\x03\x89\x01\xc0";
#endif
  mvl_type_ctrl[Originator_TYPEID].num_rt = 4;
  mvl_type_ctrl[Originator_TYPEID].data_size = 68;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Originator_TYPEID].rt = u_mvl_get_rt_tbl (Originator_TYPEID, 4);
#else
  mvl_type_ctrl[Originator_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Originator_TYPEID].type_name, "Originator");

/* SBOw_BOOL : yk */
/*
  mvl_type_ctrl[SBOw_BOOL_TYPEID].tdl = 
  "{(ctlVal)<BOOLEAN>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT\
8U>,(T)<EntryTime>,(Test)<BOOLEAN>,(Check)<CODED_ENUM2>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SBOw_BOOL_TYPEID].asn1_len = 129;
  mvl_type_ctrl[SBOw_BOOL_TYPEID].asn1 = "\xa2\x7f\xa1\x7d\x30\x0c\x80\x06\x63\x74\x6c\
\x56\x61\x6c\xa1\x02\x83\x00\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\x6d\xa1\
\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\x20\xa1\
\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\x0e\x80\
\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\x06\x63\
\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\x03\x8c\
\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00\x30\x0c\x80\x05\
\x43\x68\x65\x63\x6b\xa1\x03\x84\x01\x02";
#endif
  mvl_type_ctrl[SBOw_BOOL_TYPEID].num_rt = 12;
  mvl_type_ctrl[SBOw_BOOL_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SBOw_BOOL_TYPEID].rt = u_mvl_get_rt_tbl (SBOw_BOOL_TYPEID, 12);
#else
  mvl_type_ctrl[SBOw_BOOL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SBOw_BOOL_TYPEID].type_name, "SBOw_BOOL");

/* Cancel_BOOL : yk */
/*
  mvl_type_ctrl[Cancel_BOOL_TYPEID].tdl = 
  "{(ctlVal)<BOOLEAN>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT\
8U>,(T)<EntryTime>,(Test)<BOOLEAN>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Cancel_BOOL_TYPEID].asn1_len = 115;
  mvl_type_ctrl[Cancel_BOOL_TYPEID].asn1 = "\xa2\x71\xa1\x6f\x30\x0c\x80\x06\x63\x74\x6c\
\x56\x61\x6c\xa1\x02\x83\x00\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\x6d\xa1\
\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\x20\xa1\
\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\x0e\x80\
\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\x06\x63\
\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\x03\x8c\
\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00";
#endif
  mvl_type_ctrl[Cancel_BOOL_TYPEID].num_rt = 11;
  mvl_type_ctrl[Cancel_BOOL_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Cancel_BOOL_TYPEID].rt = u_mvl_get_rt_tbl (Cancel_BOOL_TYPEID, 11);
#else
  mvl_type_ctrl[Cancel_BOOL_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Cancel_BOOL_TYPEID].type_name, "Cancel_BOOL");

/* SBOw_INT : receives service parameters */
/*
  mvl_type_ctrl[SBOw_INT_TYPEID].tdl = 
  "{(ctlVal)<INT32>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT8U\
>,(T)<EntryTime>,(Test)<BOOLEAN>,(Check)<CODED_ENUM2>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SBOw_INT_TYPEID].asn1_len = 131;
  mvl_type_ctrl[SBOw_INT_TYPEID].asn1 = "\xa2\x81\x80\xa1\x7e\x30\x0d\x80\x06\x63\x74\
\x6c\x56\x61\x6c\xa1\x03\x85\x01\x20\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\
\x6d\xa1\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\
\x20\xa1\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\
\x0e\x80\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\
\x06\x63\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\
\x03\x8c\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00\x30\x0c\
\x80\x05\x43\x68\x65\x63\x6b\xa1\x03\x84\x01\x02";
#endif
  mvl_type_ctrl[SBOw_INT_TYPEID].num_rt = 12;
  mvl_type_ctrl[SBOw_INT_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SBOw_INT_TYPEID].rt = u_mvl_get_rt_tbl (SBOw_INT_TYPEID, 12);
#else
  mvl_type_ctrl[SBOw_INT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SBOw_INT_TYPEID].type_name, "SBOw_INT");

/* Cancel_INT : receives service parameters */
/*
  mvl_type_ctrl[Cancel_INT_TYPEID].tdl = 
  "{(ctlVal)<INT32>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT8U\
>,(T)<EntryTime>,(Test)<BOOLEAN>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Cancel_INT_TYPEID].asn1_len = 116;
  mvl_type_ctrl[Cancel_INT_TYPEID].asn1 = "\xa2\x72\xa1\x70\x30\x0d\x80\x06\x63\x74\x6c\
\x56\x61\x6c\xa1\x03\x85\x01\x20\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\x6d\
\xa1\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\x20\
\xa1\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\x0e\
\x80\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\x06\
\x63\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\x03\
\x8c\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00";
#endif
  mvl_type_ctrl[Cancel_INT_TYPEID].num_rt = 11;
  mvl_type_ctrl[Cancel_INT_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Cancel_INT_TYPEID].rt = u_mvl_get_rt_tbl (Cancel_INT_TYPEID, 11);
#else
  mvl_type_ctrl[Cancel_INT_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Cancel_INT_TYPEID].type_name, "Cancel_INT");

/* SBOw_INTU : yt */
/*
  mvl_type_ctrl[SBOw_INTU_TYPEID].tdl = 
  "{(ctlVal)<INT32>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT8U\
>,(T)<EntryTime>,(Test)<BOOLEAN>,(Check)<CODED_ENUM2>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[SBOw_INTU_TYPEID].asn1_len = 131;
  mvl_type_ctrl[SBOw_INTU_TYPEID].asn1 = "\xa2\x81\x80\xa1\x7e\x30\x0d\x80\x06\x63\x74\
\x6c\x56\x61\x6c\xa1\x03\x85\x01\x20\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\
\x6d\xa1\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\
\x20\xa1\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\
\x0e\x80\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\
\x06\x63\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\
\x03\x8c\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00\x30\x0c\
\x80\x05\x43\x68\x65\x63\x6b\xa1\x03\x84\x01\x02";
#endif
  mvl_type_ctrl[SBOw_INTU_TYPEID].num_rt = 12;
  mvl_type_ctrl[SBOw_INTU_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[SBOw_INTU_TYPEID].rt = u_mvl_get_rt_tbl (SBOw_INTU_TYPEID, 12);
#else
  mvl_type_ctrl[SBOw_INTU_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[SBOw_INTU_TYPEID].type_name, "SBOw_INTU");

/* Cancel_INTU : yt */
/*
  mvl_type_ctrl[Cancel_INTU_TYPEID].tdl = 
  "{(ctlVal)<INT32>,(operTm)<TimeStamp>,(origin)<Originator>,(ctlNum)<INT8U\
>,(T)<EntryTime>,(Test)<BOOLEAN>,}";
*/
#if !defined(MVL_DYN_ASN1_TYPES)
  mvl_type_ctrl[Cancel_INTU_TYPEID].asn1_len = 116;
  mvl_type_ctrl[Cancel_INTU_TYPEID].asn1 = "\xa2\x72\xa1\x70\x30\x0d\x80\x06\x63\x74\x6c\
\x56\x61\x6c\xa1\x03\x85\x01\x20\x30\x0c\x80\x06\x6f\x70\x65\x72\x54\x6d\
\xa1\x02\x91\x00\x30\x2c\x80\x06\x6f\x72\x69\x67\x69\x6e\xa1\x22\xa2\x20\
\xa1\x1e\x30\x0c\x80\x05\x6f\x72\x43\x61\x74\xa1\x03\x85\x01\x08\x30\x0e\
\x80\x07\x6f\x72\x49\x64\x65\x6e\x74\xa1\x03\x89\x01\xc0\x30\x0d\x80\x06\
\x63\x74\x6c\x4e\x75\x6d\xa1\x03\x86\x01\x08\x30\x08\x80\x01\x54\xa1\x03\
\x8c\x01\x01\x30\x0a\x80\x04\x54\x65\x73\x74\xa1\x02\x83\x00";
#endif
  mvl_type_ctrl[Cancel_INTU_TYPEID].num_rt = 11;
  mvl_type_ctrl[Cancel_INTU_TYPEID].data_size = 100;
#if defined USR_SUPPLIED_RT
  mvl_type_ctrl[Cancel_INTU_TYPEID].rt = u_mvl_get_rt_tbl (Cancel_INTU_TYPEID, 11);
#else
  mvl_type_ctrl[Cancel_INTU_TYPEID].rt = mvl_rt_tables[rt_table_index++];
#endif /* #if defined USR_SUPPLIED_RT */
  strcpy (mvl_type_ctrl[Cancel_INTU_TYPEID].type_name, "Cancel_INTU");


#if defined USR_SUPPLIED_RT
  u_mvl_end_init_rt_tbl ();
#endif

#ifdef _MVL_TYPE_CTRL_use_one_device_
  *pp_mvl_type_ctrl = mvl_type_ctrl;
#endif

  }


/************************************************************************/
/* RUNTIME TYPE DATA */


#if !defined USR_SUPPLIED_RT

/************************************************************************/
/* BOOLEAN : :T */

SD_CONST static RUNTIME_TYPE mvl_rt_table_0[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT8 : -128 to 127 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_1[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT16 : -32,768 to 32,767 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_2[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT32 : -2,147,483,648 to 2,147,483,647 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_3[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT128 : -2**127 to (2**127)-1 Good luck */

SD_CONST static RUNTIME_TYPE mvl_rt_table_4[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT8U : 0 to 255 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_5[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT16U : 0 to 65,535 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_6[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT32U : 0 to 4,294,967,295 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_7[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLOAT32 : Range of values IEEE 754 single */

SD_CONST static RUNTIME_TYPE mvl_rt_table_8[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLOAT64 : Range of values IEEE 754 double */

SD_CONST static RUNTIME_TYPE mvl_rt_table_9[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENUMERATED8 : signed enumeration8-bits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_10[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENUMERATED16 : signed enumeration16-bits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_11[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OCTET_STRING8 : Maximum 8 Octets */

SD_CONST static RUNTIME_TYPE mvl_rt_table_12[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    10,				/* el_size				*/
    10,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OCTET_STRING64 : Maximum 64 Octets */

SD_CONST static RUNTIME_TYPE mvl_rt_table_13[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VISIBLE_STRING255 : Maximum 255 characters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_14[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    256,				/* el_size				*/
    256,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -255,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VISIBLE_STRING64 : Maximum 64 characters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_15[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    65,				/* el_size				*/
    65,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VISIBLE_STRING97 : Maximum 97 characters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_16[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    98,				/* el_size				*/
    98,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -97,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* UTC_TM : Used by TimeStamp */

SD_CONST static RUNTIME_TYPE mvl_rt_table_17[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CODED_ENUM2 : 2 bits - 4 values */

SD_CONST static RUNTIME_TYPE mvl_rt_table_18[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* UNICODE_STRING255 : Maximum 255 Unicode */

SD_CONST static RUNTIME_TYPE mvl_rt_table_19[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UTF8_STRING,		/* el_tag				*/
    512,				/* el_size				*/
    512,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -255,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TimeStamp : UTC Time */

SD_CONST static RUNTIME_TYPE mvl_rt_table_20[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EntryTime :  8.1 Section 8.1.3.7 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_21[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Quality : Quality */

SD_CONST static RUNTIME_TYPE mvl_rt_table_22[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -13,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* IDENT :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_23[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BOOL : generalboolean */

SD_CONST static RUNTIME_TYPE mvl_rt_table_24[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* B2 : GeneralDoubleBit */

SD_CONST static RUNTIME_TYPE mvl_rt_table_25[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* D : generaldescriptioncomponent */

SD_CONST static RUNTIME_TYPE mvl_rt_table_26[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DB : Deadband */

SD_CONST static RUNTIME_TYPE mvl_rt_table_27[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* F : Generalizedfloatingpoint */

SD_CONST static RUNTIME_TYPE mvl_rt_table_28[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FF : FrozenFloatingPointvalue */

SD_CONST static RUNTIME_TYPE mvl_rt_table_29[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* HL : HighLimit */

SD_CONST static RUNTIME_TYPE mvl_rt_table_30[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* HHL : HighHighLimit */

SD_CONST static RUNTIME_TYPE mvl_rt_table_31[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LL : lowlimit */

SD_CONST static RUNTIME_TYPE mvl_rt_table_32[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LLL : lowlowlimit */

SD_CONST static RUNTIME_TYPE mvl_rt_table_33[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* I : Generalizedicomponenttype */

SD_CONST static RUNTIME_TYPE mvl_rt_table_34[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FI : frozenicomponenttype */

SD_CONST static RUNTIME_TYPE mvl_rt_table_35[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* O : Offset */

SD_CONST static RUNTIME_TYPE mvl_rt_table_36[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Q : Generalizedqualitybitstringtype */

SD_CONST static RUNTIME_TYPE mvl_rt_table_37[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* R : runningcount */

SD_CONST static RUNTIME_TYPE mvl_rt_table_38[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FR : frozenrunningcount */

SD_CONST static RUNTIME_TYPE mvl_rt_table_39[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* S : scale */

SD_CONST static RUNTIME_TYPE mvl_rt_table_40[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* T : GeneralizedTimeStamp */

SD_CONST static RUNTIME_TYPE mvl_rt_table_41[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FT : frozentimestamp */

SD_CONST static RUNTIME_TYPE mvl_rt_table_42[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* PP : PseudoPoint */

SD_CONST static RUNTIME_TYPE mvl_rt_table_43[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* U : Enumeratevalue */

SD_CONST static RUNTIME_TYPE mvl_rt_table_44[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR8 : VisibleString8-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_45[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    9,				/* el_size				*/
    9,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR16 : VisibleString16-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_46[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR32 : VisbleString32-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_47[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR64 : VisibleString64-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_48[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    65,				/* el_size				*/
    65,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR65 : VisibleString65-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_49[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VSTR128 : VisibleString128-variablelength */

SD_CONST static RUNTIME_TYPE mvl_rt_table_50[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    129,				/* el_size				*/
    129,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -128,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR1 : Twobitbistring */

SD_CONST static RUNTIME_TYPE mvl_rt_table_51[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR2 : Twobitbistring */

SD_CONST static RUNTIME_TYPE mvl_rt_table_52[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR8 : Bitstring-8 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_53[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR10 : Bitstring-10 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_54[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR16 : Bitstring-16 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_55[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BSTR32 : Bitstring-32 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_56[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VBSTR8 : VariablelengthBitstring-8 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_57[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    3,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VBSTR16 : VariablelengthBitstring-16 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_58[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VBSTR32 : VariablelengthBitstring-32 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_59[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    6,				/* el_size				*/
    6,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT8S : SignedInteger-8 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_60[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT16S : SignedInteger-16 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_61[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INT32S : SignedInteger-32 */

SD_CONST static RUNTIME_TYPE mvl_rt_table_62[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLT32 : 32bitfloatingpoint */

SD_CONST static RUNTIME_TYPE mvl_rt_table_63[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLT64 : 64bitfloatingpoint */

SD_CONST static RUNTIME_TYPE mvl_rt_table_64[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BTIME4 : Binarytimeofday */

SD_CONST static RUNTIME_TYPE mvl_rt_table_65[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BTIME6 : Binarytimeofdaytomsec */

SD_CONST static RUNTIME_TYPE mvl_rt_table_66[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENUM8 : signed enumeration8-bits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_67[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENUM16 : signed enumeration16-bits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_68[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MAG : Magnitude */

SD_CONST static RUNTIME_TYPE mvl_rt_table_69[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ANG : Angle */

SD_CONST static RUNTIME_TYPE mvl_rt_table_70[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ACCRPTENA : AccumulatorReportEnable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_71[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ACCRS : AccumulatorReset */

SD_CONST static RUNTIME_TYPE mvl_rt_table_72[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ACCSET : AccumulatorSetting */

SD_CONST static RUNTIME_TYPE mvl_rt_table_73[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ACTTAGARR : Accumulatortagarray */

SD_CONST static RUNTIME_TYPE mvl_rt_table_74[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ANCESTRY : Ancestry */

SD_CONST static RUNTIME_TYPE mvl_rt_table_75[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ANFMT : AnalogFormat */

SD_CONST static RUNTIME_TYPE mvl_rt_table_76[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    7,				/* el_size				*/
    7,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BUFTIM : Buffertime */

SD_CONST static RUNTIME_TYPE mvl_rt_table_77[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CID : CanonicalID */

SD_CONST static RUNTIME_TYPE mvl_rt_table_78[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CKTID : CircuitID */

SD_CONST static RUNTIME_TYPE mvl_rt_table_79[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CKTPHS : CircuitPhases */

SD_CONST static RUNTIME_TYPE mvl_rt_table_80[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CLASS : Classidentifier */

SD_CONST static RUNTIME_TYPE mvl_rt_table_81[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* COMMADR : Communicationaddress */

SD_CONST static RUNTIME_TYPE mvl_rt_table_82[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* COMMREV : Communicationrevision */

SD_CONST static RUNTIME_TYPE mvl_rt_table_83[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    9,				/* el_size				*/
    9,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CONTCURRTG : Continuouscurrentrating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_84[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* COUNT : count */

SD_CONST static RUNTIME_TYPE mvl_rt_table_85[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* CRIRPT : criticalreport */

SD_CONST static RUNTIME_TYPE mvl_rt_table_86[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DATSETNAM : Datasetname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_87[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DESTAE : destinationAEname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_88[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DEVFCT : devicefunction */

SD_CONST static RUNTIME_TYPE mvl_rt_table_89[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DEVMDLS : devicemodelname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_90[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    129,				/* el_size				*/
    129,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -128,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DOW : Dayoftheweek */

SD_CONST static RUNTIME_TYPE mvl_rt_table_91[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DOWSCHED : Dayoftheweekschedule */

SD_CONST static RUNTIME_TYPE mvl_rt_table_92[3] =
  {
    {				/* rt[0] init data ...			*/
    RT_ARR_START,		/* el_tag				*/
    0,				/* el_size				*/
    24,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_ARR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENABLE : enable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_93[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENCOPT : encodingoptions */

SD_CONST static RUNTIME_TYPE mvl_rt_table_94[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ENROLL : enrollname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_95[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EORBDESC :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_96[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    65,				/* el_size				*/
    65,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVACON : evaluationconditionname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_97[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVACNS : evaluationconditionname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_98[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVACRI : evaluationcriterianame */

SD_CONST static RUNTIME_TYPE mvl_rt_table_99[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVAFCT : evaluationfunctionname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_100[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVAPAR : evaluationparametersname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_101[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* EVTENA : eventenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_102[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLTCURDUR : Faultcurrentduration */

SD_CONST static RUNTIME_TYPE mvl_rt_table_103[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FLTCURRTG : Placeholder */

SD_CONST static RUNTIME_TYPE mvl_rt_table_104[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FRZENA : freezeenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_105[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FRZPD : freezeperiod */

SD_CONST static RUNTIME_TYPE mvl_rt_table_106[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* FWDPWRHA : ForwardPowerharmonics */

SD_CONST static RUNTIME_TYPE mvl_rt_table_107[3] =
  {
    {				/* rt[0] init data ...			*/
    RT_ARR_START,		/* el_tag				*/
    0,				/* el_size				*/
    124,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_ARR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* HWREV : HardwareRevision */

SD_CONST static RUNTIME_TYPE mvl_rt_table_108[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    9,				/* el_size				*/
    9,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* HZRTG : Hertzrating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_109[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INDAT : InputDataName */

SD_CONST static RUNTIME_TYPE mvl_rt_table_110[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* INTGPD : IntegrityPeriod */

SD_CONST static RUNTIME_TYPE mvl_rt_table_111[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LINLENM : Linelengthinmeters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_112[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOC : Location */

SD_CONST static RUNTIME_TYPE mvl_rt_table_113[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    129,				/* el_size				*/
    129,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -128,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOGENA : Logenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_114[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOGENR : Logenroll */

SD_CONST static RUNTIME_TYPE mvl_rt_table_115[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOGNAM : Logname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_116[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOGSIZE : Logsize */

SD_CONST static RUNTIME_TYPE mvl_rt_table_117[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* LOGWRP : LogWrapped */

SD_CONST static RUNTIME_TYPE mvl_rt_table_118[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MAC : MediumAccessControl */

SD_CONST static RUNTIME_TYPE mvl_rt_table_119[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MDL : Modelname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_120[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MED : mediatype */

SD_CONST static RUNTIME_TYPE mvl_rt_table_121[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MXREF : Measurementreference */

SD_CONST static RUNTIME_TYPE mvl_rt_table_122[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* MXTYP : MeasurementType */

SD_CONST static RUNTIME_TYPE mvl_rt_table_123[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NAME : ownername */

SD_CONST static RUNTIME_TYPE mvl_rt_table_124[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NEWTIM : newesttime */

SD_CONST static RUNTIME_TYPE mvl_rt_table_125[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NUMBITS : numberofbits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_126[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NUMPLS : numberofpulses */

SD_CONST static RUNTIME_TYPE mvl_rt_table_127[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NUMSMP : numberofsamples */

SD_CONST static RUNTIME_TYPE mvl_rt_table_128[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* NUMUNIT : numberofunits */

SD_CONST static RUNTIME_TYPE mvl_rt_table_129[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OFFDUR : Offduration */

SD_CONST static RUNTIME_TYPE mvl_rt_table_130[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OLDTIM : Oldesttime */

SD_CONST static RUNTIME_TYPE mvl_rt_table_131[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* ONDUR : Onduration */

SD_CONST static RUNTIME_TYPE mvl_rt_table_132[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OPERDEV : Operatedevice */

SD_CONST static RUNTIME_TYPE mvl_rt_table_133[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OPTFLDS : Optionalfields */

SD_CONST static RUNTIME_TYPE mvl_rt_table_134[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OUTDAT : outputdatasetname */

SD_CONST static RUNTIME_TYPE mvl_rt_table_135[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OVRST : Overflowstatus */

SD_CONST static RUNTIME_TYPE mvl_rt_table_136[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* OWN : Owner */

SD_CONST static RUNTIME_TYPE mvl_rt_table_137[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* PRO : enumeratedprotocolid */

SD_CONST static RUNTIME_TYPE mvl_rt_table_138[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* PWRHA : powerharmonics */

SD_CONST static RUNTIME_TYPE mvl_rt_table_139[3] =
  {
    {				/* rt[0] init data ...			*/
    RT_ARR_START,		/* el_tag				*/
    0,				/* el_size				*/
    124,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_ARR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* QURPTENA : qualityreportenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_140[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RBEPD : reportperiod */

SD_CONST static RUNTIME_TYPE mvl_rt_table_141[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RPTENA : Reportenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_142[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RPTID : ReportID */

SD_CONST static RUNTIME_TYPE mvl_rt_table_143[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RVSPWRHA : reversepowerharmonics */

SD_CONST static RUNTIME_TYPE mvl_rt_table_144[3] =
  {
    {				/* rt[0] init data ...			*/
    RT_ARR_START,		/* el_tag				*/
    0,				/* el_size				*/
    124,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_ARR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SBOENA : SBOenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_145[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SETTIMOUT : SBOSelectTimeout */

SD_CONST static RUNTIME_TYPE mvl_rt_table_146[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SEQNUM : Sequencenumber */

SD_CONST static RUNTIME_TYPE mvl_rt_table_147[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SERNUM : Serialnumber */

SD_CONST static RUNTIME_TYPE mvl_rt_table_148[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SFTREV : SoftwareRevisionNumber */

SD_CONST static RUNTIME_TYPE mvl_rt_table_149[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    9,				/* el_size				*/
    9,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SMPRATE : samplerate */

SD_CONST static RUNTIME_TYPE mvl_rt_table_150[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TAGD : tagdescription */

SD_CONST static RUNTIME_TYPE mvl_rt_table_151[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    129,				/* el_size				*/
    129,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -128,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TAGID : tagID */

SD_CONST static RUNTIME_TYPE mvl_rt_table_152[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TAGOWN : tagowner */

SD_CONST static RUNTIME_TYPE mvl_rt_table_153[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TAGTYP : tagtypepermitted */

SD_CONST static RUNTIME_TYPE mvl_rt_table_154[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TEMPRAT : temperaturerating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_155[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TEMPRTG : temperaturerating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_156[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TIMOFFRZ : timeoffreeze */

SD_CONST static RUNTIME_TYPE mvl_rt_table_157[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TIMRPTENA : Timestampreportenable */

SD_CONST static RUNTIME_TYPE mvl_rt_table_158[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TRGOPS : Triggeroptions */

SD_CONST static RUNTIME_TYPE mvl_rt_table_159[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* TRGS : numberoftriggers */

SD_CONST static RUNTIME_TYPE mvl_rt_table_160[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* UNITVARRTG : Unitvarrating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_161[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* UNKPWRHA : Unkownharmonicdirection */

SD_CONST static RUNTIME_TYPE mvl_rt_table_162[3] =
  {
    {				/* rt[0] init data ...			*/
    RT_ARR_START,		/* el_tag				*/
    0,				/* el_size				*/
    124,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_FLOATING_POINT,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_ARR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      31,			/*   num_elmnts				*/
      1			/*   num_rt_blks				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* USEST : utilizationstatus */

SD_CONST static RUNTIME_TYPE mvl_rt_table_163[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VARRTG : Varsrating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_164[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VARTG : VARsrating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_165[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VND : VendorID */

SD_CONST static RUNTIME_TYPE mvl_rt_table_166[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* VRTG : voltagerating */

SD_CONST static RUNTIME_TYPE mvl_rt_table_167[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    17,				/* el_size				*/
    17,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -16,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* WRNLEV : logwarninglevel */

SD_CONST static RUNTIME_TYPE mvl_rt_table_168[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* WRNST : warningstatus */

SD_CONST static RUNTIME_TYPE mvl_rt_table_169[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* PHSTAR : PhaseTarget */

SD_CONST static RUNTIME_TYPE mvl_rt_table_170[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SBO :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_171[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* STNUM :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_172[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* HOLDTIM :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_173[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* BACKTIM :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_174[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* PHSID :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_175[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* DNA :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_176[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* USERST :  */

SD_CONST static RUNTIME_TYPE mvl_rt_table_177[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    18,				/* el_size				*/
    18,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -128,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BOOL : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_178[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BTIME6 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_179[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BSTR6 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_180[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BSTR8 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_181[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BSTR9 : Client needs for writing OptFlds */

SD_CONST static RUNTIME_TYPE mvl_rt_table_182[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BVSTR6 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_183[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    3,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BVSTR8 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_184[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    3,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_BVSTR10 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_185[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -10,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_INT8U : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_186[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_INT16U : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_187[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_OSTR8 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_188[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_VSTR32 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_189[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    33,				/* el_size				*/
    33,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -32,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_VSTR65 : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_190[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_VISIBLE_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -65,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* RTYP_INT32U : UCAreporttypes */

SD_CONST static RUNTIME_TYPE mvl_rt_table_191[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* I16 : Single 16-bit signed integer */

SD_CONST static RUNTIME_TYPE mvl_rt_table_192[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    2,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* UTF8VSTRING13 : variable len Unicode UTF8 string */

SD_CONST static RUNTIME_TYPE mvl_rt_table_193[1] =
  {
    {				/* rt[0] init data ...			*/
    RT_UTF8_STRING,		/* el_tag				*/
    28,				/* el_size				*/
    28,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -13,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Originator : Originator */

SD_CONST static RUNTIME_TYPE mvl_rt_table_194[4] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SBOw_BOOL : yk */

SD_CONST static RUNTIME_TYPE mvl_rt_table_195[12] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Check, 	/* comp_name_ptr 'Check'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CHECK_STRING_INDEX, 	/* name_index 'Check'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[11] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Cancel_BOOL : yk */

SD_CONST static RUNTIME_TYPE mvl_rt_table_196[11] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SBOw_INT : receives service parameters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_197[12] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Check, 	/* comp_name_ptr 'Check'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CHECK_STRING_INDEX, 	/* name_index 'Check'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[11] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Cancel_INT : receives service parameters */

SD_CONST static RUNTIME_TYPE mvl_rt_table_198[11] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* SBOw_INTU : yt */

SD_CONST static RUNTIME_TYPE mvl_rt_table_199[12] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    1,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_BIT_STRING,		/* el_tag				*/
    3,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Check, 	/* comp_name_ptr 'Check'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CHECK_STRING_INDEX, 	/* name_index 'Check'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[11] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      10,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/
/* Cancel_INTU : yt */

SD_CONST static RUNTIME_TYPE mvl_rt_table_200[11] =
  {
    {				/* rt[0] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    100,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[1] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    4,				/* el_size				*/
    4,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      4,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlVal, 	/* comp_name_ptr 'ctlVal'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLVAL_STRING_INDEX, 	/* name_index 'ctlVal'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[2] init data ...			*/
    RT_UTC_TIME,		/* el_tag				*/
    12,				/* el_size				*/
    12,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      8,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_operTm, 	/* comp_name_ptr 'operTm'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_OPERTM_STRING_INDEX, 	/* name_index 'operTm'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[3] init data ...			*/
    RT_STR_START,		/* el_tag				*/
    0,				/* el_size				*/
    68,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_origin, 	/* comp_name_ptr 'origin'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIGIN_STRING_INDEX, 	/* name_index 'origin'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[4] init data ...			*/
    RT_INTEGER,		/* el_tag				*/
    2,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orCat, 	/* comp_name_ptr 'orCat'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORCAT_STRING_INDEX, 	/* name_index 'orCat'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[5] init data ...			*/
    RT_OCTET_STRING,		/* el_tag				*/
    66,				/* el_size				*/
    66,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      -64,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_orIdent, 	/* comp_name_ptr 'orIdent'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_ORIDENT_STRING_INDEX, 	/* name_index 'orIdent'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[6] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      2,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[7] init data ...			*/
    RT_UNSIGNED,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_ctlNum, 	/* comp_name_ptr 'ctlNum'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_CTLNUM_STRING_INDEX, 	/* name_index 'ctlNum'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[8] init data ...			*/
    RT_BINARY_TIME,		/* el_tag				*/
    8,				/* el_size				*/
    8,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      6,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_T, 	/* comp_name_ptr 'T'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_T_STRING_INDEX, 	/* name_index 'T'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[9] init data ...			*/
    RT_BOOL,		/* el_tag				*/
    4,				/* el_size				*/
    1,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      1,			/*   el_len				*/
      0			/*   pad				*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    mvlCompName_Test, 	/* comp_name_ptr 'Test'				*/
#else	/* !USE_RT_TYPE_2	*/
    FO_TEST_STRING_INDEX, 	/* name_index 'Test'				*/
#endif	/* !USE_RT_TYPE_2	*/
    },
    {				/* rt[10] init data ...			*/
    RT_STR_END,		/* el_tag				*/
    0,				/* el_size				*/
    0,				/* offset_to_last			*/
      {				/* u					*/
      {				/* p					*/
      9,			/*   num_rt_blks				*/
      0			/*   pad					*/
      }				/* end 'p'				*/
      },			/* end 'u'				*/
#ifdef USE_RT_TYPE_2
    NULL,				/* comp_name_ptr 				*/
#else	/* !USE_RT_TYPE_2	*/
    0,				/* name_index 				*/
#endif	/* !USE_RT_TYPE_2	*/
    }
  };

/************************************************************************/


ST_INT rt_table_index;

SD_CONST RUNTIME_TYPE * SD_CONST mvl_rt_tables[] =
  {
  mvl_rt_table_0,
  mvl_rt_table_1,
  mvl_rt_table_2,
  mvl_rt_table_3,
  mvl_rt_table_4,
  mvl_rt_table_5,
  mvl_rt_table_6,
  mvl_rt_table_7,
  mvl_rt_table_8,
  mvl_rt_table_9,
  mvl_rt_table_10,
  mvl_rt_table_11,
  mvl_rt_table_12,
  mvl_rt_table_13,
  mvl_rt_table_14,
  mvl_rt_table_15,
  mvl_rt_table_16,
  mvl_rt_table_17,
  mvl_rt_table_18,
  mvl_rt_table_19,
  mvl_rt_table_20,
  mvl_rt_table_21,
  mvl_rt_table_22,
  mvl_rt_table_23,
  mvl_rt_table_24,
  mvl_rt_table_25,
  mvl_rt_table_26,
  mvl_rt_table_27,
  mvl_rt_table_28,
  mvl_rt_table_29,
  mvl_rt_table_30,
  mvl_rt_table_31,
  mvl_rt_table_32,
  mvl_rt_table_33,
  mvl_rt_table_34,
  mvl_rt_table_35,
  mvl_rt_table_36,
  mvl_rt_table_37,
  mvl_rt_table_38,
  mvl_rt_table_39,
  mvl_rt_table_40,
  mvl_rt_table_41,
  mvl_rt_table_42,
  mvl_rt_table_43,
  mvl_rt_table_44,
  mvl_rt_table_45,
  mvl_rt_table_46,
  mvl_rt_table_47,
  mvl_rt_table_48,
  mvl_rt_table_49,
  mvl_rt_table_50,
  mvl_rt_table_51,
  mvl_rt_table_52,
  mvl_rt_table_53,
  mvl_rt_table_54,
  mvl_rt_table_55,
  mvl_rt_table_56,
  mvl_rt_table_57,
  mvl_rt_table_58,
  mvl_rt_table_59,
  mvl_rt_table_60,
  mvl_rt_table_61,
  mvl_rt_table_62,
  mvl_rt_table_63,
  mvl_rt_table_64,
  mvl_rt_table_65,
  mvl_rt_table_66,
  mvl_rt_table_67,
  mvl_rt_table_68,
  mvl_rt_table_69,
  mvl_rt_table_70,
  mvl_rt_table_71,
  mvl_rt_table_72,
  mvl_rt_table_73,
  mvl_rt_table_74,
  mvl_rt_table_75,
  mvl_rt_table_76,
  mvl_rt_table_77,
  mvl_rt_table_78,
  mvl_rt_table_79,
  mvl_rt_table_80,
  mvl_rt_table_81,
  mvl_rt_table_82,
  mvl_rt_table_83,
  mvl_rt_table_84,
  mvl_rt_table_85,
  mvl_rt_table_86,
  mvl_rt_table_87,
  mvl_rt_table_88,
  mvl_rt_table_89,
  mvl_rt_table_90,
  mvl_rt_table_91,
  mvl_rt_table_92,
  mvl_rt_table_93,
  mvl_rt_table_94,
  mvl_rt_table_95,
  mvl_rt_table_96,
  mvl_rt_table_97,
  mvl_rt_table_98,
  mvl_rt_table_99,
  mvl_rt_table_100,
  mvl_rt_table_101,
  mvl_rt_table_102,
  mvl_rt_table_103,
  mvl_rt_table_104,
  mvl_rt_table_105,
  mvl_rt_table_106,
  mvl_rt_table_107,
  mvl_rt_table_108,
  mvl_rt_table_109,
  mvl_rt_table_110,
  mvl_rt_table_111,
  mvl_rt_table_112,
  mvl_rt_table_113,
  mvl_rt_table_114,
  mvl_rt_table_115,
  mvl_rt_table_116,
  mvl_rt_table_117,
  mvl_rt_table_118,
  mvl_rt_table_119,
  mvl_rt_table_120,
  mvl_rt_table_121,
  mvl_rt_table_122,
  mvl_rt_table_123,
  mvl_rt_table_124,
  mvl_rt_table_125,
  mvl_rt_table_126,
  mvl_rt_table_127,
  mvl_rt_table_128,
  mvl_rt_table_129,
  mvl_rt_table_130,
  mvl_rt_table_131,
  mvl_rt_table_132,
  mvl_rt_table_133,
  mvl_rt_table_134,
  mvl_rt_table_135,
  mvl_rt_table_136,
  mvl_rt_table_137,
  mvl_rt_table_138,
  mvl_rt_table_139,
  mvl_rt_table_140,
  mvl_rt_table_141,
  mvl_rt_table_142,
  mvl_rt_table_143,
  mvl_rt_table_144,
  mvl_rt_table_145,
  mvl_rt_table_146,
  mvl_rt_table_147,
  mvl_rt_table_148,
  mvl_rt_table_149,
  mvl_rt_table_150,
  mvl_rt_table_151,
  mvl_rt_table_152,
  mvl_rt_table_153,
  mvl_rt_table_154,
  mvl_rt_table_155,
  mvl_rt_table_156,
  mvl_rt_table_157,
  mvl_rt_table_158,
  mvl_rt_table_159,
  mvl_rt_table_160,
  mvl_rt_table_161,
  mvl_rt_table_162,
  mvl_rt_table_163,
  mvl_rt_table_164,
  mvl_rt_table_165,
  mvl_rt_table_166,
  mvl_rt_table_167,
  mvl_rt_table_168,
  mvl_rt_table_169,
  mvl_rt_table_170,
  mvl_rt_table_171,
  mvl_rt_table_172,
  mvl_rt_table_173,
  mvl_rt_table_174,
  mvl_rt_table_175,
  mvl_rt_table_176,
  mvl_rt_table_177,
  mvl_rt_table_178,
  mvl_rt_table_179,
  mvl_rt_table_180,
  mvl_rt_table_181,
  mvl_rt_table_182,
  mvl_rt_table_183,
  mvl_rt_table_184,
  mvl_rt_table_185,
  mvl_rt_table_186,
  mvl_rt_table_187,
  mvl_rt_table_188,
  mvl_rt_table_189,
  mvl_rt_table_190,
  mvl_rt_table_191,
  mvl_rt_table_192,
  mvl_rt_table_193,
  mvl_rt_table_194,
  mvl_rt_table_195,
  mvl_rt_table_196,
  mvl_rt_table_197,
  mvl_rt_table_198,
  mvl_rt_table_199,
  mvl_rt_table_200
  };


#endif /* #if defined USR_SUPPLIED_RT */

