//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//SetsFileXml_SI.cpp  CSetsFileXml_SI


#include "stdafx.h"
#include "SetsFileXml_SI.h"

#ifdef _DEBUG
#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSetsFileXml_SI::CSetsFileXml_SI()
{
	//初始化属性

	//初始化成员变量
}

CSetsFileXml_SI::~CSetsFileXml_SI()
{
}

long CSetsFileXml_SI::XmlReadOwn(CXmlRWNodeBase &oNode, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_GetAttibuteValue(pXmlKeys->m_strDescKey, oNode, m_strDesc);
	xml_GetAttibuteValue(pXmlKeys->m_strTypeKey, oNode, m_strType);
	xml_GetAttibuteValue(pXmlKeys->m_strUnitKey, oNode, m_strUnit);
	xml_GetAttibuteValue(pXmlKeys->m_strMinKey, oNode, m_strMin);
	xml_GetAttibuteValue(pXmlKeys->m_strMaxKey, oNode, m_strMax);
	xml_GetAttibuteValue(pXmlKeys->m_strStepKey, oNode, m_strStep);
	xml_GetAttibuteValue(pXmlKeys->m_strRefKey, oNode, m_strRef);
	return 0;
}

long CSetsFileXml_SI::XmlWriteOwn(CXmlRWDocBase &oXMLDoc, CXmlRWElementBase &oElement, CXmlRWKeys *pXmlRWKeys)
{
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;

	xml_SetAttributeValue(pXmlKeys->m_strDescKey, oElement, m_strDesc);
	xml_SetAttributeValue(pXmlKeys->m_strTypeKey, oElement, m_strType);
	xml_SetAttributeValue(pXmlKeys->m_strUnitKey, oElement, m_strUnit);
	xml_SetAttributeValue(pXmlKeys->m_strMinKey, oElement, m_strMin);
	xml_SetAttributeValue(pXmlKeys->m_strMaxKey, oElement, m_strMax);
	xml_SetAttributeValue(pXmlKeys->m_strStepKey, oElement, m_strStep);
	xml_SetAttributeValue(pXmlKeys->m_strRefKey, oElement, m_strRef);
	return 0;
}

long CSetsFileXml_SI::SerializeOwn(CBinarySerialBuffer &oBinaryBuffer)
{
	if(oBinaryBuffer.IsCalSizeMode())
	{
		BinarySerializeCalLen(oBinaryBuffer, m_strDesc);
		BinarySerializeCalLen(oBinaryBuffer, m_strType);
		BinarySerializeCalLen(oBinaryBuffer, m_strUnit);
		BinarySerializeCalLen(oBinaryBuffer, m_strMin);
		BinarySerializeCalLen(oBinaryBuffer, m_strMax);
		BinarySerializeCalLen(oBinaryBuffer, m_strStep);
		BinarySerializeCalLen(oBinaryBuffer, m_strRef);
	}
	else if(oBinaryBuffer.IsReadMode())
	{
		BinarySerializeRead(oBinaryBuffer, m_strDesc);
		BinarySerializeRead(oBinaryBuffer, m_strType);
		BinarySerializeRead(oBinaryBuffer, m_strUnit);
		BinarySerializeRead(oBinaryBuffer, m_strMin);
		BinarySerializeRead(oBinaryBuffer, m_strMax);
		BinarySerializeRead(oBinaryBuffer, m_strStep);
		BinarySerializeRead(oBinaryBuffer, m_strRef);
	}
	else if(oBinaryBuffer.IsWriteMode())
	{
		BinarySerializeWrite(oBinaryBuffer, m_strDesc);
		BinarySerializeWrite(oBinaryBuffer, m_strType);
		BinarySerializeWrite(oBinaryBuffer, m_strUnit);
		BinarySerializeWrite(oBinaryBuffer, m_strMin);
		BinarySerializeWrite(oBinaryBuffer, m_strMax);
		BinarySerializeWrite(oBinaryBuffer, m_strStep);
		BinarySerializeWrite(oBinaryBuffer, m_strRef);
	}
	return 0;
}

void CSetsFileXml_SI::InitAfterRead()
{
}

