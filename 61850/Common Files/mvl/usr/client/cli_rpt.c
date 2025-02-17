/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	2003 - 2004, All Rights Reserved				*/
/*									*/
/* MODULE NAME : cli_rpt.c						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	Functions to perform "client" processing of IEC-61850 Reports	*/
/*	and UCA Reports received from "servers".			*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	rpt_typeids_find						*/
/*	rcb_info_create							*/
/*	rcb_info_destroy						*/
/*	u_iec_rpt_ind							*/
/*	u_iec_rpt_ind_data (user modify or replace)			*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 08/04/04  EJV     06    rcb_info_create: added typecast for Inclusion*/
/* 06/29/04  JRB     05    Del mvl_tdl_to_type_id & instead use new	*/
/*			   mvl_type_id_create_from_tdl.			*/
/* 05/13/04  JRB     04    Chg SqNum to INT16U to match 61850-7-2.	*/
/* 01/23/04  JRB     03    Use ms_local_to_text.			*/
/* 12/17/03  JRB     02    61850-8-1 FDIS changes:			*/
/*			   Decode ConfRev in rpt if enabled by OptFlds.	*/
/*			   Move SubSeqNum, MoreSegmentsFollow to just	*/
/*			   before inclusion bitstring.			*/
/*			   Chg OptFlds from bvstring9 to bvstring10.	*/
/* 10/24/03  JRB     01    New						*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mvl_acse.h"
#include "mvl_log.h"
#include "mvl_uca.h"	/* only need OPTFLD_* defines	*/

#include "client.h"
#include "RptDeCode.h"

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

RCB_INFO *rcb_info = NULL;
extern ST_INT g_nStopProtocolParseFlag;

/************************************************************************/
/* Global variables.													*/
/************************************************************************/
/* NONE	*/

/************************************************************************/
/* Static function prototypes.											*/
/************************************************************************/
static OBJECT_NAME **nvl_var_name_array_create (MVL_NET_INFO *net_info, ST_CHAR *domName,
		ST_CHAR *nvlName, ST_INT *numVarOut, ST_INT timeOut);
static ST_VOID nvl_var_name_array_destroy (OBJECT_NAME **varNameArray, ST_INT numVar);
static ST_INT var_type_create (MVL_NET_INFO *net_info, OBJECT_NAME *varObj,
		ST_INT timeOut);
static ST_RET rcb_info_var_create (RCB_INFO *rcb_info, RPT_TYPEIDS *rpt_typeids);
static ST_VOID rcb_info_var_destroy (RCB_INFO *rcb_info);
static ST_VOID log_var_data (MVL_VAR_ASSOC *var);

/* DEBUG: move these functions to library modules?	*/
OBJECT_NAME *object_name_clone_create (OBJECT_NAME *srcobj);
ST_VOID object_name_clone_destroy (OBJECT_NAME *obj);

ST_INT sym_get_length(ST_UCHAR * r_asn1buf, ST_INT *ptr);
ST_INT sym_get_vstr (ST_UCHAR * r_asn1buf, ST_UCHAR *vstr_ptr, ST_INT maxchars, ST_INT len);
ST_INT sym_get_bitstr (ST_UCHAR * r_asn1buf, ST_UCHAR *bit_ptr, ST_INT max_bits, ST_INT len);
// 2012-11-08  define 解析 bitstring
ST_INT sym_get_da_index(ST_UCHAR * r_asn1buf, ST_INT *daindex, ST_INT max_bits, ST_INT len);



/************************************************************************/
/*			rpt_typeids_find											*/
/* Find ALL types needed for controlling & decoding IEC/UCA reports.	*/
/* These types must be defined in the ODF file and created by Foundry.	*/
/* RETURN: SD_SUCCESS or SD_FAILURE (if ANY type is NOT found)			*/
/* NOTE: this function based on "mvlu_rpt_find_typeids" in "mvlu_rpt.c".*/
/************************************************************************/
ST_RET rpt_typeids_find (RPT_TYPEIDS *rpt_typeids)
{
	ST_RET retCode = SD_FAILURE;	/* assume FAILURE for now	*/
	ST_CHAR *type_name;		/* name of type to be found	*/

	/* stop on any error	*/
	do
	{	/* "one-time" loop: just to have something to break out of	*/
		if ((rpt_typeids->mmsbool = mvl_typename_to_typeid (type_name = "RTYP_BOOL")) < 0)
			break;
		if ((rpt_typeids->bstr6 = mvl_typename_to_typeid (type_name = "RTYP_BSTR6")) < 0)
			break;
		if ((rpt_typeids->bstr8 = mvl_typename_to_typeid (type_name = "RTYP_BSTR8")) < 0)
			break;
		if ((rpt_typeids->bstr9 = mvl_typename_to_typeid (type_name = "RTYP_BSTR9")) < 0)
			break;
		if ((rpt_typeids->bvstring6 = mvl_typename_to_typeid (type_name = "RTYP_BVSTR6")) < 0)
			break;
		if ((rpt_typeids->bvstring8 = mvl_typename_to_typeid (type_name = "RTYP_BVSTR8")) < 0)
			break;
		if ((rpt_typeids->bvstring10 = mvl_typename_to_typeid (type_name = "RTYP_BVSTR10")) < 0)
			break;
		if ((rpt_typeids->btime6 = mvl_typename_to_typeid (type_name = "RTYP_BTIME6")) < 0)
			break;
		if ((rpt_typeids->int8u = mvl_typename_to_typeid (type_name = "RTYP_INT8U")) < 0)
			break;
		if ((rpt_typeids->int16u = mvl_typename_to_typeid (type_name = "RTYP_INT16U")) < 0)
			break;
		if ((rpt_typeids->int32u = mvl_typename_to_typeid (type_name = "RTYP_INT32U")) < 0)
			break;
		if ((rpt_typeids->ostring8 = mvl_typename_to_typeid (type_name = "RTYP_OSTR8")) < 0)
			break;
		if ((rpt_typeids->vstring32 = mvl_typename_to_typeid (type_name = "RTYP_VSTR32")) < 0)
			break;
		if ((rpt_typeids->vstring65 = mvl_typename_to_typeid (type_name = "RTYP_VSTR65")) < 0)
			break;
		retCode = SD_SUCCESS;  /* If we get here, all were successful	*/
	} while (0);	/* end of "one-time" loop	*/

	if (retCode)
		MVL_LOG_ERR1 ("Can't find type '%s'", type_name);
	return (retCode);	/* If ANY find failed, SD_FAILURE is returned	*/
}

#ifdef _use_rptCtl

/************************************************************************/
/*						rcb_info_create									*/
/************************************************************************/
RCB_INFO *rcb_info_create (MVL_NET_INFO *net_info, RPT_TYPEIDS *rpt_typeids, ST_INT nRCB)
{
	size_t extended_size;
	ST_RET status = SD_SUCCESS;	/* set to SD_FAILURE if anything fails.	*/

	assert (rpt_typeids->mmsbool || rpt_typeids->int8u);	/* make sure global struct initialized*/
	sprintf(rptCtl[net_info->nACSI].dsName[nRCB], "%s", pACSINode[net_info->nACSI].rcb[nRCB].dsName);
	extended_size = sizeof (RCB_INFO);
	if(rcb_info == NULL){
		rcb_info = chk_calloc (1, extended_size);
		status = rcb_info_var_create (rcb_info, rpt_typeids);	/* returns SD_SUCCESS or SD_FAILURE*/
		if (status != SD_SUCCESS){
			/* something failed. Destroy anything created.	*/
			chk_free(rcb_info);
			rcb_info = NULL;
		}
	}
	return (rcb_info);
}

#endif

/************************************************************************/
/*			nvl_var_name_array_create									*/
/* Send a GetNamedVariableListAttributes request to get a list of		*/
/* variable names in a NamedVariableList (NVL).							*/
/* Assume the NVL is domain-specific									*/
/* RETURN: ptr to array of ptrs to variable names (OBJECT_NAME structs).*/
/*	   Also the variable pointed to by numVarOut contains the number	*/
/*         of variables in the NVL.										*/
/* NOTE: this function allocates memory for the (OBJECT_NAME *) array.	*/
/*	Call "nvl_var_name_array_destroy" to free the memory.				*/
/************************************************************************/
static OBJECT_NAME **nvl_var_name_array_create (MVL_NET_INFO *net_info, 
		ST_CHAR *domName, ST_CHAR *nvlName,	ST_INT *numVarOut, ST_INT timeOut)
{
	MVL_REQ_PEND *reqCtrl;
	GETVLIST_REQ_INFO getvlist_req;
	GETVLIST_RESP_INFO *getvlist_resp;	/* set to reqCtrl->u.getvlist_resp_info*/
	VARIABLE_LIST *variable_list;
	OBJECT_NAME **varNameArray;	/* Ptr to array of ptrs to var names */
	ST_RET ret;			/* general purpose return code	*/
	ST_INT j;

	getvlist_req.vl_name.object_tag = DOM_SPEC;
	getvlist_req.vl_name.domain_id = domName;
	getvlist_req.vl_name.obj_name.vmd_spec = nvlName;

	ret = mvla_getvlist (net_info, &getvlist_req, &reqCtrl);
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, timeOut, net_info->nACSI);
	if (ret != SD_SUCCESS)
	{
		SLOGALWAYS1 ("mvla_getvlist Error = 0x%X.", ret);
		varNameArray = NULL;
	}
	else
	{
		getvlist_resp = reqCtrl->u.getvlist.resp_info;
		variable_list = (VARIABLE_LIST *) (getvlist_resp + 1);
		/* Allocate array of variable names.	*/
		*numVarOut = getvlist_resp->num_of_variables;
		varNameArray = chk_malloc (getvlist_resp->num_of_variables * sizeof (OBJECT_NAME *));
		/* Copy info from response to allocated array	*/
		for (j = 0; j < getvlist_resp->num_of_variables;  j++, variable_list++)
		{
			/* Assume all variables are named.	*/
			assert (variable_list->var_spec.var_spec_tag == VA_SPEC_NAMED);
			varNameArray[j] = object_name_clone_create (&variable_list->var_spec.vs.name);
		}
	}

	mvl_free_req_ctrl (reqCtrl);	/* CRITICAL: */
	return (varNameArray);
}

/************************************************************************/
/*			nvl_var_name_array_destroy									*/
/* Free up all resources allocated by "nvl_var_name_array_create".		*/
/************************************************************************/
static ST_VOID nvl_var_name_array_destroy (OBJECT_NAME **varNameArray, ST_INT numVar)
{
	ST_INT j;
	for (j = 0; j < numVar; j++)
	object_name_clone_destroy (varNameArray[j]);
	chk_free (varNameArray);
}

