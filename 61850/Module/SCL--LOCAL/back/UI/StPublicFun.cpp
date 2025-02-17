#include "stdafx.h"
#include "StPublicFun.h"
#include <math.h>

long ST_StringToHex(CString strHex)
{
	long outvalue,tempval;
	int oneval;

	strHex.MakeUpper();
	if(strHex.Find(_T("X"))==1)
		strHex.TrimLeft(_T("0X"));
	strHex.TrimRight();
	int strlong=strHex.GetLength();
	outvalue=0;
	for (int i=0;i<strlong;i++)
	{
		char charDec=(char)strHex.GetAt(strlong-1-i);
		switch(charDec)
		{
		case 97:
		case 65:
			oneval=10;
			break;
		case 98:
		case 66:
			oneval=11;
			break;
		case 99:
		case 67:
			oneval=12;
			break;
		case 100:
		case 68:
			oneval=13;
			break;
		case 101:
		case 69:
			oneval=14;
			break;
		case 102:
		case 70:
			oneval=15;
			break;
		default:
			oneval=charDec-48;
			break;
		}
		tempval=(long)pow(16.0f,i);
		outvalue+=oneval*tempval;
	}
	return outvalue;
}

__int64 my_HexToDec(CString strHex,int nLength)
{
	int i,j;
	__int64 DecNum;
	CString temp;
	char charDec;
	int nDeci;
	i=strHex.Find(_T("x"),0);
	DecNum=0;

	for (j=nLength-1;j>=0;j--)
	{
		i++;
		charDec=strHex.GetAt(i);
		switch(charDec)
		{
		case 97:
		case 65:
			nDeci=10;
			break;
		case 98:
		case 66:
			nDeci=11;
			break;
		case 99:
		case 67:
			nDeci=12;
			break;
		case 100:
		case 68:
			nDeci=13;
			break;
		case 101:
		case 69:
			nDeci=14;
			break;
		case 102:
		case 70:
			nDeci=15;
			break;
		default:
			nDeci=charDec-48;
			break;
		}
		DecNum+=(__int64)ldexp(nDeci+0.0f,j*4);
	}


	return DecNum;
}


void Hex2CString(CString& strInText, CString& strOutText, UINT len)
{

	if (len <= 0) return;
	int j,strLen,it;
	static int nu[23]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15};
	j = strLen = it = 0;

	TCHAR ch;
	BYTE* pbt = new BYTE[len+1];

	strInText.MakeUpper();
	strInText.TrimLeft(_T("0X"));
	ZeroMemory(pbt, len);

	strLen = strInText.GetLength();
	for(int i=0; i<strLen; i++,j++)
	{
		ch = strInText.GetAt(i);

		if(ch<'0' || ch>'F' )
		{
			j--;
			continue;
		}
		it = nu[ch-'0'];
		pbt[j/2] |= it<<(((j+1)%2)*4);
	}

	pbt[6] = '\0';
	CString strText(pbt);
	strOutText = strText;
	delete []pbt;
}

std::string WChar2Ansi(LPCWSTR wstr)
{
	std::string str;

	//得到需要空间大小
	int nlen = WideCharToMultiByte(0,0,wstr,-1,NULL,0,NULL,NULL);
	if(nlen <= 0)
		str = std::string("");
	else{
		//开辟空间
		PSTR ps = new CHAR[nlen];
		//转化成多字节
		WideCharToMultiByte(0,0,wstr,-1,ps,nlen,NULL,NULL);
		str = std::string(ps);
		//释放空间
		delete[] ps;
	}

	return str;
}

