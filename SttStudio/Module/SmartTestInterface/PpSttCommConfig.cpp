#include "stdafx.h"
#include"PpSttCommConfig.h"
#include "../SttGlobalDef.h"
#include "../../../System/Module/XAtsSysSvrGlobalDef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern BOOL g_bShowTestWndTop;

//////////////////////////////////////////////////////////////////////////
//CPpSttCommConfig
CPpSttCommConfig::CPpSttCommConfig()
{
    m_pCmmConfig = NULL;
}

CPpSttCommConfig::~CPpSttCommConfig()
{ 
	
}

void CPpSttCommConfig::InitAfterRead()
{
    GetCommConfig();
}

void CPpSttCommConfig::InitEngine(const CString &strDeviceSN, const CString &strEngineID, const CString &strPpXmlFile, const CString &strDvmFile)
{
	DeleteAll();
	AddNewData(STT_CMD_PARA_DeviceSN, strDeviceSN);
	AddNewData(XPARA_ID_PPXMLFILE, strPpXmlFile);
	AddNewData(XPARA_ID_DVMFILE, strDvmFile);
	//AddNewData(XPARA_ID_EngineProgID, strEngineID);
	AddNewData(STT_CMD_PARA_EngineProgID, strEngineID);
}

void CPpSttCommConfig::Set_DeviceSN(const CString &strDeviceSN)
{
	SetDataValue(STT_CMD_PARA_DeviceSN, strDeviceSN,TRUE);
}

void CPpSttCommConfig::Set_PpXmlFile(const CString &strPpXmlFile)
{
	SetDataValue(XPARA_ID_PPXMLFILE, strPpXmlFile,TRUE);
}

void CPpSttCommConfig::Set_EngineID(const CString &strEngineID)
{
	SetDataValue(STT_CMD_PARA_EngineProgID, strEngineID,TRUE);
}

void CPpSttCommConfig::Set_DvmFile(const CString &strDvmFile)
{
	SetDataValue(STT_CMD_PARA_DvmFile, strDvmFile,TRUE);
}

bool CPpSttCommConfig::Is_MmsEngine()
{
    //return CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMmsKey);
    return  false;
}

bool CPpSttCommConfig::Is_CmsEngine()
{
    //return CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmsKey);
    return  false;
}

bool CPpSttCommConfig::Is_PpEngine()
{
   if (Is_PpEngine_Serial())
   {
	   return true;
   }

  if (Is_PpEngine_Net())
  {
	  return true;
  }

    return false;
}

bool CPpSttCommConfig::Is_PpEngine_Net()
{
    //sun if (CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpClientKey))
    //sun {
    //sun 	return true;
    //sun }
    //sun
    //sun if (CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpServerKey))
    //sun {
    //sun 	return true;
    //sun }
    //sun
    //sun if (CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpClientKey))
    //sun {
    //sun 	return true;
    //sun }
    //sun
    //sun if (CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpServerKey))
    //sun {
    //sun 	return true;
    //sun }

	return false;
}

bool CPpSttCommConfig::Is_PpEngine_Serial()
{
    //sun if (CmmConfigIsKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strSerialKey))
    //sun {
    //sun 	return true;
    //sun }

	return false;
}

CString CPpSttCommConfig::Get_DeviceSN()
{
	CString strVal;
	GetDataValue(STT_CMD_PARA_DeviceSN, strVal);
	return strVal;
}

CString CPpSttCommConfig::Get_DvmFile()
{
    CString strVal;
    GetDataValue(STT_CMD_PARA_DvmFile, strVal);
    return strVal;
}

//2023.11.15 lichao PNS331 新增
//获取Ppxml项内容
CString CPpSttCommConfig::Get_PpxmlFile()
{
	CString strVal;
	GetDataValue(XPARA_ID_PPXMLFILE, strVal);
	return strVal;
}

/*
<group>
	<data name="" id="DeviceSN" data-type="" value="MmsEngine_Demo"/>
	<data name="" id="ppxml-file" data-type="" value=""/>
	<data name="" id="dvm-file" data-type="" value="PCS931.xml"/>
	<data name="" id="EngineProgID" value="MmsEngine"/>
	<group name="" id="comm-config" data-type="" value="">
		<data name="" id="mms" data-type="" value="">
			<value name="" id="local-ip" data-type="" value="192.168.1.60"/>
			<value name="" id="local-port" data-type="" value="0"/>
			<value name="" id="remote-ip" data-type="" value="192.168.1.20"/>
			<value name="" id="remote-port" data-type="" value="9988"/>
		</data>
	</group>
</group>
*/

