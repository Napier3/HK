#pragma once

#include "SttXMainConfigGlobal.h"
#include "SttXuiDataBase.h"

class CSttXuiDataCmd : public CSttXuiDataBase
{
public:
	CSttXuiDataCmd();
    ~CSttXuiDataCmd() override;

public:
	CString  m_strType;
	CString  m_strData_Src;
	CString m_strArgv;  //2022-10-5  lijunqing
//÷ÿ‘ÿ∫Ø ˝
public:
    UINT GetClassID() override {    return MNGRCLASSID_CSTTXUIDATACMD;   }
    BSTR GetXmlElementKey() override {      return CSttXMainConfigXmlRWKeys::CSttXuiDataCmdKey();     }
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

