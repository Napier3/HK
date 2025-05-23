/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*            	  1986 - 2003, All Rights Reserved.             	*/
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : mms_tdef.c						*/
/* PRODUCT(S)  : MMSEASE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/* Function to decode ASN.1 type definitions into Runtime typedefs	*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*			ms_runtime_create				*/
/*			ms_runtime_destroy				*/
/*			ms_is_rt_prim					*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 06/29/04  JRB     45    str_done: chk for empty structure.		*/
/* 12/09/03  JRB     44    Add LYNX support.				*/
/* 11/07/03  JRB     43    Fix misleading log message when decode done.	*/
/* 10/13/03  EJV     42    Removed defined(__VAX).			*/
/* 06/05/03  JRB     41    type_name_cstr_done: copy component names	*/
/*			   for USE_RT_TYPE_2.				*/
/* 04/28/03  JRB     40    Eliminate compiler warnings.			*/
/* 04/28/03  JRB     39    Add UTF8string support (see RT_UTF8_STRING).	*/
/* 03/13/03  JRB     38    u_ml_get_rt_type: chg from "func ptr" to func.*/
/* 02/20/03  JRB     37    get_str_comp_name ret err if name index	*/
/*			   can't be found for USE_RT_TYPE_3.		*/
/*			   type_name_cstr_done save & restore comp name	*/
/*			   for USE_RT_TYPE_2/USE_RT_TYPE_3.		*/
/* 02/20/03  JRB     36	   Del PSOS code.				*/
/* 01/20/03  CRM     35    Added "defined(linux)" code.			*/
/* 01/03/03  JRB     34    Move arr_loop* globals to locals in ms_get..	*/
/* 12/31/02  MDE     33    Eliminate use of m_calc_rt_size global.	*/
/* 12/26/02  JRB     32    Add ms_asn1_to_runtime_x for backward compat.*/
/* 12/16/02  JRB     31    Add ms_is_rt_prim funct.			*/
/* 11/11/02  JRB     30    Chg ms_runtime_create/destroy args.		*/
/*			   Make ms_asn1_to_runtime static, must call	*/
/*			   ms_runtime_create instead.			*/
/*			   Use DEC_INFO struct to avoid global vars.	*/
/*			   Pass aCtx to ms_asn1_to_runtime & pass	*/
/*			   DEC_INFO in aCtx->usr_info[0].		*/
/* 04/16/02  MDE     29    Now set name index for named struct elements	*/
/* 03/04/02  JRB     28    Add more "SD_CONST RUNTIME_TYPE *".		*/
/* 12/20/01  JRB     27    Converted to use ASN1R (re-entrant ASN1)	*/
/* 11/14/01  EJV     26    Added support for new MMS type UtcTime:	*/
/*			   Added fun get_utc_time_el;			*/
/*			   set_type_tags: added code for tag 17;	*/
/*			   _ms_m_get_rt_info: added case for RT_UTC_TIME*/
/*			   _ms_log_runtime: added case for RT_UTC_TIME;	*/
/* 10/18/01  JRB     25    Eliminate warning.				*/
/* 08/29/00  JRB     24    Del ms_comp_name_find function. Use macro.	*/
/* 07/28/00  JRB     23    Simplify RT_TYPE ifdefs.			*/
/*			   Fix SD_CONST usage & lint warnings.		*/
/*			   Make ms_type_nam* static. Only used here.	*/
/* 07/13/00  JRB     22    Add ms_runtime_create, ms_runtime_destroy,	*/
/*			     ms_comp_name_find.				*/
/* 06/29/00  JRB     21    Make ms_asn1_to_runtime work for MMS LITE.	*/
/*			     Must def USE_RT_TYPE_2 to save comp names.	*/
/* 09/13/99  MDE     20    Added SD_CONST modifiers			*/
/* 04/14/99  MDE     19    Removed unnecessary include files		*/
/* 02/23/99  JRB     18    MMS_LITE: "m_data_algn.. = m_def_data_algn.."*/
/*			   Don't need packed for backward compatibility.*/
/* 09/10/98  MDE     17    Changes to work better with MMS-LITE		*/
/* 08/21/98  EJV     16    __hpux STRSTRT_ALGN set from 3 to 0, and 	*/
/* 07/23/98  RKR     15	   OPEN_VMS STRSTRT_ALGN set from 3 to 0	*/
/* 06/26/98  EJV     14    m_def_data_algn_tbl only for __alpha DECUNIX.*/
/* 06/03/98  MDE     13    Corrected structure end alignment handling	*/
/* 03/23/98  MDE     12    Tweaks to structure alignment		*/
/* 03/12/98  MDE     11    Worked on structure alignment		*/
/* 02/10/98  MDE     10    Runtime type changes for LITE		*/
/* 11/04/97  DSF     09    Fixed alignment table for WIN32		*/
/* 10/30/97  MDE     08    Minor logging change				*/
/* 09/29/97  MDE     07    Minor logging change				*/
/* 08/27/97  MDE     06    Fixed problem with log runtime w/numrt = 0	*/
/* 08/15/97  MDE     05    BTOD handling changes			*/
/* 08/04/97  MDE     04    Minor cleanup				*/
/* 06/19/97  MDE     03    Added 64 bit integer support			*/
/* 06/09/97  MDE     02    Fixed MMS-LITE compile problems, other minor	*/
/* 04/08/97  MDE     01    Fixed 'RT Table too small prob w/named types	*/
/* 04/02/97  DTL   7.00    MMSEASE 7.0 release. See MODL70.DOC for	*/
/*			   history.					*/
/************************************************************************/

#include "glbtypes.h"

#include "sysincs.h"
#include "glbsem.h"
#include "mmsdefs.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "asn1defs.h"
#if defined(MMS_LITE)
#include "mvl_defs.h"
#endif

/************************************************************************/
/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif


/************************************************************************/

#ifdef MMS_LITE
ST_VOID (*u_rt_type_process) (SD_CONST RUNTIME_TYPE *rt, ST_INT num_rt);
#endif

static ST_VOID _ms_log_runtime (ST_INT indent, SD_CONST RUNTIME_TYPE *rt, 
				ST_INT num_rt);

static ST_VOID _do_padding (RUNTIME_TYPE *padDest, 
			    ST_INT *curr_offset, 
			    ST_INT algn);
static ST_VOID _get_struct_start_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out);
static ST_VOID _get_struct_end_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out);
static ST_VOID _get_arr_start_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out);

/************************************************************************/

static ST_VOID str_comp_seq_start (ASN1_DEC_CTXT *aCtx);	/* CTX 1 CSTR - seq of comp	*/
static ST_VOID get_num_arr_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID array_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID arr_el_cstr_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_arr_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID float_cstr_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_float_exp (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_float_fract (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_str_packed (ASN1_DEC_CTXT *aCtx);   	/* CTX 0 BOOL - packed		*/
static ST_VOID get_arr_packed (ASN1_DEC_CTXT *aCtx);
static ST_VOID type_name_cstr_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID type_name_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_named_type (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_array_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_struct_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_bool_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_bitstr_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_int_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_uint_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_float_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_octstr_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_vstr_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_gtime_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_btime_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_bcd_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_utc_time_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID get_utf8_el (ASN1_DEC_CTXT *aCtx);
static ST_VOID set_type_tags (ASN1_DEC_CTXT *aCtx);
static ST_VOID td_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID td_err (ASN1_DEC_CTXT *aCtx, ST_RET err);

/************************************************************************/
/************************************************************************/
/* Variables and definitions used in this module			*/

static RUNTIME_TYPE  *rt_ptr;	/* current runtime element	*/

static ST_INT  rt_count; 	/* total elements in runtime table	*/
				/* (also index) 			*/
static ST_INT  rt_limit; 	/* max # runtime elements		*/


/* defines used during decode for various types of errors		*/
#define PDU_ERR 		2
#define LENGTH_ERR		3
#define UNSUPPORTED		4
#define UNKNOWN_TYPENAME	5
#define RUNTIME_LIMIT		6

static ST_INT arr_index[ASN1_MAX_LEVEL]; /* index to array element start */
static RUNTIME_TYPE *struct_tracking[ASN1_MAX_LEVEL];

static OBJECT_NAME type_name;	/* temp storage 		*/


/************************************************************************/
/*			ms_asn1_to_runtime				*/
/************************************************************************/

static ST_INT _ms_asn1_to_runtime (ASN1_DEC_CTXT *aCtx,
			   ST_UCHAR *asn1ptr, ST_UINT asn1len,
			   RUNTIME_TYPE *rt_table, ST_INT rt_len)
  {
MMSDEC_INFO dummy_rslt;
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  S_LOCK_COMMON_RESOURCES ();

  _mmsdec_rslt = &dummy_rslt;	/* give _ms_get_mms_objname a place to point */
				/* to					*/
  rt_ptr  = rt_table;		/* initialize the element pointer	*/
  decInfo->rt_start  = rt_table;/* initialize the element pointer	*/
  rt_limit = rt_len;		/* save the limit			*/

  rt_count = 0; 		/* set element count = 0		*/

#if defined(USE_RT_TYPE_2)
  decInfo->comp_name_used = 0;
  decInfo->comp_name_ptr = decInfo->comp_name_buf;
#endif

  aCtx->asn1r_decode_method = ASN1_TAG_METHOD;

  aCtx->asn1r_decode_done_fun = td_done;	/* set up done function 		*/
  aCtx->asn1r_err_fun = td_err;		/* set up error detected fun		*/

  set_type_tags (aCtx);		/* setup the legal tags 		*/

  asn1r_decode_asn1 (aCtx, asn1ptr,asn1len);	/* do message decode and	*/

/* If decode was OK and we are producing a real RT table, need to set	*/
/* the data element sizes.						*/
  if (rt_count && !decInfo->calc_only)
    {
    ms_rt_size_calc (rt_table,rt_count);

/* Also log the runtime type, if selected				*/
    if (mms_debug_sel & MMS_LOG_RT)
      ms_log_runtime (rt_table, rt_count);
    }

  S_UNLOCK_COMMON_RESOURCES ();
  return (rt_count);			/* return # elements used	*/
  }


/************************************************************************/
/*			set_type_tags					*/
/* setup tags for main TypeSpecfication decode				*/
/************************************************************************/

static ST_VOID set_type_tags (ASN1_DEC_CTXT *aCtx)
  {
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,0,get_named_type);
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,1,get_array_el);
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,2,get_struct_el);
  ASN1R_TAG_ADD (aCtx, CTX,3,get_bool_el);
  ASN1R_TAG_ADD (aCtx, CTX,4,get_bitstr_el);
  ASN1R_TAG_ADD (aCtx, CTX,5,get_int_el);
  ASN1R_TAG_ADD (aCtx, CTX,6,get_uint_el);
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,7,get_float_el);
  ASN1R_TAG_ADD (aCtx, CTX,9,get_octstr_el);
  ASN1R_TAG_ADD (aCtx, CTX,10,get_vstr_el);
  ASN1R_TAG_ADD (aCtx, CTX,11,get_gtime_el);
  ASN1R_TAG_ADD (aCtx, CTX,12,get_btime_el);
  ASN1R_TAG_ADD (aCtx, CTX,13,get_bcd_el);
  ASN1R_TAG_ADD (aCtx, CTX,17,get_utc_time_el);
  ASN1R_TAG_ADD (aCtx, CTX,RT_UTF8_STRING,get_utf8_el);
  }

