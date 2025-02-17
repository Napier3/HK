//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawViewBase.h  CXScdDrawViewBase

#pragma once

#include "..\..\Module\XDrawBase\XDrawElements.h"
#include "XScdDrawGlobal.h"
#include "XScdDrawIedBase.h"
#include "XScdDrawIedThumbnail.h"

//////////////////////////////////////////////////////////////////////////\
//CXScdIedGroup
class CXScdIedGroup : public CXDrawElements
{
public:
	CXScdIedGroup();
	virtual ~CXScdIedGroup();

public:
	virtual CSize Layout(CPoint &ptTopLeft);

};

class CXScdIedGroupThumb : public CXScdIedGroup
{
public:
	CXScdIedGroupThumb();
	virtual ~CXScdIedGroupThumb();
	CSize m_pScdIedGroupThumb;

public:
   // CXScdDrawIedThumbnail*	GetRefDrawIed_Thumbnail(CExBaseObject *pObj);
	virtual CSize Layout(CPoint &ptTopLeft);


    CXScdIedGroupThumb *SeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail);//排列与某一个保护测控相关的一系列合并单元智能终端的顺序
    int GetRefLinesCount(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdDrawIedThumbnail *pXScdMergIntelDrawIedThumbnail); //找到两个IED之间的线的个数
	CXScdIedGroupThumb *ReSeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb);//排列与某一个保护测控相关的一系列合并单元智能终端的顺序
     
	BOOL JudgePutFrontOrBack(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb);//判断一个组放前还是放后

	void RightRemovd(int pRange);//所有IED向右移动距离
		void LeftRemovd(int pRange);//所有IED向左移动距离

	CXScdIedGroupThumb *SeqenGroupThumb();//按照关联度大小排序
	CXScdIedGroupThumb *ReOrderGroupThumb();//按照关联度大小排序

	CXScdDrawIedThumbnail *GetMaxRefIedThumbnail();
	void SwapPosition(CString strIedId1,CString strIedId2);//根据IED的ID交换位置
//	void SwapPosition(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2);//根据DrawIed交换位置

	CXScdDrawIedThumbnail *GetIedThumbnailByIedId(CString strIedId);//根据IED的ID获得相应的DrawIed




	void MoveBackward(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//向后移动一格，与后面的互换

	
	BOOL IsRefIedThumbInGroup(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//判断是否是该组中的一员？

	 CSize IedGroupThumb_Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_ProtMeas);
	 CSize  IedGroupThumb_PM2Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel);//布局第二行的保护测控设备
	 CSize LayoutIedsGroupThumb(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel);

	 CSize LayoutIedsGroupThumb_MergIntel(CPoint &ptTopLeft,CXScdDrawIedThumbnail *pIedList_ProtMeas);//根据某一个保护测控设备布局响应的保护终端合并单元设备


};

//////////////////////////////////////////////////////////////////////////
//CXScdDrawViewBase
class CXScdDrawViewBase : public CXDrawElements
{
public:
	CXScdDrawViewBase();
	virtual ~CXScdDrawViewBase();

//重载函数
public:

//私有成员变量
   virtual void AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow);

public:
	CSclStation *m_pSclStation;
	CSclIed *m_pSclIed;

	CXDrawElement* m_pActiveElement;
	CXDrawElements m_oScdDrawLines;
	CXDrawElements m_oScdDrawLines_ToBus;
	CXDrawElements m_oScdBriefDrawLines;


//私有成员变量访问方法
public:
	void SetStation(CSclStation *p)	{	m_pSclStation = p;	}

//绘图相关函数定义
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);

	virtual void DrawActiveElement(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void LayoutLines();

//Message
public:
	virtual void UI_OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void UI_OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void UI_OnSize(UINT nType, int cx, int cy);
	virtual void UI_OnLButtonUp(UINT nFlags, CPoint point);
	virtual void UI_OnLButtonDown(UINT nFlags, CPoint point);
	virtual void UI_OnMouseMove(UINT nFlags, CPoint point);
	virtual void UI_OnTimer(UINT nIDEvent);
	virtual UINT UI_OnGetDlgCode();
	virtual BOOL UI_OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL UI_OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void UI_OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void UI_OnRButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL UI_OnEraseBkgnd(CDC* pDC);
	virtual BOOL UI_OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual void UI_OnSysColorChange();
	virtual void UI_OnCaptureChanged(CWnd *pWnd);
	virtual void UI_OnUpdateEditSelectAll(CCmdUI* pCmdUI);
	virtual void UI_OnRButtonUp(UINT nFlags, CPoint point);
	virtual void UI_OnKillFocus(CWnd* pNewWnd);	

#if _MFC_VER >= 0x0421
	virtual void UI_OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	virtual BOOL UI_OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
#endif

	virtual LRESULT UI_OnSetFont(WPARAM hFont, LPARAM lParam);
	virtual LRESULT UI_OnGetFont(WPARAM hFont, LPARAM lParam);
	virtual void UI_OnEndInPlaceEdit(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void UI_OnEndPointEdit(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void UI_OnEndInplaceComboBoxEdit(NMHDR* pNMHDR, LRESULT* pResult);

	virtual LRESULT UI_OnFillComboBox(WPARAM nColumn, LPARAM pListBox);
	virtual LRESULT UI_OnFillList(WPARAM nColumn, LPARAM pListBox);
	virtual LRESULT UI_OnFillTree(WPARAM nColumn, LPARAM pListBox);
	virtual LRESULT UI_OnFillTimeCtrl(WPARAM nColumn, LPARAM pListBox);
	virtual void UI_OnRButtonDown(UINT nFlags, CPoint point);

protected:
	CXDrawElement* UI_GetActiveXDrawElement(const CPoint &point);
};

