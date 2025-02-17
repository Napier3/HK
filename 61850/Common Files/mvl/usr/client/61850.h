#if !defined(_61850PROC)
#define _61850PROC

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////
#define     Max_dsType_Num			12

#define		dsType_NULL				-1
#define		dsType_Param			0
#define		dsType_Setting			1
#define		dsType_RelayEna			2
#define		dsType_RelayAin			3
#define		dsType_RelayDin			4
#define		dsType_RelayRec			5
#define		dsType_TripInfo			6
#define		dsType_Alarm			7
#define		dsType_Warning			8
#define     dsType_Soe				9
#define		dsType_SV				10
#define		dsType_GOOSE			11

//////////////////////////////////////////////////////////////////////////
#define		devType_NULL			-1
#define		devType_Ctrl			0
#define		devType_Prot			1

//////////////////////////////////////////////////////////////////////////
#define		rcbType_NULL			-1			 
#define		rcbType_Prot			0			// �����¼�
#define		rcbType_Din				1			// ң��
#define		rcbType_Ena				2			// ѹ��
#define		rcbType_Ain             3			// ң��
#define		rcbType_Soe             4
#define		rcbType_Alarm           5			// �����ź�
#define		rcbType_Warning         6			// �澯�ź�
#define		rcbType_CommState       7			// ͨ�Ź���

//////////////////////////////////////////////////////////////////////////
#define		dsTripInfo          "LLN0$dsTripInfo"					//  0.  ���津��

#define		dsParameter			"LLN0$dsParameter"					//	1.	װ�ò���  fc="SP"
#define		dsSetting			"LLN0$dsSetting"					//  2.	������ֵ  fc="SG"��fc="SP"
#define		dsRelayEna			"LLN0$dsRelayEna"					//	3.	����ѹ��  fc="ST"
#define		dsRelayAin			"LLN0$dsRelayAin"					//  4.	����ң�⣨���װ��ң�⣩ fc="MX"
#define		dsRelayDin			"LLN0$dsRelayDin"					//	5.	����ң�ţ����װ��ң�ţ� fc="ST"
#define		dsRelayRec			"LLN0$dsRelayRec"					//	6.	�������ϱ��� fc="ST"
#define		dsTripInfo			"LLN0$dsTripInfo"					//	7.	�����¼� fc="ST"
#define		dsAlarm				"LLN0$dsAlarm"						//	8.	���й����ź� fc="ST"
#define		dsWarning			"LLN0$dsWarning"					//	9.	���и澯�ź� fc="ST"
#define		dsRelaySoe			"LLN0$dsRelaySoe"					//	10. ң��  
#define		dsSV				"LLN0$dsSV"							//	11.	����ֵ  fc="MX"
#define		dsGOOSE				"LLN0$dsGOOSE"						//	12.	GOOSE fc="ST"��fc="MX"   

#define		dsEna				"LLN0$dsEna"						//	12.	ѹ��
#define		dsAin				"LLN0$dsAin"						//	13.	ң��
#define		dsDin				"LLN0$dsDin"						//	14.	ң��(˫��ң��)
#define		dsRec				"LLN0$dsRec"						//	15.	¼��
#define		dsSoe				"LLN0$dsSoe"						//	15.	ң��
#define		dsSetGrpNum			"LLN0$dsSetGrpNum"					//	16.	��ֵ��
#define		dsDout				"LLN0$dsDout"						//
#define		dsDevStdMsg			"LLN0$dsDevStdMsg"	//��PROT�¹̶����ӵ�װ�ñ�׼��Ϣ���ݼ�,���ݲ���Ҫ��
#define		dsRelayBlk			"LLN0$dsRelayBlk"						//	��������  
#define		dsRelayState		"LLN0$dsRelayState"						//	����״̬ 
#define		dsRelayFunEn		"LLN0$dsRelayFunEn"						//	��������ѹ�� 
#define		dsLog	        	"LLN0$dsLog"						//	��־ 

