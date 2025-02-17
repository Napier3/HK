#ifndef _STDATADEF_H
#define _STDATADEF_H
#include <algorithm>
#include <vector>
#include <map>
#include <list>
using namespace std;

//��������
#define SAMPLE_TYPE_9_1		0x0000
#define SAMPLE_TYPE_9_1_EX	0x0001
#define SAMPLE_TYPE_9_2		0x0100
//ͬ��FT3
#define SAMPLE_TYPE_FT3		0x0200
#define SAMPLE_TYPE_FT3_EX	0x0201
//�첽FT3
#define SAMPLE_TYPE_FT3_ASYN 0x0300


#define WM_USERUPDATECHN (WM_USER+1010)

//�����������֧�ֵĵ�ѹ�����ͨ����
#define MAX_CHANNEL_COUNT     16

// �����������֧�ֵĿ������򿪳�������
#define MAX_IO_COUNT          16

// IO ����װ�������֧�ֵĿ������򿪳�������
#define MAX_IO_COUNT_EX      256

//������ID��󳤶�
#define MAX_MACHINE_ID_LENGTH 32

//�����������֧�ֵ���ͨ����
#define TOTAL_CHANNEL_COUNT   (MAX_CHANNEL_COUNT*2)

// �����������֧�ֵ��ܿ���������
#define TOTAL_IO_COUNT        (MAX_IO_COUNT*2)

//���UIͨ����
#define MAX_TST_MUCHN     128

//����� ������
#define MAX_FILL_SET_NUM	128

//==================================================================================
//������󳤶�
#define MAX_PACKET_SIZE		1536

//======================================GSE ���====================================
//GseIn ���������Ŀ
#define MAX_GSE_IN_NUM	20
//GseOut ���������Ŀ
#define MAX_GSE_OUT_NUM	20

#define MAX_GOCBREF_LEN 64
#define MAX_GOID_LEN	64
#define MAX_DATASET_LEN	64
#define MAX_MACADDR_LEN 6
//GSE�����С�������
#define MAX_MAP_BIN_NUM	512
#define MIN_MAP_BIN_NUM	1



#pragma once

#define SHARED_PTR(P) std::tr1::shared_ptr<P>
#define WEAK_PTR(P) std::tr1::weak_ptr<P>
#define CONTAINER_LIST_TYPE(P) std::list<SHARED_PTR(P) >
#define CONTAINER_LIST_TYPE_ITERATOR(P) CONTAINER_LIST_TYPE(P)::iterator 

typedef struct _MU_CHNSET
{
	int nIndex;			// ͨ�����
	int nChnSel;		// ͨ��ѡ��
	DWORD m_DOWD_Q;		// Ʒ��λ����
	CString strInput;   // �ֶ�����ֵ
	CString strChnName;	// ͨ������
	BOOL bCheck;        // �Ƿ���б��Ĳ���(Ʒ�ʲ������ֵ����ʱ��Ч)

	// 2012-03-01
	int nTypeSel;       // ����ѡ�� 0-��ѹ,1-������������,2-������������,3-ʱ��
}MU_CHNSET;

const int TestType = 8;
const int MaxItem = 3;

typedef struct _tagMSGTestSet
{
	int nIndex;

	BOOL bCheck;		// ���ƴ���
	UINT nNum;			// ���ƴ���
	UINT nTestType;		// ��������
	int TestTypeSet[TestType][MaxItem];        // �������Ͳ�������
	UINT TestBeginPt;						   // ������ʼ֡

	// 2011-10-20
	UINT logicCheck;
	int nStartType;
}MSGTESTSET,*PMSGTESETSET;

typedef std::tr1::shared_ptr<MSGTESTSET> MSGTESTSETPtr;

/************************************************************************/
/* zy 2012-03-12 ͨ����������                                           */
/************************************************************************/
typedef struct tagMuCfgData
{
	UINT32 uIndex;		// ͨ������
	UINT32 uChnType;	// ͨ������ 0:��ѹ��1:������3:ʱ��

	int nSetData;		// �ɵ�����õ�һ������ֵ
	
	float Mag;			// ��ֵ*10000
	float Ang;			// ��λ*10000 -> 0~360
	float Fre;			// Ƶ��*10000
	float Quo;			// 9-2:PT/CT��� * 10000 ; 9-1:����(0x1cf,0x2d41)
	
	float fData1;		// PT/CT �ֵ1
	float fData2;		// PT/CT �ֵ2
	
	float fFirstData;	// �仯��ֵ
	float fLastData;    // �仯��ֹ
	float fStep;		// �仯����

	BOOL  bQuaTest;		// Ʒ�ʻ��ֵ����
	BOOL  bVar;			// �Ƿ�Ϊ����

	CString strName;	// ͨ������
}MuCfgData,*pMuCfgData;

