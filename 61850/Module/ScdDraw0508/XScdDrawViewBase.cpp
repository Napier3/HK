//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawViewBase.cpp  CXScdDrawViewBase


#include "stdafx.h"
#include "XScdDrawViewBase.h"

//////////////////////////////////////////////////////////////////////////
//CXScdIedGroup
CXScdIedGroup::CXScdIedGroup()
{

}

CXScdIedGroup::~CXScdIedGroup()
{
	RemoveAll();
}

CSize CXScdIedGroup::Layout(CPoint &ptTopLeft)
{
	m_ptTopLeft = ptTopLeft;
	POS pos = GetHeadPosition();
	CXScdDrawViewBase *pXDrawElement = NULL;
	CPoint pt;
	pt = ptTopLeft;
	CSize szElement;
	m_nWidth = 0;
	m_nHeight = 0;

	//CExBaseListXGridCtrlBase *pIedNameTemp=NULL;
	/*	pIedNameTemp->Create()*/
	//HDC hdc=GetDC(HWND);
	//CPaintDC dc(this);

	while (pos != NULL)
	{
		pXDrawElement = (CXScdDrawViewBase *)GetNext(pos);
		//TextOut()

		szElement = pXDrawElement->Layout(pt);

		pt.y += szElement.cy;
		m_nHeight += szElement.cy;
		//pt.y += XSCDDRAW_VIEW_GAP;
		pt.y =pt.y+ XSCDDRAW_VIEW_GAP+20;
		m_nWidth = max(m_nWidth, szElement.cx);
	}	

	return CSize(m_nWidth, m_nHeight);
}


//////////////////////////////////////////////////////////////////////////
//CXScdIedGroupThumb
CXScdIedGroupThumb::CXScdIedGroupThumb()
{
	

}

CXScdIedGroupThumb::~CXScdIedGroupThumb()
{

}
//CXScdDrawIedThumbnail CXScdIedGroupThumb::GetRefDrawIed_Thumbnail(CExBaseObject *pObj)
//{
//		CXScdDrawIedThumbnail *pXScdDrawIedThumbnail =NULL;
//	POS pos=GetHeadPosition();
//	while (pos!=NULL)
//	{
//		pXScdDrawIedThumbnail =(CXScdDrawIedThumbnail*)GetNext(pos);
//	}
//	return pXScdDrawIedThumbnail;
//
//}

CSize CXScdIedGroupThumb::Layout(CPoint &ptTopLeft)
{
	m_ptTopLeft = ptTopLeft;
	POS pos = GetHeadPosition();
	CXScdDrawViewBase *pXDrawElement = NULL;
	CPoint pt;
	pt = ptTopLeft;
	CSize szElement;
	m_nWidth = 0;
	m_nHeight = 0;

	while (pos != NULL)
	{
		pXDrawElement = (CXScdDrawViewBase *)GetNext(pos);
		szElement = pXDrawElement->Layout(pt);
		m_nHeight = max(m_nHeight, szElement.cy);

		pt.x += szElement.cx+XSCDDRAW_THUMBNAIL_GAP_IED_X;
		m_nWidth +=szElement.cx+XSCDDRAW_THUMBNAIL_GAP_IED_X;		
	}	

    //SwapPosition(_T("PL2252B"),_T("PM5091A"));
	   // SwapPosition(_T("PL2266B"),_T("PT5003A"));
		  //  SwapPosition(_T("PL2258B"),_T("PM5092B"));
			 // SwapPosition(_T("PL2258B"),_T("CG5008"));

			 // SwapPosition(_T("PL2251B"),_T("PM2291A"));

			 // SwapPosition(_T("PL2257B"),_T("CG5007"));

			 // SwapPosition(_T("PL2265B"),_T("CG5006"));
			 // SwapPosition(_T("PE2212B"),_T("PM5092A"));
	//SwapPosition(_T("CG2206"),_T("CG5008"));

	//		  	 
 //  CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1=GetIedThumbnailByIedId(_T("PT5003B"));
 //  MoveBackward(pXScdDrawIedThumbnail1);

	


	return CSize(m_nWidth, m_nHeight);
}

void CXScdIedGroupThumb::RightRemovd(int pRange)
{
	POS pos=GetHeadPosition();
	CXScdDrawIedThumbnail* pXScdDrawIedThumbnail=NULL;
	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
		pXScdDrawIedThumbnail->m_ptTopLeft.x+=pRange;
		pXScdDrawIedThumbnail->RightRemovd(pRange);
	}
}

void CXScdIedGroupThumb::LeftRemovd(int pRange)
{
	POS pos=GetHeadPosition();
	CXScdDrawIedThumbnail* pXScdDrawIedThumbnail=NULL;
	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
		pXScdDrawIedThumbnail->m_ptTopLeft.x-=pRange;
		pXScdDrawIedThumbnail->LeftRemovd(pRange);
	}
}


void CXScdIedGroupThumb::SwapPosition(CString strIedId1,CString strIedId2)
{
	CPoint pt1,pt2;
	POS pos = GetHeadPosition();
	CXScdDrawIedThumbnail *pXScdDrawIedThumbnail=NULL;
	CSclIed *pSclIed=NULL;
	while (pos != NULL)
	{
		pXScdDrawIedThumbnail = (CXScdDrawIedThumbnail *)GetNext(pos);
		pSclIed=pXScdDrawIedThumbnail->GetRefIed();
		if( pSclIed->m_strID==strIedId1)
		{
			pt1=pXScdDrawIedThumbnail->m_ptTopLeft;
		}
		if (pSclIed->m_strID==strIedId2)
		{
			pt2=pXScdDrawIedThumbnail->m_ptTopLeft;
		}
	}	
	pos = GetHeadPosition();
	while (pos != NULL)
	{
		pXScdDrawIedThumbnail = (CXScdDrawIedThumbnail *)GetNext(pos);
		pSclIed=pXScdDrawIedThumbnail->GetRefIed();
		if (pSclIed->m_strID==strIedId1)
		{
			//	pXScdDrawIedThumbnail->m_ptTopLeft=pt2;
			pXScdDrawIedThumbnail->Layout(pt2);

		}
		if (pSclIed->m_strID==strIedId2)
		{
			//pXScdDrawIedThumbnail->m_ptTopLeft=pt1;
			pXScdDrawIedThumbnail->Layout(pt1);
		}
	}	

}

//void SwapPosition(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2)
//{
//	CSclIed *pSclIed1=pXScdDrawIedThumbnail1->GetRefIed();
//	CSclIed *pSclIed2=pXScdDrawIedThumbnail2->GetRefIed();
//	SwapPosition(pSclIed1->m_strID,pSclIed2->m_strID);
//
//}



