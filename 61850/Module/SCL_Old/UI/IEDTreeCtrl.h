#pragma once

#include "..\ReadSCDF.h"

// CIEDTreeCtrl
#define WM_SHOW_IED_DETAIL  (WM_USER+950)

class CIEDTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CIEDTreeCtrl)

private:
	CReadSCDF *m_pReadFile;
	CLIENTIEDMAP *m_pClientIEDMap;
	std::list<CString> *m_pAllIEDName;

	CString m_strSelIEDName;
	CString m_strSelGsName;

public:
	CIEDTreeCtrl();
	virtual ~CIEDTreeCtrl();
	void SetSCDF(CReadSCDF *pReadFile, CLIENTIEDMAP *pClientIEDMap, std::list<CString> *pAllIEDName)	
	{	
		m_pReadFile = pReadFile;	
		m_pClientIEDMap = pClientIEDMap;
		m_pAllIEDName = pAllIEDName;
	}

	void UpdataIEDList(std::list<CString>& IEDList,CLIENTIEDMAP& ClientIEDMap,CThreadProgressInterface *pProgress); // 更新IED列表
	void Filter(const CString &strFilter);
	void GetSelName(CString &strSelIEDName, CString &strSelGsName)
	{
		strSelIEDName = m_strSelIEDName;
		strSelGsName = m_strSelGsName;
	}

	void UpdataIEDList();
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


