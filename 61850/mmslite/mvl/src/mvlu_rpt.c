/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	       1998 - 2006, All Rights Reserved.		*/
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : mvlu_rpt.c						*/
/* PRODUCT(S)  : MMSEASE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/16/07  JRB     59    Fix Resv init in ..urcb_handle_rptena_wr.	*/
/* 02/28/07  JRB     58    DO NOT PurgeBuf when OptFlds is changed.	*/
/*			   PurgeBuf when RptID, DatSet, BufTm, TrgOps,	*/
/*			   or IntgPd is changed (tissue 322 final text).*/
/* 02/13/07  JRB     57    mvl61850_get_rcb: del unused net_info arg.	*/
/*			   Chk net_info before trying to find UCA RCB.	*/
/*			   Add _rcb_writable & use it.			*/
/* 12/20/06  JRB     56    PurgeBuf only if val changed (tissue 322).	*/
/*			   PurgeBuf also when BufTm written.		*/
/* 10/30/06  JRB     55    Use new mvl_vmd_* object handling functions.	*/
/*			   u_mvl_get_va_aa: add args.			*/
/*			   Add mvlu_rpt_ctrl_destroy_all		*/
/* 09/13/06  JRB     54    mvlu_rpt_find_typeids: simplify.		*/
/* 08/09/06  JRB     53    If report buffered because of BufTm, send it	*/
/*			   BEFORE any Integrity report.			*/
/* 08/09/06  JRB     52    mvlu_create_rpt_ctrl, mvlu_free_rpt_ctrl,	*/
/*			   mvlu_rpt_service now ONLY for UCA (for 61850,*/
/*			   use new functions in mvl61850_rpt.c).	*/
/*			   Del brcb_enable_allowed (not needed now that	*/
/*			    segmenting done only when sending).		*/
/*			   Reset SqNum=0 when BRCB enabled.		*/
/*			   PurgeBuf when DatSet,OptFlds,TrgOps,IntgPd	*/
/*			    or RptID written.				*/
/*			   Reserve BRCB only when RptEna written (chged	*/
/*			    mvlu_get_wr_rcb, mvlu_rptena_wr_ind_fun).	*/
/*			   mvlu_rpt_find_typeids: create if not found.	*/
/*			   Add mvlu_rpt_ready, mvlu_rpt_rcb_type_find.	*/
/*			   Chg some static functs to extern.		*/
/* 07/27/05  JRB     51    mvlu_optflds_wr..: use rcb_type to figure	*/
/*			   out which bits are writable.			*/
/* 06/27/05  JRB     50    brcb_enable_allowed: reset netInfo on error.	*/
/* 06/27/05  JRB     49    Simplify allocation by deleting all use of	*/
/*			   MVLU_RPT_VA_CTRL & va->mvl_internal & moving	*/
/*			   last_data to MVL_VAR_ASSOC struct.		*/
/*			   Del mvlu_rpt_nvl_add/destroy, use mvl_nvl_add*/
/*			   Del unused mvlu_resolve_uca_nvl.		*/
/* 06/27/05  JRB     48    _mvlu_get_rd_rcb: add (MVLU_RPT_CLIENT **) arg*/
/* 05/24/05  CRM     47	   Added mvlu_rpt_destroy_scan_ctrl		*/
/* 05/16/05  JRB     46    Set failure=ARE_TEMP_UNAVAIL when trying to	*/
/*			   write RCB elements while RptEna=TRUE.	*/
/* 05/09/05  JRB     45    Chk Integrity bit in TrgOps, as we did	*/
/*			   BEFORE change on 03/13/03 (61850 requires it)*/
/* 08/16/04  JRB     44    Reset SqNum when URCB is enabled.		*/
/* 07/20/04  JRB     43    ..chk_reason: make sure OLD data sent in	*/
/*			   first rpt when 2nd change detected.		*/
/* 07/07/04  JRB     42    ..chk_reason: for URCB or BRCB, call		*/
/*			   mvl61850_rcb_build (NOT mvlu_send_report).	*/
/* 07/06/04  JRB     41    Add client for BRCB only when needed,	*/
/*			   allows BRCB initial values to be set first.	*/
/*			   Add mvlu_rpt_create_scan_ctrl2.		*/
/* 06/29/04  JRB     40    mvlu_rpt_nvl_add: alloc new buffer for	*/
/*			   va->data ONLY if use_static_data==FALSE.	*/
/* 12/17/03  JRB     39    61850-8-1 FDIS changes:			*/
/*			   Increase num bits in OptFlds to 10 for ConfRev.*/
/*			   Find type RTYP_INT32U for ConfRev.		*/
/* 05/02/03  JRB     38    switch(rt->el_tag): Use default for most cases*/
/* 04/17/03  JRB     37    Add & use mvlu_setup_scan_read.		*/
/* 04/04/03  JRB     36    mvlu_rpt_va_change: save data at END of funct*/
/* 04/04/03  JRB     35    Fix integrity/GI scan code so multiple	*/
/*			   concurrent scans don't corrupt one another.	*/
/* 03/13/03  JRB     34    Add URCB support including Resv.		*/
/*			   Chg OptFlds back to 8 bits for UCA (9 for IEC).*/
/*			   Trigger Intg Rpt ONLY by setting IntgPd!=0.	*/
/*			   Increment SqNum after each report.		*/
/*			   Chg names in rpt_typeids struct (clearer).	*/
/*			   Fix _mvlu_rpt_find_rpt_va to set scope.	*/
/*			   Use tmp_va_arr for all rptNvl options.	*/
/*			   Simplify mvlu_rpt_va_change.			*/
/*			   Use domain name for NVL, not VA, in RptId string.*/
/*			   Chg TrgOps to Bvstring.			*/
/* 12/16/02  JRB     33    Chg args to mvlu_create_rpt_ctrl.		*/
/*			   Add mvlu_integrity_scan_* functions.		*/
/*			   Move some init/cleanup INTO mvlu_send_report.*/
/*			   Don't allow write of RCB if RptEna=TRUE.	*/
/*			   Use mvl_internal to AVOID conflict w/ user_info.*/
/*			   Write default RptID once in mvlu_create_rpt_ctrl*/
/*			   Start "automatic" scan when IntgPd expires.	*/
/*			   Use BSTR_BIT.. macros to access bitstring bits*/
/*			   Del buffer chain code.			*/
/*			   Del rptTim*, call usr func u_mvlu_rpt_time_get*/
/*			   Del outDat*, use basrcb->DatSetNa (same string)*/
/*			   Init OptFlds.len_1=8. Chg optflds_wr_ind_fun.*/
/*			   Del *typeId globals, use mvlu_rpt_find_typeids*/
/*			   Use BSTR_NUMBITS_TO_..			*/
/* 12/09/02  MDE     32    Removed need for primRef for reports		*/
/* 03/29/02  JRB     31    Fix crash if _mvl_objname_to_va returns NULL.*/
/* 12/12/01  MDE     30    Include mvl_defs.h instead of mvl_acse.h     */
/* 11/26/01  EJV     29    Added support for new MMS type UtcTime.	*/
/* 08/30/01  JRB     28    Fix "..sqnum_rd.." (chg UINT16 to UINT8).	*/
/* 12/21/00  JRB     27    Del return in main loop of mvlu_rpt_va_change*/
/* 10/25/00  JRB     26    Del u_mvl funct ptrs. Call functs directly.	*/
/* 09/08/00  JRB     25    Default to 10 second scan period.		*/
/* 07/13/00  JRB     24    Use new ms_comp_name_find to get comp names.	*/
/* 07/11/00  MDE     23    Changed seqNum to sqNum, made INT8U		*/
/* 05/01/00  JRB     22    Lint cleanup (uninitialized var).		*/
/* 03/10/00  JRB     21    Copy va_scope to appropriate structures.	*/
/* 03/07/00  MDE     20    Fixed integrity report problem  		*/
/* 01/21/00  MDE     19    Now use MEM_SMEM for dynamic memory		*/
/* 09/27/99  NAV     18	   Set OutData data for report			*/
/* 09/13/99  MDE     17    Added SD_CONST modifiers			*/
/* 09/07/99  MDE     16    Revised and enhanced the UCA report system	*/
/* 05/04/99  JRB     15    Fixed several write indication functions.	*/
/* 03/18/99  MDE     14    Changed for runtime connection limits	*/
/* 01/21/99  JRB     13    Del mvlu_create_nvl, mvlu_destroy_nvl. Call	*/
/*			   mvl_nvl_create, mvl_nvl_destroy instead.	*/
/* 12/11/98  MDE     12    Removed scope references from VA		*/
/* 11/16/98  MDE     11    Now use '_mvl_destroy_nvl_entries'		*/
/* 11/16/98  MDE     10    Renamed internal functions (prefix '_')	*/
/* 10/01/98  MDE     09    Changes to MVLU_RPT_CTRL rcb allocation	*/
/* 09/21/98  MDE     08    Minor lint cleanup				*/
/* 09/16/98  MDE     07    Moved RD/WR functions here from rdwrind.c	*/
/* 08/11/98  MDE     06    Changed 'mvlu_create_rpt_ctrl' parameters	*/
/* 07/13/98  MDE     05    We now use our own report control 		*/
/* 06/29/98  MDE     04    Moved report function pointers to mvl_uca.c	*/
/* 06/22/98  MDE     03    SeqNum now ST_UINT16				*/
/* 06/15/98  MDE     02    Changes to allow compile under C++		*/
/* 01/02/98  MDE     01    New						*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "glbsem.h"
#include "mmsdefs.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mvl_uca.h"
#include "mvl_log.h"

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/************************************************************************/
/************************************************************************/
/* These variables must be set by the user application, and select the 	*/
/* types to be used by the elements listed below.			*/

MVLU_RPT_CTRL *mvlu_rpt_ctrl_list;
MVLU_RPT_CTRL *mvl61850_rpt_ctrl_list;	/* List of only 61850 RCBs.	*/
MVLU_RPT_SCAN_CTRL *mvlu_rpt_scan_list;

/************************************************************************/

static MVLU_RPT_CLIENT *_mvlu_add_rpt_client (MVLU_RPT_CTRL *rptCtrl,
				              MVL_NET_INFO *netInfo);
static ST_VOID _mvlu_free_rpt_client (MVLU_RPT_CLIENT *rptClient);

static ST_VOID _mvlu_rpt_client_service (MVLU_RPT_CLIENT *rptClient,
				  ST_DOUBLE timeNow);

static ST_VOID _mvlu_rpt_va_reads_done (MVL_IND_PEND *indCtrl,
					MVL_VAR_ASSOC *va);

static ST_VOID _mvlu_get_rcb (MVL_VAR_ASSOC *baseVa,
			RUNTIME_TYPE *rt,
			MVL_NET_INFO *netInfo,
			MVLU_RPT_CTRL **rptCtrlOut,
			MVLU_RPT_CLIENT **rptClientOut);

static ST_RET _mvlu_count_rpt_var (RUNTIME_TYPE *rt, ST_INT numRt,
		    ST_INT *numRptVarOut, ST_INT *nameSizeOut);

static ST_RET _mvlu_fill_rpt_var (ST_CHAR *baseName, ST_CHAR *domName,
		   RUNTIME_TYPE *rt, ST_INT numRt,
                   ST_INT numObjNames, OBJECT_NAME *objNames,
		   ST_CHAR **nameBufPtr);

static ST_VOID _mvlu_rpt_va_chk_reason (MVLU_RPT_CLIENT *rptClient,
		MVL_VAR_ASSOC *va,
		ST_INT entry_num,
		ST_UCHAR reason);

/************************************************************************/
/************************************************************************/
/************************************************************************/
/* REPORT DATASET HANDLING						*/
/************************************************************************/
/************************************************************************/

/************************************************************************/
/*			mvlu_derive_rpt_ds 				*/
/************************************************************************/

