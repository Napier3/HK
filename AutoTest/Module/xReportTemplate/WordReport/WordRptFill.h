#pragma once

#include "../RptFillInterface.h"
#include "../../../../Module/Office/msword9.h"
#include "../ReportTemplateInterface.h"
#include "stack"
using namespace std;


class CWordRptFill :	public CRptFillInterface
{
public:
	CWordRptFill(void);
	virtual ~CWordRptFill(void);
	virtual void AttachReportMap(CReportMap* pReportMap);
	virtual void FreeReportMap();

protected:
	MSWord::_Document m_oDoc;
	HWND m_hWordWnd;
	CReportMap* m_pReortMap;
	BOOL m_bAttachReportMap;

	//临时存储ITEM的STACK

	//对应的GuideBook
	CGuideBook* m_pGuideBook;

	//WORD报告的父窗口
	CWnd* m_pParentWnd;
	HWND m_hParentWnd;

	//重载父类成员虚函数
public:
	virtual long New(CString strReportMapFile, CString strReportTemplFile, CString strReportFile);
	virtual long Open(const CString  &strReportFile);
	virtual long Save();
	virtual long SaveAs(CString  strRptFile);
	virtual long Close(long nSave);

	//获取试验报告处理程序的主窗口
	//用于调整试验报告界面与主程序界面的布局
	virtual void SetParentWnd(CWnd* pParentWnd);
	virtual CWnd* GetReportMainWnd();
	//根据可显示试图的大小调整报告试图大小
	virtual void AdjustReportWindowOnSize();
	//是否包含需要填写的报告数据的位置
	virtual long HasReportNeedFill(const CGbItemBase* pItem);
	//设置报告数据，填写报告
	virtual long FillReport(CReport* pReport);
	//在报告中定位
	virtual long LocateReport(CGbItemBase* pItem);
	//调整报告
	virtual long AdjustReport();

	virtual void SetGuideBook(CGuideBook* pGuideBook){ m_pGuideBook = pGuideBook;};

	virtual void PrintReport();
	virtual void ZoomReport(long nPercentage);
	virtual long GetZoomReport();
public:
	//填写报告相关函数
	CRptItem* Match(CReport *pReport);
	CRptItem* Match(CGbItemBase* pItemBase);
	CRptItem* MatchItem(CGbItemBase* pItemBase);

	BOOL IsRptDataSingleMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr &oTag);
	void FillReport(CRptData *pData, CReport *pReport);
	void FillReportSingle(CRptData *pData, CReport *pReport);
	void FillReportGroup(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTag);
	void FillReportGroupColMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTagDataDef);
	void FillReportGroupRowMode(CRptData *pData, CReport *pReport, SystemTool::ITagPtr oTagDataDef);
	void FillReport(CRptDatas *pDatas, CReport *pReport);
	void FillReport(const CString &strValue, CRptBkmk *pBkmk);
	void FillReportCell(const _bstr_t &strValue, MSWord::Cell oCell);

	void AdjustWordWindowOnSize();

private:
	void CreateWordApp();
	BOOL CloseWordDocWindow();
	void AdjustWordWindow();

	BOOL AddNewReport(const CString &strRptTmplFile);

	//定位报告相关函数
	long LocateReport(CRptDatas *pDatas);
	long LocateReport(CRptData *pData);
	long LocateReport(CRptBkmk *pBkmk);

	MSWord::Cells GetCells(CRptBkmk *pBkmk, BOOL bRowMode);
	void ChopValueString(CRptData *pData, CString &strValue);

	//填充报告的空白位置
	long AdjustReport_FillEmpty();
	long AdjustReport_FillEmpty(const CString &strReplace, CExBaseObject *pObj);
	long AdjustReport_FillEmpty(const CString &strReplace, CExBaseList *pList);
	long AdjustReport_FillEmpty(const CString &strReplace, CRptData *pData);
	long AdjustReport_FillEmpty(const CString &strReplace, CRptBkmk *pBkmk);

	//调整报告的区域位置
	long AdjustReport_Area();
	long AdjustReport_Area(CExBaseList *pList);
	long AdjustReport_Area(CItems *pItems);
	long AdjustReport_DelArea(CGbItemBase *pItem);
	long AdjustReport_DelArea(CRptArea *pArea);
	long GetBkmkPos(CRptBkmk *pBkmk, long &nBeginPos, long &nEndPos);
	void DeleteBkmk(MSWord::Bookmarks bookmarks, const CString &strBkmk);
};
