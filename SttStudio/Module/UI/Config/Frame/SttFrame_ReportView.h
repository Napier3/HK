//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SttFrame_ReportView.h  CSttFrame_ReportView

#pragma once

#include "SttTestCtrlFrameCfgMngrGlobal.h"


#include "SttFrame_Font.h"

class CSttFrame_ReportView : public CExBaseList
{
public:
	CSttFrame_ReportView();
	virtual ~CSttFrame_ReportView();


//重载函数
public:
	virtual UINT GetClassID() {    return MNGRCLASSID_CSTTFRAME_REPORTVIEW;   }
	virtual BSTR GetXmlElementKey()  {      return CSttTestCtrlFrameCfgMngrXmlRWKeys::CSttFrame_ReportViewKey();     }
	virtual long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);
	virtual void InitAfterRead();
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
	virtual CBaseObject* CloneEx(BOOL bCopyOwn=TRUE, BOOL bCopyChildren=FALSE);
	virtual BOOL CanPaste(UINT nClassID);
	virtual CExBaseObject* CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys);
	virtual CExBaseObject* CreateNewChild(long nClassID/*, BOOL &bAddToTail*/);

//私有成员变量
private:
	CSttFrame_Font *m_pFont;

//私有成员变量访问方法
public:
	CSttFrame_Font* GetFont()	{	return m_pFont;	}
	void SetFont(CSttFrame_Font* pFont)	{	m_pFont = pFont;	}

//属性变量访问方法
public:
};

