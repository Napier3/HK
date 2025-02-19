/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QWidget>
#include "../../../Module/BaseClass/ExBaseList.h"
#include "../SttXuiData/SttXuiDataMainConfig.h"
#include "../Module/HKWgtBase.h"

class HKWgtLinux : public QWidget
{
public:
    HKWgtLinux(QWidget* pParent = nullptr);
    virtual ~HKWgtLinux();

	CExBaseList* m_pGlobalStyle;
	CExBaseList* m_pAutoTestSettings;
	CSttXuiDataMainConfig* m_pMainConfig;

public:
	virtual void InitUI(CString strFilePath, CSttXuiDataMainConfig* pSttXuiDataMainConfig);
	void SaveXmlFile();
};

extern HKWgtLinux* m_gHKWgtLinux;