MVL_NVLIST_CTRL *mvlu_derive_rpt_ds (ST_CHAR *domName, ST_CHAR *nvlName,
				     ST_INT numNodes, ST_CHAR **nodeNames)
  {
MVL_NVLIST_CTRL *nvl;
OBJECT_NAME nvlObjName;
OBJECT_NAME *objNames;
ST_RET rc;
ST_INT numDsVar;
ST_CHAR *nameBuf;


  rc = mvlu_derive_ds_va_names (domName, numNodes, nodeNames,
				 &numDsVar, &objNames, &nameBuf);
  if (rc != SD_SUCCESS)
    return (NULL);


/* Create the DataSet NVL */
  nvlObjName.object_tag = DOM_SPEC;
  nvlObjName.domain_id = domName;
  nvlObjName.obj_name.item_id = nvlName;

/* Add the DataSet NVL to the MVL data structures */
  nvl = mvl_vmd_nvl_add (&mvl_vmd,
            &nvlObjName,	/* NVL "object name"	*/
            NULL,		/* MVL_NET_INFO not used	*/
            numDsVar, 		/* num of variables			*/
            objNames,		/* array of var "object names"		*/
            SD_TRUE);		/* copy nvl name to new nvl.		*/

  M_FREE (MSMEM_GEN, nameBuf);
  M_FREE (MSMEM_GEN, objNames);
  return (nvl);
  }

/************************************************************************/
/************************************************************************/


typedef struct
  {
  MVL_VAR_ASSOC *nodeVa;
  ST_INT num_rpt_var;
  RUNTIME_TYPE *rt;
  ST_INT numRt;
  } _MVLU_RPT_DS_NODE_INFO;

ST_RET mvlu_derive_ds_va_names (ST_CHAR *domName,
       			        ST_INT numNodes, ST_CHAR **nodeNames,
				ST_INT *numObjNamesOut,
				OBJECT_NAME **objNameTblOut,
				ST_CHAR **nameBufOut)
  {
OBJECT_NAME nodeObjName;
OBJECT_NAME *objNames;
OBJECT_NAME *objNameDest;
_MVLU_RPT_DS_NODE_INFO *nodeInfoTbl;
MVL_VAR_ASSOC *nodeVa;
RUNTIME_TYPE *rt;
ST_INT numRt;
ST_INT i;
ST_RET rc;
ST_INT numNodeVar;
ST_INT numDsVar;
ST_INT nameSize;
ST_CHAR *nameBuf;
ST_CHAR *nameDest;

  nodeInfoTbl = (_MVLU_RPT_DS_NODE_INFO *)
		     M_CALLOC (MSMEM_GEN, numNodes, sizeof (_MVLU_RPT_DS_NODE_INFO));

  numDsVar = 0;
  nameSize = 0;

/* Find each node VA */
  for (i = 0; i < numNodes; ++i)
    {
    nodeObjName.object_tag = DOM_SPEC;
    nodeObjName.domain_id = domName;
    nodeObjName.obj_name.item_id = nodeNames[i];

    nodeVa = u_mvl_get_va_aa (&mvl_vmd,
                             MMSOP_MVLU_RPT_VA,
			     &nodeObjName, NULL,
  		      	     SD_FALSE, NULL, NULL);
    nodeInfoTbl[i].nodeVa = nodeVa;
    if (nodeVa == NULL)
      {
      MVL_LOG_NERR1 ("Error: Report node %s not found", nodeNames[i]);
      return (SD_FAILURE);
      }

    rc = mvl_get_runtime (nodeVa->type_id, &rt, &numRt);
    if (rc != SD_SUCCESS)
      {
      MVL_LOG_NERR0 ("Error: Runtime type not found");
      return (SD_FAILURE);
      }
    nodeInfoTbl[i].rt = rt;
    nodeInfoTbl[i].numRt = numRt;

    numNodeVar = 0;
    rc = _mvlu_count_rpt_var (rt, numRt, &numNodeVar, &nameSize);
    if (rc != SD_SUCCESS)
      return (SD_FAILURE);

    numDsVar += numNodeVar;
    nodeInfoTbl[i].num_rpt_var = numNodeVar;

  /* the name buffer must add "base$" for each name */
    nameSize += (numDsVar * (strlen (nodeVa->name) + 1));
    }

  objNames = (OBJECT_NAME *) M_CALLOC (MSMEM_GEN, numDsVar, sizeof (OBJECT_NAME));
  nameBuf = M_CALLOC (MSMEM_GEN, 1, nameSize);
  objNameDest = objNames;
  nameDest = nameBuf;
  for (i = 0; i < numNodes; ++i)
    {
    nodeVa = nodeInfoTbl[i].nodeVa;
    rt = nodeInfoTbl[i].rt;
    numRt = nodeInfoTbl[i].numRt;
    rc = _mvlu_fill_rpt_var (nodeVa->name, domName, rt, numRt,
			     nodeInfoTbl[i].num_rpt_var,
		   	     objNameDest, &nameDest);

    objNameDest += nodeInfoTbl[i].num_rpt_var;
    }

  *numObjNamesOut = numDsVar;
  *objNameTblOut = objNames;
  *nameBufOut = nameBuf;

  M_FREE (MSMEM_GEN, nodeInfoTbl);
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			_mvlu_count_rpt_var 				*/
/************************************************************************/

static ST_RET _mvlu_count_rpt_var (RUNTIME_TYPE *rt, ST_INT numRt,
		    	         ST_INT *numRptVarOut, ST_INT *nameSizeOut)
  {
ST_INT numRptVar;
ST_INT nameSize;
RUNTIME_TYPE *lastRt;
ST_CHAR *comp_name;		/* Component name	*/

  if (numRt <= 2 || rt->el_tag != RT_STR_START)
    {
    MVL_LOG_NERR0 ("Error: Not structure, or no structure elements");
    return (SD_FAILURE);
    }

  ++rt;
  numRt -= 2;
  lastRt = rt + numRt;
  numRptVar = 0;
  nameSize = 0;
  while (rt <= lastRt)
    {
    switch (rt->el_tag)
      {
      case RT_STR_END :
      case RT_ARR_END :
      break;

      default:
        ++numRptVar;
        comp_name = ms_comp_name_find (rt);
        if (strlen (comp_name) == 0)
          {
          MVL_LOG_ERR0 ("Error: unnamed structure component");
          return (SD_FAILURE);
          }
        nameSize += (strlen (comp_name) + 1);
      break;
      }

    if (rt->el_tag == RT_STR_START)
      rt += rt->u.str.num_rt_blks + 1;	/* Skip the structure contents	*/

    if (rt->el_tag == RT_ARR_START)
      rt += rt->u.arr.num_rt_blks; /* Skip the array contents	*/

    ++rt;
    }

  *numRptVarOut += numRptVar;
  *nameSizeOut += nameSize;
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			_mvlu_fill_rpt_var 				*/
/************************************************************************/

static ST_RET _mvlu_fill_rpt_var (ST_CHAR *baseName, ST_CHAR *domName,
		   RUNTIME_TYPE *rt, ST_INT numRt,
                   ST_INT numObjNames, OBJECT_NAME *objNames,
		   ST_CHAR **nameBufPtr)
  {
ST_INT dsDvCount;
RUNTIME_TYPE *lastRt;
ST_CHAR *nameBuf;
ST_CHAR *comp_name;		/* Component name	*/

  nameBuf = *nameBufPtr;

  ++rt;
  numRt -= 2;

  dsDvCount = 0;
  lastRt = rt + numRt;
  while (rt <= lastRt)
    {
    switch (rt->el_tag)
      {
      case RT_STR_END :
      case RT_ARR_END :
      break;

      default:
        comp_name = ms_comp_name_find (rt);
        if (strlen (comp_name) == 0)
          {
          MVL_LOG_ERR0 ("Error: unnamed structure component");
          return (SD_FAILURE);
          }
        sprintf (nameBuf, "%s$%s", baseName, comp_name);
        objNames[dsDvCount].object_tag = DOM_SPEC;
        objNames[dsDvCount].domain_id = domName;
        objNames[dsDvCount].obj_name.item_id = nameBuf;
        ++dsDvCount;
        nameBuf += (strlen (nameBuf) + 1);
      break;
      }

    if (rt->el_tag == RT_STR_START)
      rt += rt->u.str.num_rt_blks + 1;	/* Skip the structure contents	*/

    if (rt->el_tag == RT_ARR_START)
      rt += rt->u.arr.num_rt_blks; /* Skip the array contents	*/

    ++rt;
    }

  if (dsDvCount != numObjNames)
    {
    MVL_LOG_ERR0 ("Internal Error: dsDvCount misnatch");
    return (SD_FAILURE);
    }

  *nameBufPtr = nameBuf;
  return (SD_SUCCESS);
  }

/************************************************************************/
/************************************************************************/
/* REPORT CONTROL HANDLING						*/
/************************************************************************/
/************************************************************************/
/*                       mvlu_create_rpt_ctrl				*/
/************************************************************************/
/* Create a MVLU Report Control 					*/
/* This function creates a RPT NVL data structure and associated 	*/
/* control data to handle UCA report activity.				*/

/* Note that the 'dsNvl' can be created by 'mvlu_create_rpt_nvl',	*/
/* created by 'u_mvl_get_nvl', or can be configured. The NVL	*/
/* must be completely resolved; that is, all VA must have a valid data	*/
/* pointer, name, and type_id.						*/

MVLU_RPT_CTRL *mvlu_create_rpt_ctrl (ST_CHAR *basrcbName,
			MVL_NVLIST_CTRL *dsNvl,
			MVL_VAR_ASSOC *base_va,
			ST_INT rcb_type,
			ST_INT buftim_action,
			ST_INT brcb_bufsize,	/* for BRCB only	*/
			ST_UINT32 ConfRev)	/* for BRCB/URCB only	*/

  {
MVLU_RPT_CTRL *rptCtrl;
MVL_NVLIST_CTRL *rptNvl;
RUNTIME_TYPE *incRt;
ST_RET rc;
ST_INT i;
ST_INT numDsVars;
ST_INT rptCtrlSize;
ST_INT inc_size;
RUNTIME_TYPE *rcbHead;
ST_INT numRt;

/* This funct only works for UCA. For IEC 61850, call mvl61850_create_rpt_ctrl*/
  assert (rcb_type == RCB_TYPE_UCA);

/* Find the runtime type of the RCB (saved later in rptCtrl).	*/
/* If successful, this function sets "rcbHead" & "numRt".	*/
  if (mvlu_rpt_rcb_type_find (base_va->type_id, basrcbName, &rcbHead, &numRt))
    return (NULL);	/* error already logged.	*/

/* Alloc report control large enough to contain the inclusion BS data 	*/
/* and reasons VA's (they depend on the number of VA in the report)	*/
  numDsVars = dsNvl->num_of_entries;
  inc_size = BSTR_NUMBITS_TO_NUMBYTES(numDsVars);
  rptCtrlSize = sizeof (MVLU_RPT_CTRL) +
        strlen (basrcbName) + 1;

  rptCtrl = (MVLU_RPT_CTRL *) M_CALLOC (MSMEM_GEN, 1, rptCtrlSize);

/* Set the variable size element pointers */
  rptCtrl->basrcb_name = (ST_CHAR *) (rptCtrl + 1);
  strcpy (rptCtrl->basrcb_name, basrcbName);

/* Initialize the Report Control data elements */
  rptCtrl->dsNvl = dsNvl;
  rptCtrl->base_va = base_va;
  rptCtrl->rcbRtHead = rcbHead;

/* If domname + '/' + basrcb_name will fit in RptID, then write it.	*/
  if (strlen (dsNvl->nvl_scope.dom->name) + strlen (rptCtrl->basrcb_name) + 1
      < sizeof (rptCtrl->common_basrcb.RptID))
    {
    sprintf (rptCtrl->common_basrcb.RptID, "%s/%s",
			dsNvl->nvl_scope.dom->name,
			rptCtrl->basrcb_name);
    if (rcb_type == RCB_TYPE_UCA)
      {    /* replace $ with '.'. Only for UCA.		*/
      for (i = 0; i < (ST_INT) strlen (rptCtrl->common_basrcb.RptID); ++i)
        {
        if (rptCtrl->common_basrcb.RptID[i] == '$')
          rptCtrl->common_basrcb.RptID[i] = '.';
        }
      }
    }
  else
    {
    MVL_LOG_ERR0 ("mvlu_create_rpt_ctrl RptID too long");
    M_FREE (MSMEM_GEN, rptCtrl);
    return (NULL);
    }

  rptCtrl->rcb_type = rcb_type;
  rptCtrl->buftim_action = buftim_action;
  rptCtrl->common_basrcb.ConfRev = ConfRev;
  if (mvlu_rpt_find_typeids (&rptCtrl->rpt_typeids))
    {
    MVL_LOG_ERR0 ("mvlu_create_rpt_ctrl error finding base types");
    M_FREE (MSMEM_GEN, rptCtrl);
    return (NULL);
    }

  rptCtrl->brcbCtrl.brcb_bufsize = brcb_bufsize;	/* ONLY for IEC BRCB*/

/* Create the RPT NVL control element, used to send the actual reports	*/
  rptNvl = &rptCtrl->rptNvl;
  rptNvl->name = "RPT";

/* Alloc the entries table; allow for RptID, OptFlds, SqNum, RptTim, 	*/
/* OutDat (61850 calls it DatSetName), BufOvfl, EntryID, ConfRev,	*/
/* SubSeqNum, MoreSegmentsFollow, & InclusionBitstring plus ARRAYS of	*/
/* dataRefs, values, and Reasons.					*/
/* "assert" later if "maxNumRptVars" exceeded.				*/
/* Allow (3 * numDsVars) to handle arrays of dataRef, value, and reason.*/
  rptCtrl->maxNumRptVars = MVLU_MAX_RPT_OPTS + (3 * numDsVars);

  rptNvl->entries = (MVL_VAR_ASSOC **) M_CALLOC (MSMEM_GEN, rptCtrl->maxNumRptVars,
					sizeof (MVL_VAR_ASSOC *));

  /* NOTE: The "rptNvl->entries" array is not filled in and
   *       and "rptNvl->num_of_entries" is not set
   *       until a Report is being built.
   */

  /* We need to create a Runtime Type for the inclusion bitstring */
  incRt = &rptCtrl->incRt;
  incRt->el_tag = RT_BIT_STRING;
  incRt->el_size = BSTR_NUMBITS_TO_NUMBYTES(numDsVars);
  incRt->offset_to_last = incRt->el_size;
  incRt->u.p.el_len = (ST_RTINT) numDsVars;
  rc = mvlu_add_rt_type (&rptCtrl->incRt, 1, &rptCtrl->inclusion_typeid);
  if (rc != SD_SUCCESS)
    {
    MVL_LOG_NERR0 ("Error - could not add temp RT type");
    M_FREE (MSMEM_GEN, rptCtrl);
    return (NULL);
    }

/* That's all we can do ahead of time for the RPT variable associations	*/

/* Set a bit of the data for the common BASRCB */
  sprintf (rptCtrl->common_basrcb.DatSetNa, "%s/%s",
			dsNvl->nvl_scope.dom->name, dsNvl->name);

  if (rcb_type == RCB_TYPE_UCA)
    {
    rptCtrl->common_basrcb.OptFlds.len_1 = 8;
    rptCtrl->common_basrcb.TrgOps.len = 8;
    }
  else
    {
    rptCtrl->common_basrcb.OptFlds.len_1 = 10;
    rptCtrl->common_basrcb.TrgOps.len = 6;
    }

  rptCtrl->common_basrcb.TrgOps.data[0] = MVLU_TRGOPS_DATA;

/* Put it on the list */
  list_add_last((ST_VOID **) &mvlu_rpt_ctrl_list, (ST_VOID *) rptCtrl);
  return (rptCtrl);
  }

/************************************************************************/
/*                       mvlu_free_rpt_ctrl				*/
/************************************************************************/
/* This function is used to free a MVLU_RPT_CTRL allocated by 		*/
/* 'mvlu_create_rpt_ctrl'						*/

ST_VOID mvlu_free_rpt_ctrl (MVLU_RPT_CTRL *rptCtrl)
  {
MVLU_RPT_CLIENT *rptClient;

/* This funct only works for UCA. For IEC 61850, call mvl61850_free_rpt_ctrl*/
  assert (rptCtrl->rcb_type == RCB_TYPE_UCA);

/* Take it off the report control list */
  list_unlink ((ST_VOID **) &mvlu_rpt_ctrl_list, (ST_VOID *) rptCtrl);

/* Free up the dynamic type used for the inclusion bitstring type */
  mvlu_free_rt_type (rptCtrl->inclusion_typeid);

/* Destroy all clients for this rptCtrl	*/
/* NOTE: list_get_first removes the entry from the linked list.	*/
  while ((rptClient = (MVLU_RPT_CLIENT *) list_get_first (&rptCtrl->rpt_client_list))!=NULL)
    _mvlu_free_rpt_client (rptClient);	/* free client */

/* Now the rest of the report control */
  M_FREE (MSMEM_GEN, rptCtrl->rptNvl.entries);
  M_FREE (MSMEM_GEN, rptCtrl);
  }

/************************************************************************/
/************************************************************************/
/* REPORT CONTROL SERVICING						*/
/************************************************************************/
/************************************************************************/
/*			mvlu_rpt_service 				*/
/************************************************************************/

ST_VOID mvlu_rpt_service ()
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;
ST_DOUBLE timeNow;

/* Do Report VA Scans */
  mvlu_rpt_va_scan ();

/* See if it is time to send reports	*/
  timeNow = sGetMsTime ();
  for (rptCtrl = mvlu_rpt_ctrl_list;
       rptCtrl != NULL;
       rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvlu_rpt_ctrl_list, rptCtrl))
    {
    assert (rptCtrl->rcb_type == RCB_TYPE_UCA);	/* must be UCA URCB*/
    /* Loop through linked list of clients for UCA.*/
    for (rptClient = rptCtrl->rpt_client_list;
         rptClient != NULL;
         rptClient = (MVLU_RPT_CLIENT *) list_get_next (rptCtrl->rpt_client_list, rptClient))
      {
      _mvlu_rpt_client_service (rptClient, timeNow);
      }
    }
  }