/*
<group>
	<data name="" id="DeviceSN" data-type="" value="PpEngine_TcpClient"/>
	<data name="" id="ppxml-file" data-type="" value="TcpClient.ppxml"/>
	<data name="" id="dvm-file" data-type="" value="PCS931.xml"/>
	<data name="" id="EngineProgID" value="PpEngine"/>
	<group name="" id="comm-config" data-type="" value="">
		<data name="" id="tcp-client" data-type="" value="">
			<value name="" id="local-ip" data-type="" value="192.168.1.60"/>
			<value name="" id="local-port" data-type="" value="0"/>
			<value name="" id="remote-ip" data-type="" value="192.168.1.20"/>
			<value name="" id="remote-port" data-type="" value="9988"/>
		</data>
	</group>
</group>
*/
// BOOL CPpSttCommConfig::InitCmmConfig_Net_TcpClient(CDvmData *pData)
// {
//    CCmmTcpClientConfig *pTcpClient = AddConfigTcpClient();
// 
//    pData->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  pTcpClient->m_strLocalIP);
//    pData->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey,  pTcpClient->m_nLocalPort);
//    pData->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  pTcpClient->m_strRemoteIP);
//    pData->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  pTcpClient->m_nRemotePort);
// 
//    return TRUE;
// }

CDataGroup* CPpSttCommConfig::NewCommConfig()
{
	m_pCmmConfig = new CDataGroup();
    //sun m_pCmmConfig->m_strID = CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmmConfigKey;
	AddNewChild(m_pCmmConfig);

	return m_pCmmConfig;
}

CDvmData* CPpSttCommConfig::CmmCfg_GetByKey(const CString &strKey)
{
	GetCommConfig();

	return (CDvmData*)m_pCmmConfig->FindByID(strKey);
}

CDvmData* CPpSttCommConfig::CmmCfg_GetByKey(BSTR bstrKey)
{
	CString strKey;
	strKey = bstrKey;
	return CmmCfg_GetByKey(strKey);
}

CDvmData* CPpSttCommConfig::CmmCfg_SetByKey(const CString &strKey)
{
	return CmmCfg_AddByKey(strKey, TRUE);
}

CDvmData* CPpSttCommConfig::CmmCfg_SetByKey(BSTR bstrKey)
{
	CString strKey;
	strKey = bstrKey;
	return CmmCfg_AddByKey(strKey, TRUE);
}

bool CPpSttCommConfig::CmmConfigIsKey(const CString &strKey)
{
    CDvmData *pFind = NULL;
    GetCommConfig();

    pFind = (CDvmData*)m_pCmmConfig->FindByID(strKey);

    if (pFind != NULL)
    {
        return true;
    }

    return false;
}

bool CPpSttCommConfig::CmmConfigIsKey(BSTR bstrKey)
{
    CString strKey;
    strKey = bstrKey;
    return CmmConfigIsKey(strKey);
}

CDvmData* CPpSttCommConfig::CmmCfg_AddByKey(const CString &strKey, BOOL bClearAll)
{
	CDvmData *pFind = NULL;
	GetCommConfig();

	pFind = (CDvmData*)m_pCmmConfig->FindByID(strKey);

	if (pFind == NULL)
	{
		if (bClearAll)
		{
			m_pCmmConfig->DeleteAll();
		}

		pFind = new CDvmData();
		pFind->m_strID = strKey;
		pFind->m_strName = strKey;
		m_pCmmConfig->AddNewChild(pFind);
	}

	return pFind;
}

CDvmData* CPpSttCommConfig::CmmCfg_AddByKey(BSTR bstrKey, BOOL bClearAll)
{
	CString strKey;
	strKey = bstrKey;
	return CmmCfg_AddByKey(strKey, TRUE);
}

void CPpSttCommConfig::CmmCfg_DelByKey(const CString &strKey)
{
	GetCommConfig();
	m_pCmmConfig->DeleteByID(strKey);
}

void CPpSttCommConfig::CmmCfg_DelByKey(BSTR bstrKey)
{
	CString strKey;
	strKey = bstrKey;
	return CmmCfg_DelByKey(strKey);
}

