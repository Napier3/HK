// GpsPcTime.cpp: implementation of the CGpsPcTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GpsPcTime.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGpsPcTimeSpan::CGpsPcTimeSpan(WORD wDay, WORD wHour, WORD wMinute, WORD wSecond, WORD wMilliseconds, WORD wMicroseconds)
{
	m_wDay    = 0; 
	m_wHour   = 0; 
	m_wMinute = 0; 
	m_wSecond = 0; 
	m_wMilliseconds = 0; 
	m_wMicroseconds = 0;		
	
	if (wMicroseconds >= 1000)
	{
		m_wMilliseconds = wMicroseconds / 1000;
		m_wMicroseconds = wMicroseconds % 1000;
	}
	else
	{
		m_wMicroseconds = wMicroseconds;
	}
	
	if (wMilliseconds >= 1000)
	{
		m_wMilliseconds += wMilliseconds % 1000;
		m_wSecond = wMilliseconds / 1000;
	}
	else
	{
		m_wMilliseconds += wMilliseconds;
	}

	if (wSecond >= 60)
	{
		m_wMinute = wSecond / 60;
		m_wSecond += wSecond % 60;
	}
	else
	{
		m_wSecond += wSecond;
	}
	
	if (wMinute >= 60)
	{
		m_wHour = wMinute / 60;
		m_wMinute += wMinute % 60;
	}
	else
	{
		m_wMinute += wMinute;
	}

	if (wHour >= 24)
	{
		m_wDay = wHour / 24;
		m_wHour = wHour % 24;
	}
	else
	{
		m_wHour += wHour;
	}

	m_wDay += wDay; 
	
}

void CGpsPcTimeSpan::Init()
{
	m_wDay    = 0; 
	m_wHour   = 0; 
	m_wMinute = 0; 
	m_wSecond = 0; 
	m_wMilliseconds = 0; 
	m_wMicroseconds = 0;	
}

CGpsPcTimeSpan::CGpsPcTimeSpan()
{
	Init();
}

CGpsPcTimeSpan::~CGpsPcTimeSpan()
{
	
}

void CGpsPcTimeSpan::InitByMilliseconds( long nMs)
{
	Init();

	long nTemp = nMs / 1000;

	if (nTemp == 0)
	{
		m_wMilliseconds = (WORD)nMs;
		return;
	}

	m_wMilliseconds = nMs % 1000;
	
	m_wSecond = nTemp % 60;

	if (nTemp == m_wSecond)
	{
		return;
	}

	nTemp /= 60;
	m_wMinute = nTemp % 60;

	if (m_wMinute == nTemp)
	{
		return;
	}

	nTemp /= 60;
	m_wHour = nTemp % 24;

	if (m_wHour == nTemp)
	{
		return;
	}

	m_wDay = (WORD)(nTemp / 24);
}

CGpsPcTimeSpan& CGpsPcTimeSpan::operator= (const CGpsPcTimeSpan &ts)
{
	//m_wYear   = ts.m_wYear;
	//m_wMonth  = ts.m_wMonth; 
	m_wDay    = ts.m_wDay; 
	m_wHour   = ts.m_wHour; 
	m_wMinute = ts.m_wMinute; 
	m_wSecond = ts.m_wSecond; 
	m_wMilliseconds = ts.m_wMilliseconds; 
	m_wMicroseconds = ts.m_wMicroseconds;	

	return *this;
}


DWORD CGpsPcTimeSpan::GetTotalSecond()
{
	DWORD dwSecond = m_wDay * 24;
	dwSecond += (dwSecond + m_wHour) * 60;
	dwSecond += (dwSecond + m_wMinute) * 60;
	dwSecond += m_wSecond;
	
	return dwSecond;
}

DWORD CGpsPcTimeSpan::GetTotalMilliseconds()
{
	DWORD dwSecond = m_wDay * 24;
	dwSecond += (dwSecond + m_wHour) * 60;
	dwSecond += (dwSecond + m_wMinute) * 60;
	dwSecond += m_wSecond;
	dwSecond = dwSecond * 1000 + m_wMilliseconds;
	return dwSecond;
}