/************************************************************************/
/*			var_type_create												*/
/* Send GetVariableAccessAttributes request. Wait for response. When	*/
/* response received, create new type. Pass NULL as type_name arg to	*/
/* "mvl_type_id_create" (this avoids the problem of duplicate names).	*/
/* RETURN: Type ID														*/
/* NOTE: Call "mvl_type_id_destroy" to destroy the type created here.	*/
/************************************************************************/
#ifdef _MVL_TYPE_CTRL_use_one_device_
static ST_INT var_type_create ( MVL_NET_INFO *net_info, OBJECT_NAME *varObj,
							   ST_INT timeOut, MVL_TYPE_CTRL *mvl_type_ctrl)
#else
static ST_INT var_type_create ( MVL_NET_INFO *net_info, OBJECT_NAME *varObj,
							   ST_INT timeOut)
#endif
{
	MVL_REQ_PEND *reqCtrl;
	GETVAR_REQ_INFO getvar_req;
	VAR_ACC_TSPEC *type_spec;
	ST_INT type_id = -1;	/* invalid. If anything fails, this value returned*/
	ST_RET ret;

	getvar_req.req_tag = GETVAR_NAME;
	getvar_req.name = *varObj;

	/* Send GetVariableAccessAttributes request & wait for response. */
	ret = mvla_getvar (net_info, &getvar_req, &reqCtrl);
	if (ret == SD_SUCCESS)
		ret = waitReqDone (reqCtrl, timeOut, net_info->nACSI);
	if (ret != SD_SUCCESS)
		SLOGALWAYS1 ("GetVariableAccessAttributes error = 0x%x.", ret);
	else
	{
		type_spec = &reqCtrl->u.getvar.resp_info->type_spec;
		/* First arg (type_name) is NULL to avoid duplicate names.	*/

#ifdef _MVL_TYPE_CTRL_use_one_device_
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len, mvl_type_ctrl);
#else
		type_id = mvl_type_id_create (NULL, type_spec->data, type_spec->len);
#endif
	}
	mvl_free_req_ctrl (reqCtrl);
	return (type_id);
}

