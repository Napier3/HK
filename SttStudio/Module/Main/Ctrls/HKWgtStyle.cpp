#include "HKWgtStyle.h"
#include "../SttXuiData/SttXuiDataFont.h"

HKWgtStyle::HKWgtStyle(){}

HKWgtStyle::~HKWgtStyle(){}

void HKWgtStyle::InitStyle(CSttXuiDataBase* pSttXuiDataBase)
{
	if (pSttXuiDataBase)
	{
		m_strID = pSttXuiDataBase->m_strID;
		m_strName = pSttXuiDataBase->m_strName;
		switch(pSttXuiDataBase->GetClassID())
		{
		case MNGRCLASSID_CSTTXUIDATAFONT: 
			m_strGdColor = ((CSttXuiDataFont*)pSttXuiDataBase)->m_strCr_Text;
			m_strBkColor = ((CSttXuiDataFont*)pSttXuiDataBase)->m_strCr_Back;
			m_nSize = ((CSttXuiDataFont*)pSttXuiDataBase)->m_nSize;
			m_strType = WGT_TYPE_FONT;
			break;
		default:
			break;
		}
	}
}
