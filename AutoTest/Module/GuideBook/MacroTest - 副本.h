#pragma once

#include "GbItemBase.h"
#include "GuideBookDefine.h"
#include "Msg.h"
#include "MacroTestPara.h"
#include "CommCmd.h"

class CMacroTest : public CGbItemBase
{
public:
	CMacroTest();
	virtual ~CMacroTest();

	static CMacroTest* _New(CBaseObject *pParent=NULL)
	{
		CMacroTest *pNew = new CMacroTest();
		pNew->InitAfterRead();
		pNew->SetParent(pParent);
		pNew->InitMacroID();
		return pNew;
	}

	void InitMacroID();

public:
	CString m_strType;
	long m_nRepeatTimes;  //重复次数
	long m_nTestTimes;

	//报告处理方式:
	//0=每次独立的报告，own
	//1=最后一次作为报告
	//2=平均值作为报告，average
	//3=最大值，max
	//4=最小值，min
	CString m_strReportMode;   

	LONG GetCalMode()
	{
		return Gb_GetReportCalMode(m_strReportMode);
	}

protected:
	CExBaseList m_oListMsgs;
	CMacroTestPara* m_pPara;

public:
	void SetTestMacroID(const CString &strTestMacroID);
	CString GetTestMacroID();
	CExBaseList* GetMsgs()						{		return &m_oListMsgs;			}
	CMacroTestPara* GetMacroTestPara();
	CMacroTestParaDatas* GetFaultParaDatas();
	CMacroTestParaDatas* GetFultParaDatasUser();
	virtual BOOL GetItemParaValue(const CString &strValueID, double &dValue);
	virtual long SetItemParaValue(const CString & strValueID, const CString & strValue, BOOL bAddNew=FALSE);

	virtual void AdjustReprtDatas();
	void UpdateMacroTestParaData(const CShortData  *pData, BOOL bShowLog)		{		m_pPara->UpdateMacroTestParaData(pData, bShowLog);	}
	void ValidateMacroTestParaData(const CShortData  *pData)		{		m_pPara->ValidateMacroTestParaData(pData);	}
	void UpdateMacroTestParaData(const CShortData  *pData, const CString &strMacroID, BOOL bShowLog)		{		m_pPara->UpdateMacroTestParaData(pData, strMacroID, bShowLog);	}
	void UpdateMacroTestParaData(const CString &strID, const CString &strValue, BOOL bShowLog)		{		m_pPara->UpdateMacroTestParaData(strID, strValue, bShowLog);	}
	void ResetMacroTestParaData()		{		m_pPara->ResetMacroTestParaData();	}
	CExBaseObject* FindMacroTestParaData(const CShortData  *pData)		{		return m_pPara->FindMacroTestParaData(pData);	}
	void UpdateMacroTestParaDataUser(const CShortData  *pData)		{		m_pPara->UpdateMacroTestParaDataUser(pData);	}

//重写父类方法
public:
	virtual UINT GetClassID()		{		return GBCLASSID_MACROTEST;			}

	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual long XmlReadOwn(const MSXML2::IXMLDOMNodePtr &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(const MSXML2::IXMLDOMDocumentPtr &oXMLDoc, const MSXML2::IXMLDOMElementPtr &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual BSTR GetXmlElementKey(){		return CGbXMLKeys::g_pGbXMLKeys->m_strMacroTestKey;	};

	virtual void InitAfterRead();

	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys);
	virtual CExBaseObject* CreateNewChild(long nClassID);

	virtual BOOL IsEqual(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDesObj);

	virtual CBaseObject* Clone();
	virtual BOOL CanPaste(UINT nClassID);

#ifdef GUIDEBOOK_DEV_MODE
	virtual void GenerateDevReports();
#endif

	void ClearReport();

	virtual void ReplaceSrciptText(CScriptText *pScript, UINT nScriptClassID, CGbItemBase *pSrcGbItem, BOOL bShowLog);
	void FreeTestParas()	{	m_pPara->FreeTestParas();	}
};

void Gb_ResetMacroParas(CTestMacro* pMacro);
void Gb_ResetDatas(CShortDatas *pDatas);
CString Gb_GetMacroScriptUiDll(CMacroTest *pMacroTest);
