/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	1998 - 2005, All Rights Reserved		        */
/*									*/
/* MODULE NAME : mvl_obj.c	    					*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*	mvl_vmd_dom_add							*/
/*	mvl_vmd_var_add							*/
/*	mvl_vmd_nvl_add							*/
/*	mvl_vmd_jou_add							*/
/*	mvl_vmd_dom_remove						*/
/*	mvl_vmd_var_remove						*/
/*	mvl_vmd_nvl_remove						*/
/*	mvl_vmd_jou_remove						*/
/*	mvl_nvl_create							*/
/*	mvl_nvl_destroy							*/
/*	mvl_vmd_create							*/
/*	mvl_vmd_destroy							*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 02/21/07  JRB     27    Fix funct names in this module header.	*/
/* 12/04/06  JRB     26    mvl_vmd_destroy: add arg to specify which VMD*/
/*			   and DO NOT destroy all rpt_ctrl (let user).	*/
/* 10/30/06  JRB     25    Add vmd_ctrl arg to several functions & chg	*/
/*			   prefix from "mvl_" to "mvl_vmd_".		*/
/*			   Add vmd_ctrl, net_info args to mvl_nvl_create.*/
/*			   Check that (net_info!=NULL) before using it.	*/
/*			   Move "*_delete" to mvl_objb.c with other	*/
/*			    insert/delete functions.			*/
/*			   Add mvl_vmd_create.				*/
/* 08/09/06  JRB     24    Free "last_data" only in mvl_var_destroy.	*/
/*			   Save type_ctrl in MVL_VAR_ASSOC.		*/
/*			   mvl_vmd_destroy: free mvl61850_rpt_ctrl_list.*/
/* 01/30/06  GLB     23    Integrated porting changes for VMS           */
/* 10/25/05  EJV     22    Fix "last_data" memory leaks: alloc only if	*/
/*			   last_data==NULL, free only if last_data!=NULL.*/
/* 09/22/05  JRB     21    mvl_vmd_destroy: del VMD-spec vars, NVLs too.*/
/* 06/29/05  CRM     20    Add mvl_vmd_destroy.				*/
/* 06/27/05  JRB     19    Alloc "va->last_data" in mvl_nvl_create &	*/
/*			   free it in mvl_nvl_destroy so special NVL	*/
/*			   functs not needed for IEC/UCA reports.	*/
/* 06/27/05  JRB     18	   mvl_var_create: chk type.			*/
/* 04/27/05  CRM     17    Added code to free dom->jou_tbl in           */
/*			   mvl_dom_destroy				*/
/* 06/04/04  JRB     16    mvl_var_create: if (data), set use_static_data.*/
/* 10/03/03  JRB     15    mvl_nvl_add: set nvl_scope in MVL_NVLIST_CTRL*/
/*			   mvl_nvl_add/mvl_var_add: chk for valid dom first*/
/* 02/25/02  MDE     14    Now get max PDU size from mvl_cfg_info	*/
/* 01/23/02  EJV     13    Added journals to domain:			*/
/*			     mvl_init_dom -   added max_num_jou param	*/
/*			     mvl_dom_resize - added max_num_jou param	*/
/*			     mvl_dom_create - added max_num_jou param	*/
/*			     mvl_dom_add -    added max_num_jou param	*/
/*			     mvl_clear_dom_objs -added code for journals*/
/*			     mvl_jou_delete - added DOM_SPEC  case	*/
/* 10/25/00  JRB     12    Del u_mvl funct ptrs. Call functs directly.	*/
/*			   Control with #ifdefs.			*/
/* 04/14/00  JRB     11    Move sort & compare code to mvl_objb.c	*/
/* 04/12/00  MDE     10    Moved AA resize code to mvl_acse.c		*/
/* 01/21/00  MDE     09    Now use MEM_SMEM for dynamic memory		*/
/* 09/15/99  JRB     08    Mv mvl_obj_nosort to mvl_objb.c for DOS link	*/
/* 09/13/99  MDE     07    Added SD_CONST modifiers			*/
/* 09/07/99  MDE     06    Changed MVL_VA_SCOPE to MVL_SCOPE		*/
/* 07/12/99  MDE     05    Fixed problem 'destroying' dom w/NVL or VAR	*/
/* 04/07/99  MDE     04    Logging improvements				*/
/* 03/18/99  MDE     03    Enhanced dynamic object facilities		*/
/* 01/20/99  JRB     02    Reduce # of functions. Chg names and args.	*/
/*			   Call new "mvl_???_insert" functions.		*/
/*			   Add ..nvl_remove, ..nvl_create, ..nvl_destroy*/
/* 11/18/98  MDE     01    Created					*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mvl_acse.h"
#include "mvl_log.h"
#if defined(MVL_UCA)
#include "mvl_uca.h"	/* need "MVLU_RPT_*"	*/
#endif

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/
/************************************************************************/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif


ST_VOID _mvl_clear_aa_objs (MVL_AA_OBJ_CTRL *aa_objs);

ST_VOID (*u_mvl_dom_destroy) (MVL_DOM_CTRL *dom);
ST_VOID (*u_mvl_var_destroy)(MVL_VAR_ASSOC *va);
ST_VOID (*u_mvl_nvl_destroy) (MVL_NVLIST_CTRL *nvl);
ST_VOID (*u_mvl_jou_destroy) (MVL_JOURNAL_CTRL *jou);

/************************************************************************/
/************************************************************************/
/* SCOPE INITIALIZING FUNCTIONS 					*/
/************************************************************************/
/*			mvl_init_vmd 					*/
/************************************************************************/

ST_RET mvl_init_vmd (ST_INT max_num_dom, ST_INT max_num_var, 
		      ST_INT max_num_nvl, ST_INT max_num_jou)
  {
ST_RET rc;

/* Delete all objects in the VMD */
  rc = mvl_clear_vmd_objs ();

  if (rc == SD_SUCCESS)
    mvl_vmd_resize (max_num_dom, max_num_var, max_num_nvl, max_num_jou);

  return (rc);
  }


/************************************************************************/
/*			mvl_init_dom 					*/
/************************************************************************/

ST_RET mvl_init_dom (MVL_DOM_CTRL *dom, ST_INT max_num_var, 
		      ST_INT max_num_nvl, ST_INT max_num_jou)
  {
ST_RET rc;

  /* Delete all objects in the domain */
  rc = mvl_clear_dom_objs (dom);

  if (rc == SD_SUCCESS)
    mvl_dom_resize (dom, max_num_var, max_num_nvl, max_num_jou);

  return (rc);
  }

/************************************************************************/
/*			mvl_init_aa 					*/
/************************************************************************/

ST_RET mvl_init_aa (ST_INT max_num_var, ST_INT max_num_nvl, 
	            ST_INT max_num_jou)
  {
ST_RET rc;

  rc = mvl_clear_aa_objs ();
  if (rc == SD_SUCCESS)
    mvl_aa_resize (max_num_var, max_num_nvl, max_num_jou);

  return (rc);
  }


/************************************************************************/
/************************************************************************/
/* CLEAR SCOPE 								*/
/************************************************************************/
/************************************************************************/
/*			mvl_clear_vmd_objs 				*/
/************************************************************************/