/************************************************************************/
/*			rt_ptr_inc					*/
/* move the rt_ptr to next element and inc count. Checks vs limit.	*/
/************************************************************************/

static ST_VOID rt_ptr_inc (ASN1_DEC_CTXT *aCtx)
  {
  if (++rt_count >= rt_limit)	/* move the runtime pointer		*/
    {
    MLOG_CDEC0 ("decode_done");
    aCtx->asn1r_decode_done = SD_TRUE;
    }
  else
    rt_ptr++;			/* point to next runtime element	*/
  }

/************************************************************************/
/************************************************************************/
/* TypeSpecification element get start functions			*/
/************************************************************************/
/************************************************************************/
/*			get_named_type					*/
/* named type element, check if in database, copy if so.		*/
/************************************************************************/


static ST_VOID get_named_type (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_named_type");

/* execute 'type_name_done' when type name has been extracted    */
  _ms_get_mms_objname (aCtx, &type_name,type_name_done);
  }

/************************************************************************/
/*			type_name_done					*/
/* The type_name objectName has been read, and is now in 'type_name'	*/
/* That means that the type_name constructor now can be complete.	*/
/************************************************************************/

static ST_VOID type_name_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("type_name_done");

  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = type_name_cstr_done;
  }


/************************************************************************/
/*			get_array_el					*/
/* array element, setup to get array parameters.			*/
/************************************************************************/

static ST_VOID get_array_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_array_el");

  if (!decInfo->calc_only)
    rt_ptr->el_tag = RT_ARR_START; 	/* write the tag		*/

  arr_index[aCtx->asn1r_msg_level] = rt_count;	/* save index to this element	*/

  ASN1R_TAG_ADD (aCtx, CTX,0,get_arr_packed);/* set up to get next items	*/
  ASN1R_TAG_ADD (aCtx, CTX,1,get_num_arr_el);
  }

/************************************************************************/
/*			get_struct_el					*/
/* structure element, setup to get struct parameters.			*/
/************************************************************************/

static ST_VOID get_struct_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_struct_el");

  if (++rt_count >= rt_limit)
    {
    MLOG_NERR0 ("ASN.1 to RT Error : RT Table too small");
    asn1r_set_dec_err (aCtx, RUNTIME_LIMIT);
    }
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_STR_START; 	/* write the tag		*/
      struct_tracking[aCtx->asn1r_msg_level] = rt_ptr;
      rt_ptr++;				/* point to next runtime element*/
      }
    }

  ASN1R_TAG_ADD (aCtx, CTX,0,get_str_packed);
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,1,str_comp_seq_start);
  }

/************************************************************************/
/* Simple type get functions						*/
/************************************************************************/
/************************************************************************/
/*			get_bool_el					*/
/* boolean element encountered. 					*/
/************************************************************************/

static ST_VOID get_bool_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_bool_el");

  if (!decInfo->calc_only)
    {
    rt_ptr->el_tag = RT_BOOL;			/* set data type tag		*/
    rt_ptr->u.p.el_len = 1;		/* set max data length		*/
    }
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }

/************************************************************************/
/*			get_bitstr_el					*/
/* bitstring element encountered.					*/
/************************************************************************/

static ST_VOID get_bitstr_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_INT32 size;

  MLOG_CDEC0 ("get_bitstr_el");

  if (asn1r_get_i32 (aCtx, &size))
    asn1r_set_dec_err (aCtx, PDU_ERR);			/* too long		*/
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_BIT_STRING; 	  	/* set data type tag	*/
      rt_ptr->u.p.el_len = (ST_INT) size; 	/* save size		*/
      if (rt_ptr->u.p.el_len != (ST_INT) size)	/* make sure OK cast	*/
        { 
        MLOG_NERR0 ("Bitstring size too big");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);	 /* too long for MMS-EASE	*/
        } 
      } 
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }
/************************************************************************/
/*			get_int_el					*/
/* integer element encountered. 					*/
/************************************************************************/

static ST_VOID get_int_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_UCHAR size;

  MLOG_CDEC0 ("get_int_el");

  if (asn1r_get_u8 (aCtx, &size) || size %8)	/* read integer 		*/
    asn1r_set_dec_err (aCtx, LENGTH_ERR);		/* if too long or not byte size */
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_INTEGER;		/* set data type tag		*/
      rt_ptr->u.p.el_len = 1;   		/* set max data length		*/

      rt_ptr->u.p.el_len = (ST_INT) size/8;	/* looks OK so far		*/

      if ((rt_ptr->u.p.el_len != sizeof (ST_CHAR) &&
	  rt_ptr->u.p.el_len != sizeof (ST_INT16) &&
	  rt_ptr->u.p.el_len != sizeof (ST_INT) && /*** decunix use 1,2,4,8 bytes ***/
#ifdef INT64_SUPPORT
      	  rt_ptr->u.p.el_len != sizeof (ST_INT64) &&
#endif
      	  rt_ptr->u.p.el_len != sizeof (ST_INT32)) ||
          size % 8)
        {
        MLOG_NERR0 ("Integer length not supported");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* not standard size int	*/
        }
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/*			get_uint_el					*/
/* unsigned element encountered.					*/
/************************************************************************/

static ST_VOID get_uint_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_UCHAR size;

  MLOG_CDEC0 ("get_uint_el");

  if (asn1r_get_u8 (aCtx, &size) || size %8)	/* read integer 		*/
    asn1r_set_dec_err (aCtx, LENGTH_ERR);		/* if too long or not byte size */
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_UNSIGNED; 		/* set data type tag		*/
      rt_ptr->u.p.el_len = (ST_INT) size/8;	/* looks OK so far		*/
      if ((rt_ptr->u.p.el_len != sizeof (ST_CHAR) &&
	  rt_ptr->u.p.el_len != sizeof (ST_INT16) &&
	  rt_ptr->u.p.el_len != sizeof (ST_INT) && /*** decunix use 1,2,4,8 bytes ***/
#ifdef INT64_SUPPORT
      	  rt_ptr->u.p.el_len != sizeof (ST_INT64) &&
#endif
      	  rt_ptr->u.p.el_len != sizeof (ST_INT32)) ||
          size % 8)
        {
        MLOG_NERR0 ("Integer length not supported");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);	/* not standard size int	*/
        }
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/************************************************************************/
/*			get_float_el					*/
/* float element encountered.						*/
/************************************************************************/

static ST_UCHAR float_f;
static ST_UCHAR float_e;

static ST_VOID get_float_el (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_float_el");

  ASN1R_TAG_ADD (aCtx, UNI,INT_CODE,get_float_fract);
  }

/************************************************************************/
/*			get_float_fract					*/
/* float element fractional positions (unsigned 8) encountered		*/
/************************************************************************/

static ST_VOID get_float_fract (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_float_fract");

  if (asn1r_get_u8 (aCtx, &float_f))
    asn1r_set_dec_err (aCtx, UNSUPPORTED);
  else
    ASN1R_TAG_ADD (aCtx, UNI,INT_CODE,get_float_exp);
  }

/************************************************************************/
/*			get_float_exp					*/
/* float element fractional positions (unsigned 8) encountered		*/
/************************************************************************/