BOOL CSetsFileXml_SI::IsEqualOwn(CBaseObject* pObj)
{
	if(this == pObj)
	{
		return TRUE;
	}

	CSetsFileXml_SI *p = (CSetsFileXml_SI*)pObj;

	if(m_strDesc != p->m_strDesc)
	{
		return FALSE;
	}

	if(m_strType != p->m_strType)
	{
		return FALSE;
	}

	if(m_strUnit != p->m_strUnit)
	{
		return FALSE;
	}

	if(m_strMin != p->m_strMin)
	{
		return FALSE;
	}

	if(m_strMax != p->m_strMax)
	{
		return FALSE;
	}

	if(m_strStep != p->m_strStep)
	{
		return FALSE;
	}

	if(m_strRef != p->m_strRef)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CSetsFileXml_SI::CopyOwn(CBaseObject* pDest)
{
	if(this == pDest)
	{
		return TRUE;
	}

	CSetsFileXml_SI *p = (CSetsFileXml_SI*)pDest;

	p->m_strDesc = m_strDesc;
	p->m_strType = m_strType;
	p->m_strUnit = m_strUnit;
	p->m_strMin = m_strMin;
	p->m_strMax = m_strMax;
	p->m_strStep = m_strStep;
	p->m_strRef = m_strRef;
	return TRUE;
}

CBaseObject* CSetsFileXml_SI::Clone()
{
	CSetsFileXml_SI *p = new CSetsFileXml_SI();
	Copy(p);
	return p;
}

CBaseObject* CSetsFileXml_SI::CloneEx(BOOL bCopyOwn/*=TRUE*/, BOOL bCopyChildren/*=FALSE*/)
{
	CSetsFileXml_SI *p = new CSetsFileXml_SI();
	CopyEx(p, bCopyOwn, bCopyChildren);
	return p;
}

BOOL CSetsFileXml_SI::CanPaste(UINT nClassID)
{
	if (nClassID == MNGRCLASSID_CSETSFILEXML_VAL)
	{
		return TRUE;
	}

	return FALSE;
}

CExBaseObject* CSetsFileXml_SI::CreateNewChild(const CString &strClassID, BOOL &bAddToTail, CXmlRWKeys *pXmlRWKeys)
{
	CExBaseObject *pNew  = NULL;
	CSetFileXmlParseXmlRWKeys *pXmlKeys = (CSetFileXmlParseXmlRWKeys*)pXmlRWKeys;


	if (strClassID == pXmlKeys->m_strCSetsFileXml_ValKey)
	{
		pNew = new CSetsFileXml_Val();
	}

	return pNew;
}

CExBaseObject* CSetsFileXml_SI::CreateNewChild(long nClassID/*, BOOL &bAddToTail*/)
{
	CExBaseObject *pNew  = NULL;


	if (nClassID == MNGRCLASSID_CSETSFILEXML_VAL)
	{
		pNew = new CSetsFileXml_Val();
	}

	return pNew;
}

//nGrp：定值区号
void CSetsFileXml_SI::ParseToDvm(CDvmDataset *pDataset, long nGrp)
{
	CDvmData *pData = new CDvmData;
	pDataset->AddNewChild(pData);

	pData->m_strDataType = m_strType;
	pData->m_strName = m_strDesc;
	pData->m_strID = m_strDesc;
	pData->m_strMin = m_strMin;
	pData->m_strMax = m_strMax;
	pData->m_strStep = m_strStep;
	pData->m_strUnit = m_strUnit;

	//老版本的XML格式文件，包含多个定值区的定值，可以通过索引号查找
	//CSetsFileXml_Val *pVal = (CSetsFileXml_Val *)GetAt(nGrp - 1);

	//新版本的XML格式的定值文件，SI下面只放了一个Val，只能通过定值区号获取
	CSetsFileXml_Val *pVal = (CSetsFileXml_Val *)GetValByGrp(nGrp);

	if (pVal == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR, _T("XML格式定值文件错误，定值【%s】未找到 区号=%d 的值！"), m_strDesc, nGrp);
		return;
	}

	pData->m_strValue = pVal->m_strVal;
}

CSetsFileXml_Val* CSetsFileXml_SI::GetValByGrp(long nGrp)
{
	POS pos = GetHeadPosition();
	CSetsFileXml_Val *pFind = NULL;

	while (pos != NULL)
	{
		CSetsFileXml_Val *pVal = (CSetsFileXml_Val *)GetNext(pos);

		if (pVal->m_nGrp == nGrp)
		{
			pFind = pVal;
			break;
		}
	}

	return pFind;
}

CString CSetsFileXml_SI::GetValByGrp_String(long nGrp)
{
	CSetsFileXml_Val *pFind = GetValByGrp(nGrp);

	if (pFind == NULL)
	{
		return _T("");
	}

	return pFind->m_strVal;
}