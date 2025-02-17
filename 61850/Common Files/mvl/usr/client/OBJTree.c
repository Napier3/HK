#include "glbtypes.h"
#include "sysincs.h"
#include "signal.h"
#include "mmsdefs.h"
#include "mms_pvmd.h"
#include "mms_pvar.h"
#include "mms_vvar.h"
#include "mms_err.h"
#include "mms_pcon.h"
#include "asn1defs.h"
#include "mmsop_en.h"

#include "mvl_acse.h"
#include "acse2.h"
#include "tp0_sock.h"
#include "tp4.h"		
#include "mvl_log.h"
#include "tp4api.h"
#include "clntobj.h"
#include "client.h"
#include "memOBJTree.h"
#include "sharemem.h"

#ifdef _MVL_TYPE_CTRL_use_one_device_
extern ST_VOID mvl_init_type_ctrl (MVL_TYPE_CTRL **pp_mvl_type_ctrl);
#endif

ST_CHAR g_strTrgOps[NAMESIZE];
ST_CHAR g_strOptFlds[NAMESIZE];
long g_nCanWriteActiveSG = 0;
long g_nWriteCtrlCheckMode = 0;
long  g_nEnaWriteWait = 200;
long  g_nEnaWriteWaitAfterSel = 200;
long g_bMmsReadUseReport = 0; 
long g_bResetOnlyClearReport = 0; 
long g_nMaxReportCount = MAX_REPORT_COUNT;


ST_BOOLEAN bSCADA;
ST_BOOLEAN bOBJTree;
HANDLE hmemOBJTree;
ST_UCHAR *pmemOBJTree;
ST_INT	numDevice;
ACSI_NODE *pACSINode;

#ifdef _use_tagRelaySOEFIFO
tagSOEFIFO *pSOEFIFO;
tagRelaySOEFIFO *pRLYSOEFIFO;
#endif
HANDLE hRptNotifyEvent = NULL;

extern ST_LONG localIP1, localIP2;

ST_ULONG OMOBJTreeSize()
{
	ST_ULONG s;
	s = sizeof(ACSI_NODE);
	s = sizeof(DEVICE_NODE);

	s = sizeof(ST_INT) + MAX_DEVICE * sizeof(ACSI_CTRL) + 
		MAX_DEVICE * sizeof(DEVICE_NODE) +
		MAX_DEVICE * sizeof(ACSI_NODE)
#ifdef _use_tagRelaySOEFIFO
		+sizeof(tagSOEFIFO)
		+sizeof(tagRelaySOEFIFO)
#endif
		;
	return s;
}

// ST_BOOLEAN IsProcessExit(ST_CHAR *pName)
// {
// 	HANDLE hd;
// 	ST_BOOLEAN ret = SD_FALSE;
// 
// 	hd = CreateMutex(NULL,TRUE, pName);
// 	Sleep(100);
// 	if (hd)
// 	{
// 		if (GetLastError() == ERROR_ALREADY_EXISTS)
// 			ret = SD_TRUE;
// 		ReleaseMutex(hd);
// 	}
// 	return ret;
// }

// HANDLE BuildmemOBJTree()
// {
// 	ST_ULONG s;
// 	HANDLE  hShareMem;
// 	s = shareOBJTreeSize();
// 	hShareMem = CreateFileMapping((HANDLE)0xffffffff,
// 		NULL,
// 		PAGE_READWRITE, 
// 		0,    
// 		s,   
// 		"memOBJTree");
// 
// 	return hShareMem;
// }

// ST_UCHAR *GetmemOBJTreePtr(HANDLE hShareMem)
// {
// 	ST_UCHAR *pData;
// 	pData = (ST_UCHAR *)MapViewOfFile(hShareMem,FILE_MAP_ALL_ACCESS,0,0,0);
// 	return pData;
// }

ST_BOOLEAN InformOthers()
{
	ST_BOOLEAN ret = SD_FALSE;
	HANDLE hd;
	hd = CreateMutex(NULL,TRUE, "61850Client");
	Sleep(100);
	if (hd)
	{
		ret = SD_TRUE;
	}
	return ret;
}

ST_INT iniGetValue(ST_CHAR *file, ST_CHAR *section, ST_CHAR *item)
{
	ST_INT i=0;
	ST_CHAR *stp1,*stp2,*stp3;
	stp1=strstr(file,section);
	if(stp1 == NULL)
		return 0;

	stp2=strchr(stp1+1,'[');
	if(stp2 != NULL)
		*stp2 = 0;	

	stp3=strstr(stp1+1,item);	
	if(stp3!=NULL)
		sscanf((ST_CHAR *)(stp3+strlen(item)),"%d",&i);

	if(stp2!=NULL)
		*stp2 = '[';
	return i;
}

ST_VOID iniGetStr(ST_CHAR *file, ST_CHAR *section, ST_CHAR *item, ST_CHAR *out)
{
	ST_CHAR *stp1,*stp2,*stp3;
	*out = 0;

	stp1 = strstr(file,section);
	if(stp1 == NULL)
		return;

	stp2=strchr(stp1+1,'[');
	if(stp2 != NULL)
		*stp2 = 0;	

	stp3=strstr(stp1+1,item);	
	if(stp3!=NULL)
		sscanf((ST_CHAR *)(stp3+strlen(item)),"%s",out);

	if(stp2 != NULL)
		*stp2 = '[';
}