static ST_VOID get_float_exp (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_float_exp");

  if (asn1r_get_u8 (aCtx, &float_e))
    asn1r_set_dec_err (aCtx, UNSUPPORTED);
  else
    {					/* IEEE 754 Single		*/
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_FLOATING_POINT; /* set data type tag		*/

/* Since DIS & IS differ on the values used to represent floating point	*/
/* types, allow either.							*/

      if ((float_f == SNGL_FRACT || float_f == SNGL_WHOLE) && 
            float_e == SNGL_EXP)
        rt_ptr->u.p.el_len = 4;		/* single precision		*/
      else
        {					 /* IEEE 754 Double		*/
        if ((float_f == DOUBL_FRACT || float_f == DOUBL_WHOLE) && 
            float_e == DOUBL_EXP)
   	  rt_ptr->u.p.el_len = 8; 	  /* double precision		*/
        else
          {
          MLOG_NERR0 ("Float format not supported");
          asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* not standard size int	*/
          }
        }
      }
    }
/* Float element constructor can now be done				*/

  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = float_cstr_done;
  }

/************************************************************************/
/*			float_cstr_done					*/
/* float element cstr done function, allow type decode to continue 	*/
/************************************************************************/

static ST_VOID float_cstr_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("float_cstr_done");
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }


/************************************************************************/
/*			get_octstr_el					*/
/* octet string element encountered.					*/
/************************************************************************/

static ST_VOID get_octstr_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_INT32 size;

  MLOG_CDEC0 ("get_octstr_el");

  if (asn1r_get_i32 (aCtx, &size))
    asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* too long for MMS-EASE	*/
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_OCTET_STRING;		/* set data type tag		*/
      rt_ptr->u.p.el_len = (ST_INT) size;   	/* save precision	*/
      if (rt_ptr->u.p.el_len != (ST_INT) size)	/* make sure OK cast	*/
        {
        MLOG_NERR0 ("Octet string too big");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* too long for MMS-EASE	*/
        }
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/*			get_vstr_el					*/
/* visible string element encountered.					*/
/************************************************************************/

static ST_VOID get_vstr_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_INT32 size;

  MLOG_CDEC0 ("get_vstr_el");

  if (asn1r_get_i32 (aCtx, &size))
    asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* too long for MMS-EASE	*/
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_VISIBLE_STRING;       /* set data type tag   	*/
      rt_ptr->u.p.el_len = (ST_INT) size;   	/* save precision	*/
      if (rt_ptr->u.p.el_len != (ST_INT) size)	/* make sure OK cast	*/
        {
        MLOG_NERR0 ("Vis string too big");
        asn1r_set_dec_err (aCtx, UNSUPPORTED); 	/* too long for MMS-EASE	*/
        }
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/*			get_gtime_el					*/
/* generalized time element encountered.				*/
/************************************************************************/

static ST_VOID get_gtime_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_gtime_el");

  if (!decInfo->calc_only)
    {
    rt_ptr->el_tag = RT_GENERAL_TIME;	/* set data type tag		*/
    rt_ptr->u.p.el_len = 4;		/* gen time precision		*/
    }
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }

/************************************************************************/
/*			get_btime_el					*/
/* binary time element encountered.					*/
/************************************************************************/

static ST_VOID get_btime_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_BOOLEAN dateFlag;

  MLOG_CDEC0 ("get_btime_el");

  if (asn1r_get_bool (aCtx, &dateFlag))		/* get the 4/6 flag		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_BINARY_TIME; 	/* set data type tag		*/
      if (dateFlag) 			/* if date included		*/
        rt_ptr->u.p.el_len = 6;		/* expect 6 bytes		*/
      else				/* no date			*/
        rt_ptr->u.p.el_len = 4;		/* expect 4 bytes		*/
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/*			get_bcd_el					*/
/* bcd element encountered.						*/
/************************************************************************/

static ST_VOID get_bcd_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_UCHAR size;

  MLOG_CDEC0 ("get_bcd_el");

  if (asn1r_get_u8 (aCtx, &size))			/* get the precision		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);		/* too long			*/
  else					/* find # bytes 		*/
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_BCD;		/* set data type tag		*/
      rt_ptr->u.p.el_len = (ST_INT) size;/* save precision		*/
      if (size > 8)
        {
        MLOG_NERR0 ("BCD size too big");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);      	/* too long for MMS-EASE	*/
        } 
      } 
    }
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }

/************************************************************************/
/*			get_utc_time_el					*/
/* UTC Time element encountered.					*/
/************************************************************************/

static ST_VOID get_utc_time_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("get_utc_time_el");

    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_UTC_TIME; 	/* set data type tag		*/
      rt_ptr->u.p.el_len = 8;		/* expect 8 bytes		*/
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }


/************************************************************************/
/*			get_utf8_el					*/
/* Unicode UTF8string element encountered.				*/
/************************************************************************/

static ST_VOID get_utf8_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_INT32 size;

  MLOG_CDEC0 ("get_utf8_el");

  if (asn1r_get_i32 (aCtx, &size))
    asn1r_set_dec_err (aCtx, UNSUPPORTED);	/* too long for MMS-EASE*/
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->el_tag = RT_UTF8_STRING;		/* set data type tag   	*/
      rt_ptr->u.p.el_len = (ST_RTINT) size;	/* save size		*/
      if (rt_ptr->u.p.el_len != size)
        {					/* lost precision in cast*/
        MLOG_NERR0 ("Unicode UTF8 string too long");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);	/* too long for MMS-EASE*/
        }
      }
    rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
    }
  }

/************************************************************************/
/************************************************************************/
/* STRUCTURE COMPONENT DECODE						*/
/************************************************************************/
/* function declarations used in structure parsing			*/

static ST_VOID get_str_comp_seq (ASN1_DEC_CTXT *aCtx);	/* UNI seq - comp		*/
static ST_VOID get_str_comp_name (ASN1_DEC_CTXT *aCtx);	/* CTX 0 comp ID		*/
static ST_VOID get_str_comp_type (ASN1_DEC_CTXT *aCtx);	/* CTX 1 CSTR - typedef		*/
static ST_VOID str_comp_type_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID str_comp_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID str_comp_seq_done (ASN1_DEC_CTXT *aCtx);
static ST_VOID str_done (ASN1_DEC_CTXT *aCtx);		/* main struct cstr done	*/

/************************************************************************/
/*			get_str_packed					*/
/************************************************************************/

static ST_VOID get_str_packed (ASN1_DEC_CTXT *aCtx)
  {
#if !defined(USE_RT_TYPE_2) && !defined(USE_RT_TYPE_3)
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
#endif
ST_UCHAR m_packed;

  MLOG_CDEC0 ("get_str_packed");

  if (asn1r_get_u8 (aCtx, &m_packed)) 	/* get the boolean value		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);	/* too long				*/
  else
    {
#if !defined(USE_RT_TYPE_2) && !defined(USE_RT_TYPE_3)
    if (!decInfo->calc_only)
      rt_ptr->u.str.packd = m_packed;
#endif
    ASN1R_TAG_ADD (aCtx, CTX|CONSTR,1,str_comp_seq_start);
    }
  }

/************************************************************************/
/*			str_comp_seq_start					*/
/* This is a 'seq' component , of the main struct 'seq of'		*/
/* Next is an optional 'packed' or the components sequence		*/
/************************************************************************/

static ST_VOID str_comp_seq_start (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("str_comp_seq_start");

  ASN1R_TAG_ADD (aCtx, UNI|CONSTR,SEQ_CODE,get_str_comp_seq);
  }

/************************************************************************/
/*			get_str_comp_seq				*/
/* This is a 'seq' component , of the main struct 'seq of'		*/
/* Next is an optional 'packed' or the components sequence		*/
/************************************************************************/

static ST_VOID get_str_comp_seq (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_str_comp_seq");

  ASN1R_TAG_ADD (aCtx, CTX,0,get_str_comp_name);
  ASN1R_TAG_ADD (aCtx, CTX|CONSTR,1,get_str_comp_type);
  }


/************************************************************************/
/*			get_str_comp_name				*/
/* structure component name here					*/
/* NOTE: USE_RT_TYPE_2 must be defined or this function will not save	*/
/*       component names (needs rt_ptr->comp_name_ptr).			*/
/************************************************************************/

#if defined(USE_RT_TYPE_3)
static ST_INT _mvl_rt_name_to_index (ST_CHAR *name)
  {
ST_INT i;

  for (i = 0; i < numMvlRtNames; ++i)
    {
    if (!strcmp (mvlRtNames[i], name))
      return (i);
    }
  return (-1);
  }
#endif