CXScdDrawIedThumbnail *CXScdIedGroupThumb::GetIedThumbnailByIedId(CString strIedId)
{
	CXScdDrawIedThumbnail *pXScdDrawIedThumbnailTemp;
	CSclIed *pSclIed=NULL;

	POS pos=GetHeadPosition();
	while (pos!=NULL)
	{
		pXScdDrawIedThumbnailTemp=(CXScdDrawIedThumbnail *)GetNext(pos);
		pSclIed=pXScdDrawIedThumbnailTemp->GetRefIed();

		if (strIedId==pSclIed->m_strID)
		{
			break;			
		}
	}
	return pXScdDrawIedThumbnailTemp;

}

void CXScdIedGroupThumb::MoveBackward(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail)
	{
		CXScdDrawIedThumbnail *pXScdDrawIedThumbnailTemp;
		CSclIed *pSclIed1=pXScdDrawIedThumbnail->GetRefIed();
	    CSclIed *pSclIed2=NULL;
		POS pos=GetHeadPosition();
		while (pos!=NULL)
		{
			pXScdDrawIedThumbnailTemp=(CXScdDrawIedThumbnail *)GetNext(pos);
			if (pXScdDrawIedThumbnailTemp!=pXScdDrawIedThumbnail)
			{
				continue;
			}
			pXScdDrawIedThumbnailTemp=(CXScdDrawIedThumbnail *)GetNext(pos);
           pSclIed2=pXScdDrawIedThumbnailTemp->GetRefIed();
		   SwapPosition(pSclIed1->m_strID,pSclIed2->m_strID);
		   break;

		}

	}



CXScdIedGroupThumb *CXScdIedGroupThumb::SeqenGroupThumb()
{
	CXScdIedGroupThumb *pXScdIedGroupThumb=new CXScdIedGroupThumb();

	CXScdDrawIedThumbnail *pDrawIedThumbnail_MaxRefieds= GetMaxRefIedThumbnail();//寻找关联度最大的IED
	CXScdDrawIedThumbnail *pDrawIedThumbnail=new CXScdDrawIedThumbnail();

	int nCountRefIeds_Max=pDrawIedThumbnail_MaxRefieds->nCountRefIeds;

	pXScdIedGroupThumb->AddTail(pDrawIedThumbnail_MaxRefieds);


	POS pos=GetHeadPosition(); 
	

	for (int i=nCountRefIeds_Max;i>0||i==0;i--)	
	{
		POS pos1=pos;
	
		while (pos1!=NULL)
		{
			pDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos1);
			if (pDrawIedThumbnail==pDrawIedThumbnail_MaxRefieds)
			{
				continue;
			}
			if(pDrawIedThumbnail->nCountRefIeds==i)
			{
				pXScdIedGroupThumb->AddTail(pDrawIedThumbnail);
			}
		}
	}
	return pXScdIedGroupThumb;
}


CXScdIedGroupThumb *CXScdIedGroupThumb::ReOrderGroupThumb()//根据从大到小的顺序从新排列
{
	CXScdIedGroupThumb *pXScdIedGroupThumb=new CXScdIedGroupThumb();

	POS pos=GetHeadPosition(); 
	POS posHead=pos;
	POS posTail=pos;

	//CXScdDrawIedThumbnail *pDrawIedThumbnail_MaxRefieds= GetMaxRefIedThumbnail();//寻找关联度最大的IED
	CXScdDrawIedThumbnail *pDrawIedThumbnail=new CXScdDrawIedThumbnail();

	if (pos!=NULL)
	{
		pDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos);
		pXScdIedGroupThumb->AddTail(pDrawIedThumbnail);
	}

	while (pos!=NULL)
	{
		pDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos);
		//   posHead= pXScdIedGroupThumbTemp->InsertBefore(posHead,pDrawIedThumbnail);
		pXScdIedGroupThumb->AddHead(pDrawIedThumbnail);
		if(pos!=NULL)
		{
			pDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos);
			pXScdIedGroupThumb->AddTail(pDrawIedThumbnail);
		} 

	}
    return pXScdIedGroupThumb;

}
CXScdIedGroupThumb *CXScdIedGroupThumb::ReSeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb)
{
	POS pos=GetHeadPosition();
	CExBaseList *pRefLines=NULL;
	CXScdDrawIedThumbnail*pXScdDrawIedThumbnail=NULL;
	CXScdIedGroupThumb *pXScdIedGroupThumbAdjust=pXScdIedGroupThumb;
	CXScdDrawLineBase *pLine = NULL;
	CXDrawElement *pBeginElement=NULL;
	CXDrawElement *pEndElement=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;
     int bGSIn=0;
	int bGsOut=0;
	int bSvIn=0;
	int bSvOut=0;
	BOOL bSymble=0;//前插后插标志
	CXScdDrawCtrl_ThumbBase *pXScdDrawCtrl=NULL;
	CExBaseObject *pIedCtrl=NULL;
		UINT nClassID = 0;
	


	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
		if(pXScdIedGroupThumb->IsRefIedThumbInGroup(pXScdDrawIedThumbnail))//pXScdDrawIedThumbnail在pXScdIedGroupThumb组中
		{	           
			continue;
		}
	    bGSIn=0;
		bGsOut=0;
	    bSvIn=0;
	    bSvOut=0;
         pRefLines=pXScdProcMeasDrawIedThumbnail->GetLinesBetweenIedsThumbnail(pXScdDrawIedThumbnail);
		 POS pos1=pRefLines->GetHeadPosition();
		 while (pos1!=NULL)
		 {
			 pLine=(CXScdDrawLineBase*)pRefLines->GetNext(pos1);
			 pBeginElement=pLine->m_pBeginElement;
			 pEndElement=pLine->m_pEndElement;
			 pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail *)pBeginElement->GetParent();
			 pDrawIedThumbnail_End=(CXScdDrawIedThumbnail *)pEndElement->GetParent();
			 if (pDrawIedThumbnail_Begin==pXScdProcMeasDrawIedThumbnail)
			 {
				 pXScdDrawCtrl=(CXScdDrawCtrl_ThumbBase*)pBeginElement;
				
			 }
			 else
			 {
				 pXScdDrawCtrl=(CXScdDrawCtrl_ThumbBase*)pEndElement;
			 }

			 pIedCtrl=pXScdDrawCtrl->m_pSclCtrls;
             nClassID=pIedCtrl->GetClassID();
			 if (nClassID==SCLIECCLASSID_CTRLS_GS_IN)
			 {
				 bGSIn=1;	
			 }
			 else if(nClassID==SCLIECCLASSID_CTRLS_GS_OUT)
			 {
			      bGsOut=1;
			 }
			 else if(nClassID==SCLIECCLASSID_CTRLS_SMV_IN)
			 {
				 bSvIn=1;
			 }
			 else if(nClassID==SCLIECCLASSID_CTRLS_SMV_OUT)
			 {
			     bSvOut=1;	
			 }
		 }
		//if ()//与pXScdProcMeasDrawIedThumbnail的所有数据块都有连线，就把他放在最中间
		//{
		//	//添加在pXScdIedGroupThumb后面
		//	
		//}
		 if ((bGSIn+bGsOut+bSvIn+bSvOut)>3||(bGSIn+bGsOut+bSvIn+bSvOut)==3)
		 {
			 if(bSymble==0)
			 {				 
					 pXScdIedGroupThumbAdjust->AddTail(pXScdDrawIedThumbnail);
					 bSymble=1;
			 }
			 else
			 {
				 pXScdIedGroupThumbAdjust->AddHead(pXScdDrawIedThumbnail);
				 bSymble=0;
			 }
		 }
		 else if ((bGSIn+bGsOut+bSvIn+bSvOut)==2)
		 {
			 if(bGSIn&&bGsOut)
			 {
				 pXScdIedGroupThumbAdjust->AddHead(pXScdDrawIedThumbnail);
				 bSymble=0;
			 }
			 else
			 {
				 pXScdIedGroupThumbAdjust->AddTail(pXScdDrawIedThumbnail);
				 bSymble=1;
			 }
		 }
		 else
		 {
			 if(bGSIn||bGsOut)
			 {
				 pXScdIedGroupThumbAdjust->AddHead(pXScdDrawIedThumbnail);
				 bSymble=0;
			 }
			 else
			 {
				 pXScdIedGroupThumbAdjust->AddTail(pXScdDrawIedThumbnail);
				 bSymble=1;
			 }
		 }




	}

	//while ()//把剩余的添加到后面
	//{
	//}

   return  pXScdIedGroupThumbAdjust;

}


