//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawViewThumbnail.cpp  CXScdDrawViewThumbnail


#include "stdafx.h"
#include "XScdDrawViewThumbnail.h"
int g_VerticalLocate_Bus=0;
int g_VerticalLocate_GooseBus=0;
int g_VerticalLocate_SmvBus=0;



CXScdDrawViewThumbnail::CXScdDrawViewThumbnail()
{
	//初始化属性
	m_listGroups=NULL;

	//初始化成员变量
}

CXScdDrawViewThumbnail::~CXScdDrawViewThumbnail()
{
}

void CXScdDrawViewThumbnail::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXScdDrawViewBase::Draw(pDC,fZoomRatio,ptOffset);
}

void CXScdDrawViewThumbnail::Pick(const CPoint &point, CExBaseList &oList)
{

}

CXDrawElement* CXScdDrawViewThumbnail::XCreateChildElement(UINT nClassID)
{
	if (SCLIECCLASSID_IED == nClassID)
	{
		return new CXScdDrawIedThumbnail();
	}

	return NULL;
}

DWORD CXScdDrawViewThumbnail::XCreateElement(CExBaseObject *pData, CWnd *pParentWnd)
{
	UINT nClassID = pData->GetClassID();
	//ASSERT (nClassID == CFGCLASSID_CIECCFGDATASMNGR);

	//CreateElements
	InitXScdDrawViewThumbnail((CSclStation*)pData, pParentWnd);

	////CalLayout
	CSize szView(0,0);
	szView = CalLayout(szView);

	////调整位置
	//Layout(CPoint(0, 0));

	return XCREATE_SUCC;
}

