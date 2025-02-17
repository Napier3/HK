#ifndef _STDATADEF_H
#define _STDATADEF_H
#include <algorithm>
#include <vector>
#include <map>
#include <list>
using namespace std;

//采样类型
#define SAMPLE_TYPE_9_1		0x0000
#define SAMPLE_TYPE_9_1_EX	0x0001
#define SAMPLE_TYPE_9_2		0x0100
//同步FT3
#define SAMPLE_TYPE_FT3		0x0200
#define SAMPLE_TYPE_FT3_EX	0x0201
//异步FT3
#define SAMPLE_TYPE_FT3_ASYN 0x0300


#define WM_USERUPDATECHN (WM_USER+1010)

//测试仪最多能支持的电压或电流通道数
#define MAX_CHANNEL_COUNT     16

// 测试仪最多能支持的开入量或开出量个数
#define MAX_IO_COUNT          16

// IO 测试装置最多能支持的开入量或开出量个数
#define MAX_IO_COUNT_EX      256

//测试仪ID最大长度
#define MAX_MACHINE_ID_LENGTH 32

//测试仪最多能支持的总通道数
#define TOTAL_CHANNEL_COUNT   (MAX_CHANNEL_COUNT*2)

// 测试仪最多能支持的总开关量个数
#define TOTAL_IO_COUNT        (MAX_IO_COUNT*2)

//最大UI通道数
#define MAX_TST_MUCHN     128

//填充项 最大个数
#define MAX_FILL_SET_NUM	128

//==================================================================================
//报文最大长度
#define MAX_PACKET_SIZE		1536

//======================================GSE 相关====================================
//GseIn 启用最大数目
#define MAX_GSE_IN_NUM	20
//GseOut 启用最大数目
#define MAX_GSE_OUT_NUM	20

#define MAX_GOCBREF_LEN 64
#define MAX_GOID_LEN	64
#define MAX_DATASET_LEN	64
#define MAX_MACADDR_LEN 6
//GSE最大最小虚端子数
#define MAX_MAP_BIN_NUM	512
#define MIN_MAP_BIN_NUM	1



#pragma once

#define SHARED_PTR(P) std::tr1::shared_ptr<P>
#define WEAK_PTR(P) std::tr1::weak_ptr<P>
#define CONTAINER_LIST_TYPE(P) std::list<SHARED_PTR(P) >
#define CONTAINER_LIST_TYPE_ITERATOR(P) CONTAINER_LIST_TYPE(P)::iterator 

typedef struct _MU_CHNSET
{
	int nIndex;			// 通道编号
	int nChnSel;		// 通道选择
	DWORD m_DOWD_Q;		// 品质位数据
	CString strInput;   // 手动输入值
	CString strChnName;	// 通道名称
	BOOL bCheck;        // 是否进行报文测试(品质测试与错值测试时有效)

	// 2012-03-01
	int nTypeSel;       // 类型选择 0-电压,1-电流（保护）,2-电流（测量）,3-时间
}MU_CHNSET;

const int TestType = 8;
const int MaxItem = 3;

typedef struct _tagMSGTestSet
{
	int nIndex;

	BOOL bCheck;		// 限制次数
	UINT nNum;			// 限制次数
	UINT nTestType;		// 测试类型
	int TestTypeSet[TestType][MaxItem];        // 测试类型参数设置
	UINT TestBeginPt;						   // 测试起始帧

	// 2011-10-20
	UINT logicCheck;
	int nStartType;
}MSGTESTSET,*PMSGTESETSET;

typedef std::tr1::shared_ptr<MSGTESTSET> MSGTESTSETPtr;

/************************************************************************/
/* zy 2012-03-12 通道数据设置                                           */
/************************************************************************/
typedef struct tagMuCfgData
{
	UINT32 uIndex;		// 通道索引
	UINT32 uChnType;	// 通道类型 0:电压；1:电流；3:时间

	int nSetData;		// 飞点测试用的一个设置值
	
	float Mag;			// 幅值*10000
	float Ang;			// 相位*10000 -> 0~360
	float Fre;			// 频率*10000
	float Quo;			// 9-2:PT/CT变比 * 10000 ; 9-1:比例(0x1cf,0x2d41)
	
	float fData1;		// PT/CT 额定值1
	float fData2;		// PT/CT 额定值2
	
	float fFirstData;	// 变化初值
	float fLastData;    // 变化终止
	float fStep;		// 变化步径

	BOOL  bQuaTest;		// 品质或错值测试
	BOOL  bVar;			// 是否为变量

	CString strName;	// 通道名称
}MuCfgData,*pMuCfgData;