/************************************************************************/
/* 			rcb_info_var_create											*/
/* Create dummy variables to be used later when a report is received.	*/
/* These variables are needed to decode the data received in a report.	*/
/* This function fills in "rcb_info->rcb_data" and "rcb_info->rcb_var".	*/
/************************************************************************/
static ST_RET rcb_info_var_create (RCB_INFO *rcb_info, RPT_TYPEIDS *rpt_typeids)
{
	OBJECT_NAME dummyvar_objname;	/* dummy variable object name	*/

	/* CRITICAL: "mvl_var_create" is used (NOT "mvl_var_add") to create
	* local variables to store data received later in IEC/UCA Reports.
	* These are NOT real variables, so remote MMS nodes cannot access them.
	* All variables use the same name (dummyvar): that's OK because
	* "mvl_var_create" does NOT add them to the database and nothing needs
	* to use the name.
	*/

	/* NOTE: last arg to mvl_var_create is always SD_FALSE, so the name is
	* NOT copied. This is OK because all names here are fixed strings.
	*/

	/* Set up one OBJECT_NAME to use for all variables.	*/
	dummyvar_objname.object_tag = VMD_SPEC;
	dummyvar_objname.obj_name.vmd_spec = "dummyvar";	/* all vars use same name	*/

	if ((rcb_info->rcb_var.RptID = mvl_var_create (&dummyvar_objname, rpt_typeids->vstring65,
			&rcb_info->rcb_data.RptID, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.OptFlds = mvl_var_create (&dummyvar_objname, rpt_typeids->bvstring10,
			&rcb_info->rcb_data.OptFlds, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.SqNum = mvl_var_create (&dummyvar_objname, rpt_typeids->int16u,
			&rcb_info->rcb_data.SqNum, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.TimeOfEntry = mvl_var_create (&dummyvar_objname, rpt_typeids->btime6,
			&rcb_info->rcb_data.TimeOfEntry, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.DatSetNa = mvl_var_create (&dummyvar_objname, rpt_typeids->vstring65,
			&rcb_info->rcb_data.DatSetName, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.BufOvfl = mvl_var_create (&dummyvar_objname, rpt_typeids->mmsbool,
			&rcb_info->rcb_data.BufOvfl, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.SubSeqNum = mvl_var_create (&dummyvar_objname, rpt_typeids->int16u,
			&rcb_info->rcb_data.SubSeqNum, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.MoreSegmentsFollow = mvl_var_create (&dummyvar_objname, rpt_typeids->mmsbool,
			&rcb_info->rcb_data.MoreSegmentsFollow, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.EntryID = mvl_var_create (&dummyvar_objname, rpt_typeids->ostring8,
			&rcb_info->rcb_data.EntryID, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	if ((rcb_info->rcb_var.ConfRev = mvl_var_create (&dummyvar_objname, rpt_typeids->int32u,
			&rcb_info->rcb_data.ConfRev, NULL, SD_FALSE)) == NULL)
	return (SD_FAILURE);

	/*inclusion 用自编函数获取*/

	return (SD_SUCCESS);
}

/************************************************************************/
/* 			rcb_info_var_destroy										*/
/* Destroy everything created in "rcb_info_var_create".					*/
/* Check that each was successfully creating before destroying.	Any one	*/
/* of the "mvl_var_create" calls in "rcb_info_var_create" may have failed.*/
/************************************************************************/
static ST_VOID rcb_info_var_destroy (RCB_INFO *rcb_info)
{
	if (rcb_info->rcb_var.RptID)
		mvl_var_destroy (rcb_info->rcb_var.RptID);

	if (rcb_info->rcb_var.OptFlds)
		mvl_var_destroy (rcb_info->rcb_var.OptFlds);

	if (rcb_info->rcb_var.SqNum)
		mvl_var_destroy (rcb_info->rcb_var.SqNum);

	if (rcb_info->rcb_var.TimeOfEntry)
		mvl_var_destroy (rcb_info->rcb_var.TimeOfEntry);

	if (rcb_info->rcb_var.DatSetNa)
		mvl_var_destroy (rcb_info->rcb_var.DatSetNa);

	if (rcb_info->rcb_var.BufOvfl)
		mvl_var_destroy (rcb_info->rcb_var.BufOvfl);

	if (rcb_info->rcb_var.SubSeqNum)
		mvl_var_destroy (rcb_info->rcb_var.SubSeqNum);

	if (rcb_info->rcb_var.MoreSegmentsFollow)
		mvl_var_destroy (rcb_info->rcb_var.MoreSegmentsFollow);

	if (rcb_info->rcb_var.EntryID)
		mvl_var_destroy (rcb_info->rcb_var.EntryID);

	if (rcb_info->rcb_var.ConfRev)
		mvl_var_destroy (rcb_info->rcb_var.ConfRev);

	if (rcb_info->rcb_var.Inclusion)
		mvl_var_destroy (rcb_info->rcb_var.Inclusion);
}

/************************************************************************/
/* This sample function sets some options and enables the RCB.			*/
/* If any write fails, stop.											*/
/* If more options needed, add more arguments to this function.			*/
/************************************************************************/
ST_RET rcb_enable ( MVL_NET_INFO *netInfo, ST_CHAR *domName,
					ST_CHAR *rcbName, ST_UCHAR *OptFlds, ST_UCHAR *TrgOps,
					ST_UINT32 IntgPd, RPT_TYPEIDS *rpt_typeids, ST_CHAR *RptID, 
					ST_CHAR *EntryID, ST_INT timeOut, ST_BOOLEAN isBR )
{
	ST_BOOLEAN RptEna = 1;		/* 1 = enable the report */
	ST_RET ret = SD_SUCCESS;
	ST_CHAR varName [MAX_IDENT_LEN + 1];

	if (ret == SD_SUCCESS)
	{
		sprintf (varName, "%s$RptID", rcbName);
		ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->vstring65, RptID, timeOut);
	}

	if (ret == SD_SUCCESS)
	{
		sprintf (varName, "%s$IntgPd", rcbName);
		ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->int32u, (ST_CHAR *) &IntgPd, timeOut);
	}

	if (ret == SD_SUCCESS)
	{
		/* NOTE: only write 9 bits. 10th bit (segmentation) is read-only.	*/
		//sprintf (varName, "%s$OptFlds", rcbName);
		sprintf (varName, "%s$%s", rcbName, g_strOptFlds);
		ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->bstr9, OptFlds, timeOut);
	}

	if (ret == SD_SUCCESS)
	{
		//sprintf (varName, "%s$TrgOps", rcbName);
		sprintf (varName, "%s$%s", rcbName, g_strTrgOps);
		ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->bstr8, TrgOps, timeOut);
	}

	if(isBR){
		if (ret == SD_SUCCESS)
		{
			sprintf (varName, "%s$EntryID", rcbName);
			ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->ostring8, EntryID, timeOut);
		}
	}

//  if (ret == SD_SUCCESS)
    {
		sprintf (varName, "%s$RptEna", rcbName);
		ret = named_var_write (netInfo, varName, DOM_SPEC, domName, rpt_typeids->mmsbool, (ST_CHAR *) &RptEna, timeOut);
    }

	return (ret);
}

static ST_VOID log_var_data (MVL_VAR_ASSOC *var)
{
	//[$$$$$$$$$$$$$$$$$$$$]
#if 0
	ST_CHAR tdl_buf [500];	/* increase size if complex TDL expected*/
	MVL_TYPE_CTRL *type_ctrl;
	ST_CHAR *data_text;		/* var data converted to text */
	ST_CHAR text_buf [30000];	/* increase size if ms_local_to_text fails */

	type_ctrl = mvl_type_ctrl_find (var->type_id);
	if (type_ctrl)
    {
		/* If the TDL produced is longer than max_tdl_len, this function */
		/* "gracefully" fails (i.e. returns 0).	 */
		if (ms_runtime_to_tdl (type_ctrl->rt, type_ctrl->num_rt, tdl_buf, sizeof(tdl_buf))>0)
			SLOGCALWAYS1 ("  TYPE: %s", tdl_buf);
		else
			SLOGCALWAYS0 ("  TYPE: unknown");

		data_text = ms_local_to_text (var->data,
					 type_ctrl->rt,
					 type_ctrl->num_rt, text_buf, sizeof (text_buf));
		if (data_text)
			SLOGCALWAYS1 ("  DATA: %s", data_text);
		else
			SLOGCALWAYS0 ("  DATA: cannot be converted to text");
    }
	else
		SLOGCALWAYS0 ("  ERR: type_id is invalid");
#endif
}

/************************************************************************/
/*			u_iec_rpt_ind_data											*/
/* User function to process the received report data. This example		*/
/* function simply writes the data to the log file.						*/
/*																		*/
/* It should be easy to modify or rewrite this function to do whatever	*/
/* is appropriate for your application.									*/
/************************************************************************/
ST_VOID u_iec_rpt_ind_data (MVL_VAR_ASSOC **info_va,
							ST_UINT8 *OptFldsData,	/* ptr to data part of OptFlds bvstring	*/
							ST_UINT8 *InclusionData,/* ptr to Inclusion bstring	*/
							ST_INT numDsVar,
							ST_INT va_total)
{
	ST_CHAR strBuffTemp[NAMESIZE];
	ST_INT va_num=0;
	ST_INT j;

	SLOGALWAYS0 ("Data received in Information Report");
	SLOGCALWAYS1("Var# %02d:    RptId", va_num);
	log_var_data (info_va[va_num]);
	va_num++;
	sprintf(strBuffTemp, "Var# %02d:    %s", g_strOptFlds);
	//SLOGCALWAYS1("Var# %02d:    OptFlds", va_num);
	SLOGCALWAYS1(strBuffTemp, va_num);
	log_var_data (info_va[va_num]);
	va_num++;

	/* NOTE: Don't change initial entries in "info_va". Add these right after "OptFlds".*/
	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_SQNUM))
	{
		SLOGCALWAYS1("Var# %02d:    SqNum", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_TIMESTAMP))
	{
		SLOGCALWAYS1("Var# %02d:    TimeOfEntry", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_DATSETNAME))
	{
		SLOGCALWAYS1("Var# %02d:    DatSetNa", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET (OptFldsData, OPTFLD_BITNUM_BUFOVFL))
	{
		SLOGCALWAYS1("Var# %02d:    BufOvfl", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_ENTRYID))
	{
		SLOGCALWAYS1("Var# %02d:    EntryID", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_CONFREV))
	{
		SLOGCALWAYS1("Var# %02d:    ConfRev", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	if (BSTR_BIT_GET (OptFldsData,OPTFLD_BITNUM_SUBSEQNUM))
	{
		SLOGCALWAYS1("Var# %02d:    SubSeqNum", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
		SLOGCALWAYS1("Var# %02d:    MoreSegmentsFollow", va_num);
		log_var_data (info_va[va_num]);
		va_num++;
	}

	SLOGCALWAYS1("Var# %02d:    Inclusion", va_num);
	log_var_data (info_va[va_num]);
	va_num++;

	/* If data-Ref enabled, check "Inclusion" to figure out what is being received.*/
	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_DATAREF))
	{
		for (j = 0; j < numDsVar; ++j)
		{
			if (BSTR_BIT_GET (InclusionData, j))
			{
				SLOGCALWAYS2("Var# %02d:    DataRefName# %d", va_num, j);
				log_var_data (info_va[va_num]);
				va_num++;
			}
		}
	}

	/* HERE'S THE DATA. Check "Inclusion" to figure out what is being received.*/
	for (j = 0; j < numDsVar; ++j)
	{
		if (BSTR_BIT_GET (InclusionData, j))
		{
			SLOGCALWAYS2("Var# %02d:    Data# %d", va_num, j);
			log_var_data (info_va[va_num]);
			va_num++;
		}
	}

	/* If "reason" enabled, check "Inclusion" to figure out what is being received.*/
	if (BSTR_BIT_GET(OptFldsData, OPTFLD_BITNUM_REASON))
	{
		for (j = 0; j < numDsVar; ++j)
		{
			if (BSTR_BIT_GET (InclusionData, j))
			{
				SLOGCALWAYS2("Var# %02d:    Reason# %d", va_num, j);
				log_var_data (info_va[va_num]);
				va_num++;
			}
		}
	}
	assert (va_num==va_total);	/* Did we count right?	*/
}

/************************************************************************/
/*			object_name_clone_create									*/
/* Create clone of OBJECT_NAME struct. Can't just copy struct because	*/
/* struct contains pointers to strings.									*/
/* The function "object_name_clone_destroy" should be called to destroy	*/
/* the clone.															*/
/************************************************************************/
OBJECT_NAME *object_name_clone_create (OBJECT_NAME *srcobj)
{
	OBJECT_NAME *dstobj;
	size_t extended_size;
	ST_CHAR *extended_ptr;

	/* Allocate OBJECT_NAME structure plus extra room for additional data.
	* This effectively combines 3 allocations into one.
	* Set pointers in OBJECT_NAME structure to point into the extra space.
	*/
	extended_size = sizeof (OBJECT_NAME)
		  + MAX_IDENT_LEN + 1			/* dstobj->obj_name.vmd_spec */
		  + MAX_IDENT_LEN + 1;			/* dstobj->domain_id */

	dstobj = chk_malloc (extended_size);

	/* Copy old struct to new struct (before setting ptrs in new struct). */
	memcpy (dstobj, srcobj, sizeof (OBJECT_NAME));

	/* Fix ptrs to strings in new struct	*/
	extended_ptr = (ST_CHAR *)(dstobj + 1);	/* point after dstobj struct */

	dstobj->obj_name.vmd_spec = extended_ptr;
	extended_ptr += (MAX_IDENT_LEN + 1);		/* point after dstobj->obj_name.vmd_spec*/

	dstobj->domain_id = extended_ptr;

	/* Copy strings to the new struct.	*/
	strcpy (dstobj->obj_name.vmd_spec, srcobj->obj_name.vmd_spec);
	if (dstobj->object_tag == DOM_SPEC)
	strcpy (dstobj->domain_id, srcobj->domain_id);
	return (dstobj);
}

/************************************************************************/
/*			object_name_clone_destroy									*/
/* Destroy OBJECT_NAME clone created by "object_name_clone_create".		*/
/************************************************************************/
ST_VOID object_name_clone_destroy (OBJECT_NAME *obj)
{
	/* allocated by object_name_clone_create using chk_malloc, so use chk_free.*/
	chk_free (obj);
}

ST_RET FindRCB_INFO(MVL_NET_INFO *cc, ST_INT nRptID, ST_CHAR *rptID, ST_INT *pIdx)
{
	ST_RET	ret = SD_FAILURE;
	ST_CHAR *p;

    p = &rptID[2];
	*pIdx = atoi(p);
	if(0 == *pIdx)
		return SD_FAILURE;
	else
	{
		*pIdx = *pIdx - 1;
		if(*pIdx >= (MAX_RCB_VMD-1))
			return SD_FAILURE;
		else
			return SD_SUCCESS;
	}
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
ST_RET My_Pare_RptID_LD(LD_NODE *ptLD, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_CHAR *RptID)
{
	ST_INT i;
//	ST_INT j;
	ST_INT k;
	//ST_INT m;
// 	ST_CHAR strBrcbName[NAMESIZE];
	ST_CHAR *pTemp = NULL;

// 	for (i=0;i<ptLD->numDaSet;i++)
// 	{
// 		LD_DATASET_INFO *pLD_INFO = &ptLD->DataInfo[i];
// 
// 		for (j=0;j<ptLD->DataInfo[i].numData;j++)
// 		{
// 			for (k=0; k<pLD_INFO->numRcb;k++)
// 			{
// 				if (strstr(RptID,pLD_INFO->RCB[k].rcbName) || strstr(pLD_INFO->RCB[k].rcbName,RptID))
// 				{
// 					*numDA = ptLD->DataInfo[i].numData;
// 					*pTagDA = ptLD->DataInfo[i].DataSet;
// 					*nDsIndex = i;
// 					return SD_SUCCESS;
// 				}
// 			}
// 		}
// 	}

	for (i=0;i<ptLD->numDaSet;i++)
	{
		LD_DATASET_INFO *pLD_INFO = &ptLD->DataInfo[i];

		for (k=0; k<pLD_INFO->numRcb;k++)
		{
			if (strstr(RptID, pLD_INFO->RCB[k].rcbName) || strstr(pLD_INFO->RCB[k].rcbName, RptID))
			{
				*numDA = ptLD->DataInfo[i].numData;
				*pTagDA = ptLD->DataInfo[i].DataSet;
				*nDsIndex = i;
				return SD_SUCCESS;
			}

			if (strcmp(RptID, pLD_INFO->RCB[k].RptID) == 0)
			{
				*numDA = ptLD->DataInfo[i].numData;
				*pTagDA = ptLD->DataInfo[i].DataSet;
				*nDsIndex = i;
				return SD_SUCCESS;
			}
		}
	}
// 
// 	pTemp = RptID;
// 	*strBrcbName = 0;
// 
// 	while (*pTemp != 0)
// 	{
// 		if (*pTemp == '/')
// 		{
// 			strcpy(strBrcbName, pTemp+1);
// 			break;
// 		}
// 		
// 		pTemp++;
// 
// 		if (pTemp - RptID > NAMESIZE)
// 		{
// 			break;
// 		}
// 	}
// 	
// 	if (*strBrcbName == 0)
// 	{
// 		return SD_FAILURE;
// 	}
// 
// 	for (i=0;i<ptLD->numDaSet;i++)
// 	{
// 		LD_DATASET_INFO *pLD_INFO = &ptLD->DataInfo[i];
// 
// 		for (k=0; k<pLD_INFO->numRcb;k++)
// 		{
// 			if (strstr(strBrcbName,pLD_INFO->RCB[k].rcbName) || strstr(pLD_INFO->RCB[k].rcbName, strBrcbName))
// 			{
// 				*numDA = ptLD->DataInfo[i].numData;
// 				*pTagDA = ptLD->DataInfo[i].DataSet;
// 				*nDsIndex = i;
// 				return SD_SUCCESS;
// 			}
// 		}
// 	}

	return SD_FAILURE;
}

ST_RET My_Pare_RptID(ST_INT nACSI, LD_NODE **pLD, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_INT *nLdIndex, ST_CHAR *RptID)
{
//	ST_INT i;
//	ST_INT j;
	ST_INT n;
//	ST_INT k;
//	ST_INT m;

	// 查找数据
	ACSI_NODE *ptACSINode = &pACSINode[nACSI];
	ST_CHAR *pTemp = RptID;
	ST_CHAR strDsName[NAMESIZE];
	ST_INT nLen;

	//RptID = 0x0a27fa7c "LDO/LLN0$BR$brcbDeviceState"
	while (*pTemp != '/' && *pTemp != '$')
	{
		pTemp++;

		if (pTemp - RptID > NAMESIZE)
		{
			break;
		}
	}

	if (*pTemp == '/')
	{
		nLen = pTemp - RptID;
		memcpy(strDsName, RptID, nLen);
		strDsName[nLen] = 0;

		for (n=0;n<ptACSINode->numLD;n++)
		{
			LD_NODE *ptLD = &ptACSINode->LD[n];

			if (strstr(ptLD->LDName, strDsName) != NULL)
			{
				if (My_Pare_RptID_LD(ptLD, numDA, pTagDA, nDsIndex, RptID) == SD_SUCCESS)
				{
					*nLdIndex = n;
					*pLD = ptLD;
					return SD_SUCCESS;
				}

			}

		}

		//return SD_FAILURE;
	}

	*numDA = 0;

	for (n=0;n<ptACSINode->numLD;n++)
	{
		LD_NODE *ptLD = &ptACSINode->LD[n];

		if (My_Pare_RptID_LD(ptLD, numDA, pTagDA, nDsIndex, RptID) == SD_SUCCESS)
		{
			*pLD = ptLD;
			*nLdIndex = n;
			return SD_SUCCESS;
		}
	}

	return SD_FAILURE;
}

//zhouhj20180130 根据日志控制块名称路径查找pTagDA
ST_RET My_Pare_JournalID_LD(LD_NODE *ptLD, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_CHAR *RptID, ST_CHAR *DataPath)
{
	ST_INT i,j;

	for (i=0;i<ptLD->JournalCtrls.numData;i++)
	{
		LD_LOG_INFO *pLD_LogInfo = &ptLD->JournalCtrls.LogInfo[i];

		if (mms_str_length(&pLD_LogInfo->Name) == 0)
			continue;

		if (strstr(mms_string(&pLD_LogInfo->Name),RptID))
		{
			if (strcmp(ptLD->DataInfo[i].DataSetID,mms_string(&pLD_LogInfo->Dataset))==0)
			{
				for (j=0;j<ptLD->DataInfo[i].numData;j++)
				{
					if ((strcmp(mms_string(&ptLD->DataInfo[i].DataSet[j].DAValue.mmsName),DataPath)==0)&&(mms_str_length(&ptLD->DataInfo[i].DataSet[j].DAValue.mmsName) == strlen(DataPath)))
					{
						*pTagDA = &ptLD->DataInfo[i].DataSet[j];
						*numDA = ptLD->DataInfo[i].numData;
						*nDsIndex = i;
						return SD_SUCCESS;
					}
				}
			} 
		}
	}

	return SD_FAILURE;
}

/************************************************************************/
/* 2013-5-8  从数据集中去解析                                         */
/************************************************************************/
ST_RET My_Pare_DataSet(ST_INT nACSI, LD_NODE **pLD, ST_INT *nLdIndex, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_CHAR *dataSet)
{
	ST_INT i;
	ST_INT n;
//	ST_INT l;
	char *pLdPos = NULL;
	char *pDatasetPos = NULL, *pTemp = NULL;
	ACSI_NODE *ptACSINode = NULL;
	LD_NODE *ptLD = NULL;

	ST_CHAR  pszDataSetName[NAMESIZE];
	strcpy(pszDataSetName, dataSet);
	pDatasetPos = pszDataSetName;

	pTemp = pszDataSetName;

	while (*pTemp != NULL)
	{
		if ((*pTemp == '\\') || (*pTemp == '/'))
		{
			*pTemp = 0;
			pDatasetPos = pTemp+1;
			pLdPos = pszDataSetName;
			break;
		}

		pTemp++;
	}

	// 查找数据
	ptACSINode = &pACSINode[nACSI];
	*numDA = 0;

	for (n=0;n<ptACSINode->numLD;n++)
	{
		ptLD = &ptACSINode->LD[n];

		if (pLdPos != NULL)
		{
			if (strcmp(pLdPos, ptLD->LDName) != 0)
			{
				continue;
			}
		}

		for (i=0;i<ptLD->numDaSet;i++)
		{
			LD_DATASET_INFO*pLDInfo = &ptLD->DataInfo[i];

			if (pLDInfo)
			{
				if (strcmp(pDatasetPos, pLDInfo->DataSetID) == 0)
				{
					*pLD = &ptACSINode->LD[n];
					*numDA = pLDInfo->numData;
					*pTagDA = pLDInfo->DataSet;
					*nDsIndex = i;
					*nLdIndex = n;

					return SD_SUCCESS;
				}
			}
		}
	}

	return SD_FAILURE;
}


ST_RET My_Pare_DataSetEx(ST_INT nACSI, LD_NODE **pLD, ST_INT *nLdIndex, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_CHAR *dataSet)
{
	ST_INT i;
	ST_INT n;
	//	ST_INT l;

	// 查找数据
	ACSI_NODE *ptACSINode = &pACSINode[nACSI];
	LD_DATASET_INFO*pLDInfo = NULL;
	LD_NODE *ptLD = NULL;

	*numDA = 0;
	for (n=0;n<ptACSINode->numLD;n++)
	{
		ptLD = &ptACSINode->LD[n];

		if (strstr(dataSet,ptLD->LDName) == NULL)
		{
			continue;
		}

		for (i=0;i<ptLD->numDaSet;i++)
		{
			pLDInfo = &ptLD->DataInfo[i];

			if (pLDInfo)
			{
				if (strstr(dataSet,pLDInfo->DataSetID))
				{
					*pLD = &ptACSINode->LD[n];
					*numDA = pLDInfo->numData;
					*pTagDA = pLDInfo->DataSet;
					*nDsIndex = i;
					*nLdIndex = n;

					return SD_SUCCESS;
				}
			}
		}
	}

	return (*numDA<=0) ? SD_FAILURE : SD_SUCCESS;
}

ST_RET My_CreateRptNotifyEvent()
{	
	if (hRptNotifyEvent == NULL)
	{
		hRptNotifyEvent = CreateEvent(NULL,FALSE,FALSE,"MMS-RPT-NOTIFY");
		if (hRptNotifyEvent == NULL)
		{
			return SD_FAILURE;
		}
	}

	return SetEvent(hRptNotifyEvent);
}

ST_VOID mms_ReleaseValue(tagDAValue *pValue, BOOL bValString)
{
	mms_str_quit(&pValue->mmsName);

	if (bValString)
	{
		mms_str_quit(&pValue->Value.string);
	}
}


ST_VOID mms_ReleaseData(tagDA*pData)
{
	ST_INT i=0;

	if (pData == NULL)
	{
		return;
	}

	if (pData != NULL)
	{
		for (i=0;i<pData->nSubDANum;i++)
		{
			mms_ReleaseData(&pData->pSubDA[i]);
		}

		pData->nSubDANum = 0;
		free(pData->pSubDA);
		pData->pSubDA = NULL;
	}

	if (strstr(pData->DataType, "_STR") != NULL)
	{
		mms_ReleaseValue(&pData->DAValue, TRUE);
	}
	else
	{
		mms_ReleaseValue(&pData->DAValue, FALSE);
	}

	mms_ReleaseValue(&pData->DADescri, TRUE);
	mms_ReleaseValue(&pData->DAUnite, FALSE);
#ifdef tagDA_use_UNIT_MIN_MAX_STEP
	mms_ReleaseValue(&pData->MaxVal, FALSE);
	mms_ReleaseValue(&pData->MinVal, FALSE);
	mms_ReleaseValue(&pData->StepSize, FALSE);
#endif
}

ST_VOID mms_ReleaseDataRpt(tagDA*pData)
{
	ST_INT i=0;

	if (pData != NULL)
	{
		for (i=0;i<pData->nSubDANum;i++)
		{
			mms_ReleaseDataRpt(&pData->pSubDA[i]);
		}

		free(pData->pSubDA);
		pData->pSubDA = NULL;
	}
}

ST_VOID mms_ReleaseDataX(tagDA*pData)
{
	ST_INT i=0;

	if (pData != NULL)
	{
		for (i=0;i<pData->nSubDANum;i++)
		{
			mms_ReleaseData(&pData->pSubDA[i]);//zhouhj将 mms_ReleaseDataX(pDA) 改为此 用于测试内存泄漏
		}

		free(pData->pSubDA);
		pData->pSubDA = NULL;
		pData->nSubDANum = 0;
	}
}

ST_VOID mms_CopyValue(tagDAValue*pDst, tagDAValue*pSrc, BOOL bString)
{
#ifdef _use_mms_string
	mms_str_copy(&pDst->mmsName, &pSrc->mmsName);

	if (bString)
	{
		mms_str_copy(&pDst->Value.string, &pSrc->Value.string);
	}
	else
	{
		pDst->Value.utctime = pSrc->Value.utctime;
	}
#endif
}

ST_VOID mms_CopyValue2(tagValue*pDst, tagValue*pSrc, BOOL bString)
{
#ifdef _use_mms_string
	//mms_str_copy(&pDst->mmsName, &pSrc->mmsName);

	if (bString)
	{
		mms_str_copy(&pDst->string, &pSrc->string);
	}
	else
	{
		pDst->utctime = pSrc->utctime;
	}
#else
	*pDst = *pSrc;
#endif
}
ST_INT mms_is_da_struct(tagDA*pSrc)
{
	if (pSrc->DataType[0] == 'S')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ST_INT mms_is_da_array(tagDA*pSrc)
{
	if (pSrc->DataType[0] == 'A')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ST_INT mms_is_da_basic(tagDA*pSrc)
{
	if (mms_is_da_array(pSrc))
	{
		return 0;
	}
	
	if (mms_is_da_struct(pSrc))
	{
		return 0;
	}

	return 1;
}

ST_BOOLEAN mms_IsDataTypeString(ST_CHAR *pszDataType)
{
	return (strstr(pszDataType, "_STR") != NULL);
}

ST_BOOLEAN mms_IsDataString(tagDA *pDA)
{
	return mms_IsDataTypeString(pDA->DataType);
	//return (strstr(pDA->DataType, "_STR") != NULL);
}

ST_VOID mms_CopyData(tagDA*pSrc, tagDA*pDst, BOOL bRpt)
{
	ST_INT i=0;
	ST_INT size = 0;
// 	mms_ReleaseData(pDst);

	if (pSrc==NULL)
		return;

#ifdef _use_mms_string
	pDst->ReasonCode = pSrc->ReasonCode;
	pDst->Type_id = pSrc->Type_id;
	strcpy(pDst->DataType, pSrc->DataType);	//INT, BOOL 等
	pDst->ApplyType = pSrc->ApplyType;
	pDst->EventNum = pSrc->EventNum;
	pDst->bWrite = pSrc->bWrite;		//0-不可写 1-可写
	pDst->bModify = pSrc->bModify;		//0-未修改 1-已修改
	pDst->nSubDANum = pSrc->nSubDANum;
	pDst->dwDsMapObj = pSrc->dwDsMapObj;
	pDst->nDataType = pSrc->nDataType;//zhouhj20180130

	if (strstr(pDst->DataType, "_STR") != NULL)
	{
		mms_CopyValue(&pDst->DAValue, &pSrc->DAValue, TRUE);		//数值
	}
	else
	{
		mms_CopyValue(&pDst->DAValue, &pSrc->DAValue, FALSE);		//数值
	}

	mms_CopyValue(&pDst->DADescri, &pSrc->DADescri, TRUE);	//描述
	mms_CopyValue(&pDst->DAUnite, &pSrc->DAUnite, FALSE);		//单位

#ifdef tagDA_use_UNIT_MIN_MAX_STEP
	mms_CopyValue(&pDst->MaxVal, &pSrc->MaxVal, FALSE);		//最大值
	mms_CopyValue(&pDst->MinVal, &pSrc->MinVal, FALSE);		//最小值
	mms_CopyValue(&pDst->StepSize, &pSrc->StepSize, FALSE);		//stepsize
#endif

#else
	*pDst = *pSrc;
#endif

	if (pSrc->pSubDA != NULL)
	{
		size = pSrc->nSubDANum*sizeof(tagDA);
		pDst->pSubDA = (tagDA*)malloc(size);
		ZeroMemory(pDst->pSubDA, size);
		
		for (i=0; i<pSrc->nSubDANum; i++)
		{
			mms_InitData(&pDst->pSubDA[i]);
			mms_CopyData(&pSrc->pSubDA[i], &pDst->pSubDA[i], bRpt);
		}
	}
}

ST_VOID mms_CopyValueEx(tagDAValueEx *pDest, tagDAValueEx *pSrc)
{

#ifdef _use_mms_string
	mms_str_copy(&pDest->mmsName, &pSrc->mmsName);
	mms_str_copy(&pDest->DataType, &pSrc->DataType);

	if (strstr(mms_string(&pDest->DataType), "_STR") != NULL)
	{
		mms_CopyValue2(&pDest->Value, &pSrc->Value, TRUE);		//数值
	}
	else
	{
		mms_CopyValue2(&pDest->Value, &pSrc->Value, FALSE);		//数值
	}
#else
	*pDest = *pSrc;
#endif
}

void mms_InitData(tagDA*pDA)
{
#ifdef _use_mms_string
	mms_str_init(&pDA->DAValue.mmsName);
	mms_str_init(&pDA->DADescri.mmsName);
	mms_str_init(&pDA->DAUnite.mmsName);
#ifdef tagDA_use_UNIT_MIN_MAX_STEP
	mms_str_init(&pDA->MaxVal.mmsName);
	mms_str_init(&pDA->MinVal.mmsName);
	mms_str_init(&pDA->StepSize.mmsName);
#endif

	mms_InitDatas(pDA->pSubDA, pDA->nSubDANum);
#endif
}

ST_VOID mms_InitDatas(tagDA*pDA, long nCount)
{
	ST_INT nIndex;

	if (pDA == NULL || nCount == 0)
	{
		return;
	}

	for (nIndex=0; nIndex<nCount; nIndex++)
	{
		mms_InitData(pDA+nIndex);
	}
}


ST_VOID mms_SetValueX(tagValue*pDst, tagValueX*pSrc, ST_INT type_id)
{
	DWORD dwData;
	char *pstring;
	long nBitLenth = 13;
	long nByteLenth = 4;
	BYTE bitstr[5] = {0};
	long nTmp = 0;

	if (type_id == DA_DATATYE_UTF8_STR)
	{
		mms_UTF8ToUnicodeEx(pSrc->string, strlen(pSrc->string), pSrc->string);
		mms_str_set(&pDst->string, pSrc->string);
	}
	else if (type_id == DA_DATATYE_BIT_STR)//BIT_STR
	{
		//asn1r_dec_Bitstring_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, 380, pDA);
		nBitLenth = pSrc->i%64;

		if (nBitLenth <= 8)
		{
			nByteLenth = 1;
		}
		else if (nBitLenth <= 16)
		{
			nByteLenth = 2;
		}
		else if (nBitLenth <= 24)
		{
			nByteLenth = 3;
		}
		else if (nBitLenth <= 32)
		{
			nByteLenth = 4;
		}

		dwData = pSrc->i;

		for(nTmp = 0;nTmp<nByteLenth;nTmp++)
		{
			bitstr[nByteLenth-nTmp-1] = dwData>>24;
			dwData <<= 8;
		}
		
		mms_str_init2(&pDst->string, (8*nByteLenth + 4));
		pstring = mms_string(&pDst->string);
		CharStrToBinaryStr(bitstr,nByteLenth,pstring);

		if (nBitLenth == 0)
		{
			dwData = pSrc->i;
			dwData<<=24;
			bitstr[0] = dwData>>24;
			CharStrToBinaryStr(bitstr,1,pstring);
			mms_str_set_size(&pDst->string, 1);
			pstring[1] = 0;
		}
		else
		{
			mms_str_set_size(&pDst->string, nBitLenth);
			pstring[nBitLenth] = 0;
		}

		//dwData = pSrc->i;
		//dwData >>= 6;
		//mms_str_set_size(&pDst->string, 10);
		//pstring = mms_string(&pDst->string);
		//sprintf(pstring, "%X", dwData);
	}
	else if (type_id == DA_DATATYE_VISIBLE_STR)
	{
//		mms_UTF8ToUnicodeEx(pSrc->string, strlen(pSrc->string), pSrc->string);
		mms_str_set(&pDst->string, pSrc->string);
	}
	else if (type_id == DA_DATATYE_OCTET_STR)
	{
		mms_str_set(&pDst->string, pSrc->string);
	}
	else if (type_id == DA_DATATYE_INT)
	{
		pDst->i = pSrc->i;
	}
	else if (type_id == DA_DATATYE_ARRAY || type_id == DA_DATATYE_STRUCT)
	{

	}
	else
	{
		pDst->utctime = pSrc->utctime;
	}
}

#ifdef _tagRpt_use_DA_ref
ST_INT rpt_get_capacity(tagRpt *pRpt)
{
	return pRpt->capacity;
}

ST_INT rpt_get_size(tagRpt *pRpt)
{
	return pRpt->size;
}

void rpt_init(tagRpt *pRpt, ST_INT sz)
{
	rpt_init2(pRpt, sz, sz);
}

void rpt_init2(tagRpt *pRpt, ST_INT sz, ST_INT cap)
{
	ST_INT len;

	if (pRpt->capacity >= cap)
	{
		pRpt->size = sz;
	}
	else
	{
		rpt_quit(pRpt);
		len = sizeof(tagRptValue) * cap;
		pRpt->Value = (tagRptValue *) malloc (len);
		memset(pRpt->Value, 0, len);
		pRpt->capacity = cap;
		pRpt->size = sz;
	}
}

tagValue* rpt_get_at(tagRpt *pRpt, ST_INT nIndex)
{
	tagRptValue *pValues = pRpt->Value;

	if (pRpt->size <= nIndex)
	{
		return NULL;
	}
	else
	{
		return &pValues[nIndex].Value;
	}
}

tagRptValue* rpt_get_rptval_at(tagRpt *pRpt, ST_INT nIndex)
{
	tagRptValue *pValues = pRpt->Value;

	if (pRpt->size <= nIndex)
	{
		return NULL;
	}
	else
	{
		return pValues+nIndex;
	}
}

void rpt_quit(tagRpt *pRpt)
{
	ST_INT nIndex;
	nIndex = 0;

	for (nIndex=0; nIndex < pRpt->capacity; nIndex++)
	{
		rpt_quit_value(pRpt->Value+nIndex);
	}

	free (pRpt->Value);
	pRpt->Value = NULL;
	pRpt->size = 0;
	pRpt->capacity = 0;
}

void rpt_quit_value(tagRptValue *pValue)
{
	if (pValue == NULL)
	{
		return;
	}

	if (pValue->bString)
	{
		mms_str_quit(&pValue->Value.string);
		pValue->bString = FALSE;
	}
}

void rpt_set_at(tagRpt *pRpt, ST_INT nIndex,  tagValue *Value, ST_INT bString)
{
	tagRptValue *pRptValue = rpt_get_rptval_at(pRpt, nIndex);
	rpt_set_value(pRptValue, Value, bString);
}

void rpt_set_value(tagRptValue *pDest,  tagValue *Value, ST_INT bString)
{
	if (bString)
	{
		if (!pDest->bString)
		{
			memset(pDest, 0, sizeof(tagRptValue));
			memset(&pDest->Value, 0, sizeof(pDest->Value));
		}

		mms_str_copy(&pDest->Value.string, &Value->string);
	}
	else
	{
		if (pDest->bString)
		{
			mms_str_quit(&pDest->Value.string);
		}

		pDest->Value = *Value;
	}

	pDest->bString = bString;
}

ST_INT mms_get_value_count(tagDA *pDA)
{
	int count = 0;
	int index = 0;

	//if (strcmp(pDA->DataType, "STRUCT") == 0)
	if (mms_is_da_struct(pDA) || mms_is_da_array(pDA))
	{
		for (index = 0; index < pDA->nSubDANum; index++)
		{
			count = count + mms_get_value_count(pDA->pSubDA+index);
		}
	}
	else
	{
		count = 1;
	}

	return count;
}

ST_VOID mms_CopyDataRpt(tagDA*pSrc, tagRpt *pRpt)
{
	ST_INT i=0;
	ST_INT size = 0;
	tagRptValue *pRptValue ;

	if (pSrc==NULL)
		return;

	pRpt->pDaRef = pSrc;
	size = mms_get_value_count(pSrc);
	rpt_init(pRpt, size);
	pRptValue = pRpt->Value;
	mms_CopyDataRptValue(pSrc, &pRptValue);
}

ST_VOID mms_CopyDataRptValue(tagDA*pSrc, tagRptValue **ppRptValue)
{
	int index = 0;

	//if (strcmp(pDA->DataType, "STRUCT") == 0)
	if (mms_is_da_struct(pSrc) || mms_is_da_array(pSrc))
	{
		for (index = 0; index < pSrc->nSubDANum; index++)
		{
			mms_CopyDataRptValue(pSrc->pSubDA+index, ppRptValue);
		}
	}
	else
	{
		rpt_set_value(*ppRptValue, &pSrc->DAValue.Value, mms_IsDataString(pSrc));
		*ppRptValue = *ppRptValue + 1;
	}
}

ST_VOID mms_InitDA_DataType(tagDA*pSrc)
{
	if (strcmp(pSrc->DataType, "BOOL") == 0)
		pSrc->nDataType = DA_DATATYE_BOOL;
	else if (strcmp(pSrc->DataType, "INT") == 0)
		pSrc->nDataType = DA_DATATYE_INT;
	else if (strcmp(pSrc->DataType, "UINT") == 0)
		pSrc->nDataType = DA_DATATYE_UINT;
	else if (strcmp(pSrc->DataType, "FLOAT") == 0)
		pSrc->nDataType = DA_DATATYE_FLOAT;
	else if (strcmp(pSrc->DataType, "UTC_TIME") == 0)
		pSrc->nDataType = DA_DATATYE_UTC_TIME;
	else if (strcmp(pSrc->DataType, "ARRAY") == 0)
		pSrc->nDataType = DA_DATATYE_ARRAY;
	else if (strcmp(pSrc->DataType, "STRUCT") == 0)
		pSrc->nDataType = DA_DATATYE_STRUCT;
	else if (strcmp(pSrc->DataType, "UTF8_STR") == 0)
		pSrc->nDataType = DA_DATATYE_UTF8_STR;
	else if (strcmp(pSrc->DataType, "BIT_STR") == 0)
		pSrc->nDataType = DA_DATATYE_BIT_STR;
	else if (strcmp(pSrc->DataType, "OCT_STR") == 0)//zhouhj 20180516 
		pSrc->nDataType = DA_DATATYE_OCTET_STR;
	else if (strcmp(pSrc->DataType, "V_STR") == 0)//zhouhj 20180516 
		pSrc->nDataType = DA_DATATYE_VISIBLE_STR;
	else if (strcmp(pSrc->DataType, "BYTE") == 0)
		pSrc->nDataType = DA_DATATYE_BYTE;
	else if (strcmp(pSrc->DataType, "UTCTIME") == 0)
		pSrc->nDataType = DA_DATATYE_UTC_TIME;
	else if (strcmp(pSrc->DataType, "UBYTE") == 0)
		pSrc->nDataType = DA_DATATYE_UBYTE;
	else if (strcmp(pSrc->DataType, "OVSTRING64") == 0)
		pSrc->nDataType = DA_DATATYE_OVSTRING64;
	else if (strcmp(pSrc->DataType, "BVSTRING2") == 0)
		pSrc->nDataType = DA_DATATYE_BVSTRING2;
	else
	{
		sprintf(buff_mms_err_text, "mms_InitDA_DataType[%s]", pSrc->DataType);
		func_mms_log_error_infor();

		pSrc->nDataType = DA_DATATYE_UINT;
	}
}

#endif

/************************************************************************/
/*			u_iec_rpt_ind												*/
/* This function processes ONLY IEC-61850 and UCA Reports. If any		*/
/* other InformationReport is received, it logs an error message and	*/
/* ignores it.															*/
/* CRITICAL: this function assumes that a RCB_INFO structure has been	*/
/*	created and a pointer to it has been saved in the					*/
/*	user_info member of the MVL_NET_INFO structure for this conn.		*/
/************************************************************************/
#define  rptID_max_len   60

#define _use_cal_tick_count
ST_RET u_mvl_info_rpt_ind (MVL_COMM_EVENT *pEvent)
{
	INFO_REQ_INFO *info_ptr;
	ST_INT j;
	ST_UINT16 OptFldsData;		/* ptr to data part of OptFlds bvstring	*/
	ST_UINT8 InclusionData[1000];	/* ptr to Inclusion bstring		*/
	ST_CHAR  rptID[NAMESIZE];
	ST_CHAR  DataSetName[NAMESIZE];
	ACCESS_RESULT *ar_ptr;
	ST_CHAR *ar_ptr_end;
	ST_INT len;
	ST_INT offset;
	ST_INT numDsVar=0;
	ST_INT numDA=0;
	ST_UCHAR *cptr;
	ST_UCHAR **lpRptDT;
	ST_RET ret=SD_FAILURE;
	ST_INT startMember=0;
	ST_INT EventNum=0;
	tagDA *pTagDA = NULL;
	LD_NODE *pLD = NULL;
	ST_UCHAR EntryID[NAMESIZE];
	ST_INT daindex[MAX_DA_NUM];
	ST_INT nAcsi = pEvent->net_info->nACSI;
	long nRptCount = 0;
	long nCurrRptIndex = 0;
	ST_INT nDsIndex = -1;
	ST_INT nLdIndex = -1;
	ST_BOOLEAN bFind = SD_FALSE;

	LD_NODE *pLD2 = NULL;
	long nLdIndex2 = 0;
	long numDA2 = 0;
	tagDA *pTagDA2 = NULL;
	long nDsIndex2 = 0;

	WPARAM wParam = 0;//
	LPARAM lParam = 0;
	tagRpt *pReports = NULL;
	double dTime=0;
	int nTmMs = 0;

#ifdef _use_cal_tick_count
	DWORD dwBegin = 0, dwEnd = 0;
#endif

	if (g_nStopProtocolParseFlag == 1)
	{
		return SD_SUCCESS;
	}

	ZeroMemory(rptID,NAMESIZE);
	memset(EntryID,0,NAMESIZE);
	memset(daindex,0,sizeof(ST_INT)*MAX_DA_NUM);
	memset(InclusionData,0,sizeof(ST_UINT8)*100);
	
#ifdef _use_cal_tick_count
	dwBegin=GetTickCount();
#endif

 	if (SD_TRUE != acsi_ctrl_table[nAcsi].bShow)
 		return SD_FAILURE;

	info_ptr = (INFO_REQ_INFO *) pEvent->u.mms.dec_rslt.data_ptr;

	ar_ptr = info_ptr->acc_rslt_list;
	ar_ptr_end = pEvent->u.mms.pdu + pEvent->u.mms.pdu_len;

	//报告控制块ID
	//8a 19 50 52 4f 54 2f 4c 4c 4e 30 24 42 52 24 62 72 63 62 54 72 69 70 49 6e 66 6f
	//PROT/LLN0$BR$brcbTripInfo
	if (ar_ptr->va_data.data[0]==0x8a)
	{
		offset = sym_get_length(ar_ptr->va_data.data+1, &len);
		sym_get_vstr (ar_ptr->va_data.data+1+offset, rptID, NAMESIZE, len);
	}
	 else if (ar_ptr->va_data.data[0]==0xa2)  //Unconfirmed: InformationReport   zhouhj 20201107 在控制类信号写失败，上送的报文
	{
		offset = sym_get_length(ar_ptr->va_data.data+1, &len);

		if (ar_ptr->va_data.data[len+offset-1] == 1)
		{
			g_nCurErrorInforRpt = ar_ptr->va_data.data[len+offset];
		} 

		return SD_FAILURE;
	}
	else
	{
		return SD_FAILURE;
	}

	if (strstr(rptID, "NULL") != 0)
	{
		if (func_mms_log_error_infor != NULL)
		{
			sprintf(buff_mms_err_text, "Error:RptID=%s", rptID);
			func_mms_log_error_infor();
		}

		bFind = SD_FALSE;
	}
	else
	{
		//关联数据集pTagDA
		if (My_Pare_RptID(pEvent->net_info->nACSI, &pLD, &numDA, &pTagDA, &nDsIndex,&nLdIndex, rptID)!=SD_SUCCESS)
		{
			if (func_mms_log_error_infor != NULL)
			{
				sprintf(buff_mms_err_text, "报告控制块rptID=[%s]没有找到", rptID);
				func_mms_log_error_infor();
			}

			bFind = SD_FALSE;
		}
		else
		{
			bFind = SD_TRUE;
		}
	}

	if (strstr(rptID,"LEDRs$Oper"))
		return SD_FAILURE;

	cptr = ar_ptr->va_data.data+1+len+offset;

	if (cptr[0] == 0x84)
	{
		offset = sym_get_length(cptr+1, &len);
		sym_get_bitstr ( (ST_UCHAR*)(cptr+1+offset), (ST_UCHAR*)(&OptFldsData), 10, len);
	}
	else
	{
		sprintf(buff_mms_err_text, "if (cptr[0] != 0x84)[%s]", rptID);
		func_mms_log_error_infor();

		return SD_FAILURE;
	}

	/* NOTE: Don't change initial entries in "info_va". Add these right after "OptFlds".*/
	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_SQNUM))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
	}

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_TIMESTAMP))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
	}

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_DATSETNAME))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
		ZeroMemory(DataSetName,NAMESIZE*sizeof(ST_CHAR));
		sym_get_vstr (cptr+1+offset, DataSetName, NAMESIZE, len);
	}

	// 2013-5-8  如果从 rtptID 中未找到对应的数据集
	if (bFind == SD_FALSE)
	{
		if (My_Pare_DataSet(pEvent->net_info->nACSI, &pLD, &nLdIndex, &numDA, &pTagDA, &nDsIndex, DataSetName) !=SD_SUCCESS) 
		{
			sprintf(buff_mms_err_text, "报告控制块dataset=[%s]没有找到", DataSetName);
			func_mms_log_error_infor();
			return SD_FAILURE;
		}
	}
	else
	{
		if (My_Pare_DataSetEx(pEvent->net_info->nACSI, &pLD2, &nLdIndex2, &numDA2, &pTagDA2, &nDsIndex2, DataSetName) == SD_SUCCESS) 
		{
			if (pLD2 != pLD)
			{
				pLD = pLD2;
				nLdIndex = nLdIndex2;
				numDA = numDA2;
				pTagDA = pTagDA2;
				nDsIndex = nDsIndex2;
			}
		}
	}

	if (pTagDA == NULL)
	{//2015-4-17
		sprintf(buff_mms_err_text, "报告控制块dataset=[%s]没有找到", DataSetName);
		func_mms_log_error_infor();

		return SD_FAILURE;
	}
	else
	{
		LD_NODE *pLDNew = &pACSINode[pEvent->net_info->nACSI].LD[nLdIndex];
		LD_DATASET_INFO	*pNewDataInfo = &pLDNew->DataInfo[nDsIndex];
		sprintf(buff_mms_err_text, "逻辑设备 %s 下的 %s 数据集关联的报告控制块 %s ", pLDNew->LDName, pNewDataInfo->DataSetID,pNewDataInfo->RCB->rcbName);//zhow20180109 细化报告内容
//		sprintf(buff_mms_err_text, "报告控制块LD=%d  DS=%d", nLdIndex, nDsIndex);
//		func_mms_log_error_infor();//zhow20180110 上面if中是出错，然后这边一定会有，故将其去掉
	}

	if (BSTR_BIT_GET (&OptFldsData, OPTFLD_BITNUM_BUFOVFL))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
	}

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_ENTRYID))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
		pReports = pACSINode[pEvent->net_info->nACSI].Reports;
		nCurrRptIndex = pACSINode[pEvent->net_info->nACSI].nCurrReportIndex;
		sym_get_vstr (cptr+1+offset, EntryID, MAX_DSNAME, len);
		memcpy(pReports[nCurrRptIndex].EntryID,EntryID ,8);
	}

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_CONFREV))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
	}

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_SUBSEQNUM))
	{
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
		cptr = cptr + 1 + offset +len;
		offset = sym_get_length(cptr+1, &len);
	}

	/* Perform 2nd decode (up through "Inclusion").	*/
	cptr = cptr + 1 + offset +len;
	if (cptr[0] == 0x84)
	{
		offset = sym_get_length(cptr+1, &len);
		sym_get_bitstr (cptr+1+offset, InclusionData, 380, len);
		numDsVar = sym_get_da_index(cptr+1+offset, daindex, 380, len);
	}
	else
	{
		return SD_FAILURE;
	}

	cptr = cptr+1+offset+len;

	if (BSTR_BIT_GET(&OptFldsData, OPTFLD_BITNUM_DATAREF))
	{
		for (j = 0; j < numDsVar; ++j)
		{
			if (cptr[0] == 0x8A)
			{
				offset = sym_get_length(cptr+1, &len);
				cptr = cptr+1+offset+len;
			}
		}
	}

	if (numDsVar > 0)
	{
		lpRptDT = &cptr; 
		if (BSTR_BIT_GET (&OptFldsData,OPTFLD_BITNUM_REASON))
			startMember = DecodeReasonCode(daindex, numDA, lpRptDT, numDsVar);

		if (startMember < 0)
		{
			return SD_FAILURE;
		}

		for (j=0; j<numDA; j++)
		{
			if (daindex[j]==1)
				pTagDA[j].ReasonCode = ReasonCode[startMember];
		}

		//事件数目
		EventNum = DifEventFromVar_Ex(pTagDA, daindex, numDsVar, numDA);

		if (EventNum == -1 || numDA <= 0)
		{
			return SD_SUCCESS;
		}

		lpRptDT = &cptr; 

		if (DecodeData_Ex(InclusionData, daindex, numDA, numDsVar, pTagDA, lpRptDT, ar_ptr_end) != SD_SUCCESS)
		{
			return SD_SUCCESS;
		}

		if (*lpRptDT > ar_ptr_end)
		{
			if (func_mms_log_error_infor != 0)
			{
				sprintf(buff_mms_err_text, "DecodeData_Ex:Error RptID[%s] Dataset=[%s]", rptID, DataSetName);
				func_mms_log_error_infor();
			}
		}

		/* 缓存报告记录 */
		nCurrRptIndex = pACSINode[nAcsi].nCurrReportIndex;
		nRptCount = pACSINode[nAcsi].nCurrReportCount;
		pReports = pACSINode[nAcsi].Reports;

		if (g_n_mms_Add_DA_To_Rpts == 1)
		{
			enter_u_mvl_rpt_CriticSection();
			GeCurrTime_double(&dTime,&nTmMs);

			for (j=0; j<numDA; j++)
			{
				if (daindex[j]==1)
				{
					mms_Add_DA_To_Rpts(pReports, &pTagDA[j], &nCurrRptIndex, nAcsi
						, nLdIndex, nDsIndex, &nRptCount, j, dTime,nTmMs);
					memcpy(pReports[nCurrRptIndex].EntryID,pReports[pACSINode[nAcsi].nCurrReportIndex].EntryID,8);
				}
			}

			/* 创建报告结果通知事件 */
			wParam = nAcsi + (numDsVar << 16);//
			lParam = ((unsigned short)pACSINode[nAcsi].nCurrReportIndex) + (((unsigned short)nCurrRptIndex) << 16);
			pACSINode[nAcsi].nCurrReportCount = nRptCount;	
			pACSINode[nAcsi].nCurrReportIndex = nCurrRptIndex;	
		
// 			sprintf(buff_mms_err_text, "报告缓冲区nRptCount=%d nCurrRptIndex=%d", nRptCount, nCurrRptIndex);
// 			func_mms_log_error_infor();

			free_u_mvl_rpt_CriticSection();
		}
		else
		{
			wParam = nAcsi + (numDsVar << 16);//
			lParam = 0;
		}

		PostMessageA((HWND)(pACSINode[nAcsi].hRptMsgWnd), pACSINode[nAcsi].nRptMsg, wParam, lParam);
	}
	else
	{
		nRptCount = 0;
	}

