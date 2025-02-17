/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	2003 - 2003, All Rights Reserved.				*/
/*									*/
/*		PROPRIETARY AND CONFIDENTIAL				*/
/*									*/
/* MODULE NAME : ms_tdef4.c						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/* Function called by "ms_runtime_create" to find base types when	*/
/* building complex types.						*/
/* NOTE: This module should be included in a library & should contain	*/
/*	ONLY "u_ml_get_rt_type", so that the user can easily replace	*/
/* 	this function with a customized function.			*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*			u_ml_get_rt_type				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 04/24/03  JRB     01    New module.					*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"
#include "mms_vvar.h"
#include "mvl_defs.h"

/************************************************************************/
/*			u_ml_get_rt_type				*/
/* Called by "ms_runtime_create" to find base types (INT32S, etc.).	*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_RET u_ml_get_rt_type (ASN1_DEC_CTXT *aCtx, OBJECT_NAME *type_name,
			RUNTIME_TYPE **rt_out, ST_INT *num_rt_out, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_RET u_ml_get_rt_type (ASN1_DEC_CTXT *aCtx, OBJECT_NAME *type_name,
			RUNTIME_TYPE **rt_out, ST_INT *num_rt_out)
#endif
  {
ST_INT type_id;
ST_RET rc;

  type_id = mvl_typename_to_typeid (type_name->obj_name.vmd_spec);
  /* mvl_get_runtime chks type_id, so no need to check it here.		*/
#ifdef _MVL_TYPE_CTRL_use_one_device_
  rc = mvl_get_runtime (type_id, rt_out, num_rt_out, mvl_type_ctrl);
#else
  rc = mvl_get_runtime (type_id, rt_out, num_rt_out);
#endif

  return (rc);
  }

