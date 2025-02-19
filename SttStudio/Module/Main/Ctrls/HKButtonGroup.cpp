#include "HKButton.h"
#include "HKButtonGroup.h"
#include "../Module/HKWgtFactory.h"

HKButtonGroup::HKButtonGroup(QWidget* pParent)
{
	m_pParent = pParent;
	setParent(pParent);
}

HKButtonGroup::~HKButtonGroup(){}

void HKButtonGroup::InitTestBtnsGroup(CExBaseObject *pSttXuiData)
{
	CSttXuiDataTestBtnsGroup* pData = (CSttXuiDataTestBtnsGroup*)pSttXuiData;
	setObjectName(pData->m_strID);
	setGeometry(pData->m_nX*g_dUIShowCoef, pData->m_nY*g_dUIShowCoef, pData->m_nCx*g_dUIShowCoef, pData->m_nCy*g_dUIShowCoef);
    HKWgtStyle* pStyle = GetWgtStyle(WGT_TYPE_FONT, pData->m_strFont);
	SetWgtStyle(this, pStyle);
}

void HKButtonGroup::InitBtnsGroup(CExBaseObject *pSttXuiData)
{
	CSttXuiDataBtnsGroup* pData = (CSttXuiDataBtnsGroup*)pSttXuiData;
	setObjectName(pData->m_strID);
	setGeometry(pData->m_nX*g_dUIShowCoef, pData->m_nY*g_dUIShowCoef, pData->m_nCx*g_dUIShowCoef, pData->m_nCy*g_dUIShowCoef);
    HKWgtStyle* pStyle = GetWgtStyle(WGT_TYPE_FONT, pData->m_strFont);
	SetWgtStyle(this, pStyle);
}

void HKButtonGroup::InitUIOwn(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataBase* pData = (CSttXuiDataBase*)pSttXuiData;
		if(pData->GetClassID() == MNGRCLASSID_CSTTXUIDATATESTBTNSGROUP)
		{
			InitTestBtnsGroup(pSttXuiData);
		}
		else
		{
			InitBtnsGroup(pSttXuiData);
		}
	}
}

void HKButtonGroup::InitTestBtnsGroupChildren(CExBaseObject *pSttXuiData)
{
	CSttXuiDataTestBtnsGroup* pData = (CSttXuiDataTestBtnsGroup*)pSttXuiData;
	long nInset = pData->m_nInset*g_dUIShowCoef;
	long nX = 0;
	long nCy = pData->m_nCy;
	POS pos = pData->GetHeadPosition();
	while (pos)
	{
		CSttXuiDataBase* pNode = (CSttXuiDataBase*)pData->GetNext(pos);
        HKButton* pWgt = (HKButton*)HKWgtFactory::CreateHKWgt(pNode, this);
		pWgt->CalcGeometry(nX, nCy, nInset);
	}
}

void HKButtonGroup::InitBtnsGroupChildren(CExBaseObject *pSttXuiData)
{
	CSttXuiDataBtnsGroup* pData = (CSttXuiDataBtnsGroup*)pSttXuiData;
	long nInset = pData->m_nInset*g_dUIShowCoef;
	long nX = 0;
	long nCy = pData->m_nCy*g_dUIShowCoef;
	POS pos = pData->GetHeadPosition();
	while (pos)
	{
		CSttXuiDataBase* pNode = (CSttXuiDataBase*)pData->GetNext(pos);
        HKButton* pWgt = (HKButton*)HKWgtFactory::CreateHKWgt(pNode, this);
		pWgt->CalcGeometry(nX, nCy, nInset);
	}
}

void HKButtonGroup::InitUIChildren(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataBase* pData = (CSttXuiDataBase*)pSttXuiData;
		if(pData->GetClassID() == MNGRCLASSID_CSTTXUIDATATESTBTNSGROUP)
		{
			InitTestBtnsGroupChildren(pSttXuiData);
		}
		else
		{
			InitBtnsGroupChildren(pSttXuiData);
		}
	}
}