#ifdef _use_cal_tick_count
	dwEnd=GetTickCount();
	dwEnd = dwEnd - dwBegin;

	if (dwEnd > 50)
	{
		sprintf(DataSetName, "u_mvl_info_rpt_ind(%d,%d,%d)=%d ms", nAcsi, nLdIndex, nDsIndex,dwEnd);
		mvl_log_err_ex(DataSetName, TRUE);
	}
#endif

	return SD_SUCCESS;
}


void mms_Add_DA_To_Rpts(tagRpt *pReports, tagDA *pTagDA, long *pnCurrRptIndex
						, long nAcsi, long nLdIndex, long nDsIndex
						, long *pnRptCount, long nDaIndex, double dTime, int nTmMs)
{
	//mms_ReleaseDataRpt(&pReports[*pnCurrRptIndex].DA);

	pReports[*pnCurrRptIndex].dvIndex = nAcsi;	
	pReports[*pnCurrRptIndex].ldIndex = nLdIndex;	
	pReports[*pnCurrRptIndex].dsIndex = nDsIndex;	

	mms_CopyDataRpt(pTagDA, &pReports[*pnCurrRptIndex]);

	//2015-3-26发送消息
	mms_FireDataChangedMsg(nAcsi, nLdIndex, nDsIndex, nDaIndex);

	pReports[*pnCurrRptIndex].tmRcv = dTime;
	pReports[*pnCurrRptIndex].nTmRcvMs = nTmMs;

	*pnRptCount = *pnRptCount + 1;
	*pnCurrRptIndex = *pnCurrRptIndex + 1;

	if (*pnRptCount > g_nMaxReportCount)//MAX_REPORT_COUNT) //2018-9-30
	{
		*pnRptCount = g_nMaxReportCount;//MAX_REPORT_COUNT;
	}
	if (*pnCurrRptIndex >= g_nMaxReportCount)//MAX_REPORT_COUNT)
	{
		*pnCurrRptIndex = 0;
	}
}