void CXScdDrawViewThumbnail::InitXScdDrawViewThumbnail(CSclStation *pSclStation, CWnd *pParentWnd)
{
	POS pos=pSclStation->GetHeadPosition();
	CSclIed *pIed=NULL;
	CExBaseObject *pTemp=NULL;

	//m_pIedList_ProtMeas=new CXScdIedGroupThumb();
	//m_pIedList_MergIntel=new CXScdIedGroupThumb();

       m_pIedList_ProtMeas=new CXScdIedGroupThumb();
	   m_pIedList_MergIntel=new CXScdIedGroupThumb();

	m_listIedGroup.AddTail(m_pIedList_ProtMeas);
	m_listIedGroup.AddTail(m_pIedList_MergIntel);
	m_oScdDrawLines.DeleteAll();
	m_oScdBriefDrawLines.DeleteAll();

	while (pos!=NULL)
	{
		pTemp = pSclStation->GetNext(pos);
		pIed=(CSclIed*)pTemp;

		if (pIed->GetClassID()==CFGCLASSID_CSCLBAY)
		{
			continue;
		}

		CXScdDrawIedThumbnail *pDrawIed_Thumbnail = new CXScdDrawIedThumbnail();
		AddNewChild(pDrawIed_Thumbnail);
		pDrawIed_Thumbnail->m_strName=pIed->m_strName;
		pDrawIed_Thumbnail->m_strID=pIed->m_strID;
		pDrawIed_Thumbnail->SetRefIed(pIed);
		
		//if(pTempIed->m_strIedType==_T("合智一体装置")||pTempIed->m_strIedType==_T("合并单元")||pTempIed->m_strIedType==_T("智能终端"))
		if(pIed->IsIed_RPIT_MU())
		{
			m_pIedList_MergIntel->AddTail(pDrawIed_Thumbnail);
			pDrawIed_Thumbnail->SetSymbel(IEDTHUMBNAILTYPE_MUCTRL);
		}
		//	if (pTempIed->m_strIedType==_T("保护测控装置")||pTempIed->m_strIedType==_T("保护装置")||pTempIed->m_strIedType==_T("测控装置"))
		else /*if (pIed->m_strIedTypeLabel==_T("ProcMeas")
			||pIed->m_strIedTypeLabel==_T("Proc")
			||pIed->m_strIedTypeLabel==_T("Meas"))*/
		{
			m_pIedList_ProtMeas->AddTail(pDrawIed_Thumbnail);
			pDrawIed_Thumbnail->SetSymbel(IEDTHUMBNAILTYPE_PROCMEAS);
		}
		
		pDrawIed_Thumbnail->XCreateCtrl(pIed,pParentWnd);
		//pDrawIed_Thumbnail->GetCount_RefIeds();

		//pDrawIed_Thumbnail->GetAllKindsLines(m_oScdDrawLines,m_oScdDrawLines_ToBus);
		pDrawIed_Thumbnail->GetAllLines(m_oScdDrawLines);
	}

	//调整连接线
   	InitLinesBeginElement();
	CXScdDrawLine_Vert *pXScdDrawLine_Vert=NULL;

	POS posLine=m_oScdDrawLines.GetHeadPosition();
	while (posLine!=NULL)
	{
		pXScdDrawLine_Vert=(CXScdDrawLine_Vert*)GetNext(posLine);
        m_oScdDrawLines_ToBus.AddTail(pXScdDrawLine_Vert->pLineToBus);
		m_oScdDrawLines_ToBus.AddTail(pXScdDrawLine_Vert->pBusToLine);    


	}




////////////////////////////////////////////////////////////////////////////////////////////////////////////遍历所有的线，统计每个IED中的m_pRefIedsThumbGroups，即与之相关联的IED集合////////////////////////
	POS pos1 = m_oScdDrawLines.GetHeadPosition(); 
	CXScdDrawLineBase *pLine = NULL;
	//CExBaseObject * pBeginObj=NULL;
	//CExBaseObject * pEndObj=NULL;
	CXDrawElement *pBeginElement=NULL;
	CXDrawElement *pEndElement=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;
	CXScdIedGroupThumb *pXScdIedGroupThumbTemp=NULL;


	while (pos1!=NULL)
	{
		pLine = (CXScdDrawLineBase *)m_oScdDrawLines.GetNext(pos1);
		pBeginElement=pLine->m_pBeginElement;
		pEndElement=pLine->m_pEndElement;
		pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail *)pBeginElement->GetParent();
		pDrawIedThumbnail_End=(CXScdDrawIedThumbnail *)pEndElement->GetParent();

		if (pDrawIedThumbnail_Begin->GetSymbel()==pDrawIedThumbnail_End->GetSymbel())
		{
			continue;
		}
    
		if (pDrawIedThumbnail_End!=NULL)
		{
			pDrawIedThumbnail_Begin->nCountRefIeds++;
			pDrawIedThumbnail_Begin->m_pRefLines->AddNewChild(pLine);
			pXScdIedGroupThumbTemp=(CXScdIedGroupThumb*)pDrawIedThumbnail_Begin->m_pRefIedsThumbGroups;
			if (!pXScdIedGroupThumbTemp->IsRefIedThumbInGroup(pDrawIedThumbnail_End))//判断IED是否在某集合中
			{
				pDrawIedThumbnail_Begin->m_pRefIedsThumbGroups->AddNewChild(pDrawIedThumbnail_End);
			}			
			 
		}
		if (pDrawIedThumbnail_Begin!=NULL)
		{
			 pDrawIedThumbnail_End->nCountRefIeds++;
			 pDrawIedThumbnail_End->m_pRefLines->AddNewChild(pLine);
            pXScdIedGroupThumbTemp=(CXScdIedGroupThumb*)pDrawIedThumbnail_End->m_pRefIedsThumbGroups;
			if (!pXScdIedGroupThumbTemp->IsRefIedThumbInGroup(pDrawIedThumbnail_Begin))
			{
				pDrawIedThumbnail_End->m_pRefIedsThumbGroups->AddNewChild(pDrawIedThumbnail_Begin);
			}						 
		}

	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                             


	   //   IndependXScdDrawViewThumbnail();//将所有的IED分成保护测控与合并单元智能终端两种，分别放在	m_pIedList_ProtMeas，m_pIedList_MergIntel中，

	//      SplitIedList_ProtMeas();//生成第二行保护测控集合在	m_pIedList_ProtMeas2中
	// 	m_pIedList_ProtMeas=  ReAdjustIedList_ProtMeas(m_pIedList_ProtMeas,m_pIedList_ProtMeas2);//重新调整第一行的保护测控设备，将第一行保护测控集合中包含第二行的保护测控设备移除
    


	
  //  CXScdIedGroupThumb *pXScdIedGroupThumb=m_pIedList_ProtMeas->SeqenGroupThumb();//初次调整，从大到小排序
     
// pXScdIedGroupThumb=pXScdIedGroupThumb->ReOrderGroupThumb();//二次调整，最大在中间，外两边一次排序

	// m_pIedList_ProtMeas=pXScdIedGroupThumb;    







}


