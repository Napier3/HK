#include "HKWgtBase.h"
#include "HKWgtFactory.h"
#include "../Ctrls/HKWgtLinux.h"
#include <QFont>

HKWgtBase::HKWgtBase(QWidget* pParent)
{
	m_pParent = pParent;
    m_pWgtRef = nullptr;
    m_pXuiData = nullptr;
}

void HKWgtBase::InitUI(CExBaseObject *pSttXuiData)
{
	if (pSttXuiData)
	{
		InitUIOwn(pSttXuiData);
		InitUIChildren(pSttXuiData);
	}
}

HKWgtBase* HKWgtBase::FindWgtBase(CExBaseObject *pXuiData)
{
	return 0;
}

HKWgtStyle* HKWgtBase::GetWgtStyle(const CString& strStyleType, const CString& strStyleID)
{
    CExBaseList* pStyleType = (CExBaseList*)m_gHKWgtLinux->m_pGlobalStyle->FindByID(strStyleType);
    return (HKWgtStyle*)pStyleType->FindByID(strStyleID);
}

void HKWgtBase::SetWgtStyle(QWidget* pWidget, HKWgtStyle *pStyle)
{
	if(!pStyle)
	{
		return;
	}
	QFont font = pWidget->font();
	font.setPointSize(pStyle->m_nSize);
	pWidget->setFont(font);
}