CString StrToMACAddress(CString& strText)
{
	CString strMac = _T("");
	TCHAR ch[12];
	memset(ch,0,sizeof(TCHAR)*12);
	int nCount = 0;
	UINT nLen = strText.GetLength();
	byte mby = -1;
	for (int i = 0; i < nLen; i++)
	{
		if(nCount>=12) break;
		strText.MakeUpper();
		mby =  strText.GetAt(i);
		if ((mby>='0'&&mby<='9') || (mby>='A'&&mby<='F'))
		{
			ch[nCount++] = mby;
		}
	}

	for (int i = nCount; i < 12; i++)
	{
		ch[i] = '0';
	}

	strMac.Format(_T("%c%c-%c%c-%c%c-%c%c-%c%c-%c%c"),ch[0],ch[1],ch[2],ch[3],ch[4],ch[5],ch[6],ch[7],ch[8],ch[9],ch[10],ch[11]);


	return strMac;
}

void timeToString(time_t t,double tms,CString& strout)
{
	char* stime;
	stime=ctime(&t);		
	CString strtemp1,strtemp2,strtemp3,strtemp4;
	strtemp3=stime;
	if(strtemp3.GetLength()>20)
	{
		strtemp4=strtemp3.Mid(20,4)+_T("年");
		strtemp1=strtemp3.Mid(4,3);
		strtemp1.MakeUpper();
		if(strtemp1==_T("JAN"))
			strtemp4=strtemp4+_T("01月");
		if(strtemp1==_T("FEB"))
			strtemp4=strtemp4+_T("02月");
		if(strtemp1==_T("MAR"))
			strtemp4=strtemp4+_T("03月");
		if(strtemp1==_T("APR"))
			strtemp4=strtemp4+_T("04月");
		if(strtemp1==_T("MAY"))
			strtemp4=strtemp4+_T("05月");
		if(strtemp1==_T("JUN"))
			strtemp4=strtemp4+_T("06月");
		if(strtemp1==_T("JUL"))
			strtemp4=strtemp4+_T("07月");
		if(strtemp1==_T("AUG"))
			strtemp4=strtemp4+_T("08月");
		if(strtemp1==_T("SEP"))
			strtemp4=strtemp4+_T("09月");
		if(strtemp1==_T("OCT"))
			strtemp4=strtemp4+_T("10月");
		if(strtemp1==_T("NOV"))
			strtemp4=strtemp4+_T("11月");
		if(strtemp1==_T("DEC"))
			strtemp4=strtemp4+_T("12月");
		strtemp4+=strtemp3.Mid(8,2)+_T("日");
		strtemp4+=strtemp3.Mid(11,8);
	}

	strtemp2.Format(_T("%.6d"),(DWORD)(tms*1000000));

	strout = strtemp4 + _T(".") + strtemp2;
}

