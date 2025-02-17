#pragma once

#include "SttXMainConfigGlobal.h"
#include "SttXuiDataBase.h"
#include "SttXuiDataGlobal.h"
#include "SttXuiDataTabs.h"
#include "SttXuiDataBtnsGroup.h"
#include "SttXuiDataButton.h"
#include "SttXuiDataFileMngrGrid.h"
#include "SttXuiDataTestBtnsGroup.h"
#include "SttXuiDataText.h"

class CSttXuiDataMainConfig : public CSttXuiDataBase
{
public:
	CSttXuiDataMainConfig();
    ~CSttXuiDataMainConfig() override;

    CString  m_strFilePath{};
    CString  m_strVersion{};
    CString  m_strTitle{};
    CString  m_strPic{};
    long  m_nCx{};
    long  m_nCy{};
    long  m_nShowBatteryBtn{};//2024-1-22 zhouyangyong 添加用于是否显示电池电量图标
    double m_dStartupDelayTime{};//开机启动延时时间 zhouhj 2024.5.24
//重载函数
public:
    UINT GetClassID() override {    return MNGRCLASSID_CSTTXUIDATAMAINCONFIG;   }
    BSTR GetXmlElementKey() override {      return CSttXMainConfigXmlRWKeys::CSttXuiDataMainConfigKey();     }
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

