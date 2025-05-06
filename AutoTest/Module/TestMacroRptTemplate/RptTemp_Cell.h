//这段源代码由ClassGenerator创建
//版权所有 Eric  Eric1224@126.com
//保留所有权利

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
	CString  m_strData_Path;  //其它项目的相对路径，设置为一个“相对路径”，仅在一个模块生成一个固化报告时实现。
	CString  m_strType;  //数据来源类型定义：data-id、text、test-index。与CRptTemp_ColDef的m_strType共用
//重载函数
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

//私有成员变量
private:

//私有成员变量访问方法
public:

//属性变量访问方法
public:
};