BOOL CXScdIedGroupThumb::JudgePutFrontOrBack(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb)
{
	int Length_PutFront=0;
	int Length_PutBack=0;
	int nWidth_MergIntel=0;
	int nHeight_MergIntel=0;
	CXScdDrawIedThumbnail*pXScdDrawIedThumbnail=NULL;
    POS pos =pXScdIedGroupThumb->GetHeadPosition();
	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
		nHeight_MergIntel=max(pXScdDrawIedThumbnail->m_nHeight,nHeight_MergIntel);
        nWidth_MergIntel+=pXScdDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	}
        //先确定一下两个坐标
      	CPoint pt_MergIntel_Front,pt_MergIntel_Back;
        CPoint pt_PutFront,pt_PutBack;
		CPoint pt_ProcMeas;
		pt_ProcMeas.y=5;
        pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetHead();
		pt_MergIntel_Front=pXScdDrawIedThumbnail->m_ptTopLeft;
		pt_PutFront.x=5;
        pt_PutFront.y=pt_MergIntel_Front.y;
	
        pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetTail();
		pt_MergIntel_Back=pXScdDrawIedThumbnail->m_ptTopLeft;
        pt_PutBack.x=pt_MergIntel_Back.x+pXScdDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X; 
       	pt_PutBack.y=pt_MergIntel_Back.y;

	//如果放在后面计算一下总长度
      pos =pXScdIedGroupThumb->GetHeadPosition();
	  while (pos!=NULL)
	  {
		  pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
         pXScdDrawIedThumbnail->Layout(pt_PutBack);
		 pt_PutBack.x+=pXScdDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	  }
     pt_ProcMeas.x=(pt_MergIntel_Back.x+pt_PutBack.x+pXScdDrawIedThumbnail->m_nWidth)/2-pXScdProcMeasDrawIedThumbnail->m_nWidth/2;
     pXScdProcMeasDrawIedThumbnail->Layout(pt_ProcMeas);
     
    Length_PutBack=pXScdProcMeasDrawIedThumbnail->GetAllLinesLength();

	//如果放在前面，计算一下总长度
	RightRemovd(nWidth_MergIntel);
     pos =pXScdIedGroupThumb->GetHeadPosition(); 
	 while (pos!=NULL)
	 {
		 pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
		 pXScdDrawIedThumbnail->Layout(pt_PutFront);
		 pt_PutFront.x+=pXScdDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	 }
	 pt_ProcMeas.x=(pt_PutFront.x+pXScdDrawIedThumbnail->m_nWidth+5)/2-pXScdProcMeasDrawIedThumbnail->m_nWidth/2;
	 pXScdProcMeasDrawIedThumbnail->Layout(pt_ProcMeas);

	 Length_PutFront=pXScdProcMeasDrawIedThumbnail->GetAllLinesLength();
    LeftRemovd(nWidth_MergIntel);
	 if (Length_PutFront<Length_PutBack)//放前面，返回0
	 {
		 return FALSE;
	 }
	 else
	 
		 return TRUE;


	


}

CXScdIedGroupThumb *CXScdIedGroupThumb::SeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail)
{
	CXScdIedGroupThumb *pRefMergIntelIeds=(CXScdIedGroupThumb*)pXScdProcMeasDrawIedThumbnail->m_pRefIedsThumbGroups;
	CXScdDrawIedThumbnail *pScdDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail *pScdMaxDrawIedThumbnail=NULL;

	int nCount=0;
	int nCountMax=0;
	CExBaseList *pExBaseList=new CExBaseList();
	CXScdIedGroupThumb *pXScdIedGroupThumb=new CXScdIedGroupThumb();
	CXScdIedGroupThumb *pXScdIedGroupThumbAdjust=new CXScdIedGroupThumb();

	POS pos=pRefMergIntelIeds->GetHeadPosition();
	while (pos!=NULL)
	{
		pScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pRefMergIntelIeds->GetNext(pos);
        nCount=pRefMergIntelIeds->GetRefLinesCount(pXScdProcMeasDrawIedThumbnail,pScdDrawIedThumbnail);
		if (nCountMax<nCount)
		{
			pScdMaxDrawIedThumbnail=pScdDrawIedThumbnail;
            nCountMax=nCount;
		}
	}

	for (int i=nCountMax;i>0;i--)
	{
		
		pos=pRefMergIntelIeds->GetHeadPosition();
		while (pos!=NULL)
		{
			pScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pRefMergIntelIeds->GetNext(pos);
			nCount=pRefMergIntelIeds->GetRefLinesCount(pXScdProcMeasDrawIedThumbnail,pScdDrawIedThumbnail);
			if (nCount==i)
			{
				pXScdIedGroupThumb->AddNewChild(pScdDrawIedThumbnail);
			}
		}
		pExBaseList->AddNewChild(pXScdIedGroupThumb);
	   pXScdIedGroupThumbAdjust=pXScdIedGroupThumb->ReSeqenMergIntelGroupThumb(pXScdProcMeasDrawIedThumbnail,pXScdIedGroupThumbAdjust);
	
	}

	//pos=pExBaseList->GetHeadPosition();

	//while (pos!=NULL)
	//{
	//	pXScdIedGroupThumb=(CXScdIedGroupThumb*)pExBaseList->GetNext(pos);

	////	pos1=pXScdIedGroupThumb->GetHeadPosition();

	//	//	pScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos1); 

 //       

	//}






   return pXScdIedGroupThumbAdjust;

}