/************************************************************************/
/*			mvlu_rpt_va_scan 				*/
/************************************************************************/

ST_VOID mvlu_rpt_va_scan ()
  {
MVLU_RPT_SCAN_CTRL *scanCtrl;
ST_DOUBLE timeNow;

  timeNow = sGetMsTime ();
  scanCtrl = mvlu_rpt_scan_list;
  while (scanCtrl != NULL)		/* look through whole list	*/
    {
    if (scanCtrl->enable == SD_TRUE)
      {
      if (timeNow >= scanCtrl->next_scan_start)
        {
	if (scanCtrl->num_va_read_pend == 0)
          {
          scanCtrl->next_scan_start += scanCtrl->scan_period;
          mvlu_rpt_scan_read (scanCtrl);
          }
        else
          scanCtrl->saturated = SD_TRUE;
        }
      }
    scanCtrl = (MVLU_RPT_SCAN_CTRL *) list_get_next (mvlu_rpt_scan_list, scanCtrl);
    }
  }

/************************************************************************/
/*			mvlu_rpt_scan_read 				*/
/************************************************************************/

ST_VOID mvlu_rpt_scan_read (MVLU_RPT_SCAN_CTRL *scanCtrl)
  {
MVLAS_READ_CTRL *rdCtrl;
MVLAS_RD_VA_CTRL *vaCtrl;
MVL_IND_PEND *indCtrl;
ST_INT i;

  if (scanCtrl->num_va_read_pend == 0)
    {
    scanCtrl->num_va_read_pend = scanCtrl->num_scan_va;
    scanCtrl->num_va_changes = 0;

    indCtrl = &scanCtrl->indCtrl;
    rdCtrl = &indCtrl->u.rd;
    rdCtrl->numVar = 0;
    vaCtrl = rdCtrl->vaCtrlTbl;

    for (i = 0; i < scanCtrl->num_scan_va; ++i)
      {
      vaCtrl->va = scanCtrl->scan_va[i];
      memcpy (&vaCtrl->va_scope, &scanCtrl->scan_va_scope[i], sizeof(MVL_SCOPE));
      ++vaCtrl;
      ++rdCtrl->numVar;
      }

  /* OK, now fire off the read indication functions 			*/
  /* (*u_mvlu_report_reads_done_fun) will be invoked when all are ready	*/
    u_mvl_read_ind (indCtrl);
    }
  else
    scanCtrl->saturated = SD_TRUE;
  }

/************************************************************************/
/*			_mvlu_rpt_va_reads_done				*/
/************************************************************************/
/* This function is called by 'mvlu_rd_prim_done' when all primitive	*/
/* read indication functions for a VA have been completed. This means	*/
/* that the data is ready to be sent for this VA.			*/

static ST_VOID _mvlu_rpt_va_reads_done (MVL_IND_PEND *indCtrl,
					MVL_VAR_ASSOC *va)
  {
MVLU_RPT_SCAN_CTRL *scanCtrl;
ST_INT data_size;

/* Do some housekeeping */
  scanCtrl = (MVLU_RPT_SCAN_CTRL *) indCtrl->usr_ind_ctrl;
  --scanCtrl->num_va_read_pend;

/* Let's see if the data has changed */
  data_size = mvl_type_ctrl[va->type_id].data_size;
  if (memcmp (va->last_data, va->data, data_size) != 0)
    {
    MVLU_LOG_FLOW1 ("Report VA Scan detected change for rpt VA '%s'",
			va->name);
    mvlu_rpt_va_change (va, MVLU_TRGOPS_DATA, NULL);
    ++scanCtrl->num_va_changes;
    }
  }

/************************************************************************/
/*			_mvlu_rpt_client_service 			*/
/************************************************************************/

static ST_VOID _mvlu_rpt_client_service (MVLU_RPT_CLIENT *rptClient,
				         ST_DOUBLE timeNow)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_BASRCB *basrcb;
MVL_NVLIST_CTRL *dsNvl;
ST_RET rc;
ST_BOOLEAN sendRbe;
ST_INT incSize;

  basrcb = &rptClient->basrcb;

/* Let's see if the report is enabled */
  if (basrcb->RptEna == SD_FALSE)	/* treat any non-zero as TRUE	*/
    return;

/* Make sure we can send one if we want to ... */
  if (a_buffers_avail (rptClient->netInfo->acse_conn_id) <= 0)
    return;

/* Reporting is enabled, let's see if it is time to send the report */
  rptCtrl = rptClient->rpt_ctrl;
  dsNvl = rptCtrl->dsNvl;
  incSize = BSTR_NUMBITS_TO_NUMBYTES(dsNvl->num_of_entries);

/* First, see if Integrity scan is enabled, and if so if time to send	*/
/* This function checks time & if necessary, starts integrity scan.	*/
  mvlu_integrity_timeout (rptClient, timeNow);

/* Check for RBE enable */
/* NOTE: numTrgs ONLY incremented if changes matched the TrgOps	*/
/*       for this client. See mvlu_rpt_va_change.			*/
  if (rptClient->numTrgs > 0)
    {
  /* RBE is enabled, see if a RBE Period is selected ... */
    if (basrcb->RBEPd != 0)
      {
      if (timeNow > rptClient->next_rbe_rpt_time)
        {
      /* OK, send the report! */
        MVLU_LOG_FLOW1 ("UCA Report RBE Period timeout for client %08lx",
							rptClient);
        rc = mvlu_send_report (rptClient, MVLU_RPT_TYPE_RBE);

        rptClient->next_rbe_rpt_time = timeNow + (ST_DOUBLE) basrcb->RBEPd;
        return;
        }
      }
    else	/* NO RBE Period is selected, send right away, subject	*/
      {		/* to BufTime and Trgs parameters 			*/

    /* If neither constraint is in place, send immediately, otherwise 	*/
    /* we must exceed one or both constraints before sending		*/

      if (basrcb->Trgs == 0 && basrcb->BufTim == 0)
        sendRbe = SD_TRUE;
      else
        sendRbe = SD_FALSE;

      if (basrcb->Trgs != 0)
        {
        if (rptClient->numTrgs >= basrcb->Trgs)
          sendRbe = SD_TRUE;
        }
      if (basrcb->BufTim != 0)
        {
        if (timeNow > rptClient->buf_time_done)
          sendRbe = SD_TRUE;
        }

      /* OK, send the report! */
      if (sendRbe == SD_TRUE)
        {
        MVLU_LOG_FLOW1 ("UCA Report RBE for client %08lx", rptClient);
        rc = mvlu_send_report (rptClient, MVLU_RPT_TYPE_RBE);
        return;
        }
      }
    }
  }

