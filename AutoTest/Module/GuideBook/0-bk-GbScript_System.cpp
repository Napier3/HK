#include "StdAfx.h"
#include "GbScript_System.h"

//Lua
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "luabind.hpp"
#include "../XLanguageResourceAts.h"

#include "../../../Module/API/FileApi.h"	//yyj
#include "math.h"

extern lua_State* g_pGuideBookLua;
extern char g_pLuaReturnString[MAX_PATH];


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 在调试监视信息中显示消息
// pszMsg：消息文本/消息ID
void GBS_ShowMessage(const  char* pszMsg)
{
	CLogPrint::LogString(XLOGLEVEL_INFOR, CString(pszMsg));
}

// 播放音乐文件
// pszFile：音乐文件
// nTimes：播放次数		 0<=表示循环播放 	>0表示实际播放的次数
void GBS_PlayMusicFile(const  char* pszFileName, long nTimes)
{
	
}

const char* GBS_GetTime()
{
	SYSTEMTIME tmSys;
	::GetLocalTime(&tmSys);

	sprintf(g_pLuaReturnString, "%d-%d-%d %d:%d:%d %d", tmSys.wYear, tmSys.wMonth, tmSys.wDay
		, tmSys.wHour, tmSys.wMinute, tmSys.wSecond, tmSys.wMilliseconds);

	return g_pLuaReturnString;
}


double GBS_IEC(double dValue, double dTp, double dK, double dAlpha)
{
	double dT = dTp * dK / (pow(dValue, dAlpha) - 1);
	return dT;
}

double GBS_IEEE(double dValue, double dTp, double dA, double dB, double dP, double dQ, double dK1, double dK2)
{
	double dT = (dA * dTp + dK1) / ( pow(dValue, dP) - dQ) + dB * dTp + dK2;
	return dT;
}

double GBS_IAC(double dValue, double dTp, double dA, double dB, double dC, double dD, double dE, double dBeta)
{
	double d = dValue - dC;
	double dT = dA + dB / d + dD / (d * d) + dE / (d*d*d);
	dT = dT * (dTp / dBeta);
	return dT;
}

double GBS_I2T(double dValue, double dTp, double dA)
{
	double dT = dTp * dA / (dValue * dValue);
	return dT;
}

long GBS_CmpDouble(const char *pszVal1, const char *pszVal2, const char *pszPrecision)
{
	double dVal1 = atof(pszVal1);
	double dVal2 = atof(pszVal2);
	double dPrecision = atof(pszPrecision);

	dPrecision = fabs(dPrecision);

	if (fabs(dVal1 - dVal2) > dPrecision)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

long GBS_CmpDoubleVal(double dVal1, double dVal2, double dPrecision)
{
	if (fabs(dVal1 - dVal2) > dPrecision)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


double GBS_CalRelError(double dAbsErr, double dRefVal)
{
	if (dRefVal <= 0.00001)
	{
		return fabs(dAbsErr);
	}
	else
	{
		return fabs(dAbsErr / dRefVal);
	}
}

long GBS_dllLoad(const char *pszDllFilePath, const char *pszDllID)
{
	return 0;
}

long GBS_dllCall(const char *pszDllID, const char *pszPara)
{
	return 0;
}

long GBS_dllReadDatas(const char *pszDllID, const char *pszPara)
{
	return 0;
}

long GBS_dllUnload(const char *pszDllID)
{
	return 0;
}


//EXE调用
long GBS_RunExe(const char *pszExeFile, const char *pszPara)
{
	CString strExeFile;
	CString strPara;
	strExeFile = pszExeFile;
	strPara = pszPara;

	if (strExeFile.Find(_T(":\\")) > 0)
	{

	}
	else
	{
		CString strBin;
		strBin = _P_GetBinPath();
		strExeFile = strBin + strExeFile;
	}

	//ShellExecute(NULL,_T("open"), strExeFile, strPara, NULL, SW_SHOWNORMAL);
	ExecuteFile(strExeFile, strPara, _T("single"));
	return 0;
}

long GBS_ExitExe(const char *pszExeFile)
{
	CString strExeFile;
	strExeFile = pszExeFile;

	if (strExeFile.GetLength() < 4)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_TRACE, CXLanguageResourceAtsBase::g_sLangTxt_ParaError2/*_T("ExitExe(\"%s\")参数错误")*/ , strExeFile);
		return 0;
	}

	TerminateProgram(strExeFile);
	return 0;
}

void GBS_AddLocalTime(long nHour, long nMinute, long nSecond)
{
	SYSTEMTIME tmSys;
	::GetLocalTime(&tmSys);

	CTime tm(tmSys);
	CTimeSpan ts(0, nHour, nMinute, nSecond);

	tm += ts;
	tm.GetAsSystemTime(tmSys);
	::SetLocalTime(&tmSys);
}