// MU通道设置
typedef struct _MU_SETTING
{
	int nIndex;		   // 序号
	BOOL bUsed;        // 启用标记
	CString strMac;    // 目标MAC地址
	CString SourceMac; // 源MAC地址
	int AppId;		   // AppId
	int nTCIPr;		   // TCI Priority;
	int nTciVid;       // TCI VID
	int nLanNo;		   // 光网口选择
	int nVersion;	   // 版本号
	CString strDes;	   // 描述
	int nChnNum;		// 每帧通道数
	BOOL bSynAuto;     // 同步是否自适应

	USHORT CurrentA;		// 额定相电流
	USHORT CurrentScp;		// 额定相电流比例因子
	USHORT CurrentNeut;	    // 额定中线电流
	USHORT VoltA;			// 额定相电压

	// 除9-2外全部使用
	DWORD dwState1;      // 状态字1
	DWORD dwState2;      // 状态字2
	USHORT LDName;		 // LDName
	UCHAR LNName;		 // LNName
	USHORT DataName;     // 数据集名

	// 9-2使用
	CString strSvid;     // SVID
	BOOL bSyn;			 // 是否同步
	float fCTBitRate;	 // 9-2使用 界面值(可为float)*10000(建议使用2^14=16384，则ARM可通过移位完成除法)
	float fPTBitRate;

	// Ft3、Ft3Ex使用
	DWORD CurrentDelay;  // 额定延时

	// 输出通道选择
	vector<MU_CHNSET> pmu_chnset;

	/************************************************************************/
	/* zy 2012-03-12 通道数据定义   									    */
	/************************************************************************/
	MuCfgData UIs[MAX_TST_MUCHN];
	
	MSGTESTSETPtr msgtestsetPtr;

	bool operator==(const _MU_SETTING& musetting) const 
	{
		return (musetting.AppId == AppId && musetting.strMac == strMac);
	}
}MU_SETTING; 

// MU通用配置
typedef struct _MU_GENERALSETTTING
{
	int nSampleType;       // 0---9-1,1---9-2,2---9-1Ex,3---Ft3,4---Ft3Ex
	int nCurSelCtrl;       // 当前选择的控制块索引
	DOUBLE dSampleRate;    // 采样率
	int nMode1588;		   // 1588同步方式 无(0)/主机(1)/从机(2)
	int nMuCfgNum;		   // 启用配置数不能超过7（4光网口、3Ft3）
//	USHORT dwAsduLen;      // 单个Asdu数据长度 ; 9-1/Ex中，如含ASDU状态数据集，则长度应含状态集长度。FT3＝0
	int nAsduNum;		   // ASDU数 生成报文时，检测报文长度是否超1536字节。（超过1500时警告）FT3=1
	double dSecondCurrent; // 9-1/Ex Ft3/Ex使用  0x01:1 A制 0x05:5A制
	DWORD dwConfRev;       //     

	double dFTSampleRate;  // FT3采样速率	//2011-06-08
	int nFT3Format;        // FT3报文格式	//2011-06-30
	BOOL bConver;          // 光串口转换为光网口输出	//2011-07-11      
	BOOL bSynMode;         // TRUE---同步 FALSE---异步	//2012-02-02  
}MU_GENERALSETTTING;

//GOOSE 界面数据
typedef struct _tagGseChnCfg
{
	int nIndex;			// 序号
	int nIOIndex;		// 绑定开入开出序号
	CString strChnName; // 条目名称

	int nType;			// 类型:0---单点,1---双点，2---时间，3---品质，4---浮点，5---字符串，6---整型，7---结构
	
	CString strValue;	// 值
	BOOL bInStruct;		// 是否结构体内类型

	int nLenValue;
	DWORD dwLenStartPos; // 距开始的长度

	bool operator==(const _tagGseChnCfg& gsechncfg) const 
	{
		return (gsechncfg.nIOIndex == nIOIndex);
	}
}GSECHNCFG;

/************************************************************************/
/* zy 2012-4-12 增加 Goose 报文测试                                     */
/************************************************************************/
typedef struct _tagGsePktTestSet
{
	BOOL bLimit;			// 限制次数
	UINT nLmNum;			// 限制次数
	UINT nTestType;			// 测试类型
	int	 TestParam[4][3];	// 测试类型参数设置
	UINT nTestPT;			// 测试起始帧
}GsePktTestSet,*pGsePktTestSet;

typedef std::tr1::shared_ptr<GsePktTestSet> GsePktTestSetPtr;

typedef struct _tagcfg_GseIn
{
	int nIndex;    // 序号

	// GOOSEIN使用
	UINT ChkMask;	//按位定义，对应以下项目，增加：TTL超时、虚端子类型匹配

	// GOOSEOUT使用
	USHORT LanNo;

	CString	GocbRef;
	CString	GoID;
	CString	DataSet;
	CString strDes;	// 描述
	BOOL Used;		//启用(1)/禁用(0)
	USHORT	ConfRev;
	USHORT	NdsCom;
	CString	MacAddr;
	CString SourceMac;
	USHORT	Priority;
	USHORT	VID;
	USHORT	AppID;
	USHORT T0;
	USHORT T1;
	USHORT T2;
	USHORT T3;
	USHORT TMult;
	BOOL Test;
	UINT BinNum;
	UINT OldBinNum;

	vector<GSECHNCFG> ChnCfg;

	/************************************************************************/
	/* zy 2012-4-12 Goose 报文测试定义                                      */
	/************************************************************************/
	GsePktTestSetPtr GsetestsetPtr;

	bool operator==(const _tagcfg_GseIn& gsecfg) const 
	{
		return (gsecfg.AppID == AppID && gsecfg.MacAddr == MacAddr);
	}
} GSECFG;

