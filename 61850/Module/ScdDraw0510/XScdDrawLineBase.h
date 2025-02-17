//这段源代码由ClassGenerator创建
//版权所有 LiJunqing  lijunqing1224@126.com
//保留所有权利

//XScdDrawIed.h  CXScdDrawIed

#pragma once

#include "XScdDrawGlobal.h"





class CXScdDrawLineBase : public CXDrawElements
{
public:
	CXScdDrawLineBase();
	virtual ~CXScdDrawLineBase();
public:
	virtual UINT GetClassID() {    return XSCDDRAW_LINE_BASE;   }

public:
	CExBaseObject *m_pBeginObj;
	CExBaseObject *m_pEndObj;
	CXDrawElement *m_pBeginElement;
	CXDrawElement *m_pEndElement;
	CPoint m_ptBegin;
	CPoint m_ptEnd;

public:
	virtual BOOL CopyOwn(CBaseObject* pDest);
	virtual CBaseObject* Clone();

//重载函数
public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void InitLinePos();
	virtual void InitToBusLinePos();
};

class CXScdDrawLine_ToBus : public CXScdDrawLineBase
{
public:
	CXScdDrawLine_ToBus();
	virtual ~CXScdDrawLine_ToBus();
public:
	virtual UINT GetClassID() {    return XSCDDRAW_LINE_TOBUS;   }

public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual void InitLinePos();

};



class CXScdDrawLine_Vert : public CXScdDrawLineBase
{
public:
	CXScdDrawLine_Vert();
	virtual ~CXScdDrawLine_Vert();

public:
	
      CPoint pt_MainIedTurn; //靠近被测IED的一个拐点坐标
	  

public:
		virtual UINT GetClassID() {    return XSCDDRAW_LINE_VERT;   }

public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);
	virtual CBaseObject* Clone();

};


class CXScdDrawLine_Bus  : public CXScdDrawLineBase
{
public:
	CXScdDrawLine_Bus();
	virtual ~CXScdDrawLine_Bus();

public:

public:
	virtual void Draw(CDC *pDC, double fZoomRatio,const CPoint &ptOffset);

};


class CXScdDrawLine_GooseBus : public CXScdDrawLine_Bus
{
public:
	CXScdDrawLine_GooseBus();
	virtual ~CXScdDrawLine_GooseBus();
public:
		virtual UINT GetClassID() {    return XSCDDRAW_LINE_GOOSEBUS;   }
};


class CXScdDrawLine_SvBus : public CXScdDrawLine_Bus
{
public:
	CXScdDrawLine_SvBus();
	virtual ~CXScdDrawLine_SvBus();

public:
	virtual UINT GetClassID() {    return XSCDDRAW_LINE_SVBUS;   }
};