CDataGroup* CPpSttCommConfig::GetCommConfig()
{
	CString strKey;
    //sun strKey = CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmmConfigKey;
	CDataGroup *pFind = (CDataGroup*)FindByID(strKey);

	if (pFind == NULL)
	{
		pFind = NewCommConfig();
	}

	m_pCmmConfig = pFind;

	return pFind;
}
	
//sun CDvmData* CPpSttCommConfig::Get_TcpClient()
//sun {
//sun     return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpClientKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_TcpServer()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpServerKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_UdpClient()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpClientKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_UdpServer()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpServerKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_Serial()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strSerialKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_MMS()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMmsKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Get_CMS()
//sun {
//sun 	return CmmCfg_GetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmsKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Add_TcpClient()
//sun {
//sun 	return CmmCfg_AddByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpClientKey, FALSE);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Add_TcpServer()
//sun {
//sun 	return CmmCfg_AddByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpServerKey, FALSE);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Add_UdpClient()
//sun {
//sun 	return CmmCfg_AddByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpClientKey, FALSE);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Add_UdpServer()
//sun {
//sun 	return CmmCfg_AddByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpServerKey, FALSE);
//sun }

void CPpSttCommConfig::Set_Net()
{
	if (Is_PpEngine_Net())
	{
		return;
	}

    //sun CmmCfg_DelByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmsKey);
    //sun CmmCfg_DelByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMmsKey);
    //sun CmmCfg_DelByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strSerialKey);
}

//sun CDvmData* CPpSttCommConfig::Set_TcpClient()
//sun {
//sun 	Set_Net();
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpClientKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Set_TcpServer()
//sun {
//sun 	Set_Net();
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strTcpServerKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Set_UdpClient()
//sun {
//sun 	Set_Net();
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpClientKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Set_UdpServer()
//sun {
//sun 	Set_Net();
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strUdpServerKey);
//sun }

//sun CDvmData* CPpSttCommConfig::Set_Serial()
//sun {
//sun 	if (Is_PpEngine_Serial())
//sun 	{
//sun 		return Get_Serial();
//sun 	}
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strSerialKey);
//sun }
//sun
//sun CDvmData* CPpSttCommConfig::Set_MMS()
//sun {
//sun 	if (Is_MmsEngine())
//sun 	{
//sun 		return Get_MMS();
//sun 	}
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMmsKey);
//sun }

//sun CDvmData* CPpSttCommConfig::Set_CMS()
//sun {
//sun 	if (Is_CmsEngine())
//sun 	{
//sun 		return Get_CMS();
//sun 	}
//sun
//sun 	return CmmCfg_SetByKey(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strCmsKey);
//sun }
//sun
//sun void CPpSttCommConfig::MMS_Init(const CString &strLocalIP, const CString &strRemoteIP, long nRemotePort, const CString &strPsw, const CString &strKey)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun
//sun    dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun    dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun    dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun    dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey,  strPsw);
//sun    dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey,  strKey);
//sun }

//sun void CPpSttCommConfig::MMS_Set_EncryptPsw(const CString &strPsw)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun     dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey,  strPsw);
//sun }
//sun
//sun void CPpSttCommConfig::MMS_Set_EncryptKey(const CString &strKey)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun     dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey,  strKey);
//sun }
//sun
//sun void CPpSttCommConfig::MMS_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun 	dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun
//sun void CPpSttCommConfig::MMS_Set_RemoteIP(const CString &strRemoteIP)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun 	dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun }
//sun
//sun void CPpSttCommConfig::MMS_Set_RemotePort(long nRemotePort)
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun 	dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun }
//sun
//sun void CPpSttCommConfig::Serial_Set_port_number(long nPortNumber)
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     dvmdata_set_value(pSerial, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strPortNumKey,  nPortNumber);
//sun }
//sun
//sun void CPpSttCommConfig::Serial_Set_baud_rate(long nBaudRate)
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     dvmdata_set_value(pSerial, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strBaudRateKey,  nBaudRate);
//sun }
//sun
//sun void CPpSttCommConfig::Serial_Set_byte_size(long nByteSize)
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     dvmdata_set_value(pSerial, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strByteSizeKey,  nByteSize);
//sun }
//sun
//sun void CPpSttCommConfig::Serial_Set_stop_bit(long nStopBit)
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     dvmdata_set_value(pSerial, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strStopBitsKey,  nStopBit);
//sun }
//sun
//sun void CPpSttCommConfig::Serial_Set_parity(long nParity)
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     dvmdata_set_value(pSerial, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strParityKey,  nParity);
//sun }
//sun
//sun
//sun void CPpSttCommConfig::CMS_Init(const CString &strLocalIP, const CString &strRemoteIP, long nRemotePort, const CString &strPsw, const CString &strKey)
//sun {
//sun 	CDvmData *pCms = Set_CMS();
//sun
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun     dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey,  strPsw);
//sun     dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey,  strKey);
//sun }