/************************************************************************/
/************************************************************************/
/*			mvlu_rpt_va_change 				*/
/* CRITICAL: this function does not save the data in "va->data" until	*/
/* the very end, because depending on RCB state, it may first need to	*/
/* send a report with the previous data (see _mvlu_rpt_va_chk_reason).	*/
/************************************************************************/

ST_VOID mvlu_rpt_va_change (MVL_VAR_ASSOC *va, ST_UCHAR reason,
			    ST_VOID *new_data)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;
ST_INT va_index;
ST_INT data_size;

  MVLU_LOG_FLOW2 ("Report VA '%s' change, reason=0x%02X", va->name, reason);

  data_size = mvl_type_ctrl[va->type_id].data_size;

  /* Check all UCA RCBs.	*/
  for (rptCtrl = mvlu_rpt_ctrl_list;
       rptCtrl != NULL;
       rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvlu_rpt_ctrl_list, rptCtrl))
    {					/* see if someone is interested	*/
    assert (rptCtrl->rcb_type == RCB_TYPE_UCA);	/* this loop only for UCA*/
    va_index = mvlu_rpt_get_va_index (rptCtrl, va);
    if (va_index >= 0)
      {
      MVLU_LOG_CFLOW1 ("VA is member of report NVL '%s'", rptCtrl->dsNvl->name);
      for (rptClient = rptCtrl->rpt_client_list;
           rptClient != NULL;
           rptClient = (MVLU_RPT_CLIENT *) list_get_next (rptCtrl->rpt_client_list, rptClient))
        {
        /* If enabled, chk "reason" (i.e. compare to TrgOps, etc.)*/
        if (rptClient->basrcb.RptEna)
          {
          _mvlu_rpt_va_chk_reason (rptClient, va, va_index, reason);
          }
        else
          MVLU_LOG_CFLOW0 ("VA change ignored: Report not enabled");
        }
      }
    }

  /* Check all IEC 61850 RCBs.	*/
  for (rptCtrl = mvl61850_rpt_ctrl_list;
       rptCtrl != NULL;
       rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvl61850_rpt_ctrl_list, rptCtrl))
    {					/* see if someone is interested	*/
    assert (rptCtrl->rcb_type != RCB_TYPE_UCA);	/* this loop only for 61850*/
    va_index = mvlu_rpt_get_va_index (rptCtrl, va);
    if (va_index >= 0)
      {
      MVLU_LOG_CFLOW1 ("VA is member of report NVL '%s'", rptCtrl->dsNvl->name);
      rptClient = &rptCtrl->only_client;	/* only one client	*/
      /* If enabled, or this is IEC BRCB & it was enabled ONCE, chk "reason".*/
      if (rptClient->basrcb.RptEna
          || (rptCtrl->rcb_type == RCB_TYPE_IEC_BRCB
              && rptCtrl->brcbCtrl.enabled_once))
        {
        _mvlu_rpt_va_chk_reason (rptClient, va, va_index, reason);
        }
      else
        MVLU_LOG_CFLOW0 ("VA change ignored: Report not enabled");
      }
    }

/* If the user is passing us the data, need to save it ... */
  if (new_data != NULL)
    {
    MVLU_LOG_CFLOW0 ("Saving report VA data");
    memcpy (va->data, new_data, data_size);
    }

/* Now copy the data into the buffer chain */
/* NOTE: Multiple datasets may reference the same variable, but each	*/
/*   creates its own "va", so each gets its own copy of "last_data".	*/
  memcpy (va->last_data, va->data, data_size);	/* save data for next compare	*/
  }

/************************************************************************/
/*			_mvlu_rpt_va_chk_reason				*/
/************************************************************************/
static ST_VOID _mvlu_rpt_va_chk_reason (MVLU_RPT_CLIENT *rptClient,
		MVL_VAR_ASSOC *va,
		ST_INT va_index,
		ST_UCHAR reason)
  {
ST_INT data_size;
ST_VOID *new_data;	/* temp copy of new data while sending old data*/

  if ((reason & (MVLU_TRGOPS_DATA | MVLU_TRGOPS_QUALITY | MVLU_TRGOPS_FREEZE)) != 0)
    {
    /* If this "reason" is enabled in TrgOps, process it.	*/
    if ((rptClient->basrcb.TrgOps.data[0] & reason) != 0)
      {
      if (rptClient->basrcb.BufTim != 0)
        {
        /* If this is first change for "ANY" VA, start BufTim timer.	*/
        if (rptClient->numTrgs == 0)
          {	/* First va change. Start BufTim timer.	*/
          rptClient->buf_time_done = sGetMsTime () +
                               (ST_DOUBLE) rptClient->basrcb.BufTim;
          MVLU_LOG_CFLOW1 ("Setting buffer Time Done = %06.3fs",
                                rptClient->buf_time_done/1000);
          }

        /* If change already detected for "THIS" VA & buftim_action = SEND_NOW, send report.*/
        if (BSTR_BIT_GET (rptClient->changed_flags, va_index)
            && rptClient->rpt_ctrl->buftim_action == MVLU_RPT_BUFTIM_SEND_NOW)
          {
          /* Send report now with last data, then process new data.*/
          /* Report is built using "va->data", so must copy old data	*/
          /* to "va->data" until after first rpt built.			*/
          data_size = mvl_type_ctrl[va->type_id].data_size;
          new_data = chk_malloc (data_size);		/* alloc buf to save new data*/
          memcpy (new_data, va->data, data_size);	/* save new data	*/
          memcpy (va->data, va->last_data, data_size);	/* restore old data*/

          MVLU_LOG_CFLOW0 ("Second change for this VA before BufTim. Sending Report with first change. Restarting BufTim.");
          /* send or queue rpt	*/
          mvlu_rpt_ready (rptClient, MVLU_RPT_TYPE_RBE);
          rptClient->buf_time_done = sGetMsTime () +
                       (ST_DOUBLE) rptClient->basrcb.BufTim;

          /* Put back new data in "va->data".	*/
          memcpy (va->data, new_data, data_size);   /* restore new data   */
          chk_free (new_data);
          }
        }	/* end "if (..BufTim != 0)"	*/

      /* Set numTrgs, changed_flags, reasons_data	*/
      ++rptClient->numTrgs;
      MVLU_LOG_CFLOW1 ("Number Triggers is now %d", (int) rptClient->numTrgs);
      BSTR_BIT_SET_ON (rptClient->changed_flags, va_index);
      rptClient->reasons_data[va_index] = reason;
      }	/* end "if client TrgOps matches reason"	*/
    else
      MVLU_LOG_CFLOW0 ("VA change ignored: Reason doesn't match TrgOps");
    }
  else if ((reason & (MVLU_TRGOPS_INTEGRITY | MVLU_TRGOPS_GI)) != 0)
    {
    /* NOTE: ALL bits in "rptClient->changed_flags" are set later before report sent.	*/
    rptClient->reasons_data[va_index] = reason;	/* Always save reason*/
    }
  else
    {
    assert (0);	/* Unrecognized TRGOPS.	*/
    }
  }

/************************************************************************/
/*			mvlu_rpt_get_va_index				*/
/************************************************************************/
/* Given a MVL report control and an associated VA, find the index of	*/
/* the Va. This index is then used for manipulating the inclusion bits,	*/
/* read bits, and reason codes.						*/

ST_INT mvlu_rpt_get_va_index (MVLU_RPT_CTRL *rptCtrl, MVL_VAR_ASSOC *va)
  {
ST_INT i;
MVL_NVLIST_CTRL *dsNvl;

  dsNvl = rptCtrl->dsNvl;

  if (dsNvl!=NULL)	/* NOTE: dsNvl may be NULL	*/
    {
    for (i = 0; i < dsNvl->num_of_entries; ++i)
      {
      if (dsNvl->entries[i] == va)
        {
        return (i);
        }
      }
    }
  return (-1);
  }

/************************************************************************/
/************************************************************************/
/************************************************************************/
/* SENDING REPORTS							*/
/************************************************************************/
/************************************************************************/
/************************************************************************/
/*			mvlu_send_report 				*/
/************************************************************************/

ST_RET mvlu_send_report (MVLU_RPT_CLIENT *rptClient, ST_INT rpt_type)
  {
MVLU_RPT_CTRL *rptCtrl;
MVL_NET_INFO *netInfo;
MVL_NVLIST_CTRL *dsNvl;
MVL_NVLIST_CTRL *rptNvl;
MVL_VAR_ASSOC *va;
ST_INT i;
ST_RET rc;
ST_INT sendIndex = 0;
ST_INT sendIndexSave;	/* save index before data, compare after data	*/
ST_UINT8 optFld;
MVLU_BASRCB *basrcb;
ST_INT incSize;		/* num bytes for inclusion bitstring	*/
MVL_VAR_ASSOC *tmp_va_arr;	/* alloc array of structs	*/
ST_INT tmp_va_arr_size;		/* num of entries in tmp_va_arr	*/
MVL_VAR_ASSOC *tmp_va;		/* current entry in tmp_va_arr	*/
MMS_BTIME6 TimeOfEntry;		/* Time this report generated.		*/

  rptCtrl = rptClient->rpt_ctrl;
  netInfo = rptClient->netInfo;
  basrcb = &rptClient->basrcb;

  optFld = basrcb->OptFlds.data_1[0];
  dsNvl = rptCtrl->dsNvl;
  rptNvl = &rptCtrl->rptNvl;

  incSize = BSTR_NUMBITS_TO_NUMBYTES(dsNvl->num_of_entries);

  MVLU_LOG_FLOW1 ("Sending UCA Report, MVL_NET_INFO %08lx", rptClient->netInfo);

  /* Need tmp va's for options plus array of reasons_data.	*/
  tmp_va_arr_size = MVLU_MAX_RPT_OPTS + dsNvl->num_of_entries;
  tmp_va_arr = M_CALLOC (MSMEM_GEN, sizeof (MVL_VAR_ASSOC), tmp_va_arr_size);
  tmp_va = tmp_va_arr;	/* start out pointing to first entry	*/

/* Prepares a UCA Report NVL to be sent, based on the 			*/
/* options, data, and inclusion bitstring in the rptCtrl. After this	*/
/* function completes, the rptCtrl->rptNvl is ready to be sent.		*/

/* If this is Integrity report, just set all inclusion bits.	*/
  if (rpt_type == MVLU_RPT_TYPE_INTEGRITY_OR_GI)
    memset (rptClient->changed_flags, 0xff, incSize);

/* We will create a NVL to send, using the dsNvl as a model ...		*/

  /* RptID and OptFlds are always the first 2 entries in the Rpt NVL.	*/
  tmp_va->type_id = rptCtrl->rpt_typeids.vstring32;
  tmp_va->data = basrcb->RptID;
  rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
  MVLU_LOG_CFLOW1 ("  RptID='%s", basrcb->RptID);

  tmp_va->type_id = rptCtrl->rpt_typeids.bvstring8;
  tmp_va->data = &basrcb->OptFlds;
  rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
  MVLU_LOG_CFLOW1 ("  OptFld = 0x%02x", (int) optFld);

  if (optFld & MVLU_SQNUM_MASK)
    {
    tmp_va->type_id = rptCtrl->rpt_typeids.int8u;
    tmp_va->data = &basrcb->SqNum;
    rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
    MVLU_LOG_CFLOW1 ("    SqNum : %u", (unsigned) basrcb->SqNum);
    }
  if (optFld & MVLU_RPTTIM_MASK)
    {
    /* Call user function to get report time.	*/
    u_mvlu_rpt_time_get (&TimeOfEntry);

    MVLU_LOG_CFLOW2 ("    RptTim : %lums, %lu days",
              TimeOfEntry.ms, TimeOfEntry.day);

    tmp_va->type_id = rptCtrl->rpt_typeids.btime6;
    tmp_va->data = &TimeOfEntry;
    rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
    }
  if (optFld & MVLU_OUTDAT_MASK)
    {
    /* OutDat is same as DatSetNa	*/
    MVLU_LOG_CFLOW1 ("    OutDat : %s", basrcb->DatSetNa);
    tmp_va->type_id = rptCtrl->rpt_typeids.vstring65;	/* Obj Ref	*/
    tmp_va->data = basrcb->DatSetNa;
    rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
    }

  /* Add inclusion bitstring.	*/
  tmp_va->type_id = rptCtrl->inclusion_typeid;
  tmp_va->data = rptClient->changed_flags;
  rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/

/* Now go through the inclusion bitstring and figure out what to send	*/
  sendIndexSave = sendIndex;	/* save index before data included	*/
  for (i = 0; i < dsNvl->num_of_entries; ++i)
    {
    if (BSTR_BIT_GET (rptClient->changed_flags, i))
      {
      va = dsNvl->entries[i];
      MVLU_LOG_CFLOW3 ("  Including variable %d ('%s'), reason=0x%02X",
                      i, va->name, rptClient->reasons_data[i]);
      rptNvl->entries[sendIndex++] = va;

      /* va->data already points to latest data. Done with this va.	*/
      }
    }
  assert (sendIndex>sendIndexSave);	/* make sure SOME data included	*/

  if (optFld & MVLU_REASONS_MASK)
    {
    for (i = 0; i < dsNvl->num_of_entries; ++i)
      {
      if (BSTR_BIT_GET (rptClient->changed_flags, i))
        {
        /* Don't need BVSTR here, because size is fixed.	*/
        tmp_va->type_id = rptCtrl->rpt_typeids.bstr8;
        tmp_va->data = &rptClient->reasons_data[i];
        rptNvl->entries[sendIndex++] = tmp_va++;	/* set entry & point to next*/
	}
      }
    }
  rptNvl->num_of_entries = sendIndex;
  assert (rptNvl->num_of_entries <= rptCtrl->maxNumRptVars);	/* past end of array?*/
  assert ((tmp_va-tmp_va_arr) <= tmp_va_arr_size);	/* past end of array?*/

  rc = mvl_info_variables (rptClient->netInfo, &rptClient->rpt_ctrl->rptNvl, SD_FALSE);

  basrcb->SqNum++;		/* Increment seq number for next rpt.	*/

  /* Reset reasons, etc. to prepare for new report triggers.	*/
  memset (rptClient->reasons_data, 0, dsNvl->num_of_entries);
  memset (rptClient->changed_flags, 0, incSize);
  rptClient->numTrgs = 0;
  M_FREE (MSMEM_GEN, tmp_va_arr);
  return (rc);
  }