int CXScdIedGroupThumb::GetRefLinesCount(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdDrawIedThumbnail *pXScdMergIntelDrawIedThumbnail)
{
		//CXScdIedGroupThumb *pRefMergIntelIeds=(CXScdIedGroupThumb*)pXScdProcMeasDrawIedThumbnail->m_pRefIedsThumbGroups;
		CExBaseList *pRefLines=pXScdProcMeasDrawIedThumbnail->m_pRefLines;
      
		int RefLinesCount=0;
       POS pos=pRefLines->GetHeadPosition();
	   	CXScdDrawLineBase *pLine = NULL;
	   CXDrawElement *pBeginElement=NULL;
	   CXDrawElement *pEndElement=NULL;
	   CXScdDrawIedThumbnail *pDrawIedThumbnail_Begin=NULL;
	   CXScdDrawIedThumbnail *pDrawIedThumbnail_End=NULL;

	   while (pos!=NULL)
	   {
          pLine=(CXScdDrawLineBase*)pRefLines->GetNext(pos);
		  if (pLine==NULL)
		  {
			  continue;
		  }
		   pBeginElement=pLine->m_pBeginElement;
		   pEndElement=pLine->m_pEndElement;
		   pDrawIedThumbnail_Begin=(CXScdDrawIedThumbnail *)pBeginElement->GetParent();
		   pDrawIedThumbnail_End=(CXScdDrawIedThumbnail *)pEndElement->GetParent();
		   if (pDrawIedThumbnail_Begin==pXScdMergIntelDrawIedThumbnail)
		   {
			   RefLinesCount++;
		   }
		   if (pDrawIedThumbnail_End==pXScdMergIntelDrawIedThumbnail)
		   {
			   RefLinesCount++;
		   }

   


	   }
	   return RefLinesCount;

}


CXScdDrawIedThumbnail *CXScdIedGroupThumb::GetMaxRefIedThumbnail()
{
	//CXScdDrawIedThumbnail *XScdDrawIedThumbnail =new CXScdDrawIedThumbnail();

	POS pos= GetHeadPosition(); 
	CXScdDrawIedThumbnail *pDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_MaxRefieds=NULL;
	int nCountRefIeds_Max=0;

	while (pos!=NULL)
	{
		pDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos);

		if (nCountRefIeds_Max<pDrawIedThumbnail->nCountRefIeds)
		{
			nCountRefIeds_Max=pDrawIedThumbnail->nCountRefIeds;
			pDrawIedThumbnail_MaxRefieds=pDrawIedThumbnail;
		}
	}
	return pDrawIedThumbnail_MaxRefieds;


}

BOOL CXScdIedGroupThumb:: IsRefIedThumbInGroup(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail)
{
	POS pos=GetHeadPosition();
	CXScdDrawIedThumbnail *pTempXScdDrawIedThumbnail=NULL;
	while(pos!=NULL)
	{
		pTempXScdDrawIedThumbnail=(CXScdDrawIedThumbnail *)GetNext(pos);
		if(pTempXScdDrawIedThumbnail==pXScdDrawIedThumbnail)
		{
			return TRUE;
		}
	}
	return FALSE;


}