ST_RET mvl_clear_vmd_objs (ST_VOID)
  {
ST_INT i;

  if (mvl_vmd.foundry_objects)
    {
    MVL_LOG_NERR0 ("mvl_clear_vmd_objs: Foundry objects present, cannot clear"); 
    return (SD_FAILURE);
    }

/* Delete NVL's. We need to delete the 'entries' pointer table for each	*/
/* NVL, then delete the table of NVL's.					*/
  if (mvl_vmd.max_num_nvlist)
    {
    for (i = 0; i < mvl_vmd.num_nvlist; ++i)
      mvl_nvl_destroy (mvl_vmd.nvlist_tbl[i]);
    }    

/* Delete the variable association table.				*/
  if (mvl_vmd.max_num_var_assoc)
    {
    for (i = 0; i < mvl_vmd.num_var_assoc; ++i)
      mvl_var_destroy (mvl_vmd.var_assoc_tbl[i]);
    }

/* Delete the domains. This means deleting the contents of each domain	*/
/* then the domain control table.					*/
  if (mvl_vmd.max_num_dom)
    {
    for (i = 0; i < mvl_vmd.num_dom; ++i)
      mvl_dom_destroy (mvl_vmd.dom_tbl[i]);
    }

/* Delete the Journal control table.					*/
  if (mvl_vmd.max_num_jou)
    {
    for (i = 0; i < mvl_vmd.num_jou; ++i)
      mvl_jou_destroy (mvl_vmd.jou_tbl[i]);
    }

  mvl_vmd.num_dom = 0;
  mvl_vmd.num_var_assoc = 0;
  mvl_vmd.num_nvlist = 0;
  mvl_vmd.num_jou = 0;
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			mvl_clear_dom_objs 				*/
/************************************************************************/

ST_RET mvl_clear_dom_objs (MVL_DOM_CTRL *dom)
  {
ST_INT i;

  if (dom->foundry_objects)
    {
    MVL_LOG_NERR0 ("mvl_clear_dom_objs: Foundry objects present, cannot clear"); 
    return (SD_FAILURE);
    }


  if (dom->max_num_nvlist)
    {
    for (i = 0; i < dom->num_nvlist; ++i)
      mvl_nvl_destroy (dom->nvlist_tbl[i]);
    }
  if (dom->max_num_var_assoc)
    {
    for (i = 0; i < dom->num_var_assoc; ++i)
      mvl_var_destroy (dom->var_assoc_tbl[i]);
    }
/* Delete the Journal control table.					*/
  if (dom->max_num_jou)
    {
    for (i = 0; i < dom->num_jou; ++i)
      mvl_jou_destroy (dom->jou_tbl[i]);
    }

  dom->num_nvlist = 0;
  dom->num_var_assoc = 0;
  dom->num_jou = 0;
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			mvl_clear_aa_objs				*/
/************************************************************************/

ST_RET mvl_clear_aa_objs ()
  {
ST_INT i;
MVL_AA_OBJ_CTRL *aa_objs;

  for (i = 0; i < mvl_cfg_info->num_called; ++i)
    {
    aa_objs = mvl_called_conn_ctrl[i].aa_objs;
    if (aa_objs->foundry_objects)
      {
      MVL_LOG_NERR0 ("mvl_clear_aa_objs: Foundry objects present, cannot clear"); 
      return (SD_FAILURE);
      }
    _mvl_clear_aa_objs (aa_objs);
    }

  for (i = 0; i < mvl_cfg_info->num_calling; ++i)
    {
    aa_objs = mvl_calling_conn_ctrl[i].aa_objs;
    if (aa_objs->foundry_objects)
      {
      MVL_LOG_NERR0 ("mvl_clear_aa_objs: Foundry objects present, cannot clear"); 
      return (SD_FAILURE);
      }
    _mvl_clear_aa_objs (aa_objs);
    }
  return (SD_SUCCESS);
  }


/************************************************************************/
/* SCOPE RESIZING FUNCTIONS 						*/
/************************************************************************/
/************************************************************************/
/*			mvl_vmd_resize 					*/
/************************************************************************/

ST_VOID mvl_vmd_resize (ST_INT max_num_dom, ST_INT max_num_var, 
			ST_INT max_num_nvl, ST_INT max_num_jou)
  {
  if (max_num_dom < mvl_vmd.num_dom)
    {
    MVL_LOG_NERR0 ("Resizing VMD: new max DOM is less than current"); 
    max_num_dom = mvl_vmd.num_dom;
    }
  if (max_num_var < mvl_vmd.num_var_assoc)
    {
    MVL_LOG_NERR0 ("Resizing VMD: new max VA is less than current"); 
    max_num_var = mvl_vmd.num_var_assoc;
    }
  if (max_num_nvl < mvl_vmd.num_nvlist)
    {
    MVL_LOG_NERR0 ("Resizing VMD: new max NVL is less than current"); 
    max_num_nvl = mvl_vmd.num_nvlist;
    }
  if (max_num_jou < mvl_vmd.num_jou)
    {
    MVL_LOG_NERR0 ("Resizing VMD: new max JOU is less than current"); 
    max_num_jou = mvl_vmd.num_jou;
    }

  _mvl_resize_ptr_tbl (&(mvl_vmd.max_num_dom), 
  		         (ST_VOID ***)&(mvl_vmd.dom_tbl), max_num_dom);
  _mvl_resize_ptr_tbl (&(mvl_vmd.max_num_var_assoc), 
  		         (ST_VOID ***)&(mvl_vmd.var_assoc_tbl), max_num_var);
  _mvl_resize_ptr_tbl (&(mvl_vmd.max_num_nvlist), 
  		         (ST_VOID ***)&(mvl_vmd.nvlist_tbl), max_num_nvl);
  _mvl_resize_ptr_tbl (&(mvl_vmd.max_num_jou), 
  		         (ST_VOID ***)&(mvl_vmd.jou_tbl), max_num_jou);
  }

/************************************************************************/
/*			mvl_dom_resize 					*/
/************************************************************************/

ST_VOID mvl_dom_resize (MVL_DOM_CTRL *dom, ST_INT max_num_var, 
			ST_INT max_num_nvl, ST_INT max_num_jou)
  {
  if (max_num_var < dom->num_var_assoc)
    {
    MVL_LOG_NERR0 ("Resizing Domain: new max VA is less than current"); 
    max_num_var = dom->num_var_assoc;
    }
  if (max_num_nvl < dom->num_nvlist)
    {
    MVL_LOG_NERR0 ("Resizing Domain: new max NVL is less than current"); 
    max_num_nvl = dom->num_nvlist;
    }
  if (max_num_jou < dom->num_jou)
    {
    MVL_LOG_NERR0 ("Resizing Domain: new max JOU is less than current"); 
    max_num_jou = dom->num_jou;
    }

  _mvl_resize_ptr_tbl (&(dom->max_num_var_assoc), 
  		         (ST_VOID ***)&(dom->var_assoc_tbl), max_num_var);
  _mvl_resize_ptr_tbl (&(dom->max_num_nvlist), 
  		         (ST_VOID ***)&(dom->nvlist_tbl), max_num_nvl);
  _mvl_resize_ptr_tbl (&(dom->max_num_jou), 
  		         (ST_VOID ***)&(dom->jou_tbl), max_num_jou);
  }

/************************************************************************/
/*			_mvl_resize_ptr_tbl 				*/
/************************************************************************/

ST_VOID _mvl_resize_ptr_tbl (ST_INT *p_max_num, 
			     ST_VOID ***p_ptr_tbl, ST_INT new_size)
  {

/* See if something needs to be done at all */
  if (*p_max_num == new_size)
    return;

/* See if the table is going away altogether */
  if (new_size != 0)
    { 
    if (*p_max_num != 0)
      *p_ptr_tbl = (ST_VOID **) M_REALLOC (MSMEM_GEN, *p_ptr_tbl, (new_size * sizeof (ST_VOID *)));
    else   /* We did not have a table, but need one now */
      *p_ptr_tbl = (ST_VOID **) M_CALLOC (MSMEM_GEN, new_size, sizeof (ST_VOID *));
    }
  else	
    { 	/* If we had a table, we need to free it */
    if (*p_max_num != 0)
      M_FREE (MSMEM_GEN, *p_ptr_tbl); 
    }
  *p_max_num = new_size;
  }

/************************************************************************/
/************************************************************************/
/* DOMAIN								*/
/************************************************************************/
/************************************************************************/
/*			mvl_vmd_dom_add					*/
/* Add a domain. Allocate, fill in, and insert into table.		*/
/************************************************************************/

MVL_DOM_CTRL *mvl_vmd_dom_add (MVL_VMD_CTRL *vmd_ctrl, ST_CHAR *name, ST_INT max_num_var, 
			ST_INT max_num_nvl, ST_INT max_num_jou,
			ST_BOOLEAN copy_name)
  {
MVL_DOM_CTRL *dom;

  dom = mvl_dom_create (name, max_num_var, max_num_nvl, max_num_jou, copy_name);

/* Insert it in table.	*/
  if (mvl_vmd_dom_insert (vmd_ctrl, dom))
    {			   		/* Failed.			*/
    M_FREE (MSMEM_GEN, dom);
    return (NULL);
    }

  return (dom);
  } 

/************************************************************************/
/*			mvl_dom_create 					*/
/************************************************************************/

MVL_DOM_CTRL *mvl_dom_create (ST_CHAR *name, ST_INT max_num_var,
			      ST_INT max_num_nvl, ST_INT max_num_jou,
			      ST_BOOLEAN copy_name)
  {
MVL_DOM_CTRL *dom;

/* Allocate object and fill in "name".	*/
  if (copy_name)
    {
    dom = (MVL_DOM_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_DOM_CTRL)
                              + strlen (name) + 1);
    dom->name = (ST_CHAR *) (dom+1);
    strcpy (dom->name, name);	/* copy name		*/
    }
  else
    {
    dom = (MVL_DOM_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_DOM_CTRL));
    dom->name = name;		/* point to user buffer	*/
    }

/* Allocate the pointer tables */
  mvl_dom_resize (dom, max_num_var, max_num_nvl, max_num_jou);
  return (dom);
  }