static ST_VOID get_str_comp_name (ASN1_DEC_CTXT *aCtx)
  {
ST_CHAR name[MAX_IDENT_LEN+1]; /* for component name element		*/
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
#if defined(USE_RT_TYPE_2)
ST_INT name_len;
#endif

  MLOG_CDEC0 ("get_str_comp_name");

  if (asn1r_get_identifier (aCtx, name))		/* read the identifier		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);		/* too long			*/
  else
    {
#ifdef USE_RT_TYPE_2
    name_len = strlen (name) + 1;	/* make space for NULL		*/
    decInfo->comp_name_used += name_len;/* compute total len BEFORE copy*/
    if (!decInfo->calc_only)
      {
      if (decInfo->comp_name_ptr && 
          decInfo->comp_name_used <= decInfo->comp_name_size)	/* enough space?*/
        {
        strcpy (decInfo->comp_name_ptr, name);
		/*strcpy (rt_ptr->name, name);*/
        rt_ptr->comp_name_ptr = decInfo->comp_name_ptr;	/* Store name ptr*/
        decInfo->comp_name_ptr += name_len;
        }
      else
        {	/* Buffer too small. Should never happen.	*/
        MLOG_ERR0 ("ASN.1 to RT Error : Component name buffer overflow.")
        asn1r_set_dec_err (aCtx, RUNTIME_LIMIT);
        return;
        }
      }
#elif defined(USE_RT_TYPE_3)
    if (!decInfo->calc_only)
      {
      rt_ptr->name_index =  _mvl_rt_name_to_index (name);
      if (rt_ptr->name_index < 0)
        {
        MLOG_ERR0 ("ASN.1 to RT Error : Component name cannot be converted to index.")
        asn1r_set_dec_err (aCtx, UNKNOWN_TYPENAME);
        return;
        }
      }
#else	/* Default	*/
    if (!decInfo->calc_only)
      strcpy (rt_ptr->name, name);
#endif	/* Default	*/

    ASN1R_TAG_ADD (aCtx, CTX|CONSTR,1,get_str_comp_type); /* need to get type next	*/
    }
  }


/************************************************************************/
/*			get_str_comp_type				*/
/* structure component, is a type definition				*/
/* This constructor contains the type_definition element		*/
/************************************************************************/

static ST_VOID get_str_comp_type (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_str_comp_type");

  set_type_tags (aCtx);		/* set up to get the type spec. 	*/
  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = str_comp_type_done;
  }

/************************************************************************/
/*			str_comp_type_done 				*/
/* structure component typedef constructor complete			*/
/* This just means that is is OK for this component to be done.		*/
/************************************************************************/

static ST_VOID str_comp_type_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("str_comp_type_done");

  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = str_comp_done;
  }

/************************************************************************/
/*			str_comp_done					*/
/* structure component constructor complete				*/
/* set up to get the next						*/
/************************************************************************/

static ST_VOID str_comp_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("str_comp_done");

				/* setup to get next struct component	*/
  ASN1R_TAG_ADD (aCtx, UNI|CONSTR,SEQ_CODE,get_str_comp_seq);

/* since a struct comp has been read, OK for this seq to be done	*/
  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = str_comp_seq_done;
  }

/************************************************************************/
/*			str_comp_seq_done				*/
/* structure component seq complete					*/
/* set up to get the next seq, or could be done with this seq		*/
/************************************************************************/

static ST_VOID str_comp_seq_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("str_comp_seq_done");

/* since a struct comp has been read, OK for this seq to be done	*/
  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = str_done;   /* ok for this struct to be done	*/
  }

/************************************************************************/
/*			str_done					*/
/* structure complete							*/
/* set up to get the next element					*/
/************************************************************************/

static ST_VOID str_done (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
RUNTIME_TYPE *start_rt_blk;
ST_INT num_rt;

  MLOG_CDEC0 ("str_done");

  if (!decInfo->calc_only)
    {
    rt_ptr->el_tag = RT_STR_END;	/* write the tag		*/

/* calculate where the corresponding STR_START elment is		*/
    start_rt_blk = struct_tracking[aCtx->asn1r_msg_level+1];

/* Set num_rt, for use in AA processing                                 */
    num_rt = (rt_ptr - start_rt_blk - 1);
   
/* If everything else working correctly, this error should never occur.	*/
    if (num_rt <= 0)
      {
      MLOG_ERR0 ("ASN.1 to RT Error : Structure empty.")
      asn1r_set_dec_err (aCtx, LENGTH_ERR);
      }

    start_rt_blk->u.str.num_rt_blks = num_rt;
    rt_ptr->u.str.num_rt_blks = num_rt;

#if !defined(USE_RT_TYPE_2) && !defined(USE_RT_TYPE_3)
/* copy the packed flag from the start block to the end block 		*/
    rt_ptr->u.str.packd = start_rt_blk->u.str.packd;
#endif
    }
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }


/************************************************************************/
/************************************************************************/
/* ARRAY COMPONENT DECODE						*/
/************************************************************************/
/*			get_arr_packed					*/
/* packed flag received here, just ignore for now			*/
/************************************************************************/

static ST_VOID get_arr_packed (ASN1_DEC_CTXT *aCtx)
  {
#if !defined(USE_RT_TYPE_2) && !defined(USE_RT_TYPE_3)
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
#endif
ST_UCHAR m_packed;

  MLOG_CDEC0 ("get_arr_packed");

  if (asn1r_get_u8 (aCtx, &m_packed))	      /* get the boolean value		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);	      /* too long			*/
  else
    {
#if !defined(USE_RT_TYPE_2) && !defined(USE_RT_TYPE_3)
    if (!decInfo->calc_only)
      rt_ptr->u.arr.packd = m_packed;
#endif   
    ASN1R_TAG_ADD (aCtx, CTX,1,get_num_arr_el);	/* next must be number of elmnts*/
    }
  }

/************************************************************************/
/*			get_num_arr_el					*/
/* number of array elements						*/
/************************************************************************/

static ST_VOID get_num_arr_el (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
ST_UINT32 num;

  MLOG_CDEC0 ("get_num_arr_el");

  if (asn1r_get_u32 (aCtx, &num))		/* get the number of elements		*/
    asn1r_set_dec_err (aCtx, PDU_ERR);	/* too long				*/
  else
    {
    if (!decInfo->calc_only)
      {
      rt_ptr->u.arr.num_elmnts = (ST_INT) num;
      if (rt_ptr->u.arr.num_elmnts != (ST_INT) num) /* verify cast 	*/
        {
        MLOG_NERR0 ("Array size too big");
        asn1r_set_dec_err (aCtx, UNSUPPORTED);		/* too long				*/
        }      
      }      
    ASN1R_TAG_ADD (aCtx, CTX|CONSTR,2,get_arr_el); /* need to get type next	*/

    if (++rt_count >= rt_limit) 	/* check runtime table limit	*/
      {
      MLOG_NERR0 ("ASN.1 to RT Error : RT Table too small");
      asn1r_set_dec_err (aCtx, RUNTIME_LIMIT);
      }
    else
      rt_ptr++; 		/* move rt ptr to next element		*/
    }
  }

/************************************************************************/
/*			get_arr_el					*/
/* structure component, is a type definition				*/
/* This constructor contains the type_definition element		*/
/************************************************************************/

static ST_VOID get_arr_el (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("get_arr_el");

  set_type_tags (aCtx);		/* set up to get the type spec. 	*/
  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = arr_el_cstr_done;
  }

/************************************************************************/
/*			arr_el_cstr_done				*/
/* array element constructor complete					*/
/* This means that the array sequence is complete			*/
/************************************************************************/

static ST_VOID arr_el_cstr_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("arr_el_cstr_done");

  aCtx->asn1r_c_done_fun[aCtx->asn1r_msg_level] = array_done;	/* set done function for array	*/
  }

/************************************************************************/
/*			array_done					*/
/* array constructor complete						*/
/* calculate the # rt blocks is each element, update start/end of array */
/************************************************************************/

static ST_VOID array_done (ASN1_DEC_CTXT *aCtx)
  {
ST_INT num_rt;
RUNTIME_TYPE *start_rt_blk;
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];

  MLOG_CDEC0 ("array_done");

  if (!decInfo->calc_only)
    {
    rt_ptr->el_tag = RT_ARR_END;  	/* write the tag		*/

/* calculate and write rt count for end, start blocks			*/
    start_rt_blk = decInfo->rt_start + arr_index[aCtx->asn1r_msg_level+1];
    num_rt = rt_count - arr_index[aCtx->asn1r_msg_level+1] -1; /* rt_count not inc'd yet*/

    rt_ptr->u.arr.num_rt_blks = num_rt;
    start_rt_blk->u.arr.num_rt_blks = num_rt;

/* copy the element count from the start block to the end block 	*/
    rt_ptr->u.arr.num_elmnts = start_rt_blk->u.arr.num_elmnts;
    }
  rt_ptr_inc (aCtx);			/* move rt ptr, inc count	*/
  }


/************************************************************************/
/************************************************************************/
/* NAMED TYPE								*/
/************************************************************************/
/*			type_name_cstr_done				*/
/* type_name constructor complete					*/
/* need to find in local database, copy the runtime elements		*/
/************************************************************************/

