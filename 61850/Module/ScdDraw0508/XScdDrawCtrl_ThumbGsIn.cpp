//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbGsIn.cpp  CXScdDrawCtrl_ThumbGsIn


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbGsIn.h"
#include "XScdDrawLine_Ctrls.h"

CXScdDrawCtrl_ThumbGsIn::CXScdDrawCtrl_ThumbGsIn()
{
	//初始化属性

	//初始化成员变量
	m_strName = _T("GSIN");
	
}

CXScdDrawCtrl_ThumbGsIn::~CXScdDrawCtrl_ThumbGsIn()
{
}

void CXScdDrawCtrl_ThumbGsIn::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrl_ThumbBase::Draw(pDC, fZoomRatio, ptOffset);
}


void CXScdDrawCtrl_ThumbGsIn::CreateCtrlLines()
{
	ASSERT (m_pXDrawDataRef != NULL);

	CSclCtrlsGsIn  *pSclCtrlsGsIn  = (CSclCtrlsGsIn*)m_pXDrawDataRef;
	CSclCtrlGsIn   *pSclCtrlGsIn   = NULL;
	CSclCtrlsGsOut *pSclCtrlsGsOut = NULL;
	CSclCtrlGsOut  *pSclCtrlGsOut  = NULL;

	//CXScdDrawIedThumbnail *pScdDrawIedThumbnail =pSclCtrlsGsIn->GetParent();
	CSclIed *pSclIedByCtrlsGsIn=(CSclIed *)pSclCtrlsGsIn->GetParent();//cgl
	//if(pSclIedByCtrlsGsIn->m_strID!=_T("PB5011A"))
	//{
	//	return;
	//}

	CSclStation *pSclStation = (CSclStation*)m_pXDrawDataRef->GetAncestor(SCLIECCLASSID_STATION);
	ASSERT (pSclStation != NULL);

	if (pSclStation == NULL)
	{
		return;
	}

	POS pos = pSclCtrlsGsIn->GetHeadPosition();
	CXScdDrawLine_Ctrls *pLine = NULL;
	CXScdDrawLine_ToBus *pLineToBus=NULL;
	CXScdDrawLine_ToBus *pLineBusTo=NULL;


	while (pos != NULL)
	{
		pSclCtrlGsIn = (CSclCtrlGsIn *)pSclCtrlsGsOut->GetNext(pos);
		pSclCtrlGsOut = pSclStation->FindCrl_GooseOutput(pSclCtrlGsIn->m_strGooseId);

		if (pSclCtrlGsOut == NULL)
		{
			continue;
		}

		pSclCtrlsGsOut = (CSclCtrlsGsOut *)pSclCtrlGsOut->GetParent();
		CSclIed *pSclIedByCtrlsGsOut=(CSclIed *)pSclCtrlsGsOut->GetParent();

		if(pSclIedByCtrlsGsIn->m_strIedTypeLabel==pSclIedByCtrlsGsOut->m_strIedTypeLabel)
		{
			continue;
		}

		pLine = (CXScdDrawLine_Ctrls*)FindLineByBeginRef(pSclCtrlsGsOut);

		if (pLine == NULL)
		{
			pLine = new CXScdDrawLine_Ctrls();
			pLine->m_pBeginObj = pSclCtrlsGsOut;
			pLine->m_pEndObj   = m_pXDrawDataRef;
			pLine->m_pEndElement = this;
		
			AddNewChild(pLine);

			pLineToBus=new CXScdDrawLine_ToBus();
			pLineToBus->m_pBeginObj = pSclCtrlsGsOut;
		
			pLine->pLineToBus=pLineToBus;
			//AddNewChild(pLineToBus);

			pLineBusTo=new CXScdDrawLine_ToBus();
			pLineBusTo->m_pEndObj   = m_pXDrawDataRef;
			pLineBusTo->m_pEndElement=this;
			pLine->pBusToLine=pLineBusTo;

			//AddNewChild(pLineBusTo);
		//	pLineToBus
		}
	}
}