CSize CXScdIedGroupThumb::IedGroupThumb_Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_ProtMeas)
{

	m_nWidth = 36750;
	m_nHeight =500;


	//首先寻找具有最大关联度的保护测控IED
	//POS pos2 = pIedList_ProtMeas->GetHeadPosition(); 
	CXScdDrawIedThumbnail *pDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail *pDrawIedThumbnail_MaxRefieds=NULL;
	int nCountRefIeds_Max=0;

	//while (pos2!=NULL)
	//{
	//	pDrawIedThumbnail=(CXScdDrawIedThumbnail *)pIedList_ProtMeas->GetNext(pos2);

	//	if (nCountRefIeds_Max<pDrawIedThumbnail->nCountRefIeds)
	//	{
	//		nCountRefIeds_Max=pDrawIedThumbnail->nCountRefIeds;
	//		pDrawIedThumbnail_MaxRefieds=pDrawIedThumbnail;
	//	}
	//}


	//CSclIed *pRefIed=NULL;

	//while (pos2!=NULL)
	//{
	//	pDrawIedThumbnail=(CXScdDrawIedThumbnail *)pIedList_ProtMeas->GetNext(pos2);

 //        pRefIed=pDrawIedThumbnail->GetRefIed();
	//	if (pRefIed->m_strID==_T("PM2291B"))
	//	{			
	//		pDrawIedThumbnail_MaxRefieds=pDrawIedThumbnail;
	//	}
	//}




   
	//pDrawIedThumbnail_MaxRefieds->m_ptTopLeft.x+=5;
	//pDrawIedThumbnail_MaxRefieds->m_ptTopLeft.y+=5;
	//

	//
	//CPoint ptMaxRefieds=pDrawIedThumbnail_MaxRefieds->m_ptTopLeft; 	
	//CPoint ptMergIntel_Start(5,400);
	//CPoint ptMergIntel(5,400);
	//
 //   CExBaseList* pRefIedsGroup=pDrawIedThumbnail_MaxRefieds->m_pRefIedsThumbGroups;
 //   int nCount=pDrawIedThumbnail_MaxRefieds->nCountRefIeds;
 //   int i=0;
 //   int width_MergIntel=0;
 //   CXScdDrawIedThumbnail *pXScdDrawIedThumbnail=NULL;

 //
 //   POS pos=pRefIedsGroup->GetHeadPosition();
 //   while(pos!=NULL)
 //   {
 //    pXScdDrawIedThumbnail=(  CXScdDrawIedThumbnail*)pRefIedsGroup->GetNext(pos);
 //    width_MergIntel+=pXScdDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	// if (width_MergIntel>pDrawIedThumbnail_MaxRefieds->m_nWidth)
	// {
	//	 pDrawIedThumbnail_MaxRefieds->m_ptTopLeft.x=ptMergIntel_Start.x+width_MergIntel/2-pDrawIedThumbnail_MaxRefieds->m_nWidth/2;
	// }
	// pXScdDrawIedThumbnail->m_ptTopLeft.x+=width_MergIntel;
	//}

 //pDrawIedThumbnail_MaxRefieds->Layout( pDrawIedThumbnail_MaxRefieds->m_ptTopLeft);

// }
	pDrawIedThumbnail_MaxRefieds=pIedList_ProtMeas->GetIedThumbnailByIedId(_T("CG5006"));
CPoint pt;
CPoint ptMaxRefieds=pDrawIedThumbnail_MaxRefieds->m_ptTopLeft; 	
CExBaseList* pRefIedsGroup=pDrawIedThumbnail_MaxRefieds->m_pRefIedsThumbGroups;
   pt.y=ptMaxRefieds.y+pDrawIedThumbnail_MaxRefieds->m_nHeight+300;


    int width=0;
	int i=0;
   POS pos3=pRefIedsGroup->GetHeadPosition();
	   while (pos3!=NULL)
	   {
		   pDrawIedThumbnail=(CXScdDrawIedThumbnail *)pRefIedsGroup->GetNext(pos3);
		   if(i>nCountRefIeds_Max/2)
		   {
			   break;
		   }
		   i++;
       width+=pDrawIedThumbnail->m_nWidth+XSCDDRAW_THUMBNAIL_GAP_IED_X;

	   }


   pt.x=ptMaxRefieds.x+pDrawIedThumbnail_MaxRefieds->m_nWidth/2-XSCDDRAW_THUMBNAIL_GAP_IED_X/2-width-XSCDDRAW_THUMBNAIL_GAP_IED_X*(nCountRefIeds_Max/2-1);

   POS pos=pRefIedsGroup->GetHeadPosition();
   CXScdDrawViewBase *pXDrawElement = NULL;
   	CSize szElement;
   while (pos != NULL)
   {
	   pXDrawElement = (CXScdDrawViewBase *)pRefIedsGroup->GetNext(pos);

	   szElement = pXDrawElement->Layout(pt);
	   m_nHeight = max(m_nHeight, szElement.cy);

	   pt.x += szElement.cx+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	   m_nWidth +=szElement.cx+XSCDDRAW_THUMBNAIL_GAP_IED_X;		
   }	

    //SwapPosition(_T("IL2251B"),_T("MT2203B"));    


	return CSize(m_nWidth, m_nHeight);


}

CSize  CXScdIedGroupThumb::IedGroupThumb_PM2Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel)//布局第二行的保护测控设备
{
	m_nWidth = 36750;
	m_nHeight =500;
	POS pos=pIedList_MergIntel->GetHeadPosition();
	CXScdDrawIedThumbnail*pXScdDrawIedThumbnail=NULL;
	CXScdDrawIedThumbnail*pXScdDrawCloseIedThumbnail=NULL;


	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pIedList_MergIntel->GetNext(pos);
		if (pXScdDrawIedThumbnail->m_ptTopLeft.x==0||pXScdDrawIedThumbnail->m_ptTopLeft.y==0)
		{
			continue;
		}
		if (pXScdDrawIedThumbnail->m_pCloseIedThumb==NULL)
		{
			continue;
		}
      pXScdDrawCloseIedThumbnail=pXScdDrawIedThumbnail->m_pCloseIedThumb;
        ptTopLeft=pXScdDrawIedThumbnail->m_ptTopLeft;
		ptTopLeft.y+=XSCDDRAW_THUMBNAIL_GAP_IED_Y;
	

		pXScdDrawCloseIedThumbnail->Layout(ptTopLeft);


	}




		return CSize(m_nWidth, m_nHeight);


}