static ST_VOID type_name_cstr_done (ASN1_DEC_CTXT *aCtx)
  {
ASN1_TO_RT_DEC_INFO *decInfo = (ASN1_TO_RT_DEC_INFO *) aCtx->usr_info[0];
RUNTIME_TYPE *sub_rt_head;	/* ptr to first rt in sub-type	*/
ST_INT sub_rt_num;		/* num of rt in sub-type	*/
#if !defined(MMS_LITE)
NAMED_TYPE *tptr;
#endif

#if defined (USE_RT_TYPE_2)
ST_CHAR *name_ptr_save;
ST_INT j;
ST_INT comp_name_len;
#elif defined(USE_RT_TYPE_3)
ST_RTINT name_index_save;
#else
ST_CHAR name_save[MAX_IDENT_LEN+1];
#endif

  MLOG_CDEC0 ("type_name_cstr_done");

#if !defined(MMS_LITE)
  tptr = ms_find_named_type_obj (&type_name,0);
  if (!tptr)
    {
    MLOG_NERR1 ("Named type %s not found", type_name.obj_name.vmd_spec);
    asn1r_set_dec_err (aCtx, UNKNOWN_TYPENAME);
    return;
    }
  sub_rt_num = tptr->rt_num;
  sub_rt_head = tptr->rt_head;
#else
  /* This function finds previously defined types. The default function	*/
  /* should be in the library, but user may replace it with customized funct.*/
  if (u_ml_get_rt_type (aCtx, &type_name, &sub_rt_head, &sub_rt_num) != SD_SUCCESS)
    {
    MLOG_NERR1 ("Named type %s not found", type_name.obj_name.vmd_spec);
    asn1r_set_dec_err (aCtx, UNKNOWN_TYPENAME);
    return;
    }

#endif

/* OK, we have a pointer to the referenced runtime type and the number	*/
/* of elements. We can either insert the referenced table into the 	*/
/* new one, OR we can just add a reference.				*/

  if ((rt_count += sub_rt_num) > rt_limit)
    {
    MLOG_NERR0 ("ASN.1 to RT Error : RT Table too small");
    asn1r_set_dec_err (aCtx, RUNTIME_LIMIT);
    return;
    }
  if (decInfo->calc_only)
    {
#if defined(USE_RT_TYPE_2)	/* make room to copy comp names from sub-type*/
    for (j = 0; j < sub_rt_num; ++j)
      {
      if (sub_rt_head[j].comp_name_ptr)
        decInfo->comp_name_used += (strlen (sub_rt_head[j].comp_name_ptr) + 1);
      }
#endif
    }
  else
    {
#if defined(USE_RT_TYPE_2)
    name_ptr_save = rt_ptr->comp_name_ptr;
#elif defined(USE_RT_TYPE_3)
    name_index_save = rt_ptr->name_index;
#else
    strcpy (name_save, rt_ptr->name);
#endif

    /* Copy array of RUNTIME_TYPE structs.	*/
    memcpy ((ST_CHAR *)rt_ptr,(ST_CHAR *)sub_rt_head, sizeof(RUNTIME_TYPE)*sub_rt_num);

#if defined(USE_RT_TYPE_2)
    /* Copy component names from sub-type into new type.	*/
    /* Must update comp_name_ptr in each rt.			*/
    for (j = 0; j < sub_rt_num; ++j)
      {
      if (sub_rt_head[j].comp_name_ptr)
        {
        /* check for buffer space BEFORE strcpy.	*/
        comp_name_len = (strlen(sub_rt_head[j].comp_name_ptr) + 1);
        decInfo->comp_name_used += comp_name_len;
        if (decInfo->comp_name_used <= decInfo->comp_name_size)	/* enough space?*/
          {
          strcpy (decInfo->comp_name_ptr, sub_rt_head[j].comp_name_ptr);
          rt_ptr[j].comp_name_ptr = decInfo->comp_name_ptr;
          decInfo->comp_name_ptr += comp_name_len;
          }
        else
          {	/* Buffer too small. Should never happen.	*/
          MLOG_ERR0 ("ASN.1 to RT Error : Component name buffer overflow.")
          asn1r_set_dec_err (aCtx, RUNTIME_LIMIT);
          return;
          }
        }
      }
    rt_ptr->comp_name_ptr = name_ptr_save;
#elif defined(USE_RT_TYPE_3)
    rt_ptr->name_index = name_index_save;
#else
    strcpy (rt_ptr->name, name_save);
#endif
    rt_ptr += sub_rt_num;	/* chg global rt_ptr to point after inserted sub-type*/
    }
  }


/************************************************************************/
/************************************************************************/
/* DECODE DONE FUNCTIONS						*/
/************************************************************************/
/*			td_done 					*/
/************************************************************************/


static ST_VOID td_done (ASN1_DEC_CTXT *aCtx)
  {
  MLOG_CDEC0 ("td_done");
  }

/************************************************************************/
/*			td_err						*/
/************************************************************************/

static ST_VOID td_err (ASN1_DEC_CTXT *aCtx, ST_RET err)
  {
  MLOG_CDEC0 ("td_err");

  rt_count = 0; 			/* error, set count = 0 	*/
  mms_op_err = aCtx->asn1r_pdu_dec_err;		/* save error code		*/
  }

/************************************************************************/
/* DATA ALIGNMENT TABLE DEFINITIONS					*/
/************************************************************************/

/* This is the 'packed' data alignment table, which is used to emulate	*/
/* the alignment used by previous versions of the data conversion 	*/
/* functions.								*/

SD_CONST ST_INT m_packed_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0000,	/* INT16_ALGN	05  */
  0x0000,	/* INT32_ALGN	06  */
  0x0000,	/* INT64_ALGN	07  */
  0x0000,	/* FLOAT_ALGN	08  */
  0x0000,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0000,	/* BCD2_ALGN	13  */
  0x0000,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };

#ifdef MMS_LITE
SD_CONST ST_INT *m_data_algn_tbl = m_def_data_algn_tbl;	/* Should never change.	*/
#else	/* !MMS_LITE	*/
/* Should use "m_def_data_algn_tbl" for all systems, but must		*/
/* default to "m_packed_data_algn_tbl" for backward compatiblity with	*/
/* very old MMS-EASE products.						*/
#if !defined(NO_GLB_VAR_INIT)
SD_CONST ST_INT *m_data_algn_tbl = m_packed_data_algn_tbl;
#endif
#endif	/* !MMS_LITE	*/

/* Here is where we create the 'default' alignment tables. These should	*/
/* allow natural access to components.					*/

/* This data alignment table provides word alignment per the following 	*/
/* simple rule :							*/
/*   	Align on the smaller of the size of the data type OR 2 bytes.	*/
/* To do this we set the low bit for every type that is greater than	*/
/* or equal to 2 bytes in size.						*/

#if defined(MSDOS)

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0001,	/* INT32_ALGN	06  */
  0x0001,	/* INT64_ALGN	07  */
  0x0001,	/* FLOAT_ALGN	08  */
  0x0001,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0001,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };
#endif

/* This data alignment table provides word alignment per the following 	*/
/* simple rule :							*/
/*   	Align on the smaller of the size of the data type OR 4 bytes.	*/
/* To do this we set the low bit for every type that is  equal to 2 	*/
/* bytes in size, and the low two bits for  every type that is greater 	*/
/* than	or equal to 4 bytes in size.			     		*/

#if 0

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0003,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0000,	/* BCD2_ALGN	13  */
  0x0001,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#ifdef _AIX

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0003,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#if defined (__hpux)

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0007,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#ifdef __OS2__

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0003,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#ifdef sun

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0007,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#if (defined(__ALPHA) && defined(__VMS))

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0007,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#if defined(__alpha) && !defined(__VMS)

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0007,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#ifdef _WIN32

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,       /* STRSTRT_ALGN 02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0007,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0007,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#ifdef VXWORKS

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0001,	/* INT32_ALGN	06  */
  0x0001,	/* INT64_ALGN	07  */
  0x0001,	/* FLOAT_ALGN	08  */
  0x0001,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0001,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };   
#endif

#if defined (__QNX__)		/* packed	*/

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0000,	/* INT16_ALGN	05  */
  0x0000,	/* INT32_ALGN	06  */
  0x0000,	/* INT64_ALGN	07  */
  0x0000,	/* FLOAT_ALGN	08  */
  0x0000,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0000,	/* BCD2_ALGN	13  */
  0x0000,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };
#endif	/* __QNX__	*/

#if defined(linux)
#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST


SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0003,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0003,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };
#endif	/* linux	*/

#if defined (__LYNX)

#define M_STRSTART_MODE 	M_STRSTART_MODE_LARGEST
#define M_STREND_MODE 		M_STREND_MODE_LARGEST

SD_CONST ST_INT m_def_data_algn_tbl[NUM_ALGN_TYPES] =
  {
  0x0000,	/* ARRSTRT_ALGN	00  */
  0x0000,	/* ARREND_ALGN	01  */
  0x0000,	/* STRSTRT_ALGN	02  */
  0x0000,	/* STREND_ALGN	03  */
  0x0000,	/* INT8_ALGN	04  */
  0x0001,	/* INT16_ALGN	05  */
  0x0003,	/* INT32_ALGN	06  */
  0x0003,	/* INT64_ALGN	07  */
  0x0003,	/* FLOAT_ALGN	08  */
  0x0003,	/* DOUBLE_ALGN	09  */
  0x0000,	/* OCT_ALGN	10  */
  0x0000,	/* BOOL_ALGN	11  */
  0x0000,	/* BCD1_ALGN	12  */
  0x0001,	/* BCD2_ALGN	13  */
  0x0003,	/* BCD4_ALGN	14  */
  0x0000,	/* BIT_ALGN	15  */
  0x0000	/* VIS_ALGN	16  */
  };
#endif	/* __LYNX	*/



