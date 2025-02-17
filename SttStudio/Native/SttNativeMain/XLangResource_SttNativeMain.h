#pragma once

#include "../../../Module/XLanguage/XLanguageMngr.h"
#include "../../../AutoTest/Module/XLanguageResourceAts.h"

class CXLangResource_SttNativeMain : public CXLanguageResourceAtsBase
{
public:
	CXLangResource_SttNativeMain();
    virtual ~CXLangResource_SttNativeMain() override;

private:
    CXLanguage m_oXLangRs_Test;
	static const CString  g_strXLangRs_Test;

public:
	CXLangItem* rs_AddString(const CString &strID, CString *pstrString);
    virtual void InitLangRsByFile() override;
    virtual void RegisterLanguageResource() override;

public:
	static CString g_sLangID_Native_ChooseOpenFile;
	static CString g_sLangTxt_Native_ChooseOpenFile;
};
