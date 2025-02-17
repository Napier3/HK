//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawCtrl_ThumbBase.h  XScdDrawCtrl_ThumbBase

#pragma once

#include "XScdDrawCtrlBase.h"


class CXScdDrawCtrl_ThumbBase : public CXDrawElements
{
public:
	CXScdDrawCtrl_ThumbBase();
	virtual ~CXScdDrawCtrl_ThumbBase();

private:
	
public:
	CString m_strCtrlText;
	CExBaseObject *m_pSclCtrls;
	

public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);

	virtual DWORD XCreateElement(CExBaseObject *pData, CWnd *pParentWnd);
	virtual CSize CalLayout(CSize &szDraw);
	virtual CSize Layout(CPoint &ptTopLeft);

	virtual void CreateCtrlLines(){};
	virtual CXScdDrawLineBase* FindLineByBeginRef(CExBaseObject *pBeginRef);

	virtual void GetAllLines(CXDrawElements &oScdLines);
	void GetAllKindsLines(CXDrawElements &oScdLines,CXDrawElements &oScdToBusLines);

};