/************************************************************************/
/************************************************************************/
/*			ms_rt_size_calc					*/
/************************************************************************/
/*									*/
/* ****** PRIMITIVE elements alignment is well known. 			*/
/*   Element above == primitive  : Add padding to element above.	*/
/*     {								*/
/*     prim yy << pad							*/
/*     prim xx								*/
/*     }								*/
/*   Element above == struct end : Add padding to struct end above.	*/
/*     {								*/
/*     struct yy							*/
/*	 {								*/
/*       ...								*/
/*	 } << pad							*/
/*     prim xx								*/
/*     }								*/
/*   Element above == arr end    : Add padding to array end above.	*/
/*     {								*/
/*     arr yy[zz];							*/
/*	 arr_end << pad							*/
/*     prim xx								*/
/*     }								*/
/*									*/
/* ****** STRUCTURE START elements alignment is derived from elements	*/
/*   Element above == primitive  : Add padding to element above.	*/
/*     {								*/
/*     prim yy 								*/
/*     struct  << pad							*/
/*       {								*/
/*       ...								*/
/*       } xx								*/
/*     }								*/
/*   Element above == struct end : Add padding to struct end above.	*/
/*     {								*/
/*     struct yy							*/
/*	 {								*/
/*       ...								*/
/*	 } 								*/
/*     struct  << pad							*/
/*       {								*/
/*       ...								*/
/*       } xx								*/
/*     }								*/
/*   Element above == arr end    : Add padding to array end above.	*/
/*     {								*/
/*     arr yy[zz];							*/
/*     struct  << pad							*/
/*       {								*/
/*       ...								*/
/*       } xx								*/
/*     }								*/
/*									*/
/* ****** ARRAY START elements alignment is derived from element	*/
/*   Element above == primitive  : Add padding to element above.	*/
/*     {								*/
/*     prim yy << pad							*/
/*     arr xx[zz];							*/
/*     }								*/
/*   Element above == struct end : Add padding to struct end above.	*/
/*     {								*/
/*     struct yy							*/
/*	 {								*/
/*       ...								*/
/*	 } << pad							*/
/*     arr xx[zz];							*/
/*     }								*/
/*   Element above == arr end    : Add padding to array end above.	*/
/*     {								*/
/*     arr yy[zz];							*/
/*	 arr_end << pad							*/
/*     arr xx[zz];							*/
/*     }								*/
/*									*/
/* STRUCTURE SIZE PADDING - struct end					*/
/*   struct								*/
/*     {								*/
/*     xx								*/
/*     yy  << Pad for structure size  					*/
/*     }								*/
/*									*/
/* ARRAYS OF STRUCTURES - array of structure end			*/
/*   struct ss								*/
/*     {								*/
/*     xx								*/
/*     yy  								*/
/*     } << Pad to accomadate ss and xx alignment requirements		*/
/*	[xx];								*/
/*									*/
/*									*/

ST_INT m_struct_start_algn_mode = M_STRSTART_MODE;
ST_INT m_struct_end_algn_mode = M_STREND_MODE;

ST_VOID ms_rt_size_calc (RUNTIME_TYPE *rt_head, ST_INT rt_num)
  {
ST_INT ellen;
RUNTIME_TYPE *arr1_rt; 
RUNTIME_TYPE *rt; 
RUNTIME_TYPE *rt_end; 
RUNTIME_TYPE *rt_pad_dest; 
ST_INT curr_offset;
ST_INT algn;
ST_INT arr_level;
ST_INT arr_start_offset[ASN1_MAX_LEVEL];
ST_INT arr_element_size;

  S_LOCK_COMMON_RESOURCES ();

  rt = rt_head;		  	  /* set runtime ptr			*/
  rt_end = rt_head + rt_num;  	  /* end block				*/

  arr_level = 0;
  curr_offset = 0;		/* Offset from start of data		*/

  rt_pad_dest = NULL;
  while (rt < rt_end)
    {
    if (rt->el_tag == RT_ARR_END)	
      {
      /* Special handling for an array of structures			*/
      /* We need to check if the structure end needs to be padded	*/
      arr1_rt = rt - rt->u.arr.num_rt_blks;
      if (arr1_rt->el_tag == RT_STR_START)
        {
        _get_struct_start_align (arr1_rt, &algn, &ellen);
        _do_padding (rt_pad_dest, &curr_offset, algn);
        }

    /* Now we need to multiply the size of this array element by the	*/
    /* number of elements in the array					*/
      --arr_level;
      arr_element_size = curr_offset - arr_start_offset[arr_level];
      curr_offset += (arr_element_size * (rt->u.arr.num_elmnts-1));
      }

  /* Get the current RT element's alignment requirements and do any	*/
  /* required padding on the element above us.				*/
    _ms_m_get_rt_info (rt, &algn, &ellen);
     _do_padding (rt_pad_dest, &curr_offset, algn);

  /* If we are starting an array, we must remember the start offset	*/
    if (rt->el_tag == RT_ARR_START)
      {
      arr_start_offset[arr_level] = curr_offset;
      ++arr_level;
      }

  /* Set the current element's nominal memory requirements		*/
    rt->el_size = ellen;

  /* Set the offset for the next element				*/
    curr_offset += ellen;

  /* Usually we pad the element directly above us ...			*/
    rt_pad_dest = rt;
    rt++;			
    }

/* We are all done with adjusting padding for our type.			*/
/* Get the offset past the last element, for encoding			*/
  rt_head->offset_to_last = ms_get_blocked_length (rt_head,rt_num);

/* Let the user have a shot at the runtime type if they want to		*/
  if (u_rt_type_process)
    (*u_rt_type_process) (rt_head, rt_num);

  S_UNLOCK_COMMON_RESOURCES ();
  }

/************************************************************************/
/*				_ms_m_get_rt_info			*/
/************************************************************************/
/* WARNING: Recursive routine */

ST_RET _ms_m_get_rt_info (SD_CONST RUNTIME_TYPE *rt, ST_INT *algn_out,
			  ST_INT *ellen_out)
  {
ST_INT algn_index = NUM_ALGN_TYPES;	/* init to ILLEGAL value	*/
ST_INT ellen;

  switch (rt->el_tag)
    {
    case RT_STR_START :			/* structure starting 		*/
      _get_struct_start_align (rt, algn_out, ellen_out);
      return (SD_SUCCESS);
    break;
    
    case RT_STR_END :			/* structure done  		*/
      _get_struct_end_align (rt, algn_out, ellen_out);
      return (SD_SUCCESS);
    break;
    
    case RT_ARR_START :			/* array starting	      	*/
      _get_arr_start_align (rt, algn_out, ellen_out);
      return (SD_SUCCESS);
    break;
    
    case RT_ARR_END :			/* array done		      	*/
      ellen = 0;
      algn_index = ARREND_ALGN;
    break;
    
    case RT_GENERAL_TIME : 		/* generalized time is ST_INT32	*/
      ellen = sizeof(ST_INT32);
      algn_index = INT32_ALGN;
    break;

    case RT_BINARY_TIME :	   /* binary time is one or 2 ST_INT32	*/
      if (rt->u.p.el_len == 6)
        ellen = 2 * sizeof(ST_INT32);
      else
        ellen = sizeof(ST_INT32);
      algn_index = INT32_ALGN;
    break;

    case RT_UTC_TIME :	   	/* UTC Time is 3 ST_UINT32 in struct	*/
      ellen = sizeof (MMS_UTC_TIME);	/* 3 * sizeof(ST_UINT32); 	*/
      algn_index = INT32_ALGN;
    break;

    case RT_INTEGER  :			/* integer			*/
    case RT_UNSIGNED :			/* integer			*/
      ellen = rt->u.p.el_len; 	/* # bytes used			*/
      switch (ellen)
        {
        case 1 :
          algn_index = INT8_ALGN;
        break;
    
        case 2 :
          algn_index = INT16_ALGN;
        break;
    
        case 4 :
          algn_index = INT32_ALGN;
        break;

#ifdef INT64_SUPPORT
        case 8 :
          algn_index = INT64_ALGN;
        break;
#endif
        }
    break;
    
    case RT_FLOATING_POINT : 		/* float			*/
      ellen = rt->u.p.el_len; 	/* # bytes used			*/
      if (ellen == 4)
        algn_index = FLOAT_ALGN;
      else
        algn_index = DOUBLE_ALGN;
    break;
    
    case RT_OCTET_STRING :		/* octet string 		*/
      ellen = abs (rt->u.p.el_len); 	/* max # bytes used    		*/
      if (rt->u.p.el_len < 0)		/* if variable, allow for size	*/
        {
        algn_index = INT16_ALGN;
        ellen += sizeof (ST_INT16);
        }
      else
        algn_index = OCT_ALGN;
    break;
    
    case RT_BOOL :			/* boolean			*/
        ellen = rt->u.p.el_len; 	/* # bytes used			*/
        algn_index = BOOL_ALGN;
    break;
    
    case RT_BCD :			/* bcd				*/
        if (rt->u.p.el_len <= 2)
          {
          ellen = 1;
          algn_index = BCD1_ALGN;
          }
        else if (rt->u.p.el_len <= 4) 
          {
          ellen = 2;
          algn_index = BCD2_ALGN;
          }
        else 
          {
          ellen = 4;
          algn_index = BCD4_ALGN;
          }
    break;
    
    case RT_BIT_STRING :  		/* bit string			*/
      ellen = abs (rt->u.p.el_len)/8; 	/* # bytes used			*/
      if (rt->u.p.el_len % 8)	 	/* if not a multiple of 8	*/
        ellen++;			/* add one to take spare bits	*/

      if (rt->u.p.el_len < 0)		/* if variable, allow for size	*/
        {
        algn_index = INT16_ALGN;
        ellen += sizeof (ST_INT16);
        }
      else
        algn_index = BIT_ALGN;
    break;
    
    case RT_VISIBLE_STRING : 		/* visible string		*/
      ellen = abs (rt->u.p.el_len) + 1;	/* # bytes used			*/
      algn_index = VIS_ALGN;
    break;

    case RT_UTF8_STRING : 		/* Unicode UTF8 string		*/
#if (UNICODE_LOCAL_FORMAT==UNICODE_UTF8)
      ellen = abs(rt->u.p.el_len)*4 + 1;/* # bytes (4 bytes per char + NULL)*/
      algn_index = VIS_ALGN;		/* Same alignment as visible string*/
#else		/* assume UNICODE_UTF16	*/
      ellen = abs(rt->u.p.el_len)*2 + 2;/* # bytes (2 bytes per char + 2 byte NULL)*/
      algn_index = INT16_ALGN;
#endif
    break;

    default :				/* should not be any other tag	*/
      MLOG_NERR0 ("Bad el_tag in RT");
      return (SD_FAILURE);
    break;
    }

  if (algn_index == NUM_ALGN_TYPES)	/* ILLEGAL value	*/
    {
    MLOG_ERR0 ("algn_index never set");	/* THIS SHOULD NEVER HAPPEN	*/
    return (SD_FAILURE);
    }

  *algn_out = m_data_algn_tbl[algn_index];
  *ellen_out = ellen;
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			_get_struct_start_align				*/
/************************************************************************/
/* WARNING: Recursive routine */

static ST_VOID _get_struct_start_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out)
  {
ST_INT i;
ST_INT curr_algn;
ST_INT algn;
ST_INT ellen;
ST_INT num_rt;

  algn = m_data_algn_tbl[STRSTRT_ALGN];
  num_rt = rt->u.str.num_rt_blks;
  ++rt;		/* Point to first structure member */
  if (m_struct_start_algn_mode == M_STRSTART_MODE_LARGEST)
    {
    for (i = 0; i < num_rt; ++i, ++rt)
      {
      _ms_m_get_rt_info (rt, &curr_algn, &ellen);
      if (curr_algn > algn)
        algn = curr_algn;
      }
    }
  else if (m_struct_start_algn_mode == M_STRSTART_MODE_FIRST)
    _ms_m_get_rt_info (rt, &algn, &ellen);

  *algn_out = algn;
  *ellen_out = 0;
  }

