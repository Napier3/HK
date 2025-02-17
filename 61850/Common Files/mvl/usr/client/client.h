/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	2003 - 2003, All Rights Reserved				*/
/*									*/
/* MODULE NAME : client.h						*/
/* PRODUCT(S)  : MMSEASE-LITE						*/
/*									*/
/* MODULE DESCRIPTION :							*/
/*	Defines for sample "client" application.			*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 05/13/04  JRB     03    Chg SqNum to INT16U to match 61850-7-2.	*/
/* 12/17/03  JRB     02    61850-8-1 FDIS changes:			*/
/*			   Add ConfRev to RCB_DATA & RCB_VAR.		*/
/*			   Chg bvstring9 to bvstring10 for OptFlds.	*/
/* 10/09/03  JRB     01    New						*/
/************************************************************************/

/* Defines required by Foundry generated code.				*/
/* Default values defined in "mvl_defs.h" but we don't like the defaults*/
/* so we undefine and redefine them here.				*/

#ifdef __cplusplus
extern "C" {
#endif

#include "memOBJTree.h"

extern ST_CHAR CLIENT_PATH[255];
extern ST_CHAR LOGCFG_PATH[255];



#undef MVL_NUM_DYN_DOMS
#undef MVL_NUM_DYN_VMD_VARS
#undef MVL_NUM_DYN_VMD_NVLS
#undef MVL_NUM_DYN_JOUS
#undef MVL_NUM_DYN_DOM_VARS
#undef MVL_NUM_DYN_DOM_NVLS
#undef MVL_NUM_DYN_AA_VARS
#undef MVL_NUM_DYN_AA_NVLS
#undef MVLU_NUM_DYN_TYPES

#define MVL_NUM_DYN_DOMS	10
#define MVL_NUM_DYN_VMD_VARS	100
#define MVL_NUM_DYN_VMD_NVLS	10
#define MVL_NUM_DYN_JOUS	10
#define MVL_NUM_DYN_DOM_VARS	100
#define MVL_NUM_DYN_DOM_NVLS	10
#define MVL_NUM_DYN_AA_VARS	10
#define MVL_NUM_DYN_AA_NVLS	10
#define MVLU_NUM_DYN_TYPES	100	/* important for UCA	*/

#define REQ_TIMEOUT		2000

#define MAX_PIPE0_RPT	100
#define MAX_PIPE1_RPT	30

	/* Struct to store common type ids needed for IEC/UCA Reports.	*/
	typedef struct
	{
		ST_INT mmsbool;	/* named so not confused with C++ 'bool' type	*/
		ST_INT int8u;
		ST_INT int16u;	/* for SqNum.			*/
		/* NOTE: UCA server sends int8u for SqNum	*/
		/* but it's safe to decode it as int16u		*/
		ST_INT int32u;	/* for IntgPd			*/
		ST_INT vstring65;	/* for RptID & ObjectReference	*/
		ST_INT btime6;	/* for EntryTime		*/
		ST_INT ostring8;	/* for EntryID			*/
		ST_INT vstring32;	/* for RptId			*/
		ST_INT bvstring6;	/* for TrgOps (IEC)		*/
		ST_INT bvstring8;	/* for OptFlds,TrgOps (UCA)	*/
		ST_INT bvstring10;	/* for OptFlds (IEC)		*/
		ST_INT bstr6;		/* for Reason (IEC)		*/
		ST_INT bstr8;		/* for Reason (UCA)		*/
		ST_INT bstr9;		/* for Writing OptFlds (IEC). Can't write all 10 bits.*/
	} RPT_TYPEIDS;

	typedef struct
	{
		ST_CHAR    RptID[66];		
		struct     /* BVstring */	
		{				
			ST_INT16 len_1;		
			ST_UCHAR data_1[2];		/* BVstring9 - need 2 bytes	*/
		} OptFlds;			
		ST_UINT16  SqNum;
		MMS_BTIME6 TimeOfEntry;
		ST_CHAR    DatSetName[66];
		ST_BOOLEAN BufOvfl;
		ST_UINT16 SubSeqNum;
		ST_BOOLEAN MoreSegmentsFollow;
		ST_UINT8 EntryID [8];		/* ostring8			*/
		ST_UINT32 ConfRev;
		ST_UINT8  Inclusion[50];		/* ptr to bitstring		*/
	} RCB_DATA;		

	typedef struct
	{
		MVL_VAR_ASSOC *  RptID;
		MVL_VAR_ASSOC *  OptFlds;
		MVL_VAR_ASSOC *  SqNum;
		MVL_VAR_ASSOC *  TimeOfEntry;
		MVL_VAR_ASSOC *  DatSetNa;
		MVL_VAR_ASSOC *  BufOvfl;
		MVL_VAR_ASSOC *  SubSeqNum;
		MVL_VAR_ASSOC *  MoreSegmentsFollow;
		MVL_VAR_ASSOC *  EntryID;
		MVL_VAR_ASSOC *  ConfRev;
		MVL_VAR_ASSOC *  Inclusion;
		MVL_VAR_ASSOC ** dataRefName;	/* array of ptrs	*/
		MVL_VAR_ASSOC ** dataValue;	/* array of ptrs	*/
		MVL_VAR_ASSOC ** Reason;	/* array of ptrs	*/
	} RCB_VAR;

	typedef struct
	{
		DBL_LNK link;		/* allows linked list of this struct	*/
		RCB_DATA rcb_data;
		RCB_VAR rcb_var;
	} RCB_INFO;

	/************************************************************************/
	/* Global variables.													*/
	/************************************************************************/
	extern ST_INT g_timeOut;
	extern ST_BOOLEAN IsDualNet;
	extern ST_LONG localIP1, localIP2;
// 	extern ST_INT  nSelPipe;
	extern MVL_CFG_INFO mvlCfg; 
	extern RPT_TYPEIDS rpt_typeids;
	extern ST_CHAR *spareMem;

	/************************************************************************/
	/* Function prototypes.													*/
	/************************************************************************/
	extern ST_VOID init_mem (ST_VOID);
#if defined (DEBUG_SISCO)
	extern ST_VOID init_log_cfg (ST_VOID);
#endif

	extern ST_VOID disc_ind_fun (MVL_NET_INFO *cc, ST_INT discType);
	extern ST_RET getFile (MVL_NET_INFO *clientNetInfo, ST_CHAR *loc_file, ST_CHAR *rem_file);
	extern ST_VOID InitACSIServerNet(); 
	extern ST_RET ConnectToServer();
	extern ST_VOID SetThreadExit(ST_BOOLEAN bExit);
	extern ST_BOOLEAN GetThreadExit();
	extern ST_VOID ThreadCountAddRef();
	extern ST_VOID ThreadCountRelease();
	extern ST_INT GetThreadCount();
	//zhouhj20180130 根据日志控制块名称路径查找pTagDA
	extern ST_RET My_Pare_JournalID_LD( LD_NODE *pLD, ST_INT *numDA, tagDA **pTagDA, ST_INT *nDsIndex, ST_CHAR *RptID, ST_CHAR *DataPath);

	ST_RET waitReqDone (MVL_REQ_PEND *req, ST_INT timeout, ST_INT nACSI);

	ST_RET rpt_typeids_find (RPT_TYPEIDS *rpt_typeids);

	RCB_INFO *rcb_info_create (MVL_NET_INFO *net_info, RPT_TYPEIDS *rpt_typeids, ST_INT idx);
	ST_VOID rcb_info_destroy (RCB_INFO *rcb_info);

	ST_RET rcb_enable (MVL_NET_INFO *netInfo, ST_CHAR *domName,
		ST_CHAR *rcbName, ST_UCHAR *OptFlds, ST_UCHAR *TrgOps,
		ST_UINT32 IntgPd, RPT_TYPEIDS *rpt_typeids, ST_CHAR *RptID,  ST_CHAR *EntryID, ST_INT timeOut, ST_BOOLEAN isBR);

	/* Simple functions to read/write a single variable.	*/
	ST_RET named_var_read (MVL_NET_INFO *net_info, ST_CHAR *varName,
		ST_INT scope, ST_CHAR *domName,
		ST_INT type_id, ST_VOID *dataDest, ST_INT timeOut);
	ST_RET named_var_write (MVL_NET_INFO *netInfo, ST_CHAR *varName,
		ST_INT scope, ST_CHAR *domName,
		ST_INT type_id,	ST_VOID *dataSrc, ST_INT timeOut);

	ST_RET u_iec_rpt_ind (MVL_COMM_EVENT *event);
	ST_VOID u_iec_rpt_ind_data (MVL_VAR_ASSOC **info_va,
		ST_UINT8 *OptFldsData,	/* ptr to data part of OptFlds bvstring	*/
		ST_UINT8 *InclusionData,	/* ptr to Inclusion bstring	*/
		ST_INT numDsVar,
		ST_INT va_total);

	ST_INT mms_is_da_struct(tagDA*pSrc);
	ST_INT mms_is_da_array(tagDA*pSrc);
	ST_INT mms_is_da_basic(tagDA*pSrc);
	ST_BOOLEAN mms_IsDataString(tagDA *pDA);
	ST_BOOLEAN mms_IsDataTypeString(ST_CHAR *pszDataType);
	ST_VOID mms_CopyValue(tagDAValue*pDst, tagDAValue*pSrc, BOOL bString);
	ST_VOID mms_CopyValue2(tagValue*pDst, tagValue*pSrc, BOOL bString);
	ST_VOID mms_CopyData(tagDA*pSrc, tagDA*pDst, BOOL bRpt);
	ST_VOID mms_InitData(tagDA*pDA);
	ST_VOID mms_InitDatas(tagDA*pDA, long nCount);
	ST_VOID mms_SetValueX(tagValue*pDst, tagValueX*pSrc, ST_INT type_id);
	ST_INT mms_UTF8ToUnicodeEx(const char* str , int len, char *pszDest);

	ST_VOID mms_ReleaseData(tagDA*pData);
	ST_VOID mms_ReleaseDataRpt(tagDA*pData);
	ST_VOID mms_ReleaseDataX(tagDA*pData);
	ST_VOID mms_Add_DA_To_Rpts(tagRpt *pReports, tagDA *pTagDA, long *pnCurrRptIndex
		, long nAcsi, long nLdIndex, long nDsIndex
		, long *pnRptCount, long nDaIndex, double dTime, int nTmMs);//zhouhj 20200113增加ms参数,用于解决之前时间中ms值为0的问题

#ifdef _use_dynamic_mem
	ST_VOID mms_Free_tagDA(tagDA*pData);
	ST_VOID mms_Free_tagDAs(tagDA *pTagDAs, ST_INT nCount);
	ST_VOID mms_Free_LD_DATASET_INFO(LD_DATASET_INFO *pDataSet);
	ST_VOID mms_Free_LD_JOURNAL_CTRLS(LD_JOURNAL_CTRLS *pJournal);
	ST_VOID mms_Free_LD_DATASET_INFO_Ex(LD_DATASET_INFO *pDataSet);
	ST_VOID mms_JournalDataOfVector_Free(unsigned long* pJournalDatas,ST_INT nNumOfData);//zhouhj20180309
	ST_VOID mms_New_LD_DATASET_INFO_numData(LD_DATASET_INFO *pDataSet, ST_INT numData);
	ST_VOID mms_New_LD_JOURNAL_CTRLS_numData(LD_JOURNAL_CTRLS *pDataSet, ST_INT numData);
	ST_VOID mms_New_LD_DATASET_INFO_numData_Ex(LD_DATASET_INFO **ppDataSet, ST_INT numData);

	ST_VOID mms_Free_Data_Node(MMS_DATA_NODE *p_mms_data_node);
	ST_VOID mms_Free_LD_NODE(LD_NODE *pLdevice);
	ST_VOID mms_Free_LD_NODE_Ex(LD_NODE *pLdevice);
	ST_VOID mms_New_LD_NODE_numDataset(LD_NODE *pLdevice, ST_INT numDataset);
	ST_VOID mms_New_LD_NODE_numJournal(LD_NODE *pLdevice, ST_INT numJournal);//2018.1.17zhouhj
	ST_VOID mms_New_LD_NODE_numDataset_Ex(LD_NODE **ppLdevice, ST_INT numDataset);

	ST_VOID mms_file_sys_free(XMMS_FILE_SYS_OBJ *pMmsFileSysObj);
// 	ST_VOID mms_file_sys_add(fsize, mtimpres, mtime, filename);
// 	ST_VOID mms_file_sys_copy();
// 	ST_VOID mms_file_sys_cmp();

	ST_VOID mms_Free_ACSI_NODE(ACSI_NODE *pDevice);
	ACSI_NODE* mms_New_ACSI_NODE_numLD(ACSI_NODE *pDevice, ST_INT numLD, BOOL bDelete);

	BOOL mms_FireDataChangedMsg(ST_INT nAcsi, ST_INT nLdIndex, ST_INT nDsIndex, ST_INT nDataIndex);
	BOOL mms_FireCmdMsg(ST_INT nAcsi, ST_INT nLdIndex, ST_INT nDsIndex, ST_INT nDataIndex, ST_INT nCmdID, ST_INT nCmdIndex);

	MMS_DATA_NODE* mms_find_data_node_child(MMS_DATA_NODE *pParentNode, ST_CHAR *pName);
	MMS_DATA_NODE* mms_node_append_sibling(MMS_DATA_NODE *pParent, MMS_DATA_NODE** ppSiblingNode, ST_CHAR *pName, enum NODE_TYPE type);
	MMS_DATA_NODE* mms_node_append_sibling2(MMS_DATA_NODE *pParent, MMS_DATA_NODE** ppSiblingNode);
	
	MMS_DATA_NODE* mms_node_append_child(MMS_DATA_NODE* pParentNode, ST_CHAR *pName, enum NODE_TYPE type);
	MMS_DATA_NODE* mms_node_append_child2(MMS_DATA_NODE* pParentNode);

#endif

	typedef void (MMS_ERROR_LOG_FUNC) ();
	extern ST_INT mms_log_error_infor;
	extern ST_CHAR buff_mms_err_text[255];
	extern MMS_ERROR_LOG_FUNC *func_mms_log_error_infor;
	extern ST_INT mms_ena_read_before_write;
	extern ST_INT mms_ena_read_before_write_t;
	extern ST_INT g_n_mms_Add_DA_To_Rpts;

	typedef void (MMS_ERROR_MVL_REQ_PEND_FUNC) (MVL_REQ_PEND *, ST_INT);
	extern MMS_ERROR_MVL_REQ_PEND_FUNC *func_mms_error_mvl_req_pend;

#ifdef _tagRpt_use_DA_ref
	ST_INT rpt_get_capacity(tagRpt *pRpt);
	ST_INT rpt_get_size(tagRpt *pRpt);
	void rpt_init(tagRpt *pRpt, ST_INT sz);
	void rpt_init2(tagRpt *pRpt, ST_INT sz, ST_INT cap);
	tagValue* rpt_get_at(tagRpt *pRpt, ST_INT nIndex);
	tagRptValue* rpt_get_rptval_at(tagRpt *pRpt, ST_INT nIndex);
	void rpt_set_at(tagRpt *pRpt, ST_INT nIndex,  tagValue *Value, ST_INT bString);
	void rpt_set_value(tagRptValue *pDest,  tagValue *Value, ST_INT bString);
	void rpt_quit(tagRpt *pRpt);
	void rpt_quit_value(tagRptValue *pValue);
	void rpt_set_at(tagRpt *pRpt, ST_INT nIndex,  tagValue *Value, ST_INT bString);

	ST_INT mms_get_value_count(tagDA *pDA);
	ST_VOID mms_CopyDataRpt(tagDA*pSrc, tagRpt *pRpt);
	ST_VOID mms_CopyDataRptValue(tagDA*pSrc, tagRptValue **ppRptValue);

	ST_VOID mms_InitDA_DataType(tagDA*pSrc);
	ST_VOID mms_CopyValueEx(tagDAValueEx *pDest, tagDAValueEx *pSrc);
#endif

#ifdef __cplusplus
}
#endif