typedef struct _tagUI_Gse
{
	UINT	Version;		//0x20110309

	int GseInNumSel;	// 启用配置	
	int GseOutNumSel;

	vector<GSECFG> GseInCfg;
	vector<GSECFG> GseOutCfg;

} GSEUI;

typedef struct MapBin_Get
{
	USHORT BinOrder;	//虚端子序号
	USHORT BinType;	    //虚端子类型 83/84
	UINT	MapType;	//数据来源编码
}MAPBIN_GET;

typedef struct fillset_Mu_Content
{
	UINT FillType;//数据来源编码
	UINT FillCtrl;//填充控制，低16位=填充位置，高16位=填充长度
} FILLSETCONTENT;

typedef struct _tag_FillSet_MU
{
	USHORT FillSetNum;	                        //报文在PC机打包，此处指明报文中需要填充的项数
	FILLSETCONTENT FillSet[MAX_FILL_SET_NUM];   //填充配置项
}FILLSET_MU;

typedef struct _tag_MUCtrl_UI
{
	DWORD smpCntFill;     // 采样计数器填充
	UINT nFillStartPos;   // 通道填充起始位置
}MUCTRL_UI;

typedef struct _tag_mu_cfg
{
	//0422增加
	DWORD smpCntFill;     // 采样计数器填充
	UINT nFillStartPos;   // 通道填充起始位置

	UINT PacketDataLen;   // 报文数据的实际长度
	UCHAR PacketData[MAX_PACKET_SIZE];//报文数据
	             
	UINT nAsduLen;        // ASDU长度
	FILLSET_MU FillSet;   // 填充配置项
	FILLSET_MU TestSet;   // 设置配置项，报文测试
}MUDOWN_CFG;

typedef struct _tagBin_Fill
{
	UINT MapType;	//数据来源编码
	UINT FillCtrl;	//填充控制，低16位=填充位置，高16位=填充长度
	USHORT BinType;	//虚端子类型 83/84
}BINFILL;

typedef struct _tagcfg_GseOutfile
{
	UCHAR GocbRef[MAX_GOCBREF_LEN];
	UINT GocbRefLen;
	UCHAR GoID[MAX_GOID_LEN];
	UINT GoIDLen;
	UCHAR DataSet[MAX_DATASET_LEN];
	UINT DataSetLen;
	UCHAR MacAddr[MAX_MACADDR_LEN];
	UCHAR SourceMac[MAX_MACADDR_LEN];

	UINT PacketLen;					    //报文长度
	UCHAR PacketData[MAX_PACKET_SIZE];  //报文数据
	UINT MapBinNum;					    //已映射虚端子个数
	UINT FillSetNum;	                //报文在PC机打包，此处指明报文中需要填充的项数
	UINT AllDataLen;
	BINFILL	MapBinCfg[MAX_MAP_BIN_NUM];

	UINT ttlFill;
	UINT tFill;
	UINT stnumFill;
	UINT sqnumFill;

	/************************************************************************/
	/* zy 2012-4-12 Goose报文测试填充位置                                   */
	/************************************************************************/
	//FILLSET_MU PktTestSet;				//设置配置项，报文测试
} CFG_GSEOUTFILE;

typedef struct _tagBin_Get
{
	USHORT BinOrder;	//虚端子序号
	USHORT BinType;	    //虚端子类型 83/84
	UINT MapType;	//数据来源编码
}BIN_GET;

typedef struct _tagcfg_GseInfile
{
	UCHAR GocbRef[MAX_GOCBREF_LEN];
	USHORT GocbRefLen;
	UCHAR GoID[MAX_GOID_LEN];
	USHORT GoIDLen;
	UCHAR DataSet[MAX_DATASET_LEN];
	USHORT DataSetLen;

	UCHAR MacAddr[MAX_MACADDR_LEN];
	USHORT MapBinNum;      // 已映射虚端子个数
	BIN_GET	MapBinCfg[MAX_MAP_BIN_NUM];
} CFG_GSEINFILE;

typedef std::tr1::shared_ptr<CFG_GSEOUTFILE> GOUTFILESHAREPTR;
typedef std::vector<GOUTFILESHAREPTR > GOUTFILEGVECTOR;

typedef std::tr1::shared_ptr<CFG_GSEINFILE> GINFILESHAREPTR;
typedef std::vector<GINFILESHAREPTR > GINFILEVECTOR;

typedef struct _tagGSEFILE
{
	UINT	Version;		//0x20110309
	GINFILEVECTOR pGseinCfg;
	GOUTFILEGVECTOR pGseoutCfg;
}GSEFILE;

typedef std::tr1::shared_ptr<MUDOWN_CFG> MUDOWNCFGSHAREPTR;
typedef std::vector<MUDOWNCFGSHAREPTR > MUDOWNCFGVECTOR;

#endif

