//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XCharElementTestPoints.h  CXCharElementTestPoints

#pragma once

#include "CharacteristicGlobal.h"

class CXCharElementTestPoints : public CExBaseObject
{
public:
	CXCharElementTestPoints();
	virtual ~CXCharElementTestPoints();

	CString  m_strFrom;
	CString  m_strTo;
	CString  m_strStep;

	double m_dFrom;
	double m_dTo;
	double m_dStep;
	
//重载函数
public:
	virtual UINT GetClassID() {    return CHARCLASSID_CCHARELEMENTTESTPOINTS;   }
	virtual BSTR GetXmlElementKey()  {      return CCharacteristicXmlRWKeys::CCharElementTestPointsKey();     }
	virtual long XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys);
	virtual long XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys);
	virtual void InitAfterRead();
	virtual BOOL IsEqualOwn(CBaseObject* pObj);
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();
	virtual long SerializeOwn(CBinarySerialBuffer &oBinaryBuffer);

//私有成员变量
private:

//私有成员变量访问方法
public:

};

