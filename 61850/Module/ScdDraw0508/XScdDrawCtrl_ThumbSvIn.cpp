//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbSvIn.cpp  CXScdDrawCtrl_ThumbSvIn


#include "stdafx.h"
#include "XScdDrawCtrl_ThumbSvIn.h"
#include "XScdDrawLine_Ctrls.h"


CXScdDrawCtrl_ThumbSvIn::CXScdDrawCtrl_ThumbSvIn()
{
	//初始化属性

	//初始化成员变量
	m_strName = _T("SVIN");
}

CXScdDrawCtrl_ThumbSvIn::~CXScdDrawCtrl_ThumbSvIn()
{
}

void CXScdDrawCtrl_ThumbSvIn::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawCtrl_ThumbBase::Draw(pDC, fZoomRatio, ptOffset);
}

void CXScdDrawCtrl_ThumbSvIn::CreateCtrlLines()
{
	ASSERT (m_pXDrawDataRef != NULL);

	CSclCtrlsSmvIn  *pSclCtrlsSmvIn  = (CSclCtrlsSmvIn*)m_pXDrawDataRef;
	CSclCtrlSmvIn   *pSclCtrlSmvIn   = NULL;
	CSclCtrlsSmvOut *pSclCtrlsSmvOut = NULL;
	CSclCtrlSmvOut  *pSclCtrlSmvOut  = NULL;

	CSclIed *pSclIedByCtrlsSmvIn=(CSclIed *)pSclCtrlsSmvIn->GetParent();

	//if(pSclIedByCtrlsSmvIn->m_strID!=_T("PB5011A"))
	//{
	//	return;
	//}


	CSclStation *pSclStation = (CSclStation*)m_pXDrawDataRef->GetAncestor(SCLIECCLASSID_STATION);
	ASSERT (pSclStation != NULL);

	if (pSclStation == NULL)
	{
		return;
	}

	POS pos = pSclCtrlsSmvIn->GetHeadPosition();
	CXScdDrawLine_Ctrls *pLine = NULL;
	CXScdDrawLine_ToBus *pLineToBus=NULL;
	CXScdDrawLine_ToBus *pLineBusTo=NULL;


	while (pos != NULL)
	{
		pSclCtrlSmvIn = (CSclCtrlSmvIn *)pSclCtrlsSmvOut->GetNext(pos);
		pSclCtrlSmvOut = pSclStation->FindCrl_SmvOutput(pSclCtrlSmvIn->m_strSVID);

		if (pSclCtrlSmvOut == NULL)
		{
			continue;
		}

		pSclCtrlsSmvOut = (CSclCtrlsSmvOut *)pSclCtrlSmvOut->GetParent();
		CSclIed *pSclIedByCtrlsSmvOut=(CSclIed *)pSclCtrlsSmvOut->GetParent();
		if(pSclIedByCtrlsSmvIn->m_strIedTypeLabel==pSclIedByCtrlsSmvOut->m_strIedTypeLabel)
		{
			continue;
		}



		pLine = (CXScdDrawLine_Ctrls*)FindLineByBeginRef(pSclCtrlsSmvOut);

		if (pLine == NULL)
		{
			pLine = new CXScdDrawLine_Ctrls();
			pLine->m_pBeginObj = pSclCtrlsSmvOut;
			pLine->m_pEndObj   = m_pXDrawDataRef;
			pLine->m_pEndElement = this;
			
			AddNewChild(pLine);


			pLineToBus=new CXScdDrawLine_ToBus();
			pLineToBus->m_pBeginObj = pSclCtrlsSmvOut;
			pLine->pLineToBus=pLineToBus;
		
		//	AddNewChild(pLineToBus);

			pLineBusTo=new CXScdDrawLine_ToBus();
			pLineBusTo->m_pEndObj   = m_pXDrawDataRef;
			pLineBusTo->m_pEndElement=this;
			pLine->pBusToLine=pLineBusTo;
		//	AddNewChild(pLineBusTo);
		}
	}
}