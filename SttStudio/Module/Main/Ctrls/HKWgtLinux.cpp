#include "HKWgtLinux.h"
#include "HkTabWidget.h"
#include "../Module/HKWgtFactory.h"
#include "QGridLayout"
#include "HKWgtStyle.h"

HKWgtLinux* m_gHKWgtLinux = nullptr;

HKWgtLinux::HKWgtLinux(QWidget* pParent)
{
    m_gHKWgtLinux = this;
	m_pGlobalStyle = new CExBaseList;
	m_pAutoTestSettings = new CExBaseList;
    m_pMainConfig = nullptr;
}

HKWgtLinux::~HKWgtLinux()
{
	delete m_pGlobalStyle;
	delete m_pAutoTestSettings;
    m_pGlobalStyle = nullptr;
}

void HKWgtLinux::InitUI(CString strFilePath, CSttXuiDataMainConfig* pSttXuiDataMainConfig)
{
	if(!pSttXuiDataMainConfig)
	{
		return;
	}

	m_pMainConfig = pSttXuiDataMainConfig;
	m_pMainConfig->m_strFilePath = strFilePath;
	POS pos = pSttXuiDataMainConfig->GetHeadPosition();

	while (pos)
	{
		CSttXuiDataBase* pNode = (CSttXuiDataBase*)pSttXuiDataMainConfig->GetNext(pos);
		if(pNode->GetClassID() == MNGRCLASSID_CSTTXUIDATAGLOBAL)
		{
			//��¼global��ʽ
			POS pos = pNode->GetHeadPosition();

			while (pos)
			{
				CSttXuiDataBase* pData = (CSttXuiDataBase*)pNode->GetNext(pos);
				if(pData->GetClassID() == MNGRCLASSID_CSTTXUIDATATEXT)
				{
					//��¼�Զ������������
					CSttXuiDataText* pText = (CSttXuiDataText*)pData;
					m_pAutoTestSettings->AddNew(pText->m_strText, pText->m_strID);
				}
				else
				{
                    HKWgtStyle* pWgtStyle = new HKWgtStyle();
					pWgtStyle->InitStyle(pData);
                    CExBaseList* pStyle = nullptr;
					pStyle = (CExBaseList*)m_pGlobalStyle->FindByID(pWgtStyle->m_strType);
					if(!pStyle)
					{
						pStyle = new CExBaseList;
						pStyle->m_strID = pStyle->m_strName = pWgtStyle->m_strType;
						m_pGlobalStyle->AddNewChild(pStyle);
					}

					if(!pStyle->FindByID(pWgtStyle->m_strID))
					{
						//���Գ��ֵ��ظ�id,�����ڵ�������
						pStyle->AddNewChild(pWgtStyle);
					}
				}
			}
		}
		else
		{
            HKWgtFactory::CreateHKWgt(pNode, this);
		}
	}
}

void HKWgtLinux::SaveXmlFile()
{
	m_pMainConfig->SaveXmlFile(m_pMainConfig->m_strFilePath, CSttXMainConfigXmlRWKeys::g_pXmlKeys);
}