ST_INT sym_get_length(ST_UCHAR * r_asn1buf, ST_INT *ptr)
{
	ST_UCHAR tmpByte;
	ST_INT len = 0;
	ST_INT offset = 0;

	tmpByte = *r_asn1buf;
	if(tmpByte & 0x80)
	{
		tmpByte &= 0x7f;
		r_asn1buf += tmpByte;
		if(tmpByte == 0x01)
		{
			len = (ST_UCHAR)(*(r_asn1buf + 1));
			offset=2;
		}
		else if(tmpByte == 0x02)
		{
			*((ST_UCHAR *)&len) = *(r_asn1buf + 1);
			*((ST_UCHAR *)&len + 1) = *(r_asn1buf + 2);
			offset=3;
		}
	}
	else
	{
		len = (ST_UCHAR)(*r_asn1buf);
		offset = 1;
	}
	*ptr = len;
	return offset;
}

ST_INT sym_get_vstr (ST_UCHAR * r_asn1buf, ST_UCHAR *vstr_ptr, ST_INT maxchars, ST_INT len)
{
	ST_INT  accepted_chars;

	if (maxchars != 0  &&  len > maxchars)
		accepted_chars = maxchars;	/* truncated */
	else
		accepted_chars = len;
	memcpy (vstr_ptr, r_asn1buf, accepted_chars);
	return accepted_chars;
}