/************************************************************************/
/*			mvl_vmd_dom_remove 					*/
/************************************************************************/

ST_RET mvl_vmd_dom_remove (MVL_VMD_CTRL *vmd_ctrl, ST_CHAR *dom_name)
  {
MVL_DOM_CTRL *dom;

  dom = mvl_vmd_dom_delete (vmd_ctrl, dom_name);
  if (dom != NULL)
    {
    mvl_dom_destroy (dom);
    return (SD_SUCCESS);
    }
  return (SD_FAILURE);
  }

/************************************************************************/
/*			mvl_dom_destroy 					*/
/************************************************************************/

ST_RET mvl_dom_destroy (MVL_DOM_CTRL *dom)
  {
ST_RET rc;

  if (u_mvl_dom_destroy != NULL)
    (*u_mvl_dom_destroy)(dom);

  rc = mvl_clear_dom_objs (dom);
  if (rc == SD_SUCCESS)
    {
    if (dom->max_num_var_assoc != 0)
      M_FREE (MSMEM_GEN, dom->var_assoc_tbl);

    if (dom->max_num_nvlist != 0)
      M_FREE (MSMEM_GEN, dom->nvlist_tbl); 

    if (dom->max_num_jou != 0)
      M_FREE (MSMEM_GEN, dom->jou_tbl); 

    M_FREE (MSMEM_GEN, dom);
    }

  return (rc);
  }