/************************************************************************/
/*				_get_struct_end_align			*/
/************************************************************************/
/* WARNING: Recursive routine */

static ST_VOID _get_struct_end_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out)
  {
ST_INT i;
ST_INT algn;
ST_INT curr_algn;
ST_INT ellen;
ST_INT num_rt;

  num_rt = rt->u.str.num_rt_blks; 
  rt -= rt->u.str.num_rt_blks; 
  algn = m_data_algn_tbl[STREND_ALGN];
  if (m_struct_end_algn_mode == M_STREND_MODE_LARGEST)
    {
    for (i = 0; i < num_rt; ++i, ++rt)
      {
      _ms_m_get_rt_info (rt, &curr_algn, &ellen);
      if (curr_algn > algn)
        algn = curr_algn;
      }
    }

  *algn_out = algn;
  *ellen_out = 0;
  }

/************************************************************************/
/*			_get_arr_start_align				*/
/************************************************************************/
/* WARNING: Recursive routine */

static ST_VOID _get_arr_start_align (SD_CONST RUNTIME_TYPE *rt, 
				 ST_INT *algn_out,
				 ST_INT *ellen_out)
  {
ST_INT i;
ST_INT algn;
ST_INT ellen;
ST_INT num_rt;

  algn = m_data_algn_tbl[ARRSTRT_ALGN];
  num_rt = rt->u.arr.num_rt_blks;
  ++rt;
  for (i = 0; i < num_rt; ++i, ++rt)
    {
    if (rt->el_tag != RT_ARR_START)
      {
      _ms_m_get_rt_info (rt, &algn, &ellen);
      break;
      }
    }
  *algn_out = algn;
  *ellen_out = 0;
  }

/************************************************************************/
/*				_do_padding				*/
/************************************************************************/

static ST_VOID _do_padding (RUNTIME_TYPE *padDest, 
			    ST_INT *curr_offset, 
			    ST_INT algn)
  {
ST_INT pad;

/*Increment the offset until no bits are set that shouldn't be	*/
  pad = 0;
  while ((*curr_offset) & algn)
    {
    (*curr_offset)++;
    pad++;
    }
  
  /* If pad bytes are needed, add to the end struct element */
  if (pad)
    {
    if (!padDest)
      {
      MLOG_ERR0 ("Alignment table error");
      }
    else
      padDest->el_size += pad;
    }
  }


/************************************************************************/
/************************************************************************/
/************************************************************************/
/*			ms_get_blocked_len 				*/
/* Function to return the size of buffer required for blocked data for	*/
/* the data type selected. This is used when type definitions come over */
/* the wire, and in general, when a type is created.			*/
/************************************************************************/

#ifndef MMS_LITE

ST_INT ms_get_blocked_len (NAMED_TYPE *tptr)
  {
  return (ms_get_blocked_length (tptr->rt_head,tptr->rt_num));
  }

#endif

/************************************************************************/
/*			ms_get_blocked_length 				*/
/************************************************************************/

ST_INT ms_get_blocked_length (SD_CONST RUNTIME_TYPE *rt_head, ST_INT rt_num)
  {
ST_INT total_size;
SD_CONST RUNTIME_TYPE *rt;	/* current runtime element	*/
SD_CONST RUNTIME_TYPE *rt_end;
ST_INT arr_loop_buf[ASN1_MAX_LEVEL];
ST_INT arr_loop_level;
ST_INT *arr_loops;

  S_LOCK_COMMON_RESOURCES ();
  arr_loop_level = 0;
  arr_loops = arr_loop_buf;

  rt = rt_head;		  /* set runtime ptr		*/
  rt_end = rt_head + rt_num;  	  /* end block			*/
  total_size = 0;

  while (rt < rt_end)
    {
    if (rt->el_tag == RT_ARR_START)	/* Set up array looping		*/
      {
      ++arr_loop_level;
      arr_loops[arr_loop_level] = rt->u.arr.num_elmnts;
      }

    if (rt->el_tag == RT_ARR_END)	/* treat case of array ending	*/
      {
      if (--arr_loops[arr_loop_level] > 0) /* if need to do next ar elmnt	*/
        {
        rt -= rt->u.arr.num_rt_blks; /* mv rt to start of arr	*/
        continue; 
        }
      --arr_loop_level;
      }

    total_size += rt->el_size;
    rt++;			/* point to next runtime element*/
    }
    
  S_UNLOCK_COMMON_RESOURCES ();
  return (total_size);
  }


/************************************************************************/
/*			 ms_log_runtime 				*/
/************************************************************************/
/* list the elements in a runtime type def table			*/


#define MAX_INDENT 5

ST_VOID ms_log_runtime (SD_CONST RUNTIME_TYPE *rt, ST_INT num_rt)
  {
  _ms_log_runtime (0, rt, num_rt);
  }