CString CGpsPcTimeSpan::FormatString()
{
	CString strTime;	
	
	if (m_wDay > 0)
	{
		strTime.Format(_T("%d %d:%d:%d %d"), m_wDay, m_wHour, m_wMinute, m_wSecond, m_wMilliseconds);
	}
	else
	{
		strTime.Format(_T("%d:%d:%d %d"), m_wHour, m_wMinute, m_wSecond, m_wMilliseconds);
	}
	
	return strTime;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CGpsPcTime::CGpsPcTime()
{
	m_wYear   = 0;
	m_wMonth  = 0;
	m_wDay    = 0;
	m_wHour   = 0;
	m_wMinute = 0;
	m_wSecond = 0;
	m_wMilliseconds = 0;
	m_wMicroseconds = 0;
}

CGpsPcTime::CGpsPcTime(const GPSTIME &tm)
{
	m_wYear   = (short)tm.nYear; 
	m_wMonth  = (short)tm.nMonth; 
	m_wDay    = (short)tm.nDay; 
	m_wHour   = (short)tm.nHour; 
	m_wMinute = (short)tm.nMinute; 
	m_wSecond = (short)tm.nSecond; 
	m_wMilliseconds = (short)tm.nMilliseconds; 
	m_wMicroseconds = (short)tm.nMicroseconds;	
}

CGpsPcTime::CGpsPcTime(const PCTIME &tm)
{
	m_wYear   = (short)tm.nYear; 
	m_wMonth  = (short)tm.nMonth; 
	m_wDay    = (short)tm.nDay; 
	m_wHour   = (short)tm.nHour; 
	m_wMinute = (short)tm.nMinute; 
	m_wSecond = (short)tm.nSecond; 
	m_wMilliseconds = (short)tm.nMilliseconds; 
	m_wMicroseconds = 0;	
}

CGpsPcTime::CGpsPcTime(const SYSTEMTIME &tm)
{
	m_wYear   = (short)tm.wYear; 
	m_wMonth  = (short)tm.wMonth; 
	m_wDay    = (short)tm.wDay; 
	m_wHour   = (short)tm.wHour; 
	m_wMinute = (short)tm.wMinute; 
	m_wSecond = (short)tm.wSecond; 
	m_wMilliseconds = (short)tm.wMilliseconds; 
	m_wMicroseconds = 0;	
}

void CGpsPcTime::GetGpsPcTime(GPSTIME &oGpsPcTime)
{
	oGpsPcTime.nYear= m_wYear;
	oGpsPcTime.nMonth= m_wMonth; 
	oGpsPcTime.nDay= m_wDay; 
	oGpsPcTime.nHour= m_wHour; 
	oGpsPcTime.nMinute= m_wMinute; 
	oGpsPcTime.nSecond= m_wSecond; 
	oGpsPcTime.nMilliseconds= m_wMilliseconds; 
	oGpsPcTime.nMicroseconds= m_wMicroseconds;	
}

void CGpsPcTime::GetGpsPcTime(PCTIME &oGpsPcTime)
{
	oGpsPcTime.nYear= m_wYear;
	oGpsPcTime.nMonth= m_wMonth; 
	oGpsPcTime.nDay= m_wDay; 
	oGpsPcTime.nHour= m_wHour; 
	oGpsPcTime.nMinute= m_wMinute; 
	oGpsPcTime.nSecond= m_wSecond; 
	oGpsPcTime.nMilliseconds= m_wMilliseconds; 
}

CGpsPcTime::CGpsPcTime(WORD wYear, WORD wMonth, WORD wDay, WORD wHour, WORD wMinute, WORD wSecond, WORD wMilliseconds, WORD wMicroseconds)
{
	m_wYear   = wYear; 
	m_wMonth  = wMonth; 
	m_wDay    = wDay; 
	m_wHour   = wHour; 
	m_wMinute = wMinute; 
	m_wSecond = wSecond; 
	m_wMilliseconds = wMilliseconds; 
	m_wMicroseconds = wMicroseconds;	
}

CGpsPcTime::~CGpsPcTime()
{

}

//目前之处理如下两种格式的时间
//时间的格式：YY*MM*DD hh:mm:ss.ms.us
//hh:mm:ss.ms.us



BOOL  CGpsPcTime::FromString(const CString &strTime)
{
	CBufferBase oBuffer(strTime);
	char *pBufferBegin = oBuffer.GetBufferBeginPos();
	char *pTimePos = NULL;
	char *pTemp = NULL;

	char *pEnd = oBuffer.GetBufferEndPos();
	pTemp = pBufferBegin;

	while (pTemp < pEnd)
	{
		if ( !  ('0' <= *pTemp && *pTemp <= '9') )
		{
			*pTemp = 0;
		}

		pTemp++;
	}

	GetYyMmDd(oBuffer);
	GetTime(oBuffer);


// 
// 	//查找第一个":"，表示时间的起始位置
// 	pTemp = pBufferBegin;
// 
// 	while (*pTemp != 0)
// 	{
// 		if (*pTemp == ':' || *pTemp == '.')
// 		{
// 			pTimePos = pTemp;
// 			break;
// 		}
// 
// 		pTemp++;
// 	}
// 
// 	if (pTimePos == NULL)
// 	{
// 		return FALSE;
// 	}
// 
// 	pTimePos--;
// 
// 	//获得时间起始位置
// 	while ('0' <= *pTimePos && *pTimePos <= '9')
// 	{
// 		pTimePos--;
// 	}
// 
// 	if (pTimePos < pBufferBegin)
// 	{
// 		pTimePos = pBufferBegin;
// 	}
// 
// 	//处理时分秒毫秒等
// 	if ( ! ('0' <= *pTimePos && *pTimePos <= '9') )
// 	{
// 		pTemp = pTimePos + 1;
// 	}
// 	else
// 	{
// 		pTemp = pTimePos;
// 	}
// 
// 	char *pVal = pTemp;
// 	char *pEnd = oBuffer.GetBufferEndPos();
// 
// 	GetTime(pTemp, pEnd);
// 
// 	//处理年月日
// 	GetYyMmDd(pBufferBegin, pTimePos);

	return TRUE;
}

BOOL  CGpsPcTime::FromStringEx(const CString &strTime)
{
	FromString(strTime);
// 	CBufferBase oBuffer(strTime);
// 	char *pBufferBegin = oBuffer.GetBufferBeginPos();
// 
// 	char *pCurr = pBufferBegin;
// 	char *pEnd = oBuffer.GetBufferEndPos();
// 
// 	long nLen = GetLongValue(pCurr, m_wYear, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMonth, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wDay, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wHour, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMinute, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wSecond, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMilliseconds, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMicroseconds, pEnd);

	return TRUE;
}

void CGpsPcTime::ToString(CString &strTime)
{
	strTime.Format(_T("%d-%d-%d %d:%d:%d"), m_wYear, m_wMonth, m_wDay, m_wHour, m_wMinute, m_wSecond);
}

void CGpsPcTime::GetSysTime(SYSTEMTIME &tm)
{
	tm.wYear = m_wYear;
	tm.wMonth = m_wMonth;
	tm.wDay = m_wDay;
	tm.wHour = m_wHour;
	tm.wMinute = m_wMinute;
	tm.wSecond = m_wSecond;
	tm.wMilliseconds = m_wMilliseconds;
}

long CGpsPcTime::GetTime(CBufferBase &oBuffer)//char *pCurr, char *pEnd)
{
	if (GetLongValue(oBuffer, m_wHour) == -1)
	{
		return -1;
	}

	if (GetLongValue(oBuffer, m_wMinute) == -1)
	{
		return -1;
	}

	if (GetLongValue(oBuffer, m_wSecond) == -1)
	{
		return -1;
	}

	if (GetLongValue(oBuffer, m_wMilliseconds) == -1)
	{
		return -1;
	}
// 
// 	long nLen = GetLongValue(pCurr, m_wHour, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMinute, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wSecond, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMilliseconds, pEnd);
// 
// 	if (nLen < 0)
// 	{
// 		return 0;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMicroseconds, pEnd);

	return 0;
}

long CGpsPcTime::GetYyMmDd(CBufferBase &oBuffer)//char *pCurr, char *pEnd)
{
	if (GetLongValue(oBuffer, m_wYear) == -1)
	{
		return -1;
	}

	if (GetLongValue(oBuffer, m_wMonth) == -1)
	{
		return -1;
	}

	if (GetLongValue(oBuffer, m_wDay) == -1)
	{
		return -1;
	}

	return 0;
// 
// 	long nOffset = 0;
// 	long nLen = GetLongValue(pCurr, m_wYear, pEnd);
// 	nOffset += nLen;
// 
// 	if (nLen < 0)
// 	{
// 		return nOffset;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wMonth, pEnd);
// 	nOffset += nLen;
// 
// 	if (nLen < 0)
// 	{
// 		return nOffset;
// 	}
// 
// 	pCurr += nLen;
// 	nLen = GetLongValue(pCurr, m_wDay, pEnd);
// 	nOffset += nOffset;
// 
// 	return nOffset;
}

long CGpsPcTime::GetLongValue( CBufferBase &oBuffer, short &nValue)//char *pCurr, short &nValue, char *pEnd)
{
	if (!oBuffer.IsPoiterInBuffer())
	{
		return -1;
	}

	char *pString = oBuffer.GetString();
	nValue = (short)atol(pString);
	oBuffer.NextString();
	
	return 0;
// 	char *pTemp = pCurr;
// 	long nLen = 0;
// 
// 	if (pTemp > pEnd)
// 	{
// 		return -1;
// 	}
// 
// 	while ('0' <= *pTemp && *pTemp <= '9')
// 	{
// 		pTemp++;
// 	}
// 
// 	if (pTemp > pEnd)
// 	{
// 		return -1;
// 	}
// 
// 	*pTemp = 0;
// 	nValue = (short)atol(pCurr);
// 
// 	while (pTemp < pEnd)
// 	{
// 		if ( !  ('0' <= *pTemp && *pTemp <= '9') )
// 		{
// 			*pTemp = 0;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 
// 		pTemp++;
// 	}
// 
// 	return pTemp - pCurr;
}

CGpsPcTime& CGpsPcTime::operator= (const CGpsPcTime &tm)
{
	m_wYear   = tm.m_wYear; 
	m_wMonth  = tm.m_wMonth; 
	m_wDay    = tm.m_wDay; 
	m_wHour   = tm.m_wHour; 
	m_wMinute = tm.m_wMinute; 
	m_wSecond = tm.m_wSecond; 
	m_wMilliseconds = tm.m_wMilliseconds; 
	m_wMicroseconds = tm.m_wMicroseconds;	

	return *this;
}

//CGpsPcTimeSpan CGpsPcTime::operator-= (const CGpsPcTime &tm)
//{
//	CGpsPcTimeSpan ts;
//	return ts;
//}

void CGpsPcTime::AdjustSub(BOOL bUseDayZero)
{
	if (m_wMilliseconds < 0)
	{
		m_wMilliseconds = 1000 + m_wMilliseconds;
		m_wSecond--;
	}

	if (m_wSecond < 0)
	{
		m_wSecond = 60 + m_wSecond;
		m_wMinute--;
	}
	
	if (m_wMinute < 0)
	{
		m_wMinute = 60 + m_wMinute;
		m_wHour--;
	}
	
	if (m_wHour < 0)
	{
		m_wHour = 24 + m_wHour;
		m_wDay--;
	}
	
	if (bUseDayZero)
	{
		if (m_wDay < 0)
		{
			m_wMonth--;
			
			if (m_wMonth > 0)
			{
				m_wDay = Mr_GetDaysOfMonth(m_wYear, m_wMonth);
			}
			else
			{
				m_wDay = 31; //前一年的12月
			}
		}
	}
	else
	{
		if (m_wDay <= 0)
		{
			m_wMonth--;

			if (m_wMonth > 0)
			{
				m_wDay = Mr_GetDaysOfMonth(m_wYear, m_wMonth);
			}
			else
			{
				m_wDay = 31; //前一年的12月
			}
		}
	}
	
	
	if (m_wMonth <= 0)
	{
		m_wMonth = 12;
		m_wYear--;
	}
}


void CGpsPcTime::AdjustAdd()
{
	if (m_wMilliseconds >= 1000)
	{
		m_wMilliseconds -= 1000;
		m_wSecond++;
	}

	if (m_wSecond >= 60)
	{
		m_wSecond -= 60;
		m_wMinute++;
	}
	
	if (m_wMinute >= 60)
	{
		m_wMinute -= 60;
		m_wHour++;
	}
	
	if (m_wHour >= 24)
	{
		m_wHour -= 24;
		m_wDay++;
	}
	
	WORD dDay = 0;
	
	if (m_wMonth > 0) 
	{
		dDay = Mr_GetDaysOfMonth(m_wYear, m_wMonth);
	}

	if (m_wDay > dDay)
	{
		m_wDay = 1;
		m_wMonth++;
	}
	
	if (m_wMonth > 12)
	{
		m_wMonth = 1;
		m_wYear++;
	}
}

CGpsPcTime& CGpsPcTime::operator-= (const CGpsPcTimeSpan &ts)
{
	int tmpVal = 0;
	if (m_wMicroseconds < ts.m_wMicroseconds)
	{
		tmpVal = ts.m_wMicroseconds;
		while (m_wMicroseconds < tmpVal)
		{
			m_wMicroseconds = 1000 + m_wMicroseconds - tmpVal;
			m_wMilliseconds--;
			AdjustSub();

			tmpVal = tmpVal-1000;
		}
	}
	else
	{
		m_wMicroseconds -= ts.m_wMicroseconds;
	}

	if (m_wMilliseconds < ts.m_wMilliseconds)
	{
		tmpVal = ts.m_wMilliseconds;
		while (m_wMilliseconds < tmpVal)
		{
			m_wMilliseconds = 1000 + m_wMilliseconds - tmpVal;
			m_wSecond--;
			AdjustSub();

			tmpVal = tmpVal-1000;
		}
	}
	else
	{
		m_wMilliseconds -= ts.m_wMilliseconds;
	}

	if (m_wSecond < ts.m_wSecond)
	{
		tmpVal = ts.m_wSecond;
		while (m_wSecond < tmpVal)
		{
			m_wSecond = 60 + m_wSecond - tmpVal;
			m_wMinute--;
			AdjustSub();

			tmpVal = tmpVal-60;
		}
	}
	else
	{
		m_wSecond -= ts.m_wSecond;
	}

	if (m_wMinute < ts.m_wMinute)
	{
		tmpVal = ts.m_wMinute;
		while (m_wMinute < tmpVal)
		{
			m_wMinute = 60 + m_wMinute - tmpVal;
			m_wHour--;
			AdjustSub();

			tmpVal = tmpVal-60;
		}
	}
	else
	{
		m_wMinute -= ts.m_wMinute;
	}

	if (m_wHour < ts.m_wHour)
	{
		tmpVal = ts.m_wHour;
		while (m_wHour < tmpVal)
		{
			m_wHour = 24 + m_wHour - tmpVal;
			m_wDay--;
			AdjustSub();

			tmpVal = tmpVal-24;
		}
	}
	else
	{
		m_wHour -= ts.m_wHour;
	}

	while(m_wDay < ts.m_wDay)
	{
		m_wMonth--;

		if (m_wMonth < 1)
		{
			m_wMonth = 12;
			m_wYear--;
		}

		m_wDay = Mr_GetDaysOfMonth(m_wYear, m_wMonth) + m_wDay;
	}
	m_wDay -= ts.m_wDay;

	return *this;
}

CGpsPcTime& CGpsPcTime::operator+= (const CGpsPcTimeSpan &ts)
{
	m_wMicroseconds += ts.m_wMicroseconds;

	while (m_wMicroseconds >= 1000)
	{
		m_wMicroseconds -= 1000;
		m_wMilliseconds++;
		AdjustAdd();
	}
	
	m_wMilliseconds += ts.m_wMilliseconds;
	
	while (m_wMilliseconds >= 1000 )
	{
		m_wMilliseconds -= 1000;
		m_wSecond++;
		AdjustAdd();
	}
	
	m_wSecond += ts.m_wSecond;
	while (m_wSecond >= 60 )
	{
		m_wSecond -= 60;
		m_wMinute++;
		AdjustAdd();
	}

	m_wMinute += ts.m_wMinute;
	
	while (m_wMinute >= 60)
	{
		m_wMinute -= 60;
		m_wHour++;
		AdjustAdd();
	}

	m_wHour += ts.m_wHour;

	while (m_wHour >= 24)
	{
		m_wHour -= 24;
		m_wDay++;
		AdjustAdd();
	}
	
	m_wDay += ts.m_wDay;
	while (1)
	{
		WORD dDay = Mr_GetDaysOfMonth(m_wYear, m_wMonth);

		if (m_wDay > dDay)
		{
			m_wDay = m_wDay - dDay;
			m_wMonth++;

			if (m_wMonth > 12)
			{
				m_wMonth -= 12;
				m_wYear++;
			}
		}
		else
		{
			break;
		}
	}
	
	
	
//	m_wMonth += ts.m_wMonth;
//
//	if (m_wMonth > 12)
//	{
//		m_wMonth -= 12;
//		m_wYear++;
//	}
	
	return *this;
}

CGpsPcTimeSpan CGpsPcTime::operator- (const CGpsPcTime &tm)
{
	CGpsPcTimeSpan ts;
	ts.m_wDay = tm.m_wDay;
	ts.m_wHour = tm.m_wHour;
	ts.m_wMinute = tm.m_wMinute;
	ts.m_wSecond = tm.m_wSecond;
	ts.m_wMilliseconds = tm.m_wMilliseconds;
	ts.m_wMicroseconds = tm.m_wMicroseconds;
	
	CGpsPcTime tmSrc = *this;
	tmSrc -= ts;
	tmSrc.AdjustSub(TRUE);
	
	ts.m_wDay = tmSrc.m_wDay;
	ts.m_wHour = tmSrc.m_wHour;
	ts.m_wMinute = tmSrc.m_wMinute;
	ts.m_wSecond = tmSrc.m_wSecond;
	ts.m_wMilliseconds = tmSrc.m_wMilliseconds;
	ts.m_wMicroseconds = tmSrc.m_wMicroseconds;
	
	return ts;
}


BOOL CGpsPcTime::operator> (const CGpsPcTime &tm)
{
	if (m_wYear > tm.m_wYear)
	{
		return TRUE;
	}
	else if (m_wYear < tm.m_wYear)
	{
		return FALSE;
	}

	if (m_wMonth > tm.m_wMonth)
	{
		return TRUE;
	}
	else if (m_wMonth < tm.m_wMonth)
	{
		return FALSE;
	}

	if (m_wDay > tm.m_wDay)
	{
		return TRUE;
	}
	else if (m_wDay < tm.m_wDay)
	{
		return FALSE;
	}

	if (m_wHour > tm.m_wHour)
	{
		return TRUE;
	}
	else if (m_wHour < tm.m_wHour)
	{
		return FALSE;
	}

	if (m_wMinute > tm.m_wMinute)
	{
		return TRUE;
	}
	else if (m_wMinute < tm.m_wMinute)
	{
		return FALSE;
	}

	if (m_wSecond > tm.m_wSecond)
	{
		return TRUE;
	}
	else if (m_wSecond < tm.m_wSecond)
	{
		return FALSE;
	}

	if (m_wMilliseconds > tm.m_wMilliseconds)
	{
		return TRUE;
	}
	else if (m_wMilliseconds < tm.m_wMilliseconds)
	{
		return FALSE;
	}

	if (m_wMicroseconds > tm.m_wMicroseconds)
	{
		return TRUE;
	}
	
	return FALSE;
}

BOOL CGpsPcTime::operator>= (const CGpsPcTime &tm)
{
	return ! (*this < tm);
}

BOOL CGpsPcTime::operator< (const CGpsPcTime &tm)
{
	if (m_wYear < tm.m_wYear)
	{
		return TRUE;
	}
	else if (m_wYear > tm.m_wYear)
	{
		return FALSE;
	}
	
	if (m_wMonth < tm.m_wMonth)
	{
		return TRUE;
	}
	else if (m_wMonth > tm.m_wMonth)
	{
		return FALSE;
	}
	
	if (m_wDay < tm.m_wDay)
	{
		return TRUE;
	}
	else if (m_wDay > tm.m_wDay)
	{
		return FALSE;
	}
	
	if (m_wHour < tm.m_wHour)
	{
		return TRUE;
	}
	else if (m_wHour > tm.m_wHour)
	{
		return FALSE;
	} 
	
	if (m_wMinute < tm.m_wMinute)
	{
		return TRUE;
	}
	else if (m_wMinute > tm.m_wMinute)
	{
		return FALSE;
	}
	
	if (m_wSecond < tm.m_wSecond)
	{
		return TRUE;
	}
	else if (m_wSecond > tm.m_wSecond)
	{
		return FALSE;
	}
	
	if (m_wMilliseconds < tm.m_wMilliseconds)
	{
		return TRUE;
	}
	else if (m_wMilliseconds > tm.m_wMilliseconds)
	{
		return FALSE;
	}
	
	if (m_wMicroseconds < tm.m_wMicroseconds)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL CGpsPcTime::operator<= (const CGpsPcTime &tm)
{
	return ! (*this > tm);
}

BOOL CGpsPcTime::operator== (const CGpsPcTime &tm)
{
	if (m_wYear != tm.m_wYear)
	{
		return FALSE;
	}
	
	if (m_wMonth != tm.m_wMonth)
	{
		return FALSE;
	}
	
	if (m_wDay != tm.m_wDay)
	{
		return FALSE;
	}
	
	if (m_wHour != tm.m_wHour)
	{
		return FALSE;
	}
	
	if (m_wMinute != tm.m_wMinute)
	{
		return FALSE;
	}
	
	if (m_wSecond != tm.m_wSecond)
	{
		return FALSE;
	}
	
	if (m_wMilliseconds != tm.m_wMilliseconds)
	{
		return FALSE;
	}
	
	if (m_wMicroseconds != tm.m_wMicroseconds)
	{
		return FALSE;
	}
	
	return TRUE;
}

DWORD CGpsPcTime::GetTotalSecond()
{
	DWORD dwSecond = m_wDay * 24;
	dwSecond += (dwSecond + m_wHour) * 60;
	dwSecond += (dwSecond + m_wMinute) * 60;
	dwSecond += m_wSecond;
	return dwSecond;
}

DWORD CGpsPcTime::GetTotalMilliseconds()
{
	DWORD dwSecond = m_wDay * 24;
	dwSecond += (dwSecond + m_wHour) * 60;
	dwSecond += (dwSecond + m_wMinute) * 60;
	dwSecond += m_wSecond;
	dwSecond += dwSecond * 1000 + m_wMilliseconds;
	return dwSecond;
}

__time64_t CGpsPcTime::GetTime_Int64()
{
	SYSTEMTIME tmSys;
	tmSys.wYear = m_wYear;
	tmSys.wMonth = m_wMonth;
	tmSys.wDay   = m_wDay;
	tmSys.wHour  = m_wHour;
	tmSys.wMinute = m_wMinute;
	tmSys.wSecond = m_wSecond;
	tmSys.wMilliseconds = m_wMilliseconds;

	CTime tm(tmSys);

	return tm.GetTime();
}

double CGpsPcTime::GetTime_double()
{
	return (double)GetTime_Int64();
}

CGpsPcTimeTickCount::CGpsPcTimeTickCount()
{
	Enter();
}

CGpsPcTimeTickCount::~CGpsPcTimeTickCount()
{

}
void CGpsPcTimeTickCount::Enter()
{
	InitByLocalTime(m_oGpsPcTime);
}

long CGpsPcTimeTickCount::GetTickCountLong(BOOL bUdate)
{
	CGpsPcTime tmCurr;
	InitByLocalTime(tmCurr);
	CGpsPcTimeSpan ts = tmCurr - m_oGpsPcTime;
	long nMs = ts.GetTotalMilliseconds();

	if (bUdate)
	{
		InitByLocalTime(m_oGpsPcTime);
	}

	return nMs;
}

void CGpsPcTimeTickCount::InitByLocalTime(CGpsPcTime &tmGps)
{
	SYSTEMTIME tmSys;
	::GetLocalTime(&tmSys);

	tmGps.m_wYear    = tmSys.wYear;
	tmGps.m_wMonth   = tmSys.wMonth; 
	tmGps.m_wDay     = tmSys.wDay; 
	tmGps.m_wHour    = tmSys.wHour; 
	tmGps.m_wMinute  = tmSys.wMinute; 
	tmGps.m_wSecond  = tmSys.wSecond; 
	tmGps.m_wMilliseconds  = tmSys.wMilliseconds; 
	tmGps.m_wMicroseconds  = 0;
}