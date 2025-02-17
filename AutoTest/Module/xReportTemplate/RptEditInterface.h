#include "..\..\..\module\baseclass\exbaseobject.h"

class CRptData;
class CRptItems;
class CRptItem;
class CReportMap;

class CRptEditInterface :	public CExBaseObject
{
public:
	CRptEditInterface(void);
	~CRptEditInterface(void);

public:
	// Ù–‘
	CString			m_strReportMapFile;
	CString			m_strReportTemplateFile;
	CString			m_strPath;
	CReportMap*		m_pReportMap;
	CGuideBook*		m_pGuideBook;
	BOOL            m_bHasModified; 
	BOOL			m_bSave;
	BOOL			m_bTreeChange;

public:
	//File Mathods
	virtual long Open(const CString &strGuideBookFile) = 0;
	virtual long Save() = 0;
	virtual long Close(BOOL bSave) = 0;

	//Bkmk Mathods
	virtual long LocateBkmk(const CString &  strBkmk) = 0;
	virtual long LocateBkmk(CRptData *pData, LONG nIndex) = 0;

	virtual CExBaseObject* FindRptBkmk(const CString & strBkmk);
	virtual long DeleteBkmk(const CString & strBkmk);
	virtual long DeleteBkmk(CExBaseObject *pObj);
	virtual long AddBkmk(CString strBkmk);

	//GuideBook Mathods
	CExBaseObject* AddRptData(CGbItemBase *pItem, const SystemTool::IShortDataPtr &oData,long nPrecision);
	CExBaseObject* AddRptData(CGbItemBase *pItem, const SystemTool::IValuePtr &oValue,long nPrecision);
	CExBaseObject* AddRptData(CGbItemBase* pItem,CString strName, CString strID, long nPrecision);
	CExBaseObject* AddRptData(CGbItemBase* pItem,CExBaseObject* pObj, long nPrecision);
	CExBaseObject* AddRptData(CGbItemBase* pItem, CString strID, long nPrecision);
	CRptItem* InsertMapItemByGbItem(CGbItemBase* pItem);
	CRptItem* FindMapItemByGbItem(CGbItemBase* pItem);

};
