/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	2000 - 2000, All Rights Reserved				*/
/*									*/
/* MODULE NAME : mvl_typ2.c						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	Dynamic type creation/destruction functions.			*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	mvl_type_id_create						*/
/*	mvl_type_id_destroy						*/
/*	mvl_type_id_create_from_tdl					*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev     Comments					*/
/* --------  ---  ------   -------------------------------------------	*/
/* 06/29/04  JRB     06    Add mvl_type_id_create_from_tdl.		*/
/* 09/18/03  JRB     05    mvl_type_id_create: Allow type_name==NULL.	*/
/* 03/13/03  JRB     04    Use static funcs mvl_type_id_create2/destroy2.*/
/*			   In create2, make sure name not already used.	*/
/*			   Call mvlu_proc_rt_type for UCA types.	*/
/*			   MVL_TYPE_CTRL: type_name is now array, copy to it*/
/* 11/11/02  JRB     03    Use NEW ms_runtime_create/destroy (new args).*/
/* 09/05/00  JRB     02    Use mvl_get_runtime_dyn to find runtime type.*/
/* 09/05/00  JRB     01    Created. Moved code here from "mvl_type.c".	*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"

#include "mmsdefs.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mvl_defs.h"
#include "mvl_log.h"
#include "mvl_uca.h"	/* need mvlu_proc_rt_type proto	*/


/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/* Static function prototypes.						*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
static ST_INT mvl_type_id_create2 (ST_CHAR *type_name, RUNTIME_CTRL *rt_ctrl, MVL_TYPE_CTRL *mvl_type_ctrl);
#else
static ST_INT mvl_type_id_create2 (ST_CHAR *type_name, RUNTIME_CTRL *rt_ctrl);
#endif

#ifdef _MVL_TYPE_CTRL_use_one_device_
static RUNTIME_CTRL *mvl_type_id_destroy2 (ST_INT typeId, MVL_TYPE_CTRL *mvl_type_ctrl);
#else
static RUNTIME_CTRL *mvl_type_id_destroy2 (ST_INT typeId);
#endif


/************************************************************************/
/*			mvl_type_id_create				*/
/* RETURNS:								*/
/*	Type Id (or -1 on error)					*/
/* NOTE: Use "mvl_type_id_destroy" to destroy this object.		*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_INT mvl_type_id_create (ST_CHAR *type_name, ST_UCHAR *asn1_data, ST_UINT asn1_len, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_INT mvl_type_id_create (ST_CHAR *type_name, ST_UCHAR *asn1_data, ST_UINT asn1_len)
#endif
{
	RUNTIME_CTRL *rt_ctrl;
	ST_INT TypeId = -1;	/* assume failure	*/

	rt_ctrl = ms_runtime_create (asn1_data, asn1_len,
		(UINT_MAX/sizeof(RUNTIME_TYPE))-100);
	if (rt_ctrl)
	{			/* "runtime create" successful, do "step 2".	*/
#ifdef _MVL_TYPE_CTRL_use_one_device_
		TypeId = mvl_type_id_create2 (type_name, rt_ctrl, mvl_type_ctrl);
#else
		TypeId = mvl_type_id_create2 (type_name, rt_ctrl);
#endif

		if (TypeId < 0)	/* "step 2" failed, so destroy runtime just created.*/
			ms_runtime_destroy (rt_ctrl);
	}
	return (TypeId);
}

/************************************************************************/
/*			mvl_type_id_destroy				*/
/* Destroy object created by "mvl_type_id_create".			*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_VOID mvl_type_id_destroy (ST_INT TypeId, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_VOID mvl_type_id_destroy (ST_INT TypeId)
#endif
{
	RUNTIME_CTRL *rt_ctrl;
#ifdef _MVL_TYPE_CTRL_use_one_device_
	rt_ctrl = mvl_type_id_destroy2 (TypeId, mvl_type_ctrl);	/* remove it from list	*/
#else
	rt_ctrl = mvl_type_id_destroy2 (TypeId);	/* remove it from list	*/
#endif

	if (rt_ctrl)
		ms_runtime_destroy (rt_ctrl);	/* destroy it	*/
	else
		MVL_LOG_ERR1 ("mvl_type_id_destroy error: TypeId %d not dynamically created", TypeId);
}

/************************************************************************/
/*			mvl_type_id_create2				*/
/* Second step of creating type_id.					*/
/* RETURNS:								*/
/*	Type Id (or -1 on error)					*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
static ST_INT mvl_type_id_create2 (ST_CHAR *type_name, RUNTIME_CTRL *rt_ctrl, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
static ST_INT mvl_type_id_create2 (ST_CHAR *type_name, RUNTIME_CTRL *rt_ctrl)
#endif
{
	ST_INT typeId;
	MVL_TYPE_CTRL *type_ctrl;	/* ptr to current array element	*/

	/* This assertion fails if the global array mvl_type_ctrl is not initialized
	* To avoid this, create dynamic types ONLY AFTER "mvl_init_type_ctrl"
	* (in Foundry output "c" file) is called.
	*/
	assert (mvl_type_ctrl);	/* make sure type control initialized	*/

	/* If named, make sure name not too long & name not already used.	*/
	if (type_name!=NULL)
	{
		if (strlen (type_name) >= sizeof (type_ctrl->type_name))
			return (-1);	/* type_name exceeds max allowed size	*/

		for (typeId = 0; typeId < mvl_num_types; ++typeId)
		{
			type_ctrl = &mvl_type_ctrl[typeId];	/* ptr to array elem*/
			if (type_ctrl->num_rt!=0  &&  type_ctrl->type_name!=NULL
				&&  strcmp (type_ctrl->type_name, type_name) == 0)
			{
				MVL_LOG_ERR1 ("Type creation error: name '%s' already in use", type_name);
				return (-1);	/* FAILED: name in use		*/
			}
		}
	}

