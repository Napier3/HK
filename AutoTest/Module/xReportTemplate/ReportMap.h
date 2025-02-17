#pragma once

//�������� ��������ӳ���ļ�

#include "ReportTemplateDefine.h"
#include "RptData.h"

class CReportMap : public CExBaseList
{
public:
	CReportMap(void);
	CReportMap(const CString strFilePath);
	virtual ~CReportMap(void);

//����
public:
	CString  m_strFilePath;

private:
	//ΪFindBkmk���ã�
	CExBaseObject* FindBkmkInList(const CString&  strBkmk,CExBaseList* pList);

	CExBaseList *m_pGuideBookRef;

//�����ӿ�
public:
	
	CExBaseObject* FindBkmk(const CString  strBkmk);

	void InsertBkmk(const CString  strBkmk);
	CExBaseObject* FindItemByID(const CString  strID);//���Բ��ҵ���Items��Item��Datas��Data
	CExBaseObject* FindItem(long nIndex);
	
	//���ļ����
	void Open(const CString  strFilePath);
	void SaveAs(const CString  strFilePath);
	void Save();
	void Save(const CString  strFilePath);

	//������ҵָ�������Ϊÿһ������ڵ��ӦGbItem����
	void AttachGuideBook(CExBaseList *pGuideBook);  

//��д���෽��
public:
	virtual UINT GetClassID() {        return RPTCLASSID_RPTREPORTMAP;             }     
	virtual BSTR GetXmlElementKey()  {      return CRptXmlRWKeys::g_pRptXmlRWKeys->m_strMapFileKey;     }
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail);
	virtual CExBaseObject* CreateNewChild(long nClassID);

};


//CExBaseObject* _FindTheItemByID(CExBaseList *pList, CString strID);