/************************************************************************/
/************************************************************************/
/*			_mvlu_rpt_disconnect_rcvd 			*/
/************************************************************************/

ST_VOID _mvlu_rpt_disconnect_rcvd (MVL_NET_INFO *netInfo)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;

  /* Loop through list of UCA RCBs.	*/
  for (rptCtrl = mvlu_rpt_ctrl_list;
       rptCtrl != NULL;
       rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvlu_rpt_ctrl_list, rptCtrl))
    {
    assert (rptCtrl->rcb_type == RCB_TYPE_UCA);
    /* Loop through list of clients.	*/
    for (rptClient = rptCtrl->rpt_client_list;
         rptClient != NULL;
         rptClient = (MVLU_RPT_CLIENT *) list_get_next (rptCtrl->rpt_client_list, rptClient))
      {
      if (rptClient->netInfo == netInfo)
        {
        list_unlink ((ST_VOID **) &rptCtrl->rpt_client_list, (ST_VOID *) rptClient);
        _mvlu_free_rpt_client (rptClient);
        break;	/* one client per connection */
        }
      }
    }

  /* Loop through list of IEC 61850 RCBs (URCB or BRCB).	*/
  for (rptCtrl = mvl61850_rpt_ctrl_list;
       rptCtrl != NULL;
       rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvl61850_rpt_ctrl_list, rptCtrl))
    {
    assert (rptCtrl->rcb_type != RCB_TYPE_UCA);
    rptClient = &rptCtrl->only_client;	/* only one client	*/
    if (rptClient->netInfo == netInfo)
      {	/* Reset RCB parameters.	*/
      rptClient->netInfo = NULL;
      rptClient->basrcb.RptEna = SD_FALSE;
      rptClient->basrcb.Resv = SD_FALSE;	/* Ignored for BRCB	*/
      }
    }
  }

/************************************************************************/
/************************************************************************/
/* MVLU REPORT SCAN CONTROL						*/
/************************************************************************/
/************************************************************************/
/*			mvlu_rpt_create_scan_ctrl2 			*/
/* DEBUG: pass "enable" as additional arg?				*/
/* DEBUG: delete older "mvlu_rpt_create_scan_ctrl" function?		*/
/************************************************************************/

MVLU_RPT_SCAN_CTRL *mvlu_rpt_create_scan_ctrl2 (
	MVL_NVLIST_CTRL *nvl,
	ST_RET (*scan_done_fun) (struct mvl_ind_pend *ind_pend),
	ST_UINT report_scan_rate)	/* report scan rate (millisec)	*/
  {
MVLU_RPT_SCAN_CTRL *scanCtrl;
ST_INT scanCtrlSize;
ST_INT numScanVa = nvl->num_of_entries;
ST_INT j;

  scanCtrlSize = sizeof (MVLU_RPT_SCAN_CTRL) +
  		 (numScanVa * sizeof (MVLAS_RD_VA_CTRL)) +
  		 (numScanVa * sizeof (MVL_SCOPE)) +
  		 (numScanVa * sizeof (MVL_VAR_ASSOC *));

  scanCtrl = (MVLU_RPT_SCAN_CTRL *) M_CALLOC (MSMEM_GEN, 1, scanCtrlSize);
  scanCtrl->scan_va = (MVL_VAR_ASSOC **) (scanCtrl + 1);
  scanCtrl->num_scan_va = numScanVa;
  /* Point after array of (MVL_VAR_ASSOC *)	*/
  scanCtrl->scan_va_scope = (MVL_SCOPE *) (scanCtrl->scan_va + numScanVa);

  scanCtrl->indCtrl.event = &scanCtrl->commEvent;
  scanCtrl->commEvent.event_type = MVLU_RPT_COMM_EVENT;
  scanCtrl->indCtrl.op = MMSOP_MVLU_RPT_VA;
  /* Point after array of (MVL_SCOPE)	*/
  scanCtrl->indCtrl.u.rd.vaCtrlTbl =
		(MVLAS_RD_VA_CTRL *) (scanCtrl->scan_va_scope + numScanVa);

  scanCtrl->indCtrl.scan_va_done_fun = _mvlu_rpt_va_reads_done;

  scanCtrl->indCtrl.usr_ind_ctrl = scanCtrl;

  /* Fill in other structure elements from args passed.			*/
  for (j = 0; j < nvl->num_of_entries; ++j)
    scanCtrl->scan_va[j]= nvl->entries[j];
  memcpy (scanCtrl->scan_va_scope, nvl->va_scope,
          nvl->num_of_entries * sizeof (MVL_SCOPE));
  scanCtrl->enable = SD_TRUE;		/* ALWAYS enable		*/
  /* Optional user function to be called when each scan completes.	*/
  scanCtrl->indCtrl.usr_resp_fun = scan_done_fun;
  scanCtrl->scan_period = (ST_DOUBLE) report_scan_rate;

  list_add_last((ST_VOID **) &mvlu_rpt_scan_list, (ST_VOID *) scanCtrl);
  return (scanCtrl);
  }

/************************************************************************/
/*			mvlu_rpt_create_scan_ctrl 			*/
/************************************************************************/

MVLU_RPT_SCAN_CTRL *mvlu_rpt_create_scan_ctrl (ST_INT numScanVa)
  {
MVLU_RPT_SCAN_CTRL *scanCtrl;
ST_INT scanCtrlSize;

  scanCtrlSize = sizeof (MVLU_RPT_SCAN_CTRL) +
  		 (numScanVa * sizeof (MVLAS_RD_VA_CTRL)) +
  		 (numScanVa * sizeof (MVL_SCOPE)) +
  		 (numScanVa * sizeof (MVL_VAR_ASSOC *));

  scanCtrl = (MVLU_RPT_SCAN_CTRL *) M_CALLOC (MSMEM_GEN, 1, scanCtrlSize);
  scanCtrl->scan_va = (MVL_VAR_ASSOC **) (scanCtrl + 1);
  scanCtrl->num_scan_va = numScanVa;
  /* Point after array of (MVL_VAR_ASSOC *)	*/
  scanCtrl->scan_va_scope = (MVL_SCOPE *) (scanCtrl->scan_va + numScanVa);

  scanCtrl->indCtrl.event = &scanCtrl->commEvent;
  scanCtrl->commEvent.event_type = MVLU_RPT_COMM_EVENT;
  scanCtrl->indCtrl.op = MMSOP_MVLU_RPT_VA;
  /* Point after array of (MVL_SCOPE)	*/
  scanCtrl->indCtrl.u.rd.vaCtrlTbl =
		(MVLAS_RD_VA_CTRL *) (scanCtrl->scan_va_scope + numScanVa);

  scanCtrl->indCtrl.scan_va_done_fun = _mvlu_rpt_va_reads_done;

  scanCtrl->indCtrl.usr_ind_ctrl = scanCtrl;
  scanCtrl->scan_period = 10000;	/* Default to 10 second scan period*/

  list_add_last((ST_VOID **) &mvlu_rpt_scan_list, (ST_VOID *) scanCtrl);
  return (scanCtrl);
  }
/************************************************************************/
/*                       mvlu_rpt_destroy_scan_ctrl			*/
/* This function destroys a MVLU_RPT_SCAN_CTRL created by		*/
/* 'mvlu_rpt_create_scan_ctrl'						*/
/************************************************************************/
ST_VOID mvlu_rpt_destroy_scan_ctrl (MVLU_RPT_SCAN_CTRL *scanCtrl)
  {
  /* Take it off the scan control list */
  list_unlink ((ST_VOID **) &mvlu_rpt_scan_list, (ST_VOID *) scanCtrl);
  M_FREE (MSMEM_GEN, scanCtrl);
  }


/************************************************************************/
/************************************************************************/
/* 			BASRCB READ/WRITE HANDLERS			*/
/************************************************************************/

/************************************************************************/
/*			_mvlu_get_rcb 					*/
/************************************************************************/

static ST_VOID _mvlu_get_rcb (MVL_VAR_ASSOC *baseVa,
			RUNTIME_TYPE *rt,
			MVL_NET_INFO *netInfo,
			MVLU_RPT_CTRL **rptCtrlOut,
			MVLU_RPT_CLIENT **rptClientOut)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;

  *rptCtrlOut = NULL;
  *rptClientOut = NULL;

   /* Find the associated Report Control, using this RT as a key */
  rptCtrl = mvlu_rpt_ctrl_list;
  while (rptCtrl != NULL)		/* look through whole list	*/
    {
    if (rptCtrl->base_va == baseVa &&
        (rt > rptCtrl->rcbRtHead) &&
        (rt <= rptCtrl->rcbRtHead + rptCtrl->rcbRtHead->u.str.num_rt_blks))
      {
      *rptCtrlOut = rptCtrl;
      break;
      }
    rptCtrl = (MVLU_RPT_CTRL *) list_get_next (mvlu_rpt_ctrl_list, rptCtrl);
    }
  if (*rptCtrlOut == NULL)
    {
    MVL_LOG_NERR0 ("Warning: could not find report control");
    return;
    }

  /* Report Control found.	*/
  assert (rptCtrl->rcb_type == RCB_TYPE_UCA);	/* must be UCA URCB*/

   /* Now see if this connection has an active client */
  rptClient = rptCtrl->rpt_client_list;
  while (rptClient != NULL)		/* look through whole list	*/
    {
    if (rptClient->netInfo == netInfo)
      break;				/* return a pointer to it	*/

    rptClient = (MVLU_RPT_CLIENT *) list_get_next (rptCtrl->rpt_client_list, rptClient);
    }
  *rptClientOut = rptClient;
  }


/************************************************************************/
/*			_mvlu_get_rd_rcb 				*/
/* NOTE: Caller can access MVLU_RPT_CTRL, if needed, by using "rpt_ctrl"*/
/* member of MVLU_RPT_CLIENT.						*/
/************************************************************************/
MVLU_BASRCB *_mvlu_get_rd_rcb (MVLU_RD_VA_CTRL *mvluRdVaCtrl,
				MVLU_RPT_CLIENT **rptClientOut)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;