/************************************************************************/
/**** VARIABLE ASSOCIATIONS						*/
/************************************************************************/
/*			mvl_vmd_var_add					*/
/* Add a variable association. Allocate, fill in, and insert into table.*/
/************************************************************************/

MVL_VAR_ASSOC *mvl_vmd_var_add (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *obj, MVL_NET_INFO *net_info,
			ST_INT type_id,
			ST_VOID *data, 
			MVL_VAR_PROC *proc,
			ST_BOOLEAN copy_name)
  {
MVL_VAR_ASSOC *va;
MVL_DOM_CTRL *dom = NULL;

/* Find domain, if necessary, before allocating anything.	*/
  if (obj->object_tag==DOM_SPEC && (dom = mvl_vmd_find_dom (vmd_ctrl, obj->domain_id)) == NULL)
    {
    MVL_LOG_ERR2 ("Error creating VAR '%s': domain '%s' not found", 
        obj->obj_name.vmd_spec, obj->domain_id);
    return (NULL);
    }

  va = mvl_var_create (obj, type_id, data, proc, copy_name);

/* Insert it in table.	*/
  if (va)
    {
    if (mvl_vmd_var_insert (vmd_ctrl, va, obj, net_info))
      {			   		/* Failed.			*/
      mvl_var_destroy (va);	/* destroy var just created	*/
      return (NULL);
      }
    }

  return (va);
  }


/************************************************************************/
/*			mvl_var_create 					*/
/************************************************************************/

MVL_VAR_ASSOC *mvl_var_create (OBJECT_NAME *obj, ST_INT type_id,  
				 ST_VOID *data, MVL_VAR_PROC *proc,
			         ST_BOOLEAN copy_name)
  {
MVL_VAR_ASSOC *va;
MVL_TYPE_CTRL *type_ctrl;

  type_ctrl = mvl_type_ctrl_find (type_id);
  if (type_ctrl == NULL)
    {
    MVL_LOG_ERR0 ("Cannot create variable (type_id invalid).");
    return (NULL);
    }  

/* Allocate object and fill in "name".	*/
  if (copy_name)
    {
    va = (MVL_VAR_ASSOC *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_VAR_ASSOC)
                              + strlen (obj->obj_name.vmd_spec) + 1);
    va->name = (ST_CHAR *) (va+1);
    strcpy (va->name, obj->obj_name.vmd_spec);	/* copy name		*/
    }
  else
    {
    va = (MVL_VAR_ASSOC *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_VAR_ASSOC));
    va->name = obj->obj_name.vmd_spec;		/* point to user buffer	*/
    }

/* Fill in rest of object.	*/
  va->type_id = type_id;
  va->type_ctrl = type_ctrl;	/* don't need to call mvl_get_runtime	*/
				/* to get type details.			*/
  va->data = data;
#if defined(MVL_UCA)
/* If caller set the data ptr (!=NULL), assume they want to use static data.*/
  if (data!=NULL)
    va->use_static_data = SD_TRUE;
#endif
  va->proc = proc;
  return (va);
  }


/************************************************************************/
/*			mvl_vmd_var_remove 					*/
/************************************************************************/

