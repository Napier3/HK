//���Դ������ClassGenerator����
//��Ȩ���� LiJunqing  lijunqing1224@126.com
//��������Ȩ��

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

//���غ���
public:
 	virtual UINT GetClassID() {    return XSCDDRAW_IED_THUMBNAIL;   }

//˽�г�Ա����
private:
	CSclIed *m_pRefIed;
	int m_b_ProtMeas_MuCtrl;


public:
	int nCountRefIeds;//ͳ���������IED����
	CExBaseList *m_pRefIedsThumbGroups;
	CExBaseList *m_pRefLines;

public:
	CXScdDrawIedThumbnail  *m_pCloseIedThumb;//�뱾��ΪGsIn��GsOut��IEDThumb
	CExBaseList *GetLinesBetweenIedsThumbnail(CXScdDrawIedThumbnail *pXScdDrawIedThumbnail);//�����ָ��IED����������߼���
    void RightRemovd(int nRange);
	    void LeftRemovd(int nRange);
      int  GetAllLinesLength();//���ĳIED���������ߵĳ���
//˽�г�Ա�������ʷ���
public:
	void SetRefIed(CSclIed *pRefIed) {m_pRefIed=pRefIed;}
	CSclIed* GetRefIed() {return m_pRefIed;}

	void SetSymbel (int b_ProtMeas_MuCtrl) {m_b_ProtMeas_MuCtrl = b_ProtMeas_MuCtrl;}
	int GetSymbel() {return m_b_ProtMeas_MuCtrl;}

	//��ͼ��غ�������
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
   
	CSize CalLayout(CSize &szDraw);
	virtual CSize Layout(CPoint &ptTopLeft);

	virtual void  XCreateCtrl(CSclIed *pIedData, CWnd *pParentWnd);
	virtual void GetAllLines(CXDrawElements &oScdLines);
	void GetAllKindsLines(CXDrawElements &oScdLines,CXDrawElements &oScdToBusLines);
	//void GetCount_RefIed(CSclIed *pIedData);

};