void CXScdDrawViewThumbnail::IndependXScdDrawViewThumbnail()
{


	//以关联度最大的IED为例进行分组

	//首先获得关联度最大的保护测控
	POS pos = m_pIedList_ProtMeas->GetHeadPosition(); 
	CXScdDrawIedThumbnail *pDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_MaxRefieds=NULL;
	int nCountRefIeds_Max=0;
	while (pos!=NULL)
	{
		pDrawIedThumbnail=(CXScdDrawIedThumbnail *)m_pIedList_ProtMeas->GetNext(pos);

		if (nCountRefIeds_Max<pDrawIedThumbnail->nCountRefIeds)
		{
			nCountRefIeds_Max=pDrawIedThumbnail->nCountRefIeds;
			pDrawIedThumbnail_MaxRefieds=pDrawIedThumbnail;
		}
	}
    CXScdIedGroupThumb *pIedList_ProtMeas=new CXScdIedGroupThumb();
	CXScdIedGroupThumb *pIedList_MergIntel=new CXScdIedGroupThumb();
	m_listGroups=new CExBaseList();
   m_listGroups->AddTail(pIedList_ProtMeas);
   m_listGroups->AddTail(pIedList_MergIntel);

    FilterIedThumbnail(pDrawIedThumbnail_MaxRefieds,pIedList_ProtMeas,pIedList_MergIntel);
	m_pIedList_ProtMeas=pIedList_ProtMeas;
	m_pIedList_MergIntel=pIedList_MergIntel;
}

void CXScdDrawViewThumbnail::FilterIedThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail,CXScdIedGroupThumb *m_pIedList_ProtMeas,CXScdIedGroupThumb *m_pIedList_MergIntel)
{
	CExBaseList *pRefIedsThumbGroups=pXScdDrawIedThumbnail->m_pRefIedsThumbGroups;
	CXScdDrawIedThumbnail *pTempXScdDrawIedThumbnail=NULL;
	POS pos=pRefIedsThumbGroups->GetHeadPosition();
	while (pos!=NULL)
	{
		pTempXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pRefIedsThumbGroups->GetNext(pos);
		if(pXScdDrawIedThumbnail->GetSymbel()==pTempXScdDrawIedThumbnail->GetSymbel())
		{
			continue;
		}
		if (m_pIedList_ProtMeas->IsRefIedThumbInGroup(pTempXScdDrawIedThumbnail)||m_pIedList_MergIntel->IsRefIedThumbInGroup(pTempXScdDrawIedThumbnail))
		{
			continue;
		}
		if (pTempXScdDrawIedThumbnail->GetSymbel()==IEDTHUMBNAILTYPE_MUCTRL)//保护测控
		{
			m_pIedList_MergIntel->AddTail(pTempXScdDrawIedThumbnail);
		}
		else if (pTempXScdDrawIedThumbnail->GetSymbel()==IEDTHUMBNAILTYPE_PROCMEAS)
		{
			m_pIedList_ProtMeas->AddTail(pTempXScdDrawIedThumbnail);
		}
       FilterIedThumbnail(pTempXScdDrawIedThumbnail,m_pIedList_ProtMeas,m_pIedList_MergIntel);
	}
}

