#if !defined(_MEMOBJTREE)
#define _MEMOBJTREE

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif

/*与OBJTree相关的共享内存由SISCO客户机程序分配
SISCO的客户机程序，通过以下两个变量：bSCADA,bOBJTree识别SCADA和OBJTree程序是否存在。
SISCO客户机程序，通过命名互斥锁“61850Client”通知其他程序，自己是否存在。
命名互斥锁“memOBJTree”  对应OBJTree分配的共享内存
*/

// #define _use_rptCtl

#ifdef  __cplusplus
extern "C" {
#endif

#include "RptDeCode.h"
#include "sharemem.h"
extern ST_CHAR WMD_PATH[255];

typedef struct{
ST_CHAR dsName[MAX_RCB_VMD][MAX_DSNAME+1];
ST_CHAR EntryID[MAX_RCB_VMD][MAX_DSNAME+1];
}tagRptCtl;

extern ST_BOOLEAN bSCADA;
extern ST_BOOLEAN bOBJTree;
extern HANDLE hmemOBJTree;
extern ST_UCHAR *pmemOBJTree;
extern ST_INT numDevice;
extern ACSI_CTRL *acsi_ctrl_table;
extern DEVICE_NODE *device_node_table;
extern ACSI_NODE *pACSINode;
extern HANDLE hRptNotifyEvent;

#ifdef _use_tagRelaySOEFIFO
extern tagSOEFIFO *pSOEFIFO;
extern tagRelaySOEFIFO *pRLYSOEFIFO;
#endif

#ifdef _use_rptCtl
extern tagRptCtl rptCtl[MAX_DEVICE];
#endif

extern ST_VOID InitDeviceNode();
extern ST_VOID InitDeviceNode_mvl_type_ctrl();
extern ST_VOID ReleaseDeviceNode();
extern ST_BOOLEAN InformOthers();

#ifdef  __cplusplus
}
#endif

#endif

