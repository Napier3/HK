//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

//XScdDrawViewThumbnail.h  CXScdDrawViewThumbnail

#pragma once

#include "XScdDrawViewBase.h"
#include "XScdDrawIedThumbnail.h"

extern int  g_VerticalLocate_Bus;//ĸ�ߵ�������λ��
extern 	int g_VerticalLocate_GooseBus;
extern int g_VerticalLocate_SmvBus;


class CXScdDrawViewThumbnail : public CXScdDrawViewBase
{
public:
	CXScdDrawViewThumbnail();
	virtual ~CXScdDrawViewThumbnail();

//���غ���
public:
 	virtual UINT GetClassID() {    return XSCDDRAW_VIEW_THUMB;   }

//˽�г�Ա����
private:
	CExBaseList m_listIedGroup;
	CXScdIedGroupThumb *m_pIedList_ProtMeas;//������ؼ���
	CXScdIedGroupThumb *m_pIedList_MergIntel;//�����ն˺ϲ���Ԫ����
	CXScdIedGroupThumb *m_pIedList_ProtMeas2;//�ڶ��б������IED

//˽�г�Ա�������ʷ���
public:
	CExBaseList *m_listGroups;


	//��ͼ��غ�������
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void Pick(const CPoint &point, CExBaseList &oList);

public:
	virtual CXDrawElement* XCreateChildElement(UINT nClassID);

	virtual DWORD XCreateElement(CExBaseObject *pData, CWnd *pParentWnd);
	void InitXScdDrawViewThumbnail(CSclStation *pSclStation, CWnd *pParentWnd);
	

	void IndependXScdDrawViewThumbnail();
	void FilterIedThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail,CXScdIedGroupThumb *m_pIedList_ProtMeas,CXScdIedGroupThumb *m_pIedList_MergIntel);

	void SplitIedList_ProtMeas();//���ݵ�һ�б�����غ͵ڶ��кϲ���Ԫ�����ն��������ɵ�һ�к͵����б������
   BOOL IsCloselyIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2);
 CXScdIedGroupThumb* ReAdjustIedList_ProtMeas(CXScdIedGroupThumb *pIedList_ProtMeas,CXScdIedGroupThumb *pIedList_ProtMeas2);//���µ������������


	virtual CSize CalLayout(CSize &szDraw);
	virtual CSize Layout(CPoint &ptTopLeft);

	virtual void LayoutLines();
	virtual void InitLinesBeginElement();
	//void SetIedsArea(CXScdDrawIedThumbnail *pDrawIed_Thumbnail );

};

