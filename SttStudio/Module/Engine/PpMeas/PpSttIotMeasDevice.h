#ifndef CPPSTTIOTMEASDEVICE_H
#define CPPSTTIOTMEASDEVICE_H

#include "../PpEngineServerBase/SttPxPotoEngineBase.h"
#include "../../../../Module/SmartCap/X61850CapBase.h"

class CPpSttIotMeasDevice : public CSttPxPotoEngineBase
{
public:
	CPpSttIotMeasDevice();
	virtual ~CPpSttIotMeasDevice();
	CX61850CapBase *m_pX61850CapBase;


protected:
	virtual long Process_Cmd_IOT_PkgParse(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_PkgProduce(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_RunProcedure(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmdDriver oDrvIotCmd);
	virtual long Process_Cmd_IOT_GetDataset(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_SetDataset(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_ConfigDevice(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_UpdateDataset(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);

	virtual long Process_Cmd_IOT_RunProcedure_ReadAin(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);
	virtual long Process_Cmd_IOT_RunProcedure_SetDataset(CIotPxCommChannelInterface *pPxCommChn, CSttIotCmd *pIotCmd);

	virtual BOOL IsConnectSuccessful();

};

#endif//!CPPSTTIOTMEASDEVICE_H