ST_RET mvl_vmd_var_remove (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *obj, MVL_NET_INFO *net_info)
  {
MVL_VAR_ASSOC *va;

  va = mvl_vmd_var_delete (vmd_ctrl, obj, net_info);
  if (va == NULL)
    return (SD_FAILURE);

  mvl_var_destroy (va);
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			mvl_var_destroy 					*/
/************************************************************************/

ST_VOID mvl_var_destroy (MVL_VAR_ASSOC *va)
  {
  if (u_mvl_var_destroy != NULL)
    (*u_mvl_var_destroy)(va);

  /* "last_data" may have been allocated if this var used in NVL.	*/
  if (va->last_data)
    chk_free (va->last_data);
  M_FREE (MSMEM_GEN, va);
  }


/************************************************************************/
/**** NAMED VARIABLE LISTS						*/
/************************************************************************/
/*			mvl_vmd_nvl_add					*/
/* Add a Named Variable List. Allocate, fill in, and insert into table.	*/
/************************************************************************/

MVL_NVLIST_CTRL *mvl_vmd_nvl_add (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *nvl_obj, MVL_NET_INFO *net_info,
			ST_INT num_var,
			OBJECT_NAME *var_obj,	/* array of var names	*/
			ST_BOOLEAN copy_name)
  {
MVL_NVLIST_CTRL *nvl;
MVL_DOM_CTRL *dom = NULL;

/* Find domain, if necessary, before allocating anything.	*/
  if (nvl_obj->object_tag==DOM_SPEC && (dom = mvl_vmd_find_dom (vmd_ctrl, nvl_obj->domain_id)) == NULL)
    {
    MVL_LOG_ERR2 ("Error creating NVL '%s': domain '%s' not found", 
        nvl_obj->obj_name.vmd_spec, nvl_obj->domain_id);
    return (NULL);
    }

/* Allocate it AND fill it in.	*/
  nvl = mvl_nvl_create (vmd_ctrl, nvl_obj->obj_name.vmd_spec, num_var, var_obj, net_info, copy_name);
  if (nvl == NULL)
    return (NULL);

/* Add scope info to "nvl".	*/
  nvl->nvl_scope.scope = nvl_obj->object_tag;
  nvl->nvl_scope.dom = dom;	/* NOTE: NULL if not DOM_SPEC (see above)	*/

/* Insert it in table.	*/
  if (mvl_vmd_nvl_insert (vmd_ctrl, nvl, nvl_obj, net_info))
    {			   		/* Failed.			*/
    mvl_nvl_destroy (nvl);
    return (NULL);
    }

  return (nvl);
  }

/************************************************************************/
/*                       mvl_nvl_create					*/
/************************************************************************/
/* Given a list of MMS object names, create a MVL Named Variable List.	*/
/* This can include both configured and MVLU manufactured variables	*/
/* Use 'mvl_nvl_destroy' to free this NVL.				*/

MVL_NVLIST_CTRL *mvl_nvl_create (MVL_VMD_CTRL *vmd_ctrl,
			ST_CHAR *nvlName,
			ST_INT numNames,
			OBJECT_NAME *var_obj,	/* array of var obj names*/
			MVL_NET_INFO *net_info,	/* where to find var_obj*/
						/* if it is AA_SPEC	*/
			ST_BOOLEAN copy_name)
  {
MVL_NVLIST_CTRL *nvl;
ST_INT j;
  
/* Allocate object and fill in "name".	*/
  if (copy_name)
    {
    nvl = (MVL_NVLIST_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_NVLIST_CTRL)
                              + strlen (nvlName) + 1);
    nvl->name = (ST_CHAR *) (nvl+1);
    strcpy (nvl->name, nvlName);	/* copy name		*/
    }
  else
    {
    nvl = (MVL_NVLIST_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_NVLIST_CTRL));
    nvl->name = nvlName;		/* point to user buffer	*/
    }

/* Fill in rest of object.	*/

  nvl->entries = (MVL_VAR_ASSOC **) M_CALLOC (MSMEM_GEN, numNames, 
					sizeof (MVL_VAR_ASSOC *));
  nvl->va_scope = (MVL_SCOPE *) M_CALLOC (MSMEM_GEN, numNames, 
					sizeof (MVL_SCOPE));
  nvl->num_of_entries = numNames;

  for (j = 0;  j < nvl->num_of_entries;  ++j, ++var_obj)
    {
    MVL_VAR_ASSOC *var;
    if ((nvl->entries[j] = var = _mvl_objname_to_va (vmd_ctrl, net_info, MMSOP_INFO_RPT,
                      var_obj, &nvl->va_scope[j], SD_FALSE, NULL, NULL)) == NULL)
      {
      MVL_LOG_ERR2 ("Error creating NVL '%s': member variable '%s' not found", 
    					nvlName, var_obj->obj_name.vmd_spec);
      mvl_nvl_destroy (nvl);
      return (NULL);
      }
    else
      {
      /* Alloc buffer for last data (used for IEC/UCA reports).	*/
      if (!var->last_data)
        var->last_data = chk_calloc (1, mvl_type_ctrl[var->type_id].data_size);
      }
    }

  return (nvl);
  }