// 2012-11-08 
ST_INT sym_get_da_index(ST_UCHAR * r_asn1buf, ST_INT *daindex, ST_INT max_bits, ST_INT len)
{
	ST_INT unused_bits;
	ST_INT used_bits;

	ST_INT i,k;
	ST_INT count=0, usenum=0;
	ST_UCHAR bytedata;

	unused_bits = *r_asn1buf++;
	if (max_bits == 10)
		unused_bits = 6;

	/* Return error code for bad unused-bits value.	*/
	if (unused_bits>7 || unused_bits<0)
		return 0;

	if (len > 1)
	{
		used_bits = ((len-1)*8 - unused_bits); /* Compute # data bits. */

		for (i=len-1; i>0; i--)
		{
			bytedata = *r_asn1buf++;
			for (k=8; k>0; k--)
			{
				if (count < used_bits)
				{
					if (bytedata&(1<<(k-1)))
					{
						daindex[count] = 1;
						usenum++;
					}

					count++;
				}
				else
					return usenum;
			}
		}
	}
	
	return usenum;
}

// 2012-11-08 
ST_INT sym_get_bitstr(ST_UCHAR * r_asn1buf, ST_UCHAR *bit_ptr, ST_INT max_bits, ST_INT len)
{
	ST_INT unused_bits;
	ST_INT used_bits;
	ST_INT accepted_bits;
	char pszErrorMsg[100];

	unused_bits = *r_asn1buf++;
	if(max_bits==10)
		unused_bits = 6;

	/* Return error code for bad unused-bits value.	*/
	if(unused_bits>7 || unused_bits<0)
		return 0;
	if(len == 1)
	{
		bit_ptr[0] = 0;
		return 0;
	}
	else
	{
		used_bits = ((len-1)*8 - unused_bits); /* Compute # data bits.	*/

		/* If caller imposed a limit, truncate. */
		if (max_bits != 0  &&  used_bits > max_bits)
		{
			accepted_bits = max_bits;	/* truncated */
			sprintf(pszErrorMsg, "--------------------------------------------  used_bits(%d) > max_bits(%d)",used_bits, max_bits);
			mvl_log_err(pszErrorMsg);
		}
		else
			accepted_bits = used_bits;

		/* Copy bitstring to user buffer */
		bstrcpy (bit_ptr, r_asn1buf, accepted_bits);
		return accepted_bits;
	}
}

