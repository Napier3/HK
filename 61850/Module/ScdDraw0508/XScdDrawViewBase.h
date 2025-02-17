//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

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


    CXScdIedGroupThumb *SeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail);//������ĳһ�����������ص�һϵ�кϲ���Ԫ�����ն˵�˳��
    int GetRefLinesCount(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdDrawIedThumbnail *pXScdMergIntelDrawIedThumbnail); //�ҵ�����IED֮����ߵĸ���
	CXScdIedGroupThumb *ReSeqenMergIntelGroupThumb(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb);//������ĳһ�����������ص�һϵ�кϲ���Ԫ�����ն˵�˳��
     
	BOOL JudgePutFrontOrBack(CXScdDrawIedThumbnail *pXScdProcMeasDrawIedThumbnail,CXScdIedGroupThumb *pXScdIedGroupThumb);//�ж�һ�����ǰ���Ƿź�

	void RightRemovd(int pRange);//����IED�����ƶ�����
		void LeftRemovd(int pRange);//����IED�����ƶ�����

	CXScdIedGroupThumb *SeqenGroupThumb();//���չ����ȴ�С����
	CXScdIedGroupThumb *ReOrderGroupThumb();//���չ����ȴ�С����

	CXScdDrawIedThumbnail *GetMaxRefIedThumbnail();
	void SwapPosition(CString strIedId1,CString strIedId2);//����IED��ID����λ��
//	void SwapPosition(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail1,CXScdDrawIedThumbnail *pXScdDrawIedThumbnail2);//����DrawIed����λ��

	CXScdDrawIedThumbnail *GetIedThumbnailByIedId(CString strIedId);//����IED��ID�����Ӧ��DrawIed




	void MoveBackward(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//����ƶ�һ�������Ļ���

	
	BOOL IsRefIedThumbInGroup(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//�ж��Ƿ��Ǹ����е�һԱ��

	 CSize IedGroupThumb_Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_ProtMeas);
	 CSize  IedGroupThumb_PM2Layout(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel);//���ֵڶ��еı�������豸
	 CSize LayoutIedsGroupThumb(CPoint &ptTopLeft,CXScdIedGroupThumb *pIedList_MergIntel);

	 CSize LayoutIedsGroupThumb_MergIntel(CPoint &ptTopLeft,CXScdDrawIedThumbnail *pIedList_ProtMeas);//����ĳһ����������豸������Ӧ�ı����ն˺ϲ���Ԫ�豸


};

//////////////////////////////////////////////////////////////////////////
//CXScdDrawViewBase
class CXScdDrawViewBase : public CXDrawElements
{
public:
	CXScdDrawViewBase();
	virtual ~CXScdDrawViewBase();

//���غ���
public:

//˽�г�Ա����
   virtual void AttachViewWindow(CXDrawBaseInterface_ViewWindow *pViewWindow);

public:
	CSclStation *m_pSclStation;
	CSclIed *m_pSclIed;

	CXDrawElement* m_pActiveElement;
	CXDrawElements m_oScdDrawLines;
	CXDrawElements m_oScdDrawLines_ToBus;
	CXDrawElements m_oScdBriefDrawLines;


//˽�г�Ա�������ʷ���
public:
	void SetStation(CSclStation *p)	{	m_pSclStation = p;	}

//��ͼ��غ�������
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