/*
 ** SYSTEMTIME转time_t
 */
 time_t systime_to_timet(const SYSTEMTIME& st)
 {
	 struct tm gm = {st.wSecond, st.wMinute, st.wHour, st.wDay, st.wMonth-1, st.wYear-1900, st.wDayOfWeek, 0, 0};
	 return mktime(&gm);
 }

 void my_ConvertRecvMsgToString(BYTE *byRecvBuf, int nRecvLen, CString &strMsg)
 {
	 TCHAR *byStrBuf;
	 byStrBuf = new TCHAR[nRecvLen*3+1];
	 int nTcLen = sizeof(TCHAR);
	 memset(byStrBuf, 0, nTcLen*nRecvLen*3+1*nTcLen);
	 for( int iLoop=0; iLoop < nRecvLen; iLoop++ )
	 {
		 _sntprintf(&byStrBuf[iLoop*3], 3*nTcLen,_T("%.2X "), byRecvBuf[iLoop]);
	 }
	 strMsg.Format(_T("%s\r\n"), byStrBuf);
	 strMsg.TrimRight();
	 delete []byStrBuf;
	 byStrBuf = NULL;
 }

 void InitMUMSGCfgData(LPCTSTR lpstr,MuCfgData* const UIs,vector<MU_CHNSET>& chnset)
 {
	 BOOL bChk = FALSE;
	 MU_CHNSET *pChSet = NULL;
	 int nOffSetCount = 0;
	 float fAng = 0.0f;
	 int nNum = chnset.size();
	 vector<MU_CHNSET>::const_iterator itr;
	 for (int k=0;k<MAX_TST_MUCHN;k++)
	 {
		 itr = chnset.begin();

		 if (k<nNum)
			 pChSet = &chnset.at(k);

		 UIs[k].uIndex = k;
//		 if (NodeName==_T("m_muset92")&&pChSet->nTypeSel==2)
		 if (_tcscmp(lpstr,_T("m_muset92")) == 0&&pChSet->nTypeSel==2)
			nOffSetCount++;
			 
		 switch(k%3)
		 {
		 case 0: fAng = 0.0f;    break;
		 case 1: fAng = -120.0f; break;
		 case 2: fAng = 120.0f;  break;
		 }

		 fAng += nOffSetCount*120;
		 UIs[k].Ang = AdjustAngle(fAng);

		 UIs[k].Fre = 50.0f;
		 UIs[k].uChnType = ((k/3)==0||(k/3)==2)?0:1;

		 if (k%3==0)
			 bChk = !bChk;

		 UIs[k].Mag = (bChk)?57.735f:1.0f;
		 UIs[k].fData1 = (bChk)?220000.0f:1000.0f;
		 UIs[k].fData2 = (bChk)?100.0f:1.0f;

		 if (_tcscmp(lpstr,_T("m_muset92")) == 0)
		 {
			 UIs[k].Quo = (bChk)?2200.0f:1000.0f;
		 }
		 else
		 {
			 UIs[k].Quo = 0x0000;
		 }

		 UIs[k].uChnType = (bChk)?0:1;
		 UIs[k].fFirstData = 0.0f;
		 UIs[k].fLastData = 0.0f;
		 UIs[k].fStep = 0.0f;
		 UIs[k].bQuaTest = TRUE;
		 UIs[k].bVar = TRUE;

		 //////////////////////////////////////////////////////////////////////////
		 if (pChSet)
		 {
			 UIs[k].strName = pChSet->strChnName;

			 if (_tcscmp(lpstr,_T("m_muset91")) == 0||
				 _tcscmp(lpstr,_T("m_muset91Ex")) == 0)
			 {	//类型选择
				 UIs[k].uChnType = pChSet->nTypeSel;
				 switch(pChSet->nTypeSel)
				 {
				 case 0://电压	
					 UIs[k].Mag = 57.735f;
					 UIs[k].Quo = 0x2d41;
					 break;
				 case 1://电流（保护）
					 UIs[k].Mag = 1.0f;
					 UIs[k].Quo = 0x01cf;
					 break;
				 case 2://电流（测量）
					 UIs[k].uChnType = 1;
					 UIs[k].Mag = 1.0f;
					 UIs[k].Quo = 0x2d41;
					 break;
				 }
			 }

			 if (_tcscmp(lpstr,_T("m_muset92")) == 0)
			 {
				 UIs[k].uChnType = pChSet->nTypeSel;
				 switch(pChSet->nTypeSel)
				 {
				 case 0://电压
					 UIs[k].Mag = 57.735f;
					 UIs[k].fData1 = 220000.0f;
					 UIs[k].fData2 = 100.0f;
					 UIs[k].Quo = 2200.0f;
					 break;
				 case 1://电流
					 UIs[k].Mag = 1.0f;
					 UIs[k].fData1 = 1000.0f;
					 UIs[k].fData2 = 1.0f;
					 UIs[k].Quo = 1000.0f;
					 break;
				 case 2://时间
					 UIs[k].uChnType = 3;
					 UIs[k].fData1 = 0.0f;
					 UIs[k].fData2 = 1.0f;
					 UIs[k].Quo = 0.0f;
					 UIs[k].Mag = _wtof(pChSet->strInput);
					 UIs[k].Ang = 0.0f;
					 UIs[k].Fre = 0.0f;
					 break;
				 }
			 }
		 }
	 }
 }