void GBS_SubLocalTime(long nHour, long nMinute, long nSecond)
{
	SYSTEMTIME tmSys;
	::GetLocalTime(&tmSys);

	CTime tm(tmSys);
	CTimeSpan ts(0, nHour, nMinute, nSecond);

	tm -= ts;
	tm.GetAsSystemTime(tmSys);
	::SetLocalTime(&tmSys);
}

#define RAND_RANG_MAX  10000

long GBS_RandLong(long nMin, long nMax)
{
	long nRange = nMax - nMin;

	long nRand = rand();
	nRand = nRand % RAND_RANG_MAX;;

	float fRate = nRand;
	fRate /= RAND_RANG_MAX;

	float fValue = nMin + nRange * fRate;

	return (long)fValue;
}

float GBS_RandFloat(float fMin, float fMax)
{
	float fRange = fMax - fMin;

	long nRand = rand();
	nRand = nRand % RAND_RANG_MAX;;
	float fRate = nRand;
	fRate /= RAND_RANG_MAX;

	float fValue = fMin + fRange * fRate;

	return fValue;
}

double GBS_RandDouble(double fMin, double fMax)
{
	double fRange = fMax - fMin;

	long nRand = rand();
	nRand = nRand % RAND_RANG_MAX;;
	double fRate = nRand;
	fRate /= RAND_RANG_MAX;

	double fValue = fMin + fRange * fRate;

	return fValue;
}

void GBS_RandSeed()
{
	srand(time(0));
}

const char* GBS_GetFileNameFromPath(const char *pszPath)
{
	if (pszPath == NULL)
	{
		g_pLuaReturnString[0] = 0;
		return g_pLuaReturnString;
	}

	CString strFile, strPath;
	strPath = pszPath;

	strFile = GetPathFileNameFromFilePathName(strPath);

	if (strFile.GetLength() == 0)
	{
		strFile = GetPathFileNameFromFilePathName(strPath, '/');
	}

	if (strFile.Find('/') > 0)
	{
		strFile = GetPathFileNameFromFilePathName(strPath, '/');
	}

	CString_to_char(strFile, g_pLuaReturnString);

	return g_pLuaReturnString;
}

const char* GBS_ParseFilePostfix(const char* pszFileName)
{
	if (pszFileName == NULL)
	{
		g_pLuaReturnString[0] = 0;
		return g_pLuaReturnString;
	}

	const char *pFind = strrchr(pszFileName, '.');

	if (pFind == NULL)
	{
		g_pLuaReturnString[0] = 0;
	}
	else
	{
		pFind++;
		strcpy(g_pLuaReturnString, pFind);
	}

	return g_pLuaReturnString;
}

const char* GBS_ParseFileName(const char *pszFileName)
{
	if (pszFileName == NULL)
	{
		g_pLuaReturnString[0] = 0;
		return g_pLuaReturnString;
	}

	CString strFile, strFileName;
	strFileName = pszFileName;
	strFile = GetPathFileNameFromFilePathName(strFileName);

	if (strFile.GetLength() == 0)
	{
		strFile = strFileName;
	}

	if (strFile.Find('/') > 0)
	{
		strFile = GetPathFileNameFromFilePathName(strFile, '/');
	}

	long nPos = strFile.ReverseFind('.');

	if (nPos >= 0)
	{
		strFileName = strFile.Left(nPos);
		CString_to_char(strFileName, g_pLuaReturnString);
	}
	else
	{
		CString_to_char(strFile, g_pLuaReturnString);
	}

	return g_pLuaReturnString;
}

long GBS_SubStrToLong(const char *pszString, long nBegin, long nLen)
{
	if (pszString == NULL)
	{
		return 0;
	}

	const char *p = GBS_SubStrToStr(pszString, nBegin, nLen);

	if (*p == 0)
	{
		return 0;
	}
	else
	{
		return atol(p);
	}
}

const char* GBS_SubStrToStr(const char *pszString, long nBegin, long nLen)
{
	g_pLuaReturnString[0] = 0;

	if (pszString == NULL)
	{
		return g_pLuaReturnString;
	}

	long nStrLen = strlen(pszString);

	if (nBegin >= nStrLen)
	{
		return g_pLuaReturnString;
	}

	if (nBegin < 0)
	{
		nBegin = 0;
	}

	if (nBegin + nLen >= nStrLen)
	{
		nLen = nStrLen - nBegin;
	}

	if (nLen < 0)
	{
		nLen = nStrLen - nBegin;
	}

	memcpy(g_pLuaReturnString, pszString+nBegin, nLen);
	g_pLuaReturnString[nLen] = 0;

	return g_pLuaReturnString;
}

long GBS_GetSecondsFromMidnight()
{
	SYSTEMTIME tmSys;
	::GetLocalTime(&tmSys);
	long nSeconds = tmSys.wSecond + tmSys.wMinute * 60 + tmSys.wHour * 3600;

	return nSeconds;
}