void CXScdDrawViewThumbnail::SplitIedList_ProtMeas()
{
	POS pos=m_pIedList_ProtMeas->GetHeadPosition();
	CXScdDrawIedThumbnail *pXScdDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail *pXScdDrawRefIedThumbnail=NULL;
	m_pIedList_ProtMeas2=new CXScdIedGroupThumb();
	int nCountRefIeds=0;
	CExBaseList *pExBaseList=NULL;
   while (pos!=NULL)
   {
	   pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)m_pIedList_ProtMeas->GetNext(pos);
       pExBaseList=pXScdDrawIedThumbnail->m_pRefIedsThumbGroups;
	   if (pXScdDrawIedThumbnail->nCountRefIeds>5)
	   {
		   continue;
	   }
	   
	   POS pos1=pExBaseList->GetHeadPosition();	 
        nCountRefIeds=0;
	   
	   while (pos1!=NULL)
	   {
		   pXScdDrawRefIedThumbnail=(CXScdDrawIedThumbnail*)pExBaseList->GetNext(pos1);
		   if(!m_pIedList_MergIntel->IsRefIedThumbInGroup(pXScdDrawRefIedThumbnail))
		   {
			   continue;
		   }
		if (! IsCloselyIedsThumbnail(pXScdDrawIedThumbnail,pXScdDrawRefIedThumbnail))
		{
			continue;
		}
		if (m_pIedList_ProtMeas2->IsRefIedThumbInGroup(pXScdDrawIedThumbnail))
		{
			continue;
		}
		pXScdDrawIedThumbnail->m_pCloseIedThumb=pXScdDrawRefIedThumbnail;
		pXScdDrawRefIedThumbnail->m_pCloseIedThumb=pXScdDrawIedThumbnail;
		m_pIedList_ProtMeas2->AddTail(pXScdDrawIedThumbnail);   	
		pXScdDrawIedThumbnail->SetSymbel(IEDTHUMBNAILTYPE_PROCMEAS2);
     
	   }
   }
}

BOOL CXScdDrawViewThumbnail::IsCloselyIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2)
{
	POS pos = m_oScdDrawLines.GetHeadPosition(); 
	CXScdDrawLineBase *pLine = NULL;
	CXDrawElement *pBeginElement=NULL;
	CXDrawElement *pEndElement=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;
	BOOL b1=FALSE;
	BOOL b2=FALSE;
	

	while (pos!=NULL)
	{
		pLine=(CXScdDrawLineBase* )m_oScdDrawLines.GetNext(pos);
		if (pLine==NULL)
		{
			continue;
		}
		pBeginElement=pLine->m_pBeginElement;
		pEndElement=pLine->m_pEndElement;
		pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail *)pBeginElement->GetParent();
		pDrawIedThumbnail_End=(CXScdDrawIedThumbnail *)pEndElement->GetParent();
		if (pXScdDrawIedThumbnail1==pDrawIedThumbnail_Begin&&pXScdDrawIedThumbnail2==pDrawIedThumbnail_End)
		{
			b1=TRUE;
		}
		if (pXScdDrawIedThumbnail1==pDrawIedThumbnail_End&&pXScdDrawIedThumbnail2==pDrawIedThumbnail_Begin)
		{
			b2=TRUE;
		}
	}

	if (b1&&b2)
	{
		return TRUE;
	}
	return FALSE;
}

 CXScdIedGroupThumb* CXScdDrawViewThumbnail::ReAdjustIedList_ProtMeas(CXScdIedGroupThumb *pIedList_ProtMeas,CXScdIedGroupThumb *pIedList_ProtMeas2)
{
	POS pos=pIedList_ProtMeas->GetHeadPosition();
	CXScdDrawIedThumbnail *pXScdDrawIedThumbnailTemp=NULL;
	CXScdIedGroupThumb *pXScdIedGroupThumb=new CXScdIedGroupThumb();

	while (pos!=NULL)
	{
		pXScdDrawIedThumbnailTemp=(CXScdDrawIedThumbnail*)pIedList_ProtMeas->GetNext(pos);
		if (pIedList_ProtMeas2->IsRefIedThumbInGroup(pXScdDrawIedThumbnailTemp))
		{
			continue;
		}
		pXScdIedGroupThumb->AddTail(pXScdDrawIedThumbnailTemp);
	}
    return pXScdIedGroupThumb;

}


//void CXScdDrawViewThumbnail::SetIedsArea(CXScdDrawIedThumbnail *pDrawIed_Thumbnail )
//{
//	if (pDrawIed_Thumbnail==NULL)
//	{
//		continue;
//	}
//	if(pDrawIed_Thumbnail->GetSymbel())//智能终端合并单元
//	{
//
//	}
//	else//保护测控装置
//	{
//
//
//
//	}
//
//
//}


CSize CXScdDrawViewThumbnail::CalLayout(CSize &szDraw)
{
	CSize szEntire(0,0);//计算所有的IED的Size
	CSize szIed(0,0);
	POS pos=GetHeadPosition(); 
	CXScdDrawIedThumbnail *pIedThumbnail=NULL;
	CSclIed *pTempIed=NULL;

	while (pos!=NULL)
	{
		pIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
		szIed=pIedThumbnail->CalLayout(szIed);
	}

	szEntire.cy=max(szEntire.cy,szIed.cy);
	szEntire.cx+=szIed.cx;

	//计算总的Size
	szDraw = Layout(CPoint(0, 0));

	return szDraw;
}

