#include "stdafx.h"
#include "SttPowerCtrl_PI_V300.h"

CSttPowerCtrlV300_PI::CSttPowerCtrlV300_PI()
{	
	m_fMaxVal_DC=300;
	m_bVolt_440V=FALSE;
	m_fMaxVal=300;
	m_fMaxVal2=300;
}

void CSttPowerCtrlV300_PI::SetVoltDA(float fVout, BOOL bIsDc)
{	
	if(bIsDc)
		fVout = fVout /1.414;

	if(fVout<120)
		fVout = 116;//ģ�����ֵ

	if(fVout>300)
		fVout=300;

	float fDAValue = (fVout*1.414-163)/82;
	unsigned char nByte = fDAValue/3.3*255;
	m_nDA = ((unsigned int)nByte)<<(1*8);
}

void CSttPowerCtrlV300_PI::SetVoltDA_State()
{
    SetVoltDA(300,FALSE);
}
