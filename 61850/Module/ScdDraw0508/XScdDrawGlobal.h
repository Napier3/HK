//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//IecXScdDrawGlobal.h

#pragma once

#include "..\..\..\Module\XDrawBase\XDrawElements.h"
#include "..\..\..\Module\DataMngr\DataMngrGlobal.h"
#include "..\SCL\SclIecCfgDatas.h"
#include "..\CfgDataMngr\IecCfgDevice.h"
#include "..\..\..\Module\BaseClass\XDrawBaseInterface.h"

#define XSCDDRAW_BASECLASS         (XDRAW_BASECLASS   + 0X00100000)
#define XSCDDRAW_EXLISTCLASS       (XDRAW_EXLISTCLASS + 0X00100000)

#define XSCDDRAW_IED_THUMBNAIL        (XSCDDRAW_EXLISTCLASS + 0X00000001)
#define XSCDDRAW_IED_CFG              (XSCDDRAW_EXLISTCLASS + 0X00000002)
#define XSCDDRAW_IED_VTEST            (XSCDDRAW_EXLISTCLASS + 0X00000003)
#define XSCDDRAW_CTRL_CFG_SVOUT       (XSCDDRAW_EXLISTCLASS + 0X00000004)
#define XSCDDRAW_CTRL_CFG_SVIN        (XSCDDRAW_EXLISTCLASS + 0X00000005)
#define XSCDDRAW_CTRL_CFG_GSOUT       (XSCDDRAW_EXLISTCLASS + 0X00000006)
#define XSCDDRAW_CTRL_CFG_GSIN        (XSCDDRAW_EXLISTCLASS + 0X00000007)
#define XSCDDRAW_CTRL_VTEST_SVOUT     (XSCDDRAW_EXLISTCLASS + 0X00000008)
#define XSCDDRAW_CTRL_VTEST_SVIN      (XSCDDRAW_EXLISTCLASS + 0X00000009)
#define XSCDDRAW_CTRL_VTEST_GSOUT     (XSCDDRAW_EXLISTCLASS + 0X0000000A)
#define XSCDDRAW_CTRL_VTEST_GSIN      (XSCDDRAW_EXLISTCLASS + 0X0000000B)
#define XSCDDRAW_LINE                 (XSCDDRAW_BASECLASS   + 0X0000000C)
#define XSCDDRAW_VIEW_THUMB           (XSCDDRAW_EXLISTCLASS + 0X0000000C)
#define XSCDDRAW_VIEW_CFG             (XSCDDRAW_EXLISTCLASS + 0X0000000C)
#define XSCDDRAW_VIEW_VTEST           (XSCDDRAW_EXLISTCLASS + 0X0000000C)

#define XSCDDRAW_LINE_CTRLS          (XSCDDRAW_BASECLASS + 0X0000000D)
#define XSCDDRAW_LINE_CTRL_CH         (XSCDDRAW_BASECLASS + 0X0000000E)
#define XSCDDRAW_LINE_BASE          (XSCDDRAW_BASECLASS + 0X010000001)
#define XSCDDRAW_LINE_VERT         (XSCDDRAW_BASECLASS + 0X010000002)
#define XSCDDRAW_LINE_GOOSEBUS         (XSCDDRAW_BASECLASS + 0X010000003)
#define XSCDDRAW_LINE_SVBUS         (XSCDDRAW_BASECLASS + 0X010000004)
#define XSCDDRAW_LINE_TOBUS        (XSCDDRAW_BASECLASS + 0X010000005)
#define XSCDDRAW_LINE_CTRL          (XSCDDRAW_BASECLASS + 0X010000006)

#define XSCDDRAW_VIEW_IED_GAP_HOR  80
#define XSCDDRAW_VIEW_IED_GAP_VER  10
#define XSCDDRAW_VIEW_GAP     5

#define XSCDDRAW_IED_TITLE_HEIGHT   20
#define XSCDDRAW_IED_WIDTH_MIN      300
#define XSCDDRAW_IED_BORDER_GAP     15

#define XSCDDRAW_CTRL_GAP    45
#define XSCDDRAW_CTRL_GAP_UNMAINIED   5//数据集之间的间隙，两侧的IED使用

#define WM_XSCDDRAW_DATACHANGED  (WM_USER+1202)

#define TlTLE_COL_WIDTH_SEL      32
#define TlTLE_COL_WIDTH_CTRLTYPE 60
#define TlTLE_COL_WIDTH_APPID    60
#define TlTLE_COL_WIDTH_FIBER    50

#define TlTLE_COL_WIDTH_CHANLABEL    90


#define CHANNEL_COL_WIDTH 60

// #define XSCDDRAW_THUMBNAIL_VIEW_GAP 50
// #define XSCDDRAW_THUMBNAIL_GAP_CTRL 5
#define XSCDDRAW_THUMBNAIL_GAP_IED_X 10
#define XSCDDRAW_THUMBNAIL_GAP_IED_Y 300

#define XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE  40
#define XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID    25
#define XSCDDRAW_THUMBNAIL_IED_HEIGHT_CTRLS 25

#define XSCDDRAW_THUMBNAIL_IED_HEIGHT   (XSCDDRAW_THUMBNAIL_IED_HEIGHT_TYPE+XSCDDRAW_THUMBNAIL_IED_HEIGHT_ID+XSCDDRAW_THUMBNAIL_IED_HEIGHT_CTRLS)

#define XSCDDRAW_THUMBNAIL_IED_WIDTH  200
#define XSCDDRAW_THUMBNAIL_CTRL_WIDTH 50
#define XSCDDRAW_ELEMENT_MARGIN             5


class CXScdDrawXmlRWKeys : public CDataMngrXmlRWKeys
{
protected:
	CXScdDrawXmlRWKeys();
	virtual ~CXScdDrawXmlRWKeys();
	static long g_nCFGRef;

public:
	static CXScdDrawXmlRWKeys* g_pXmlKeys;
	static CXScdDrawXmlRWKeys* Create();
	static void Release();


public:


public:
	

};



class CXScdDrawConstGlobal
{
private:
	CXScdDrawConstGlobal();
	virtual ~CXScdDrawConstGlobal();

public:
	static CXScdDrawConstGlobal* Create();
	static void Release();

	static BOOL OnlyShowUsedSvOutChs();
	static BOOL OnlyShowUsedGsOutChs();
	static void SetOnlyShowUsedSvOutChs(long nShow);
	static void SetOnlyShowUsedGsOutChs(long nShow);

private:
	static long g_nGlobalRef;
	static CXScdDrawConstGlobal *g_pGlobal;

	void InitGlobal();

private:
	static long m_nOnlyShowUsedSvOutChs;
	static long m_nOnlyShowUsedGsOutChs;

public:
//定义全局常量管理对象访问函数，例如  static CExBaseList* GetVariableDataTypes()	{	return &(g_pGlobal->m_oVariableDataTypes);	}

//定义全局常量，例如  static CString g_pstrVariableType_CString;

};
