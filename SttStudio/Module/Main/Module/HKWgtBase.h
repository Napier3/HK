/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once

#include "../Ctrls/HKWgtStyle.h"
#include "../../../Module/BaseClass/ExBaseList.h"
#include <QWidget>
#include <QFont>

class HKWgtBase
{
public:
    HKWgtBase(QWidget* pParent = nullptr);
    virtual ~HKWgtBase() {}

public:
	QWidget* m_pParent;
    HKWgtBase* m_pWgtRef;
	CExBaseObject* m_pXuiData;

public:
	virtual void InitUI(CExBaseObject *pSttXuiData);
    virtual void InitUIOwn(CExBaseObject *pSttXuiData) {}
    virtual void InitUIChildren(CExBaseObject *pSttXuiData) {}
    virtual HKWgtBase* FindWgtBase(CExBaseObject *pXuiData);
    virtual HKWgtStyle* GetWgtStyle(const CString& strStyleType, const CString& strStyleID);
    virtual void SetWgtStyle(QWidget* pWidget, HKWgtStyle* pStyle);
};

extern QFont *g_pSttGlobalFont; 
