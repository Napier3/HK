#include "HKMainApplicationBase.h"
#include "../../../Module/API/GlobalConfigApi.h"
#include "../../../61850/Module/SCL/SclFileMngr/XSclFileMngr.h"
#include "../../../61850/Module/CfgDataMngr/IecCfgDataMngrGlobal.h"
#include "../UI/Module/PopupDialog/SttFileMngrTool.h"
#include "../../../61850/Module/XLanguageResourcePp_Mms.h"

HKMainApplicationBase *g_HKMainApp = nullptr;

HKMainApplicationBase::HKMainApplicationBase()
{
   g_HKMainApp = this;
}

HKMainApplicationBase::~HKMainApplicationBase() {}

void HKMainApplicationBase::InitHKMainApp(CXLanguageResourceBase *pLanguage)
{
	_P_InitSystemPath();

	CXLanguageXmlRWKeys::Create();
    CXLanguageMngr::Create(pLanguage, true);
    CXLanguageMngr::xlang_AddXLanguageRerouce(new CXLanguageResourcePp_Mms(), true);

    CDataMngrXmlRWKeys::Create();
	CCfgDataMngrXmlRWKeys::Create();
	CSclFileMngrXmlRWKeys::Create();
	g_oXSclFileMngr.OpenSclFileMngrCfg();
	g_oFileMngrTool.OpenConfigFile();
}
void HKMainApplicationBase::ExitHKMainApp()
{
	CSclFileMngrXmlRWKeys::Release();
	CCfgDataMngrXmlRWKeys::Release();
	CDataMngrXmlRWKeys::Release();
	CXLanguageMngr::Release();
	CXLanguageXmlRWKeys::Release();
}

void HKMainApplicationBase::OnCmd_StartHKMain(){}

void HKMainApplicationBase::OnCmd_StopHKMain(){}

