//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.h  CXScdDrawIed

#pragma once

#include "..\..\Module\XDrawBase\XDrawElements.h"
#include "XScdDrawGlobal.h"
#include "XScdDrawIedBase.h"

#include "XScdDrawCtrl_ThumbSvOut.h"
#include "XScdDrawCtrl_ThumbSvIn.h"
#include "XScdDrawCtrl_ThumbGsOut.h"
#include "XScdDrawCtrl_ThumbGsIn.h"
#include "XScdDrawLineBase.h"


#define IEDTHUMBNAILTYPE_PROCMEAS 1
#define IEDTHUMBNAILTYPE_MUCTRL 2
#define IEDTHUMBNAILTYPE_PROCMEAS2 3



class CXScdDrawIedThumbnail : public CXScdDrawIedBase
{
public:
	CXScdDrawIedThumbnail();
	virtual ~CXScdDrawIedThumbnail();

//重载函数
public:
 	virtual UINT GetClassID() {    return XSCDDRAW_IED_THUMBNAIL;   }

//私有成员变量
private:
	CSclIed *m_pRefIed;
	int m_b_ProtMeas_MuCtrl;


public:
	int nCountRefIeds;//统计相关联的IED个数
	CExBaseList *m_pRefIedsThumbGroups;
	CExBaseList *m_pRefLines;

public:
	CXScdDrawIedThumbnail  *m_pCloseIedThumb;//与本身互为GsIn、GsOut的IEDThumb
	CExBaseList *GetLinesBetweenIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//获得与指定IED相关联的连线集合
    void RightRemovd(int nRange);
	    void LeftRemovd(int nRange);
      int  GetAllLinesLength();//获得某IED的所有连线的长度
//私有成员变量访问方法
public:
	void SetRefIed(CSclIed *pRefIed) {m_pRefIed=pRefIed;}
	CSclIed* GetRefIed() {return m_pRefIed;}

	void SetSymbel (int b_ProtMeas_MuCtrl) {m_b_ProtMeas_MuCtrl = b_ProtMeas_MuCtrl;}
	int GetSymbel() {return m_b_ProtMeas_MuCtrl;}

	//绘图相关函数定义
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
   
	CSize CalLayout(CSize &szDraw);
	virtual CSize Layout(CPoint &ptTopLeft);

	virtual void  XCreateCtrl(CSclIed *pIedData, CWnd *pParentWnd);
	virtual void GetAllLines(CXDrawElements &oScdLines);
	void GetAllKindsLines(CXDrawElements &oScdLines,CXDrawElements &oScdToBusLines);
	//void GetCount_RefIed(CSclIed *pIedData);

};

