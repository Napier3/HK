/*
 *Shandong HuanKe copyright 2025
 *Author: Eric
*/
#pragma once
#include "../SttXuiData/SttXuiDataBase.h"

#define WGT_TYPE_FONT "font"

//�ؼ�global��ʽ��
class HKWgtStyle : public CExBaseList
{
public:
    CString m_strType{};
    CString m_strBkColor{};//����
    CString m_strGdColor{};//ǰ��
    long m_nSize{};

public:
    HKWgtStyle();
    ~HKWgtStyle() override;

	void InitStyle(CSttXuiDataBase* pSttXuiDataBase);
};
