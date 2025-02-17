#pragma once

#include "SttXMainConfigGlobal.h"
#include "SttXuiDataBase.h"

class CSttXuiDataFileType : public CSttXuiDataBase
{
public:
	CSttXuiDataFileType();
    ~CSttXuiDataFileType() override;

public:
	CString  m_strRoot;
	CString  m_strType;

public:
    UINT GetClassID() override {    return MNGRCLASSID_CSTTXUIDATAFILETYPE;   }
    BSTR GetXmlElementKey() override {      return CSttXMainConfigXmlRWKeys::CSttXuiDataFileTypeKey();     }
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

