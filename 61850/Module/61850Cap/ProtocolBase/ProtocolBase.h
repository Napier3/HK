// ProtocolBase.h: interface for the CProtocolBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_StPROTOCOLBASE_H__)
#define _StPROTOCOLBASE_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FrameBaseList.h"

//报文基类，制造、解析、匹配报文
class CProtocolBase : public CExBaseList
{
public:
	CProtocolBase();
	virtual ~CProtocolBase();

//属性
public:
	CFrameBaseList  *m_pParseFrames;   //解析帧管理
	long m_nFrameMaxLength;
	long m_nFrameMinLength;

	EPCAPPARSEDATAS m_oCapParseDatas;
	EPBUFFERPOS m_bufPos;
	DWORD m_dwPrototcol;   //规约的类型

public:
	UINT GetClassID()	{	return STPROTOCOLCLASSID_PROTOCOL;	}
	void InitBufPos()
	{
		ZeroMemory(&m_bufPos, sizeof(EPBUFFERPOS));
		m_bufPos.pDatas = &m_oCapParseDatas;
	}

public:
	virtual CExBaseObject* Parse(CFrameMemBuffer *pBuffer, CFrameDetail *pDetailList, DWORD dwPara)
	{
		InitBufPos();
		m_bufPos.dwPara = dwPara;
		pBuffer->GetBufferPos(m_bufPos);
		CExBaseObject *p = Parse(&m_bufPos, pDetailList);
		return p;
	}
	virtual CExBaseObject* Parse(CFrameMemBuffer *pBuffer, DWORD dwPara)
	{
		InitBufPos();
		m_bufPos.dwPara = dwPara;
		pBuffer->GetBufferPos(m_bufPos);
		CExBaseObject *p = Parse(&m_bufPos);
		return p;
	}

	void AddParseFrame(CFrameBase *pFrame);

	CFrameBase* Match(PEPBUFFERPOS pBufferPos);
	CFrameBase* Parse(PEPBUFFERPOS pBufferPos, CFrameDetail *pDetailList);
	CFrameBase* Parse(PEPBUFFERPOS pBufferPos);

	CFrameBase* FindFrameByID(DWORD dwClassID);

//////////////////////////////////////////////////////////////////////////
//通讯通道定义
protected:
	CExBaseObject *m_pDevice;
	//CStDeviceCmmChannel *m_pDeviceCmmChannel;    //关联的设备通讯对象
	
public:
	void AttachDevice(CExBaseObject *pDevice);

};


#endif // !defined(_StPROTOCOLBASE_H__)
