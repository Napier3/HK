/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once
#include "../SttXuiData/SttXuiDataBase.h"

#define WGT_TYPE_FONT "font"

//控件global样式类
class HKWgtStyle : public CExBaseList
{
public:
    CString m_strType{};
    CString m_strBkColor{};//背景
    CString m_strGdColor{};//前景
    long m_nSize{};

public:
    HKWgtStyle();
    ~HKWgtStyle() override;

	void InitStyle(CSttXuiDataBase* pSttXuiDataBase);
};
