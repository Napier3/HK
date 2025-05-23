// MemBuffer_Float.cpp: implementation of the CMemBuffer_Float class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemBuffer_Float.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMemBuffer_Float::CMemBuffer_Float()
{
	m_nBufferLength		= 0;	
	m_nDataFillBeginPos = 0;
	m_nDataLength		= 0;
	m_pBuffer			= NULL;
	m_pdValue           = NULL;
	m_strBufferID		= "";   
	memset(m_dwFreqZeroPosition, 0, MAX_FREQ_ZERO_POS_BUFFER*sizeof(DWORD));
	m_nFreqZeroPosCount = 0;
	
}

CMemBuffer_Float::~CMemBuffer_Float()
{
	FreeBuffer();
}

long CMemBuffer_Float::CopyBuffer(CMemBufferInterface *pBuffer, long &lCopyBeginPos, long lGap)
{
	ASSERT (FALSE);
	return 0;
}

void CMemBuffer_Float::BuildComplexBufferScript()
{

}


float* CMemBuffer_Float::GetBuffer_float()
{
	return m_pBuffer;
}

void CMemBuffer_Float::OffsetDataFillBeginPosition(long nLen)
{
	m_nDataFillBeginPos += nLen;
	m_nDataLength += nLen;
	
	if (m_nDataFillBeginPos >= m_nBufferLength)
	{
		m_nDataFillBeginPos -= m_nBufferLength;
	}
	
	if (m_nDataLength >= m_nBufferLength)
	{
		m_nDataLength = m_nBufferLength;
	}	
}

void CMemBuffer_Float::Init()
{
	m_nDataFillBeginPos = 0;
	m_nDataLength		= 0;
}

void CMemBuffer_Float::SetBufferLength(long lBufferLen)
{
	FreeBuffer();
	m_nBufferLength = lBufferLen;
	m_pBuffer = new float[lBufferLen+MEMBUFFER_LENGTH_EX];
	memset(m_pBuffer, 0, lBufferLen*sizeof(float));
}

void CMemBuffer_Float::AppendBuffer(float *pBuffer, long lLen)
{
	FreeBuffer();
	m_pBuffer = pBuffer;
	m_nBufferLength = lLen;
}

void CMemBuffer_Float::AppendBuffer(CMemBuffer_Float *pBuffer)
{
	FreeBuffer();
	m_pBuffer = pBuffer->GetBuffer_float();
}

void CMemBuffer_Float::AttachBuffer(float *pBuffer, long lLen)
{
	FreeBuffer();
	m_pBuffer = pBuffer;
	m_nBufferLength = lLen;
	m_nDataLength = m_nBufferLength;
	m_nDataFillBeginPos = 0;
}

void CMemBuffer_Float::DettachBuffer()
{
	m_pBuffer = NULL;
	m_nBufferLength		= 0;	
	m_nDataFillBeginPos = 0;
	m_nDataLength		= 0;
}


long CMemBuffer_Float::CopyBuffer(float *pBuffer, long lLen, long lGap)
{
	long lPos1Begin = -1;
	long lPos1End = -1;
	long lPos2Begin = -1;
	long lPos2End = -1;

	long lLenCopy = CalCopyBuffer(lLen, lGap, FALSE, lPos1Begin, lPos1End, lPos2Begin, lPos2End);

	if (lPos1Begin >= 0)
	{
		CopyBufferByPos(pBuffer, lPos1Begin, lPos1End, lGap);
	}

	if (lPos2Begin >= 0)
	{
		CopyBufferByPos(pBuffer+lPos1End-lPos1Begin, lPos2Begin, lPos2End, lGap);
	}

	lLenCopy = CalCopyBuffer(lLen, lGap, TRUE, lPos1Begin, lPos1End, lPos2Begin, lPos2End);
	
	return lLenCopy;
}

