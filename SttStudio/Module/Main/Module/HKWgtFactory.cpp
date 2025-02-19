#include "stdafx.h"
#include "HKWgtFactory.h"

#include "../SttXuiData/SttXuiDataMainConfig.h"
#include "../Ctrls/HKButton.h"
#include "../Ctrls/HKButtonGroup.h"
#include "../Ctrls/HKWgtFileMngrGrid.h"
#include "../Ctrls/HkTabWidget.h"
#include "../Ctrls/HKWgtText.h"

HKWgtFactory* g_pHKWgtFactory = nullptr;
long g_nHKWgtFactoryRef = 0;

HKWgtFactory::HKWgtFactory(){}

HKWgtFactory::~HKWgtFactory(){}

HKWgtFactory *HKWgtFactory::Create()
{
    g_nHKWgtFactoryRef++;

    if (g_nHKWgtFactoryRef == 1)
	{
        g_pHKWgtFactory = new HKWgtFactory();
	}
    return g_pHKWgtFactory;
}

HKWgtBase* HKWgtFactory::CreateHKWgt(CSttXuiDataBase *pSttXuiData, QWidget* pParent)
{
    HKWgtBase* pWgtBase = nullptr;

    switch (pSttXuiData->GetClassID())
    {
    case MNGRCLASSID_CSTTXUIDATATABS:
        pWgtBase = new HkTabWidget(pParent);
        break;

    case MNGRCLASSID_CSTTXUIDATATAB:
        pWgtBase = new HkTabPage(pParent);
        break;

    case MNGRCLASSID_CSTTXUIDATATEXT:
        pWgtBase = new HKWgtText(pParent);
        break;

    case MNGRCLASSID_CSTTXUIDATATESTBTNSGROUP:
    case MNGRCLASSID_CSTTXUIDATABTNSGROUP:
        pWgtBase = new HKButtonGroup(pParent);
        break;

    case MNGRCLASSID_CSTTXUIDATABUTTON:
        pWgtBase = new HKButton(pParent);
        break;

    case MNGRCLASSID_CSTTXUIDATAFILEMNGRGRID:
        pWgtBase = new HKWgtFileMngrGrid(pParent);
        break;

    default:
        pWgtBase = nullptr;
        break;
    }

    if (pWgtBase)
    {
        pWgtBase->m_pWgtRef = pWgtBase;
        pWgtBase->m_pXuiData = pSttXuiData;
        pWgtBase->InitUI(pSttXuiData);
    }

    return pWgtBase;
}

void HKWgtFactory::Release()
{
    g_nHKWgtFactoryRef--;

    if (g_nHKWgtFactoryRef == 0)
	{
        delete g_pHKWgtFactory;
        g_pHKWgtFactory = nullptr;
	}
}
