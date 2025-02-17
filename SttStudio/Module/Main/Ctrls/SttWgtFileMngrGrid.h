#pragma once

#include <QTableWidget>
#include "../Module/SttWgtBase.h"

class QSttWgtFileMngrGrid : public QSttWgtBase, public QTableWidget
{
public:
    QSttWgtFileMngrGrid(QWidget* pParent = nullptr);
    ~QSttWgtFileMngrGrid() override;

public:
    void InitUIOwn(CExBaseObject *pSttXuiData) override;
	void LoadFiles(const CString& strPath, const CString& strStyle);
	void InitUI();
	void Clear();
};