void CPpSttCommConfig::PpEngineNet_Init(const CString &strLocalIP,const CString &strRemoteIP, long nRemotePort)
{
	Set_Net();
    //TcpClient_Set_LocalIP(strLocalIP);
    //TcpClient_Set_RemoteIP(strRemoteIP);
    //TcpClient_Set_RemotePort(nRemotePort);
}

//sun void CPpSttCommConfig::CMS_Set_EncryptPsw(const CString &strPsw)
//sun {
//sun     CDvmData *pMms = Set_CMS();
//sun     dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey,  strPsw);
//sun }
//sun
//sun void CPpSttCommConfig::CMS_Set_EncryptKey(const CString &strKey)
//sun {
//sun     CDvmData *pMms = Set_CMS();
//sun     dvmdata_set_value(pMms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey,  strKey);
//sun }
//sun
//sun void CPpSttCommConfig::CMS_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun 	CDvmData *pCms = Set_CMS();
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun
//sun void CPpSttCommConfig::CMS_Set_RemoteIP(const CString &strRemoteIP)
//sun {
//sun 	CDvmData *pCms = Set_CMS();
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun }
//sun
//sun void CPpSttCommConfig::CMS_Set_RemotePort(long nRemotePort)
//sun {
//sun 	CDvmData *pCms = Set_CMS();
//sun 	dvmdata_set_value(pCms, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun }
//sun
//sun //////////////////////////////////////////////////////////////////////////////////
//sun ///TcpClient
//sun void CPpSttCommConfig::TcpClient_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     dvmdata_set_value(pTcpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun
//sun void CPpSttCommConfig::TcpClient_Set_LocalPort(long nLocalPort)
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     dvmdata_set_value(pTcpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey,  nLocalPort);
//sun }
//sun
//sun void CPpSttCommConfig::TcpClient_Set_RemoteIP(const CString &strRemoteIP)
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     dvmdata_set_value(pTcpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun }

//sun void CPpSttCommConfig::TcpClient_Set_RemotePort(long nRemotePort)
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     dvmdata_set_value(pTcpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun }


///////////////////////////////////////////////////////////////////////
///TcpServer
//sun void CPpSttCommConfig::TcpServer_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun     CDvmData *pTcpServer = Set_TcpServer();
//sun     dvmdata_set_value(pTcpServer, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun
//sun void CPpSttCommConfig::TcpServer_Set_LocalPort(long nLocalPort)
//sun {
//sun     CDvmData *pTcpServer = Set_TcpServer();
//sun     dvmdata_set_value(pTcpServer, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey,  nLocalPort);
//sun }
//sun
//sun
//sun //UdpServer_Set
//sun void CPpSttCommConfig::UdpServer_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     dvmdata_set_value(pUdpServer, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun void CPpSttCommConfig::UdpServer_Set_LocalPort(long nLocalPort)
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     dvmdata_set_value(pUdpServer, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey,  nLocalPort);
//sun }
//sun void CPpSttCommConfig::UdpServer_Set_MuticastIP(const CString &strMuticastIP)
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     dvmdata_set_value(pUdpServer, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMulticastIPKey,  strMuticastIP);
//sun }
//sun
//sun //UdpClient_Set
//sun void CPpSttCommConfig::UdpClient_Set_LocalIP(const CString &strLocalIP)
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     dvmdata_set_value(pUdpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey,  strLocalIP);
//sun }
//sun void CPpSttCommConfig::UdpClient_Set_LocalPort(long nLocalPort)
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     dvmdata_set_value(pUdpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey,  nLocalPort);
//sun }
//sun void CPpSttCommConfig::UdpClient_Set_MuticastIP(const CString &strMuticastIP)
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     dvmdata_set_value(pUdpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMulticastIPKey,  strMuticastIP);
//sun }
//sun void CPpSttCommConfig::UdpClient_Set_RemoteIP(const CString &strRemoteIP)
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     dvmdata_set_value(pUdpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey,  strRemoteIP);
//sun }
//sun
//sun void CPpSttCommConfig::UdpClient_Set_RemotePort(long nRemotePort)
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     dvmdata_set_value(pUdpClient, CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey,  nRemotePort);
//sun }



