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

ST_BOOLEAN bSCADA;
ST_BOOLEAN bOBJTree;
HANDLE hmemOBJTree;
ST_UCHAR *pmemOBJTree;

extern ACSI_CTRL *acsi_ctrl_table;

ST_LONG shareOBJTreeSize()
{
ST_LONG s;
	s = sizeof(ST_INT) + sizeof(REQ_CTRL) + 
		MAX_DEVICE * sizeof(DEVICE_NODE) +
		sizeof(ACSI_NODE);
	return s;
}

ST_BOOLEAN IsProcessExit(ST_CHAR *pName)
{
HANDLE hd;
ST_BOOLEAN ret = SD_FALSE;

	hd = CreateMutex(NULL,TRUE, pName);
	Sleep(100);
	if(hd){
		if(GetLastError() == ERROR_ALREADY_EXISTS)
						ret = SD_TRUE;
		ReleaseMutex(hd);
	}
	return ret;
}

HANDLE BuildmemOBJTree()
{
ST_LONG s;
HANDLE  hShareMem;
	s = shareOBJTreeSize();
	hShareMem = CreateFileMapping((HANDLE)0xffffffff,
				NULL,
				PAGE_READWRITE, 
				0,    
				s,   
				"memOBJTree");
	return hShareMem;
}

ST_UCHAR *GetmemOBJTreePtr(HANDLE hShareMem)
{
ST_UCHAR *pData;
	pData = (ST_UCHAR *)MapViewOfFile(hShareMem,FILE_MAP_ALL_ACCESS,0,0,0);
	return pData;
}

ST_BOOLEAN InformOthers()
{
ST_BOOLEAN ret = SD_FALSE;
HANDLE hd;
	hd = CreateMutex(NULL,TRUE, "61850Client");
	Sleep(100);
	if(hd){
		ret = SD_TRUE;
	}
	return ret;
}

ST_VOID InitDeviceNode()
{
ST_INT  i;
DEVICE_NODE *pDevice;
REQ_CTRL *pReq;
	hmemOBJTree = BuildmemOBJTree();
	if(0 == hmemOBJTree)
			exit(100);
	pmemOBJTree = GetmemOBJTreePtr(hmemOBJTree);
	*((ST_INT *)pmemOBJTree) = 10;
	pDevice = (DEVICE_NODE *)(pmemOBJTree + sizeof(ST_INT) + sizeof(REQ_CTRL));
	for(i=0; i<MAX_DEVICE; i++){
			sprintf(pDevice[i].DeviceModel,"ISA61850-%d",i+1);
		    pDevice[i].IP1 = (i+123) << 24 + 1 << 16 + 1 << 8 + 10;
		    pDevice[i].IP2 = (i+123) << 24 + 1 << 16 + 1 << 8 + 10;
	}
	pReq = (REQ_CTRL *)(pmemOBJTree + sizeof(ST_INT));
	pReq->CMD = CMD_NULL;
	pReq->IsEnd = STAT_END;
	pReq->nDevice = 0;
	pReq->nRCB = 0;
	pReq->nDeviceHMI = 0;
}

ST_VOID ServeOBJTree()
{
REQ_CTRL *pReq;
	pReq = (REQ_CTRL *)(pmemOBJTree + sizeof(ST_INT));
	if(pReq-> IsEnd == STAT_WAIT)		
			return;
	else	pReq-> IsEnd = STAT_END;

	if(pReq->CMD == CMD_NULL)
			return;

	if(pReq->nDevice != pReq->nDeviceHMI){
			pReq->CMD = CMD_NULL;
			return;
	}

	switch(pReq->CMD){
	case	CMD_DIR:	
		acsi_ctrl_table[pReq->nDeviceHMI%MAX_DEVICE].needDirectory = SD_TRUE;
		pReq-> IsEnd = STAT_WAIT;
		break;
	case	CMD_START_RCB:		
		acsi_ctrl_table[pReq->nDeviceHMI%MAX_DEVICE].startRCB[pReq->nRCB] = SD_TRUE;
		pReq-> IsEnd = STAT_WAIT;		
		break;
	case	CMD_STOP_RCB:		 
		acsi_ctrl_table[pReq->nDeviceHMI%MAX_DEVICE].stopRCB[pReq->nRCB] = SD_TRUE;
		pReq-> IsEnd = STAT_WAIT;		
		break;
	case	CMD_CONTROL:		 
		break;
	case	CMD_READ_SG:		 
		break;
	case	CMD_WRITE_SE:		 
		break;
	}
}