//pBuffer：源缓冲区
//lCopyBeginPos：源缓冲开始拷贝的位置
long CMemBuffer_Float::CopyBuffer(CMemBuffer_Float *pBuffer, long &lCopyBeginPos, long lGap)
{
	{
		float *pTemp = pBuffer->GetBuffer_float();
		if (pTemp[pBuffer->GetBufferLength()-1] == 0x0087)
		{
			int i = 0;
		}
	}
	//确保源缓冲区的长度小于等于目标缓冲区的长度
	ASSERT(pBuffer->m_nBufferLength <= m_nBufferLength);
	if(pBuffer->m_nBufferLength > m_nBufferLength)
	{
		return -1;
	}
	
	//
	if (pBuffer->m_nDataLength == 0)
	{
		return -1;
	}
	
	long lOffset = 0;
	long lLen = 0;
	long lCopyLen = 0;
	long lCopyLenRet = 0;
	float *pTemp = NULL;

	//当前填充的位置大于开始拷贝的位置，只需要拷贝源数据的一个区域
	//即从lCopyBeginPos到pBuffer->m_nDataFillBeginPos位置
	if (pBuffer->m_nDataFillBeginPos > lCopyBeginPos)
	{
		pTemp = pBuffer->GetBuffer_float() + lCopyBeginPos;
		lLen = pBuffer->GetDataFillBeginPosition() - lCopyBeginPos;
		lCopyLenRet = CopyBuffer(pTemp, lLen, lGap);

		lOffset = lLen - lCopyLenRet;

//		if (lCopyLenRet == 0)
//		{
//			lCopyBeginPos = lCopyBeginPos + lCopyLenRet;//下一次拷贝的位置=当前位置+实际拷贝的长度
//		}
//		else if (lCopyBeginPos > 0)
//		{
//			lCopyBeginPos = lCopyBeginPos + lCopyLenRet - lOffset + lGap;
//		}
//		else //(lCopyBeginPos < 0)
//		{
//			lCopyBeginPos = lCopyBeginPos + lCopyLenRet - lOffset;
//		}
		
		lCopyBeginPos = lCopyBeginPos + lCopyLenRet;//下一次拷贝的位置=当前位置+实际拷贝的长度
	}
	else
	{
		//总的长度
		long nTotalLen = pBuffer->GetDataLength() - lCopyBeginPos + pBuffer->GetDataFillBeginPosition();

		//第一次拷贝，拷贝到缓冲区结束位置
		pTemp = pBuffer->GetBuffer_float() + lCopyBeginPos;
		lLen = pBuffer->GetDataLength() - lCopyBeginPos;
		lCopyLen = CopyBuffer(pTemp, lLen, lGap);
		lOffset = lLen - lCopyLen;  //间隔拷贝过程中到缓冲区末尾剩下的长度
		lCopyLenRet = lCopyLen;

		//第二次拷贝
		lLen = nTotalLen - lCopyLen;

		//第二次开始拷贝的起始位置
		if(lOffset > 0)
		{
			pTemp = pBuffer->GetBuffer_float() - lOffset + lGap;
		}
		else if (lOffset == 0)
		{
			pTemp = pBuffer->GetBuffer_float();
		}
		else //lOffset < 0
		{
			pTemp = pBuffer->GetBuffer_float() - lOffset;
		}

		//下一次拷贝的位置=第二次实际拷贝的长度
		lCopyLen = CopyBuffer(pTemp, lLen, lGap);
		lCopyBeginPos = lCopyLen - lOffset; 
		lCopyLenRet += lCopyLen;
	}

	return lCopyLenRet*lGap;
}

//第三个参数的作用是TRUE修改索引地址，FALSE时获得地址
// long CMemBuffer_Float::CopyBuffer(long lLen, long lGap, BOOL bOffsetBuffer, long &lPos1Begin, long &lPos1End, long &lPos2Begin, long &lPos2End)
// {
// 	long lLenCopy = lLen / lGap;
// 	long nOffset = lLen - lLenCopy * lGap;
// 
// 	if (nOffset > 0)
// 	{
// 		lLenCopy++;
// 	}
// 
// 	long lEndPos = m_nDataFillBeginPos + lLenCopy; //目标缓冲区期望末位置
// 	long lLenCopy1 = 0, lLenCopy2 = 0;
// 	
// 	lPos1Begin = -1;
// 	lPos1End   = -1;
// 	lPos2Begin = -1;
// 	lPos2End   = -1;
// 	
// 	if (lEndPos < m_nBufferLength)
// 	{
// 		lPos1Begin = m_nDataFillBeginPos;
// 		lPos1End   = lEndPos;
// 		
// 		if (bOffsetBuffer)
// 		{
// 			m_nDataFillBeginPos = lEndPos;
// 		}
// 	}
// 	else 
// 	{
// 		//第一次拷贝,从m_nDataFillBeginPos到缓冲区末尾
// 		lLenCopy1 = m_nBufferLength - m_nDataFillBeginPos;
// 		lPos1Begin = m_nDataFillBeginPos;
// 		lPos1End   = m_nBufferLength;
// 		
// 		//第一次拷贝,从缓冲区开始到......
// 		lLenCopy2 = lLenCopy - lLenCopy1;
// 		lPos2Begin = 0;
// 		lPos2End   = lLenCopy2;
// 		
// 		if (bOffsetBuffer)
// 		{
// 			m_nDataFillBeginPos = lLenCopy2;
// 		}
// 		
// 	}
// 	
// 	if (bOffsetBuffer)
// 	{
// 		m_nDataLength += lLenCopy;
// 		
// 		if (m_nDataLength >= m_nBufferLength)
// 		{
// 			m_nDataLength = m_nBufferLength;
// 		}
// 	}
// 	
// 	return lLenCopy*lGap;
// }