ST_CHAR *openf2s(ST_CHAR *infile)
{
	FILE * iniFd;
	ST_LONG inilength; 
	ST_CHAR *inifdstr;

	if ((iniFd = fopen (infile, "r")) == NULL)
	{
		log_printf ("Can't open \"%s\"\n", infile);
		return NULL;
	}

	inilength=ftell(iniFd);
	fseek(iniFd,0,SEEK_END);
	inilength=ftell(iniFd)-inilength;

	if ((inifdstr=malloc(inilength+1)) == NULL)
	{
		log_printf ("Can't malloc");
		fclose (iniFd);
		return NULL;
	}

	memset(inifdstr, 0, inilength);
	fseek(iniFd,0,SEEK_SET);
	fread (inifdstr, 1, inilength, iniFd);
	inifdstr[inilength]=0;
	fclose (iniFd);
	return inifdstr;
}

ST_VOID closef2s(ST_CHAR *filestr)
{
	if(filestr != NULL)
		free(filestr);    
}

ST_CHAR WMD_PATH[255];

ST_RET ReadDeviceCFG()
{
	ST_CHAR *inifdstr;
	ST_CHAR strKey[NAMESIZE],strTmp[NAMESIZE];
	ST_INT DeviceIdx = 0;

	inifdstr = openf2s(WMD_PATH);
	if (inifdstr == NULL)
		return SD_FAILURE;

	for(;;)
	{
		sprintf(strKey,"[LOCALIP]");
		iniGetStr(inifdstr, strKey, "IP1=", strTmp);
		if (NULL != strTmp)
		{
			localIP1 = inet_addr(strTmp);
		}

		iniGetStr(inifdstr, strKey, "IP2=", strTmp);
		if (NULL != strTmp)
		{
			localIP2 = inet_addr(strTmp);
		}

		sprintf(strKey,"[DEVICE%d]", DeviceIdx+1);
		if (strstr(inifdstr,strKey) == NULL || DeviceIdx >= MAX_DEVICE)
			break;

		iniGetStr(inifdstr, strKey, "MODEL=", strTmp);
		strcpy(device_node_table[DeviceIdx].DeviceModel, strTmp);

		iniGetStr(inifdstr, strKey, "IP1=", strTmp);
		if (NULL != strTmp)
		{
			device_node_table[DeviceIdx].IP1 = inet_addr(strTmp);
		}

		iniGetStr(inifdstr, strKey, "IP2=", strTmp);
		if (NULL != strTmp)
		{
			device_node_table[DeviceIdx].IP2 = inet_addr(strTmp);
		}
		else
		{
			device_node_table[DeviceIdx].IP2 = device_node_table[DeviceIdx].IP1;
		}

		DeviceIdx++;
	}

	numDevice = DeviceIdx;

	/**************************************************/
	closef2s(inifdstr);
	return SD_SUCCESS;
}

ST_VOID ReleaseDeviceNode()
{
	if (pmemOBJTree)
	{
		free(pmemOBJTree);
		pmemOBJTree = NULL;
	}
}

ST_VOID InitDeviceNode()
{
	ST_INT  i;
	ST_ULONG ulSize;

	ulSize = OMOBJTreeSize();
	pmemOBJTree = (ST_CHAR *)malloc(ulSize);
	ZeroMemory(pmemOBJTree,ulSize);

	*((ST_INT *)pmemOBJTree) = 10;
	device_node_table = (DEVICE_NODE *)(pmemOBJTree + sizeof(ST_INT) + MAX_DEVICE * sizeof(ACSI_CTRL));
	acsi_ctrl_table = (ACSI_CTRL *)(pmemOBJTree + sizeof(ST_INT));
	pACSINode = (ACSI_NODE *)(pmemOBJTree + sizeof(ST_INT) + MAX_DEVICE * sizeof(ACSI_CTRL) + 
		MAX_DEVICE * sizeof(DEVICE_NODE));
#ifdef _use_tagRelaySOEFIFO
	pSOEFIFO = (tagSOEFIFO *)((ST_UCHAR *)pACSINode + MAX_DEVICE * sizeof(ACSI_NODE));
	pRLYSOEFIFO = (tagRelaySOEFIFO *)((ST_UCHAR *)pSOEFIFO + sizeof(tagSOEFIFO));

	pSOEFIFO->numSOE = 0;
	pSOEFIFO->readp = 0;
	pSOEFIFO->writep = 0;

	pRLYSOEFIFO->numSOE = 0;
	pRLYSOEFIFO->readp = 0;
	pRLYSOEFIFO->writep = 0;
#endif

	for (i=0; i<MAX_DEVICE; i++)
	{
		memset(&acsi_ctrl_table[i],0,sizeof(ACSI_CTRL));
		acsi_ctrl_table[i].IsEnd = STAT_END;
		acsi_ctrl_table[i].CMD = CMD_NULL;
		acsi_ctrl_table[i].bShow = SD_FALSE;
	}

	ReadDeviceCFG();
	*((ST_INT *)pmemOBJTree) = numDevice;
}

void InitDeviceNode_mvl_type_ctrl()
{
#ifdef _MVL_TYPE_CTRL_use_one_device_
	int i = 0;
	ACSI_NODE *p = NULL;
	PIPE_MSG_BUFS *pMsgBufs = NULL;

	for (i=0; i<numDevice; i++)
	{
		p = &pACSINode[i];
		mvl_init_type_ctrl(&p->p_mvl_type_ctrl);

		pMsgBufs = g_pPipeMsgBuffs+i;
		pMsgBufs->p_mvl_type_ctrl = p->p_mvl_type_ctrl;
	}

#endif
}