// MUͨ������
typedef struct _MU_SETTING
{
	int nIndex;		   // ���
	BOOL bUsed;        // ���ñ��
	CString strMac;    // Ŀ��MAC��ַ
	CString SourceMac; // ԴMAC��ַ
	int AppId;		   // AppId
	int nTCIPr;		   // TCI Priority;
	int nTciVid;       // TCI VID
	int nLanNo;		   // ������ѡ��
	int nVersion;	   // �汾��
	CString strDes;	   // ����
	int nChnNum;		// ÿ֡ͨ����
	BOOL bSynAuto;     // ͬ���Ƿ�����Ӧ

	USHORT CurrentA;		// ������
	USHORT CurrentScp;		// ��������������
	USHORT CurrentNeut;	    // ����ߵ���
	USHORT VoltA;			// ����ѹ

	// ��9-2��ȫ��ʹ��
	DWORD dwState1;      // ״̬��1
	DWORD dwState2;      // ״̬��2
	USHORT LDName;		 // LDName
	UCHAR LNName;		 // LNName
	USHORT DataName;     // ���ݼ���

	// 9-2ʹ��
	CString strSvid;     // SVID
	BOOL bSyn;			 // �Ƿ�ͬ��
	float fCTBitRate;	 // 9-2ʹ�� ����ֵ(��Ϊfloat)*10000(����ʹ��2^14=16384����ARM��ͨ����λ��ɳ���)
	float fPTBitRate;

	// Ft3��Ft3Exʹ��
	DWORD CurrentDelay;  // ���ʱ

	// ���ͨ��ѡ��
	vector<MU_CHNSET> pmu_chnset;

	/************************************************************************/
	/* zy 2012-03-12 ͨ�����ݶ���   									    */
	/************************************************************************/
	MuCfgData UIs[MAX_TST_MUCHN];
	
	MSGTESTSETPtr msgtestsetPtr;

	bool operator==(const _MU_SETTING& musetting) const 
	{
		return (musetting.AppId == AppId && musetting.strMac == strMac);
	}
}MU_SETTING; 

// MUͨ������
typedef struct _MU_GENERALSETTTING
{
	int nSampleType;       // 0---9-1,1---9-2,2---9-1Ex,3---Ft3,4---Ft3Ex
	int nCurSelCtrl;       // ��ǰѡ��Ŀ��ƿ�����
	DOUBLE dSampleRate;    // ������
	int nMode1588;		   // 1588ͬ����ʽ ��(0)/����(1)/�ӻ�(2)
	int nMuCfgNum;		   // �������������ܳ���7��4�����ڡ�3Ft3��
//	USHORT dwAsduLen;      // ����Asdu���ݳ��� ; 9-1/Ex�У��纬ASDU״̬���ݼ����򳤶�Ӧ��״̬�����ȡ�FT3��0
	int nAsduNum;		   // ASDU�� ���ɱ���ʱ����ⱨ�ĳ����Ƿ�1536�ֽڡ�������1500ʱ���棩FT3=1
	double dSecondCurrent; // 9-1/Ex Ft3/Exʹ��  0x01:1 A�� 0x05:5A��
	DWORD dwConfRev;       //     

	double dFTSampleRate;  // FT3��������	//2011-06-08
	int nFT3Format;        // FT3���ĸ�ʽ	//2011-06-30
	BOOL bConver;          // �⴮��ת��Ϊ���������	//2011-07-11      
	BOOL bSynMode;         // TRUE---ͬ�� FALSE---�첽	//2012-02-02  
}MU_GENERALSETTTING;

