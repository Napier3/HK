#pragma once

#include "SttXMainConfigGlobal.h"
#include "SttXuiDataBase.h"


class CSttXuiDataText : public CSttXuiDataBase
{
public:
	CSttXuiDataText();
    ~CSttXuiDataText() override;

public:
    long  m_nX{};
    long  m_nY{};
    long  m_nCx{};
    long  m_nCy{};
    CString  m_strText{};
    CString  m_strFont{};
    CString  m_strPic{};

public:
    UINT GetClassID() override {    return MNGRCLASSID_CSTTXUIDATATEXT;   }
    BSTR GetXmlElementKey() override {      return CSttXMainConfigXmlRWKeys::CSttXuiDataTextKey();     }
    long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys) override;
    long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys) override;
    long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer) override;
    void InitAfterRead() override;
    BOOL IsEqualOwn(CBaseObject* pObj) override;
    BOOL CopyOwn(CBaseObject* pDest) override;
    CBaseObject* Clone() override;
    CBaseObject* CloneEx(BOOL bCopyOwn=TRUE, BOOL bCopyChildren=FALSE) override;
    BOOL CanPaste(UINT nClassID) override;
    CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys) override;
    CExBaseObject* CreateNewChild(long nClassID) override;
};

