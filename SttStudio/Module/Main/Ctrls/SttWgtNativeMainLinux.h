#pragma once

#include <QWidget>
#include "../../../Module/BaseClass/ExBaseList.h"
#include "../SttXuiData/SttXuiDataMainConfig.h"
#include "../Module/SttWgtBase.h"

class QSttWgtNativeMainLinux : public QWidget
{
public:
    QSttWgtNativeMainLinux(QWidget* pParent = nullptr);
	virtual ~QSttWgtNativeMainLinux();

	CExBaseList* m_pGlobalStyle;
	CExBaseList* m_pAutoTestSettings;
	CSttXuiDataMainConfig* m_pMainConfig;

public:
	virtual void InitUI(CString strFilePath, CSttXuiDataMainConfig* pSttXuiDataMainConfig);
	void SaveXmlFile();
};

extern QSttWgtNativeMainLinux* m_gQSttWgtNativeMainLinux;