#if defined (MVL_UCA)	/* do post-processing for UCA types.	*/
	if (mvlu_proc_rt_type (type_name, rt_ctrl, NULL))
		return (-1);	/* FAILED: return invalid typeId		*/
#endif	/* MVL_UCA	*/

	/* Just search for a unused slot */
	for (typeId = mvl_num_types - _mvlu_num_dyn_types; typeId < mvl_num_types; ++typeId)
	{
		type_ctrl = &mvl_type_ctrl[typeId];	/* ptr to array elem*/
		if (type_ctrl->num_rt == 0)
		{
			if (type_name)
				strcpy (type_ctrl->type_name, type_name);	/* size checked above	*/
			else
				type_ctrl->type_name[0] = '\0';			/* unnamed type		*/
			type_ctrl->rt_ctrl = rt_ctrl;	/* no other func sets this*/
			type_ctrl->rt = rt_ctrl->rt_first;
			type_ctrl->num_rt = rt_ctrl->rt_num;
			type_ctrl->data_size = rt_ctrl->rt_first->offset_to_last;
			return (typeId);
		}
	}
	MVL_LOG_ERR0 ("mvl_type_id_create error: type array full");
	return (-1);	/* error, no slots available. Return invalid typeId.	*/
}

/************************************************************************/
/*			mvl_type_id_destroy2				*/
/* Second step of destroying type_id.					*/
/* Remove type from array, return pointer to it.			*/
/* NOTE: uses mvl_type_ctrl_find_dyn to make sure it's "dynamic" type.	*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
static RUNTIME_CTRL *mvl_type_id_destroy2 (ST_INT typeId, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
static RUNTIME_CTRL *mvl_type_id_destroy2 (ST_INT typeId)
#endif
{
	MVL_TYPE_CTRL *type_ctrl;
	RUNTIME_CTRL *rt_ctrl = NULL;	/* assume failure	*/

#ifdef _MVL_TYPE_CTRL_use_one_device_
	type_ctrl = mvl_type_ctrl_find_dyn (typeId, mvl_type_ctrl);
#else
	type_ctrl = mvl_type_ctrl_find_dyn (typeId);
#endif

	if (type_ctrl)
	{		/* save ptr to type, then remove it from array	*/
		rt_ctrl = type_ctrl->rt_ctrl;
		type_ctrl->num_rt = 0;		/* indicates unused array entry	*/
		type_ctrl->rt_ctrl = NULL;		/* don't leave old ptr here	*/
	}
	return (rt_ctrl);
}

/************************************************************************/
/*			mvl_type_id_create_from_tdl			*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
ST_INT mvl_type_id_create_from_tdl (ST_CHAR *type_name, ST_CHAR *tdl, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
ST_INT mvl_type_id_create_from_tdl (ST_CHAR *type_name, ST_CHAR *tdl)
#endif
{
	ST_UCHAR *asn1_buf;	/* tmp ASN.1 buffer. Alloc & free here.	*/
	ST_INT asn1_len;
	ST_INT type_id;
	RUNTIME_CTRL *rt_ctrl;

	/* Allocate minimum of 2000 bytes, more for long TDL.			*/
	/* NOTE: may want to increase mininum to reduce memory fragmentation.	*/
	asn1_len = max (2000, (2 * strlen (tdl)));	/* initial len. Changed by ms_mk_asn1_type*/
	asn1_buf = chk_malloc (asn1_len);

	if ((rt_ctrl = ms_tdl_to_runtime (tdl, asn1_buf, asn1_len)) == NULL)
	{
		MVL_LOG_ERR0 ("ms_tdl_to_runtime error");
		type_id = -1;	/* error	*/
	}
	else
	{
		/* Create MVL type_id. This function also performs post-processing	*/
		/* on "rt_ctrl".							*/
#ifdef _MVL_TYPE_CTRL_use_one_device_
		type_id = mvl_type_id_create2 (type_name, rt_ctrl, mvl_type_ctrl);
#else
		type_id = mvl_type_id_create2 (type_name, rt_ctrl);
#endif
	}

	if (type_id < 0)
		MVL_LOG_ERR2 ("mvl_type_id_create_from_tdl: type creation failed for '%s', TDL=%s.", type_name, tdl);

	chk_free (asn1_buf);
	return (type_id);
}
