#include <QMouseEvent>
#include "HKButton.h"
#include "../SttXuiData/SttXuiDataButton.h"
#include "../Module/HKWgtCmdExecTool.h"
#include "../../../../Module/API/GlobalConfigApi.h"
#include "HKWgtLinux.h"

HKButton::HKButton(QWidget* pParent)
{
	m_pParent = pParent;
	setParent(pParent);
}

HKButton::~HKButton(){}

void HKButton::CalcGeometry(long& nX, long nCy, long nInset)
{
	CSttXuiDataButton* pData = (CSttXuiDataButton*)m_pXuiData;
	long nTempCy = nCy - 2 * nInset;
	long nWidth = 0;
	if(pData->m_strPic.GetLength())
	{
		setGeometry(nX, nInset, nTempCy, nTempCy);
		setIconSize(QSize(nTempCy / 2 + 2 * nInset, nTempCy / 2 + 2 * nInset));
		nWidth = nTempCy;
	}
	else
	{
		long nCount = pData->m_strName.GetLength();
		setGeometry(nX, nInset, (nCount + 2) * 20, nTempCy);
		nWidth = (nCount + 2) * 20;
	}
	nX = nX + nWidth + nInset;
}

void HKButton::InitUIOwn(CExBaseObject *pSttXuiData)
{
	if(pSttXuiData)
	{
		CSttXuiDataButton* pData = (CSttXuiDataButton*)pSttXuiData;
		setObjectName(pData->m_strID);

		CSttXuiDataCmd *pChildCmd = (CSttXuiDataCmd*)pData->FindByClassID(MNGRCLASSID_CSTTXUIDATACMD);

        if ((pChildCmd != NULL)&&(pChildCmd->m_strID.IsEmpty()))//命令ID为空,按钮不可用
		{
			setEnabled(false);
		}
		
		if(pData->m_strPic.GetLength())
		{
			QIcon image;
			CString strPath = _P_GetResourcePath() + pData->m_strPic;
			image.addFile(strPath);
			setIcon(image);
			setAutoRaise(true);
			setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

		}

		setText(pData->m_strName);
	}
}

void HKButton::OnClick()
{
	CSttXuiDataBase* pXuiData = (CSttXuiDataBase*)m_pXuiData;
	if(pXuiData)
	{
		POS pos = pXuiData->GetHeadPosition();
		while (pos)
		{
			CSttXuiDataCmd* pCmd = (CSttXuiDataCmd*)pXuiData->GetNext(pos);
            HKWgtCmdExecTool::ExecCmd(pCmd->m_strType, pCmd->m_strID, pCmd->m_strData_Src, pCmd->m_strArgv);
		}
	}
}

void HKButton::mousePressEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
	{
        m_gHKWgtLinux->setEnabled(false);
        OnClick();
        m_gHKWgtLinux->setEnabled(true);
	}
}