//////////////////////////////////////////////////////////////////////////
//************************************************************************
//2013-6-14
#ifdef _use_dynamic_mem

ST_VOID mms_Free_tagDA(tagDA*pData)
{
	mms_ReleaseData(pData);
//	ST_INT i=0;
// 	mms_str_quit(&pData->DAValue.mmsName);
// 	mms_str_quit(&pData->DADescri.mmsName);
// 	mms_str_quit(&pData->DAUnite.mmsName);
// 	mms_str_quit(&pData->MaxVal.mmsName);
// 	mms_str_quit(&pData->MinVal.mmsName);
// 	mms_str_quit(&pData->StepSize.mmsName);
// 
// 	if (pData != NULL)
// 	{
// 		for (i=0;i<pData->nSubDANum;i++)
// 		{
// 			if (pData->pSubDA[i].pSubDA!=NULL)
// 				mms_ReleaseData(&pData->pSubDA[i]);
// 		}
// 
// 		free(pData->pSubDA);
// 		pData->pSubDA = NULL;
// 	}
}

void mms_Free_tagDAs(tagDA *pTagDAs, ST_INT nCount)
{
	ST_INT nIndex=0;

	if (pTagDAs == NULL)
	{
		return;
	}

	for (nIndex=0; nIndex<nCount; nIndex++)
	{
		mms_Free_tagDA(&pTagDAs[nIndex]);
	}
}

void mms_Free_LD_DATASET_INFO(LD_DATASET_INFO *pDataSet)
{
	if (pDataSet == NULL)
	{
		return;
	}

	mms_Free_tagDAs(pDataSet->DataSet, pDataSet->numData);

	if (pDataSet->DataSet != NULL)
	{
		free(pDataSet->DataSet);
		pDataSet->numData = 0;
		pDataSet->DataSet = NULL;
	}
}

void mms_Free_LD_DATASET_INFO_Ex(LD_DATASET_INFO *pDataSet)
{
	if (pDataSet == NULL)
	{
		return;
	}

	//mms_Free_tagDAs(pDataSet->DataSet, pDataSet->numData);
	//free(pDataSet->DataSet);
	mms_Free_LD_DATASET_INFO(pDataSet);
	free(pDataSet);
}