static ST_VOID _ms_log_runtime (ST_INT indent, SD_CONST RUNTIME_TYPE *rt, ST_INT num_rt)
  {
#if defined(DEBUG_SISCO)

ST_INT i;
ST_CHAR *comp_name;
ST_CHAR *sp[MAX_INDENT] =
  {
  "  ",
  "    ",
  "      ",
  "        ",
  "          ",
  };
ST_CHAR *sp2[MAX_INDENT] =
  {
  "        ",
  "      ",
  "    ",
  "  ",
  "",
  };

  S_LOCK_COMMON_RESOURCES ();

  if (num_rt == 0)
    {
    MLOG_ALWAYS0 ("Runtime Type : 0 elements");
    }
  else if (indent == 0)
    {
    MLOG_ALWAYS2 ("Runtime Type : %d elements,  Offset past last : %d",
				num_rt, rt->offset_to_last);
    }

  for (i = 0; i < num_rt; ++i, rt++)
    {
    comp_name = (ST_CHAR *)ms_comp_name_find (rt);	/* cast to remove const*/
    if (strlen (comp_name))
      {
      MLOG_CALWAYS3 ("%sNamed comp  %s: %s", 
    				sp[indent], 
                                sp2[indent],
    				comp_name);
      }

    switch (rt->el_tag)
      {
      case RT_ARR_START :
	MLOG_CALWAYS5 ("%sArray start %s: size %02d, %02d elmnts, %02d rt", 
                                       sp[indent],
                                       sp2[indent],
                                       rt->el_size,
                                       rt->u.arr.num_elmnts,
                                       rt->u.arr.num_rt_blks);
        if (++indent >= MAX_INDENT)
          indent--;
      break;

      case RT_ARR_END :
        if (--indent < 0)
          indent++;
	MLOG_CALWAYS5 ("%sArray end   %s: size %02d, %02d elmnts, %02d rt", 
                                       sp[indent],
                                       sp2[indent],
                                       rt->el_size,
                                       rt->u.arr.num_elmnts,
                                       rt->u.arr.num_rt_blks);
      break;

      case RT_STR_START :
	MLOG_CALWAYS4 ("%sStruct start%s: size %02d, %02d rt", 
				       	sp[indent],
                                       	sp2[indent],
					rt->el_size,
                                        rt->u.str.num_rt_blks);
        if (++indent >= MAX_INDENT)
          indent--;
      break;

      case RT_STR_END :
        if (--indent < 0)
          indent++;
	MLOG_CALWAYS3 ("%sStruct end  %s: size %02d", 
				       	sp[indent],
                                       	sp2[indent],
					rt->el_size);
      break;

      case RT_BOOL :
	MLOG_CALWAYS4 ("%sBoolean     %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_BIT_STRING :
	MLOG_CALWAYS4 ("%sBitstring   %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_INTEGER : 
	MLOG_CALWAYS4 ("%sInteger     %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_UNSIGNED : 
	MLOG_CALWAYS4 ("%sUnsigned    %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_FLOATING_POINT :
	MLOG_CALWAYS4 ("%sFloat       %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_OCTET_STRING :
	MLOG_CALWAYS4  ("%sOctet Str  %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_VISIBLE_STRING :
	MLOG_CALWAYS4 ("%sVisible Str %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_GENERAL_TIME :
	MLOG_CALWAYS4 ("%sGen Time    %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_BINARY_TIME :
	MLOG_CALWAYS4 ("%sBin Time    %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_BCD :
	MLOG_CALWAYS4 ("%sBCD         %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_UTC_TIME :
	MLOG_CALWAYS4 ("%sUTC Time    %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      case RT_UTF8_STRING :
	MLOG_CALWAYS4 ("%sUTF8string  %s: size %02d, precision %02d",
                                   sp[indent],
                                   sp2[indent],
                                   rt->el_size,
                                   rt->u.p.el_len); 
      break;

      default : 			/* should not be any other tag	*/
	MLOG_CALWAYS1 (" **** UNKNOWN ELEMENT %02d ",i);
      break;
      }
    }

  S_UNLOCK_COMMON_RESOURCES ();

#endif
  }

/************************************************************************/
/*			ms_runtime_create				*/
/* This function parses an ASN.1 type definition, and creates a Runtime	*/
/* Type Table from it. It allocates memory for the table and fills it in.*/
/* The table should be destroyed by calling "ms_runtime_destroy".	*/
/************************************************************************/
RUNTIME_CTRL *ms_runtime_create (ST_UCHAR *asn1_data,
			ST_UINT asn1_len,
			ST_INT max_num_rt)
  {
RUNTIME_CTRL *rt_ctrl = NULL;	/* assume failure	*/
ST_INT num_rt;		/* num entries in RUNTIME_TYPE array	*/
ASN1_DEC_CTXT aCtx;	/* Main decode struct	*/
ASN1_TO_RT_DEC_INFO decInfo;	/* temporary storage for extra decode info.	*/
ST_UCHAR *asn1_tmp;		/* temporary copy of asn1_data.		*/

  /* First decode only to compute "num_rt" (RUNTIME_TYPE array NOT alloc'd)*/
  memset (&aCtx, 0, sizeof (ASN1_DEC_CTXT));	/* CRITICAL: start clean.*/
  aCtx.usr_info[0] = &decInfo;	/* save ptr to decInfo in context.	*/

  /* set global variables to parse the type for size  */
  decInfo.calc_only = SD_TRUE;		/* flag to calculate num rt blocks*/

  /* If USE_COMPACT_MMS_STRUCTS defined & ObjectNames included in ASN.1,*/
  /* (maybe other cases) the ASN1 buffer gets corrupted by decode.	*/
  /* Copy to tmp buffer & use tmp buffer on 1st decode.			*/
  asn1_tmp = (ST_UCHAR *) chk_calloc (1, asn1_len);
  memcpy (asn1_tmp, asn1_data, asn1_len);
  num_rt = _ms_asn1_to_runtime (&aCtx, asn1_tmp, asn1_len, NULL, max_num_rt);
  chk_free (asn1_tmp);		/* done with temporary copy	*/

  /* Second decode to alloc & init array of RUNTIME_TYPE structs.	*/
  if (num_rt)
    {
    memset (&aCtx, 0, sizeof (ASN1_DEC_CTXT));	/* CRITICAL: start clean.*/
    aCtx.usr_info[0] = &decInfo;	/* save ptr to decInfo in context.*/
    /* Allocate RUNTIME_CTRL struct plus array of RUNTIME_TYPE structs.	*/
    rt_ctrl = chk_calloc (1, sizeof (RUNTIME_CTRL) + num_rt * sizeof (RUNTIME_TYPE));
    rt_ctrl->rt_first = (RUNTIME_TYPE *)(rt_ctrl + 1);

    /* parse the type encoding a second time to get an RT TYPE */
    decInfo.calc_only = SD_FALSE;
#if defined(USE_RT_TYPE_2)
    decInfo.comp_name_size = decInfo.comp_name_used;	/* Save running count.*/
    if (decInfo.comp_name_size)
      decInfo.comp_name_buf = chk_calloc (1, decInfo.comp_name_size);
    else
      decInfo.comp_name_buf = NULL;	/* There is no buffer.	*/
#endif	/* USE_RT_TYPE_2	*/
    rt_ctrl->rt_num = _ms_asn1_to_runtime (&aCtx, asn1_data, asn1_len, rt_ctrl->rt_first, num_rt);
    if (rt_ctrl->rt_num == 0)
      {	/* 2nd decode failed. Should almost NEVER happen. Cleanup.	*/
#if defined(USE_RT_TYPE_2)
      if (decInfo.comp_name_buf)
        chk_free (decInfo.comp_name_buf);
#endif
      chk_free (rt_ctrl);
      rt_ctrl = NULL;
      }
    }
  /* rt_first & rt_num should now be set in rt_ctrl	*/
  return (rt_ctrl);
  }

/************************************************************************/
/*			ms_runtime_destroy				*/
/* This function frees up all the memory for a Runtime Type Table	*/
/* created by "ms_runtime_create".					*/
/* It should not be called until all references to the Rumtime Type	*/
/* (i.e. Variable associations, etc.) have been destroyed.		*/ 
/************************************************************************/
ST_VOID ms_runtime_destroy (RUNTIME_CTRL *rt_ctrl)
  {
#if defined(USE_RT_TYPE_2)
RUNTIME_TYPE *rt_table = rt_ctrl->rt_first;
ST_INT j;
  /* Component names only saved if USE_RT_TYPE_2 defined. Must free them.*/
  /* Find the first non-NULL comp_name_ptr. This should be the pointer	*/
  /* to the buffer allocated for "component names". Free the buffer.	*/
  for (j=0; j < rt_ctrl->rt_num; j++)
    {
    if (rt_table[j].comp_name_ptr != 0)
      {
      chk_free (rt_table[j].comp_name_ptr);	/* Free the buffer of names*/
      break;
      }
    }
#endif	/* USE_RT_TYPE_2	*/

  /* Free the table.	*/
  chk_free (rt_ctrl);
  }

/************************************************************************/
/*			ms_is_rt_prim					*/
/************************************************************************/
ST_BOOLEAN ms_is_rt_prim (RUNTIME_TYPE *rt)
  {
  switch (rt->el_tag)
    {
    case RT_BOOL : 
    case RT_BIT_STRING : 
    case RT_INTEGER :
    case RT_UNSIGNED :
    case RT_FLOATING_POINT :
    case RT_OCTET_STRING : 
    case RT_VISIBLE_STRING :
    case RT_GENERAL_TIME : 
    case RT_BINARY_TIME : 
    case RT_BCD : 
    case RT_BOOLEANARRAY : 
    case RT_UTC_TIME : 
    case RT_UTF8_STRING : 
      return (SD_TRUE);
    break;
    }
  return (SD_FALSE);
  }

/************************************************************************/
/*			ms_asn1_to_runtime_x				*/
/* For backward compatibility only. Does NOT work with USE_RT_TYPE_2.	*/
/* New programs should use ms_runtime_create.				*/
/************************************************************************/

#if !defined(MMS_LITE)
ST_INT ms_asn1_to_runtime_x (ST_UCHAR *asn1_data, ST_UINT asn1_len,
   		            RUNTIME_TYPE *rt_table, ST_INT rt_len, 
   		            ST_BOOLEAN calc_only)
  {
ST_INT rt_num;		/* num entries in RUNTIME_TYPE array	*/
ASN1_DEC_CTXT aCtx;	/* Main decode struct	*/
ASN1_TO_RT_DEC_INFO decInfo;	/* temporary storage for extra decode info.	*/

  memset (&aCtx, 0, sizeof (ASN1_DEC_CTXT));	/* CRITICAL: start clean.*/
  aCtx.usr_info[0] = &decInfo;	/* save ptr to decInfo in context.*/
  decInfo.calc_only = calc_only;

  rt_num = _ms_asn1_to_runtime (&aCtx, asn1_data, asn1_len, rt_table, rt_len);

  /* rt_first & rt_num should now be set in rt_ctrl	*/
  return (rt_num);
  }

#endif	/* !MMS_LITE	*/
