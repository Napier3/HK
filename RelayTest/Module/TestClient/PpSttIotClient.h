#pragma once
#include "SttTestClientBase.h"
#include "../SttTestAppConfig/SttTestDeviceCfg.h"
#include "../SttCmd/SttIotCmd.h"

class CPpSttIotClient :	public CSttTestClientBase
{
public:
	CPpSttIotClient(void);
	virtual ~CPpSttIotClient(void);

public:
	//暂时先写死，后面考虑增加配置
	CSttTestDeviceCfg m_oTestDeviceCfg;   //新增配置，配置服务端的IP、端口

public:
	virtual long SendIotCmd(CSttIotCmd &oIotCmd);
	virtual BOOL ConnectSttServer();

	
	void InitSttTestDeviceCfg(const CString &strCfgFile);
};
