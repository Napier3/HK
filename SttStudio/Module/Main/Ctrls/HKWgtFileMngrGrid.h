/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include <QTableWidget>
#include "../Module/HKWgtBase.h"

class HKWgtFileMngrGrid : public HKWgtBase, public QTableWidget
{
public:
    HKWgtFileMngrGrid(QWidget* pParent = nullptr);
    ~HKWgtFileMngrGrid() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
	void LoadFiles(const CString& strPath, const CString& strStyle);
    void InitUI(CExBaseObject *pSttXuiData) override;
	void Clear();
};