void mms_New_LD_DATASET_INFO_numData(LD_DATASET_INFO *pDataSet, ST_INT numData)
{
	if (pDataSet == NULL)
	{
		return;
	}

	mms_Free_LD_DATASET_INFO(pDataSet);

	if ( (pDataSet != NULL) && (numData > 0) )
	{
		ST_INT nSize = sizeof(tagDA) * numData;
		pDataSet->DataSet = (tagDA *)malloc(nSize);
		ASSERT (pDataSet->DataSet != NULL);

		if (pDataSet->DataSet != NULL)
		{
			memset(pDataSet->DataSet, 0, nSize);
			pDataSet->numData = numData;
			mms_InitDatas(pDataSet->DataSet, numData);
		}
	}
}

void mms_New_LD_JOURNAL_CTRLS_numData(LD_JOURNAL_CTRLS *pJournal, ST_INT numData)
{
	if (pJournal == NULL)
	{
		return;
	}

	mms_Free_LD_JOURNAL_CTRLS(pJournal);

	if ( (pJournal != NULL) && (numData > 0) )
	{
		ST_INT nSize = sizeof(LD_LOG_INFO) * numData;
		pJournal->LogInfo = (LD_LOG_INFO *)malloc(nSize);
		ASSERT (pJournal->LogInfo != NULL);

		if (pJournal->LogInfo != NULL)
		{
			memset(pJournal->LogInfo, 0, nSize);
			pJournal->numData = numData;
		}
	}
}

void mms_New_LD_DATASET_INFO_numData_Ex(LD_DATASET_INFO **ppDataSet, ST_INT numData)
{
	if (*ppDataSet != NULL)
	{
		mms_Free_LD_DATASET_INFO_Ex(*ppDataSet);
		*ppDataSet = NULL;
	}

	*ppDataSet = (LD_DATASET_INFO*)malloc(sizeof(LD_DATASET_INFO));
	memset(*ppDataSet, 0, sizeof(LD_DATASET_INFO));

	mms_New_LD_DATASET_INFO_numData(*ppDataSet, numData);
}

ST_VOID mms_Free_Data_Node(MMS_DATA_NODE *p_mms_data_node)
{
	MMS_DATA_NODE *pCurr = p_mms_data_node;
	MMS_DATA_NODE *pNext = NULL;

	if (p_mms_data_node == NULL)
	{
		return;
	}

	pNext = pCurr->pNext;

	do 
	{
		mms_Free_Data_Node(pCurr->pFirstChild);
		pNext = pCurr->pNext;
#ifdef _use_mms_string
		mms_str_quit(&pCurr->name);
#endif

		free(pCurr);
		pCurr = pNext;
	}while (pCurr != NULL);
}

ST_VOID mms_Free_ValueEx(tagDAValueEx *pValueEx)
{
#ifdef _use_mms_string
	if (mms_IsDataTypeString(mms_string(&pValueEx->DataType)))
	{
		mms_str_quit(&pValueEx->Value.string);
	}

	mms_str_quit(&pValueEx->DataType);
	mms_str_quit(&pValueEx->mmsName);
#endif
}

ST_VOID mms_Free_Journal(LD_LOG_INFO *Journal)
{
	MMS_TAGDA_LIST_NODE *pList = NULL;
	MMS_TAGDA_LIST_NODE *p = NULL;

	if (Journal == NULL)
	{
		return;
	}

#ifdef _use_mms_string
	mms_str_quit(&Journal->Name);
#endif

//	mms_str_quit(&Journal->Descri);
	mms_str_quit(&Journal->Dataset);
//	mms_str_quit(&Journal->intgPD);
	mms_str_quit(&Journal->logRef);
//	mms_str_quit(&Journal->logEna);
//	mms_str_quit(&Journal->trgOps);

// 	pList = Journal->pList;
// 
// 	if (pList == NULL)
// 	{
// 		return;
// 	}
// 
// 	p = pList;
// 
// 	while (p != NULL)
// 	{
// 		mms_Free_tagDA(p->DA);
// 		free(p->DA);
// 
// 		p = p->pNext;
// 
// 		if (p == pList)
// 		{
// 			break;
// 		}
// 	}
}

ST_VOID mms_Free_LD_JOURNAL_CTRLS(LD_JOURNAL_CTRLS *pJournal)
{
	ST_INT nDataset;
	if (pJournal == NULL)
	{
		return;
	}

	if (pJournal->LogInfo != NULL)
	{
		for (nDataset= 0;nDataset<pJournal->numData;nDataset++)
			mms_Free_Journal(&pJournal->LogInfo[nDataset]);

		free (pJournal->LogInfo);
	}

	pJournal->numData = 0;
}

ST_VOID mms_Free_LD_NODE(LD_NODE *pLdevice)
{
	ST_INT nDataset = 0;

	if (pLdevice == NULL)
	{
		return;
	}

	for (nDataset=0; nDataset<pLdevice->numDaSet; nDataset++)
	{
		mms_Free_LD_DATASET_INFO(pLdevice->DataInfo+nDataset);
	}

	mms_Free_LD_JOURNAL_CTRLS(&pLdevice->JournalCtrls);
	mms_JournalDataOfVector_Free(pLdevice->JournalDatas.Datas,pLdevice->JournalDatas.numOfData);
	vector_free(&pLdevice->JournalDatas);

	mms_Free_Data_Node(pLdevice->mms_data_node);

	if (pLdevice->DataInfo != NULL)
	{
		free(pLdevice->DataInfo);
		pLdevice->DataInfo = NULL;
	}
}

ST_VOID mms_Free_LD_NODE_Ex(LD_NODE *pLdevice)
{
	if (pLdevice == NULL)
	{
		return;
	}

	mms_Free_LD_NODE(pLdevice);
	free(pLdevice);
}

ST_VOID mms_New_LD_NODE_numDataset(LD_NODE *pLdevice, ST_INT numDataset)
{
	ST_INT nSize;
	mms_Free_LD_NODE(pLdevice);

	nSize = numDataset * sizeof(LD_DATASET_INFO);

	if (nSize > 0)
	{
		pLdevice->DataInfo = (LD_DATASET_INFO*)malloc(nSize);
		memset(pLdevice->DataInfo, 0, nSize);
	}

	pLdevice->numDaSet = numDataset;
}

//2018.1.17zhouhj
ST_VOID mms_New_LD_NODE_numJournal(LD_NODE *pLdevice, ST_INT numJournal)
{
	ST_INT nSize;

	if (pLdevice == NULL)
	{
		return;
	}

	if (pLdevice->JournalCtrls.LogInfo != NULL)
	{
		for (nSize= 0;nSize<pLdevice->JournalCtrls.numData;nSize++)
		{
			mms_Free_Journal(&pLdevice->JournalCtrls.LogInfo[nSize]);
		}

		pLdevice->JournalCtrls.numData = 0;
	}

	nSize = numJournal * sizeof(LD_LOG_INFO);

	if (nSize > 0)
	{
		pLdevice->JournalCtrls.LogInfo = (LD_LOG_INFO*)malloc(nSize);
		memset(pLdevice->JournalCtrls.LogInfo, 0, nSize);
	}

	pLdevice->JournalCtrls.numData = numJournal;
}

ST_VOID mms_New_LD_NODE_numDataset_Ex(LD_NODE **ppLdevice, ST_INT numDataset)
{
	mms_Free_LD_NODE_Ex(*ppLdevice);
	*ppLdevice = (LD_NODE *)malloc(sizeof(LD_NODE));
	memset(*ppLdevice, 0, sizeof(LD_NODE));

	mms_New_LD_NODE_numDataset(*ppLdevice, numDataset);
}

ST_VOID mms_Free_ACSI_NODE(ACSI_NODE *pDevice)
{
	ST_INT nLdIndex = 0;
	ST_INT nIndex=0;

	if (pDevice == NULL)
	{
		return;
	}

	for (nLdIndex=0; nLdIndex<pDevice->numLD; nLdIndex++)
	{
		mms_Free_LD_NODE(pDevice->LD+nLdIndex);
	}

	if (pDevice->LD != NULL)
	{
		free(pDevice->LD);
		pDevice->LD = NULL;
	}

	if (pDevice->nCurrReportCount > 0)
	{
		for (nIndex=0; nIndex<pDevice->nCurrReportCount; nIndex++)
		{
			rpt_quit(&pDevice->Reports[nIndex]);
		}
	}

	mms_file_sys_free(&pDevice->FileDir);
	mms_str_quit(&pDevice->RcdFilePath);
	mms_str_quit(&pDevice->IpAddr);
}

ST_VOID mms_file_sys_free(XMMS_FILE_SYS_OBJ *pMmsFileSysObj)
{
	XMMS_FILE_SYS_OBJ *pSubFileDir = NULL;
	int nIndex = 0;
	mms_str_quit(&pMmsFileSysObj->filedir.filename);

	for(nIndex = 0;nIndex<pMmsFileSysObj->subFiles.numOfData;nIndex++)
	{
		pSubFileDir = (XMMS_FILE_SYS_OBJ *)*(pMmsFileSysObj->subFiles.Datas + nIndex);
		mms_file_sys_free(pSubFileDir);
		free(pSubFileDir);
	}

	vector_free(&pMmsFileSysObj->subFiles);
}

//zhouhj20180309 用来释放容器存储的日志对象
ST_VOID mms_JournalDataOfVector_Free(unsigned long* pJournalDatas,ST_INT nNumOfData)
{
	ST_INT nTmp;
	LD_JOURNAL_DATA *pJournalData = NULL;
	for (nTmp = 0;nTmp<nNumOfData;nTmp++)
	{
		pJournalData = *(pJournalDatas + nTmp/**sizeof(unsigned long)*/);//??????zhouhj 指针加1 为什么就是4个字节了？？？？？
		if (pJournalData != NULL)
		{
			mms_Free_tagDAs(pJournalData->DAValue,pJournalData->numData);

			if (pJournalData->DAValue != NULL)
			{
				free(pJournalData->DAValue);
				pJournalData->DAValue = NULL;
			}

			mms_str_quit(&pJournalData->LogCtrl);
			mms_str_quit(&pJournalData->DataSetName);
			free(pJournalData);
		}
	}
}

ACSI_NODE* mms_New_ACSI_NODE_numLD(ACSI_NODE *pDevice, ST_INT numLD, BOOL bDelete)
{
	ST_INT nSize = 0;
	ACSI_NODE *pBack = NULL;

	if (pDevice == NULL)
	{
		return NULL;
	}

	nSize = numLD * sizeof(LD_NODE);

	if (bDelete)
	{
		mms_Free_ACSI_NODE(pDevice);
	}
	else
	{
		pBack = (ACSI_NODE *)malloc(sizeof(ACSI_NODE));
		pBack->LD = pDevice->LD;
		pBack->numLD = pDevice->numLD;
		pDevice->numLD = 0;
		pDevice->LD = NULL;
	}

	pDevice->LD = (LD_NODE *)malloc(nSize);
	memset(pDevice->LD, 0, nSize);
	pDevice->numLD = numLD;

	return pBack;
}

#endif

//************************************************************************
//////////////////////////////////////////////////////////////////////////