/************************************************************************/
/*			mvl_vmd_nvl_remove					*/
/* Remove a Named Variable List. Delete it from table and "destroy" it.	*/
/************************************************************************/

ST_RET mvl_vmd_nvl_remove (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *obj, MVL_NET_INFO *net_info)
  {
MVL_NVLIST_CTRL *nvl;

/* Delete it from table.	*/
  if ((nvl = mvl_vmd_nvl_delete (vmd_ctrl, obj, net_info)) == NULL)
    return (SD_FAILURE);		/* nvl not found	*/

/* Destroy it.			*/
  mvl_nvl_destroy (nvl);
  return (SD_SUCCESS);
  }

/************************************************************************/
/*                       mvl_nvl_destroy				*/
/************************************************************************/
/* Free a MVL Named Variable List created by 'mvl_nvl_create'		*/

ST_VOID mvl_nvl_destroy (MVL_NVLIST_CTRL *nvl)
  {
MVL_VAR_ASSOC *va;
ST_INT i;

  if (u_mvl_nvl_destroy != NULL)
    (*u_mvl_nvl_destroy)(nvl);

/* Free up any manufactured variables */
  for (i = 0; i < nvl->num_of_entries; ++i)
    {
    va = nvl->entries[i];
#if defined(MVL_UCA) || defined(USE_MANUFACTURED_OBJS)
/* NOTE: "va" may be NULL if mvl_nvl_create failed while adding entries.*/
    if (va && va->va_to_free == va)
      {
      u_mvl_free_va (MMSOP_INFO_RPT, va, NULL);
      }
#endif
    }

  M_FREE (MSMEM_GEN, nvl->entries);
  M_FREE (MSMEM_GEN, nvl->va_scope);
  M_FREE (MSMEM_GEN, nvl);
  }

/************************************************************************/
/**** JOURNALS								*/
/************************************************************************/
/*			mvl_vmd_jou_add					*/
/* Add a Journal. Allocate, fill in, and insert into table.		*/
/************************************************************************/

MVL_JOURNAL_CTRL *mvl_vmd_jou_add (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *obj, MVL_NET_INFO *net_info,
			ST_BOOLEAN copy_name)
  {
MVL_JOURNAL_CTRL *jou;

  jou = mvl_jou_create (obj, net_info, copy_name);
  if (mvl_vmd_jou_insert (vmd_ctrl, jou, obj, net_info))
    {			   		/* Failed.			*/
    M_FREE (MSMEM_GEN, jou);
    return (NULL);
    }
  return (jou);
  } 

/************************************************************************/
/*			mvl_jou_create 					*/
/************************************************************************/

MVL_JOURNAL_CTRL *mvl_jou_create (OBJECT_NAME *obj, MVL_NET_INFO *net_info,
			         ST_BOOLEAN copy_name)
  {
MVL_JOURNAL_CTRL *jou;

/* Allocate object and fill in "name".	*/
  if (copy_name)
    {
    jou = (MVL_JOURNAL_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_JOURNAL_CTRL)
                              + strlen (obj->obj_name.vmd_spec) + 1);
    jou->name = (ST_CHAR *) (jou+1);
    strcpy (jou->name, obj->obj_name.vmd_spec);	/* copy name		*/
    }
  else
    {
    jou = (MVL_JOURNAL_CTRL *) M_CALLOC (MSMEM_GEN, 1, sizeof (MVL_JOURNAL_CTRL));
    jou->name = obj->obj_name.vmd_spec;		/* point to user buffer	*/
    }

  return (jou);
  }

/************************************************************************/
/*			mvl_vmd_jou_remove 					*/
/************************************************************************/

ST_RET mvl_vmd_jou_remove (MVL_VMD_CTRL *vmd_ctrl, OBJECT_NAME *obj, MVL_NET_INFO *net_info)
  {
MVL_JOURNAL_CTRL *jou;

  jou = mvl_vmd_jou_delete (vmd_ctrl, obj, net_info);
  if (jou == NULL)
    return (SD_FAILURE);

  mvl_jou_destroy (jou);
  return (SD_SUCCESS);
  }

/************************************************************************/
/*			mvl_jou_destroy 				*/
/************************************************************************/

ST_VOID mvl_jou_destroy (MVL_JOURNAL_CTRL *jou)
  {
  if (u_mvl_jou_destroy != NULL)
    (*u_mvl_jou_destroy)(jou);

  M_FREE (MSMEM_GEN, jou);
  }