void CXScdDrawViewThumbnail::InitLinesBeginElement()
{
	POS pos = m_oScdDrawLines.GetHeadPosition(); 
///	CXScdDrawLineBase *pLine = NULL;
	CXScdDrawLine_Vert	*pLine=NULL;
	CXScdDrawLine_ToBus *pLineToBus=NULL;

	while (pos!=NULL)
	{
		pLine = (CXScdDrawLine_Vert *)m_oScdDrawLines.GetNext(pos);
		pLine->m_pBeginElement = QueryByXDrawDataRef(pLine->m_pBeginObj);
		pLineToBus=pLine->pLineToBus;
		pLineToBus->m_pBeginElement=pLine->m_pBeginElement ;
	}

	//pos=m_oScdDrawLines_ToBus.GetHeadPosition();
	//while (pos!=NULL)
	//{
	//	pLine = (CXScdDrawLineBase *)m_oScdDrawLines_ToBus.GetNext(pos);
	//	if (pLine->m_pBeginObj==NULL)
	//	{
	//		continue;
	//	}
	//	pLine->m_pBeginElement = QueryByXDrawDataRef(pLine->m_pBeginObj);

	//}
}

void CXScdDrawViewThumbnail::LayoutLines()
{
	POS pos = m_oScdDrawLines.GetHeadPosition(); 
	CXScdDrawLineBase *pLine = NULL;

	CXDrawElement *pElement=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail=NULL;
	CExBaseObject *pSclCtrls=NULL;
	CXScdDrawCtrl_ThumbBase *pXScdDrawCtrl=NULL;



	while (pos!=NULL)
	{
		pLine = (CXScdDrawLineBase *)m_oScdDrawLines.GetNext(pos);

		if (pLine->GetClassID()==XSCDDRAW_LINE_GOOSEBUS||pLine->GetClassID()==XSCDDRAW_LINE_SVBUS)
		{
	      
			continue;
		}		

		if((pLine->m_pBeginObj!=NULL)&&(pLine->m_pEndObj!=NULL))
		{
			pElement=(CXDrawElement*)pLine->m_pBeginElement;
		}

		pXScdDrawCtrl=(  CXScdDrawCtrl_ThumbBase *)pElement;
		pSclCtrls=pXScdDrawCtrl->m_pSclCtrls;


		if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_OUT)
		{
			g_VerticalLocate_Bus=g_VerticalLocate_GooseBus;
		}
		else if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_SMV_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_SMV_OUT)
		{
			g_VerticalLocate_Bus=g_VerticalLocate_SmvBus;
		}


		pLine->InitLinePos();
	}


	//CXDrawElement *pElement=NULL;
	//CXScdDrawIedThumbnail *pDrawIedThumbnail=NULL;
	//CExBaseObject *pSclCtrls=NULL;
	//CXScdDrawCtrl_ThumbBase *pXScdDrawCtrl=NULL;

	//while(pos!=NULL)
	//{
	//	pLine = (CXScdDrawLineBase *)m_oScdDrawLines_ToBus.GetNext(pos);

	//	//判断是SV线还是GOOSE线，调整母线的高度




	//	pLine->InitToBusLinePos();

	//}


}


