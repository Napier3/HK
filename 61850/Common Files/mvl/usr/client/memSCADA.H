#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif

/*与SCADA相关的共享内存由SCADA分配
SISCO的客户机程序，通过以下两个变量：bSCADA,bOBJTree识别SCADA和OBJTree程序是否存在。
SISCO客户机程序，通过命名互斥锁“61850Server”通知其他程序，自己是否存在。
命名互斥锁“memSCADA”  对应SCADA分配的共享内存
memSCADA 由以下几个部分组成：
装置信息库
四遥库
61850解析库
保护定值区
保护测量值区
SOE事件FIFO
保护事件FIFO
*/

/*SOE事件FIFO定义*/
#define MAX_SOE_RPT		512
typedef struct
{
ST_INT		year;
ST_UCHAR	month;
ST_UCHAR	day;

ST_UCHAR	hour;
ST_UCHAR	minute;

ST_INT		second;
ST_INT		ms;
}tagEVENTTIME;

typedef struct
{
ST_CHAR			MARK;			/*1-有效 0-无效*/
ST_UCHAR		stat;			/*0-分 1-合 2-异常*/
ST_INT			SN;
tagEVENTTIME	t;
}tagSOERpt;

typedef struct
{
ST_INT			readp;
ST_INT			writep;
tagSOERpt		soeRpt[MAX_SOE_RPT];
}tagSOEFIFO;

/*保护事件FIFO定义*/
#define MAX_RELAYSOE_RPT		256
typedef struct
{
ST_UCHAR		IP[4];			/*由低到高  从右向左*/
ST_INT			modelSN;		/*事件模板记录号，从0开始*/
ST_UCHAR		action;			/*1-动作 0-复归*/
ST_UCHAR		isDirection;	/*1-方向 0-非方向*/
/*0-接地 1-A相故障 2-B相故障 3-C相故障 4-AB相故障 5-CA相故障 6-BC相故障 7-ABC相故障*/
ST_UCHAR		fault;		
/*0-中线故障方向 1-A相故障方向 2-B相故障方向 3-C相故障方向 4-双向*/
ST_UCHAR		direction;	
ST_UCHAR		measure[4];		/*4字节union*/
tagEVENTTIME	t;
}tagRELAYSOERpt;

typedef struct
{
ST_INT				readp;
ST_INT				writep;
tagRELAYSOERpt		relaysoeRpt[MAX_RELAYSOE_RPT];
}tagRELAYSOEFIFO;

#ifdef  __cplusplus
extern "C" {
#endif

#define   NAMESIZE		64
#define   MAX_YC		6000
#define   MAX_YX		8000
#define   MAX_YM		2000

#define   MAX_LEVEL		20

#define   DEVICE_STAT_UNUSED	0	/*不通*/
#define   DEVICE_STAT_NORMAL	1	/*正常*/
#define   DEVICE_STAT_ERROR		2	/*通、不正常*/

#define   MAX_DEVICE	395
#define   MAX_RCB		60
#define   MAX_DATASET	100

typedef struct
{
ST_UCHAR	IP1[30];
ST_UCHAR	IP2[30];
ST_UCHAR	stat;		/*DEVICE_STAT_?*/
ST_INT		numBHSoe;
ST_VOID		ptrBHSoeModel;
}tagDevice;

typedef struct                   
{
ST_INT		nDevice;				/*装置数组下标*/    
ST_CHAR		LDName[NAMESIZE+1];     
ST_CHAR		RCBName[NAMESIZE+1];    
ST_INT		dsNameIdx;				/*DataSetName[?][NAMESIZE+1]*/		
}tagRCBTable;      

typedef struct
{
ST_INT		SN;						/*遥测点数组下标*/ 
ST_CHAR		mmsVARName[NAMESIZE+1];
ST_UCHAR	mmsDataType;
ST_INT		dsNameIdx;				/*DataSetName[?][NAMESIZE+1]*/
ST_UCHAR	Level[MAX_LEVEL+1];
}tagYCAssoc;

typedef struct
{
ST_INT		SN;
ST_CHAR		mmsVARName[NAMESIZE+1];
ST_UCHAR	mmsDataType;
ST_INT		dsNameIdx;				/*DataSetName[?][NAMESIZE+1]*/
ST_UCHAR	Level[MAX_LEVEL+1];
}tagYXAssoc;

typedef struct
{
ST_INT		SN;
ST_CHAR		mmsVARName[NAMESIZE+1];
ST_UCHAR	mmsDataType;
}tagYKAssoc;

typedef struct
{
ST_INT		SN;
ST_INT		dsNameIdx;				/*DataSetName[?][NAMESIZE+1]*/
ST_INT		dsFCDIdx;				/*SPS,DPS在数据集的索引*/
ST_UCHAR	stValLevel[MAX_LEVEL+1];
ST_UCHAR	tValLevel[MAX_LEVEL+1];
ST_UCHAR	qValLevel[MAX_LEVEL+1];
}tagSOEAssoc;

typedef struct
{
ST_INT		dsNameIdx;				/*DataSetName[?][NAMESIZE+1]*/
ST_INT		dsFCDIdx;				/*ACT,ACD在数据集的索引*/
ST_CHAR 	mmsVARName[NAMESIZE+1];
ST_BOOLEAN	IsDirection;			
ST_UCHAR	GeneralLevel[MAX_LEVEL+1];
ST_UCHAR	RecoverLevel[MAX_LEVEL+1];
ST_UCHAR	PhsALevel[MAX_LEVEL+1];   
ST_UCHAR	PhsBLevel[MAX_LEVEL+1];   
ST_UCHAR	PhsCLevel[MAX_LEVEL+1];   
ST_UCHAR	NeutLevel[MAX_LEVEL+1];   
ST_UCHAR	MeasureLevel[MAX_LEVEL+1];
ST_UCHAR	dirGeneralLevel[MAX_LEVEL+1];
ST_UCHAR	dirPhsALevel[MAX_LEVEL+1];
ST_UCHAR	dirPhsBLevel[MAX_LEVEL+1];
ST_UCHAR	dirPhsCLevel[MAX_LEVEL+1];
ST_UCHAR	dirNeutLevel[MAX_LEVEL+1];
}tagRelaySOEAssoc;


typedef struct
{
ST_INT		iValue;
ST_FLOAT	fValue;		//实测值
ST_UCHAR	bRefresh;	//0-未刷新
}tagAnalog;

typedef struct
{
ST_UCHAR	iValue;
ST_UCHAR    bTest;		//1- 测试状态
ST_UCHAR	bRefresh;	//0-未刷新
}tagSignal;

typedef struct
{
ST_LONG		iValue;
ST_DOUBLE	dValue;		//实测值
ST_UCHAR	bRefresh;	//0-未刷新
}tagPulse;


/*共享内存容量，变量定义顺序
ST_CHAR  dataset[MAX_DATASET+1][NAMESIZE+1]
ACSI_CTRL[MAX_DEVICE+1]
tagDevice[MAX_DEVICE*+1]
tagRCB[MAX_DEVICE*MAX_RCB+1]	
*/

ST_LONG shareSCADASize()
{
ST_LONG s;
	return s;
}