CSize CXScdIedGroupThumb:: LayoutIedsGroupThumb(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel)
{

	int  nWidth_ProtMeas =0;
	int  nHeight_ProtMeas=0;
	int nWidth_MergIntel=0;
	int nHeight_MergIntel=0;
	CPoint pt_ProtMeas=ptTopLeft;
	CPoint pt_MergIntel=ptTopLeft;
    CXScdIedGroupThumb *Label_ProcMeas=new CXScdIedGroupThumb();
	CXScdIedGroupThumb *Label_MergIntel=new CXScdIedGroupThumb();

	
	CXScdDrawIedThumbnail *pMaxDrawIedThumbnail=GetMaxRefIedThumbnail();   
	//CSize szElement_ProtMeas= pMaxDrawIedThumbnail->Layout(ptTopLeft);
	nHeight_ProtMeas=pMaxDrawIedThumbnail->m_nHeight;
	nWidth_ProtMeas=pMaxDrawIedThumbnail->m_nWidth;

	CXScdIedGroupThumb *pXScdIedGroupThumb=(CXScdIedGroupThumb *)pMaxDrawIedThumbnail->m_pRefIedsThumbGroups;
	CXScdDrawIedThumbnail *pXScdDrawIedThumbnail=NULL;
	POS pos=pXScdIedGroupThumb->GetHeadPosition();
	while (pos!=NULL)
	{
		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
       nWidth_MergIntel+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
	   nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
	}

   pXScdIedGroupThumb= pXScdIedGroupThumb->SeqenMergIntelGroupThumb(pMaxDrawIedThumbnail);     //重新调整合并单元智能终端的顺序

	if (nWidth_MergIntel>nWidth_ProtMeas)
	{
		pt_ProtMeas.x+=nWidth_MergIntel/2-pMaxDrawIedThumbnail->m_nWidth/2;
		pMaxDrawIedThumbnail->Layout(pt_ProtMeas);
        Label_ProcMeas->AddTail(pMaxDrawIedThumbnail);
		pt_MergIntel.y+=nHeight_ProtMeas+XSCDDRAW_THUMBNAIL_GAP_IED_Y;

		pos=pXScdIedGroupThumb->GetHeadPosition();
		while (pos!=NULL)
		{
			pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
			
			//nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
			pXScdDrawIedThumbnail->Layout(pt_MergIntel);
			Label_MergIntel->AddTail(pXScdDrawIedThumbnail);
			pt_MergIntel.x+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
		}
	}
	m_nHeight=nHeight_ProtMeas+XSCDDRAW_THUMBNAIL_GAP_IED_Y+nHeight_MergIntel;
	m_nWidth=max(nWidth_MergIntel,nWidth_ProtMeas);


	int  nWidth_ProtMeas2 =0;
	int  nHeight_ProtMeas2=0;
	int nWidth_MergIntel2=0;
	int nHeight_MergIntel2=0;
	CPoint pt_ProtMeas2=ptTopLeft;
	CPoint pt_MergIntel2=ptTopLeft;
	int m_nWidth2=0;
	int m_nHeight2=0;
	BOOL Label_Insert=0;
	CSclIed*pSclIed=NULL;
    CXScdDrawIedThumbnail *pXCurrentIedThumbnail=pMaxDrawIedThumbnail;
     int nCountProcMeas=GetCount();
     int nIndex=0;


   
	
	while (nIndex<9)
	{
		nIndex=FindIndex(pXCurrentIedThumbnail);
		pXCurrentIedThumbnail=(CXScdDrawIedThumbnail*)GetAtIndex(nIndex+1);
		pSclIed=pXCurrentIedThumbnail->GetRefIed();
		//if (strstr(pSclIed->m_strName,_T("主变")))
		//{
		//	continue;
		//}
		nWidth_ProtMeas2 =0;
		nHeight_ProtMeas2=0;
	   nWidth_MergIntel2=0;
	    nHeight_MergIntel2=0;
		pt_ProtMeas2=ptTopLeft;
		pt_MergIntel2=ptTopLeft;
	   m_nWidth2=0;
		m_nHeight2=0;

		nHeight_ProtMeas2=pXCurrentIedThumbnail->m_nHeight;
		nWidth_ProtMeas2=pXCurrentIedThumbnail->m_nWidth;

		pXScdIedGroupThumb=(CXScdIedGroupThumb *)pXCurrentIedThumbnail->m_pRefIedsThumbGroups;
		pos=pXScdIedGroupThumb->GetHeadPosition();
		while (pos!=NULL)
		{

			pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
			if (Label_MergIntel->IsRefIedThumbInGroup(pXScdDrawIedThumbnail))
			{
				pXScdIedGroupThumb->Remove(pXScdDrawIedThumbnail);
				continue;			
			}
			nWidth_MergIntel2+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
			nHeight_MergIntel2=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
		} 

		if (pXScdIedGroupThumb->GetCount()==0)
		{
			continue;
		}

 	  pXScdIedGroupThumb= pXScdIedGroupThumb->SeqenMergIntelGroupThumb(pXCurrentIedThumbnail);  

        Label_Insert=Label_MergIntel->JudgePutFrontOrBack(pXCurrentIedThumbnail,pXScdIedGroupThumb);






		if(Label_Insert==0)//往前放
		{
			Label_MergIntel->RightRemovd(nWidth_MergIntel2);
			Label_ProcMeas->RightRemovd(nWidth_MergIntel2);
		

		  if (nWidth_MergIntel2>nWidth_ProtMeas2)
		  {
			  pt_ProtMeas2.x+=nWidth_MergIntel2/2-pXCurrentIedThumbnail->m_nWidth/2;
			  pXCurrentIedThumbnail->Layout(pt_ProtMeas2);
			  Label_ProcMeas->AddTail(pXCurrentIedThumbnail);
			  pt_MergIntel2.y+=nHeight_ProtMeas2+XSCDDRAW_THUMBNAIL_GAP_IED_Y;

			  pos=pXScdIedGroupThumb->GetHeadPosition();
			  while (pos!=NULL)
			  {
				  pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);

				  //nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
				  pXScdDrawIedThumbnail->Layout(pt_MergIntel2);
				  Label_MergIntel->AddTail(pXScdDrawIedThumbnail);
				  pt_MergIntel2.x+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
			  }
		  }
		}
		  else if (Label_Insert==1)//往后放
		  {
			     pt_ProtMeas2.x+=m_nWidth;
			     pt_MergIntel2.x+=m_nWidth;
					

				 if (nWidth_MergIntel2>nWidth_ProtMeas2)
				 {
					 pt_ProtMeas2.x+=nWidth_MergIntel2/2-pXCurrentIedThumbnail->m_nWidth/2;
					 pXCurrentIedThumbnail->Layout(pt_ProtMeas2);
					 Label_ProcMeas->AddTail(pXCurrentIedThumbnail);
					 pt_MergIntel2.y+=nHeight_ProtMeas2+XSCDDRAW_THUMBNAIL_GAP_IED_Y;

					 pos=pXScdIedGroupThumb->GetHeadPosition();
					 while (pos!=NULL)
					 {
						 pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);

						 //nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
						 pXScdDrawIedThumbnail->Layout(pt_MergIntel2);
						 Label_MergIntel->AddTail(pXScdDrawIedThumbnail);
						 pt_MergIntel2.x+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
					 }
				 }

		  }
		  m_nHeight2=nHeight_ProtMeas2+XSCDDRAW_THUMBNAIL_GAP_IED_Y+nHeight_MergIntel2;
		  m_nWidth2=max(nWidth_MergIntel2,nWidth_ProtMeas2);

		  m_nHeight=max(m_nHeight,m_nHeight2);
		  m_nWidth+=m_nWidth2+XSCDDRAW_THUMBNAIL_GAP_IED_X;
	


	}
	//

//  pMaxDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
 
//上面为最大的一个保护测控设备极其相关联的合并单元、智能终端布局图

