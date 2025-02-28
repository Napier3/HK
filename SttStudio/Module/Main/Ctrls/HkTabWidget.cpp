#include "HkTabWidget.h"
#include "../SttXuiData/SttXuiDataTabs.h"
#include "../Module/HKWgtFactory.h"
#include "HKButtonGroup.h"
#include "HKWgtText.h"
#include "../SttXuiData/SttXuiDataFileMngrGrid.h"
#include "HKWgtFileMngrGrid.h"
#include "../../UI/SCL/QSttSelSclFileWidget.h"

HkTabWidget::HkTabWidget(QWidget* pParent)
{
	m_pParent = pParent;
	setParent(pParent);
}

HkTabWidget::~HkTabWidget(){}

void HkTabWidget::InitUIOwn(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataTabs* pData = (CSttXuiDataTabs*)pSttXuiData;
		setGeometry(pData->m_nX*g_dUIShowCoef, pData->m_nY*g_dUIShowCoef, pData->m_nCx*g_dUIShowCoef, pData->m_nCy*g_dUIShowCoef);
		setObjectName(pData->m_strID);
        HKWgtStyle* pStyle = GetWgtStyle(WGT_TYPE_FONT, pData->m_strFont);
		SetWgtStyle(this, pStyle);
	}
}

void HkTabWidget::InitUIChildren(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataBase* pData = (CSttXuiDataBase*)pSttXuiData;
		POS pos = pData->GetHeadPosition();

		while(pos)
		{
			CSttXuiDataBase* pNode = (CSttXuiDataBase*)pData->GetNext(pos);
            HKWgtFactory::CreateHKWgt(pNode, this);
		}
	}
}

HkTabPage::HkTabPage(QWidget* pParent)
{
	m_pParent = pParent;
}

HkTabPage::~HkTabPage(){}

void HkTabPage::InitUIOwn(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataTab* pData = (CSttXuiDataTab*)pSttXuiData;
        long nCount = ((HkTabWidget*)m_pParent)->count();
        ((HkTabWidget*)m_pParent)->insertTab(nCount, this, pData->m_strName);
        HKWgtStyle* pStyle = GetWgtStyle(WGT_TYPE_FONT, pData->m_strFont);
		SetWgtStyle(this, pStyle);
	}
}

void HkTabPage::InitUIChildren(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		if (pSttXuiData->m_strID == _T("SelSCLFile"))
		{
			*g_pSttGlobalFont = this->font();
			QSttSelSclFileWidget *pQSttSelSclFileWidget = new QSttSelSclFileWidget(this);

            if (g_pSttGlobalFont != nullptr)
			{
				pQSttSelSclFileWidget->setFont(*g_pSttGlobalFont);
			}

			pQSttSelSclFileWidget->InitUI();
			g_pSttSelSclFileWidget = pQSttSelSclFileWidget;
			AddWidgetChild(pQSttSelSclFileWidget);
		}
		else
		{
			CSttXuiDataBase* pData = (CSttXuiDataBase*)pSttXuiData;
            CSttXuiDataBase* pNode = nullptr;
			POS pos = pData->GetHeadPosition();

			while(pos)
			{
				pNode = (CSttXuiDataBase*)pData->GetNext(pos);
                HKWgtFactory::CreateHKWgt(pNode, this);
			}
		}
	}
}

void HkTabPage::AddWidgetChild(QWidget *pChildWidget)
{
	QVBoxLayout *pVBoxLayout = new QVBoxLayout;
	pVBoxLayout->addWidget(pChildWidget);
	setLayout(pVBoxLayout);
}
