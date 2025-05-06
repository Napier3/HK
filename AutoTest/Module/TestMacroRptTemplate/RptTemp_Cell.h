//���Դ������ClassGenerator����
//��Ȩ���� Eric  Eric1224@126.com
//��������Ȩ��

//RptTemp_Cell.h  CRptTemp_Cell

#pragma once

#include "TestMacroRptTemplateGlobal.h"



class CRptTemp_Cell : public CExBaseObject
{
public:
	CRptTemp_Cell();
	virtual ~CRptTemp_Cell();


	long  m_nRow_Span;
	long  m_nCol_Span;
	CString  m_strText;
	CString  m_strData_Path;  //������Ŀ�����·��������Ϊһ�������·����������һ��ģ������һ���̻�����ʱʵ�֡�
	CString  m_strType;  //������Դ���Ͷ��壺data-id��text��test-index����CRptTemp_ColDef��m_strType����
//���غ���
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CRPTTEMP_CELL;   }
	virtual BSTR GetXmlElementKey()  {      return CTestMacroRptTemplateXmlRWKeys::CRptTemp_CellKey();     }
	virtual long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual void InitAfterRead();
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
	virtual CBaseObject* CloneEx(BOOL bCopyOwn=TRUE, BOOL bCopyChildren=FALSE);

//˽�г�Ա����
private:

//˽�г�Ա�������ʷ���
public:

//���Ա������ʷ���
public:
};