#define		key_dsParameter			"Parameter"	
#define		key_dsSetting			"Setting"
#define		key_dsRelayEna			"Ena"
#define		key_dsRelayAin			"Ain"
#define		key_dsRelayDin			"Din"
#define		key_dsRelayRec			"Rec"
#define		key_dsTripInfo			"TripInfo"
#define		key_dsAlarm				"Alarm"
#define		key_dsWarning			"Warning"
#define		key_dsGOOSE				"GOOSE"	  
#define		key_dsSetGrpNum			"SetGrpNum"
#define		key_dsDeviceState			"DeviceState"
#define		key_dsCommState			"CommState"
#define		key_dsLog			"Log"
#define		key_dsRelayBlk			"RelayBlk"
#define		key_dsRelayFunEn			"RelayFunEn"
#define		key_dsRelayState			"RelayState"
#define		key_dsDout					"Dout"

//////////////////////////////////////////////////////////////////////////

#define		MAXREAD		100
#define		SD_WAIT		3			/*�����ݵȴ�*/
#define		SD_ERROR	4			/*�����ݳ���*/
#define		MAXSG		512

//#define _use_tagSGCB
// #define _use_Prompt  1
	/*
	<DAType id="SGCB">			<!-- sec 13.2.1 -->
	<BDA name="NumOfSG"		bType="INT8U"/>			<!-- M -->
	<BDA name="ActSG"		bType="INT8U"/>			<!-- M -->
	<BDA name="EditSG"		bType="INT8U"/>			<!-- M -->
	<BDA name="CnfEdit"		bType="BOOLEAN"/>	   	<!-- M -->
	<BDA name="LActTim"		bType="Timestamp"/>	   	<!-- M -->
	</DAType>
	*/
	/*
	��ǰ��ֱֵ�ӻ�ȡFC=SG
	�޸�ʱ��������EditSG,�ٶ�FC=SE������ 
	д�������CnfEdit
	*/
#define		    SG_FINISH		1
#define		    SG_CALLING		1
#define		    SG_FINISH		1

	/*
	��ֵ����Ϊ��ռģʽ������Ϊ��
	�����ж�ֵ		CMD_READ_SG
	��ĳ����ֵ		CMD_READ_SG_ZONE
	�޸�ĳ����ֵ	CMD_WRITE_SE	
	*/

#ifdef _use_tagSGCB
	typedef struct{
		ST_UCHAR		numZone;		/*��ֵ������*/
		ST_UCHAR		ActSG;
		ST_UCHAR		EditSG;
		ST_BOOLEAN		CnfEdit;
		MMS_UTC_TIME	LActTm;

		tagDA			*pnumZone;		
		tagDA			*pActSG;
		tagDA			*pEditSG;
		tagDA			*pCnfEdit;
		tagDA			*pLActTm;

		ST_INT			nACSI;			/*װ������*/
		ST_INT			numSG;
		tagDA			*pSG[MAXSG];	/*SCADAģ�����Ϊ�����ڴ�飬�ò��ֲ���ָ����Ǳ���*/
		tagDA			*pSE[MAXSG];	/*SCADAģ�����Ϊ�����ڴ�飬�ò��ֲ���ָ����Ǳ���*/

		ST_INT			sgCMD;			/*��ֵ��������*/
		ST_BOOLEAN		sgStat;			/*��ֵ����״̬*/
		ST_INT			nZone;			/*��ǰ��ֵ����-1Ϊ���ж�ֵ��*/
	}tagSGCB;

	extern tagSGCB SGCB;