//	int  nWidth_ProtMeas2 =0;
//	int  nHeight_ProtMeas2=0;
//	int nWidth_MergIntel2=0;
//	int nHeight_MergIntel2=0;
//	CPoint pt_ProtMeas2=ptTopLeft;
//	CPoint pt_MergIntel2=ptTopLeft;
//	int m_nWidth2=0;
//	int m_nHeight2=0;
//
//	BOOL Label_Insert=0;//插前插后标记
//
//	nHeight_ProtMeas2=pMaxDrawIedThumbnail->m_nHeight;
//	nWidth_ProtMeas2=pMaxDrawIedThumbnail->m_nWidth;
//    pXScdIedGroupThumb=(CXScdIedGroupThumb *)pMaxDrawIedThumbnail->m_pRefIedsThumbGroups;
//	pos=pXScdIedGroupThumb->GetHeadPosition();
//	while (pos!=NULL)
//	{
//
//		pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
//		if (Label_MergIntel->IsRefIedThumbInGroup(pXScdDrawIedThumbnail))
//		{
//			pXScdIedGroupThumb->Remove(pXScdDrawIedThumbnail);
//			continue;			
//		}
//		nWidth_MergIntel2+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
//		nHeight_MergIntel2=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
//	} 
//     //整体向右移动nWidth_MergIntel2   
//
//
//	  pXScdIedGroupThumb= pXScdIedGroupThumb->SeqenMergIntelGroupThumb(pMaxDrawIedThumbnail);     
//	  if (nWidth_MergIntel2>nWidth_ProtMeas2)
//	  {
//		  pt_ProtMeas2.x+=nWidth_MergIntel2/2-pMaxDrawIedThumbnail->m_nWidth/2;
//		  pMaxDrawIedThumbnail->Layout(pt_ProtMeas2);
//		  Label_ProcMeas->AddTail(pMaxDrawIedThumbnail);
//		  pt_MergIntel2.y+=nHeight_ProtMeas2+XSCDDRAW_THUMBNAIL_GAP_IED_Y;
//
//		  pos=pXScdIedGroupThumb->GetHeadPosition();
//		  while (pos!=NULL)
//		  {
//			  pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
//
//			  //nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
//			  pXScdDrawIedThumbnail->Layout(pt_MergIntel2);
//			  Label_MergIntel->AddTail(pXScdDrawIedThumbnail);
//			  pt_MergIntel2.x+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
//		  }
//	  }
//	  m_nHeight2=nHeight_ProtMeas2+XSCDDRAW_THUMBNAIL_GAP_IED_Y+nHeight_MergIntel2;
//	  m_nWidth2=max(nWidth_MergIntel2,nWidth_ProtMeas2);
//
//    m_nHeight=max(m_nHeight,m_nHeight2);
//   m_nWidth+=m_nWidth2+XSCDDRAW_THUMBNAIL_GAP_IED_X;
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   nIndex=FindIndex(pMaxDrawIedThumbnail);
//   pMaxDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetAtIndex(nIndex+1);
//   //  pMaxDrawIedThumbnail=(CXScdDrawIedThumbnail*)GetNext(pos);
//
//
//   int  nWidth_ProtMeas3 =0;
//   int  nHeight_ProtMeas3=0;
//   int nWidth_MergIntel3=0;
//   int nHeight_MergIntel3=0;
//   CPoint pt_ProtMeas3=ptTopLeft;
//   pt_ProtMeas3.x+=m_nWidth;
//   CPoint pt_MergIntel3=ptTopLeft;
//    pt_MergIntel3.x+=m_nWidth;
//   int m_nWidth3=0;
//   int m_nHeight3=0;
//
//   nHeight_ProtMeas3=pMaxDrawIedThumbnail->m_nHeight;
//   nWidth_ProtMeas3=pMaxDrawIedThumbnail->m_nWidth;
//   pXScdIedGroupThumb=(CXScdIedGroupThumb *)pMaxDrawIedThumbnail->m_pRefIedsThumbGroups;
//   pos=pXScdIedGroupThumb->GetHeadPosition();
//   while (pos!=NULL)
//   {
//
//	   pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
//	   if (Label_MergIntel->IsRefIedThumbInGroup(pXScdDrawIedThumbnail))
//	   {
//		   pXScdIedGroupThumb->Remove(pXScdDrawIedThumbnail);
//		   continue;			
//	   }
//	   nWidth_MergIntel3+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
//	   nHeight_MergIntel3=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
//   } 
//
//
//
//
//   pXScdIedGroupThumb= pXScdIedGroupThumb->SeqenMergIntelGroupThumb(pMaxDrawIedThumbnail);     
//   if (nWidth_MergIntel3>nWidth_ProtMeas3)
//   {
//	   pt_ProtMeas3.x+=nWidth_MergIntel3/2-pMaxDrawIedThumbnail->m_nWidth/2;
//	   pMaxDrawIedThumbnail->Layout(pt_ProtMeas3);
//	   Label_ProcMeas->AddTail(pMaxDrawIedThumbnail);
//	   pt_MergIntel3.y+=nHeight_ProtMeas3+XSCDDRAW_THUMBNAIL_GAP_IED_Y;
//
//	   pos=pXScdIedGroupThumb->GetHeadPosition();
//	   while (pos!=NULL)
//	   {
//		   pXScdDrawIedThumbnail=(CXScdDrawIedThumbnail*)pXScdIedGroupThumb->GetNext(pos);
//
//		   //nHeight_MergIntel=max(nHeight_MergIntel,pXScdDrawIedThumbnail->m_nHeight);		
//		   pXScdDrawIedThumbnail->Layout(pt_MergIntel3);
//		   Label_MergIntel->AddTail(pXScdDrawIedThumbnail);
//		   pt_MergIntel3.x+=XSCDDRAW_THUMBNAIL_GAP_IED_X+pXScdDrawIedThumbnail->m_nWidth;
//	   }
//   }
//   m_nHeight3=nHeight_ProtMeas3+XSCDDRAW_THUMBNAIL_GAP_IED_Y+nHeight_MergIntel3;
//   m_nWidth3=max(nWidth_MergIntel3,nWidth_ProtMeas3);
//
//   m_nHeight=max(m_nHeight,m_nHeight3);
//   m_nWidth+=m_nWidth3+XSCDDRAW_THUMBNAIL_GAP_IED_Y;



   
	
 //return CSize(m_nWidth,m_nHeight);

return CSize(5000,2500);



}


CSize CXScdIedGroupThumb::LayoutIedsGroupThumb_MergIntel(CPoint &ptTopLeft,CXScdDrawIedThumbnail *pIedList_ProtMeas)
{
    return CSize(0,0);

}







//////////////////////////////////////////////////////////////////////////
//CXScdDrawViewBase
CXScdDrawViewBase::CXScdDrawViewBase()
{
	//初始化属性

	//初始化成员变量
	m_pActiveElement = NULL;
	m_pSclIed = NULL;
}

CXScdDrawViewBase::~CXScdDrawViewBase()
{
}
void CXScdDrawViewBase::AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow)
{
	CXScdDrawIedBase *pIedBase = NULL;
	POS pos = GetHeadPosition();

	while (pos != NULL)
	{
		pIedBase = (CXScdDrawIedBase *)GetNext(pos);
		pIedBase->AttachViewWindow(pViewWindow);
	}
}
void CXScdDrawViewBase::Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	CXDrawElements::Draw(pDC, fZoomRatio, ptOffset);
	//m_oScdBriefDrawLines.Draw(pDC, fZoomRatio, ptOffset);
   m_oScdDrawLines_ToBus.Draw(pDC, fZoomRatio, ptOffset);
//	m_oScdDrawLines.Draw(pDC, fZoomRatio, ptOffset);
}