//GOOSE ��������
typedef struct _tagGseChnCfg
{
	int nIndex;			// ���
	int nIOIndex;		// �󶨿��뿪�����
	CString strChnName; // ��Ŀ����

	int nType;			// ����:0---����,1---˫�㣬2---ʱ�䣬3---Ʒ�ʣ�4---���㣬5---�ַ�����6---���ͣ�7---�ṹ
	
	CString strValue;	// ֵ
	BOOL bInStruct;		// �Ƿ�ṹ��������

	int nLenValue;
	DWORD dwLenStartPos; // �࿪ʼ�ĳ���

	bool operator==(const _tagGseChnCfg& gsechncfg) const 
	{
		return (gsechncfg.nIOIndex == nIOIndex);
	}
}GSECHNCFG;

/************************************************************************/
/* zy 2012-4-12 ���� Goose ���Ĳ���                                     */
/************************************************************************/
typedef struct _tagGsePktTestSet
{
	BOOL bLimit;			// ���ƴ���
	UINT nLmNum;			// ���ƴ���
	UINT nTestType;			// ��������
	int	 TestParam[4][3];	// �������Ͳ�������
	UINT nTestPT;			// ������ʼ֡
}GsePktTestSet,*pGsePktTestSet;

typedef std::tr1::shared_ptr<GsePktTestSet> GsePktTestSetPtr;

typedef struct _tagcfg_GseIn
{
	int nIndex;    // ���

	// GOOSEINʹ��
	UINT ChkMask;	//��λ���壬��Ӧ������Ŀ�����ӣ�TTL��ʱ�����������ƥ��

	// GOOSEOUTʹ��
	USHORT LanNo;

	CString	GocbRef;
	CString	GoID;
	CString	DataSet;
	CString strDes;	// ����
	BOOL Used;		//����(1)/����(0)
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
	/* zy 2012-4-12 Goose ���Ĳ��Զ���                                      */
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

	int GseInNumSel;	// ��������	
	int GseOutNumSel;

	vector<GSECFG> GseInCfg;
	vector<GSECFG> GseOutCfg;

} GSEUI;

typedef struct MapBin_Get
{
	USHORT BinOrder;	//��������
	USHORT BinType;	    //��������� 83/84
	UINT	MapType;	//������Դ����
}MAPBIN_GET;

typedef struct fillset_Mu_Content
{
	UINT FillType;//������Դ����
	UINT FillCtrl;//�����ƣ���16λ=���λ�ã���16λ=��䳤��
} FILLSETCONTENT;

typedef struct _tag_FillSet_MU
{
	USHORT FillSetNum;	                        //������PC��������˴�ָ����������Ҫ��������
	FILLSETCONTENT FillSet[MAX_FILL_SET_NUM];   //���������
}FILLSET_MU;

typedef struct _tag_MUCtrl_UI
{
	DWORD smpCntFill;     // �������������
	UINT nFillStartPos;   // ͨ�������ʼλ��
}MUCTRL_UI;

typedef struct _tag_mu_cfg
{
	//0422����
	DWORD smpCntFill;     // �������������
	UINT nFillStartPos;   // ͨ�������ʼλ��

	UINT PacketDataLen;   // �������ݵ�ʵ�ʳ���
	UCHAR PacketData[MAX_PACKET_SIZE];//��������
	             
	UINT nAsduLen;        // ASDU����
	FILLSET_MU FillSet;   // ���������
	FILLSET_MU TestSet;   // ������������Ĳ���
}MUDOWN_CFG;

typedef struct _tagBin_Fill
{
	UINT MapType;	//������Դ����
	UINT FillCtrl;	//�����ƣ���16λ=���λ�ã���16λ=��䳤��
	USHORT BinType;	//��������� 83/84
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

	UINT PacketLen;					    //���ĳ���
	UCHAR PacketData[MAX_PACKET_SIZE];  //��������
	UINT MapBinNum;					    //��ӳ������Ӹ���
	UINT FillSetNum;	                //������PC��������˴�ָ����������Ҫ��������
	UINT AllDataLen;
	BINFILL	MapBinCfg[MAX_MAP_BIN_NUM];

	UINT ttlFill;
	UINT tFill;
	UINT stnumFill;
	UINT sqnumFill;

	/************************************************************************/
	/* zy 2012-4-12 Goose���Ĳ������λ��                                   */
	/************************************************************************/
	//FILLSET_MU PktTestSet;				//������������Ĳ���
} CFG_GSEOUTFILE;

typedef struct _tagBin_Get
{
	USHORT BinOrder;	//��������
	USHORT BinType;	    //��������� 83/84
	UINT MapType;	//������Դ����
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
	USHORT MapBinNum;      // ��ӳ������Ӹ���
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