/************************************************************************/
/*			 mvl_vmd_create					*/
/* Create a new VMD with empty object arrays.				*/
/* Use "mvl_vmd_destroy" to destroy the VMD.				*/
/************************************************************************/
MVL_VMD_CTRL *mvl_vmd_create (ST_INT max_num_dom,
	ST_INT max_num_var,
	ST_INT max_num_nvl,
	ST_INT max_num_journal)
  {
MVL_VMD_CTRL *vmd_ctrl = chk_calloc (1, sizeof (MVL_VMD_CTRL));

  vmd_ctrl->max_num_var_assoc = max_num_var;
  if (vmd_ctrl->max_num_var_assoc)
    vmd_ctrl->var_assoc_tbl = (MVL_VAR_ASSOC **) chk_calloc (
                        vmd_ctrl->max_num_var_assoc, sizeof (MVL_VAR_ASSOC *));

  vmd_ctrl->max_num_nvlist = max_num_nvl;
  if (vmd_ctrl->max_num_nvlist)
    vmd_ctrl->nvlist_tbl = (MVL_NVLIST_CTRL **) chk_calloc (
                        vmd_ctrl->max_num_nvlist, sizeof (MVL_NVLIST_CTRL *));

  vmd_ctrl->max_num_dom = max_num_dom;
  if (vmd_ctrl->max_num_dom)
    vmd_ctrl->dom_tbl = (MVL_DOM_CTRL **) chk_calloc (
                        vmd_ctrl->max_num_dom, sizeof (MVL_DOM_CTRL *));

  vmd_ctrl->max_num_jou = max_num_journal;
  if (vmd_ctrl->max_num_jou)
    vmd_ctrl->jou_tbl = (MVL_JOURNAL_CTRL **) chk_calloc (
                        vmd_ctrl->max_num_jou, sizeof (MVL_JOURNAL_CTRL *));

  return (vmd_ctrl);
  };

/************************************************************************/
/*			mvl_vmd_destroy					*/
/* Destroy all objects in this VMD.					*/
/* RETURNS:  SD_SUCCESS or error code					*/
/************************************************************************/
ST_RET mvl_vmd_destroy (MVL_VMD_CTRL *vmd_ctrl)
  {
ST_RET ret;
ST_INT vidx;	/* index to variable array	*/
ST_INT j;
MVL_DOM_CTRL *dom;
MVL_VAR_ASSOC *var;

  ret = SD_SUCCESS;	/* default ret val: returned if LD linked list empty.*/

  /* Delete VMD-Specific NVL's.	*/
  for (j = 0; j < vmd_ctrl->num_nvlist; ++j)
    mvl_nvl_destroy (vmd_ctrl->nvlist_tbl[j]);
  vmd_ctrl->num_nvlist = 0;
  
  /* Delete VMD-Specific Variables.	*/
  for (j = 0; j < vmd_ctrl->num_var_assoc; ++j)
    mvl_var_destroy (vmd_ctrl->var_assoc_tbl[j]);
  vmd_ctrl->num_var_assoc = 0;

  /* Delete Domains (always VMD-Specific).	*/
  while ((dom = mvl_vmd_dom_find_last (vmd_ctrl)) != NULL)
    {
    for (vidx = 0; vidx < dom->num_var_assoc; vidx++)
      {
      var = dom->var_assoc_tbl[vidx];
      chk_free (var->data);	/* we allocated data so we must free it*/
      }
    ret = mvl_vmd_dom_remove (vmd_ctrl, dom->name);

    if (ret != SD_SUCCESS)
      break;
    }

  /* Destroy all types for this VMD.	*/
  if (ret == SD_SUCCESS)
    ret = mvl_vmd_type_id_destroy_all (vmd_ctrl);

  /* Finally, free the tables and the VMD itself (allocated by mvl_vmd_create).*/
  /* NOTE: can't do this for "mvl_vmd" because it was created by Foundry.*/
  if (vmd_ctrl != &mvl_vmd)
    {
    if (vmd_ctrl->var_assoc_tbl)
      chk_free (vmd_ctrl->var_assoc_tbl);
    if (vmd_ctrl->nvlist_tbl)
      chk_free (vmd_ctrl->nvlist_tbl);
    if (vmd_ctrl->dom_tbl)
      chk_free (vmd_ctrl->dom_tbl);
    if (vmd_ctrl->jou_tbl)
      chk_free (vmd_ctrl->jou_tbl);
    chk_free (vmd_ctrl);
    }

  return (ret);
  }

