//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawViewThumbnail.h  CXScdDrawViewThumbnail

#pragma once

#include "XScdDrawViewBase.h"
#include "XScdDrawIedThumbnail.h"

extern int  g_VerticalLocate_Bus;//母线的纵坐标位置
extern 	int g_VerticalLocate_GooseBus;
extern int g_VerticalLocate_SmvBus;


class CXScdDrawViewThumbnail : public CXScdDrawViewBase
{
public:
	CXScdDrawViewThumbnail();
	virtual ~CXScdDrawViewThumbnail();

//重载函数
public:
 	virtual UINT GetClassID() {    return XSCDDRAW_VIEW_THUMB;   }

//私有成员变量
private:
	CExBaseList m_listIedGroup;
	CXScdIedGroupThumb *m_pIedList_ProtMeas;//保护测控集合
	CXScdIedGroupThumb *m_pIedList_MergIntel;//智能终端合并单元集合
	CXScdIedGroupThumb *m_pIedList_ProtMeas2;//第二行保护测控IED

//私有成员变量访问方法
public:
	CExBaseList *m_listGroups;


	//绘图相关函数定义
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void Pick(const CPoint &point, CExBaseList &oList);

public:
	virtual CXDrawElement* XCreateChildElement(UINT nClassID);

	virtual DWORD XCreateElement(CExBaseObject *pData, CWnd *pParentWnd);
	void InitXScdDrawViewThumbnail(CSclStation *pSclStation, CWnd *pParentWnd);
	

	void IndependXScdDrawViewThumbnail();
	void FilterIedThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail,CXScdIedGroupThumb *m_pIedList_ProtMeas,CXScdIedGroupThumb *m_pIedList_MergIntel);

	void SplitIedList_ProtMeas();//根据第一行保护测控和第二行合并单元智能终端重新生成第一行和第三行保护测控
   BOOL IsCloselyIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2);
 CXScdIedGroupThumb* ReAdjustIedList_ProtMeas(CXScdIedGroupThumb *pIedList_ProtMeas,CXScdIedGroupThumb *pIedList_ProtMeas2);//重新调整保护测控行


	virtual CSize CalLayout(CSize &szDraw);
	virtual CSize Layout(CPoint &ptTopLeft);

	virtual void LayoutLines();
	virtual void InitLinesBeginElement();
	//void SetIedsArea(CXScdDrawIedThumbnail *pDrawIed_Thumbnail );

};

