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

	//��ʱ�洢ITEM��STACK

	//��Ӧ��GuideBook
	CGuideBook* m_pGuideBook;

	//WORD����ĸ�����
	CWnd* m_pParentWnd;
	HWND m_hParentWnd;

	//���ظ����Ա�麯��
public:
	virtual long New(CString strReportMapFile, CString strReportTemplFile, CString strReportFile);
	virtual long Open(const CString  &strReportFile);
	virtual long Save();
	virtual long SaveAs(CString  strRptFile);
	virtual long Close(long nSave);

	//��ȡ���鱨�洦������������
	//���ڵ������鱨����������������Ĳ���
	virtual void SetParentWnd(CWnd* pParentWnd);
	virtual CWnd* GetReportMainWnd();
	//���ݿ���ʾ��ͼ�Ĵ�С����������ͼ��С
	virtual void AdjustReportWindowOnSize();
	//�Ƿ������Ҫ��д�ı������ݵ�λ��
	virtual long HasReportNeedFill(const CGbItemBase* pItem);
	//���ñ������ݣ���д����
	virtual long FillReport(CReport* pReport);
	//�ڱ����ж�λ
	virtual long LocateReport(CGbItemBase* pItem);
	//��������
	virtual long AdjustReport();

	virtual void SetGuideBook(CGuideBook* pGuideBook){ m_pGuideBook = pGuideBook;};

	virtual void PrintReport();
	virtual void ZoomReport(long nPercentage);
	virtual long GetZoomReport();
public:
	//��д������غ���
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

	//��λ������غ���
	long LocateReport(CRptDatas *pDatas);
	long LocateReport(CRptData *pData);
	long LocateReport(CRptBkmk *pBkmk);

	MSWord::Cells GetCells(CRptBkmk *pBkmk, BOOL bRowMode);
	void ChopValueString(CRptData *pData, CString &strValue);

	//��䱨��Ŀհ�λ��
	long AdjustReport_FillEmpty();
	long AdjustReport_FillEmpty(const CString &strReplace, CExBaseObject *pObj);
	long AdjustReport_FillEmpty(const CString &strReplace, CExBaseList *pList);
	long AdjustReport_FillEmpty(const CString &strReplace, CRptData *pData);
	long AdjustReport_FillEmpty(const CString &strReplace, CRptBkmk *pBkmk);

	//�������������λ��
	long AdjustReport_Area();
	long AdjustReport_Area(CExBaseList *pList);
	long AdjustReport_Area(CItems *pItems);
	long AdjustReport_DelArea(CGbItemBase *pItem);
	long AdjustReport_DelArea(CRptArea *pArea);
	long GetBkmkPos(CRptBkmk *pBkmk, long &nBeginPos, long &nEndPos);
	void DeleteBkmk(MSWord::Bookmarks bookmarks, const CString &strBkmk);
};
