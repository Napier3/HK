#include "SttWgtBase.h"
#include "SttWgtFactory.h"
#include "../Ctrls/SttWgtNativeMainLinux.h"
#include <QFont>

QSttWgtBase::QSttWgtBase(QWidget* pParent)
{
	m_pParent = pParent;
    m_pWgtRef = nullptr;
    m_pXuiData = nullptr;
}

void QSttWgtBase::InitUI(CExBaseObject *pSttXuiData)
{
	if (pSttXuiData)
	{
		InitUIOwn(pSttXuiData);
		InitUIChildren(pSttXuiData);
	}
}

QSttWgtBase* QSttWgtBase::FindWgtBase(CExBaseObject *pXuiData)
{
	return 0;
}

QSttWgtStyle* QSttWgtBase::GetWgtStyle(const CString& strStyleType, const CString& strStyleID)
{
	CExBaseList* pStyleType = (CExBaseList*)m_gQSttWgtNativeMainLinux->m_pGlobalStyle->FindByID(strStyleType);
	return (QSttWgtStyle*)pStyleType->FindByID(strStyleID);
}

void QSttWgtBase::SetWgtStyle(QWidget* pWidget, QSttWgtStyle* pStyle)
{
	if(!pStyle)
	{
		return;
	}
	QFont font = pWidget->font();
	font.setPointSize(pStyle->m_nSize);
	pWidget->setFont(font);
}
