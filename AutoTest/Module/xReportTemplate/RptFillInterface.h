#pragma once
/*
   ���洦��ģ��Ľӿ�
   ���ű��洦���ȫ���������
*/

#include "../GuideBook/GuideBookInterface.h"

class CRptFillInterface
{
public:
	CRptFillInterface(void);
	virtual ~CRptFillInterface(void);

protected:
	//����ӳ���ϵ�ļ�
	CString m_strReportMapFile;

	//����ģ���ļ�
	CString m_strReportTemplFile;

	//�����ļ�
	CString m_strReportFile;

public:
	virtual long New(CString strReportMapFile, CString strReportTemplFile, CString strReportFile) = 0;
	virtual long Open(const CString  &strReportFile) = 0;
	virtual long Save() = 0;
	virtual long SaveAs(CString  strRptFile)= 0;
	virtual long Close(long nSave) = 0;

	//��ȡ���鱨�洦������������
	//���ڵ������鱨����������������Ĳ���
	virtual void SetParentWnd(CWnd* pParentWnd) = 0;
	virtual CWnd* GetReportMainWnd() = 0;

	//���ݿ���ʾ��ͼ�Ĵ�С����������ͼ��С
	virtual void AdjustReportWindowOnSize() = 0;

	//�Ƿ������Ҫ��д�ı������ݵ�λ��
	virtual long HasReportNeedFill(const CGbItemBase* pItem) = 0;

	//���ñ������ݣ���д����
	virtual long FillReport(CReport* pReport) = 0;

	//�ڱ����ж�λ
	virtual long LocateReport(CGbItemBase* pItemBase) = 0;

	//��������
	virtual long AdjustReport() = 0;

	//
	virtual void SetGuideBook(CGuideBook* pGuideBook) = 0;

	virtual void AttachReportMap(CReportMap* pReportMap) = 0;
	virtual void FreeReportMap() = 0;

	virtual void PrintReport() = 0;
	virtual void ZoomReport(long nPercentage) = 0;
	virtual long GetZoomReport() = 0;
};