void CXScdDrawViewBase::DrawActiveElement(CDC *pDC, double fZoomRatio,const CPoint &ptOffset)
{
	if (m_pActiveElement == NULL)
	{
		return;
	}

	m_pActiveElement->Draw(pDC, fZoomRatio, ptOffset);
}

void CXScdDrawViewBase::LayoutLines()
{
	
}

////////////////////////////////////////////////////////////////////////
CXDrawElement* CXScdDrawViewBase::UI_GetActiveXDrawElement(const CPoint &point)
{
	CExBaseList oList;
	Pick(point, oList);

	CXDrawElement *pActiveElement = NULL;

	if (oList.GetCount() > 0)
	{
		pActiveElement = (CXDrawElement *)oList.GetHead();
	}

	oList.RemoveAll();

	return pActiveElement;
}

void CXScdDrawViewBase::UI_OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

}

void CXScdDrawViewBase::UI_OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

}

void CXScdDrawViewBase::UI_OnSize(UINT nType, int cx, int cy)
{

}

void CXScdDrawViewBase::UI_OnLButtonUp(UINT nFlags, CPoint point)
{
	CXDrawElement *pActiveElement = UI_GetActiveXDrawElement(point);

	if (pActiveElement != m_pActiveElement)
	{
		// 		if (m_pActiveElement != NULL)
		// 		{
		// 			m_pActiveElement->UI_KillFocus()
		// 		}
		// 
		// 		m_pActiveElement = pActiveElement;
		//
		// 		if (m_pActiveElement != NULL)
		// 		{
		// 			m_pActiveElement->UI_OnLButtonUp(nFlags, point);
		// 		}
	}
	else
	{
		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_OnLButtonUp(nFlags, point);
		}
	}
}

void CXScdDrawViewBase::UI_OnLButtonDown(UINT nFlags, CPoint point)
{
	CXDrawElement *pActiveElement = UI_GetActiveXDrawElement(point);

	if (pActiveElement != m_pActiveElement)
	{
		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_KillFocus();
		}

		m_pActiveElement = pActiveElement;

		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_OnLButtonDown(nFlags, point);
		}
	}
	else
	{
		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_OnLButtonDown(nFlags, point);
		}
	}
}

void CXScdDrawViewBase::UI_OnMouseMove(UINT nFlags, CPoint point)
{
	CXDrawElement *pActiveElement = UI_GetActiveXDrawElement(point);

	if (pActiveElement != NULL)
	{
		pActiveElement->UI_OnMouseMove(nFlags, point);
	}
}

void CXScdDrawViewBase::UI_OnTimer(UINT nIDEvent)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnTimer(nIDEvent);
	}
}

UINT CXScdDrawViewBase::UI_OnGetDlgCode()
{
	return 0;
}

BOOL CXScdDrawViewBase::UI_OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnKeyDown(nChar, nRepCnt, nFlags);
	}

	return FALSE;
}

BOOL CXScdDrawViewBase::UI_OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnChar(nChar, nRepCnt, nFlags);
	}

	return FALSE;
}

void CXScdDrawViewBase::UI_OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CXDrawElement *pActiveElement = UI_GetActiveXDrawElement(point);

	if (pActiveElement != m_pActiveElement)
	{
		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_KillFocus();
		}

		m_pActiveElement = pActiveElement;

		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_OnLButtonDblClk(nFlags, point);
		}
	}
	else
	{
		if (m_pActiveElement != NULL)
		{
			m_pActiveElement->UI_OnLButtonDblClk(nFlags, point);
		}
	}
}

void CXScdDrawViewBase::UI_OnRButtonDblClk(UINT nFlags, CPoint point)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnRButtonDblClk(nFlags, point);
	}
}

BOOL CXScdDrawViewBase::UI_OnEraseBkgnd(CDC* pDC)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnEraseBkgnd(pDC);
	}

	return FALSE;
}

BOOL CXScdDrawViewBase::UI_OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	return FALSE;
}

void CXScdDrawViewBase::UI_OnSysColorChange()
{

}

void CXScdDrawViewBase::UI_OnCaptureChanged(CWnd *pWnd)
{
	if (m_pActiveElement != NULL)
	{
		m_pActiveElement->UI_OnCaptureChanged(pWnd);
	}
}

void CXScdDrawViewBase::UI_OnUpdateEditSelectAll(CCmdUI* pCmdUI)
{

}

void CXScdDrawViewBase::UI_OnRButtonUp(UINT nFlags, CPoint point)
{
	if (m_pActiveElement != NULL)
	{
		m_pActiveElement->UI_OnRButtonUp(nFlags, point);
	}
}

void CXScdDrawViewBase::UI_OnKillFocus(CWnd* pNewWnd)
{
	if (m_pActiveElement != NULL)
	{
		m_pActiveElement->UI_OnKillFocus(pNewWnd);
	}
}


#if _MFC_VER >= 0x0421
void CXScdDrawViewBase::UI_OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{

}

BOOL CXScdDrawViewBase::UI_OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	return FALSE;
}
#endif

LRESULT CXScdDrawViewBase::UI_OnSetFont(WPARAM hFont, LPARAM lParam)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnSetFont(hFont, lParam);
	}

	return 0;
}

LRESULT CXScdDrawViewBase::UI_OnGetFont(WPARAM hFont, LPARAM lParam)
{
	if (m_pActiveElement != NULL)
	{
		return m_pActiveElement->UI_OnGetFont(hFont, lParam);
	}

	return 0;
}

void CXScdDrawViewBase::UI_OnEndInPlaceEdit(NMHDR* pNMHDR, LRESULT* pResult)
{

}

void CXScdDrawViewBase::UI_OnEndPointEdit(NMHDR* pNMHDR, LRESULT* pResult)
{

}

void CXScdDrawViewBase::UI_OnEndInplaceComboBoxEdit(NMHDR* pNMHDR, LRESULT* pResult)
{

}

LRESULT CXScdDrawViewBase::UI_OnFillComboBox(WPARAM nColumn, LPARAM pListBox)
{
	return 0;
}

LRESULT CXScdDrawViewBase::UI_OnFillList(WPARAM nColumn, LPARAM pListBox)
{
	return 0;
}

LRESULT CXScdDrawViewBase::UI_OnFillTree(WPARAM nColumn, LPARAM pListBox)
{
	return 0;
}

LRESULT CXScdDrawViewBase::UI_OnFillTimeCtrl(WPARAM nColumn, LPARAM pListBox)
{
	return 0;
}

void CXScdDrawViewBase::UI_OnRButtonDown(UINT nFlags, CPoint point)
{

}
