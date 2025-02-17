#pragma once
/*
   报告处理模块的接口
   开放报告处理的全部功能入口
*/

#include "../GuideBook/GuideBookInterface.h"

class CRptFillInterface
{
public:
	CRptFillInterface(void);
	virtual ~CRptFillInterface(void);

protected:
	//报告映射关系文件
	CString m_strReportMapFile;

	//报告模板文件
	CString m_strReportTemplFile;

	//报告文件
	CString m_strReportFile;

public:
	virtual long New(CString strReportMapFile, CString strReportTemplFile, CString strReportFile) = 0;
	virtual long Open(const CString  &strReportFile) = 0;
	virtual long Save() = 0;
	virtual long SaveAs(CString  strRptFile)= 0;
	virtual long Close(long nSave) = 0;

	//获取试验报告处理程序的主窗口
	//用于调整试验报告界面与主程序界面的布局
	virtual void SetParentWnd(CWnd* pParentWnd) = 0;
	virtual CWnd* GetReportMainWnd() = 0;

	//根据可显示试图的大小调整报告试图大小
	virtual void AdjustReportWindowOnSize() = 0;

	//是否包含需要填写的报告数据的位置
	virtual long HasReportNeedFill(const CGbItemBase* pItem) = 0;

	//设置报告数据，填写报告
	virtual long FillReport(CReport* pReport) = 0;

	//在报告中定位
	virtual long LocateReport(CGbItemBase* pItemBase) = 0;

	//调整报告
	virtual long AdjustReport() = 0;

	//
	virtual void SetGuideBook(CGuideBook* pGuideBook) = 0;

	virtual void AttachReportMap(CReportMap* pReportMap) = 0;
	virtual void FreeReportMap() = 0;

	virtual void PrintReport() = 0;
	virtual void ZoomReport(long nPercentage) = 0;
	virtual long GetZoomReport() = 0;
};
