#pragma once
#include "..\..\..\..\Module\GridCtrl\Gridctrl.h"
#include "..\ReadSCDF.h"
#include "stPublicFun.h"

const int nFileGIn = 10;
const CString strFileGIn[nFileGIn] = {_T("序号"),_T("AppID"),_T("MAC"),_T("通道数目"),
	_T("引用数目"),_T("控制块所在IED"),_T("数据集描述"),_T("gocbRef"),_T("Dataset"),_T("goID")};
const int nFileGOut = 7;
const CString strFileGOut[nFileGOut] = {_T("序号"),_T("AppID"),
	_T("MAC"),_T("通道数目"),_T("gocbRef"),_T("Dataset"),_T("goID")};
const int nFileSmvIn = 7;
const CString strFileSmvIn[nFileSmvIn] = {_T("序号"),_T("AppID"),
	_T("MAC"),_T("通道数目"),_T("引用数目"),_T("控制块所在IED"),_T("smvID")};

const int nFIleSmvOut = 8;
const CString strFileSmvOut[nFIleSmvOut] = {_T("序号"),_T("AppID"),
	_T("MAC"),_T("条目数"),_T("svID"),_T("优先级"),_T("VLanID"),_T("版本号")};


class CIEDGrid : public CGridCtrl
{
	DECLARE_DYNCREATE(CIEDGrid)

public:
	CIEDGrid();
	virtual ~CIEDGrid();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
public:
	enum IMPORTFILETYPE{FILEGIN,FILEGOUT,FILESMVIN};
	//  创建列表
	void CreateGrid(int nRow,int nCol,int nFixedRow = 0,int nFixedCol = 0);
	void SetGridHead(const CString* pCstr, const int nCount);
	void SetGridRowData_GooseInput(const PGOOSEIN giptitr,int nRow);
	void SetGridRowData_GooseOutput(const PGOOSEOUT goptitr,int nRow);
	void SetGridRowData_SMVInput(const PSMVIN smviptitr,int nRow);
	void SetGridRowData_SMVOutput(const PSMVOUT smvoptitr,int nRow);
	// 初始化列表
	void InitGrid(int nimportfiletype,const CLIENTIEDPTR& showiedPtr);
	// 删除全部，除表头
	void DeleteAllItems();

	void ShowGooseInput(CScdDataList& listGooseIn);
	void ShowGooseOutput(CScdDataList& listGooseOut);
	void ShowSMVInput(CScdDataList& listSMVIn);
	void ShowSMVOutput(CScdDataList& listSMVOut);

	void SetIEDCtrlCheck(BOOL bCheck,DWORD dwitrAddr);
	void GetSelIedPtr(long &nType, DWORD &dwItrAddr)
	{
		if (m_nRowCurSel > 0)
		{
			nType = m_nType;
			dwItrAddr = GetItemData(m_nRowCurSel, 0);
		}
		else
		{
			dwItrAddr = 0;
		}
	}

private:
	int m_nRowCurSel;
	int m_nType;
	CString m_strIEDDes;
	CString m_strIEDName;
};

const int nFileGInChn = 6;
const CString strFileGInChn[nFileGInChn] = {_T("序号"),_T("内部地址"),_T("内部信号描述"),
	_T("外部信号序号"),_T("外部信号地址"),_T("外部信号描述")};
const int nFileGOutChn = 6;
const CString strFileGOutChn[nFileGOutChn] = {_T("序号"),_T("LN描述"),_T("DOI描述"),
	_T("DAI描述"),_T("类型"),_T("地址")};
const int nFileSmvInChn = 6;
const CString strFileSmvInChn[nFileSmvInChn] = {_T("序号"),_T("内部地址"),_T("内部信号描述"),
	_T("外部信号序号"),_T("外部信号地址"),_T("外部信号描述")};
const int nFileSmvOutChn = 4;
const CString strFileSmvOutChn[nFileSmvOutChn] = {_T("序号"),_T("LN描述"),_T("DOI描述"),_T("地址")};

const int AddSMVType = 2;
const CString strAddSMVType[AddSMVType] = {_T("9-2协议"),_T("FT3扩展协议")};

class CIEDChnGrid : public CGridCtrl
{
	DECLARE_DYNCREATE(CIEDChnGrid)

public:
	CIEDChnGrid();
	virtual ~CIEDChnGrid();

protected:
	DECLARE_MESSAGE_MAP()
public:
	enum IMPORTFILETYPE{FILEGINCHN,FILEGOUTCHN,FILESMVINCHN};
	// 创建表头
	void CreateGrid(int nRow,int nCol,int nFixedRow = 0,int nFixedCol = 0);
	// 初始化列表
//	void InitGrid(const CHNINFO& info);
	// 删除全部，除表头
	void DeleteAllItems();


	void SetGridHead(const CString* pCstr, const int nCount);
	void SetGridRowData_GooseInputChn(const INPUTCHNPtr& giptPtrchn,int nRow);
	void SetGridRowData_GooseOutputChn(const GOOSEOUTPUTCHNPtr& goptchnPtr,int nRow);
	void SetGridRowData_SMVInputChn(const INPUTCHNPtr& smviptchnPtr,int nRow);
	void SetGridRowData_SMVOutputChn(const SMVOUTPUTCHNPtr& smvoptchnPtr,int nRow);

	void ShowGooseInputChn(const GOOSEINPtr& giptPtr);
	void ShowGooseOutputChn(const GOOSEOUTPtr& goptPtr);
	void ShowSMVInputChn(const SMVINPtr& smviptPtr);
	void ShowSMVOutputChn(const SMVOUTPtr& smvoptPtr);


public:
	void InitGrid(const DWORD dwPtr,const UINT showType);
};