#endif

	extern ST_LONG localIP1, localIP2;
	extern ST_VOID timer_proc(ST_INT addms);
	extern ST_RET connect_proc(ST_INT nACSI, ST_BOOLEAN isStart, ST_CHAR *psw);
	extern ST_VOID enable_gi(ST_INT nACSI, ST_INT nRCB);
	extern ST_VOID rcb_disable(ST_INT nACSI, ST_INT nRCB);
	extern ST_RET start_iec_brcb (MVL_NET_INFO *clientNetInfo, ST_CHAR* domname, ST_CHAR* brcbname, ST_CHAR* entryid, RPT_TYPEIDS *rpt_typeids, ST_INT nRCB);
	extern ST_RET start_iec_urcb (MVL_NET_INFO *clientNetInfo,  ST_CHAR* domname, ST_CHAR* urcbname, RPT_TYPEIDS *rpt_typeids, ST_INT nRCB);
	extern ST_RET disconnectFromServer(MVL_NET_INFO *clientNetInfo);
	extern ST_RET disconnectFromServerEx(ST_INT nDeviceIndex);
	extern ST_RET ReadSG(ST_INT nACSI, ST_INT zone);
	extern ST_VOID BuildSGCB(ST_INT nACSI);

#ifdef _MVL_TYPE_CTRL_use_one_device_
	ST_RET SelectSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check, MVL_TYPE_CTRL *mvl_type_ctrl);
#else
	extern ST_RET SelectSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check);
#endif
	extern ST_VOID Prompt(ST_CHAR *p);
	extern ST_VOID ResetNetInfo(ST_INT nACSI);
	extern ST_RET SetActSGZone(ST_INT nACSI, ST_INT zone);
	extern VOID StopRCB(ST_INT nACSI);
	extern VOID StartRCB(ST_INT nACSI);
	extern ST_RET test_net_proc(ST_INT nACSI, ST_BOOLEAN isStart);
	extern ST_RET SetCnfEdit(ST_INT nACSI);
	extern ST_RET WriteSG(ST_INT nACSI);
	extern ST_RET get_dir(ST_INT nACSI, ST_CHAR *pfilespec,XMMS_FILE_SYS_OBJ *pFileDir/*, ST_CHAR *ppathname*/,ST_BOOLEAN bOnlyReadCfg);
	extern ST_RET get_file(ST_INT nACSI, ST_CHAR *pfile, ST_CHAR *pszLocalPath);

	extern ST_RET set_FCDA_type(ST_INT el_tag, ST_CHAR *pType);

	// 2012-09-18  ��ȡ�߼��豸������
	extern ST_RET get_varlistattri(MVL_NET_INFO *net_info, LD_NODE *pLD, ST_INT nDsIndex);
	// 2012-09-18  ��ȡ����������
#ifdef _MVL_TYPE_CTRL_use_one_device_
	extern ST_RET get_varType(MVL_NET_INFO *net_info, ST_CHAR *LDName, ST_INT *nDAType, ST_CHAR *LNName, MVL_TYPE_CTRL *mvl_type_ctrl);
#else
	extern ST_RET get_varType(MVL_NET_INFO *net_info, ST_CHAR *LDName, ST_INT *nDAType, ST_CHAR *LNName);
#endif
	// 2012-09-19  ��ȡ��������ֵ
	extern ST_RET get_varvalue(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataDest, ST_INT num_dataDest);
	extern ST_RET get_varvalue_x(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataDest, ST_INT num_dataDest, ST_INT nDataType);
	/* 2012-10-16  �������ݵ���ֵ */
	extern ST_RET set_varvalue(MVL_NET_INFO *net_info, ST_CHAR *varName, ST_CHAR *domName, ST_INT type_id, ST_VOID *dataSrc);
	/* 2012-12-03   */
	extern ST_INT JudgeControlMode(ST_INT nACSI, ST_CHAR *pOper_ctlVal, ST_CHAR *pSBOw, ST_CHAR *pOper);
	/* 2012-12-03   */
	extern ST_INT GetOper(MVL_NET_INFO *net_info, ST_CHAR *pOper, ST_INT nACSI);
	/* 2012-12-03   */

#ifdef _MVL_TYPE_CTRL_use_one_device_
	ST_RET OperSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check, MVL_TYPE_CTRL *mvl_type_ctrl);
#else
	extern ST_RET OperSBOw(ST_INT nACSI, ST_CHAR *pOper, ST_INT type_id, ST_INT iValue, ST_INT fValue, ST_INT test, ST_INT check);
#endif

	extern int ping(unsigned long IP);


#ifdef __cplusplus
}
#endif


#endif