CSize CXScdDrawViewThumbnail::Layout(CPoint &ptTopLeft)
{
	CSize szMergIntel, szProcMeas;
	
	m_pIedList_ProtMeas->GetSize(szProcMeas,GETSIZE_MODE_XADD_YMAX);
	m_pIedList_MergIntel->GetSize(szMergIntel,GETSIZE_MODE_XADD_YMAX);
	

	ptTopLeft.x=XSCDDRAW_ELEMENT_MARGIN;
	ptTopLeft.y=XSCDDRAW_ELEMENT_MARGIN;

	//szMain=m_pIedList_ProtMeas->LayoutIedsGroupThumb(ptTopLeft,m_pIedList_MergIntel);//将第一行保护测控设备和第二行合并单元、智能终端一同布局，参数为合并单元、智能终端集合

//	保护、测控
	szProcMeas=m_pIedList_ProtMeas->Layout(ptTopLeft);

//	合并单元、智能终端
	ptTopLeft.y += szProcMeas.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
     szMergIntel = m_pIedList_MergIntel->Layout(ptTopLeft);


   
	//szMergIntel = m_pIedList_MergIntel->IedGroupThumb_Layout(ptTopLeft,m_pIedList_ProtMeas);
      //szMain=m_pIedList_ProtMeas->IedGroupThumb_Layout(ptTopLeft,m_pIedList_ProtMeas,m_pIedList_MergIntel);

	ptTopLeft.y += szMergIntel.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
	// ptTopLeft.y += szMain.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
   


       

	m_nHeight = ptTopLeft.y;

	m_nWidth  = max(szProcMeas.cx,szMergIntel.cx) + XSCDDRAW_THUMBNAIL_GAP_IED_X*2;
	//m_nWidth  = szMain.cx + XSCDDRAW_THUMBNAIL_GAP_IED_X*2;
	m_nHeight +=szProcMeas.cy + XSCDDRAW_ELEMENT_MARGIN;



	CXScdDrawLine_GooseBus *pBusLine_GOOSE=new CXScdDrawLine_GooseBus();
	CXScdDrawLine_SvBus *pBusLine_SMV=new CXScdDrawLine_SvBus();
	m_oScdDrawLines_ToBus.AddTail(pBusLine_GOOSE);
	m_oScdDrawLines_ToBus.AddTail(pBusLine_SMV);

	pBusLine_GOOSE->m_ptBegin.x=m_pIedList_ProtMeas->m_ptTopLeft.x;
	pBusLine_GOOSE->m_ptBegin.y=m_pIedList_ProtMeas->m_ptTopLeft.y+m_pIedList_ProtMeas->m_nHeight+(m_pIedList_MergIntel->m_ptTopLeft.y-m_pIedList_ProtMeas->m_ptTopLeft.y-m_pIedList_ProtMeas->m_nHeight)/3;

	pBusLine_GOOSE->m_ptEnd.x= pBusLine_GOOSE->m_ptBegin.x+max(m_pIedList_ProtMeas->m_nWidth,m_pIedList_MergIntel->m_nWidth);
	pBusLine_GOOSE->m_ptEnd.y=  pBusLine_GOOSE->m_ptBegin.y;	    

	pBusLine_SMV->m_ptBegin.x=m_pIedList_ProtMeas->m_ptTopLeft.x;
	pBusLine_SMV->m_ptBegin.y=m_pIedList_ProtMeas->m_ptTopLeft.y+m_pIedList_ProtMeas->m_nHeight+(m_pIedList_MergIntel->m_ptTopLeft.y-m_pIedList_ProtMeas->m_ptTopLeft.y-m_pIedList_ProtMeas->m_nHeight)*2/3;
	pBusLine_SMV->m_ptEnd.x=pBusLine_SMV->m_ptBegin.x+max(m_pIedList_ProtMeas->m_nWidth,m_pIedList_MergIntel->m_nWidth);
	pBusLine_SMV->m_ptEnd.y=pBusLine_SMV->m_ptBegin.y;
	g_VerticalLocate_GooseBus=pBusLine_GOOSE->m_ptBegin.y;
	g_VerticalLocate_SmvBus=pBusLine_SMV->m_ptBegin.y;

	LayoutLines();








	//pXScdDrawLineBase->m_ptBegin.x=m_pIedList_ProtMeas->m_ptTopLeft.x;
	//pXScdDrawLineBase->m_ptBegin.y=m_pIedList_ProtMeas->m_ptTopLeft.y+m_pIedList_ProtMeas->m_nHeight+(m_pIedList_MergIntel->m_ptTopLeft.y-m_pIedList_ProtMeas->m_ptTopLeft.y-m_pIedList_ProtMeas->m_nHeight)/3;

	//pXScdDrawLineBase->m_ptEnd.x= pXScdDrawLineBase->m_ptBegin.x+max(m_pIedList_ProtMeas->m_nWidth,m_pIedList_MergIntel->m_nWidth);
	//pXScdDrawLineBase->m_ptEnd.y=  pXScdDrawLineBase->m_ptBegin.y;	    

	//pXScdDrawLineBase->m_ptBegin.x=m_pIedList_ProtMeas->m_ptTopLeft.x;
	//pXScdDrawLineBase->m_ptBegin.y=m_pIedList_ProtMeas->m_ptTopLeft.y+m_pIedList_ProtMeas->m_nHeight+(m_pIedList_MergIntel->m_ptTopLeft.y-m_pIedList_ProtMeas->m_ptTopLeft.y-m_pIedList_ProtMeas->m_nHeight)*2/3;
	//pXScdDrawLineBase->m_ptEnd.x=pXScdDrawLineBase->m_ptBegin.x+max(m_pIedList_ProtMeas->m_nWidth,m_pIedList_MergIntel->m_nWidth);
	//pXScdDrawLineBase->m_ptEnd.y=pXScdDrawLineBase->m_ptBegin.y;



	//POS posLine=m_oScdDrawLines.GetHeadPosition();
	//CXScdDrawLineBase *pXScdDrawLineBase=NULL;
	//CXDrawElement *pBeginElement=NULL;
	//CXDrawElement *pEndElement=NULL;
	//CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	//CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;
	//CExBaseObject *pSclCtrls=NULL;
	//CXScdDrawCtrl_ThumbBase *pXScdDrawCtrl=NULL;
	//while (posLine!=NULL)
	//{

	//	pXScdDrawLineBase=(CXScdDrawLineBase*)m_oScdDrawLines.GetNext(posLine);


	//	//if (pXScdDrawLineBase->GetClassID()==XSCDDRAW_LINE_GOOSEBUS)
	//	//{
	//	//	
	//	//	continue;
	//	//}
	//	//if (pXScdDrawLineBase->GetClassID()==XSCDDRAW_LINE_SVBUS)
	//	//{
	//	//	
	//	//	continue;
	//	//}

 //     pBeginElement=pXScdDrawLineBase->m_pBeginElement;
	//  pEndElement=pXScdDrawLineBase->m_pEndElement;
 //     pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail*)pBeginElement->GetParent();
	//  pDrawIedThumbnail_End=(CXScdDrawIedThumbnail*)pEndElement->GetParent();
	//  if (pDrawIedThumbnail_Begin->GetSymbel()==pDrawIedThumbnail_End->GetSymbel())
	//  {
	//	  continue;
	//  }
	//	CXScdDrawLine_Vert*pLine1=new CXScdDrawLine_Vert();
	//	CXScdDrawLine_Vert*pLine2=new CXScdDrawLine_Vert();


	//	if (pXScdDrawLineBase->m_ptBegin.y<pXScdDrawLineBase->m_ptEnd.y)
	//	{      
	//		pLine1->m_pBeginElement=pBeginElement;
	//     	pLine1->m_ptBegin=pXScdDrawLineBase->m_ptBegin;
	//	    pLine1->m_ptEnd.x=  pLine1->m_ptBegin.x;
 //         pXScdDrawCtrl=(  CXScdDrawCtrl_ThumbBase *)pBeginElement;
	//	  pSclCtrls=pXScdDrawCtrl->m_pSclCtrls;
	//		if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_OUT)
	//		{
	//			pLine1->m_ptEnd.y=  pLine1->m_ptBegin.y+100;
	//		}
	//		else
 //               pLine1->m_ptEnd.y=  pLine1->m_ptBegin.y+200;
	//		

	//		pLine2->m_pEndElement=pEndElement;
	//		pLine2->m_ptEnd=pXScdDrawLineBase->m_ptEnd;
	//		pLine2->m_ptBegin.x=  pLine2->m_ptEnd.x;
	//		pXScdDrawCtrl=(  CXScdDrawCtrl_ThumbBase *)pEndElement;
	//		pSclCtrls=pXScdDrawCtrl->m_pSclCtrls;
	//		if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_OUT)
	//		{
	//			pLine2->m_ptBegin.y=  pLine2->m_ptEnd.y-200;
	//		}
	//		else
 //              pLine2->m_ptBegin.y=  pLine2->m_ptEnd.y-100;
	//		
	//	}
	//	else
	//	{
 //             pLine1->m_pEndElement=pEndElement;
	//		  pLine1->m_ptEnd=pXScdDrawLineBase->m_ptEnd;
 //              pLine1->m_ptBegin.x=pLine1->m_ptEnd.x;
	//		   pXScdDrawCtrl=(  CXScdDrawCtrl_ThumbBase *)pEndElement;
	//		   pSclCtrls=pXScdDrawCtrl->m_pSclCtrls;
	//		   if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_OUT)
	//		   {
	//			   pLine1->m_ptBegin.y=pLine1->m_ptEnd.y+100;
	//		   }
	//		   else
 //                   pLine1->m_ptBegin.y=pLine1->m_ptEnd.y+200;
	//		

	//		   pLine2->m_pBeginElement=pBeginElement;
	//		   pLine2->m_ptBegin=pXScdDrawLineBase->m_ptBegin;
	//		   pLine2->m_ptEnd.x=pLine2->m_ptBegin.x;
	//		   pXScdDrawCtrl=(  CXScdDrawCtrl_ThumbBase *)pBeginElement;
	//		   pSclCtrls=pXScdDrawCtrl->m_pSclCtrls;
 //                if (pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_IN||pSclCtrls->GetClassID()==SCLIECCLASSID_CTRLS_GS_OUT)
	//			 { 
	//				 pLine2->m_ptEnd.y=pLine2->m_ptBegin.y-200;
	//			 }
	//			 else
 //                      pLine2->m_ptEnd.y=pLine2->m_ptBegin.y-100;
	//		  

	//	}
	//	m_oScdBriefDrawLines.AddTail(pLine1);
	//	m_oScdBriefDrawLines.AddTail(pLine2);



		
	//}

	return CSize(m_nWidth, m_nHeight);
}