//TcpClient_Get
//sun CString CPpSttCommConfig::TcpClient_Get_RemotePort()
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     return pTcpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey);
//sun }
//sun
//sun CString CPpSttCommConfig::TcpClient_Get_RemoteIP()
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     return pTcpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey);
//sun }
//sun
//sun CString CPpSttCommConfig::TcpClient_Get_LocalIP()
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     return pTcpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun CString CPpSttCommConfig::TcpClient_Get_LocalPort()
//sun {
//sun     CDvmData *pTcpClient = Set_TcpClient();
//sun     return pTcpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey);
//sun }

//TcpServer_Get
//sun CString  CPpSttCommConfig::TcpServer_Get_LocalPort()
//sun {
//sun     CDvmData *pTcpServer = Set_TcpServer();
//sun     return pTcpServer->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey);
//sun }
//sun CString  CPpSttCommConfig::TcpServer_Get_LocalIP()
//sun {
//sun     CDvmData *pTcpServer = Set_TcpServer();
//sun     return pTcpServer->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun
//sun //UdpServer_Get
//sun CString  CPpSttCommConfig::UdpServer_Get_MuticastIP()
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     return pUdpServer->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMulticastIPKey);
//sun }
//sun CString  CPpSttCommConfig::UdpServer_Get_LocalPort()
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     return pUdpServer->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey);
//sun }
//sun CString  CPpSttCommConfig::UdpServer_Get_LocalIP()
//sun {
//sun     CDvmData *pUdpServer = Set_UdpServer();
//sun     return pUdpServer->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun
//sun //UdpClient_Get
//sun CString  CPpSttCommConfig::UdpClient_Get_RemotePort()
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     return pUdpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey);
//sun }
//sun CString  CPpSttCommConfig::UdpClient_Get_RemoteIP()
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     return pUdpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey);
//sun }
//sun CString  CPpSttCommConfig::UdpClient_Get_MuticastIP()
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     return pUdpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strMulticastIPKey);
//sun }
//sun CString  CPpSttCommConfig::UdpClient_Get_LocalPort()
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     return pUdpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalPortKey);
//sun }
//sun CString  CPpSttCommConfig::UdpClient_Get_LocalIP()
//sun {
//sun     CDvmData *pUdpClient = Set_UdpClient();
//sun     return pUdpClient->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun
//sun //SerialMode_Get
//sun CString CPpSttCommConfig::Serial_Get_port_number()
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     return pSerial->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strPortNumKey);
//sun }
//sun CString CPpSttCommConfig::Serial_Get_baud_rate()
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     return pSerial->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strBaudRateKey);
//sun }
//sun CString CPpSttCommConfig::Serial_Get_byte_size()
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     return pSerial->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strByteSizeKey);
//sun }
//sun CString CPpSttCommConfig::Serial_Get_stop_bit()
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     return pSerial->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strStopBitsKey);
//sun }
//sun CString CPpSttCommConfig::Serial_Get_parity()
//sun {
//sun     CDvmData *pSerial = Set_Serial();
//sun     return pSerial->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strParityKey);
//sun }

//MmsMode_Get
//sun CString CPpSttCommConfig::MMS_Get_LocalIP()
//sun {
//sun     CDvmData *pMms = Set_MMS();
//sun     return pMms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun CString CPpSttCommConfig::MMS_Get_RemoteIP()
//sun {
//sun 	CDvmData *pMms = Set_MMS();
//sun 	return pMms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey);
//sun }
//sun CString CPpSttCommConfig::MMS_Get_EncryptKey()
//sun {
//sun     CDvmData *pMms = Set_MMS();
//sun     return pMms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey);
//sun }
//sun CString CPpSttCommConfig::MMS_Get_EncryptPsw()
//sun {
//sun     CDvmData *pMms = Set_MMS();
//sun     return pMms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey);
//sun }

