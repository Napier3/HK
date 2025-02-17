#pragma once

#include "SttXMainConfigGlobal.h"
#include "SttXuiDataBase.h"
#include "SttXuiDataTab.h"

class CSttXuiDataTabs : public CSttXuiDataBase
{
public:
	CSttXuiDataTabs();
    ~CSttXuiDataTabs() override;

public:
    long  m_nX{};
    long  m_nY{};
    long  m_nCy{};
    long  m_nCx{};
    CString m_strFont{};
//÷ÿ‘ÿ∫Ø ˝
public:
    UINT GetClassID() override {    return MNGRCLASSID_CSTTXUIDATATABS;   }
    BSTR GetXmlElementKey() override {      return CSttXMainConfigXmlRWKeys::CSttXuiDataTabsKey();     }
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