long CMemBuffer_Float::CopyBufferByPos(float *pBuffer, long lBeginPos, long lEndPos, long lGap)
{
	ASSERT (lBeginPos >= 0 && lEndPos >= 0 && lEndPos >= lBeginPos);
	if (!(lBeginPos >= 0 && lEndPos >= 0 && lEndPos >= lBeginPos))
	{
		return 0;
	}

	float *pDest = NULL;
	float *pDestEnd = NULL;
	float *pSrc = NULL;
	float *pSrcEnd = NULL;	

	pDest = m_pBuffer + lBeginPos;
	
	if (lGap == 1)
	{
		memcpy(pDest, pBuffer, (lEndPos - lBeginPos)*sizeof(float));
	}
	else
	{
		pDestEnd = m_pBuffer + lEndPos;
		pSrc = pBuffer;
		
		while (pDest < pDestEnd)
		{
			*pDest = *pSrc;
			pDest++;
			pSrc += lGap;
		}
	}

	return lGap * (lEndPos - lBeginPos);
}


long CMemBuffer_Float::AddValue(float *pValue)
{
	return AddValue(*pValue);
}

long CMemBuffer_Float::AddValue(float fValue)
{
	m_pBuffer[m_nDataFillBeginPos] = fValue;
	
	if (m_nDataFillBeginPos + 1 < m_nBufferLength)
	{
		m_nDataFillBeginPos++;
	}
	else 
	{
		m_nDataFillBeginPos = 0;
	}

	m_nDataLength ++;

	if (m_nDataLength >= m_nBufferLength)
	{
		m_nDataLength = m_nBufferLength;
	}
	
	return 1;
}

// void CMemBuffer_Float::SetValue(long nIndex, float fValue)
// {
// 	m_pBuffer[nIndex] = fValue;
// // 	m_nDataFillBeginPos = nIndex
// }

void CMemBuffer_Float::FreeBuffer()
{
	if (m_pBuffer!= NULL)
	{
		delete m_pBuffer;
		m_pBuffer = NULL;
	}
	m_nBufferLength		= 0;	
	m_nDataFillBeginPos = 0;
	m_nDataLength		= 0;
}

double CMemBuffer_Float::GetCurrValue()
{
	double dValue = 0.0;

	if (m_nDataLength <= 1)
	{
		return dValue;
	}

	float *pBuffer = GetBuffer_float();
	long nValuePos = 0; 

	if (m_nDataLength == m_nBufferLength)
	{
		nValuePos = m_nDataFillBeginPos - 1;

		if (nValuePos < 1)
		{
			nValuePos = m_nBufferLength - 1;
		}
	}
	else
	{
		nValuePos = m_nDataFillBeginPos - 1;
	}

	dValue = *(pBuffer + nValuePos);

	return dValue;
}

/*
#ifdef _use_global_log_
void CMemBuffer_Float::LOG_ShowBuffer(BOOL bShowTitle)
{
	long nIndex = 0;
	CString strTemp;
	CString strData;

	if (bShowTitle)
	{
		strTemp.Format("BufferLen=%d  DataLen=%d  DataFill=%d", m_nBufferLength, m_nDataLength, m_nDataFillBeginPos);
		LOG_WriteLawString(strTemp);
	}

	for (nIndex=0; nIndex<m_nBufferLength; nIndex++)
	{
		strTemp.Format("%.3f ", m_pBuffer[nIndex]);
		strData += strTemp;
	}

	LOG_WriteLawString(strData);
}

#endif*/



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CComplexMemBuffer_Float::CComplexMemBuffer_Float()
{
	m_nSrcMemBufferCount = 0;
	long nIndex = 0;

	for (nIndex=0; nIndex<COMPLEX_MEMBUFFER_SRCBUF_MAXCOUNT; nIndex++)
	{
		m_pSrcBuffer[nIndex] = NULL;
	}

	m_pScript = new CRtComplexBufUShortFloatScript();
}

CComplexMemBuffer_Float::~CComplexMemBuffer_Float()
{
	if (m_pScript != NULL)
	{
		delete m_pScript;
		m_pScript = NULL;
	}

}

BOOL CComplexMemBuffer_Float::ExecScript(long nPos1Begin, long nPos1End, long nPos2Begin, long nPos2End)
{
	short nVal = 0;
	long nIndex = 0;

	for (nIndex=nPos1Begin; nIndex<nPos1End; nIndex++)
	{
		m_pScript->m_nIndex = nIndex;
		m_pScript->RunExpression(m_pBuffer[nIndex]);
	}

	for (nIndex=nPos2Begin; nIndex<nPos2End; nIndex++)
	{
		m_pScript->m_nIndex = nIndex;
		m_pScript->RunExpression(m_pBuffer[nIndex]);
	}

	return TRUE;
}