//Cms_Get
//sun CString CPpSttCommConfig::CMS_Get_LocalIP()
//sun {
//sun     CDvmData *pCms=Set_CMS();
//sun     return pCms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strLocalIPKey);
//sun }
//sun CString CPpSttCommConfig::CMS_Get_EncryptKey()
//sun {
//sun     CDvmData *pCms=Set_CMS();
//sun     return pCms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptKeyKey);
//sun }
//sun CString CPpSttCommConfig::CMS_Get_EncryptPsw()
//sun {
//sun     CDvmData *pCms=Set_CMS();
//sun     return pCms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strEncryptPswKey);
//sun }
//sun CString CPpSttCommConfig::CMS_Get_RemoteIP()
//sun {
//sun     CDvmData *pCms=Set_CMS();
//sun     return pCms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemoteIPKey);
//sun }

//sun CString CPpSttCommConfig::CMS_Get_RemotePort()
//sun {
//sun     CDvmData *pCms=Set_CMS();
//sun     return pCms->GetValueByID(CDeviceModelXmlKeys::g_pXmlRWKeys->m_strRemotePortKey);
//sun }

void CPpSttCommConfig::dvmdata_set_value(CDvmData *pData, BSTR bstrKey, const CString &strValue)
{
	CString strKey;
	strKey = bstrKey;
	pData->SetValue(strKey, strValue);
}

void CPpSttCommConfig::dvmdata_set_value(CDvmData *pData, BSTR bstrKey, long nValue)
{
	CString strKey;
	strKey = bstrKey;
	pData->SetValue(strKey, nValue);
}


BOOL CPpSttCommConfig::OpenCommConfigFile(const CString &strFile)
{
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	BOOL bRet = OpenXmlFile(strFile, CDataMngrXmlRWKeys::g_pXmlKeys);
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;

	return bRet;
}

void CPpSttCommConfig::SaveCommConfigFile(const CString &strFile)
{
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nXmlOnlyWrite_Id_Value++;
	BOOL bRet = SaveXmlFile(strFile, CDataMngrXmlRWKeys::g_pXmlKeys);
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nXmlOnlyWrite_Id_Value--;
}

void CPpSttCommConfig::UpdateFilePath_UseAbs()
{
	CString strFolderPath,strFileName,strTmp;
	strFolderPath = _P_GetInstallPath();
	strFolderPath += _T("e-Protocol/Template/");
	strFileName = "";
	GetDataValue(XPARA_ID_PPXMLFILE,strFileName);

	if (!strFileName.IsEmpty())
	{
		strTmp = strFolderPath + strFileName;

		if (IsFileExist(strTmp))
		{
			SetDataValue(XPARA_ID_PPXMLFILE,strTmp);
		}
	}

	strFolderPath = _P_GetInstallPath();
	strFolderPath += _T("e-Protocol/Library/");
	strFileName = "";
	GetDataValue(XPARA_ID_DVMFILE,strFileName);

	if (!strFileName.IsEmpty())
	{
		strTmp = strFolderPath + strFileName;

		if (IsFileExist(strTmp))
		{
			SetDataValue(XPARA_ID_DVMFILE,strTmp);
		}
	}
}


//////////////////////////////////////////////////////////////////////////
CPpSttCommConfigs::CPpSttCommConfigs()
{

}

CPpSttCommConfigs::~CPpSttCommConfigs()
{

}

BOOL CPpSttCommConfigs::OpenCommConfigsFile(const CString &strFile)
{
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData++;
	BOOL bRet = OpenXmlFile(strFile, CDataMngrXmlRWKeys::g_pXmlKeys);
	CDataMngrXmlRWKeys::g_pXmlKeys->m_nIsGroupUseDvmData--;

	return bRet;
}

void CPpSttCommConfigs::SaveCommConfigsFile(const CString &strFile)
{

}



//////////////////////////////////////////////////////////////////////////
CString File_SmartTestCommConfig_mms()
{
	CString strFile;
	strFile = _P_GetConfigPath();
	strFile += _T("SmartTestCommConfig_mms.xml");

	return strFile;
}

CString File_SmartTestCommConfig_cms()
{
	CString strFile;
	strFile = _P_GetConfigPath();
	strFile += _T("SmartTestCommConfig_cms.xml");

	return strFile;
}

CString File_SmartTestCommConfig_pp()
{
	CString strFile;
	strFile = _P_GetConfigPath();
	strFile += _T("SmartTestCommConfig_pp.xml");

	return strFile;
}