MVLU_BASRCB *rcb;

  /* Try to find 61850 RCB first. If found, return it.	*/
  if ((rcb = mvl61850_get_rcb (mvluRdVaCtrl->rdVaCtrl->va->base_va,
	    mvluRdVaCtrl->rt,
            rptClientOut)) != NULL)
    return (rcb);

  /* Could not find 61850 RCB, so now try to find UCA RCB.	*/

  /* NOTE: Need net_info to find correct UCA RCB, so if it's not */
  /* known, give up now. This problem can occur if user includes*/
  /* RCB element in a Report DataSet (not supported for UCA).	*/
  if (mvluRdVaCtrl->indCtrl->event == NULL  ||
      mvluRdVaCtrl->indCtrl->event->net_info == NULL)
    return (NULL);	/* don't know the connection, so can't find UCA RCB.*/

  _mvlu_get_rcb (mvluRdVaCtrl->rdVaCtrl->va->base_va,
	    mvluRdVaCtrl->rt,
  	    mvluRdVaCtrl->indCtrl->event->net_info,
	    &rptCtrl,
	    &rptClient);

  if (rptClientOut != NULL)
    *rptClientOut = rptClient;

/* If we have a report client, use it's BASRCB */
  if (rptClient != NULL)
    return (&rptClient->basrcb);

/* If not, and the report control was found, use the commom data */
  if (rptCtrl != NULL)
    return (&rptCtrl->common_basrcb);

/* Whoops, could not find the report control at all */
  return (NULL);
  }

/************************************************************************/
/*                       _mvlu_get_wr_rcb					*/
/* NOTE: Caller can access MVLU_RPT_CTRL, if needed, by using "rpt_ctrl"*/
/* member of MVLU_RPT_CLIENT.						*/
/************************************************************************/
MVLU_BASRCB *_mvlu_get_wr_rcb (MVLU_WR_VA_CTRL *mvluWrVaCtrl,
				      MVLU_RPT_CLIENT **rptClientOut)
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_CLIENT *rptClient;
MVL_NET_INFO *netInfo;
MVLU_RPT_CLIENT *foundClient=NULL;	/* If correct Client found,	*/
					/* this is set to point to it.	*/
MVLU_BASRCB *rcb;

  /* Try to find 61850 RCB first. If found, return it.	*/
  if ((rcb = mvl61850_get_rcb (mvluWrVaCtrl->wrVaCtrl->va->base_va,
	    mvluWrVaCtrl->rt,
            rptClientOut)) != NULL)
    return (rcb);

/* Find the associated Report Control */
  netInfo = mvluWrVaCtrl->indCtrl->event->net_info;
  _mvlu_get_rcb (mvluWrVaCtrl->wrVaCtrl->va->base_va,
	    mvluWrVaCtrl->rt,
  	    netInfo,
	    &rptCtrl,
	    &rptClient);

  if (rptClient)   			/* if Client was found,	*/
    foundClient = rptClient;		/* use it	*/
  else if (rptCtrl)			/* else if rptCtrl was found,	*/
    foundClient = _mvlu_add_rpt_client (rptCtrl, netInfo);	/* add client, use it*/

  /* Set caller's ptr.	*/
  if (rptClientOut != NULL)
    *rptClientOut = foundClient;

  /* If client found, return its basrcb, else return NULL.	*/
  return (foundClient ? (&foundClient->basrcb) : NULL);
  }
/************************************************************************/
/*			_rcb_writable					*/
/* Check if an RCB element is writable at this moment.			*/
/* NOTE: Special RCB elements may require additional checking.		*/
/* RETURNS: SD_TRUE if writable, SD_FALSE if NOT writable.		*/
/************************************************************************/
ST_RET _rcb_writable (MVLU_BASRCB *rcb,	MVLU_RPT_CLIENT *rptClient,
	MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_RET writable;

  writable = SD_FALSE;	/* assume NOT writable. Change if conditions correct.*/

  /* First, the "rcb" must be valid (!=NULL), and NOT enabled.	*/
  if (rcb != NULL  &&  rcb->RptEna == 0)
    {	/* if rcb is valid, rptClient must also be valid	*/
    assert (rptClient != NULL);
    if (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_URCB)
      {	/* if not reserved OR reserved by us, allow write.	*/
      if (rcb->Resv == 0  ||  rptClient->netInfo == mvluWrVaCtrl->indCtrl->event->net_info)
        writable = SD_TRUE;
      }
    else	/* rcb_type == RCB_TYPE_IEC_BRCB or RCB_TYPE_UCA	*/
      {	/* nothing else to check, allow write.	*/
      writable = SD_TRUE;
      }
    }
  return (writable);
  }

/************************************************************************/
/*			_mvlu_add_rpt_client 				*/
/************************************************************************/

static MVLU_RPT_CLIENT *_mvlu_add_rpt_client (MVLU_RPT_CTRL *rptCtrl,
				              MVL_NET_INFO *netInfo)
  {
MVLU_RPT_CLIENT *rptClient;
ST_INT rptClientSize;
ST_INT numDsVars;
ST_INT changed_flags_size;

  assert (rptCtrl->rcb_type == RCB_TYPE_UCA);	/* this funct only for UCA*/
/* Alloc report control client enough to contain the reasons and 	*/
/* changed_flags data							*/
  numDsVars = rptCtrl->dsNvl->num_of_entries;
  changed_flags_size = BSTR_NUMBITS_TO_NUMBYTES(numDsVars);
  rptClientSize = sizeof (MVLU_RPT_CLIENT) +
	(numDsVars * sizeof (ST_UINT8)) +	  /* reasons_data     	*/
	2 * changed_flags_size;	/* changed_flags & segmented_inclusion	*/

  rptClient = M_CALLOC (MSMEM_GEN, 1, rptClientSize);
  rptClient->rpt_ctrl = rptCtrl;
  rptClient->netInfo = netInfo;
  memcpy (&rptClient->basrcb, &rptCtrl->common_basrcb, sizeof (MVLU_BASRCB));
  rptClient->reasons_data = (ST_UINT8 *) (rptClient + 1);
  rptClient->changed_flags = (ST_UINT8 *) (rptClient->reasons_data + numDsVars);
  rptClient->segmented_inclusion = rptClient->changed_flags + changed_flags_size;

  list_add_last((ST_VOID **) &rptCtrl->rpt_client_list, (ST_VOID *) rptClient);
  ++rptCtrl->num_rpt_clients;

  _mvlu_rpt_disconnect_rcvd_fun = _mvlu_rpt_disconnect_rcvd;
  return (rptClient);
  }

/************************************************************************/
/*			_mvlu_free_rpt_client 				*/
/************************************************************************/

static ST_VOID _mvlu_free_rpt_client (MVLU_RPT_CLIENT *rptClient)
  {
  M_FREE (MSMEM_GEN, rptClient);
  }

