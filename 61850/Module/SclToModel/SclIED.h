#pragma once
#include "..\..\..\Module\BaseClass\ExBaseObject.h"
#include "SclToModelTool.h"

#define SCLCLASSID_SCLIED             (0X00011111)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CSclIED : public CExBaseObject
{
public:
	long m_nChoose;
	CString m_strDevType;
	CString m_strDevModel;
	CString m_strFactoryName;

	CString m_strIP;
	CString m_strSubNet;
	CString m_strGateWay;

	SCL_IED* m_pScl_ied;

	CSclIED();
	virtual ~CSclIED();

	virtual UINT GetClassID()	{	return SCLCLASSID_SCLIED;	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////