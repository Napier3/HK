#ifndef _STPUBLICFUN_H
#define _STPUBLICFUN_H
#include <xstring>
#include "..\stdatadef.h"

long ST_StringToHex(CString strHex);
std::string WChar2Ansi(LPCWSTR wstr);
__int64 my_HexToDec(CString strHex,int nLength);
void Hex2CString(CString& strInText, CString& strOutText, UINT len);
CString StrToMACAddress(CString& strText);
// time_t×ª×Ö·û´®¸ñÊ½
void timeToString(time_t t,double tms,CString& strout);

time_t systime_to_timet(const SYSTEMTIME& st);

void my_ConvertRecvMsgToString(BYTE *byRecvBuf, int nRecvLen, CString &strMsg);


void InitMUMSGCfgData(LPCTSTR lpstr,MuCfgData* const UIs,vector<MU_CHNSET>& chnset);

inline float AdjustAngle(float fAngle)
{
	while (fAngle > 360)
	{
		fAngle -= 360;
	}

	while (fAngle <- 360)
	{
		fAngle += 360;
	}

	return fAngle;
}

#endif