/************************************************************************/
/************************************************************************/
/*			mvlu_rptid_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_rptid_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_CHAR *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;

  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_CHAR *) mvluRdVaCtrl->primData;
    strcpy (dest, rcb->RptID);
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_rptena_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_rptena_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_BOOLEAN *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_BOOLEAN *) mvluRdVaCtrl->primData;
    *dest = rcb->RptEna;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_resv_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_resv_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_BOOLEAN *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_BOOLEAN *) mvluRdVaCtrl->primData;
    *dest = rcb->Resv;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_datsetna_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_datsetna_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_CHAR *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    assert (strlen(rcb->DatSetNa) <= (size_t)abs(mvluRdVaCtrl->rt->u.p.el_len));
    dest = mvluRdVaCtrl->primData;
    strcpy (dest, rcb->DatSetNa);
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_optflds_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_optflds_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    assert (rcb->OptFlds.len_1 <= sizeof(rcb->OptFlds.data_1)*8);
    bvstrcpy ((MMS_BVSTRING *) mvluRdVaCtrl->primData,
              (MMS_BVSTRING *) &rcb->OptFlds);
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_buftim_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_buftim_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_UINT32 *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_UINT32 *) mvluRdVaCtrl->primData;
    *dest = rcb->BufTim;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*	       		mvlu_trgs_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_trgs_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_UINT16 *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_UINT16 *) mvluRdVaCtrl->primData;
    *dest = rcb->Trgs;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_sqnum_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_sqnum_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_UINT8 *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_UINT8 *) mvluRdVaCtrl->primData;
    *dest = rcb->SqNum;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_trgops_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_trgops_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    assert (rcb->TrgOps.len <= sizeof(rcb->TrgOps.data)*8);
    bvstrcpy ((MMS_BVSTRING *) mvluRdVaCtrl->primData,
              (MMS_BVSTRING *) &rcb->TrgOps);
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_rbepd_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_rbepd_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_UINT32 *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_UINT32 *) mvluRdVaCtrl->primData;
    *dest = rcb->RBEPd;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_intgpd_rd_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_intgpd_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
ST_UINT32 *dest;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_rd_rcb (mvluRdVaCtrl, NULL);
  if (rcb != NULL)
    {
    dest = (ST_UINT32 *) mvluRdVaCtrl->primData;
    *dest = rcb->IntgPd;
    rc = SD_SUCCESS;
    }
  mvlu_rd_prim_done (mvluRdVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_rptid_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_rptid_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_CHAR *src;
MVLU_BASRCB *rcb;
ST_RET rc;
MVLU_RPT_CLIENT *rptClient;
ST_BOOLEAN do_purge = SD_FALSE;	/* Chg to SD_TRUE if Purge Buffer required*/

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (_rcb_writable (rcb, rptClient, mvluWrVaCtrl))
    {
    src = mvluWrVaCtrl->primData;
    if (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_BRCB
        && strcmp (rcb->RptID, src))
      do_purge = SD_TRUE;	/* BRCB & val changed, must purge buffer*/
    strcpy (rcb->RptID, src);
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  if (do_purge)
    mvl61850_brcb_rpt_lists_clean (&rptClient->rpt_ctrl->brcbCtrl);

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvl61850_brcb_handle_rptena_wr			*/
/* Process "RptEna" write for 61850 BRCB.				*/
/************************************************************************/
ST_RET mvl61850_brcb_handle_rptena_wr (MVLU_RPT_CLIENT *rptClient, MVLU_BASRCB *rcb,
	MVL_NET_INFO *net_info, ST_BOOLEAN newval)
  {
ST_RET retCode;
  if (rptClient->netInfo == NULL  ||
      rptClient->netInfo == net_info)
    {	/* BRCB not enabled, or already enabled by us, so allow write.*/
    retCode = SD_SUCCESS;	/* allow write		*/
    if (newval != 0)
      {	/* trying to enable	*/
      rptClient->rpt_ctrl->brcbCtrl.enabled_once = SD_TRUE;
      rptClient->netInfo = net_info;	/* reserve BRCB	*/
      rcb->SqNumInt16u = 0;			/* reset SqNum	*/
      }
    else
      {	/* trying to disable	*/
      rptClient->netInfo = NULL;	/* release BRCB reservation	*/
      }
    }
  return (retCode);
  }
/************************************************************************/
/*			mvl61850_urcb_handle_rptena_wr			*/
/* Process "RptEna" write for 61850 URCB.				*/
/************************************************************************/
ST_RET mvl61850_urcb_handle_rptena_wr (MVLU_RPT_CLIENT *rptClient, MVLU_BASRCB *rcb,
	MVL_NET_INFO *net_info, ST_BOOLEAN newval)
  {
ST_RET retCode;
  if (rptClient->netInfo == NULL  ||
      rptClient->netInfo == net_info)
    {	/* RCB not reserved, or reserved by us	*/
    retCode = SD_SUCCESS;	/* allow write	*/
    if (newval != 0)
      {	/* enabling RCB	*/
      if (rcb->Resv == 0)	/* If URCB not reserved yet,	*/
        rcb->Resv = 1;		/* reserve it now.		*/
      rcb->SqNum = 0;	/* reset SqNum for URCB only	*/
      rptClient->netInfo = net_info;	/* reserve RCB	*/
      }
    /* If newval==0, do nothing (just allow write). RCB not released until Resv set to 0.*/
    }
  else
    {	/* RCB reserved by someone else		*/
    retCode = SD_FAILURE;	/* DO NOT allow write	*/
    }
  return (retCode);
  }

/************************************************************************/
/*			mvlu_rptena_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_rptena_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_BOOLEAN newval;	/* val to write to RptEna	*/
MVLU_BASRCB *rcb;
MVLU_RPT_CLIENT *rptClient;
ST_RET rc;
MVL_NET_INFO *net_info;	/* current connection info	*/

  net_info = mvluWrVaCtrl->indCtrl->event->net_info;

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (rcb != NULL)
    {
    newval = *(ST_BOOLEAN *) mvluWrVaCtrl->primData;
    /* CRITICAL: don't allow enable if dataSet not set (dsNvl==NULL).	*/
    if (newval != 0 && rptClient->rpt_ctrl->dsNvl == NULL)
      {		/* Just log it. rc already set.*/
      MVL_LOG_NERR0 ("Cannot enable RCB with NULL DataSet.");
      }
    else
      {
      switch (rptClient->rpt_ctrl->rcb_type)
        {
        case RCB_TYPE_IEC_BRCB:
          rc = mvl61850_brcb_handle_rptena_wr (rptClient, rcb, net_info, newval);
          break;
        case RCB_TYPE_IEC_URCB:
          rc = mvl61850_urcb_handle_rptena_wr (rptClient, rcb, net_info, newval);
          break;
        default:	/* must be UCA URCB	*/
          rc = SD_SUCCESS;	/* ALWAYS allow write for URCB	*/
          if (newval != 0)	/* enabling RCB	*/
            rcb->SqNum = 0;	/* reset SqNum for URCB only	*/
          break;
        }
      }
    }

  /* If allowing write, store new value.	*/
  if (rc == SD_SUCCESS)
    rcb->RptEna = newval;
  else	/* for any error, return TEMP_UNAVAIL	*/
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_resv_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_resv_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
MVLU_BASRCB *rcb;
MVLU_RPT_CLIENT *rptClient;
ST_RET rc = SD_FAILURE;

  /* Only for 61850, so use mvl61850_get_rcb, not mvlu_get_wr_rcb.	*/
  rcb = mvl61850_get_rcb (mvluWrVaCtrl->wrVaCtrl->va->base_va,
	    mvluWrVaCtrl->rt,
            &rptClient);
  if (rcb != NULL)
    {
    assert (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_URCB);
    if (rptClient->netInfo == NULL  ||
        rptClient->netInfo == mvluWrVaCtrl->indCtrl->event->net_info)
      {	/* RCB not reserved, or reserved by us, so allow write.*/
      rc = SD_SUCCESS;	/* allow write	*/
      rcb->Resv = *(ST_BOOLEAN *) mvluWrVaCtrl->primData;
      if (rcb->Resv != 0)
        rptClient->netInfo = mvluWrVaCtrl->indCtrl->event->net_info;	/* reserve RCB	*/
      else
        rptClient->netInfo = NULL;					/* unreserve RCB*/
      }
    /* else rc=SD_FAILURE already set	*/
    }

  if (rc != SD_SUCCESS)
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_optflds_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_optflds_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
MVLU_BASRCB *rcb;
ST_RET rc;
MMS_BVSTRING *bvstr;
ST_INT numbits;
MVLU_RPT_CLIENT *rptClient;

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (_rcb_writable (rcb, rptClient, mvluWrVaCtrl))
    {
    /* Use 'rcb_type' to figure out how many bits are writable.	*/
    ST_INT rcb_type = rptClient->rpt_ctrl->rcb_type;

    bvstr = (MMS_BVSTRING *)  mvluWrVaCtrl->primData;
    /* NOTE: don't change OptFlds.len_1. May only be writing a few	*/
    /* bits, but want to send ALL bits in read response or Info Rpt.	*/

    if (rcb_type == RCB_TYPE_UCA)
      {
      numbits = min (bvstr->len, 5);	/* 5 bits writable. Ignore higher bits.*/
      bstrcpy (rcb->OptFlds.data_1, bvstr->data, numbits);
      }
    else
      {		/* must be either IEC_URCB or IEC_BRCB	*/
      numbits = min (bvstr->len, 9);	/* 9 bits writable. Ignore higher bits.*/
      bstrcpy (rcb->OptFlds.data_1, bvstr->data, numbits);
      if (rcb_type == RCB_TYPE_IEC_URCB)
        {	/* 61850-8-1 says to ignore buffer-overflow, entryID bits, so clear them*/
        BSTR_BIT_SET_OFF (rcb->OptFlds.data_1, OPTFLD_BITNUM_BUFOVFL);
        BSTR_BIT_SET_OFF (rcb->OptFlds.data_1, OPTFLD_BITNUM_ENTRYID);
        }
      }
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_buftim_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_buftim_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_UINT32 *src;
MVLU_BASRCB *rcb;
ST_RET rc;
MVLU_RPT_CLIENT *rptClient;
ST_BOOLEAN do_purge = SD_FALSE;	/* Chg to SD_TRUE if Purge Buffer required*/

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (_rcb_writable (rcb, rptClient, mvluWrVaCtrl))
    {
    src = (ST_UINT32 *) mvluWrVaCtrl->primData;
    if (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_BRCB
        && rcb->BufTim != *src)
      do_purge = SD_TRUE;	/* BRCB & val changed, must purge buffer*/
    rcb->BufTim = *src;
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  if (do_purge)
    mvl61850_brcb_rpt_lists_clean (&rptClient->rpt_ctrl->brcbCtrl);

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_trgs_wr_ind_fun				*/
/* NOTE: for UCA RCB only.						*/
/************************************************************************/

ST_VOID mvlu_trgs_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_UINT16 *src;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, NULL);
  if (rcb != NULL && rcb->RptEna == SD_FALSE)	/* if enabled, can't write*/
    {
    src = (ST_UINT16 *) mvluWrVaCtrl->primData;
    rcb->Trgs = *src;
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*                       mvlu_sqnum_wr_ind_fun				*/
/* NOTE: for UCA RCB only. In IEC 61850 RCB, SqNum may not be written.	*/
/************************************************************************/

ST_VOID mvlu_sqnum_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_UINT8 *src;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, NULL);
  if (rcb != NULL && rcb->RptEna == SD_FALSE)	/* if enabled, can't write*/
    {
    src =(ST_UINT8 *)  mvluWrVaCtrl->primData;
    rcb->SqNum = *src;
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_trgops_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_trgops_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
MVLU_BASRCB *rcb;
ST_RET rc;
MMS_BVSTRING *bvstr;
MVLU_RPT_CLIENT *rptClient;
ST_BOOLEAN do_purge = SD_FALSE;	/* Chg to SD_TRUE if Purge Buffer required*/

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (_rcb_writable (rcb, rptClient, mvluWrVaCtrl))
    {
    bvstr = (MMS_BVSTRING *)  mvluWrVaCtrl->primData;
    /* NOTE: don't change TrgOps.len. May only be writing a few	*/
    /* bits, but want to send ALL bits in read response or Info Rpt.	*/

    assert (bvstr->len <= (sizeof (rcb->TrgOps.data)*8));
    if (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_BRCB
        && bstrcmp (rcb->TrgOps.data, bvstr->data, bvstr->len))
      do_purge = SD_TRUE;	/* BRCB & val changed, must purge buffer*/
    bstrcpy (rcb->TrgOps.data, bvstr->data, bvstr->len);
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  if (do_purge)
    mvl61850_brcb_rpt_lists_clean (&rptClient->rpt_ctrl->brcbCtrl);

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_rbepd_wr_ind_fun				*/
/* NOTE: for UCA RCB only.						*/
/************************************************************************/

ST_VOID mvlu_rbepd_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_UINT32 *src;
MVLU_BASRCB *rcb;
ST_RET rc;

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, NULL);
  if (rcb != NULL && rcb->RptEna == SD_FALSE)	/* if enabled, can't write*/
    {
    src = (ST_UINT32 *) mvluWrVaCtrl->primData;
    rcb->RBEPd = *src;
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/*			mvlu_intgpd_wr_ind_fun				*/
/************************************************************************/

ST_VOID mvlu_intgpd_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
ST_UINT32 *src;
MVLU_BASRCB *rcb;
ST_RET rc;
MVLU_RPT_CLIENT *rptClient;
ST_BOOLEAN do_purge = SD_FALSE;	/* Chg to SD_TRUE if Purge Buffer required*/

  rc = SD_FAILURE;
  rcb = _mvlu_get_wr_rcb (mvluWrVaCtrl, &rptClient);
  if (_rcb_writable (rcb, rptClient, mvluWrVaCtrl))
    {
    src = (ST_UINT32 *) mvluWrVaCtrl->primData;
    if (rptClient->rpt_ctrl->rcb_type == RCB_TYPE_IEC_BRCB
        && rcb->IntgPd != *src)
      do_purge = SD_TRUE;	/* BRCB & val changed, must purge buffer*/
    rcb->IntgPd = *src;
    rc = SD_SUCCESS;
    }
  else
    mvluWrVaCtrl->wrVaCtrl->failure = ARE_TEMP_UNAVAIL;

  if (do_purge)
    mvl61850_brcb_rpt_lists_clean (&rptClient->rpt_ctrl->brcbCtrl);

  mvlu_wr_prim_done (mvluWrVaCtrl, rc);
  }

/************************************************************************/
/************************************************************************/
/* For backward compatibility ... do not use */
ST_VOID mvlu_seqnum_rd_ind_fun (MVLU_RD_VA_CTRL *mvluRdVaCtrl)
  {
  mvlu_sqnum_rd_ind_fun (mvluRdVaCtrl);
  }
ST_VOID mvlu_seqnum_wr_ind_fun (MVLU_WR_VA_CTRL *mvluWrVaCtrl)
  {
  mvlu_sqnum_wr_ind_fun (mvluWrVaCtrl);
  }

/*
 *			mvlu_integrity_scan_destroy
 * Free data allocated by mvlu_integrity_scan_read.
 */
ST_VOID mvlu_integrity_scan_destroy (MVL_IND_PEND *indCtrl)
  {
  M_FREE (MSMEM_GEN, indCtrl);
  }

/*
 *			mvlu_integrity_scan_read
 * This function "BEGINS" the scan of ALL data for one Report DataSet (NVL).
 * It is called automatically when an Integrity Report or a
 * General Interrogation Report needs to be sent. This is much more
 * efficient than constantly scanning.
 * - It allocates & initializes a temporary MVL_IND_PEND structure.
 * - It calls "u_mvl_read_ind" to begin the scan.
 * - The scan may complete synchronously or asynchronously.
 * - When the scan completes, the funct pointed to by "scan_done_fun" arg
 *   is called to build the report and cleanup.
 * CRITICAL: Function pointed to by "scan_done_fun" must call
 * "mvlu_integrity_scan_destroy" to free temporary MVL_IND_PEND struct.
 */

ST_VOID mvlu_integrity_scan_read (MVLU_RPT_CLIENT *rptClient,
			ST_VOID (*scan_va_done_fun)(MVL_IND_PEND *indCtrl,
					MVL_VAR_ASSOC *va),
			ST_RET (*scan_done_fun)(MVL_IND_PEND *indCtrl)
			)
  {
MVL_IND_PEND *indCtrl;

  /* Create a simulated read indication for the DataSet NVL.	*/
  indCtrl = mvlu_setup_scan_read (rptClient->rpt_ctrl->dsNvl,
                          scan_va_done_fun, scan_done_fun);

  indCtrl->usr_ind_ctrl = rptClient;	/* Save rptClient		*/

  /* OK, now fire off the read indication functions.	*/
  u_mvl_read_ind (indCtrl);
  }

/**
 *			mvlu_setup_scan_read
 * This function sets up the scan of ALL data for one NVL.
 * It allocates & initializes a temporary MVL_IND_PEND structure for a
 * simulated read indication.
 * RETURNS: (MVL_IND_PEND *)
 */

MVL_IND_PEND *mvlu_setup_scan_read (MVL_NVLIST_CTRL *nvl,
		ST_VOID (*scan_va_done_fun)(MVL_IND_PEND *indCtrl,
					MVL_VAR_ASSOC *va),
		ST_RET (*scan_done_fun)(MVL_IND_PEND *indCtrl)
		)
  {
MVLAS_RD_VA_CTRL *vaCtrl;
MVL_IND_PEND *indCtrl;
ST_INT j;

/* Allocate space for MVL_IND_PEND & array of MVLAS_RD_VA_CTRL.	*/
  indCtrl = M_CALLOC (MSMEM_GEN, 1,
              sizeof (MVL_IND_PEND) +
              nvl->num_of_entries * sizeof (MVLAS_RD_VA_CTRL));

  indCtrl->u.rd.numVar = nvl->num_of_entries;
  indCtrl->op = MMSOP_MVLU_RPT_VA;	/* indicates this is not normal read*/

  indCtrl->u.rd.vaCtrlTbl = (MVLAS_RD_VA_CTRL *)(indCtrl+1);/*point after indCtrl*/

  for (j = 0, vaCtrl = indCtrl->u.rd.vaCtrlTbl;
       j < nvl->num_of_entries;
       j++, vaCtrl++)
    {
    vaCtrl->va = nvl->entries[j];
    memcpy (&vaCtrl->va_scope, &nvl->va_scope[j], sizeof(MVL_SCOPE));
    }

  /* Save funct ptr. Called from "mvlu_rd_prim_done" when scan of ONE va complete.*/
  indCtrl->scan_va_done_fun = scan_va_done_fun;

  /* Save funct ptr. Called from "mvlu_rd_prim_done" when scan complete.*/
  indCtrl->usr_resp_fun = scan_done_fun;	/* CRITICAL:	*/

  return (indCtrl);
  }

/************************************************************************/
/*			mvlu_integrity_scan_va_done			*/
/* This function is called by 'mvlu_rd_prim_done' when all "leaf"	*/
/* functions for a VA have been completed (i.e. data ready for this VA).*/
/* NOTE: Same as "_mvlu_rpt_va_reads_done" except this function ALWAYS	*/
/*       calls mvlu_rpt_va_change and sets reason_for_inclusion=INTEGRITY.*/
/************************************************************************/

ST_VOID mvlu_integrity_scan_va_done (MVL_IND_PEND *indCtrl,
					MVL_VAR_ASSOC *va)
  {
  mvlu_rpt_va_change (va, MVLU_TRGOPS_INTEGRITY, NULL);
  }

/************************************************************************/
/*			mvlu_integrity_scan_done			*/
/* Same as "_mvlu_rpt_scan_done" except arg is (MVL_IND_PEND *)		*/
/* instead of (MVLU_RPT_SCAN_CTRL *).					*/
/*									*/
/* This function is called when the integrity scan is complete.		*/
/* (i.e. 'mvlu_rd_prim_done' has been called for all "leafs" of all	*/
/* variables in the report). Everything is ready to build a report,	*/
/* so build it now.							*/
/************************************************************************/

ST_RET mvlu_integrity_scan_done (MVL_IND_PEND *indCtrl)
  {
ST_RET retCode;
MVLU_RPT_CLIENT *rptClient;

  /* Get "rptClient", saved in "indCtrl" when scan initialized.	*/
  rptClient = (MVLU_RPT_CLIENT *) indCtrl->usr_ind_ctrl;

  /* send or queue rpt	*/
  retCode = mvlu_rpt_ready (rptClient, MVLU_RPT_TYPE_INTEGRITY_OR_GI);

  if (retCode != SD_SUCCESS)
    MVLU_LOG_FLOW1 ("Integrity report send failed: err=0x%X", retCode);

  /* set time for next integrity report	*/
  rptClient->next_integ_rpt_time = sGetMsTime ()
                     + (ST_DOUBLE) rptClient->basrcb.IntgPd;
  rptClient->integ_scan_in_progress = SD_FALSE;
  mvlu_integrity_scan_destroy (indCtrl);	/* destroy temporary struct*/
  return (retCode);
  }

/************************************************************************/
/*			find_or_create_typeid				*/
/* Try to find the type_id. If that fails, try to create it.		*/
/************************************************************************/
static ST_INT find_or_create_typeid (ST_CHAR *type_name, ST_CHAR *tdl)
  {
ST_INT type_id;
  if ((type_id = mvl_typename_to_typeid (type_name)) < 0)	/* find	*/
    type_id = mvl_type_id_create_from_tdl (type_name, tdl);	/* create*/
  return (type_id);
  }

/************************************************************************/
/*			mvlu_rpt_find_typeids				*/
/* Find or create ALL types needed to encode reports.			*/
/* These types may have been defined in the ODF file and created by	*/
/* Foundry or may have been created by an earlier call to this function.*/
/* RETURNS:	SD_SUCCESS if ALL types found or created		*/
/*		SD_FAILURE if ANY type could not be found or created.	*/
/************************************************************************/
ST_RET mvlu_rpt_find_typeids (MVLU_RPT_TYPEIDS *rpt_typeids)
  {
ST_RET retCode = SD_FAILURE;	/* assume FAILURE for now	*/
ST_CHAR *type_name;		/* name of type to be found	*/

  /* stop on any error	*/
  do
    {	/* "one-time" loop: just to have something to break out of	*/
    if ((rpt_typeids->mmsbool = find_or_create_typeid (type_name = "RTYP_BOOL", "Bool")) < 0)
      break;
    if ((rpt_typeids->bstr6 = find_or_create_typeid (type_name = "RTYP_BSTR6", "Bstring6")) < 0)
      break;
    if ((rpt_typeids->bstr8 = find_or_create_typeid (type_name = "RTYP_BSTR8", "Bstring8")) < 0)
      break;
    if ((rpt_typeids->bvstring6 = find_or_create_typeid (type_name = "RTYP_BVSTR6", "Bvstring6")) < 0)
      break;
    if ((rpt_typeids->bvstring8 = find_or_create_typeid (type_name = "RTYP_BVSTR8", "Bvstring8")) < 0)
      break;
    if ((rpt_typeids->bvstring10 = find_or_create_typeid (type_name = "RTYP_BVSTR10", "Bvstring10")) < 0)
      break;
    if ((rpt_typeids->btime6 = find_or_create_typeid (type_name = "RTYP_BTIME6", "Btime6")) < 0)
      break;
    if ((rpt_typeids->int8u = find_or_create_typeid (type_name = "RTYP_INT8U", "Ubyte")) < 0)
      break;
    if ((rpt_typeids->int16u = find_or_create_typeid (type_name = "RTYP_INT16U", "Ushort")) < 0)
      break;
    if ((rpt_typeids->int32u = find_or_create_typeid (type_name = "RTYP_INT32U", "Ulong")) < 0)
      break;
    if ((rpt_typeids->ostring8 = find_or_create_typeid (type_name = "RTYP_OSTR8", "Ostring8")) < 0)
      break;
    if ((rpt_typeids->vstring32 = find_or_create_typeid (type_name = "RTYP_VSTR32", "Vstring32")) < 0)
      break;
    if ((rpt_typeids->vstring65 = find_or_create_typeid (type_name = "RTYP_VSTR65", "Vstring65")) < 0)
      break;
    if ((rpt_typeids->vstring129 = find_or_create_typeid (type_name = "RTYP_VSTR129", "Vstring129")) < 0)
      break;

    retCode = SD_SUCCESS;  /* If we get here, all were successful	*/
    } while (0);	/* end of "one-time" loop	*/

  if (retCode)
    MVL_LOG_ERR1 ("Can't find or create type '%s'", type_name);
  return (retCode);	/* If ANY find failed, SD_FAILURE is returned	*/
  }

/************************************************************************/
/*			mvlu_integrity_timeout				*/
/* Check for Integrity period timeout. If timeout occurred, start	*/
/* integrity scan.							*/
/* RETURNS: SD_TRUE if IntgPd is set and timeout occurred		*/
/*          SD_FALSE otherwise						*/
/************************************************************************/
ST_RET mvlu_integrity_timeout (MVLU_RPT_CLIENT *rptClient, ST_DOUBLE timeNow)
  {
ST_RET ret;

  if (rptClient->basrcb.IntgPd != 0
      && BSTR_BIT_GET (rptClient->basrcb.TrgOps.data, TRGOPS_BITNUM_INTEGRITY)	/* enabled*/
      && (!rptClient->integ_scan_in_progress)
      && timeNow > rptClient->next_integ_rpt_time)
    {
    MVLU_LOG_FLOW1 ("UCA Report Integrity Period timeout for client %08lx",
							rptClient);

    /* Send last buffered entry (due to BufTm buffering) BEFORE this integrity report.*/
    if (rptClient->numTrgs > 0)
      {		/* send or queue report	*/
      mvlu_rpt_ready (rptClient, MVLU_RPT_TYPE_RBE);
      }

    /* Set scan_in_progress flag so new scan can't start before last
     * scan finished. Clear flag in "mvlu_integrity_scan_done".
     */
    rptClient->integ_scan_in_progress = SD_TRUE;

    /* This function "begins" the integrity scan. When the scan is
     * complete, "mvlu_integrity_scan_done" is called to build the
     * the report. If ALL "leaf" functions are synchronous,
     * "mvlu_integrity_scan_done" is called BEFORE this function returns.
     */
    mvlu_integrity_scan_read (rptClient,
                mvlu_integrity_scan_va_done,
                mvlu_integrity_scan_done);
    ret = SD_TRUE;
    }
  else
    ret = SD_FALSE;
  return (ret);
  }

/************************************************************************/
/*			mvlu_rpt_rcb_type_find				*/
/* Find the runtime type of the RCB and save it in *rcbHeadOut & *numRtOut.*/
/************************************************************************/
ST_RET mvlu_rpt_rcb_type_find (ST_INT type_id, ST_CHAR *basrcbName,
	RUNTIME_TYPE **rcbHeadOut, ST_INT *numRtOut)
  {
ST_RET ret = SD_FAILURE;
ST_CHAR *ptr;

  ptr = strstr (basrcbName, "$");
  if (ptr)
    {
    ++ptr;	/* Skip the '$' */
    if (mvlu_find_comp_type (type_id, ptr, rcbHeadOut, numRtOut) == SD_SUCCESS)
      {
      if ((*rcbHeadOut)->el_tag == RT_STR_START)
        ret = SD_SUCCESS;	/* only path to success	*/
      else
        MVL_LOG_NERR1 ("'%s' is not a structure", basrcbName);
      }
    else
      MVL_LOG_NERR1 ("Could not find type for component '%s'", basrcbName);
    }
  else
    MVL_LOG_NERR1 ("Invalid BASRCB name: %s", basrcbName);

  return (ret);
  }

/************************************************************************/
/*			mvlu_rpt_ready					*/
/* Report is ready to send or save in "buffer".				*/
/* Check the RCB type and call appropriate function.			*/
/************************************************************************/
ST_RET mvlu_rpt_ready (MVLU_RPT_CLIENT *rptClient, ST_INT rpt_type)
  {
ST_RET retCode;
  switch (rptClient->rpt_ctrl->rcb_type)
    {
    case RCB_TYPE_UCA:
      retCode = mvlu_send_report (rptClient, rpt_type);
      break;
    case RCB_TYPE_IEC_BRCB:
      retCode = mvl61850_brcb_rpt_save (rptClient);	/* save rpt in buffer*/
      break;
    case RCB_TYPE_IEC_URCB:
      retCode = mvl61850_urcb_rpt_send (rptClient->rpt_ctrl, rptClient, rpt_type);
      break;
    default:
      retCode = SD_FAILURE;	/* should never happen	*/
      break;
    }
  return (retCode);
  }

/************************************************************************/
/*			mvlu_rpt_ctrl_destroy_all			*/
/* Destroy all UCA report controls.					*/
/************************************************************************/
ST_VOID mvlu_rpt_ctrl_destroy_all ()
  {
MVLU_RPT_CTRL *rptCtrl;
MVLU_RPT_SCAN_CTRL *scanCtrl;
  /* Use list_find_last to avoid calling list_unlink twice.	*/
  while ((scanCtrl = (MVLU_RPT_SCAN_CTRL *) list_find_last ((DBL_LNK *)mvlu_rpt_scan_list)) != NULL)
    {
    mvlu_rpt_destroy_scan_ctrl (scanCtrl);	/* this also unlinks it from list*/
    }

  /* Use list_find_last to avoid calling list_unlink twice.	*/
  while ((rptCtrl = (MVLU_RPT_CTRL *) list_find_last ((DBL_LNK *)mvlu_rpt_ctrl_list)) != NULL)
    {
    mvlu_free_rpt_ctrl (rptCtrl);	/* this also unlinks it from list*/
    }
  }