//CSize CXScdDrawViewThumbnail::Layout(CPoint &ptTopLeft)
//{
//	CSize szMergIntel, szProcMeas,szProcMeas2;
//	CSize szMain;
//	m_pIedList_ProtMeas->GetSize(szProcMeas,GETSIZE_MODE_XADD_YMAX);
//	m_pIedList_MergIntel->GetSize(szMergIntel,GETSIZE_MODE_XADD_YMAX);
//	m_pIedList_ProtMeas2->GetSize(szProcMeas,GETSIZE_MODE_XADD_YMAX);
//
//	ptTopLeft.x=XSCDDRAW_ELEMENT_MARGIN;
//	ptTopLeft.y=XSCDDRAW_ELEMENT_MARGIN;
//
//	szMain=m_pIedList_ProtMeas->LayoutIedsGroupThumb(ptTopLeft,m_pIedList_MergIntel);//将第一行保护测控设备和第二行合并单元、智能终端一同布局，参数为合并单元、智能终端集合
//
//	//	保护、测控
//	//	szProcMeas=m_pIedList_ProtMeas->Layout(ptTopLeft);
//
//	//合并单元、智能终端
//	//	ptTopLeft.y += szProcMeas.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
//	//  szMergIntel = m_pIedList_MergIntel->Layout(ptTopLeft);
//
//
//
//	//szMergIntel = m_pIedList_MergIntel->IedGroupThumb_Layout(ptTopLeft,m_pIedList_ProtMeas);
//	//szMain=m_pIedList_ProtMeas->IedGroupThumb_Layout(ptTopLeft,m_pIedList_ProtMeas,m_pIedList_MergIntel);
//
//	//ptTopLeft.y += szMergIntel.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
//	ptTopLeft.y += szMain.cy + XSCDDRAW_THUMBNAIL_GAP_IED_Y;
//	szProcMeas2=m_pIedList_ProtMeas2->IedGroupThumb_PM2Layout(ptTopLeft,m_pIedList_MergIntel);//对最下面一行的保护测控设备进行布局，参数为第二行的合并单元智能终端集合
//
//
//
//
//	m_nHeight = ptTopLeft.y;
//
//	m_nWidth  = max(szProcMeas2.cx, szMain.cx) + XSCDDRAW_THUMBNAIL_GAP_IED_X*2;
//	//m_nWidth  = szMain.cx + XSCDDRAW_THUMBNAIL_GAP_IED_X*2;
//	m_nHeight +=szProcMeas2.cy + XSCDDRAW_ELEMENT_MARGIN;
//
//	LayoutLines();
//
//	return CSize(m_nWidth, m_nHeight);
//}