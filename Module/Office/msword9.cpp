// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "msword9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


	
/////////////////////////////////////////////////////////////////////////////
// _Application properties

/////////////////////////////////////////////////////////////////////////////
// _Application operations
namespace MSWord
{

	LPDISPATCH _Application::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Application::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetDocuments()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetWindows()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetActiveDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetActiveWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetSelection()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetWordBasic()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetRecentFiles()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetNormalTemplate()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetSystem()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetAutoCorrect()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetLandscapeFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetPortraitFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetLanguages()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetAssistant()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetBrowser()
	{
		LPDISPATCH result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetFileConverters()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetMailingLabel()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetDialogs()
	{
		LPDISPATCH result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetCaptionLabels()
	{
		LPDISPATCH result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetAutoCaptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetAddIns()
	{
		LPDISPATCH result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetVisible()
	{
		BOOL result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetVisible(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _Application::GetVersion()
	{
		CString result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetScreenUpdating()
	{
		BOOL result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetScreenUpdating(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Application::GetPrintPreview()
	{
		BOOL result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetPrintPreview(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Application::GetTasks()
	{
		LPDISPATCH result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetDisplayStatusBar()
	{
		BOOL result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayStatusBar(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Application::GetSpecialMode()
	{
		BOOL result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long _Application::GetUsableWidth()
	{
		long result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long _Application::GetUsableHeight()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetMathCoprocessorAvailable()
	{
		BOOL result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetMouseAvailable()
	{
		BOOL result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	VARIANT _Application::GetInternational(long Index)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
			Index);
		return result;
	}

	CString _Application::GetBuild()
	{
		CString result;
		InvokeHelper(0x2f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetCapsLock()
	{
		BOOL result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetNumLock()
	{
		BOOL result;
		InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetUserName_()
	{
		CString result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetUserName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Application::GetUserInitials()
	{
		CString result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetUserInitials(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Application::GetUserAddress()
	{
		CString result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetUserAddress(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH _Application::GetMacroContainer()
	{
		LPDISPATCH result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetDisplayRecentFiles()
	{
		BOOL result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayRecentFiles(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x38, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Application::GetCommandBars()
	{
		LPDISPATCH result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetSynonymInfo(LPCTSTR Word, VARIANT* LanguageID)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			Word, LanguageID);
		return result;
	}

	LPDISPATCH _Application::GetVbe()
	{
		LPDISPATCH result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetDefaultSaveFormat()
	{
		CString result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDefaultSaveFormat(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH _Application::GetListGalleries()
	{
		LPDISPATCH result;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetActivePrinter()
	{
		CString result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetActivePrinter(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH _Application::GetTemplates()
	{
		LPDISPATCH result;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetCustomizationContext()
	{
		LPDISPATCH result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Application::SetCustomizationContext(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Application::GetKeyBindings()
	{
		LPDISPATCH result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetKeysBoundTo(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			KeyCategory, Command, CommandParameter);
		return result;
	}

	LPDISPATCH _Application::GetFindKey(long KeyCode, VARIANT* KeyCode2)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}

	CString _Application::GetCaption()
	{
		CString result;
		InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetCaption(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Application::GetPath()
	{
		CString result;
		InvokeHelper(0x51, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetDisplayScrollBars()
	{
		BOOL result;
		InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayScrollBars(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x52, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _Application::GetStartupPath()
	{
		CString result;
		InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetStartupPath(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _Application::GetBackgroundSavingStatus()
	{
		long result;
		InvokeHelper(0x55, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long _Application::GetBackgroundPrintingStatus()
	{
		long result;
		InvokeHelper(0x56, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long _Application::GetLeft()
	{
		long result;
		InvokeHelper(0x57, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetLeft(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x57, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Application::GetTop()
	{
		long result;
		InvokeHelper(0x58, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetTop(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x58, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Application::GetWidth()
	{
		long result;
		InvokeHelper(0x59, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x59, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Application::GetHeight()
	{
		long result;
		InvokeHelper(0x5a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetHeight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Application::GetWindowState()
	{
		long result;
		InvokeHelper(0x5b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetWindowState(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Application::GetDisplayAutoCompleteTips()
	{
		BOOL result;
		InvokeHelper(0x5c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayAutoCompleteTips(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Application::GetOptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Application::GetDisplayAlerts()
	{
		long result;
		InvokeHelper(0x5e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayAlerts(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH _Application::GetCustomDictionaries()
	{
		LPDISPATCH result;
		InvokeHelper(0x5f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetPathSeparator()
	{
		CString result;
		InvokeHelper(0x60, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetStatusBar(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x61, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Application::GetMAPIAvailable()
	{
		BOOL result;
		InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetDisplayScreenTips()
	{
		BOOL result;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDisplayScreenTips(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _Application::GetEnableCancelKey()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetEnableCancelKey(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Application::GetUserControl()
	{
		BOOL result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetFileSearch()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Application::GetMailSystem()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString _Application::GetDefaultTableSeparator()
	{
		CString result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDefaultTableSeparator(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Application::GetShowVisualBasicEditor()
	{
		BOOL result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetShowVisualBasicEditor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _Application::GetBrowseExtraFileTypes()
	{
		CString result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Application::SetBrowseExtraFileTypes(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Application::GetIsObjectValid(LPDISPATCH Object)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
			Object);
		return result;
	}

	LPDISPATCH _Application::GetHangulHanjaDictionaries()
	{
		LPDISPATCH result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetMailMessage()
	{
		LPDISPATCH result;
		InvokeHelper(0x15c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetFocusInMailHeader()
	{
		BOOL result;
		InvokeHelper(0x182, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::Quit(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 SaveChanges, OriginalFormat, RouteDocument);
	}

	void _Application::ScreenRefresh()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::LookupNameProperties(LPCTSTR Name)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name);
	}

	void _Application::SubstituteFont(LPCTSTR UnavailableFont, LPCTSTR SubstituteFont)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 UnavailableFont, SubstituteFont);
	}

	BOOL _Application::Repeat(VARIANT* Times)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x131, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Times);
		return result;
	}

	void _Application::DDEExecute(long Channel, LPCTSTR Command)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR;
		InvokeHelper(0x136, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel, Command);
	}

	long _Application::DDEInitiate(LPCTSTR App, LPCTSTR Topic)
	{
		long result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x137, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			App, Topic);
		return result;
	}

	void _Application::DDEPoke(long Channel, LPCTSTR Item, LPCTSTR Data)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_BSTR;
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel, Item, Data);
	}

	CString _Application::DDERequest(long Channel, LPCTSTR Item)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR;
		InvokeHelper(0x139, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			Channel, Item);
		return result;
	}

	void _Application::DDETerminate(long Channel)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel);
	}

	void _Application::DDETerminateAll()
	{
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long _Application::BuildKeyCode(long Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4)
	{
		long result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x13c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Arg1, Arg2, Arg3, Arg4);
		return result;
	}

	CString _Application::KeyString(long KeyCode, VARIANT* KeyCode2)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}

	void _Application::OrganizerCopy(LPCTSTR Source, LPCTSTR Destination, LPCTSTR Name, long Object)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Source, Destination, Name, Object);
	}

	void _Application::OrganizerDelete(LPCTSTR Source, LPCTSTR Name, long Object)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x13f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Source, Name, Object);
	}

	void _Application::OrganizerRename(LPCTSTR Source, LPCTSTR Name, LPCTSTR NewName, long Object)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Source, Name, NewName, Object);
	}

	CString _Application::GetAddress(VARIANT* Name, VARIANT* AddressProperties, VARIANT* UseAutoText, VARIANT* DisplaySelectDialog, VARIANT* SelectDialog, VARIANT* CheckNamesDialog, VARIANT* RecentAddressesChoice, VARIANT* UpdateRecentAddresses)
	{
		CString result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			Name, AddressProperties, UseAutoText, DisplaySelectDialog, SelectDialog, CheckNamesDialog, RecentAddressesChoice, UpdateRecentAddresses);
		return result;
	}

	BOOL _Application::CheckGrammar(LPCTSTR String)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x143, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			String);
		return result;
	}

	BOOL _Application::CheckSpelling(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, 
			VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Word, CustomDictionary, IgnoreUppercase, MainDictionary, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
		return result;
	}

	void _Application::ResetIgnoreAll()
	{
		InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Application::GetSpellingSuggestions(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
			VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x147, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Word, CustomDictionary, IgnoreUppercase, MainDictionary, SuggestionMode, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, 
			CustomDictionary10);
		return result;
	}

	void _Application::GoBack()
	{
		InvokeHelper(0x148, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::Help(VARIANT* HelpType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x149, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 HelpType);
	}

	void _Application::AutomaticChange()
	{
		InvokeHelper(0x14a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::ShowMe()
	{
		InvokeHelper(0x14b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::HelpTool()
	{
		InvokeHelper(0x14c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Application::NewWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x159, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Application::ListCommands(BOOL ListAllCommands)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x15a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ListAllCommands);
	}

	void _Application::ShowClipboard()
	{
		InvokeHelper(0x15d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::OnTime(VARIANT* When, LPCTSTR Name, VARIANT* Tolerance)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x15e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 When, Name, Tolerance);
	}

	void _Application::NextLetter()
	{
		InvokeHelper(0x15f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	short _Application::MountVolume(LPCTSTR Zone, LPCTSTR Server, LPCTSTR Volume, VARIANT* User, VARIANT* UserPassword, VARIANT* VolumePassword)
	{
		short result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x161, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
			Zone, Server, Volume, User, UserPassword, VolumePassword);
		return result;
	}

	CString _Application::CleanString(LPCTSTR String)
	{
		CString result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x162, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			String);
		return result;
	}

	void _Application::SendFax()
	{
		InvokeHelper(0x164, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::ChangeFileOpenDirectory(LPCTSTR Path)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x165, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Path);
	}

	void _Application::GoForward()
	{
		InvokeHelper(0x167, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::Move(long Left, long Top)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x168, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Left, Top);
	}

	void _Application::Resize(long Width, long Height)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x169, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Width, Height);
	}

	float _Application::InchesToPoints(float Inches)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x172, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Inches);
		return result;
	}

	float _Application::CentimetersToPoints(float Centimeters)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x173, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Centimeters);
		return result;
	}

	float _Application::MillimetersToPoints(float Millimeters)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x174, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Millimeters);
		return result;
	}

	float _Application::PicasToPoints(float Picas)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x175, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Picas);
		return result;
	}

	float _Application::LinesToPoints(float Lines)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x176, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Lines);
		return result;
	}

	float _Application::PointsToInches(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17c, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Application::PointsToCentimeters(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17d, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Application::PointsToMillimeters(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17e, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Application::PointsToPicas(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17f, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Application::PointsToLines(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x180, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	void _Application::Activate()
	{
		InvokeHelper(0x181, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	float _Application::PointsToPixels(float Points, VARIANT* fVertical)
	{
		float result;
		static BYTE parms[] =
			VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x183, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points, fVertical);
		return result;
	}

	float _Application::PixelsToPoints(float Pixels, VARIANT* fVertical)
	{
		float result;
		static BYTE parms[] =
			VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x184, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Pixels, fVertical);
		return result;
	}

	void _Application::KeyboardLatin()
	{
		InvokeHelper(0x190, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::KeyboardBidi()
	{
		InvokeHelper(0x191, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Application::ToggleKeyboard()
	{
		InvokeHelper(0x192, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long _Application::Keyboard(long LangId)
	{
		long result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1be, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			LangId);
		return result;
	}

	CString _Application::ProductCode()
	{
		CString result;
		InvokeHelper(0x194, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::DefaultWebOptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x195, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Application::SetDefaultTheme(LPCTSTR Name, long DocumentType)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_I4;
		InvokeHelper(0x19e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, DocumentType);
	}

	CString _Application::GetDefaultTheme(long DocumentType)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1a0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			DocumentType);
		return result;
	}

	LPDISPATCH _Application::GetEmailOptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x185, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Application::GetLanguage()
	{
		long result;
		InvokeHelper(0x187, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetCOMAddIns()
	{
		LPDISPATCH result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Application::GetCheckLanguage()
	{
		BOOL result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Application::SetCheckLanguage(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Application::GetLanguageSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Application::GetAnswerWizard()
	{
		LPDISPATCH result;
		InvokeHelper(0x199, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Application::GetFeatureInstall()
	{
		long result;
		InvokeHelper(0x1bf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Application::SetFeatureInstall(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1bf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void _Application::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
			VARIANT* FileName, VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
			VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, FileName, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
	}

	VARIANT _Application::Run(LPCTSTR MacroName, VARIANT* varg1, VARIANT* varg2, VARIANT* varg3, VARIANT* varg4, VARIANT* varg5, VARIANT* varg6, VARIANT* varg7, VARIANT* varg8, VARIANT* varg9, VARIANT* varg10, VARIANT* varg11, VARIANT* varg12, VARIANT* varg13, 
			VARIANT* varg14, VARIANT* varg15, VARIANT* varg16, VARIANT* varg17, VARIANT* varg18, VARIANT* varg19, VARIANT* varg20, VARIANT* varg21, VARIANT* varg22, VARIANT* varg23, VARIANT* varg24, VARIANT* varg25, VARIANT* varg26, VARIANT* varg27, 
			VARIANT* varg28, VARIANT* varg29, VARIANT* varg30)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bd, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
			MacroName, varg1, varg2, varg3, varg4, varg5, varg6, varg7, varg8, varg9, varg10, varg11, varg12, varg13, varg14, varg15, varg16, varg17, varg18, varg19, varg20, varg21, varg22, varg23, varg24, varg25, varg26, varg27, varg28, varg29, 
			varg30);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// _Global properties

	/////////////////////////////////////////////////////////////////////////////
	// _Global operations

	LPDISPATCH _Global::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Global::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Global::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetDocuments()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetWindows()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetActiveDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetActiveWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetSelection()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetWordBasic()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Global::GetPrintPreview()
	{
		BOOL result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Global::SetPrintPreview(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Global::GetRecentFiles()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetNormalTemplate()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetSystem()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetAutoCorrect()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetLandscapeFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetPortraitFontNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetLanguages()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetAssistant()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetFileConverters()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetDialogs()
	{
		LPDISPATCH result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetCaptionLabels()
	{
		LPDISPATCH result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetAutoCaptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetAddIns()
	{
		LPDISPATCH result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetTasks()
	{
		LPDISPATCH result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetMacroContainer()
	{
		LPDISPATCH result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetCommandBars()
	{
		LPDISPATCH result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetSynonymInfo(LPCTSTR Word, VARIANT* LanguageID)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			Word, LanguageID);
		return result;
	}

	LPDISPATCH _Global::GetVbe()
	{
		LPDISPATCH result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetListGalleries()
	{
		LPDISPATCH result;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Global::GetActivePrinter()
	{
		CString result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Global::SetActivePrinter(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH _Global::GetTemplates()
	{
		LPDISPATCH result;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetCustomizationContext()
	{
		LPDISPATCH result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Global::SetCustomizationContext(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Global::GetKeyBindings()
	{
		LPDISPATCH result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetKeysBoundTo(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			KeyCategory, Command, CommandParameter);
		return result;
	}

	LPDISPATCH _Global::GetFindKey(long KeyCode, VARIANT* KeyCode2)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}

	LPDISPATCH _Global::GetOptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetCustomDictionaries()
	{
		LPDISPATCH result;
		InvokeHelper(0x5f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Global::SetStatusBar(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x61, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Global::GetShowVisualBasicEditor()
	{
		BOOL result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Global::SetShowVisualBasicEditor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Global::GetIsObjectValid(LPDISPATCH Object)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
			Object);
		return result;
	}

	LPDISPATCH _Global::GetHangulHanjaDictionaries()
	{
		LPDISPATCH result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Global::Repeat(VARIANT* Times)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x131, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Times);
		return result;
	}

	void _Global::DDEExecute(long Channel, LPCTSTR Command)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR;
		InvokeHelper(0x136, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel, Command);
	}

	long _Global::DDEInitiate(LPCTSTR App, LPCTSTR Topic)
	{
		long result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x137, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			App, Topic);
		return result;
	}

	void _Global::DDEPoke(long Channel, LPCTSTR Item, LPCTSTR Data)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_BSTR;
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel, Item, Data);
	}

	CString _Global::DDERequest(long Channel, LPCTSTR Item)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR;
		InvokeHelper(0x139, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			Channel, Item);
		return result;
	}

	void _Global::DDETerminate(long Channel)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Channel);
	}

	void _Global::DDETerminateAll()
	{
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long _Global::BuildKeyCode(long Arg1, VARIANT* Arg2, VARIANT* Arg3, VARIANT* Arg4)
	{
		long result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x13c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Arg1, Arg2, Arg3, Arg4);
		return result;
	}

	CString _Global::KeyString(long KeyCode, VARIANT* KeyCode2)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}

	BOOL _Global::CheckSpelling(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, 
			VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Word, CustomDictionary, IgnoreUppercase, MainDictionary, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
		return result;
	}

	LPDISPATCH _Global::GetSpellingSuggestions(LPCTSTR Word, VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
			VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x147, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Word, CustomDictionary, IgnoreUppercase, MainDictionary, SuggestionMode, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, 
			CustomDictionary10);
		return result;
	}

	void _Global::Help(VARIANT* HelpType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x149, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 HelpType);
	}

	LPDISPATCH _Global::NewWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x159, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Global::CleanString(LPCTSTR String)
	{
		CString result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x162, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			String);
		return result;
	}

	void _Global::ChangeFileOpenDirectory(LPCTSTR Path)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x163, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Path);
	}

	float _Global::InchesToPoints(float Inches)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x172, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Inches);
		return result;
	}

	float _Global::CentimetersToPoints(float Centimeters)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x173, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Centimeters);
		return result;
	}

	float _Global::MillimetersToPoints(float Millimeters)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x174, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Millimeters);
		return result;
	}

	float _Global::PicasToPoints(float Picas)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x175, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Picas);
		return result;
	}

	float _Global::LinesToPoints(float Lines)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x176, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Lines);
		return result;
	}

	float _Global::PointsToInches(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17c, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Global::PointsToCentimeters(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17d, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Global::PointsToMillimeters(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17e, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Global::PointsToPicas(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x17f, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Global::PointsToLines(float Points)
	{
		float result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x180, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points);
		return result;
	}

	float _Global::PointsToPixels(float Points, VARIANT* fVertical)
	{
		float result;
		static BYTE parms[] =
			VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x181, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Points, fVertical);
		return result;
	}

	float _Global::PixelsToPoints(float Pixels, VARIANT* fVertical)
	{
		float result;
		static BYTE parms[] =
			VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x182, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
			Pixels, fVertical);
		return result;
	}

	LPDISPATCH _Global::GetLanguageSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Global::GetAnswerWizard()
	{
		LPDISPATCH result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// FontNames properties

	/////////////////////////////////////////////////////////////////////////////
	// FontNames operations

	LPUNKNOWN FontNames::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long FontNames::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FontNames::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FontNames::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FontNames::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString FontNames::Item(long Index)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Languages properties

	/////////////////////////////////////////////////////////////////////////////
	// Languages operations

	LPUNKNOWN Languages::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Languages::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Languages::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Languages::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Languages::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Languages::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Language properties

	/////////////////////////////////////////////////////////////////////////////
	// Language operations

	LPDISPATCH Language::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Language::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Language::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Language::GetId()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString Language::GetNameLocal()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString Language::GetName()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Language::GetActiveGrammarDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Language::GetActiveHyphenationDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Language::GetActiveSpellingDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Language::GetActiveThesaurusDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Language::GetDefaultWritingStyle()
	{
		CString result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Language::SetDefaultWritingStyle(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	VARIANT Language::GetWritingStyleList()
	{
		VARIANT result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	long Language::GetSpellingDictionaryType()
	{
		long result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Language::SetSpellingDictionaryType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Documents properties

	/////////////////////////////////////////////////////////////////////////////
	// Documents operations

	LPUNKNOWN Documents::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Documents::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Documents::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Documents::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Documents::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Documents::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void Documents::Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 SaveChanges, OriginalFormat, RouteDocument);
	}

	void Documents::Save(VARIANT* NoPrompt, VARIANT* OriginalFormat)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NoPrompt, OriginalFormat);
	}

	LPDISPATCH Documents::Add(VARIANT* Template, VARIANT* NewTemplate, VARIANT* DocumentType, VARIANT* Visible)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Template, NewTemplate, DocumentType, Visible);
		return result;
	}

	LPDISPATCH Documents::Open(VARIANT* FileName, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, 
			VARIANT* WritePasswordTemplate, VARIANT* Format, VARIANT* Encoding, VARIANT* Visible)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, ConfirmConversions, ReadOnly, AddToRecentFiles, PasswordDocument, PasswordTemplate, Revert, WritePasswordDocument, WritePasswordTemplate, Format, Encoding, Visible);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// _Document properties

	/////////////////////////////////////////////////////////////////////////////
	// _Document operations

	CString _Document::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Document::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetBuiltInDocumentProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetCustomDocumentProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Document::GetPath()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetBookmarks()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetFootnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetEndnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetComments()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Document::GetType()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetAutoHyphenation()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetAutoHyphenation(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetHyphenateCaps()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetHyphenateCaps(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _Document::GetHyphenationZone()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetHyphenationZone(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Document::GetConsecutiveHyphensLimit()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetConsecutiveHyphensLimit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH _Document::GetSections()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetWords()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetSentences()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetCharacters()
	{
		LPDISPATCH result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetFormFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetStyles()
	{
		LPDISPATCH result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetFrames()
	{
		LPDISPATCH result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetTablesOfFigures()
	{
		LPDISPATCH result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetVariables()
	{
		LPDISPATCH result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetMailMerge()
	{
		LPDISPATCH result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetEnvelope()
	{
		LPDISPATCH result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _Document::GetFullName()
	{
		CString result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetRevisions()
	{
		LPDISPATCH result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetTablesOfContents()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetTablesOfAuthorities()
	{
		LPDISPATCH result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetPageSetup()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPageSetup(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Document::GetWindows()
	{
		LPDISPATCH result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetHasRoutingSlip()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetHasRoutingSlip(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetRoutingSlip()
	{
		LPDISPATCH result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetRouted()
	{
		BOOL result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetTablesOfAuthoritiesCategories()
	{
		LPDISPATCH result;
		InvokeHelper(0x26, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetIndexes()
	{
		LPDISPATCH result;
		InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetSaved()
	{
		BOOL result;
		InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSaved(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetContent()
	{
		LPDISPATCH result;
		InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetActiveWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x2a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Document::GetKind()
	{
		long result;
		InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetKind(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Document::GetReadOnly()
	{
		BOOL result;
		InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetSubdocuments()
	{
		LPDISPATCH result;
		InvokeHelper(0x2d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetIsMasterDocument()
	{
		BOOL result;
		InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	float _Document::GetDefaultTabStop()
	{
		float result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetDefaultTabStop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL _Document::GetEmbedTrueTypeFonts()
	{
		BOOL result;
		InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetEmbedTrueTypeFonts(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x32, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetSaveFormsData()
	{
		BOOL result;
		InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSaveFormsData(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x33, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetReadOnlyRecommended()
	{
		BOOL result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetReadOnlyRecommended(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x34, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetSaveSubsetFonts()
	{
		BOOL result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSaveSubsetFonts(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x35, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetCompatibility(long Type)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
			Type);
		return result;
	}

	void _Document::SetCompatibility(long Type, BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BOOL;
		InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 Type, bNewValue);
	}

	LPDISPATCH _Document::GetStoryRanges()
	{
		LPDISPATCH result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetCommandBars()
	{
		LPDISPATCH result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetIsSubdocument()
	{
		BOOL result;
		InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long _Document::GetSaveFormat()
	{
		long result;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long _Document::GetProtectionType()
	{
		long result;
		InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetHyperlinks()
	{
		LPDISPATCH result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetShapes()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetListTemplates()
	{
		LPDISPATCH result;
		InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetLists()
	{
		LPDISPATCH result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetUpdateStylesOnOpen()
	{
		BOOL result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetUpdateStylesOnOpen(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	VARIANT _Document::GetAttachedTemplate()
	{
		VARIANT result;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void _Document::SetAttachedTemplate(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Document::GetInlineShapes()
	{
		LPDISPATCH result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetBackground()
	{
		LPDISPATCH result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Document::SetBackground(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL _Document::GetGrammarChecked()
	{
		BOOL result;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGrammarChecked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetSpellingChecked()
	{
		BOOL result;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSpellingChecked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetShowGrammaticalErrors()
	{
		BOOL result;
		InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetShowGrammaticalErrors(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetShowSpellingErrors()
	{
		BOOL result;
		InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetShowSpellingErrors(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetVersions()
	{
		LPDISPATCH result;
		InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetShowSummary()
	{
		BOOL result;
		InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetShowSummary(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _Document::GetSummaryViewMode()
	{
		long result;
		InvokeHelper(0x4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSummaryViewMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Document::GetSummaryLength()
	{
		long result;
		InvokeHelper(0x4e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSummaryLength(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Document::GetPrintFractionalWidths()
	{
		BOOL result;
		InvokeHelper(0x4f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPrintFractionalWidths(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetPrintPostScriptOverText()
	{
		BOOL result;
		InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPrintPostScriptOverText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetContainer()
	{
		LPDISPATCH result;
		InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetPrintFormsData()
	{
		BOOL result;
		InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPrintFormsData(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetListParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x54, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPassword(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x55, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	void _Document::SetWritePassword(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x56, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Document::GetHasPassword()
	{
		BOOL result;
		InvokeHelper(0x57, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetWriteReserved()
	{
		BOOL result;
		InvokeHelper(0x58, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString _Document::GetActiveWritingStyle(VARIANT* LanguageID)
	{
		CString result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x5a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
			LanguageID);
		return result;
	}

	void _Document::SetActiveWritingStyle(VARIANT* LanguageID, LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_BSTR;
		InvokeHelper(0x5a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 LanguageID, lpszNewValue);
	}

	BOOL _Document::GetUserControl()
	{
		BOOL result;
		InvokeHelper(0x5c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetUserControl(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetHasMailer()
	{
		BOOL result;
		InvokeHelper(0x5d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetHasMailer(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH _Document::GetMailer()
	{
		LPDISPATCH result;
		InvokeHelper(0x5e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetReadabilityStatistics()
	{
		LPDISPATCH result;
		InvokeHelper(0x60, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetGrammaticalErrors()
	{
		LPDISPATCH result;
		InvokeHelper(0x61, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetSpellingErrors()
	{
		LPDISPATCH result;
		InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetVBProject()
	{
		LPDISPATCH result;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetFormsDesign()
	{
		BOOL result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString _Document::Get_CodeName()
	{
		CString result;
		InvokeHelper(0x80010000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Document::Set_CodeName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x80010000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Document::GetCodeName()
	{
		CString result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetSnapToGrid()
	{
		BOOL result;
		InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSnapToGrid(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetSnapToShapes()
	{
		BOOL result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSnapToShapes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float _Document::GetGridDistanceHorizontal()
	{
		float result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridDistanceHorizontal(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _Document::GetGridDistanceVertical()
	{
		float result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridDistanceVertical(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _Document::GetGridOriginHorizontal()
	{
		float result;
		InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridOriginHorizontal(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _Document::GetGridOriginVertical()
	{
		float result;
		InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridOriginVertical(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x131, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _Document::GetGridSpaceBetweenHorizontalLines()
	{
		long result;
		InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridSpaceBetweenHorizontalLines(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x132, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Document::GetGridSpaceBetweenVerticalLines()
	{
		long result;
		InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridSpaceBetweenVerticalLines(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x133, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Document::GetGridOriginFromMargin()
	{
		BOOL result;
		InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetGridOriginFromMargin(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x134, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetKerningByAlgorithm()
	{
		BOOL result;
		InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetKerningByAlgorithm(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x135, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _Document::GetJustificationMode()
	{
		long result;
		InvokeHelper(0x136, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetJustificationMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x136, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Document::GetFarEastLineBreakLevel()
	{
		long result;
		InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetFarEastLineBreakLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x137, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString _Document::GetNoLineBreakBefore()
	{
		CString result;
		InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Document::SetNoLineBreakBefore(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Document::GetNoLineBreakAfter()
	{
		CString result;
		InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Document::SetNoLineBreakAfter(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _Document::GetTrackRevisions()
	{
		BOOL result;
		InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetTrackRevisions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetPrintRevisions()
	{
		BOOL result;
		InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetPrintRevisions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetShowRevisions()
	{
		BOOL result;
		InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetShowRevisions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void _Document::Close(VARIANT* SaveChanges, VARIANT* OriginalFormat, VARIANT* RouteDocument)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x451, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 SaveChanges, OriginalFormat, RouteDocument);
	}

	void _Document::SaveAs(VARIANT* FileName, VARIANT* FileFormat, VARIANT* LockComments, VARIANT* Password, VARIANT* AddToRecentFiles, VARIANT* WritePassword, VARIANT* ReadOnlyRecommended, VARIANT* EmbedTrueTypeFonts, VARIANT* SaveNativePictureFormat, 
			VARIANT* SaveFormsData, VARIANT* SaveAsAOCELetter)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileName, FileFormat, LockComments, Password, AddToRecentFiles, WritePassword, ReadOnlyRecommended, EmbedTrueTypeFonts, SaveNativePictureFormat, SaveFormsData, SaveAsAOCELetter);
	}

	void _Document::Repaginate()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::FitToPages()
	{
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ManualHyphenation()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::DataForm()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Route()
	{
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Save()
	{
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::SendMail()
	{
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Document::Range(VARIANT* Start, VARIANT* End)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7d0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Start, End);
		return result;
	}

	void _Document::RunAutoMacro(long Which)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Which);
	}

	void _Document::Activate()
	{
		InvokeHelper(0x71, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::PrintPreview()
	{
		InvokeHelper(0x72, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Document::GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What, Which, Count, Name);
		return result;
	}

	BOOL _Document::Undo(VARIANT* Times)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Times);
		return result;
	}

	BOOL _Document::Redo(VARIANT* Times)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Times);
		return result;
	}

	long _Document::ComputeStatistics(long Statistic, VARIANT* IncludeFootnotesAndEndnotes)
	{
		long result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Statistic, IncludeFootnotesAndEndnotes);
		return result;
	}

	void _Document::MakeCompatibilityDefault()
	{
		InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Protect(long Type, VARIANT* NoReset, VARIANT* Password)
	{
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type, NoReset, Password);
	}

	void _Document::Unprotect(VARIANT* Password)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Password);
	}

	void _Document::EditionOptions(long Type, long Option, LPCTSTR Name, VARIANT* Format)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type, Option, Name, Format);
	}

	void _Document::RunLetterWizard(VARIANT* LetterContent, VARIANT* WizardMode)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 LetterContent, WizardMode);
	}

	LPDISPATCH _Document::GetLetterContent()
	{
		LPDISPATCH result;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Document::SetLetterContent(VARIANT* LetterContent)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 LetterContent);
	}

	void _Document::CopyStylesFromTemplate(LPCTSTR Template)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Template);
	}

	void _Document::UpdateStyles()
	{
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::CheckGrammar()
	{
		InvokeHelper(0x83, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
			VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 CustomDictionary, IgnoreUppercase, AlwaysSuggest, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
	}

	void _Document::FollowHyperlink(VARIANT* Address, VARIANT* SubAddress, VARIANT* NewWindow, VARIANT* AddHistory, VARIANT* ExtraInfo, VARIANT* Method, VARIANT* HeaderInfo)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Address, SubAddress, NewWindow, AddHistory, ExtraInfo, Method, HeaderInfo);
	}

	void _Document::AddToFavorites()
	{
		InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Reload()
	{
		InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Document::AutoSummarize(VARIANT* Length, VARIANT* Mode, VARIANT* UpdateProperties)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Length, Mode, UpdateProperties);
		return result;
	}

	void _Document::RemoveNumbers(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	void _Document::ConvertNumbersToText(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	long _Document::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			NumberType, Level);
		return result;
	}

	void _Document::Post()
	{
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ToggleFormsDesign()
	{
		InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Compare(LPCTSTR Name)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name);
	}

	void _Document::UpdateSummaryProperties()
	{
		InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	VARIANT _Document::GetCrossReferenceItems(VARIANT* ReferenceType)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
			ReferenceType);
		return result;
	}

	void _Document::AutoFormat()
	{
		InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ViewCode()
	{
		InvokeHelper(0x95, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ViewPropertyBrowser()
	{
		InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ForwardMailer()
	{
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::Reply()
	{
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ReplyAll()
	{
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::SendMailer(VARIANT* FileFormat, VARIANT* Priority)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileFormat, Priority);
	}

	void _Document::UndoClear()
	{
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::PresentIt()
	{
		InvokeHelper(0xff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::SendFax(LPCTSTR Address, VARIANT* Subject)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Address, Subject);
	}

	void _Document::Merge(LPCTSTR FileName)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileName);
	}

	void _Document::ClosePrintPreview()
	{
		InvokeHelper(0x102, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::CheckConsistency()
	{
		InvokeHelper(0x103, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH _Document::CreateLetterContent(LPCTSTR DateFormat, BOOL IncludeHeaderFooter, LPCTSTR PageDesign, long LetterStyle, BOOL Letterhead, long LetterheadLocation, float LetterheadSize, LPCTSTR RecipientName, LPCTSTR RecipientAddress, 
			LPCTSTR Salutation, long SalutationType, LPCTSTR RecipientReference, LPCTSTR MailingInstructions, LPCTSTR AttentionLine, LPCTSTR Subject, LPCTSTR CCList, LPCTSTR ReturnAddress, LPCTSTR SenderName, LPCTSTR Closing, LPCTSTR SenderCompany, 
			LPCTSTR SenderJobTitle, LPCTSTR SenderInitials, long EnclosureNumber, VARIANT* InfoBlock, VARIANT* RecipientCode, VARIANT* RecipientGender, VARIANT* ReturnAddressShortForm, VARIANT* SenderCity, VARIANT* SenderCode, VARIANT* SenderGender, 
			VARIANT* SenderReference)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_BOOL VTS_BSTR VTS_I4 VTS_BOOL VTS_I4 VTS_R4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x104, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			DateFormat, IncludeHeaderFooter, PageDesign, LetterStyle, Letterhead, LetterheadLocation, LetterheadSize, RecipientName, RecipientAddress, Salutation, SalutationType, RecipientReference, MailingInstructions, AttentionLine, Subject, 
			CCList, ReturnAddress, SenderName, Closing, SenderCompany, SenderJobTitle, SenderInitials, EnclosureNumber, InfoBlock, RecipientCode, RecipientGender, ReturnAddressShortForm, SenderCity, SenderCode, SenderGender, SenderReference);
		return result;
	}

	void _Document::AcceptAllRevisions()
	{
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::RejectAllRevisions()
	{
		InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::DetectLanguage()
	{
		InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ApplyTheme(LPCTSTR Name)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name);
	}

	void _Document::RemoveTheme()
	{
		InvokeHelper(0x143, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::WebPagePreview()
	{
		InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Document::ReloadAs(long Encoding)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x14b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Encoding);
	}

	CString _Document::GetActiveTheme()
	{
		CString result;
		InvokeHelper(0x21c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString _Document::GetActiveThemeDisplayName()
	{
		CString result;
		InvokeHelper(0x21d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetEmail()
	{
		LPDISPATCH result;
		InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetScripts()
	{
		LPDISPATCH result;
		InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL _Document::GetLanguageDetected()
	{
		BOOL result;
		InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetLanguageDetected(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x141, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _Document::GetFarEastLineBreakLanguage()
	{
		long result;
		InvokeHelper(0x146, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetFarEastLineBreakLanguage(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x146, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH _Document::GetFrameset()
	{
		LPDISPATCH result;
		InvokeHelper(0x147, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT _Document::GetClickAndTypeParagraphStyle()
	{
		VARIANT result;
		InvokeHelper(0x148, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void _Document::SetClickAndTypeParagraphStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x148, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Document::GetHTMLProject()
	{
		LPDISPATCH result;
		InvokeHelper(0x149, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Document::GetWebOptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x14a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Document::GetOpenEncoding()
	{
		long result;
		InvokeHelper(0x14c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long _Document::GetSaveEncoding()
	{
		long result;
		InvokeHelper(0x14d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Document::SetSaveEncoding(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x14d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Document::GetOptimizeForWord97()
	{
		BOOL result;
		InvokeHelper(0x14e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::SetOptimizeForWord97(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL _Document::GetVBASigned()
	{
		BOOL result;
		InvokeHelper(0x14f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Document::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
			VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Template properties

	/////////////////////////////////////////////////////////////////////////////
	// Template operations

	CString Template::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Template::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Template::GetPath()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetAutoTextEntries()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Template::GetLanguageID()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Template::GetSaved()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Template::SetSaved(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Template::GetType()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString Template::GetFullName()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetBuiltInDocumentProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetCustomDocumentProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Template::GetListTemplates()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Template::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Template::GetVBProject()
	{
		LPDISPATCH result;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Template::GetKerningByAlgorithm()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Template::SetKerningByAlgorithm(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Template::GetJustificationMode()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetJustificationMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Template::GetFarEastLineBreakLevel()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetFarEastLineBreakLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Template::GetNoLineBreakBefore()
	{
		CString result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Template::SetNoLineBreakBefore(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Template::GetNoLineBreakAfter()
	{
		CString result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Template::SetNoLineBreakAfter(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Template::OpenAsDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Template::Save()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Template::GetNoProofing()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Template::GetFarEastLineBreakLanguage()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Template::SetFarEastLineBreakLanguage(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Templates properties

	/////////////////////////////////////////////////////////////////////////////
	// Templates operations

	LPDISPATCH Templates::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Templates::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Templates::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Templates::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Templates::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Templates::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// RoutingSlip properties

	/////////////////////////////////////////////////////////////////////////////
	// RoutingSlip operations

	LPDISPATCH RoutingSlip::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long RoutingSlip::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH RoutingSlip::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString RoutingSlip::GetSubject()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetSubject(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString RoutingSlip::GetMessage()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetMessage(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long RoutingSlip::GetDelivery()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetDelivery(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL RoutingSlip::GetTrackStatus()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetTrackStatus(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long RoutingSlip::GetProtect()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetProtect(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL RoutingSlip::GetReturnWhenDone()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void RoutingSlip::SetReturnWhenDone(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long RoutingSlip::GetStatus()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT RoutingSlip::GetRecipients(VARIANT* Index)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
			Index);
		return result;
	}

	void RoutingSlip::Reset()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void RoutingSlip::AddRecipient(LPCTSTR Recipient)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Recipient);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Bookmark properties

	/////////////////////////////////////////////////////////////////////////////
	// Bookmark operations

	CString Bookmark::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Bookmark::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Bookmark::GetEmpty()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Bookmark::GetStart()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Bookmark::SetStart(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Bookmark::GetEnd()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Bookmark::SetEnd(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Bookmark::GetColumn()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Bookmark::GetStoryType()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Bookmark::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Bookmark::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Bookmark::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Bookmark::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Bookmark::Delete()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Bookmark::Copy(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Bookmarks properties

	/////////////////////////////////////////////////////////////////////////////
	// Bookmarks operations

	LPUNKNOWN Bookmarks::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Bookmarks::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Bookmarks::GetDefaultSorting()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Bookmarks::SetDefaultSorting(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Bookmarks::GetShowHidden()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Bookmarks::SetShowHidden(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Bookmarks::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Bookmarks::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Bookmarks::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Bookmarks::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Bookmarks::Add(LPCTSTR Name, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Range);
		return result;
	}

	BOOL Bookmarks::Exists(LPCTSTR Name)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Variable properties

	/////////////////////////////////////////////////////////////////////////////
	// Variable operations

	LPDISPATCH Variable::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Variable::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Variable::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Variable::GetName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString Variable::GetValue()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Variable::SetValue(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Variable::GetIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Variable::Delete()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Variables properties

	/////////////////////////////////////////////////////////////////////////////
	// Variables operations

	LPUNKNOWN Variables::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Variables::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Variables::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Variables::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Variables::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Variables::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Variables::Add(LPCTSTR Name, VARIANT* Value)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Value);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// RecentFile properties

	/////////////////////////////////////////////////////////////////////////////
	// RecentFile operations

	LPDISPATCH RecentFile::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long RecentFile::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH RecentFile::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString RecentFile::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long RecentFile::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL RecentFile::GetReadOnly()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void RecentFile::SetReadOnly(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString RecentFile::GetPath()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH RecentFile::Open()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void RecentFile::Delete()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// RecentFiles properties

	/////////////////////////////////////////////////////////////////////////////
	// RecentFiles operations

	LPDISPATCH RecentFiles::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long RecentFiles::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH RecentFiles::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN RecentFiles::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long RecentFiles::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long RecentFiles::GetMaximum()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void RecentFiles::SetMaximum(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH RecentFiles::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH RecentFiles::Add(VARIANT* Document, VARIANT* ReadOnly)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Document, ReadOnly);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Window properties

	/////////////////////////////////////////////////////////////////////////////
	// Window operations

	LPDISPATCH Window::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Window::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetActivePane()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetPanes()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetSelection()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Window::GetLeft()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetLeft(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Window::GetTop()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetTop(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Window::GetWidth()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Window::GetHeight()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetHeight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Window::GetSplit()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetSplit(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Window::GetSplitVertical()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetSplitVertical(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Window::GetCaption()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Window::SetCaption(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Window::GetWindowState()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetWindowState(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Window::GetDisplayRulers()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayRulers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetDisplayVerticalRuler()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayVerticalRuler(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Window::GetView()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Window::GetType()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Window::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Window::GetWindowNumber()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Window::GetDisplayVerticalScrollBar()
	{
		BOOL result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayVerticalScrollBar(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetDisplayHorizontalScrollBar()
	{
		BOOL result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayHorizontalScrollBar(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Window::GetStyleAreaWidth()
	{
		float result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Window::SetStyleAreaWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Window::GetDisplayScreenTips()
	{
		BOOL result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayScreenTips(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Window::GetHorizontalPercentScrolled()
	{
		long result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetHorizontalPercentScrolled(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Window::GetVerticalPercentScrolled()
	{
		long result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetVerticalPercentScrolled(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Window::GetDocumentMap()
	{
		BOOL result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDocumentMap(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetActive()
	{
		BOOL result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Window::GetDocumentMapPercentWidth()
	{
		long result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetDocumentMapPercentWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Window::GetIndex()
	{
		long result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Window::GetIMEMode()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Window::SetIMEMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Window::Activate()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Window::Close(VARIANT* SaveChanges, VARIANT* RouteDocument)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 SaveChanges, RouteDocument);
	}

	void Window::LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up, ToRight, ToLeft);
	}

	void Window::SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up, ToRight, ToLeft);
	}

	LPDISPATCH Window::NewWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Window::PageScroll(VARIANT* Down, VARIANT* Up)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up);
	}

	void Window::SetFocus()
	{
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Window::RangeFromPoint(long x, long y)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			x, y);
		return result;
	}

	void Window::ScrollIntoView(LPDISPATCH obj, VARIANT* Start)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 obj, Start);
	}

	void Window::GetPoint(long* ScreenPixelsLeft, long* ScreenPixelsTop, long* ScreenPixelsWidth, long* ScreenPixelsHeight, LPDISPATCH obj)
	{
		static BYTE parms[] =
			VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_DISPATCH;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ScreenPixelsLeft, ScreenPixelsTop, ScreenPixelsWidth, ScreenPixelsHeight, obj);
	}

	void Window::PrintOut(VARIANT* Background, VARIANT* Append, VARIANT* Range, VARIANT* OutputFileName, VARIANT* From, VARIANT* To, VARIANT* Item, VARIANT* Copies, VARIANT* Pages, VARIANT* PageType, VARIANT* PrintToFile, VARIANT* Collate, 
			VARIANT* ActivePrinterMacGX, VARIANT* ManualDuplexPrint, VARIANT* PrintZoomColumn, VARIANT* PrintZoomRow, VARIANT* PrintZoomPaperWidth, VARIANT* PrintZoomPaperHeight)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Background, Append, Range, OutputFileName, From, To, Item, Copies, Pages, PageType, PrintToFile, Collate, ActivePrinterMacGX, ManualDuplexPrint, PrintZoomColumn, PrintZoomRow, PrintZoomPaperWidth, PrintZoomPaperHeight);
	}

	long Window::GetUsableWidth()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Window::GetUsableHeight()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Window::GetEnvelopeVisible()
	{
		BOOL result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetEnvelopeVisible(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetDisplayRightRuler()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayRightRuler(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetDisplayLeftScrollBar()
	{
		BOOL result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetDisplayLeftScrollBar(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Window::GetVisible()
	{
		BOOL result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Window::SetVisible(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Windows properties

	/////////////////////////////////////////////////////////////////////////////
	// Windows operations

	LPUNKNOWN Windows::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Windows::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Windows::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Windows::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Windows::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Windows::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Windows::Add(VARIANT* Window)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Window);
		return result;
	}

	void Windows::Arrange(VARIANT* ArrangeStyle)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ArrangeStyle);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Pane properties

	/////////////////////////////////////////////////////////////////////////////
	// Pane operations

	LPDISPATCH Pane::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Pane::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetSelection()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Pane::GetDisplayRulers()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Pane::SetDisplayRulers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Pane::GetDisplayVerticalRuler()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Pane::SetDisplayVerticalRuler(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Pane::GetZooms()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Pane::GetIndex()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetView()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Pane::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Pane::GetHorizontalPercentScrolled()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Pane::SetHorizontalPercentScrolled(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Pane::GetVerticalPercentScrolled()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Pane::SetVerticalPercentScrolled(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Pane::GetMinimumFontSize()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Pane::SetMinimumFontSize(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Pane::GetBrowseWidth()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Pane::Activate()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Pane::Close()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Pane::LargeScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up, ToRight, ToLeft);
	}

	void Pane::SmallScroll(VARIANT* Down, VARIANT* Up, VARIANT* ToRight, VARIANT* ToLeft)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up, ToRight, ToLeft);
	}

	void Pane::AutoScroll(long Velocity)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Velocity);
	}

	void Pane::PageScroll(VARIANT* Down, VARIANT* Up)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Down, Up);
	}

	void Pane::NewFrameset()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Pane::TOCInFrameset()
	{
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Pane::GetFrameset()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Panes properties

	/////////////////////////////////////////////////////////////////////////////
	// Panes operations

	LPUNKNOWN Panes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Panes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Panes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Panes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Panes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Panes::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Panes::Add(VARIANT* SplitVertical)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			SplitVertical);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Range properties

	/////////////////////////////////////////////////////////////////////////////
	// Range operations

	CString Range::GetText()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Range::SetText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Range::GetFormattedText()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetFormattedText(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Range::GetStart()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetStart(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetEnd()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetEnd(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Range::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Range::GetDuplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetStoryType()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetWords()
	{
		LPDISPATCH result;
		InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetSentences()
	{
		LPDISPATCH result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetCharacters()
	{
		LPDISPATCH result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetFootnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetEndnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetComments()
	{
		LPDISPATCH result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetCells()
	{
		LPDISPATCH result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetSections()
	{
		LPDISPATCH result;
		InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Range::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetTextRetrievalMode()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetTextRetrievalMode(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x3e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Range::GetFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetFormFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetFrames()
	{
		LPDISPATCH result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetParagraphFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetParagraphFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Range::GetListFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetBookmarks()
	{
		LPDISPATCH result;
		InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetBold()
	{
		long result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetBold(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetItalic()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetItalic(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetUnderline()
	{
		long result;
		InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetUnderline(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetEmphasisMark()
	{
		long result;
		InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetEmphasisMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Range::GetDisableCharacterSpaceGrid()
	{
		BOOL result;
		InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Range::SetDisableCharacterSpaceGrid(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Range::GetRevisions()
	{
		LPDISPATCH result;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT Range::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x97, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Range::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x97, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Range::GetStoryLength()
	{
		long result;
		InvokeHelper(0x98, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Range::GetLanguageID()
	{
		long result;
		InvokeHelper(0x99, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x99, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Range::GetSynonymInfo()
	{
		LPDISPATCH result;
		InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetHyperlinks()
	{
		LPDISPATCH result;
		InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetListParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x9d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetSubdocuments()
	{
		LPDISPATCH result;
		InvokeHelper(0x9f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Range::GetGrammarChecked()
	{
		BOOL result;
		InvokeHelper(0x104, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Range::SetGrammarChecked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Range::GetSpellingChecked()
	{
		BOOL result;
		InvokeHelper(0x105, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Range::SetSpellingChecked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Range::GetHighlightColorIndex()
	{
		long result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetHighlightColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Range::GetColumns()
	{
		LPDISPATCH result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetRows()
	{
		LPDISPATCH result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Range::GetIsEndOfRowMark()
	{
		BOOL result;
		InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Range::GetBookmarkID()
	{
		long result;
		InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Range::GetPreviousBookmarkID()
	{
		long result;
		InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetFind()
	{
		LPDISPATCH result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetPageSetup()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Range::SetPageSetup(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Range::GetShapeRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetCase()
	{
		long result;
		InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetCase(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	VARIANT Range::GetInformation(long Type)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
			Type);
		return result;
	}

	LPDISPATCH Range::GetReadabilityStatistics()
	{
		LPDISPATCH result;
		InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetGrammaticalErrors()
	{
		LPDISPATCH result;
		InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetSpellingErrors()
	{
		LPDISPATCH result;
		InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetOrientation()
	{
		long result;
		InvokeHelper(0x13d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetOrientation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Range::GetInlineShapes()
	{
		LPDISPATCH result;
		InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetNextStoryRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x141, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetLanguageIDOther()
	{
		long result;
		InvokeHelper(0x142, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetLanguageIDOther(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x142, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Range::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::SetRange(long Start, long End)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Start, End);
	}

	void Range::Collapse(VARIANT* Direction)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Direction);
	}

	void Range::InsertBefore(LPCTSTR Text)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text);
	}

	void Range::InsertAfter(LPCTSTR Text)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text);
	}

	LPDISPATCH Range::Next(VARIANT* Unit, VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	LPDISPATCH Range::Previous(VARIANT* Unit, VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Range::StartOf(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	long Range::EndOf(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	long Range::Move(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Range::MoveStart(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Range::MoveEnd(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Range::MoveWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Range::MoveStartWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Range::MoveEndWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Range::MoveUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Range::MoveStartUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Range::MoveEndUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	void Range::Cut()
	{
		InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::Copy()
	{
		InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::Paste()
	{
		InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::InsertBreak(VARIANT* Type)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type);
	}

	void Range::InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileName, Range, ConfirmConversions, Link, Attachment);
	}

	BOOL Range::InStory(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	BOOL Range::InRange(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	long Range::Delete(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	void Range::WholeStory()
	{
		InvokeHelper(0x80, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Range::Expand(VARIANT* Unit)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit);
		return result;
	}

	void Range::InsertParagraph()
	{
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::InsertParagraphAfter()
	{
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias)
	{
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 CharacterNumber, Font, Unicode, Bias);
	}

	void Range::InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ReferenceType, ReferenceKind, ReferenceItem, InsertAsHyperlink, IncludePosition);
	}

	void Range::InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Label, Title, TitleAutoText, Position);
	}

	void Range::CopyAsPicture()
	{
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::SortAscending()
	{
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::SortDescending()
	{
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL Range::IsEqual(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	float Range::Calculate()
	{
		float result;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_R4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What, Which, Count, Name);
		return result;
	}

	LPDISPATCH Range::GoToNext(long What)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What);
		return result;
	}

	LPDISPATCH Range::GoToPrevious(long What)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What);
		return result;
	}

	void Range::PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 IconIndex, Link, Placement, DisplayAsIcon, DataType, IconFileName, IconLabel);
	}

	void Range::LookupNameProperties()
	{
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Range::ComputeStatistics(long Statistic)
	{
		long result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Statistic);
		return result;
	}

	void Range::Relocate(long Direction)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Direction);
	}

	void Range::CheckSynonyms()
	{
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::SubscribeTo(LPCTSTR Edition, VARIANT* Format)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Edition, Format);
	}

	void Range::CreatePublisher(VARIANT* Edition, VARIANT* ContainsPICT, VARIANT* ContainsRTF, VARIANT* ContainsText)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Edition, ContainsPICT, ContainsRTF, ContainsText);
	}

	void Range::InsertAutoText()
	{
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::InsertDatabase(VARIANT* Format, VARIANT* Style, VARIANT* LinkToSource, VARIANT* Connection, VARIANT* SQLStatement, VARIANT* SQLStatement1, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* WritePasswordDocument, 
			VARIANT* WritePasswordTemplate, VARIANT* DataSource, VARIANT* From, VARIANT* To, VARIANT* IncludeFields)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Format, Style, LinkToSource, Connection, SQLStatement, SQLStatement1, PasswordDocument, PasswordTemplate, WritePasswordDocument, WritePasswordTemplate, DataSource, From, To, IncludeFields);
	}

	void Range::AutoFormat()
	{
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::CheckGrammar()
	{
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::CheckSpelling(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* AlwaysSuggest, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, 
			VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 CustomDictionary, IgnoreUppercase, AlwaysSuggest, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
	}

	LPDISPATCH Range::GetSpellingSuggestions(VARIANT* CustomDictionary, VARIANT* IgnoreUppercase, VARIANT* MainDictionary, VARIANT* SuggestionMode, VARIANT* CustomDictionary2, VARIANT* CustomDictionary3, VARIANT* CustomDictionary4, 
			VARIANT* CustomDictionary5, VARIANT* CustomDictionary6, VARIANT* CustomDictionary7, VARIANT* CustomDictionary8, VARIANT* CustomDictionary9, VARIANT* CustomDictionary10)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			CustomDictionary, IgnoreUppercase, MainDictionary, SuggestionMode, CustomDictionary2, CustomDictionary3, CustomDictionary4, CustomDictionary5, CustomDictionary6, CustomDictionary7, CustomDictionary8, CustomDictionary9, CustomDictionary10);
		return result;
	}

	void Range::InsertParagraphBefore()
	{
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::NextSubdocument()
	{
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::PreviousSubdocument()
	{
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::ConvertHangulAndHanja(VARIANT* ConversionsMode, VARIANT* FastConversion, VARIANT* CheckHangulEnding, VARIANT* EnableRecentOrdering, VARIANT* CustomDictionary)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ConversionsMode, FastConversion, CheckHangulEnding, EnableRecentOrdering, CustomDictionary);
	}

	void Range::PasteAsNestedTable()
	{
		InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Range::ModifyEnclosure(VARIANT* Style, VARIANT* Symbol, VARIANT* EnclosedText)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Style, Symbol, EnclosedText);
	}

	void Range::PhoneticGuide(LPCTSTR Text, long Alignment, long Raise, long FontSize, LPCTSTR FontName)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text, Alignment, Raise, FontSize, FontName);
	}

	void Range::InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DateTimeFormat, InsertAsField, InsertAsFullWidth, DateLanguage, CalendarType);
	}

	void Range::Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
			VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
			VTS_PVARIANT;
		InvokeHelper(0x1e4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExcludeHeader, FieldNumber, SortFieldType, SortOrder, FieldNumber2, SortFieldType2, SortOrder2, FieldNumber3, SortFieldType3, SortOrder3, SortColumn, Separator, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, 
			IgnoreHe, LanguageID);
	}

	void Range::DetectLanguage()
	{
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Range::ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
			VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Separator, NumRows, NumColumns, InitialColumnWidth, Format, ApplyBorders, ApplyShading, ApplyFont, ApplyColor, ApplyHeadingRows, ApplyLastRow, ApplyFirstColumn, ApplyLastColumn, AutoFit, AutoFitBehavior, DefaultTableBehavior);
		return result;
	}

	void Range::TCSCConverter(long WdTCSCConverterDirection, BOOL CommonTerms, BOOL UseVariants)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BOOL VTS_BOOL;
		InvokeHelper(0x1f3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 WdTCSCConverterDirection, CommonTerms, UseVariants);
	}

	BOOL Range::GetLanguageDetected()
	{
		BOOL result;
		InvokeHelper(0x107, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Range::SetLanguageDetected(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x107, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Range::GetFitTextWidth()
	{
		float result;
		InvokeHelper(0x108, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Range::SetFitTextWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x108, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Range::GetHorizontalInVertical()
	{
		long result;
		InvokeHelper(0x109, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetHorizontalInVertical(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x109, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetTwoLinesInOne()
	{
		long result;
		InvokeHelper(0x10a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetTwoLinesInOne(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x10a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Range::GetCombineCharacters()
	{
		BOOL result;
		InvokeHelper(0x10b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Range::SetCombineCharacters(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Range::GetNoProofing()
	{
		long result;
		InvokeHelper(0x143, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x143, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Range::GetTopLevelTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x144, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Range::GetScripts()
	{
		LPDISPATCH result;
		InvokeHelper(0x145, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Range::GetCharacterWidth()
	{
		long result;
		InvokeHelper(0x146, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetCharacterWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x146, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetKana()
	{
		long result;
		InvokeHelper(0x147, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetKana(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x147, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetBoldBi()
	{
		long result;
		InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetBoldBi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x190, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Range::GetItalicBi()
	{
		long result;
		InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Range::SetItalicBi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x191, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Range::GetId()
	{
		CString result;
		InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Range::SetId(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x195, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// ListFormat operations

	long ListFormat::GetListLevelNumber()
	{
		long result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListFormat::SetListLevelNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH ListFormat::GetList()
	{
		LPDISPATCH result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListFormat::GetListTemplate()
	{
		LPDISPATCH result;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListFormat::GetListValue()
	{
		long result;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL ListFormat::GetSingleList()
	{
		BOOL result;
		InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL ListFormat::GetSingleListTemplate()
	{
		BOOL result;
		InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long ListFormat::GetListType()
	{
		long result;
		InvokeHelper(0x4a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString ListFormat::GetListString()
	{
		CString result;
		InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListFormat::CanContinuePreviousList(LPDISPATCH ListTemplate)
	{
		long result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			ListTemplate);
		return result;
	}

	void ListFormat::RemoveNumbers(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	void ListFormat::ConvertNumbersToText(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	long ListFormat::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			NumberType, Level);
		return result;
	}

	void ListFormat::ListOutdent()
	{
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ListFormat::ListIndent()
	{
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ListFormat::ApplyBulletDefault(VARIANT* DefaultListBehavior)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DefaultListBehavior);
	}

	void ListFormat::ApplyNumberDefault(VARIANT* DefaultListBehavior)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DefaultListBehavior);
	}

	void ListFormat::ApplyOutlineNumberDefault(VARIANT* DefaultListBehavior)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DefaultListBehavior);
	}

	void ListFormat::ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* ApplyTo, VARIANT* DefaultListBehavior)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ListTemplate, ContinuePreviousList, ApplyTo, DefaultListBehavior);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Find properties

	/////////////////////////////////////////////////////////////////////////////
	// Find operations

	LPDISPATCH Find::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Find::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Find::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Find::GetForward()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetForward(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Find::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Find::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Find::GetFound()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Find::GetMatchAllWordForms()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchAllWordForms(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchCase()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchCase(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchWildcards()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchWildcards(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchSoundsLike()
	{
		BOOL result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchSoundsLike(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchWholeWord()
	{
		BOOL result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchWholeWord(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchFuzzy()
	{
		BOOL result;
		InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchFuzzy(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchByte()
	{
		BOOL result;
		InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchByte(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Find::GetParagraphFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Find::SetParagraphFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Find::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Find::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Find::GetText()
	{
		CString result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Find::SetText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Find::GetLanguageID()
	{
		long result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Find::GetHighlight()
	{
		long result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetHighlight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Find::GetReplacement()
	{
		LPDISPATCH result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Find::GetFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Find::GetWrap()
	{
		long result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetWrap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Find::GetFormat()
	{
		BOOL result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetFormat(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Find::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Find::GetLanguageIDOther()
	{
		long result;
		InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetLanguageIDOther(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Find::GetCorrectHangulEndings()
	{
		BOOL result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetCorrectHangulEndings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void Find::ClearFormatting()
	{
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Find::SetAllFuzzyOptions()
	{
		InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Find::ClearAllFuzzyOptions()
	{
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL Find::Execute(VARIANT* FindText, VARIANT* MatchCase, VARIANT* MatchWholeWord, VARIANT* MatchWildcards, VARIANT* MatchSoundsLike, VARIANT* MatchAllWordForms, VARIANT* Forward, VARIANT* Wrap, VARIANT* Format, VARIANT* ReplaceWith, 
			VARIANT* Replace, VARIANT* MatchKashida, VARIANT* MatchDiacritics, VARIANT* MatchAlefHamza, VARIANT* MatchControl)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			FindText, MatchCase, MatchWholeWord, MatchWildcards, MatchSoundsLike, MatchAllWordForms, Forward, Wrap, Format, ReplaceWith, Replace, MatchKashida, MatchDiacritics, MatchAlefHamza, MatchControl);
		return result;
	}

	long Find::GetNoProofing()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Find::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Find::GetMatchKashida()
	{
		BOOL result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchKashida(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchDiacritics()
	{
		BOOL result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchDiacritics(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchAlefHamza()
	{
		BOOL result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchAlefHamza(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Find::GetMatchControl()
	{
		BOOL result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Find::SetMatchControl(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Replacement properties

	/////////////////////////////////////////////////////////////////////////////
	// Replacement operations

	LPDISPATCH Replacement::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Replacement::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Replacement::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Replacement::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Replacement::GetParagraphFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetParagraphFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Replacement::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Replacement::GetText()
	{
		CString result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Replacement::GetLanguageID()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Replacement::GetHighlight()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetHighlight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Replacement::GetFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Replacement::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Replacement::ClearFormatting()
	{
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Replacement::GetNoProofing()
	{
		long result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Replacement::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Characters properties

	/////////////////////////////////////////////////////////////////////////////
	// Characters operations

	LPUNKNOWN Characters::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Characters::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Characters::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Characters::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Characters::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Characters::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Characters::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Characters::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Words properties

	/////////////////////////////////////////////////////////////////////////////
	// Words operations

	LPUNKNOWN Words::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Words::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Words::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Words::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Words::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Words::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Words::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Words::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Sentences properties

	/////////////////////////////////////////////////////////////////////////////
	// Sentences operations

	LPUNKNOWN Sentences::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Sentences::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sentences::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sentences::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sentences::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Sentences::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sentences::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sentences::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Sections properties

	/////////////////////////////////////////////////////////////////////////////
	// Sections operations

	LPUNKNOWN Sections::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Sections::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sections::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sections::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sections::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Sections::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sections::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Sections::GetPageSetup()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Sections::SetPageSetup(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Sections::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Sections::Add(VARIANT* Range, VARIANT* Start)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Start);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Section properties

	/////////////////////////////////////////////////////////////////////////////
	// Section operations

	LPDISPATCH Section::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Section::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Section::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Section::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Section::GetPageSetup()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Section::SetPageSetup(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Section::GetHeaders()
	{
		LPDISPATCH result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Section::GetFooters()
	{
		LPDISPATCH result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Section::GetProtectedForForms()
	{
		BOOL result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Section::SetProtectedForForms(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Section::GetIndex()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Section::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Section::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Paragraphs properties

	/////////////////////////////////////////////////////////////////////////////
	// Paragraphs operations

	LPUNKNOWN Paragraphs::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Paragraphs::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraphs::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraphs::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraphs::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Paragraphs::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraphs::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraphs::GetFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Paragraphs::GetTabStops()
	{
		LPDISPATCH result;
		InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetTabStops(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Paragraphs::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Paragraphs::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraphs::GetAlignment()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetKeepTogether()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetKeepTogether(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetKeepWithNext()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetKeepWithNext(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetPageBreakBefore()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetPageBreakBefore(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetNoLineNumber()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetNoLineNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Paragraphs::GetRightIndent()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetLeftIndent()
	{
		float result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetFirstLineIndent()
	{
		float result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetLineSpacing()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetLineSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraphs::GetLineSpacingRule()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetLineSpacingRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Paragraphs::GetSpaceBefore()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetSpaceBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetSpaceAfter()
	{
		float result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetSpaceAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraphs::GetHyphenation()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetHyphenation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetWidowControl()
	{
		long result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetWidowControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Paragraphs::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Paragraphs::GetFarEastLineBreakControl()
	{
		long result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetFarEastLineBreakControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetWordWrap()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetWordWrap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetHangingPunctuation()
	{
		long result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetHangingPunctuation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetHalfWidthPunctuationOnTopOfLine()
	{
		long result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetAddSpaceBetweenFarEastAndAlpha()
	{
		long result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetAddSpaceBetweenFarEastAndDigit()
	{
		long result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetBaseLineAlignment()
	{
		long result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetBaseLineAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetAutoAdjustRightIndent()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetAutoAdjustRightIndent(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetDisableLineHeightGrid()
	{
		long result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetDisableLineHeightGrid(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetOutlineLevel()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetOutlineLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Paragraphs::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Paragraphs::Add(VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	void Paragraphs::CloseUp()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::OpenUp()
	{
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::OpenOrCloseUp()
	{
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::TabHangingIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraphs::TabIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraphs::Reset()
	{
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::Space1()
	{
		InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::Space15()
	{
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::Space2()
	{
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::IndentCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraphs::IndentFirstLineCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraphs::OutlinePromote()
	{
		InvokeHelper(0x144, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::OutlineDemote()
	{
		InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::OutlineDemoteToBody()
	{
		InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::Indent()
	{
		InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraphs::Outdent()
	{
		InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	float Paragraphs::GetCharacterUnitRightIndent()
	{
		float result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetCharacterUnitRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetCharacterUnitLeftIndent()
	{
		float result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetCharacterUnitLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetCharacterUnitFirstLineIndent()
	{
		float result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetCharacterUnitFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetLineUnitBefore()
	{
		float result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetLineUnitBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraphs::GetLineUnitAfter()
	{
		float result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetLineUnitAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraphs::GetReadingOrder()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetReadingOrder(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetSpaceBeforeAuto()
	{
		long result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetSpaceBeforeAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraphs::GetSpaceAfterAuto()
	{
		long result;
		InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraphs::SetSpaceAfterAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Paragraph properties

	/////////////////////////////////////////////////////////////////////////////
	// Paragraph operations

	LPDISPATCH Paragraph::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraph::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Paragraph::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraph::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Paragraph::GetFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Paragraph::GetTabStops()
	{
		LPDISPATCH result;
		InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetTabStops(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Paragraph::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Paragraph::GetDropCap()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT Paragraph::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraph::GetAlignment()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetKeepTogether()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetKeepTogether(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetKeepWithNext()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetKeepWithNext(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetPageBreakBefore()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetPageBreakBefore(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetNoLineNumber()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetNoLineNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Paragraph::GetRightIndent()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetLeftIndent()
	{
		float result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetFirstLineIndent()
	{
		float result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetLineSpacing()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetLineSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraph::GetLineSpacingRule()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetLineSpacingRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Paragraph::GetSpaceBefore()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetSpaceBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetSpaceAfter()
	{
		float result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetSpaceAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraph::GetHyphenation()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetHyphenation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetWidowControl()
	{
		long result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetWidowControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Paragraph::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Paragraph::GetFarEastLineBreakControl()
	{
		long result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetFarEastLineBreakControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetWordWrap()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetWordWrap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetHangingPunctuation()
	{
		long result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetHangingPunctuation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetHalfWidthPunctuationOnTopOfLine()
	{
		long result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetAddSpaceBetweenFarEastAndAlpha()
	{
		long result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetAddSpaceBetweenFarEastAndDigit()
	{
		long result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetBaseLineAlignment()
	{
		long result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetBaseLineAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetAutoAdjustRightIndent()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetAutoAdjustRightIndent(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetDisableLineHeightGrid()
	{
		long result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetDisableLineHeightGrid(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetOutlineLevel()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetOutlineLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Paragraph::CloseUp()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::OpenUp()
	{
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::OpenOrCloseUp()
	{
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::TabHangingIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraph::TabIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraph::Reset()
	{
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::Space1()
	{
		InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::Space15()
	{
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::Space2()
	{
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::IndentCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void Paragraph::IndentFirstLineCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	LPDISPATCH Paragraph::Next(VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Count);
		return result;
	}

	LPDISPATCH Paragraph::Previous(VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x145, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Count);
		return result;
	}

	void Paragraph::OutlinePromote()
	{
		InvokeHelper(0x146, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::OutlineDemote()
	{
		InvokeHelper(0x147, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::OutlineDemoteToBody()
	{
		InvokeHelper(0x148, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::Indent()
	{
		InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Paragraph::Outdent()
	{
		InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	float Paragraph::GetCharacterUnitRightIndent()
	{
		float result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetCharacterUnitRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetCharacterUnitLeftIndent()
	{
		float result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetCharacterUnitLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetCharacterUnitFirstLineIndent()
	{
		float result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetCharacterUnitFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetLineUnitBefore()
	{
		float result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetLineUnitBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Paragraph::GetLineUnitAfter()
	{
		float result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetLineUnitAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Paragraph::GetReadingOrder()
	{
		long result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetReadingOrder(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Paragraph::GetId()
	{
		CString result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetId(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xcc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Paragraph::GetSpaceBeforeAuto()
	{
		long result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetSpaceBeforeAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Paragraph::GetSpaceAfterAuto()
	{
		long result;
		InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Paragraph::SetSpaceAfterAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// DropCap properties

	/////////////////////////////////////////////////////////////////////////////
	// DropCap operations

	LPDISPATCH DropCap::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long DropCap::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH DropCap::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long DropCap::GetPosition()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DropCap::SetPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString DropCap::GetFontName()
	{
		CString result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void DropCap::SetFontName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long DropCap::GetLinesToDrop()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DropCap::SetLinesToDrop(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float DropCap::GetDistanceFromText()
	{
		float result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void DropCap::SetDistanceFromText(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	void DropCap::Clear()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void DropCap::Enable()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TabStops properties

	/////////////////////////////////////////////////////////////////////////////
	// TabStops operations

	LPUNKNOWN TabStops::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TabStops::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStops::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TabStops::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStops::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStops::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TabStops::Add(float Position, VARIANT* Alignment, VARIANT* Leader)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_R4 VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Position, Alignment, Leader);
		return result;
	}

	void TabStops::ClearAll()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH TabStops::Before(float Position)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Position);
		return result;
	}

	LPDISPATCH TabStops::After(float Position)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Position);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TabStop properties

	/////////////////////////////////////////////////////////////////////////////
	// TabStop operations

	LPDISPATCH TabStop::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TabStop::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStop::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TabStop::GetAlignment()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TabStop::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TabStop::GetLeader()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TabStop::SetLeader(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float TabStop::GetPosition()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TabStop::SetPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL TabStop::GetCustomTab()
	{
		BOOL result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStop::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TabStop::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void TabStop::Clear()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// _ParagraphFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// _ParagraphFormat operations

	LPDISPATCH _ParagraphFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _ParagraphFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _ParagraphFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _ParagraphFormat::GetDuplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT _ParagraphFormat::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _ParagraphFormat::GetAlignment()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetKeepTogether()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetKeepTogether(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetKeepWithNext()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetKeepWithNext(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetPageBreakBefore()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetPageBreakBefore(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetNoLineNumber()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetNoLineNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _ParagraphFormat::GetRightIndent()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetLeftIndent()
	{
		float result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetFirstLineIndent()
	{
		float result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetLineSpacing()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetLineSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _ParagraphFormat::GetLineSpacingRule()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetLineSpacingRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _ParagraphFormat::GetSpaceBefore()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetSpaceBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetSpaceAfter()
	{
		float result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetSpaceAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _ParagraphFormat::GetHyphenation()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetHyphenation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetWidowControl()
	{
		long result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetWidowControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetFarEastLineBreakControl()
	{
		long result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetFarEastLineBreakControl(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetWordWrap()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetWordWrap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetHangingPunctuation()
	{
		long result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetHangingPunctuation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetHalfWidthPunctuationOnTopOfLine()
	{
		long result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetHalfWidthPunctuationOnTopOfLine(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetAddSpaceBetweenFarEastAndAlpha()
	{
		long result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetAddSpaceBetweenFarEastAndAlpha(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetAddSpaceBetweenFarEastAndDigit()
	{
		long result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetAddSpaceBetweenFarEastAndDigit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetBaseLineAlignment()
	{
		long result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetBaseLineAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetAutoAdjustRightIndent()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetAutoAdjustRightIndent(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetDisableLineHeightGrid()
	{
		long result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetDisableLineHeightGrid(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH _ParagraphFormat::GetTabStops()
	{
		LPDISPATCH result;
		InvokeHelper(0x44f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetTabStops(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _ParagraphFormat::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _ParagraphFormat::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _ParagraphFormat::GetOutlineLevel()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetOutlineLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void _ParagraphFormat::CloseUp()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::OpenUp()
	{
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::OpenOrCloseUp()
	{
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::TabHangingIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void _ParagraphFormat::TabIndent(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void _ParagraphFormat::Reset()
	{
		InvokeHelper(0x138, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::Space1()
	{
		InvokeHelper(0x139, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::Space15()
	{
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::Space2()
	{
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _ParagraphFormat::IndentCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	void _ParagraphFormat::IndentFirstLineCharWidth(short Count)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x142, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Count);
	}

	float _ParagraphFormat::GetCharacterUnitRightIndent()
	{
		float result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetCharacterUnitRightIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetCharacterUnitLeftIndent()
	{
		float result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetCharacterUnitLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetCharacterUnitFirstLineIndent()
	{
		float result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetCharacterUnitFirstLineIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetLineUnitBefore()
	{
		float result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetLineUnitBefore(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _ParagraphFormat::GetLineUnitAfter()
	{
		float result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetLineUnitAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _ParagraphFormat::GetReadingOrder()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetReadingOrder(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetSpaceBeforeAuto()
	{
		long result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetSpaceBeforeAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _ParagraphFormat::GetSpaceAfterAuto()
	{
		long result;
		InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _ParagraphFormat::SetSpaceAfterAuto(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// _Font properties

	/////////////////////////////////////////////////////////////////////////////
	// _Font operations

	LPDISPATCH _Font::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Font::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Font::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _Font::GetDuplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Font::GetBold()
	{
		long result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetBold(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetItalic()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetItalic(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetHidden()
	{
		long result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetHidden(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetSmallCaps()
	{
		long result;
		InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSmallCaps(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x85, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetAllCaps()
	{
		long result;
		InvokeHelper(0x86, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetAllCaps(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x86, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetStrikeThrough()
	{
		long result;
		InvokeHelper(0x87, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetStrikeThrough(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x87, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetDoubleStrikeThrough()
	{
		long result;
		InvokeHelper(0x88, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetDoubleStrikeThrough(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x88, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetColorIndex()
	{
		long result;
		InvokeHelper(0x89, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x89, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetSubscript()
	{
		long result;
		InvokeHelper(0x8a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSubscript(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetSuperscript()
	{
		long result;
		InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSuperscript(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetUnderline()
	{
		long result;
		InvokeHelper(0x8c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetUnderline(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _Font::GetSize()
	{
		float result;
		InvokeHelper(0x8d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSize(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x8d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString _Font::GetName()
	{
		CString result;
		InvokeHelper(0x8e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Font::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x8e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _Font::GetPosition()
	{
		long result;
		InvokeHelper(0x8f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _Font::GetSpacing()
	{
		float result;
		InvokeHelper(0x90, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x90, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _Font::GetScaling()
	{
		long result;
		InvokeHelper(0x91, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetScaling(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x91, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetShadow()
	{
		long result;
		InvokeHelper(0x92, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetShadow(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x92, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetOutline()
	{
		long result;
		InvokeHelper(0x93, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetOutline(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x93, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetEmboss()
	{
		long result;
		InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetEmboss(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x94, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _Font::GetKerning()
	{
		float result;
		InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetKerning(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x95, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long _Font::GetEngrave()
	{
		long result;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetEngrave(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x96, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetAnimation()
	{
		long result;
		InvokeHelper(0x97, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetAnimation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x97, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH _Font::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _Font::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH _Font::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x99, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _Font::GetEmphasisMark()
	{
		long result;
		InvokeHelper(0x9a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetEmphasisMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _Font::GetDisableCharacterSpaceGrid()
	{
		BOOL result;
		InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _Font::SetDisableCharacterSpaceGrid(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _Font::GetNameFarEast()
	{
		CString result;
		InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Font::SetNameFarEast(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x9c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Font::GetNameAscii()
	{
		CString result;
		InvokeHelper(0x9d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Font::SetNameAscii(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x9d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _Font::GetNameOther()
	{
		CString result;
		InvokeHelper(0x9e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Font::SetNameOther(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x9e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	void _Font::Grow()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Font::Shrink()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Font::Reset()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _Font::SetAsTemplateDefault()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long _Font::GetColor()
	{
		long result;
		InvokeHelper(0x9f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetBoldBi()
	{
		long result;
		InvokeHelper(0xa0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetBoldBi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetItalicBi()
	{
		long result;
		InvokeHelper(0xa1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetItalicBi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _Font::GetSizeBi()
	{
		float result;
		InvokeHelper(0xa2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetSizeBi(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString _Font::GetNameBi()
	{
		CString result;
		InvokeHelper(0xa3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _Font::SetNameBi(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _Font::GetColorIndexBi()
	{
		long result;
		InvokeHelper(0xa4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetColorIndexBi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetDiacriticColor()
	{
		long result;
		InvokeHelper(0xa5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetDiacriticColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long _Font::GetUnderlineColor()
	{
		long result;
		InvokeHelper(0xa6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _Font::SetUnderlineColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Table properties

	/////////////////////////////////////////////////////////////////////////////
	// Table operations

	LPDISPATCH Table::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Table::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Table::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Table::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Table::GetColumns()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Table::GetRows()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Table::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Table::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Table::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Table::GetUniform()
	{
		BOOL result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Table::GetAutoFormatType()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Table::Select()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Table::Delete()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Table::SortAscending()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Table::SortDescending()
	{
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Table::AutoFormat(VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Format, ApplyBorders, ApplyShading, ApplyFont, ApplyColor, ApplyHeadingRows, ApplyLastRow, ApplyFirstColumn, ApplyLastColumn, AutoFit);
	}

	void Table::UpdateAutoFormat()
	{
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Table::Cell(long Row, long Column)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Row, Column);
		return result;
	}

	LPDISPATCH Table::Split(VARIANT* BeforeRow)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			BeforeRow);
		return result;
	}

	LPDISPATCH Table::ConvertToText(VARIANT* Separator, VARIANT* NestedTables)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Separator, NestedTables);
		return result;
	}

	void Table::AutoFitBehavior(long Behavior)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Behavior);
	}

	void Table::Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
			VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExcludeHeader, FieldNumber, SortFieldType, SortOrder, FieldNumber2, SortFieldType2, SortOrder2, FieldNumber3, SortFieldType3, SortOrder3, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, IgnoreHe, LanguageID);
	}

	LPDISPATCH Table::GetTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Table::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Table::GetAllowPageBreaks()
	{
		BOOL result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Table::SetAllowPageBreaks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Table::GetAllowAutoFit()
	{
		BOOL result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Table::SetAllowAutoFit(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Table::GetPreferredWidth()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetPreferredWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Table::GetPreferredWidthType()
	{
		long result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Table::SetPreferredWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Table::GetTopPadding()
	{
		float result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetTopPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Table::GetBottomPadding()
	{
		float result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetBottomPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Table::GetLeftPadding()
	{
		float result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetLeftPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Table::GetRightPadding()
	{
		float result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetRightPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Table::GetSpacing()
	{
		float result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Table::SetSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Table::GetTableDirection()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Table::SetTableDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Table::GetId()
	{
		CString result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Table::SetId(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Row properties

	/////////////////////////////////////////////////////////////////////////////
	// Row operations

	LPDISPATCH Row::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Row::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Row::GetAllowBreakAcrossPages()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Row::SetAllowBreakAcrossPages(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Row::GetAlignment()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Row::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Row::GetHeadingFormat()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Row::SetHeadingFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Row::GetSpaceBetweenColumns()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Row::SetSpaceBetweenColumns(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Row::GetHeight()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Row::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Row::GetHeightRule()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Row::SetHeightRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Row::GetLeftIndent()
	{
		float result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Row::SetLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Row::GetIsLast()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Row::GetIsFirst()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Row::GetIndex()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetCells()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Row::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Row::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Row::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Row::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Row::Delete()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Row::SetLeftIndent(float LeftIndent, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 LeftIndent, RulerStyle);
	}

	void Row::SetHeight(float RowHeight, long HeightRule)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 RowHeight, HeightRule);
	}

	LPDISPATCH Row::ConvertToText(VARIANT* Separator, VARIANT* NestedTables)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Separator, NestedTables);
		return result;
	}

	long Row::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString Row::GetId()
	{
		CString result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Row::SetId(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Column properties

	/////////////////////////////////////////////////////////////////////////////
	// Column operations

	LPDISPATCH Column::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Column::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Column::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Column::GetWidth()
	{
		float result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Column::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Column::GetIsFirst()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Column::GetIsLast()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Column::GetIndex()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Column::GetCells()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Column::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Column::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Column::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Column::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Column::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Column::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Column::Delete()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Column::SetWidth(float ColumnWidth, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ColumnWidth, RulerStyle);
	}

	void Column::AutoFit()
	{
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Column::Sort(VARIANT* ExcludeHeader, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExcludeHeader, SortFieldType, SortOrder, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, IgnoreHe, LanguageID);
	}

	long Column::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Column::GetPreferredWidth()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Column::SetPreferredWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Column::GetPreferredWidthType()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Column::SetPreferredWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Cell properties

	/////////////////////////////////////////////////////////////////////////////
	// Cell operations

	LPDISPATCH Cell::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Cell::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Cell::GetRowIndex()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Cell::GetColumnIndex()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Cell::GetWidth()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Cell::GetHeight()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Cell::GetHeightRule()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetHeightRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Cell::GetVerticalAlignment()
	{
		long result;
		InvokeHelper(0x450, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetVerticalAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x450, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Cell::GetColumn()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetRow()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cell::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Cell::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	void Cell::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Cell::Delete(VARIANT* ShiftCells)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ShiftCells);
	}

	void Cell::Formula(VARIANT* Formula, VARIANT* NumFormat)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Formula, NumFormat);
	}

	void Cell::SetWidth(float ColumnWidth, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ColumnWidth, RulerStyle);
	}

	void Cell::SetHeight(VARIANT* RowHeight, long HeightRule)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_I4;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 RowHeight, HeightRule);
	}

	void Cell::Merge(LPDISPATCH MergeTo)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 MergeTo);
	}

	void Cell::Split(VARIANT* NumRows, VARIANT* NumColumns)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumRows, NumColumns);
	}

	void Cell::AutoSum()
	{
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Cell::GetTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Cell::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Cell::GetWordWrap()
	{
		BOOL result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Cell::SetWordWrap(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Cell::GetPreferredWidth()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetPreferredWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Cell::GetFitText()
	{
		BOOL result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Cell::SetFitText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Cell::GetTopPadding()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetTopPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Cell::GetBottomPadding()
	{
		float result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetBottomPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Cell::GetLeftPadding()
	{
		float result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetLeftPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Cell::GetRightPadding()
	{
		float result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetRightPadding(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Cell::GetId()
	{
		CString result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Cell::SetId(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Cell::GetPreferredWidthType()
	{
		long result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cell::SetPreferredWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Tables properties

	/////////////////////////////////////////////////////////////////////////////
	// Tables operations

	LPUNKNOWN Tables::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Tables::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Tables::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Tables::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Tables::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Tables::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Tables::Add(LPDISPATCH Range, long NumRows, long NumColumns, VARIANT* DefaultTableBehavior, VARIANT* AutoFitBehavior)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, NumRows, NumColumns, DefaultTableBehavior, AutoFitBehavior);
		return result;
	}

	long Tables::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Rows properties

	/////////////////////////////////////////////////////////////////////////////
	// Rows operations

	LPUNKNOWN Rows::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Rows::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Rows::GetAllowBreakAcrossPages()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetAllowBreakAcrossPages(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Rows::GetAlignment()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Rows::GetHeadingFormat()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetHeadingFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Rows::GetSpaceBetweenColumns()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetSpaceBetweenColumns(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetHeight()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Rows::GetHeightRule()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetHeightRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Rows::GetLeftIndent()
	{
		float result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetLeftIndent(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Rows::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Rows::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Rows::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Rows::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Rows::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Rows::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Rows::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Rows::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Rows::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Rows::Add(VARIANT* BeforeRow)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			BeforeRow);
		return result;
	}

	void Rows::Select()
	{
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Rows::Delete()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Rows::SetLeftIndent(float LeftIndent, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 LeftIndent, RulerStyle);
	}

	void Rows::SetHeight(float RowHeight, long HeightRule)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 RowHeight, HeightRule);
	}

	void Rows::DistributeHeight()
	{
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Rows::ConvertToText(VARIANT* Separator, VARIANT* NestedTables)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Separator, NestedTables);
		return result;
	}

	long Rows::GetWrapAroundText()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetWrapAroundText(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Rows::GetDistanceTop()
	{
		float result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetDistanceTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetDistanceBottom()
	{
		float result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetDistanceBottom(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetDistanceLeft()
	{
		float result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetDistanceLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetDistanceRight()
	{
		float result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetDistanceRight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetHorizontalPosition()
	{
		float result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetHorizontalPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Rows::GetVerticalPosition()
	{
		float result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetVerticalPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Rows::GetRelativeHorizontalPosition()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetRelativeHorizontalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Rows::GetRelativeVerticalPosition()
	{
		long result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetRelativeVerticalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Rows::GetAllowOverlap()
	{
		long result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetAllowOverlap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Rows::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Rows::GetTableDirection()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Rows::SetTableDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Columns properties

	/////////////////////////////////////////////////////////////////////////////
	// Columns operations

	LPUNKNOWN Columns::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Columns::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Columns::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Columns::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Columns::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Columns::GetFirst()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Columns::GetLast()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Columns::GetWidth()
	{
		float result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Columns::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Columns::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Columns::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Columns::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Columns::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Columns::Add(VARIANT* BeforeColumn)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			BeforeColumn);
		return result;
	}

	void Columns::Select()
	{
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Columns::Delete()
	{
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Columns::SetWidth(float ColumnWidth, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ColumnWidth, RulerStyle);
	}

	void Columns::AutoFit()
	{
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Columns::DistributeWidth()
	{
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Columns::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Columns::GetPreferredWidth()
	{
		float result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Columns::SetPreferredWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Columns::GetPreferredWidthType()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Columns::SetPreferredWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Cells properties

	/////////////////////////////////////////////////////////////////////////////
	// Cells operations

	LPUNKNOWN Cells::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Cells::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cells::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Cells::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cells::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Cells::GetWidth()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Cells::GetHeight()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Cells::GetHeightRule()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetHeightRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Cells::GetVerticalAlignment()
	{
		long result;
		InvokeHelper(0x450, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetVerticalAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x450, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Cells::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Cells::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Cells::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Cells::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Cells::Add(VARIANT* BeforeCell)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			BeforeCell);
		return result;
	}

	void Cells::Delete(VARIANT* ShiftCells)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ShiftCells);
	}

	void Cells::SetWidth(float ColumnWidth, long RulerStyle)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ColumnWidth, RulerStyle);
	}

	void Cells::SetHeight(VARIANT* RowHeight, long HeightRule)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_I4;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 RowHeight, HeightRule);
	}

	void Cells::Merge()
	{
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Cells::Split(VARIANT* NumRows, VARIANT* NumColumns, VARIANT* MergeBeforeSplit)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumRows, NumColumns, MergeBeforeSplit);
	}

	void Cells::DistributeHeight()
	{
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Cells::DistributeWidth()
	{
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Cells::AutoFit()
	{
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Cells::GetNestingLevel()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Cells::GetPreferredWidth()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetPreferredWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Cells::GetPreferredWidthType()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Cells::SetPreferredWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrect properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrect operations

	LPDISPATCH AutoCorrect::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCorrect::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCorrect::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCorrect::GetCorrectDays()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectDays(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetCorrectInitialCaps()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectInitialCaps(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetCorrectSentenceCaps()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectSentenceCaps(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetReplaceText()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetReplaceText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH AutoCorrect::GetEntries()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCorrect::GetFirstLetterExceptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCorrect::GetFirstLetterAutoAdd()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetFirstLetterAutoAdd(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH AutoCorrect::GetTwoInitialCapsExceptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCorrect::GetTwoInitialCapsAutoAdd()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetTwoInitialCapsAutoAdd(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetCorrectCapsLock()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectCapsLock(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetCorrectHangulAndAlphabet()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectHangulAndAlphabet(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH AutoCorrect::GetHangulAndAlphabetExceptions()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCorrect::GetHangulAndAlphabetAutoAdd()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetHangulAndAlphabetAutoAdd(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetReplaceTextFromSpellingChecker()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetReplaceTextFromSpellingChecker(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AutoCorrect::GetOtherCorrectionsAutoAdd()
	{
		BOOL result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetOtherCorrectionsAutoAdd(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH AutoCorrect::GetOtherCorrectionsExceptions()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCorrect::GetCorrectKeyboardSetting()
	{
		BOOL result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrect::SetCorrectKeyboardSetting(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrectEntries properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrectEntries operations

	LPDISPATCH AutoCorrectEntries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCorrectEntries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCorrectEntries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN AutoCorrectEntries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long AutoCorrectEntries::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCorrectEntries::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH AutoCorrectEntries::Add(LPCTSTR Name, LPCTSTR Value)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Value);
		return result;
	}

	LPDISPATCH AutoCorrectEntries::AddRichText(LPCTSTR Name, LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_DISPATCH;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Range);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrectEntry properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoCorrectEntry operations

	LPDISPATCH AutoCorrectEntry::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCorrectEntry::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCorrectEntry::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCorrectEntry::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString AutoCorrectEntry::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void AutoCorrectEntry::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString AutoCorrectEntry::GetValue()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void AutoCorrectEntry::SetValue(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL AutoCorrectEntry::GetRichText()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCorrectEntry::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void AutoCorrectEntry::Apply(LPDISPATCH Range)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Range);
	}


	/////////////////////////////////////////////////////////////////////////////
	// FirstLetterExceptions properties

	/////////////////////////////////////////////////////////////////////////////
	// FirstLetterExceptions operations

	LPDISPATCH FirstLetterExceptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FirstLetterExceptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FirstLetterExceptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN FirstLetterExceptions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long FirstLetterExceptions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FirstLetterExceptions::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH FirstLetterExceptions::Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// FirstLetterException properties

	/////////////////////////////////////////////////////////////////////////////
	// FirstLetterException operations

	LPDISPATCH FirstLetterException::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FirstLetterException::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FirstLetterException::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FirstLetterException::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString FirstLetterException::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FirstLetterException::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TwoInitialCapsExceptions properties

	/////////////////////////////////////////////////////////////////////////////
	// TwoInitialCapsExceptions operations

	LPDISPATCH TwoInitialCapsExceptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TwoInitialCapsExceptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TwoInitialCapsExceptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN TwoInitialCapsExceptions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TwoInitialCapsExceptions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TwoInitialCapsExceptions::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TwoInitialCapsExceptions::Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TwoInitialCapsException properties

	/////////////////////////////////////////////////////////////////////////////
	// TwoInitialCapsException operations

	LPDISPATCH TwoInitialCapsException::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TwoInitialCapsException::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TwoInitialCapsException::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TwoInitialCapsException::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString TwoInitialCapsException::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TwoInitialCapsException::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Footnotes properties

	/////////////////////////////////////////////////////////////////////////////
	// Footnotes operations

	LPUNKNOWN Footnotes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Footnotes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnotes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Footnotes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnotes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Footnotes::GetLocation()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Footnotes::SetLocation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Footnotes::GetNumberStyle()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Footnotes::SetNumberStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Footnotes::GetStartingNumber()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Footnotes::SetStartingNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Footnotes::GetNumberingRule()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Footnotes::SetNumberingRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Footnotes::GetSeparator()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnotes::GetContinuationSeparator()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnotes::GetContinuationNotice()
	{
		LPDISPATCH result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnotes::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Footnotes::Add(LPDISPATCH Range, VARIANT* Reference, VARIANT* Text)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Reference, Text);
		return result;
	}

	void Footnotes::Convert()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Footnotes::SwapWithEndnotes()
	{
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Footnotes::ResetSeparator()
	{
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Footnotes::ResetContinuationSeparator()
	{
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Footnotes::ResetContinuationNotice()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Endnotes properties

	/////////////////////////////////////////////////////////////////////////////
	// Endnotes operations

	LPUNKNOWN Endnotes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Endnotes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnotes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Endnotes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnotes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Endnotes::GetLocation()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Endnotes::SetLocation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Endnotes::GetNumberStyle()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Endnotes::SetNumberStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Endnotes::GetStartingNumber()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Endnotes::SetStartingNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Endnotes::GetNumberingRule()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Endnotes::SetNumberingRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Endnotes::GetSeparator()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnotes::GetContinuationSeparator()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnotes::GetContinuationNotice()
	{
		LPDISPATCH result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnotes::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Endnotes::Add(LPDISPATCH Range, VARIANT* Reference, VARIANT* Text)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Reference, Text);
		return result;
	}

	void Endnotes::Convert()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Endnotes::SwapWithFootnotes()
	{
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Endnotes::ResetSeparator()
	{
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Endnotes::ResetContinuationSeparator()
	{
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Endnotes::ResetContinuationNotice()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Comments properties

	/////////////////////////////////////////////////////////////////////////////
	// Comments operations

	LPUNKNOWN Comments::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Comments::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comments::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Comments::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comments::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Comments::GetShowBy()
	{
		CString result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Comments::SetShowBy(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Comments::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Comments::Add(LPDISPATCH Range, VARIANT* Text)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Text);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Footnote properties

	/////////////////////////////////////////////////////////////////////////////
	// Footnote operations

	LPDISPATCH Footnote::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Footnote::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnote::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnote::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Footnote::GetReference()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Footnote::GetIndex()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Footnote::Delete()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Endnote properties

	/////////////////////////////////////////////////////////////////////////////
	// Endnote operations

	LPDISPATCH Endnote::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Endnote::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnote::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnote::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Endnote::GetReference()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Endnote::GetIndex()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Endnote::Delete()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Comment properties

	/////////////////////////////////////////////////////////////////////////////
	// Comment operations

	LPDISPATCH Comment::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Comment::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comment::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comment::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comment::GetReference()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ec, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Comment::GetScope()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Comment::GetIndex()
	{
		long result;
		InvokeHelper(0x3ee, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString Comment::GetAuthor()
	{
		CString result;
		InvokeHelper(0x3ef, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Comment::SetAuthor(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3ef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Comment::GetInitial()
	{
		CString result;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Comment::SetInitial(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL Comment::GetShowTip()
	{
		BOOL result;
		InvokeHelper(0x3f1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Comment::SetShowTip(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3f1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void Comment::Delete()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Borders properties

	/////////////////////////////////////////////////////////////////////////////
	// Borders operations

	LPDISPATCH Borders::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Borders::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Borders::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Borders::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Borders::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Borders::GetEnable()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetEnable(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetDistanceFromTop()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetDistanceFromTop(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Borders::GetShadow()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetShadow(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Borders::GetInsideLineStyle()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetInsideLineStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetOutsideLineStyle()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetOutsideLineStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetInsideLineWidth()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetInsideLineWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetOutsideLineWidth()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetOutsideLineWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetInsideColorIndex()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetInsideColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetOutsideColorIndex()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetOutsideColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetDistanceFromLeft()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetDistanceFromLeft(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetDistanceFromBottom()
	{
		long result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetDistanceFromBottom(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetDistanceFromRight()
	{
		long result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetDistanceFromRight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Borders::GetAlwaysInFront()
	{
		BOOL result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetAlwaysInFront(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Borders::GetSurroundHeader()
	{
		BOOL result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetSurroundHeader(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Borders::GetSurroundFooter()
	{
		BOOL result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetSurroundFooter(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Borders::GetJoinBorders()
	{
		BOOL result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetJoinBorders(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Borders::GetHasHorizontal()
	{
		BOOL result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Borders::GetHasVertical()
	{
		BOOL result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Borders::GetDistanceFrom()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetDistanceFrom(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Borders::GetEnableFirstPageInSection()
	{
		BOOL result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetEnableFirstPageInSection(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Borders::GetEnableOtherPagesInSection()
	{
		BOOL result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Borders::SetEnableOtherPagesInSection(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Borders::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void Borders::ApplyPageBordersToAllSections()
	{
		InvokeHelper(0x7d0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Borders::GetInsideColor()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetInsideColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x20, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Borders::GetOutsideColor()
	{
		long result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Borders::SetOutsideColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Border properties

	/////////////////////////////////////////////////////////////////////////////
	// Border operations

	LPDISPATCH Border::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Border::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Border::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Border::GetVisible()
	{
		BOOL result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Border::SetVisible(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Border::GetColorIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Border::GetInside()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Border::GetLineStyle()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetLineStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Border::GetLineWidth()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetLineWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Border::GetArtStyle()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetArtStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Border::GetArtWidth()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetArtWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Border::GetColor()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Border::SetColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Shading properties

	/////////////////////////////////////////////////////////////////////////////
	// Shading operations

	LPDISPATCH Shading::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shading::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shading::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shading::GetForegroundPatternColorIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shading::SetForegroundPatternColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shading::GetBackgroundPatternColorIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shading::SetBackgroundPatternColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shading::GetTexture()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shading::SetTexture(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shading::GetForegroundPatternColor()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shading::SetForegroundPatternColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shading::GetBackgroundPatternColor()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shading::SetBackgroundPatternColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextRetrievalMode properties

	/////////////////////////////////////////////////////////////////////////////
	// TextRetrievalMode operations

	LPDISPATCH TextRetrievalMode::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextRetrievalMode::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextRetrievalMode::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextRetrievalMode::GetViewType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextRetrievalMode::SetViewType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH TextRetrievalMode::GetDuplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TextRetrievalMode::GetIncludeHiddenText()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TextRetrievalMode::SetIncludeHiddenText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TextRetrievalMode::GetIncludeFieldCodes()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TextRetrievalMode::SetIncludeFieldCodes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoTextEntries properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoTextEntries operations

	LPDISPATCH AutoTextEntries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoTextEntries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoTextEntries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN AutoTextEntries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long AutoTextEntries::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoTextEntries::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH AutoTextEntries::Add(LPCTSTR Name, LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_DISPATCH;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Range);
		return result;
	}

	LPDISPATCH AutoTextEntries::AppendToSpike(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoTextEntry properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoTextEntry operations

	LPDISPATCH AutoTextEntry::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoTextEntry::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoTextEntry::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoTextEntry::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString AutoTextEntry::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void AutoTextEntry::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString AutoTextEntry::GetStyleName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString AutoTextEntry::GetValue()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void AutoTextEntry::SetValue(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	void AutoTextEntry::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH AutoTextEntry::Insert(LPDISPATCH Where, VARIANT* RichText)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Where, RichText);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// System properties

	/////////////////////////////////////////////////////////////////////////////
	// System operations

	LPDISPATCH System::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long System::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH System::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString System::GetOperatingSystem()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString System::GetProcessorType()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString System::GetVersion()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long System::GetFreeDiskSpace()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long System::GetCountry()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString System::GetLanguageDesignation()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long System::GetHorizontalResolution()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long System::GetVerticalResolution()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString System::GetProfileString(LPCTSTR Section, LPCTSTR Key)
	{
		CString result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
			Section, Key);
		return result;
	}

	void System::SetProfileString(LPCTSTR Section, LPCTSTR Key, LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 Section, Key, lpszNewValue);
	}

	CString System::GetPrivateProfileString(LPCTSTR FileName, LPCTSTR Section, LPCTSTR Key)
	{
		CString result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
			FileName, Section, Key);
		return result;
	}

	void System::SetPrivateProfileString(LPCTSTR FileName, LPCTSTR Section, LPCTSTR Key, LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 FileName, Section, Key, lpszNewValue);
	}

	BOOL System::GetMathCoprocessorInstalled()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString System::GetComputerType()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString System::GetMacintoshName()
	{
		CString result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL System::GetQuickDrawInstalled()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long System::GetCursor()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void System::SetCursor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void System::MSInfo()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void System::Connect(LPCTSTR Path, VARIANT* Drive, VARIANT* Password)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Path, Drive, Password);
	}


	/////////////////////////////////////////////////////////////////////////////
	// OLEFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// OLEFormat operations

	LPDISPATCH OLEFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long OLEFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH OLEFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString OLEFormat::GetClassType()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::SetClassType(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL OLEFormat::GetDisplayAsIcon()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::SetDisplayAsIcon(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString OLEFormat::GetIconName()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::SetIconName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString OLEFormat::GetIconPath()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long OLEFormat::GetIconIndex()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::SetIconIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString OLEFormat::GetIconLabel()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::SetIconLabel(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString OLEFormat::GetLabel()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH OLEFormat::GetObject()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString OLEFormat::GetProgID()
	{
		CString result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void OLEFormat::Activate()
	{
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void OLEFormat::Edit()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void OLEFormat::Open()
	{
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void OLEFormat::DoVerb(VARIANT* VerbIndex)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 VerbIndex);
	}

	void OLEFormat::ConvertTo(VARIANT* ClassType, VARIANT* DisplayAsIcon, VARIANT* IconFileName, VARIANT* IconIndex, VARIANT* IconLabel)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ClassType, DisplayAsIcon, IconFileName, IconIndex, IconLabel);
	}

	void OLEFormat::ActivateAs(LPCTSTR ClassType)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ClassType);
	}


	/////////////////////////////////////////////////////////////////////////////
	// LinkFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// LinkFormat operations

	LPDISPATCH LinkFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LinkFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH LinkFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL LinkFormat::GetAutoUpdate()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void LinkFormat::SetAutoUpdate(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString LinkFormat::GetSourceName()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString LinkFormat::GetSourcePath()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL LinkFormat::GetLocked()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void LinkFormat::SetLocked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long LinkFormat::GetType()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString LinkFormat::GetSourceFullName()
	{
		CString result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void LinkFormat::SetSourceFullName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL LinkFormat::GetSavePictureWithDocument()
	{
		BOOL result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void LinkFormat::SetSavePictureWithDocument(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void LinkFormat::BreakLink()
	{
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void LinkFormat::Update()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// _OLEControl properties

	/////////////////////////////////////////////////////////////////////////////
	// _OLEControl operations

	float _OLEControl::GetLeft()
	{
		float result;
		InvokeHelper(0x80010103, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::SetLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80010103, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _OLEControl::GetTop()
	{
		float result;
		InvokeHelper(0x80010104, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::SetTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80010104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _OLEControl::GetHeight()
	{
		float result;
		InvokeHelper(0x80010105, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80010105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float _OLEControl::GetWidth()
	{
		float result;
		InvokeHelper(0x80010106, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80010106, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString _OLEControl::GetName()
	{
		CString result;
		InvokeHelper(0x80010000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x80010000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH _OLEControl::GetAutomation()
	{
		LPDISPATCH result;
		InvokeHelper(0x80010107, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void _OLEControl::Select()
	{
		InvokeHelper(0x80010220, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _OLEControl::Copy()
	{
		InvokeHelper(0x80010228, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _OLEControl::Cut()
	{
		InvokeHelper(0x80010229, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _OLEControl::Delete()
	{
		InvokeHelper(0x80010250, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void _OLEControl::Activate()
	{
		InvokeHelper(0x80010251, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Browser properties

	/////////////////////////////////////////////////////////////////////////////
	// Browser operations

	LPDISPATCH Browser::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Browser::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Browser::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Browser::GetTarget()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Browser::SetTarget(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Browser::Next()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Browser::Previous()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Styles properties

	/////////////////////////////////////////////////////////////////////////////
	// Styles operations

	LPDISPATCH Styles::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Styles::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Styles::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Styles::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Styles::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Styles::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Styles::Add(LPCTSTR Name, VARIANT* Type)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Type);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Style properties

	/////////////////////////////////////////////////////////////////////////////
	// Style operations

	LPDISPATCH Style::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Style::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Style::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Style::GetNameLocal()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Style::SetNameLocal(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	VARIANT Style::GetBaseStyle()
	{
		VARIANT result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Style::SetBaseStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Style::GetDescription()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long Style::GetType()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Style::GetBuiltIn()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	VARIANT Style::GetNextParagraphStyle()
	{
		VARIANT result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Style::SetNextParagraphStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Style::GetInUse()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Style::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Style::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Style::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Style::GetParagraphFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Style::SetParagraphFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Style::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Style::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Style::GetFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Style::GetLanguageID()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Style::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Style::GetAutomaticallyUpdate()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Style::SetAutomaticallyUpdate(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Style::GetListTemplate()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Style::GetListLevelNumber()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Style::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Style::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Style::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Style::LinkToListTemplate(LPDISPATCH ListTemplate, VARIANT* ListLevelNumber)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ListTemplate, ListLevelNumber);
	}

	long Style::GetNoProofing()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Style::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Frames properties

	/////////////////////////////////////////////////////////////////////////////
	// Frames operations

	LPDISPATCH Frames::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Frames::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frames::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Frames::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Frames::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frames::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Frames::Add(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	void Frames::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Frame properties

	/////////////////////////////////////////////////////////////////////////////
	// Frame operations

	LPDISPATCH Frame::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Frame::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frame::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Frame::GetHeightRule()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetHeightRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frame::GetWidthRule()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetWidthRule(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Frame::GetHorizontalDistanceFromText()
	{
		float result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetHorizontalDistanceFromText(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Frame::GetHeight()
	{
		float result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Frame::GetHorizontalPosition()
	{
		float result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetHorizontalPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Frame::GetLockAnchor()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Frame::SetLockAnchor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Frame::GetRelativeHorizontalPosition()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetRelativeHorizontalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frame::GetRelativeVerticalPosition()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetRelativeVerticalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Frame::GetVerticalDistanceFromText()
	{
		float result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetVerticalDistanceFromText(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Frame::GetVerticalPosition()
	{
		float result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetVerticalPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Frame::GetWidth()
	{
		float result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frame::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Frame::GetTextWrap()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Frame::SetTextWrap(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Frame::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frame::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Frame::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Frame::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Frame::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Frame::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Frame::Copy()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Frame::Cut()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// FormFields properties

	/////////////////////////////////////////////////////////////////////////////
	// FormFields operations

	LPDISPATCH FormFields::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FormFields::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormFields::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FormFields::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL FormFields::GetShaded()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void FormFields::SetShaded(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPUNKNOWN FormFields::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormFields::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH FormFields::Add(LPDISPATCH Range, long Type)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_I4;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Type);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// FormField properties

	/////////////////////////////////////////////////////////////////////////////
	// FormField operations

	LPDISPATCH FormField::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FormField::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormField::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FormField::GetType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString FormField::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString FormField::GetEntryMacro()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetEntryMacro(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString FormField::GetExitMacro()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetExitMacro(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL FormField::GetOwnHelp()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void FormField::SetOwnHelp(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL FormField::GetOwnStatus()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void FormField::SetOwnStatus(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString FormField::GetHelpText()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetHelpText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString FormField::GetStatusText()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetStatusText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL FormField::GetEnabled()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void FormField::SetEnabled(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString FormField::GetResult()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void FormField::SetResult(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH FormField::GetTextInput()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormField::GetCheckBox()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormField::GetDropDown()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormField::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FormField::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL FormField::GetCalculateOnExit()
	{
		BOOL result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void FormField::SetCalculateOnExit(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH FormField::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void FormField::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void FormField::Copy()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void FormField::Cut()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void FormField::Delete()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextInput properties

	/////////////////////////////////////////////////////////////////////////////
	// TextInput operations

	LPDISPATCH TextInput::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextInput::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextInput::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TextInput::GetValid()
	{
		BOOL result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString TextInput::GetDefault()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TextInput::SetDefault(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long TextInput::GetType()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString TextInput::GetFormat()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long TextInput::GetWidth()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextInput::SetWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void TextInput::Clear()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TextInput::EditType(long Type, VARIANT* Default, VARIANT* Format, VARIANT* Enabled)
	{
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type, Default, Format, Enabled);
	}


	/////////////////////////////////////////////////////////////////////////////
	// CheckBox properties

	/////////////////////////////////////////////////////////////////////////////
	// CheckBox operations

	LPDISPATCH CheckBox::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CheckBox::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CheckBox::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL CheckBox::GetValid()
	{
		BOOL result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL CheckBox::GetAutoSize()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void CheckBox::SetAutoSize(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float CheckBox::GetSize()
	{
		float result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CheckBox::SetSize(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL CheckBox::GetDefault()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void CheckBox::SetDefault(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL CheckBox::GetValue()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void CheckBox::SetValue(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// DropDown properties

	/////////////////////////////////////////////////////////////////////////////
	// DropDown operations

	LPDISPATCH DropDown::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long DropDown::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH DropDown::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL DropDown::GetValid()
	{
		BOOL result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long DropDown::GetDefault()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DropDown::SetDefault(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long DropDown::GetValue()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DropDown::SetValue(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH DropDown::GetListEntries()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListEntries properties

	/////////////////////////////////////////////////////////////////////////////
	// ListEntries operations

	LPDISPATCH ListEntries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListEntries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListEntries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN ListEntries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ListEntries::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListEntries::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH ListEntries::Add(LPCTSTR Name, VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Index);
		return result;
	}

	void ListEntries::Clear()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListEntry properties

	/////////////////////////////////////////////////////////////////////////////
	// ListEntry operations

	LPDISPATCH ListEntry::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListEntry::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListEntry::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListEntry::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString ListEntry::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ListEntry::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	void ListEntry::Delete()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TablesOfFigures properties

	/////////////////////////////////////////////////////////////////////////////
	// TablesOfFigures operations

	LPDISPATCH TablesOfFigures::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TablesOfFigures::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TablesOfFigures::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN TablesOfFigures::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TablesOfFigures::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long TablesOfFigures::GetFormat()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TablesOfFigures::SetFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH TablesOfFigures::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TablesOfFigures::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Entry, EntryAutoText, TableID, Level);
		return result;
	}

	LPDISPATCH TablesOfFigures::Add(LPDISPATCH Range, VARIANT* Caption, VARIANT* IncludeLabel, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, 
			VARIANT* IncludePageNumbers, VARIANT* AddedStyles, VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Caption, IncludeLabel, UseHeadingStyles, UpperHeadingLevel, LowerHeadingLevel, UseFields, TableID, RightAlignPageNumbers, IncludePageNumbers, AddedStyles, UseHyperlinks, HidePageNumbersInWeb);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TableOfFigures properties

	/////////////////////////////////////////////////////////////////////////////
	// TableOfFigures operations

	LPDISPATCH TableOfFigures::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfFigures::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TableOfFigures::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString TableOfFigures::GetCaption()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetCaption(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL TableOfFigures::GetIncludeLabel()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetIncludeLabel(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfFigures::GetRightAlignPageNumbers()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetRightAlignPageNumbers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfFigures::GetUseHeadingStyles()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetUseHeadingStyles(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long TableOfFigures::GetLowerHeadingLevel()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetLowerHeadingLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TableOfFigures::GetUpperHeadingLevel()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetUpperHeadingLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL TableOfFigures::GetIncludePageNumbers()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetIncludePageNumbers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH TableOfFigures::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TableOfFigures::GetUseFields()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetUseFields(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString TableOfFigures::GetTableID()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetTableID(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH TableOfFigures::GetHeadingStyles()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfFigures::GetTabLeader()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetTabLeader(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void TableOfFigures::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TableOfFigures::UpdatePageNumbers()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TableOfFigures::Update()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL TableOfFigures::GetUseHyperlinks()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetUseHyperlinks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfFigures::GetHidePageNumbersInWeb()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfFigures::SetHidePageNumbersInWeb(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMerge properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMerge operations

	LPDISPATCH MailMerge::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMerge::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMerge::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMerge::GetMainDocumentType()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetMainDocumentType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long MailMerge::GetState()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long MailMerge::GetDestination()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetDestination(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH MailMerge::GetDataSource()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMerge::GetFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMerge::GetViewMailMergeFieldCodes()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetViewMailMergeFieldCodes(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL MailMerge::GetSuppressBlankLines()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetSuppressBlankLines(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL MailMerge::GetMailAsAttachment()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetMailAsAttachment(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString MailMerge::GetMailAddressFieldName()
	{
		CString result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetMailAddressFieldName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString MailMerge::GetMailSubject()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void MailMerge::SetMailSubject(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	void MailMerge::CreateDataSource(VARIANT* Name, VARIANT* PasswordDocument, VARIANT* WritePasswordDocument, VARIANT* HeaderRecord, VARIANT* MSQuery, VARIANT* SQLStatement, VARIANT* SQLStatement1, VARIANT* Connection, VARIANT* LinkToSource)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, PasswordDocument, WritePasswordDocument, HeaderRecord, MSQuery, SQLStatement, SQLStatement1, Connection, LinkToSource);
	}

	void MailMerge::CreateHeaderSource(LPCTSTR Name, VARIANT* PasswordDocument, VARIANT* WritePasswordDocument, VARIANT* HeaderRecord)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, PasswordDocument, WritePasswordDocument, HeaderRecord);
	}

	void MailMerge::OpenDataSource(LPCTSTR Name, VARIANT* Format, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* LinkToSource, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, 
			VARIANT* WritePasswordDocument, VARIANT* WritePasswordTemplate, VARIANT* Connection, VARIANT* SQLStatement, VARIANT* SQLStatement1)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, Format, ConfirmConversions, ReadOnly, LinkToSource, AddToRecentFiles, PasswordDocument, PasswordTemplate, Revert, WritePasswordDocument, WritePasswordTemplate, Connection, SQLStatement, SQLStatement1);
	}

	void MailMerge::OpenHeaderSource(LPCTSTR Name, VARIANT* Format, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* AddToRecentFiles, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, 
			VARIANT* WritePasswordTemplate)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, Format, ConfirmConversions, ReadOnly, AddToRecentFiles, PasswordDocument, PasswordTemplate, Revert, WritePasswordDocument, WritePasswordTemplate);
	}

	void MailMerge::Execute(VARIANT* Pause)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Pause);
	}

	void MailMerge::Check()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMerge::EditDataSource()
	{
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMerge::EditHeaderSource()
	{
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMerge::EditMainDocument()
	{
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMerge::UseAddressBook(LPCTSTR Type)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type);
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFields properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFields operations

	LPDISPATCH MailMergeFields::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeFields::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeFields::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN MailMergeFields::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long MailMergeFields::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeFields::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH MailMergeFields::Add(LPDISPATCH Range, LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Name);
		return result;
	}

	LPDISPATCH MailMergeFields::AddAsk(LPDISPATCH Range, LPCTSTR Name, VARIANT* Prompt, VARIANT* DefaultAskText, VARIANT* AskOnce)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Name, Prompt, DefaultAskText, AskOnce);
		return result;
	}

	LPDISPATCH MailMergeFields::AddFillIn(LPDISPATCH Range, VARIANT* Prompt, VARIANT* DefaultFillInText, VARIANT* AskOnce)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Prompt, DefaultFillInText, AskOnce);
		return result;
	}

	LPDISPATCH MailMergeFields::AddIf(LPDISPATCH Range, LPCTSTR MergeField, long Comparison, VARIANT* CompareTo, VARIANT* TrueAutoText, VARIANT* TrueText, VARIANT* FalseAutoText, VARIANT* FalseText)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, MergeField, Comparison, CompareTo, TrueAutoText, TrueText, FalseAutoText, FalseText);
		return result;
	}

	LPDISPATCH MailMergeFields::AddMergeRec(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	LPDISPATCH MailMergeFields::AddMergeSeq(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	LPDISPATCH MailMergeFields::AddNext(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	LPDISPATCH MailMergeFields::AddNextIf(LPDISPATCH Range, LPCTSTR MergeField, long Comparison, VARIANT* CompareTo)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, MergeField, Comparison, CompareTo);
		return result;
	}

	LPDISPATCH MailMergeFields::AddSet(LPDISPATCH Range, LPCTSTR Name, VARIANT* ValueText, VARIANT* ValueAutoText)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Name, ValueText, ValueAutoText);
		return result;
	}

	LPDISPATCH MailMergeFields::AddSkipIf(LPDISPATCH Range, LPCTSTR MergeField, long Comparison, VARIANT* CompareTo)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, MergeField, Comparison, CompareTo);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeField properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeField operations

	LPDISPATCH MailMergeField::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeField::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeField::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeField::GetType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL MailMergeField::GetLocked()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void MailMergeField::SetLocked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH MailMergeField::GetCode()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void MailMergeField::SetCode(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH MailMergeField::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeField::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void MailMergeField::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMergeField::Copy()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMergeField::Cut()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMergeField::Delete()
	{
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataSource properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataSource operations

	LPDISPATCH MailMergeDataSource::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataSource::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeDataSource::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataSource::GetName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataSource::GetHeaderSourceName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataSource::GetType()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataSource::GetHeaderSourceType()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataSource::GetConnectString()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataSource::GetQueryString()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void MailMergeDataSource::SetQueryString(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long MailMergeDataSource::GetActiveRecord()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMergeDataSource::SetActiveRecord(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long MailMergeDataSource::GetFirstRecord()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMergeDataSource::SetFirstRecord(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long MailMergeDataSource::GetLastRecord()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailMergeDataSource::SetLastRecord(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH MailMergeDataSource::GetFieldNames()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeDataSource::GetDataFields()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL MailMergeDataSource::FindRecord(LPCTSTR FindText, LPCTSTR Field)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			FindText, Field);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFieldNames properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFieldNames operations

	LPDISPATCH MailMergeFieldNames::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeFieldNames::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeFieldNames::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN MailMergeFieldNames::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long MailMergeFieldNames::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeFieldNames::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFieldName properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeFieldName operations

	LPDISPATCH MailMergeFieldName::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeFieldName::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeFieldName::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString MailMergeFieldName::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long MailMergeFieldName::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataFields properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataFields operations

	LPDISPATCH MailMergeDataFields::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataFields::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeDataFields::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN MailMergeDataFields::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataFields::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeDataFields::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataField properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMergeDataField operations

	LPDISPATCH MailMergeDataField::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataField::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMergeDataField::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataField::GetValue()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString MailMergeDataField::GetName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long MailMergeDataField::GetIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Envelope properties

	/////////////////////////////////////////////////////////////////////////////
	// Envelope operations

	LPDISPATCH Envelope::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Envelope::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Envelope::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Envelope::GetAddress()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Envelope::GetReturnAddress()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Envelope::GetDefaultPrintBarCode()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultPrintBarCode(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Envelope::GetDefaultPrintFIMA()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultPrintFIMA(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Envelope::GetDefaultHeight()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Envelope::GetDefaultWidth()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Envelope::GetDefaultSize()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultSize(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL Envelope::GetDefaultOmitReturnAddress()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultOmitReturnAddress(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Envelope::GetFeedSource()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetFeedSource(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Envelope::GetAddressFromLeft()
	{
		float result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetAddressFromLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Envelope::GetAddressFromTop()
	{
		float result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetAddressFromTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Envelope::GetReturnAddressFromLeft()
	{
		float result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetReturnAddressFromLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Envelope::GetReturnAddressFromTop()
	{
		float result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetReturnAddressFromTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Envelope::GetAddressStyle()
	{
		LPDISPATCH result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Envelope::GetReturnAddressStyle()
	{
		LPDISPATCH result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Envelope::GetDefaultOrientation()
	{
		long result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultOrientation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Envelope::GetDefaultFaceUp()
	{
		BOOL result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Envelope::SetDefaultFaceUp(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void Envelope::Insert(VARIANT* ExtractAddress, VARIANT* Address, VARIANT* AutoText, VARIANT* OmitReturnAddress, VARIANT* ReturnAddress, VARIANT* ReturnAutoText, VARIANT* PrintBarCode, VARIANT* PrintFIMA, VARIANT* Size, VARIANT* Height, VARIANT* Width, 
			VARIANT* FeedSource, VARIANT* AddressFromLeft, VARIANT* AddressFromTop, VARIANT* ReturnAddressFromLeft, VARIANT* ReturnAddressFromTop, VARIANT* DefaultFaceUp, VARIANT* DefaultOrientation)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExtractAddress, Address, AutoText, OmitReturnAddress, ReturnAddress, ReturnAutoText, PrintBarCode, PrintFIMA, Size, Height, Width, FeedSource, AddressFromLeft, AddressFromTop, ReturnAddressFromLeft, ReturnAddressFromTop, DefaultFaceUp, 
			DefaultOrientation);
	}

	void Envelope::PrintOut(VARIANT* ExtractAddress, VARIANT* Address, VARIANT* AutoText, VARIANT* OmitReturnAddress, VARIANT* ReturnAddress, VARIANT* ReturnAutoText, VARIANT* PrintBarCode, VARIANT* PrintFIMA, VARIANT* Size, VARIANT* Height, 
			VARIANT* Width, VARIANT* FeedSource, VARIANT* AddressFromLeft, VARIANT* AddressFromTop, VARIANT* ReturnAddressFromLeft, VARIANT* ReturnAddressFromTop, VARIANT* DefaultFaceUp, VARIANT* DefaultOrientation)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExtractAddress, Address, AutoText, OmitReturnAddress, ReturnAddress, ReturnAutoText, PrintBarCode, PrintFIMA, Size, Height, Width, FeedSource, AddressFromLeft, AddressFromTop, ReturnAddressFromLeft, ReturnAddressFromTop, DefaultFaceUp, 
			DefaultOrientation);
	}

	void Envelope::UpdateDocument()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailingLabel properties

	/////////////////////////////////////////////////////////////////////////////
	// MailingLabel operations

	LPDISPATCH MailingLabel::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailingLabel::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailingLabel::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL MailingLabel::GetDefaultPrintBarCode()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void MailingLabel::SetDefaultPrintBarCode(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long MailingLabel::GetDefaultLaserTray()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void MailingLabel::SetDefaultLaserTray(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH MailingLabel::GetCustomLabels()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString MailingLabel::GetDefaultLabelName()
	{
		CString result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void MailingLabel::SetDefaultLabelName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH MailingLabel::CreateNewDocument(VARIANT* Name, VARIANT* Address, VARIANT* AutoText, VARIANT* ExtractAddress, VARIANT* LaserTray)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, Address, AutoText, ExtractAddress, LaserTray);
		return result;
	}

	void MailingLabel::PrintOut(VARIANT* Name, VARIANT* Address, VARIANT* ExtractAddress, VARIANT* LaserTray, VARIANT* SingleLabel, VARIANT* Row, VARIANT* Column)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Name, Address, ExtractAddress, LaserTray, SingleLabel, Row, Column);
	}


	/////////////////////////////////////////////////////////////////////////////
	// CustomLabels properties

	/////////////////////////////////////////////////////////////////////////////
	// CustomLabels operations

	LPDISPATCH CustomLabels::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CustomLabels::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CustomLabels::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN CustomLabels::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long CustomLabels::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CustomLabels::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH CustomLabels::Add(LPCTSTR Name, VARIANT* DotMatrix)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, DotMatrix);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// CustomLabel properties

	/////////////////////////////////////////////////////////////////////////////
	// CustomLabel operations

	LPDISPATCH CustomLabel::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CustomLabel::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CustomLabel::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CustomLabel::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString CustomLabel::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	float CustomLabel::GetTopMargin()
	{
		float result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetTopMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CustomLabel::GetSideMargin()
	{
		float result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetSideMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CustomLabel::GetHeight()
	{
		float result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CustomLabel::GetWidth()
	{
		float result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CustomLabel::GetVerticalPitch()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetVerticalPitch(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CustomLabel::GetHorizontalPitch()
	{
		float result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetHorizontalPitch(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long CustomLabel::GetNumberAcross()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetNumberAcross(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CustomLabel::GetNumberDown()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetNumberDown(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL CustomLabel::GetDotMatrix()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long CustomLabel::GetPageSize()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::SetPageSize(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL CustomLabel::GetValid()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void CustomLabel::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TablesOfContents properties

	/////////////////////////////////////////////////////////////////////////////
	// TablesOfContents operations

	LPDISPATCH TablesOfContents::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TablesOfContents::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TablesOfContents::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN TablesOfContents::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TablesOfContents::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long TablesOfContents::GetFormat()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TablesOfContents::SetFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH TablesOfContents::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TablesOfContents::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* TableID, VARIANT* Level)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Entry, EntryAutoText, TableID, Level);
		return result;
	}

	LPDISPATCH TablesOfContents::Add(LPDISPATCH Range, VARIANT* UseHeadingStyles, VARIANT* UpperHeadingLevel, VARIANT* LowerHeadingLevel, VARIANT* UseFields, VARIANT* TableID, VARIANT* RightAlignPageNumbers, VARIANT* IncludePageNumbers, VARIANT* AddedStyles, 
			VARIANT* UseHyperlinks, VARIANT* HidePageNumbersInWeb)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, UseHeadingStyles, UpperHeadingLevel, LowerHeadingLevel, UseFields, TableID, RightAlignPageNumbers, IncludePageNumbers, AddedStyles, UseHyperlinks, HidePageNumbersInWeb);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TableOfContents properties

	/////////////////////////////////////////////////////////////////////////////
	// TableOfContents operations

	LPDISPATCH TableOfContents::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfContents::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TableOfContents::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TableOfContents::GetUseHeadingStyles()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetUseHeadingStyles(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfContents::GetUseFields()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetUseFields(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long TableOfContents::GetUpperHeadingLevel()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetUpperHeadingLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TableOfContents::GetLowerHeadingLevel()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetLowerHeadingLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString TableOfContents::GetTableID()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetTableID(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH TableOfContents::GetHeadingStyles()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TableOfContents::GetRightAlignPageNumbers()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetRightAlignPageNumbers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfContents::GetIncludePageNumbers()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetIncludePageNumbers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH TableOfContents::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfContents::GetTabLeader()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetTabLeader(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void TableOfContents::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TableOfContents::UpdatePageNumbers()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TableOfContents::Update()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL TableOfContents::GetUseHyperlinks()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetUseHyperlinks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfContents::GetHidePageNumbersInWeb()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfContents::SetHidePageNumbersInWeb(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TablesOfAuthorities properties

	/////////////////////////////////////////////////////////////////////////////
	// TablesOfAuthorities operations

	LPDISPATCH TablesOfAuthorities::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TablesOfAuthorities::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TablesOfAuthorities::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN TablesOfAuthorities::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TablesOfAuthorities::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long TablesOfAuthorities::GetFormat()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TablesOfAuthorities::SetFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH TablesOfAuthorities::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TablesOfAuthorities::Add(LPDISPATCH Range, VARIANT* Category, VARIANT* Bookmark, VARIANT* Passim, VARIANT* KeepEntryFormatting, VARIANT* Separator, VARIANT* IncludeSequenceName, VARIANT* EntrySeparator, VARIANT* PageRangeSeparator, 
			VARIANT* IncludeCategoryHeader, VARIANT* PageNumberSeparator)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Category, Bookmark, Passim, KeepEntryFormatting, Separator, IncludeSequenceName, EntrySeparator, PageRangeSeparator, IncludeCategoryHeader, PageNumberSeparator);
		return result;
	}

	void TablesOfAuthorities::NextCitation(LPCTSTR ShortCitation)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ShortCitation);
	}

	LPDISPATCH TablesOfAuthorities::MarkCitation(LPDISPATCH Range, LPCTSTR ShortCitation, VARIANT* LongCitation, VARIANT* LongCitationAutoText, VARIANT* Category)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, ShortCitation, LongCitation, LongCitationAutoText, Category);
		return result;
	}

	void TablesOfAuthorities::MarkAllCitations(LPCTSTR ShortCitation, VARIANT* LongCitation, VARIANT* LongCitationAutoText, VARIANT* Category)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ShortCitation, LongCitation, LongCitationAutoText, Category);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TableOfAuthorities properties

	/////////////////////////////////////////////////////////////////////////////
	// TableOfAuthorities operations

	LPDISPATCH TableOfAuthorities::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfAuthorities::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TableOfAuthorities::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL TableOfAuthorities::GetPassim()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetPassim(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL TableOfAuthorities::GetKeepEntryFormatting()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetKeepEntryFormatting(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long TableOfAuthorities::GetCategory()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetCategory(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString TableOfAuthorities::GetBookmark()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetBookmark(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString TableOfAuthorities::GetSeparator()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetSeparator(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString TableOfAuthorities::GetIncludeSequenceName()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetIncludeSequenceName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString TableOfAuthorities::GetEntrySeparator()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetEntrySeparator(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString TableOfAuthorities::GetPageRangeSeparator()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetPageRangeSeparator(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL TableOfAuthorities::GetIncludeCategoryHeader()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetIncludeCategoryHeader(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString TableOfAuthorities::GetPageNumberSeparator()
	{
		CString result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetPageNumberSeparator(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH TableOfAuthorities::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfAuthorities::GetTabLeader()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthorities::SetTabLeader(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void TableOfAuthorities::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void TableOfAuthorities::Update()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Dialogs properties

	/////////////////////////////////////////////////////////////////////////////
	// Dialogs operations

	LPDISPATCH Dialogs::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Dialogs::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dialogs::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Dialogs::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Dialogs::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dialogs::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Dialog properties

	/////////////////////////////////////////////////////////////////////////////
	// Dialog operations

	LPDISPATCH Dialog::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x7d03, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Dialog::GetCreator()
	{
		long result;
		InvokeHelper(0x7d04, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dialog::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x7d05, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Dialog::GetDefaultTab()
	{
		long result;
		InvokeHelper(0x7d02, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Dialog::SetDefaultTab(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7d02, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Dialog::GetType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Dialog::Show(VARIANT* TimeOut)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x150, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			TimeOut);
		return result;
	}

	long Dialog::Display(VARIANT* TimeOut)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x152, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			TimeOut);
		return result;
	}

	void Dialog::Execute()
	{
		InvokeHelper(0x7d01, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Dialog::Update()
	{
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	CString Dialog::GetCommandName()
	{
		CString result;
		InvokeHelper(0x7d06, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// PageSetup properties

	/////////////////////////////////////////////////////////////////////////////
	// PageSetup operations

	LPDISPATCH PageSetup::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long PageSetup::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH PageSetup::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float PageSetup::GetTopMargin()
	{
		float result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetTopMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetBottomMargin()
	{
		float result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetBottomMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetLeftMargin()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetLeftMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetRightMargin()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetRightMargin(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetGutter()
	{
		float result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetGutter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetPageWidth()
	{
		float result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetPageWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetPageHeight()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetPageHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long PageSetup::GetOrientation()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetOrientation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetFirstPageTray()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetFirstPageTray(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetOtherPagesTray()
	{
		long result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetOtherPagesTray(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetVerticalAlignment()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetVerticalAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetMirrorMargins()
	{
		long result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetMirrorMargins(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float PageSetup::GetHeaderDistance()
	{
		float result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetHeaderDistance(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetFooterDistance()
	{
		float result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetFooterDistance(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long PageSetup::GetSectionStart()
	{
		long result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetSectionStart(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetOddAndEvenPagesHeaderFooter()
	{
		long result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetOddAndEvenPagesHeaderFooter(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetDifferentFirstPageHeaderFooter()
	{
		long result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetDifferentFirstPageHeaderFooter(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetSuppressEndnotes()
	{
		long result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetSuppressEndnotes(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH PageSetup::GetLineNumbering()
	{
		LPDISPATCH result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetLineNumbering(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH PageSetup::GetTextColumns()
	{
		LPDISPATCH result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetTextColumns(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long PageSetup::GetPaperSize()
	{
		long result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetPaperSize(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL PageSetup::GetTwoPagesOnOne()
	{
		BOOL result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetTwoPagesOnOne(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float PageSetup::GetCharsLine()
	{
		float result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetCharsLine(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PageSetup::GetLinesPage()
	{
		float result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetLinesPage(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL PageSetup::GetShowGrid()
	{
		BOOL result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetShowGrid(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void PageSetup::TogglePortrait()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void PageSetup::SetAsTemplateDefault()
	{
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long PageSetup::GetGutterStyle()
	{
		long result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetGutterStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetSectionDirection()
	{
		long result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetSectionDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetLayoutMode()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetLayoutMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageSetup::GetGutterPos()
	{
		long result;
		InvokeHelper(0x4c6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageSetup::SetGutterPos(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4c6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// LineNumbering properties

	/////////////////////////////////////////////////////////////////////////////
	// LineNumbering operations

	LPDISPATCH LineNumbering::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LineNumbering::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH LineNumbering::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LineNumbering::GetRestartMode()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineNumbering::SetRestartMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineNumbering::GetStartingNumber()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineNumbering::SetStartingNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float LineNumbering::GetDistanceFromText()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void LineNumbering::SetDistanceFromText(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long LineNumbering::GetCountBy()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineNumbering::SetCountBy(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineNumbering::GetActive()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineNumbering::SetActive(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextColumns properties

	/////////////////////////////////////////////////////////////////////////////
	// TextColumns operations

	LPUNKNOWN TextColumns::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TextColumns::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextColumns::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextColumns::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextColumns::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextColumns::GetEvenlySpaced()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextColumns::SetEvenlySpaced(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextColumns::GetLineBetween()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextColumns::SetLineBetween(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float TextColumns::GetWidth()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextColumns::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float TextColumns::GetSpacing()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextColumns::SetSpacing(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH TextColumns::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH TextColumns::Add(VARIANT* Width, VARIANT* Spacing, VARIANT* EvenlySpaced)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Width, Spacing, EvenlySpaced);
		return result;
	}

	void TextColumns::SetCount(long NumColumns)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumColumns);
	}

	long TextColumns::GetFlowDirection()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextColumns::SetFlowDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextColumn properties

	/////////////////////////////////////////////////////////////////////////////
	// TextColumn operations

	LPDISPATCH TextColumn::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextColumn::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextColumn::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float TextColumn::GetWidth()
	{
		float result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextColumn::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float TextColumn::GetSpaceAfter()
	{
		float result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextColumn::SetSpaceAfter(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Selection properties

	/////////////////////////////////////////////////////////////////////////////
	// Selection operations

	CString Selection::GetText()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Selection::SetText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Selection::GetFormattedText()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::SetFormattedText(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Selection::GetStart()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetStart(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Selection::GetEnd()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetEnd(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Selection::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Selection::GetType()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Selection::GetStoryType()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT Selection::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Selection::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Selection::GetTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x32, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetWords()
	{
		LPDISPATCH result;
		InvokeHelper(0x33, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetSentences()
	{
		LPDISPATCH result;
		InvokeHelper(0x34, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetCharacters()
	{
		LPDISPATCH result;
		InvokeHelper(0x35, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetFootnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetEndnotes()
	{
		LPDISPATCH result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetComments()
	{
		LPDISPATCH result;
		InvokeHelper(0x38, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetCells()
	{
		LPDISPATCH result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetSections()
	{
		LPDISPATCH result;
		InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Selection::GetShading()
	{
		LPDISPATCH result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetFormFields()
	{
		LPDISPATCH result;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetFrames()
	{
		LPDISPATCH result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetParagraphFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x44e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::SetParagraphFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Selection::GetPageSetup()
	{
		LPDISPATCH result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::SetPageSetup(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Selection::GetBookmarks()
	{
		LPDISPATCH result;
		InvokeHelper(0x4b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Selection::GetStoryLength()
	{
		long result;
		InvokeHelper(0x98, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Selection::GetLanguageID()
	{
		long result;
		InvokeHelper(0x99, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x99, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Selection::GetLanguageIDFarEast()
	{
		long result;
		InvokeHelper(0x9a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetLanguageIDFarEast(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Selection::GetLanguageIDOther()
	{
		long result;
		InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetLanguageIDOther(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Selection::GetHyperlinks()
	{
		LPDISPATCH result;
		InvokeHelper(0x9c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetColumns()
	{
		LPDISPATCH result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetRows()
	{
		LPDISPATCH result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetHeaderFooter()
	{
		LPDISPATCH result;
		InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Selection::GetIsEndOfRowMark()
	{
		BOOL result;
		InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Selection::GetBookmarkID()
	{
		long result;
		InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Selection::GetPreviousBookmarkID()
	{
		long result;
		InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetFind()
	{
		LPDISPATCH result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT Selection::GetInformation(long Type)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
			Type);
		return result;
	}

	long Selection::GetFlags()
	{
		long result;
		InvokeHelper(0x192, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetFlags(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x192, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Selection::GetActive()
	{
		BOOL result;
		InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Selection::GetStartIsActive()
	{
		BOOL result;
		InvokeHelper(0x194, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Selection::SetStartIsActive(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x194, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Selection::GetIPAtEndOfLine()
	{
		BOOL result;
		InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Selection::GetExtendMode()
	{
		BOOL result;
		InvokeHelper(0x196, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Selection::SetExtendMode(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x196, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Selection::GetColumnSelectMode()
	{
		BOOL result;
		InvokeHelper(0x197, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Selection::SetColumnSelectMode(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x197, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Selection::GetOrientation()
	{
		long result;
		InvokeHelper(0x19a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetOrientation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x19a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Selection::GetInlineShapes()
	{
		LPDISPATCH result;
		InvokeHelper(0x19b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Selection::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GetShapeRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ec, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SetRange(long Start, long End)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Start, End);
	}

	void Selection::Collapse(VARIANT* Direction)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Direction);
	}

	void Selection::InsertBefore(LPCTSTR Text)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text);
	}

	void Selection::InsertAfter(LPCTSTR Text)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text);
	}

	LPDISPATCH Selection::Next(VARIANT* Unit, VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	LPDISPATCH Selection::Previous(VARIANT* Unit, VARIANT* Count)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Selection::StartOf(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	long Selection::EndOf(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	long Selection::Move(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Selection::MoveStart(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Selection::MoveEnd(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Selection::MoveWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Selection::MoveStartWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Selection::MoveEndWhile(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Selection::MoveUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Selection::MoveStartUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	long Selection::MoveEndUntil(VARIANT* Cset, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Cset, Count);
		return result;
	}

	void Selection::Cut()
	{
		InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::Copy()
	{
		InvokeHelper(0x78, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::Paste()
	{
		InvokeHelper(0x79, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertBreak(VARIANT* Type)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Type);
	}

	void Selection::InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileName, Range, ConfirmConversions, Link, Attachment);
	}

	BOOL Selection::InStory(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	BOOL Selection::InRange(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	long Selection::Delete(VARIANT* Unit, VARIANT* Count)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count);
		return result;
	}

	long Selection::Expand(VARIANT* Unit)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit);
		return result;
	}

	void Selection::InsertParagraph()
	{
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertParagraphAfter()
	{
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertSymbol(long CharacterNumber, VARIANT* Font, VARIANT* Unicode, VARIANT* Bias)
	{
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 CharacterNumber, Font, Unicode, Bias);
	}

	void Selection::InsertCrossReference(VARIANT* ReferenceType, long ReferenceKind, VARIANT* ReferenceItem, VARIANT* InsertAsHyperlink, VARIANT* IncludePosition)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_I4 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ReferenceType, ReferenceKind, ReferenceItem, InsertAsHyperlink, IncludePosition);
	}

	void Selection::InsertCaption(VARIANT* Label, VARIANT* Title, VARIANT* TitleAutoText, VARIANT* Position)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Label, Title, TitleAutoText, Position);
	}

	void Selection::CopyAsPicture()
	{
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SortAscending()
	{
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SortDescending()
	{
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL Selection::IsEqual(LPDISPATCH Range)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Range);
		return result;
	}

	float Selection::Calculate()
	{
		float result;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_R4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::GoTo(VARIANT* What, VARIANT* Which, VARIANT* Count, VARIANT* Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What, Which, Count, Name);
		return result;
	}

	LPDISPATCH Selection::GoToNext(long What)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What);
		return result;
	}

	LPDISPATCH Selection::GoToPrevious(long What)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			What);
		return result;
	}

	void Selection::PasteSpecial(VARIANT* IconIndex, VARIANT* Link, VARIANT* Placement, VARIANT* DisplayAsIcon, VARIANT* DataType, VARIANT* IconFileName, VARIANT* IconLabel)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 IconIndex, Link, Placement, DisplayAsIcon, DataType, IconFileName, IconLabel);
	}

	LPDISPATCH Selection::PreviousField()
	{
		LPDISPATCH result;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Selection::NextField()
	{
		LPDISPATCH result;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Selection::InsertParagraphBefore()
	{
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertCells(VARIANT* ShiftCells)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ShiftCells);
	}

	void Selection::Extend(VARIANT* Character)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x12c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Character);
	}

	void Selection::Shrink()
	{
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Selection::MoveLeft(VARIANT* Unit, VARIANT* Count, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f4, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count, Extend);
		return result;
	}

	long Selection::MoveRight(VARIANT* Unit, VARIANT* Count, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count, Extend);
		return result;
	}

	long Selection::MoveUp(VARIANT* Unit, VARIANT* Count, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f6, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count, Extend);
		return result;
	}

	long Selection::MoveDown(VARIANT* Unit, VARIANT* Count, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Count, Extend);
		return result;
	}

	long Selection::HomeKey(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f8, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	long Selection::EndKey(VARIANT* Unit, VARIANT* Extend)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f9, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			Unit, Extend);
		return result;
	}

	void Selection::EscapeKey()
	{
		InvokeHelper(0x1fa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::TypeText(LPCTSTR Text)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x1fb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Text);
	}

	void Selection::CopyFormat()
	{
		InvokeHelper(0x1fd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::PasteFormat()
	{
		InvokeHelper(0x1fe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::TypeParagraph()
	{
		InvokeHelper(0x200, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::TypeBackspace()
	{
		InvokeHelper(0x201, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::NextSubdocument()
	{
		InvokeHelper(0x202, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::PreviousSubdocument()
	{
		InvokeHelper(0x203, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectColumn()
	{
		InvokeHelper(0x204, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentFont()
	{
		InvokeHelper(0x205, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentAlignment()
	{
		InvokeHelper(0x206, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentSpacing()
	{
		InvokeHelper(0x207, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentIndent()
	{
		InvokeHelper(0x208, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentTabs()
	{
		InvokeHelper(0x209, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCurrentColor()
	{
		InvokeHelper(0x20a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::CreateTextbox()
	{
		InvokeHelper(0x20b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::WholeStory()
	{
		InvokeHelper(0x20c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectRow()
	{
		InvokeHelper(0x20d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SplitTable()
	{
		InvokeHelper(0x20e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertRows(VARIANT* NumRows)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x210, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumRows);
	}

	void Selection::InsertColumns()
	{
		InvokeHelper(0x211, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertFormula(VARIANT* Formula, VARIANT* NumberFormat)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x212, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Formula, NumberFormat);
	}

	LPDISPATCH Selection::NextRevision(VARIANT* Wrap)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x213, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Wrap);
		return result;
	}

	LPDISPATCH Selection::PreviousRevision(VARIANT* Wrap)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x214, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Wrap);
		return result;
	}

	void Selection::PasteAsNestedTable()
	{
		InvokeHelper(0x215, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Selection::CreateAutoTextEntry(LPCTSTR Name, LPCTSTR StyleName)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x216, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, StyleName);
		return result;
	}

	void Selection::DetectLanguage()
	{
		InvokeHelper(0x217, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::SelectCell()
	{
		InvokeHelper(0x218, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertRowsBelow(VARIANT* NumRows)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x219, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumRows);
	}

	void Selection::InsertColumnsRight()
	{
		InvokeHelper(0x21a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertRowsAbove(VARIANT* NumRows)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x21b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumRows);
	}

	void Selection::RtlRun()
	{
		InvokeHelper(0x258, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::LtrRun()
	{
		InvokeHelper(0x259, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::BoldRun()
	{
		InvokeHelper(0x25a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::ItalicRun()
	{
		InvokeHelper(0x25b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::RtlPara()
	{
		InvokeHelper(0x25d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::LtrPara()
	{
		InvokeHelper(0x25e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Selection::InsertDateTime(VARIANT* DateTimeFormat, VARIANT* InsertAsField, VARIANT* InsertAsFullWidth, VARIANT* DateLanguage, VARIANT* CalendarType)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DateTimeFormat, InsertAsField, InsertAsFullWidth, DateLanguage, CalendarType);
	}

	void Selection::Sort(VARIANT* ExcludeHeader, VARIANT* FieldNumber, VARIANT* SortFieldType, VARIANT* SortOrder, VARIANT* FieldNumber2, VARIANT* SortFieldType2, VARIANT* SortOrder2, VARIANT* FieldNumber3, VARIANT* SortFieldType3, VARIANT* SortOrder3, 
			VARIANT* SortColumn, VARIANT* Separator, VARIANT* CaseSensitive, VARIANT* BidiSort, VARIANT* IgnoreThe, VARIANT* IgnoreKashida, VARIANT* IgnoreDiacritics, VARIANT* IgnoreHe, VARIANT* LanguageID)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT 
			VTS_PVARIANT;
		InvokeHelper(0x1bd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ExcludeHeader, FieldNumber, SortFieldType, SortOrder, FieldNumber2, SortFieldType2, SortOrder2, FieldNumber3, SortFieldType3, SortOrder3, SortColumn, Separator, CaseSensitive, BidiSort, IgnoreThe, IgnoreKashida, IgnoreDiacritics, 
			IgnoreHe, LanguageID);
	}

	LPDISPATCH Selection::ConvertToTable(VARIANT* Separator, VARIANT* NumRows, VARIANT* NumColumns, VARIANT* InitialColumnWidth, VARIANT* Format, VARIANT* ApplyBorders, VARIANT* ApplyShading, VARIANT* ApplyFont, VARIANT* ApplyColor, 
			VARIANT* ApplyHeadingRows, VARIANT* ApplyLastRow, VARIANT* ApplyFirstColumn, VARIANT* ApplyLastColumn, VARIANT* AutoFit, VARIANT* AutoFitBehavior, VARIANT* DefaultTableBehavior)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1c9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Separator, NumRows, NumColumns, InitialColumnWidth, Format, ApplyBorders, ApplyShading, ApplyFont, ApplyColor, ApplyHeadingRows, ApplyLastRow, ApplyFirstColumn, ApplyLastColumn, AutoFit, AutoFitBehavior, DefaultTableBehavior);
		return result;
	}

	long Selection::GetNoProofing()
	{
		long result;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetNoProofing(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Selection::GetTopLevelTables()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ee, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Selection::GetLanguageDetected()
	{
		BOOL result;
		InvokeHelper(0x3ef, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Selection::SetLanguageDetected(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3ef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Selection::GetFitTextWidth()
	{
		float result;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Selection::SetFitTextWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TablesOfAuthoritiesCategories properties

	/////////////////////////////////////////////////////////////////////////////
	// TablesOfAuthoritiesCategories operations

	LPDISPATCH TablesOfAuthoritiesCategories::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TablesOfAuthoritiesCategories::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TablesOfAuthoritiesCategories::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN TablesOfAuthoritiesCategories::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long TablesOfAuthoritiesCategories::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TablesOfAuthoritiesCategories::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TableOfAuthoritiesCategory properties

	/////////////////////////////////////////////////////////////////////////////
	// TableOfAuthoritiesCategory operations

	LPDISPATCH TableOfAuthoritiesCategory::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TableOfAuthoritiesCategory::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TableOfAuthoritiesCategory::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString TableOfAuthoritiesCategory::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TableOfAuthoritiesCategory::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long TableOfAuthoritiesCategory::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// CaptionLabels properties

	/////////////////////////////////////////////////////////////////////////////
	// CaptionLabels operations

	LPDISPATCH CaptionLabels::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CaptionLabels::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CaptionLabels::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN CaptionLabels::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long CaptionLabels::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CaptionLabels::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH CaptionLabels::Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// CaptionLabel properties

	/////////////////////////////////////////////////////////////////////////////
	// CaptionLabel operations

	LPDISPATCH CaptionLabel::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CaptionLabel::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CaptionLabel::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString CaptionLabel::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL CaptionLabel::GetBuiltIn()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long CaptionLabel::GetId()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL CaptionLabel::GetIncludeChapterNumber()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void CaptionLabel::SetIncludeChapterNumber(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long CaptionLabel::GetNumberStyle()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CaptionLabel::SetNumberStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CaptionLabel::GetChapterStyleLevel()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CaptionLabel::SetChapterStyleLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CaptionLabel::GetSeparator()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CaptionLabel::SetSeparator(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CaptionLabel::GetPosition()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CaptionLabel::SetPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void CaptionLabel::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoCaptions properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoCaptions operations

	LPDISPATCH AutoCaptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCaptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCaptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN AutoCaptions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long AutoCaptions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCaptions::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void AutoCaptions::CancelAutoInsert()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AutoCaption properties

	/////////////////////////////////////////////////////////////////////////////
	// AutoCaption operations

	LPDISPATCH AutoCaption::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AutoCaption::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AutoCaption::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString AutoCaption::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL AutoCaption::GetAutoInsert()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AutoCaption::SetAutoInsert(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long AutoCaption::GetIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT AutoCaption::GetCaptionLabel()
	{
		VARIANT result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void AutoCaption::SetCaptionLabel(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Indexes properties

	/////////////////////////////////////////////////////////////////////////////
	// Indexes operations

	LPDISPATCH Indexes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Indexes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Indexes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Indexes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Indexes::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Indexes::GetFormat()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Indexes::SetFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Indexes::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Indexes::MarkEntry(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic, VARIANT* Reading)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, Entry, EntryAutoText, CrossReference, CrossReferenceAutoText, BookmarkName, Bold, Italic, Reading);
		return result;
	}

	void Indexes::MarkAllEntries(LPDISPATCH Range, VARIANT* Entry, VARIANT* EntryAutoText, VARIANT* CrossReference, VARIANT* CrossReferenceAutoText, VARIANT* BookmarkName, VARIANT* Bold, VARIANT* Italic)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Range, Entry, EntryAutoText, CrossReference, CrossReferenceAutoText, BookmarkName, Bold, Italic);
	}

	void Indexes::AutoMarkEntries(LPCTSTR ConcordanceFileName)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ConcordanceFileName);
	}

	LPDISPATCH Indexes::Add(LPDISPATCH Range, VARIANT* HeadingSeparator, VARIANT* RightAlignPageNumbers, VARIANT* Type, VARIANT* NumberOfColumns, VARIANT* AccentedLetters, VARIANT* SortBy, VARIANT* IndexLanguage)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range, HeadingSeparator, RightAlignPageNumbers, Type, NumberOfColumns, AccentedLetters, SortBy, IndexLanguage);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Index properties

	/////////////////////////////////////////////////////////////////////////////
	// Index operations

	LPDISPATCH Index::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Index::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Index::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Index::GetHeadingSeparator()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetHeadingSeparator(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Index::GetRightAlignPageNumbers()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Index::SetRightAlignPageNumbers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Index::GetType()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Index::GetNumberOfColumns()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetNumberOfColumns(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Index::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Index::GetTabLeader()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetTabLeader(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Index::GetAccentedLetters()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Index::SetAccentedLetters(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Index::GetSortBy()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetSortBy(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Index::GetFilter()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetFilter(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Index::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Index::Update()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	long Index::GetIndexLanguage()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Index::SetIndexLanguage(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AddIn properties

	/////////////////////////////////////////////////////////////////////////////
	// AddIn operations

	LPDISPATCH AddIn::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AddIn::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AddIn::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString AddIn::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long AddIn::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString AddIn::GetPath()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL AddIn::GetInstalled()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AddIn::SetInstalled(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL AddIn::GetCompiled()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL AddIn::GetAutoload()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void AddIn::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// AddIns properties

	/////////////////////////////////////////////////////////////////////////////
	// AddIns operations

	LPDISPATCH AddIns::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long AddIns::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AddIns::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN AddIns::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long AddIns::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH AddIns::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH AddIns::Add(LPCTSTR FileName, VARIANT* Install)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, Install);
		return result;
	}

	void AddIns::Unload(BOOL RemoveFromList)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 RemoveFromList);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Revisions properties

	/////////////////////////////////////////////////////////////////////////////
	// Revisions operations

	LPDISPATCH Revisions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Revisions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Revisions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Revisions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Revisions::GetCount()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Revisions::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void Revisions::AcceptAll()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Revisions::RejectAll()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Revision properties

	/////////////////////////////////////////////////////////////////////////////
	// Revision operations

	LPDISPATCH Revision::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Revision::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Revision::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Revision::GetAuthor()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	DATE Revision::GetDate()
	{
		DATE result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Revision::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Revision::GetType()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Revision::GetIndex()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Revision::Accept()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Revision::Reject()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Task properties

	/////////////////////////////////////////////////////////////////////////////
	// Task operations

	LPDISPATCH Task::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Task::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Task::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Task::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long Task::GetLeft()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Task::SetLeft(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Task::GetTop()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Task::SetTop(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Task::GetWidth()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Task::SetWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Task::GetHeight()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Task::SetHeight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Task::GetWindowState()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Task::SetWindowState(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Task::GetVisible()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Task::SetVisible(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void Task::Activate(VARIANT* Wait)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Wait);
	}

	void Task::Close()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Task::Move(long Left, long Top)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Left, Top);
	}

	void Task::Resize(long Width, long Height)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Width, Height);
	}

	void Task::SendWindowMessage(long Message, long wParam, long lParam)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Message, wParam, lParam);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Tasks properties

	/////////////////////////////////////////////////////////////////////////////
	// Tasks operations

	LPDISPATCH Tasks::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Tasks::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Tasks::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Tasks::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Tasks::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Tasks::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	BOOL Tasks::Exists(LPCTSTR Name)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			Name);
		return result;
	}

	void Tasks::ExitWindows_()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// HeadersFooters properties

	/////////////////////////////////////////////////////////////////////////////
	// HeadersFooters operations

	LPDISPATCH HeadersFooters::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HeadersFooters::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeadersFooters::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN HeadersFooters::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long HeadersFooters::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeadersFooters::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// HeaderFooter properties

	/////////////////////////////////////////////////////////////////////////////
	// HeaderFooter operations

	LPDISPATCH HeaderFooter::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HeaderFooter::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeaderFooter::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeaderFooter::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HeaderFooter::GetIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL HeaderFooter::GetIsHeader()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL HeaderFooter::GetExists()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void HeaderFooter::SetExists(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH HeaderFooter::GetPageNumbers()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL HeaderFooter::GetLinkToPrevious()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void HeaderFooter::SetLinkToPrevious(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH HeaderFooter::GetShapes()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// PageNumbers properties

	/////////////////////////////////////////////////////////////////////////////
	// PageNumbers operations

	LPDISPATCH PageNumbers::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long PageNumbers::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH PageNumbers::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN PageNumbers::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long PageNumbers::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long PageNumbers::GetNumberStyle()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetNumberStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL PageNumbers::GetIncludeChapterNumber()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetIncludeChapterNumber(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long PageNumbers::GetHeadingLevelForChapter()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetHeadingLevelForChapter(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PageNumbers::GetChapterPageSeparator()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetChapterPageSeparator(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL PageNumbers::GetRestartNumberingAtSection()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetRestartNumberingAtSection(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long PageNumbers::GetStartingNumber()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetStartingNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL PageNumbers::GetShowFirstPageNumber()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetShowFirstPageNumber(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH PageNumbers::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH PageNumbers::Add(VARIANT* PageNumberAlignment, VARIANT* FirstPage)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			PageNumberAlignment, FirstPage);
		return result;
	}

	BOOL PageNumbers::GetDoubleQuote()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void PageNumbers::SetDoubleQuote(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// PageNumber properties

	/////////////////////////////////////////////////////////////////////////////
	// PageNumber operations

	LPDISPATCH PageNumber::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long PageNumber::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH PageNumber::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long PageNumber::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long PageNumber::GetAlignment()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PageNumber::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void PageNumber::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void PageNumber::Copy()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void PageNumber::Cut()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void PageNumber::Delete()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Subdocuments properties

	/////////////////////////////////////////////////////////////////////////////
	// Subdocuments operations

	LPDISPATCH Subdocuments::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Subdocuments::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Subdocuments::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Subdocuments::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Subdocuments::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	BOOL Subdocuments::GetExpanded()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Subdocuments::SetExpanded(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Subdocuments::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Subdocuments::AddFromFile(VARIANT* Name, VARIANT* ConfirmConversions, VARIANT* ReadOnly, VARIANT* PasswordDocument, VARIANT* PasswordTemplate, VARIANT* Revert, VARIANT* WritePasswordDocument, VARIANT* WritePasswordTemplate)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name, ConfirmConversions, ReadOnly, PasswordDocument, PasswordTemplate, Revert, WritePasswordDocument, WritePasswordTemplate);
		return result;
	}

	LPDISPATCH Subdocuments::AddFromRange(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	void Subdocuments::Merge(VARIANT* FirstSubdocument, VARIANT* LastSubdocument)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FirstSubdocument, LastSubdocument);
	}

	void Subdocuments::Delete()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Subdocuments::Select()
	{
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Subdocument properties

	/////////////////////////////////////////////////////////////////////////////
	// Subdocument operations

	LPDISPATCH Subdocument::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Subdocument::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Subdocument::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Subdocument::GetLocked()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Subdocument::SetLocked(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Subdocument::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Subdocument::GetName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString Subdocument::GetPath()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL Subdocument::GetHasFile()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Subdocument::GetLevel()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Subdocument::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Subdocument::Split(LPDISPATCH Range)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Range);
	}

	LPDISPATCH Subdocument::Open()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// HeadingStyles properties

	/////////////////////////////////////////////////////////////////////////////
	// HeadingStyles operations

	LPDISPATCH HeadingStyles::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HeadingStyles::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeadingStyles::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN HeadingStyles::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long HeadingStyles::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeadingStyles::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH HeadingStyles::Add(VARIANT* Style, short Level)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_I2;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Style, Level);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// HeadingStyle properties

	/////////////////////////////////////////////////////////////////////////////
	// HeadingStyle operations

	LPDISPATCH HeadingStyle::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HeadingStyle::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HeadingStyle::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT HeadingStyle::GetStyle()
	{
		VARIANT result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void HeadingStyle::SetStyle(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	short HeadingStyle::GetLevel()
	{
		short result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
		return result;
	}

	void HeadingStyle::SetLevel(short nNewValue)
	{
		static BYTE parms[] =
			VTS_I2;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void HeadingStyle::Delete()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// StoryRanges properties

	/////////////////////////////////////////////////////////////////////////////
	// StoryRanges operations

	LPUNKNOWN StoryRanges::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long StoryRanges::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH StoryRanges::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long StoryRanges::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH StoryRanges::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH StoryRanges::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListLevel properties

	/////////////////////////////////////////////////////////////////////////////
	// ListLevel operations

	long ListLevel::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString ListLevel::GetNumberFormat()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetNumberFormat(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long ListLevel::GetTrailingCharacter()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetTrailingCharacter(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ListLevel::GetNumberStyle()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetNumberStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float ListLevel::GetNumberPosition()
	{
		float result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetNumberPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ListLevel::GetAlignment()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float ListLevel::GetTextPosition()
	{
		float result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetTextPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float ListLevel::GetTabPosition()
	{
		float result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetTabPosition(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ListLevel::GetStartAt()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetStartAt(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString ListLevel::GetLinkedStyle()
	{
		CString result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetLinkedStyle(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH ListLevel::GetFont()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetFont(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH ListLevel::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListLevel::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListLevel::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListLevel::GetResetOnHigher()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ListLevel::SetResetOnHigher(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListLevels properties

	/////////////////////////////////////////////////////////////////////////////
	// ListLevels operations

	LPUNKNOWN ListLevels::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ListLevels::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListLevels::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListLevels::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListLevels::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListLevels::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListTemplate properties

	/////////////////////////////////////////////////////////////////////////////
	// ListTemplate operations

	LPDISPATCH ListTemplate::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListTemplate::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListTemplate::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL ListTemplate::GetOutlineNumbered()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void ListTemplate::SetOutlineNumbered(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString ListTemplate::GetName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ListTemplate::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH ListTemplate::GetListLevels()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListTemplate::Convert(VARIANT* Level)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Level);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListTemplates properties

	/////////////////////////////////////////////////////////////////////////////
	// ListTemplates operations

	LPUNKNOWN ListTemplates::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ListTemplates::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListTemplates::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListTemplates::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListTemplates::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListTemplates::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH ListTemplates::Add(VARIANT* OutlineNumbered, VARIANT* Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			OutlineNumbered, Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListParagraphs properties

	/////////////////////////////////////////////////////////////////////////////
	// ListParagraphs operations

	LPUNKNOWN ListParagraphs::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ListParagraphs::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListParagraphs::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListParagraphs::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListParagraphs::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListParagraphs::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// List properties

	/////////////////////////////////////////////////////////////////////////////
	// List operations

	LPDISPATCH List::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH List::GetListParagraphs()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL List::GetSingleListTemplate()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH List::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long List::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH List::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void List::ConvertNumbersToText(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	void List::RemoveNumbers(VARIANT* NumberType)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NumberType);
	}

	long List::CountNumberedItems(VARIANT* NumberType, VARIANT* Level)
	{
		long result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			NumberType, Level);
		return result;
	}

	long List::CanContinuePreviousList(LPDISPATCH ListTemplate)
	{
		long result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
			ListTemplate);
		return result;
	}

	void List::ApplyListTemplate(LPDISPATCH ListTemplate, VARIANT* ContinuePreviousList, VARIANT* DefaultListBehavior)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ListTemplate, ContinuePreviousList, DefaultListBehavior);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Lists properties

	/////////////////////////////////////////////////////////////////////////////
	// Lists operations

	LPUNKNOWN Lists::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Lists::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Lists::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Lists::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Lists::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Lists::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListGallery properties

	/////////////////////////////////////////////////////////////////////////////
	// ListGallery operations

	LPDISPATCH ListGallery::GetListTemplates()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListGallery::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListGallery::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListGallery::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL ListGallery::GetModified(long Index)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
			Index);
		return result;
	}

	void ListGallery::Reset(long Index)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ListGalleries properties

	/////////////////////////////////////////////////////////////////////////////
	// ListGalleries operations

	LPUNKNOWN ListGalleries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ListGalleries::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListGalleries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ListGalleries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListGalleries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ListGalleries::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// KeyBindings properties

	/////////////////////////////////////////////////////////////////////////////
	// KeyBindings operations

	LPDISPATCH KeyBindings::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long KeyBindings::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeyBindings::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN KeyBindings::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long KeyBindings::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeyBindings::GetContext()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeyBindings::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH KeyBindings::Add(long KeyCategory, LPCTSTR Command, long KeyCode, VARIANT* KeyCode2, VARIANT* CommandParameter)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_I4 VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			KeyCategory, Command, KeyCode, KeyCode2, CommandParameter);
		return result;
	}

	void KeyBindings::ClearAll()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH KeyBindings::Key(long KeyCode, VARIANT* KeyCode2)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// KeysBoundTo properties

	/////////////////////////////////////////////////////////////////////////////
	// KeysBoundTo operations

	LPDISPATCH KeysBoundTo::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long KeysBoundTo::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeysBoundTo::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN KeysBoundTo::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long KeysBoundTo::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long KeysBoundTo::GetKeyCategory()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString KeysBoundTo::GetCommand()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString KeysBoundTo::GetCommandParameter()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeysBoundTo::GetContext()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeysBoundTo::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH KeysBoundTo::Key(long KeyCode, VARIANT* KeyCode2)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			KeyCode, KeyCode2);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// KeyBinding properties

	/////////////////////////////////////////////////////////////////////////////
	// KeyBinding operations

	LPDISPATCH KeyBinding::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long KeyBinding::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeyBinding::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString KeyBinding::GetCommand()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString KeyBinding::GetKeyString()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL KeyBinding::GetProtected()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long KeyBinding::GetKeyCategory()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long KeyBinding::GetKeyCode()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long KeyBinding::GetKeyCode2()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString KeyBinding::GetCommandParameter()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH KeyBinding::GetContext()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void KeyBinding::Clear()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void KeyBinding::Disable()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void KeyBinding::Execute()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void KeyBinding::Rebind(long KeyCategory, LPCTSTR Command, VARIANT* CommandParameter)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 KeyCategory, Command, CommandParameter);
	}


	/////////////////////////////////////////////////////////////////////////////
	// FileConverter properties

	/////////////////////////////////////////////////////////////////////////////
	// FileConverter operations

	LPDISPATCH FileConverter::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FileConverter::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FileConverter::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString FileConverter::GetFormatName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString FileConverter::GetClassName()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long FileConverter::GetSaveFormat()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FileConverter::GetOpenFormat()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL FileConverter::GetCanSave()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL FileConverter::GetCanOpen()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString FileConverter::GetPath()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString FileConverter::GetName()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString FileConverter::GetExtensions()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// FileConverters properties

	/////////////////////////////////////////////////////////////////////////////
	// FileConverters operations

	LPDISPATCH FileConverters::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FileConverters::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FileConverters::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FileConverters::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN FileConverters::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long FileConverters::GetConvertMacWordChevrons()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void FileConverters::SetConvertMacWordChevrons(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH FileConverters::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// SynonymInfo properties

	/////////////////////////////////////////////////////////////////////////////
	// SynonymInfo operations

	LPDISPATCH SynonymInfo::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long SynonymInfo::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH SynonymInfo::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString SynonymInfo::GetWord()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	BOOL SynonymInfo::GetFound()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long SynonymInfo::GetMeaningCount()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT SynonymInfo::GetMeaningList()
	{
		VARIANT result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	VARIANT SynonymInfo::GetPartOfSpeechList()
	{
		VARIANT result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	VARIANT SynonymInfo::GetSynonymList(VARIANT* Meaning)
	{
		VARIANT result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
			Meaning);
		return result;
	}

	VARIANT SynonymInfo::GetAntonymList()
	{
		VARIANT result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	VARIANT SynonymInfo::GetRelatedExpressionList()
	{
		VARIANT result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	VARIANT SynonymInfo::GetRelatedWordList()
	{
		VARIANT result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Hyperlinks properties

	/////////////////////////////////////////////////////////////////////////////
	// Hyperlinks operations

	LPDISPATCH Hyperlinks::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Hyperlinks::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Hyperlinks::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Hyperlinks::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Hyperlinks::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Hyperlinks::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Hyperlinks::Add(LPDISPATCH Anchor, VARIANT* Address, VARIANT* SubAddress, VARIANT* ScreenTip, VARIANT* TextToDisplay, VARIANT* Target)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Anchor, Address, SubAddress, ScreenTip, TextToDisplay, Target);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Hyperlink properties

	/////////////////////////////////////////////////////////////////////////////
	// Hyperlink operations

	LPDISPATCH Hyperlink::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Hyperlink::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Hyperlink::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Hyperlink::GetName()
	{
		CString result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long Hyperlink::GetType()
	{
		long result;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Hyperlink::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ee, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Hyperlink::GetShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ef, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Hyperlink::GetExtraInfoRequired()
	{
		BOOL result;
		InvokeHelper(0x3f1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::Delete()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Hyperlink::Follow(VARIANT* NewWindow, VARIANT* AddHistory, VARIANT* ExtraInfo, VARIANT* Method, VARIANT* HeaderInfo)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 NewWindow, AddHistory, ExtraInfo, Method, HeaderInfo);
	}

	void Hyperlink::AddToFavorites()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Hyperlink::CreateNewDocument(LPCTSTR FileName, BOOL EditNow, BOOL Overwrite)
	{
		static BYTE parms[] =
			VTS_BSTR VTS_BOOL VTS_BOOL;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FileName, EditNow, Overwrite);
	}

	CString Hyperlink::GetAddress()
	{
		CString result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetAddress(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Hyperlink::GetSubAddress()
	{
		CString result;
		InvokeHelper(0x44d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetSubAddress(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x44d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Hyperlink::GetEmailSubject()
	{
		CString result;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetEmailSubject(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Hyperlink::GetScreenTip()
	{
		CString result;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetScreenTip(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Hyperlink::GetTextToDisplay()
	{
		CString result;
		InvokeHelper(0x3f4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetTextToDisplay(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3f4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString Hyperlink::GetTarget()
	{
		CString result;
		InvokeHelper(0x3f5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Hyperlink::SetTarget(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x3f5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Shapes properties

	/////////////////////////////////////////////////////////////////////////////
	// Shapes operations

	LPDISPATCH Shapes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shapes::GetCreator()
	{
		long result;
		InvokeHelper(0x1f41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shapes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shapes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Shapes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shapes::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Shapes::AddCallout(long Type, float Left, float Top, float Width, float Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Type, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddCurve(VARIANT* SafeArrayOfPoints, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			SafeArrayOfPoints, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddLabel(long Orientation, float Left, float Top, float Width, float Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Orientation, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddLine(float BeginX, float BeginY, float EndX, float EndY, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			BeginX, BeginY, EndX, EndY, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddPicture(LPCTSTR FileName, VARIANT* LinkToFile, VARIANT* SaveWithDocument, VARIANT* Left, VARIANT* Top, VARIANT* Width, VARIANT* Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, LinkToFile, SaveWithDocument, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddPolyline(VARIANT* SafeArrayOfPoints, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			SafeArrayOfPoints, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddShape(long Type, float Left, float Top, float Width, float Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Type, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddTextEffect(long PresetTextEffect, LPCTSTR Text, LPCTSTR FontName, float FontSize, long FontBold, long FontItalic, float Left, float Top, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_BSTR VTS_BSTR VTS_R4 VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			PresetTextEffect, Text, FontName, FontSize, FontBold, FontItalic, Left, Top, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddTextbox(long Orientation, float Left, float Top, float Width, float Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_PVARIANT;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Orientation, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::BuildFreeform(long EditingType, float X1, float Y1)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			EditingType, X1, Y1);
		return result;
	}

	LPDISPATCH Shapes::Range(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void Shapes::SelectAll()
	{
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Shapes::AddOLEObject(VARIANT* ClassType, VARIANT* FileName, VARIANT* LinkToFile, VARIANT* DisplayAsIcon, VARIANT* IconFileName, VARIANT* IconIndex, VARIANT* IconLabel, VARIANT* Left, VARIANT* Top, VARIANT* Width, VARIANT* Height, 
			VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			ClassType, FileName, LinkToFile, DisplayAsIcon, IconFileName, IconIndex, IconLabel, Left, Top, Width, Height, Anchor);
		return result;
	}

	LPDISPATCH Shapes::AddOLEControl(VARIANT* ClassType, VARIANT* Left, VARIANT* Top, VARIANT* Width, VARIANT* Height, VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			ClassType, Left, Top, Width, Height, Anchor);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ShapeRange properties

	/////////////////////////////////////////////////////////////////////////////
	// ShapeRange operations

	LPDISPATCH ShapeRange::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetCreator()
	{
		long result;
		InvokeHelper(0x1f41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN ShapeRange::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetAdjustments()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetAutoShapeType()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetAutoShapeType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH ShapeRange::GetCallout()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetFill()
	{
		LPDISPATCH result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetGroupItems()
	{
		LPDISPATCH result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float ShapeRange::GetHeight()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ShapeRange::GetHorizontalFlip()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float ShapeRange::GetLeft()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH ShapeRange::GetLine()
	{
		LPDISPATCH result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetLockAspectRatio()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetLockAspectRatio(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString ShapeRange::GetName()
	{
		CString result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH ShapeRange::GetNodes()
	{
		LPDISPATCH result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float ShapeRange::GetRotation()
	{
		float result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetRotation(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH ShapeRange::GetPictureFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetShadow()
	{
		LPDISPATCH result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetTextEffect()
	{
		LPDISPATCH result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetTextFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetThreeD()
	{
		LPDISPATCH result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float ShapeRange::GetTop()
	{
		float result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ShapeRange::GetType()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetVerticalFlip()
	{
		long result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT ShapeRange::GetVertices()
	{
		VARIANT result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetVisible()
	{
		long result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float ShapeRange::GetWidth()
	{
		float result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ShapeRange::GetZOrderPosition()
	{
		long result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetHyperlink()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeRange::GetRelativeHorizontalPosition()
	{
		long result;
		InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetRelativeHorizontalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ShapeRange::GetRelativeVerticalPosition()
	{
		long result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetRelativeVerticalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ShapeRange::GetLockAnchor()
	{
		long result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetLockAnchor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH ShapeRange::GetWrapFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::GetAnchor()
	{
		LPDISPATCH result;
		InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void ShapeRange::Align(long Align, long RelativeTo)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Align, RelativeTo);
	}

	void ShapeRange::Apply()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ShapeRange::Delete()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ShapeRange::Distribute(long Distribute, long RelativeTo)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Distribute, RelativeTo);
	}

	LPDISPATCH ShapeRange::Duplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::Flip(long FlipCmd)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FlipCmd);
	}

	void ShapeRange::IncrementLeft(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void ShapeRange::IncrementRotation(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void ShapeRange::IncrementTop(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	LPDISPATCH ShapeRange::Group()
	{
		LPDISPATCH result;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::PickUp()
	{
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH ShapeRange::Regroup()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::ScaleHeight(float Factor, long RelativeToOriginalSize, long Scale)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4 VTS_I4;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Factor, RelativeToOriginalSize, Scale);
	}

	void ShapeRange::ScaleWidth(float Factor, long RelativeToOriginalSize, long Scale)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4 VTS_I4;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Factor, RelativeToOriginalSize, Scale);
	}

	void ShapeRange::Select(VARIANT* Replace)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Replace);
	}

	void ShapeRange::SetShapesDefaultProperties()
	{
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH ShapeRange::Ungroup()
	{
		LPDISPATCH result;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::ZOrder(long ZOrderCmd)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ZOrderCmd);
	}

	LPDISPATCH ShapeRange::ConvertToFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeRange::ConvertToInlineShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::Activate()
	{
		InvokeHelper(0x32, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	CString ShapeRange::GetAlternativeText()
	{
		CString result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void ShapeRange::SetAlternativeText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// GroupShapes properties

	/////////////////////////////////////////////////////////////////////////////
	// GroupShapes operations

	LPDISPATCH GroupShapes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long GroupShapes::GetCreator()
	{
		long result;
		InvokeHelper(0x1f41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH GroupShapes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long GroupShapes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN GroupShapes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH GroupShapes::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Shape properties

	/////////////////////////////////////////////////////////////////////////////
	// Shape operations

	LPDISPATCH Shape::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shape::GetCreator()
	{
		long result;
		InvokeHelper(0x1f41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetAdjustments()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shape::GetAutoShapeType()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetAutoShapeType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Shape::GetCallout()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetFill()
	{
		LPDISPATCH result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetGroupItems()
	{
		LPDISPATCH result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Shape::GetHeight()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Shape::GetHorizontalFlip()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Shape::GetLeft()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Shape::GetLine()
	{
		LPDISPATCH result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shape::GetLockAspectRatio()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetLockAspectRatio(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Shape::GetName()
	{
		CString result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Shape::SetName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Shape::GetNodes()
	{
		LPDISPATCH result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Shape::GetRotation()
	{
		float result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetRotation(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Shape::GetPictureFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetShadow()
	{
		LPDISPATCH result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetTextEffect()
	{
		LPDISPATCH result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetTextFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetThreeD()
	{
		LPDISPATCH result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float Shape::GetTop()
	{
		float result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Shape::GetType()
	{
		long result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Shape::GetVerticalFlip()
	{
		long result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT Shape::GetVertices()
	{
		VARIANT result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	long Shape::GetVisible()
	{
		long result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float Shape::GetWidth()
	{
		float result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Shape::GetZOrderPosition()
	{
		long result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetHyperlink()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Shape::GetRelativeHorizontalPosition()
	{
		long result;
		InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetRelativeHorizontalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shape::GetRelativeVerticalPosition()
	{
		long result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetRelativeVerticalPosition(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Shape::GetLockAnchor()
	{
		long result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Shape::SetLockAnchor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Shape::GetWrapFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetOLEFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetAnchor()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::GetLinkFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Shape::Apply()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Shape::Delete()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Shape::Duplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Shape::Flip(long FlipCmd)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 FlipCmd);
	}

	void Shape::IncrementLeft(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void Shape::IncrementRotation(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void Shape::IncrementTop(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void Shape::PickUp()
	{
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void Shape::ScaleHeight(float Factor, long RelativeToOriginalSize, long Scale)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4 VTS_I4;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Factor, RelativeToOriginalSize, Scale);
	}

	void Shape::ScaleWidth(float Factor, long RelativeToOriginalSize, long Scale)
	{
		static BYTE parms[] =
			VTS_R4 VTS_I4 VTS_I4;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Factor, RelativeToOriginalSize, Scale);
	}

	void Shape::Select(VARIANT* Replace)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Replace);
	}

	void Shape::SetShapesDefaultProperties()
	{
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Shape::Ungroup()
	{
		LPDISPATCH result;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Shape::ZOrder(long ZOrderCmd)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ZOrderCmd);
	}

	LPDISPATCH Shape::ConvertToInlineShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Shape::ConvertToFrame()
	{
		LPDISPATCH result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Shape::Activate()
	{
		InvokeHelper(0x32, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	CString Shape::GetAlternativeText()
	{
		CString result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Shape::SetAlternativeText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	LPDISPATCH Shape::GetScript()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextFrame properties

	/////////////////////////////////////////////////////////////////////////////
	// TextFrame operations

	LPDISPATCH TextFrame::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f40, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextFrame::GetCreator()
	{
		long result;
		InvokeHelper(0x1f41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextFrame::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float TextFrame::GetMarginBottom()
	{
		float result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetMarginBottom(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float TextFrame::GetMarginLeft()
	{
		float result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetMarginLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float TextFrame::GetMarginRight()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetMarginRight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float TextFrame::GetMarginTop()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetMarginTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long TextFrame::GetOrientation()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetOrientation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH TextFrame::GetTextRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextFrame::GetContainingRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextFrame::GetNext()
	{
		LPDISPATCH result;
		InvokeHelper(0x1389, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetNext(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x1389, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH TextFrame::GetPrevious()
	{
		LPDISPATCH result;
		InvokeHelper(0x138a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void TextFrame::SetPrevious(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x138a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL TextFrame::GetOverflowing()
	{
		BOOL result;
		InvokeHelper(0x138b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long TextFrame::GetHasText()
	{
		long result;
		InvokeHelper(0x1390, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextFrame::BreakForwardLink()
	{
		InvokeHelper(0x138c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	BOOL TextFrame::ValidLinkTarget(LPDISPATCH TargetTextFrame)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x138e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			TargetTextFrame);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// _LetterContent properties

	/////////////////////////////////////////////////////////////////////////////
	// _LetterContent operations

	LPDISPATCH _LetterContent::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long _LetterContent::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _LetterContent::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH _LetterContent::GetDuplicate()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString _LetterContent::GetDateFormat()
	{
		CString result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetDateFormat(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _LetterContent::GetIncludeHeaderFooter()
	{
		BOOL result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetIncludeHeaderFooter(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _LetterContent::GetPageDesign()
	{
		CString result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetPageDesign(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _LetterContent::GetLetterStyle()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetLetterStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL _LetterContent::GetLetterhead()
	{
		BOOL result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetLetterhead(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long _LetterContent::GetLetterheadLocation()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetLetterheadLocation(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float _LetterContent::GetLetterheadSize()
	{
		float result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetLetterheadSize(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString _LetterContent::GetRecipientName()
	{
		CString result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetRecipientName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetRecipientAddress()
	{
		CString result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetRecipientAddress(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSalutation()
	{
		CString result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSalutation(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _LetterContent::GetSalutationType()
	{
		long result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSalutationType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString _LetterContent::GetRecipientReference()
	{
		CString result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetRecipientReference(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetMailingInstructions()
	{
		CString result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetMailingInstructions(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetAttentionLine()
	{
		CString result;
		InvokeHelper(0x73, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetAttentionLine(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x73, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSubject()
	{
		CString result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSubject(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x74, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _LetterContent::GetEnclosureNumber()
	{
		long result;
		InvokeHelper(0x75, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetEnclosureNumber(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x75, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString _LetterContent::GetCCList()
	{
		CString result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetCCList(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetReturnAddress()
	{
		CString result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetReturnAddress(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x77, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderName()
	{
		CString result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetClosing()
	{
		CString result;
		InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetClosing(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x79, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderCompany()
	{
		CString result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderCompany(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderJobTitle()
	{
		CString result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderJobTitle(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderInitials()
	{
		CString result;
		InvokeHelper(0x7c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderInitials(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL _LetterContent::GetInfoBlock()
	{
		BOOL result;
		InvokeHelper(0x7d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetInfoBlock(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString _LetterContent::GetRecipientCode()
	{
		CString result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetRecipientCode(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _LetterContent::GetRecipientGender()
	{
		long result;
		InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetRecipientGender(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString _LetterContent::GetReturnAddressShortForm()
	{
		CString result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetReturnAddressShortForm(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderCity()
	{
		CString result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderCity(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString _LetterContent::GetSenderCode()
	{
		CString result;
		InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderCode(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long _LetterContent::GetSenderGender()
	{
		long result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderGender(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString _LetterContent::GetSenderReference()
	{
		CString result;
		InvokeHelper(0x84, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void _LetterContent::SetSenderReference(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// View properties

	/////////////////////////////////////////////////////////////////////////////
	// View operations

	LPDISPATCH View::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long View::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH View::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long View::GetType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL View::GetFullScreen()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetFullScreen(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetDraft()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetDraft(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowAll()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowAll(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowFieldCodes()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowFieldCodes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetMailMergeDataView()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetMailMergeDataView(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetMagnifier()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetMagnifier(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowFirstLineOnly()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowFirstLineOnly(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowFormat()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowFormat(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH View::GetZoom()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL View::GetShowObjectAnchors()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowObjectAnchors(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowTextBoundaries()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowTextBoundaries(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowHighlight()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowHighlight(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowDrawings()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowDrawings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowTabs()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowTabs(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowSpaces()
	{
		BOOL result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowSpaces(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowParagraphs()
	{
		BOOL result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowParagraphs(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowHyphens()
	{
		BOOL result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowHyphens(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowHiddenText()
	{
		BOOL result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowHiddenText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetWrapToWindow()
	{
		BOOL result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetWrapToWindow(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowPicturePlaceHolders()
	{
		BOOL result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowPicturePlaceHolders(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetShowBookmarks()
	{
		BOOL result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowBookmarks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long View::GetFieldShading()
	{
		long result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetFieldShading(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL View::GetShowAnimation()
	{
		BOOL result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowAnimation(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL View::GetTableGridlines()
	{
		BOOL result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetTableGridlines(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long View::GetEnlargeFontsLessThan()
	{
		long result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetEnlargeFontsLessThan(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL View::GetShowMainTextLayer()
	{
		BOOL result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowMainTextLayer(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long View::GetSeekView()
	{
		long result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetSeekView(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long View::GetSplitSpecial()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetSplitSpecial(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long View::GetBrowseToWindow()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void View::SetBrowseToWindow(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL View::GetShowOptionalBreaks()
	{
		BOOL result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void View::SetShowOptionalBreaks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void View::CollapseOutline(VARIANT* Range)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Range);
	}

	void View::ExpandOutline(VARIANT* Range)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Range);
	}

	void View::ShowAllHeadings()
	{
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void View::ShowHeading(long Level)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Level);
	}

	void View::PreviousHeaderFooter()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void View::NextHeaderFooter()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Zoom properties

	/////////////////////////////////////////////////////////////////////////////
	// Zoom operations

	LPDISPATCH Zoom::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Zoom::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Zoom::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Zoom::GetPercentage()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Zoom::SetPercentage(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Zoom::GetPageFit()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Zoom::SetPageFit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Zoom::GetPageRows()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Zoom::SetPageRows(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Zoom::GetPageColumns()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Zoom::SetPageColumns(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Zooms properties

	/////////////////////////////////////////////////////////////////////////////
	// Zooms operations

	LPDISPATCH Zooms::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Zooms::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Zooms::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Zooms::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// InlineShape properties

	/////////////////////////////////////////////////////////////////////////////
	// InlineShape operations

	LPDISPATCH InlineShape::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long InlineShape::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetBorders()
	{
		LPDISPATCH result;
		InvokeHelper(0x44c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetBorders(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x44c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH InlineShape::GetRange()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetLinkFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetField()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetOLEFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long InlineShape::GetType()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetHyperlink()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float InlineShape::GetHeight()
	{
		float result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float InlineShape::GetWidth()
	{
		float result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float InlineShape::GetScaleHeight()
	{
		float result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetScaleHeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float InlineShape::GetScaleWidth()
	{
		float result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetScaleWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long InlineShape::GetLockAspectRatio()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetLockAspectRatio(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH InlineShape::GetLine()
	{
		LPDISPATCH result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetFill()
	{
		LPDISPATCH result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetPictureFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetPictureFormat(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x76, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	void InlineShape::Activate()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void InlineShape::Reset()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void InlineShape::Delete()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void InlineShape::Select()
	{
		InvokeHelper(0xffff, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH InlineShape::ConvertToShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetHorizontalLineFormat()
	{
		LPDISPATCH result;
		InvokeHelper(0x77, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetScript()
	{
		LPDISPATCH result;
		InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShape::GetTextEffect()
	{
		LPDISPATCH result;
		InvokeHelper(0x78, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetTextEffect(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x78, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString InlineShape::GetAlternativeText()
	{
		CString result;
		InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void InlineShape::SetAlternativeText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// InlineShapes properties

	/////////////////////////////////////////////////////////////////////////////
	// InlineShapes operations

	LPDISPATCH InlineShapes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long InlineShapes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShapes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long InlineShapes::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN InlineShapes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH InlineShapes::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH InlineShapes::AddPicture(LPCTSTR FileName, VARIANT* LinkToFile, VARIANT* SaveWithDocument, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, LinkToFile, SaveWithDocument, Range);
		return result;
	}

	LPDISPATCH InlineShapes::AddOLEObject(VARIANT* ClassType, VARIANT* FileName, VARIANT* LinkToFile, VARIANT* DisplayAsIcon, VARIANT* IconFileName, VARIANT* IconIndex, VARIANT* IconLabel, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			ClassType, FileName, LinkToFile, DisplayAsIcon, IconFileName, IconIndex, IconLabel, Range);
		return result;
	}

	LPDISPATCH InlineShapes::AddOLEControl(VARIANT* ClassType, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			ClassType, Range);
		return result;
	}

	LPDISPATCH InlineShapes::New(LPDISPATCH Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	LPDISPATCH InlineShapes::AddHorizontalLine(LPCTSTR FileName, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, Range);
		return result;
	}

	LPDISPATCH InlineShapes::AddHorizontalLineStandard(VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Range);
		return result;
	}

	LPDISPATCH InlineShapes::AddPictureBullet(LPCTSTR FileName, VARIANT* Range)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName, Range);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// SpellingSuggestions properties

	/////////////////////////////////////////////////////////////////////////////
	// SpellingSuggestions operations

	LPDISPATCH SpellingSuggestions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long SpellingSuggestions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH SpellingSuggestions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN SpellingSuggestions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long SpellingSuggestions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long SpellingSuggestions::GetSpellingErrorType()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH SpellingSuggestions::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// SpellingSuggestion properties

	/////////////////////////////////////////////////////////////////////////////
	// SpellingSuggestion operations

	LPDISPATCH SpellingSuggestion::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long SpellingSuggestion::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH SpellingSuggestion::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString SpellingSuggestion::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Dictionaries properties

	/////////////////////////////////////////////////////////////////////////////
	// Dictionaries operations

	LPDISPATCH Dictionaries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Dictionaries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dictionaries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Dictionaries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Dictionaries::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Dictionaries::GetMaximum()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dictionaries::GetActiveCustomDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void Dictionaries::SetActiveCustomDictionary(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH Dictionaries::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH Dictionaries::Add(LPCTSTR FileName)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName);
		return result;
	}

	void Dictionaries::ClearAll()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// HangulHanjaConversionDictionaries properties

	/////////////////////////////////////////////////////////////////////////////
	// HangulHanjaConversionDictionaries operations

	LPDISPATCH HangulHanjaConversionDictionaries::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HangulHanjaConversionDictionaries::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulHanjaConversionDictionaries::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN HangulHanjaConversionDictionaries::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long HangulHanjaConversionDictionaries::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long HangulHanjaConversionDictionaries::GetMaximum()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulHanjaConversionDictionaries::GetActiveCustomDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void HangulHanjaConversionDictionaries::SetActiveCustomDictionary(LPDISPATCH newValue)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH HangulHanjaConversionDictionaries::GetBuiltinDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulHanjaConversionDictionaries::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH HangulHanjaConversionDictionaries::Add(LPCTSTR FileName)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			FileName);
		return result;
	}

	void HangulHanjaConversionDictionaries::ClearAll()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Dictionary properties

	/////////////////////////////////////////////////////////////////////////////
	// Dictionary operations

	LPDISPATCH Dictionary::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Dictionary::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Dictionary::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Dictionary::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString Dictionary::GetPath()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long Dictionary::GetLanguageID()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Dictionary::SetLanguageID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Dictionary::GetReadOnly()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	long Dictionary::GetType()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	BOOL Dictionary::GetLanguageSpecific()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Dictionary::SetLanguageSpecific(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	void Dictionary::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ReadabilityStatistics properties

	/////////////////////////////////////////////////////////////////////////////
	// ReadabilityStatistics operations

	LPDISPATCH ReadabilityStatistics::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ReadabilityStatistics::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ReadabilityStatistics::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN ReadabilityStatistics::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ReadabilityStatistics::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ReadabilityStatistics::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ReadabilityStatistic properties

	/////////////////////////////////////////////////////////////////////////////
	// ReadabilityStatistic operations

	LPDISPATCH ReadabilityStatistic::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ReadabilityStatistic::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ReadabilityStatistic::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString ReadabilityStatistic::GetName()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	float ReadabilityStatistic::GetValue()
	{
		float result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Versions properties

	/////////////////////////////////////////////////////////////////////////////
	// Versions operations

	LPDISPATCH Versions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Versions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Versions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Versions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long Versions::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Versions::GetAutoVersion()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Versions::SetAutoVersion(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH Versions::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void Versions::Save(VARIANT* Comment)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Comment);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Version properties

	/////////////////////////////////////////////////////////////////////////////
	// Version operations

	LPDISPATCH Version::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Version::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Version::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString Version::GetSavedBy()
	{
		CString result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	CString Version::GetComment()
	{
		CString result;
		InvokeHelper(0x3ec, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	DATE Version::GetDate()
	{
		DATE result;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}

	long Version::GetIndex()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Version::Delete()
	{
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	LPDISPATCH Version::Open()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Options properties

	/////////////////////////////////////////////////////////////////////////////
	// Options operations

	LPDISPATCH Options::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Options::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Options::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL Options::GetAllowAccentedUppercase()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowAccentedUppercase(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetWPHelp()
	{
		BOOL result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetWPHelp(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetWPDocNavKeys()
	{
		BOOL result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetWPDocNavKeys(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPagination()
	{
		BOOL result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPagination(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetBlueScreen()
	{
		BOOL result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetBlueScreen(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetEnableSound()
	{
		BOOL result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetEnableSound(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetConfirmConversions()
	{
		BOOL result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetConfirmConversions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x16, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetUpdateLinksAtOpen()
	{
		BOOL result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUpdateLinksAtOpen(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSendMailAttach()
	{
		BOOL result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSendMailAttach(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetMeasurementUnit()
	{
		long result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetMeasurementUnit(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetButtonFieldClicks()
	{
		long result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetButtonFieldClicks(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetShortMenuNames()
	{
		BOOL result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetShortMenuNames(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetRTFInClipboard()
	{
		BOOL result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetRTFInClipboard(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetUpdateFieldsAtPrint()
	{
		BOOL result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUpdateFieldsAtPrint(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintProperties()
	{
		BOOL result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintProperties(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintFieldCodes()
	{
		BOOL result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintFieldCodes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x20, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintComments()
	{
		BOOL result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintComments(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintHiddenText()
	{
		BOOL result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintHiddenText(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetEnvelopeFeederInstalled()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	BOOL Options::GetUpdateLinksAtPrint()
	{
		BOOL result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUpdateLinksAtPrint(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintBackground()
	{
		BOOL result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintBackground(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintDrawingObjects()
	{
		BOOL result;
		InvokeHelper(0x26, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintDrawingObjects(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x26, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString Options::GetDefaultTray()
	{
		CString result;
		InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultTray(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x27, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	long Options::GetDefaultTrayID()
	{
		long result;
		InvokeHelper(0x28, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultTrayID(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x28, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetCreateBackup()
	{
		BOOL result;
		InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetCreateBackup(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAllowFastSave()
	{
		BOOL result;
		InvokeHelper(0x2a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowFastSave(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSavePropertiesPrompt()
	{
		BOOL result;
		InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSavePropertiesPrompt(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSaveNormalPrompt()
	{
		BOOL result;
		InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSaveNormalPrompt(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetSaveInterval()
	{
		long result;
		InvokeHelper(0x2d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetSaveInterval(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetBackgroundSave()
	{
		BOOL result;
		InvokeHelper(0x2e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetBackgroundSave(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x2e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetInsertedTextMark()
	{
		long result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetInsertedTextMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x39, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetDeletedTextMark()
	{
		long result;
		InvokeHelper(0x3a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDeletedTextMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetRevisedLinesMark()
	{
		long result;
		InvokeHelper(0x3b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetRevisedLinesMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetInsertedTextColor()
	{
		long result;
		InvokeHelper(0x3c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetInsertedTextColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetDeletedTextColor()
	{
		long result;
		InvokeHelper(0x3d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDeletedTextColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetRevisedLinesColor()
	{
		long result;
		InvokeHelper(0x3e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetRevisedLinesColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString Options::GetDefaultFilePath(long Path)
	{
		CString result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
			Path);
		return result;
	}

	void Options::SetDefaultFilePath(long Path, LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_I4 VTS_BSTR;
		InvokeHelper(0x41, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 Path, lpszNewValue);
	}

	BOOL Options::GetOvertype()
	{
		BOOL result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetOvertype(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetReplaceSelection()
	{
		BOOL result;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetReplaceSelection(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAllowDragAndDrop()
	{
		BOOL result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowDragAndDrop(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoWordSelection()
	{
		BOOL result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoWordSelection(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetINSKeyForPaste()
	{
		BOOL result;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetINSKeyForPaste(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSmartCutPaste()
	{
		BOOL result;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSmartCutPaste(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x47, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetTabIndentKey()
	{
		BOOL result;
		InvokeHelper(0x48, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetTabIndentKey(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x48, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString Options::GetPictureEditor()
	{
		CString result;
		InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Options::SetPictureEditor(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL Options::GetAnimateScreenMovements()
	{
		BOOL result;
		InvokeHelper(0x4a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAnimateScreenMovements(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetRevisedPropertiesMark()
	{
		long result;
		InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetRevisedPropertiesMark(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetRevisedPropertiesColor()
	{
		long result;
		InvokeHelper(0x4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetRevisedPropertiesColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetSnapToGrid()
	{
		BOOL result;
		InvokeHelper(0x4f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSnapToGrid(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSnapToShapes()
	{
		BOOL result;
		InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSnapToShapes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	float Options::GetGridDistanceHorizontal()
	{
		float result;
		InvokeHelper(0x51, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Options::SetGridDistanceHorizontal(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x51, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Options::GetGridDistanceVertical()
	{
		float result;
		InvokeHelper(0x52, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Options::SetGridDistanceVertical(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x52, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Options::GetGridOriginHorizontal()
	{
		float result;
		InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Options::SetGridOriginHorizontal(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float Options::GetGridOriginVertical()
	{
		float result;
		InvokeHelper(0x54, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Options::SetGridOriginVertical(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x54, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL Options::GetInlineConversion()
	{
		BOOL result;
		InvokeHelper(0x56, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetInlineConversion(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x56, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetIMEAutomaticControl()
	{
		BOOL result;
		InvokeHelper(0x57, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetIMEAutomaticControl(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x57, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatApplyHeadings()
	{
		BOOL result;
		InvokeHelper(0xfa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatApplyHeadings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xfa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatApplyLists()
	{
		BOOL result;
		InvokeHelper(0xfb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatApplyLists(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xfb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatApplyBulletedLists()
	{
		BOOL result;
		InvokeHelper(0xfc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatApplyBulletedLists(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xfc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatApplyOtherParas()
	{
		BOOL result;
		InvokeHelper(0xfd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatApplyOtherParas(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xfd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceQuotes()
	{
		BOOL result;
		InvokeHelper(0xfe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceQuotes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xfe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceSymbols()
	{
		BOOL result;
		InvokeHelper(0xff, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceSymbols(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xff, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceOrdinals()
	{
		BOOL result;
		InvokeHelper(0x100, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceOrdinals(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceFractions()
	{
		BOOL result;
		InvokeHelper(0x101, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceFractions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x101, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplacePlainTextEmphasis()
	{
		BOOL result;
		InvokeHelper(0x102, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplacePlainTextEmphasis(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x102, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatPreserveStyles()
	{
		BOOL result;
		InvokeHelper(0x103, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatPreserveStyles(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x103, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyHeadings()
	{
		BOOL result;
		InvokeHelper(0x104, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyHeadings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyBorders()
	{
		BOOL result;
		InvokeHelper(0x105, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyBorders(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyBulletedLists()
	{
		BOOL result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyBulletedLists(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x106, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyNumberedLists()
	{
		BOOL result;
		InvokeHelper(0x107, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyNumberedLists(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x107, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceQuotes()
	{
		BOOL result;
		InvokeHelper(0x108, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceQuotes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x108, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceSymbols()
	{
		BOOL result;
		InvokeHelper(0x109, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceSymbols(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x109, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceOrdinals()
	{
		BOOL result;
		InvokeHelper(0x10a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceOrdinals(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceFractions()
	{
		BOOL result;
		InvokeHelper(0x10b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceFractions(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplacePlainTextEmphasis()
	{
		BOOL result;
		InvokeHelper(0x10c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplacePlainTextEmphasis(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeFormatListItemBeginning()
	{
		BOOL result;
		InvokeHelper(0x10d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeFormatListItemBeginning(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeDefineStyles()
	{
		BOOL result;
		InvokeHelper(0x10e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeDefineStyles(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatPlainTextWordMail()
	{
		BOOL result;
		InvokeHelper(0x10f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatPlainTextWordMail(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x10f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceHyperlinks()
	{
		BOOL result;
		InvokeHelper(0x110, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceHyperlinks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x110, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceHyperlinks()
	{
		BOOL result;
		InvokeHelper(0x111, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceHyperlinks(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x111, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDefaultHighlightColorIndex()
	{
		long result;
		InvokeHelper(0x112, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultHighlightColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x112, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetDefaultBorderLineStyle()
	{
		long result;
		InvokeHelper(0x113, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultBorderLineStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x113, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetCheckSpellingAsYouType()
	{
		BOOL result;
		InvokeHelper(0x114, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetCheckSpellingAsYouType(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x114, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetCheckGrammarAsYouType()
	{
		BOOL result;
		InvokeHelper(0x115, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetCheckGrammarAsYouType(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x115, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetIgnoreInternetAndFileAddresses()
	{
		BOOL result;
		InvokeHelper(0x116, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetIgnoreInternetAndFileAddresses(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x116, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetShowReadabilityStatistics()
	{
		BOOL result;
		InvokeHelper(0x117, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetShowReadabilityStatistics(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x117, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetIgnoreUppercase()
	{
		BOOL result;
		InvokeHelper(0x118, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetIgnoreUppercase(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x118, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetIgnoreMixedDigits()
	{
		BOOL result;
		InvokeHelper(0x119, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetIgnoreMixedDigits(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x119, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSuggestFromMainDictionaryOnly()
	{
		BOOL result;
		InvokeHelper(0x11a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSuggestFromMainDictionaryOnly(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetSuggestSpellingCorrections()
	{
		BOOL result;
		InvokeHelper(0x11b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetSuggestSpellingCorrections(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDefaultBorderLineWidth()
	{
		long result;
		InvokeHelper(0x11c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultBorderLineWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x11c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetCheckGrammarWithSpelling()
	{
		BOOL result;
		InvokeHelper(0x11d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetCheckGrammarWithSpelling(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDefaultOpenFormat()
	{
		long result;
		InvokeHelper(0x11e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultOpenFormat(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x11e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetPrintDraft()
	{
		BOOL result;
		InvokeHelper(0x11f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintDraft(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x11f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintReverse()
	{
		BOOL result;
		InvokeHelper(0x120, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintReverse(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x120, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMapPaperSize()
	{
		BOOL result;
		InvokeHelper(0x121, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMapPaperSize(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x121, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyTables()
	{
		BOOL result;
		InvokeHelper(0x122, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyTables(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x122, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatApplyFirstIndents()
	{
		BOOL result;
		InvokeHelper(0x123, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatApplyFirstIndents(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x123, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatMatchParentheses()
	{
		BOOL result;
		InvokeHelper(0x126, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatMatchParentheses(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x126, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatReplaceFarEastDashes()
	{
		BOOL result;
		InvokeHelper(0x127, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatReplaceFarEastDashes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x127, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatDeleteAutoSpaces()
	{
		BOOL result;
		InvokeHelper(0x128, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatDeleteAutoSpaces(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x128, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyFirstIndents()
	{
		BOOL result;
		InvokeHelper(0x129, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyFirstIndents(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x129, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyDates()
	{
		BOOL result;
		InvokeHelper(0x12a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyDates(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeApplyClosings()
	{
		BOOL result;
		InvokeHelper(0x12b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeApplyClosings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeMatchParentheses()
	{
		BOOL result;
		InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeMatchParentheses(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeReplaceFarEastDashes()
	{
		BOOL result;
		InvokeHelper(0x12d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeReplaceFarEastDashes(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeDeleteAutoSpaces()
	{
		BOOL result;
		InvokeHelper(0x12e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeDeleteAutoSpaces(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeInsertClosings()
	{
		BOOL result;
		InvokeHelper(0x12f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeInsertClosings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x12f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeAutoLetterWizard()
	{
		BOOL result;
		InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeAutoLetterWizard(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoFormatAsYouTypeInsertOvers()
	{
		BOOL result;
		InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoFormatAsYouTypeInsertOvers(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x131, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetDisplayGridLines()
	{
		BOOL result;
		InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetDisplayGridLines(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x132, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyCase()
	{
		BOOL result;
		InvokeHelper(0x135, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyCase(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x135, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyByte()
	{
		BOOL result;
		InvokeHelper(0x136, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyByte(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x136, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyHiragana()
	{
		BOOL result;
		InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyHiragana(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x137, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzySmallKana()
	{
		BOOL result;
		InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzySmallKana(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyDash()
	{
		BOOL result;
		InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyDash(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyIterationMark()
	{
		BOOL result;
		InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyIterationMark(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyKanji()
	{
		BOOL result;
		InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyKanji(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyOldKana()
	{
		BOOL result;
		InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyOldKana(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyProlongedSoundMark()
	{
		BOOL result;
		InvokeHelper(0x13d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyProlongedSoundMark(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyDZ()
	{
		BOOL result;
		InvokeHelper(0x13e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyDZ(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyBV()
	{
		BOOL result;
		InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyBV(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x13f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyTC()
	{
		BOOL result;
		InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyTC(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x140, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyHF()
	{
		BOOL result;
		InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyHF(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x141, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyZJ()
	{
		BOOL result;
		InvokeHelper(0x142, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyZJ(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x142, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyAY()
	{
		BOOL result;
		InvokeHelper(0x143, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyAY(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x143, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyKiKu()
	{
		BOOL result;
		InvokeHelper(0x144, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyKiKu(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x144, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzyPunctuation()
	{
		BOOL result;
		InvokeHelper(0x145, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzyPunctuation(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x145, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetMatchFuzzySpace()
	{
		BOOL result;
		InvokeHelper(0x146, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetMatchFuzzySpace(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x146, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetApplyFarEastFontsToAscii()
	{
		BOOL result;
		InvokeHelper(0x147, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetApplyFarEastFontsToAscii(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x147, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetConvertHighAnsiToFarEast()
	{
		BOOL result;
		InvokeHelper(0x148, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetConvertHighAnsiToFarEast(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x148, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintOddPagesInAscendingOrder()
	{
		BOOL result;
		InvokeHelper(0x14a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintOddPagesInAscendingOrder(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetPrintEvenPagesInAscendingOrder()
	{
		BOOL result;
		InvokeHelper(0x14b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetPrintEvenPagesInAscendingOrder(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x14b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDefaultBorderColorIndex()
	{
		long result;
		InvokeHelper(0x151, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultBorderColorIndex(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x151, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetEnableMisusedWordsDictionary()
	{
		BOOL result;
		InvokeHelper(0x152, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetEnableMisusedWordsDictionary(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x152, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAllowCombinedAuxiliaryForms()
	{
		BOOL result;
		InvokeHelper(0x153, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowCombinedAuxiliaryForms(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x153, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetHangulHanjaFastConversion()
	{
		BOOL result;
		InvokeHelper(0x154, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetHangulHanjaFastConversion(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x154, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetCheckHangulEndings()
	{
		BOOL result;
		InvokeHelper(0x155, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetCheckHangulEndings(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x155, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetEnableHangulHanjaRecentOrdering()
	{
		BOOL result;
		InvokeHelper(0x156, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetEnableHangulHanjaRecentOrdering(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x156, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetMultipleWordConversionsMode()
	{
		long result;
		InvokeHelper(0x157, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetMultipleWordConversionsMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x157, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void Options::SetWPHelpOptions(VARIANT* CommandKeyHelp, VARIANT* DocNavigationKeys, VARIANT* MouseSimulation, VARIANT* DemoGuidance, VARIANT* DemoSpeed, VARIANT* HelpType)
	{
		static BYTE parms[] =
			VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 CommandKeyHelp, DocNavigationKeys, MouseSimulation, DemoGuidance, DemoSpeed, HelpType);
	}

	long Options::GetDefaultBorderColor()
	{
		long result;
		InvokeHelper(0x158, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDefaultBorderColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x158, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetAllowPixelUnits()
	{
		BOOL result;
		InvokeHelper(0x159, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowPixelUnits(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x159, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetUseCharacterUnit()
	{
		BOOL result;
		InvokeHelper(0x15a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUseCharacterUnit(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x15a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAllowCompoundNounProcessing()
	{
		BOOL result;
		InvokeHelper(0x15b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowCompoundNounProcessing(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x15b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAutoKeyboardSwitching()
	{
		BOOL result;
		InvokeHelper(0x18f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAutoKeyboardSwitching(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x18f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDocumentViewDirection()
	{
		long result;
		InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDocumentViewDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x190, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetArabicNumeral()
	{
		long result;
		InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetArabicNumeral(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x191, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetMonthNames()
	{
		long result;
		InvokeHelper(0x192, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetMonthNames(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x192, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetCursorMovement()
	{
		long result;
		InvokeHelper(0x193, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetCursorMovement(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x193, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetVisualSelection()
	{
		long result;
		InvokeHelper(0x194, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetVisualSelection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x194, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetShowDiacritics()
	{
		BOOL result;
		InvokeHelper(0x195, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetShowDiacritics(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x195, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetShowControlCharacters()
	{
		BOOL result;
		InvokeHelper(0x196, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetShowControlCharacters(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x196, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAddControlCharacters()
	{
		BOOL result;
		InvokeHelper(0x197, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAddControlCharacters(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x197, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetAddBiDirectionalMarksWhenSavingTextFile()
	{
		BOOL result;
		InvokeHelper(0x198, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAddBiDirectionalMarksWhenSavingTextFile(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x198, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetStrictInitialAlefHamza()
	{
		BOOL result;
		InvokeHelper(0x199, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetStrictInitialAlefHamza(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x199, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetStrictFinalYaa()
	{
		BOOL result;
		InvokeHelper(0x19a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetStrictFinalYaa(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetHebrewMode()
	{
		long result;
		InvokeHelper(0x19b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetHebrewMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x19b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Options::GetArabicMode()
	{
		long result;
		InvokeHelper(0x19c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetArabicMode(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x19c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetAllowClickAndTypeMouse()
	{
		BOOL result;
		InvokeHelper(0x19d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAllowClickAndTypeMouse(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetUseGermanSpellingReform()
	{
		BOOL result;
		InvokeHelper(0x19f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUseGermanSpellingReform(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x19f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetInterpretHighAnsi()
	{
		long result;
		InvokeHelper(0x1a2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetInterpretHighAnsi(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1a2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetAddHebDoubleQuote()
	{
		BOOL result;
		InvokeHelper(0x1a3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetAddHebDoubleQuote(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1a3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL Options::GetUseDiffDiacColor()
	{
		BOOL result;
		InvokeHelper(0x1a4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetUseDiffDiacColor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1a4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long Options::GetDiacriticColorVal()
	{
		long result;
		InvokeHelper(0x1a5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Options::SetDiacriticColorVal(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1a5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Options::GetOptimizeForWord97byDefault()
	{
		BOOL result;
		InvokeHelper(0x1a7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Options::SetOptimizeForWord97byDefault(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1a7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// MailMessage properties

	/////////////////////////////////////////////////////////////////////////////
	// MailMessage operations

	LPDISPATCH MailMessage::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long MailMessage::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH MailMessage::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void MailMessage::CheckName()
	{
		InvokeHelper(0x14e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::Delete()
	{
		InvokeHelper(0x14f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::DisplayMoveDialog()
	{
		InvokeHelper(0x150, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::DisplayProperties()
	{
		InvokeHelper(0x151, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::DisplaySelectNamesDialog()
	{
		InvokeHelper(0x152, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::Forward()
	{
		InvokeHelper(0x153, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::GoToNext()
	{
		InvokeHelper(0x154, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::GoToPrevious()
	{
		InvokeHelper(0x155, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::Reply()
	{
		InvokeHelper(0x156, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::ReplyAll()
	{
		InvokeHelper(0x157, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void MailMessage::ToggleHeader()
	{
		InvokeHelper(0x158, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ProofreadingErrors properties

	/////////////////////////////////////////////////////////////////////////////
	// ProofreadingErrors operations

	LPDISPATCH ProofreadingErrors::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ProofreadingErrors::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ProofreadingErrors::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN ProofreadingErrors::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long ProofreadingErrors::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long ProofreadingErrors::GetType()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ProofreadingErrors::Item(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// Mailer properties

	/////////////////////////////////////////////////////////////////////////////
	// Mailer operations

	LPDISPATCH Mailer::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Mailer::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Mailer::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	VARIANT Mailer::GetBCCRecipients()
	{
		VARIANT result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Mailer::SetBCCRecipients(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Mailer::GetCCRecipients()
	{
		VARIANT result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Mailer::SetCCRecipients(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Mailer::GetRecipients()
	{
		VARIANT result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Mailer::SetRecipients(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	VARIANT Mailer::GetEnclosures()
	{
		VARIANT result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	void Mailer::SetEnclosures(VARIANT* newValue)
	{
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	CString Mailer::GetSender()
	{
		CString result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	DATE Mailer::GetSendDateTime()
	{
		DATE result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}

	BOOL Mailer::GetReceived()
	{
		BOOL result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	CString Mailer::GetSubject()
	{
		CString result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Mailer::SetSubject(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// WrapFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// WrapFormat operations

	LPDISPATCH WrapFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long WrapFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH WrapFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long WrapFormat::GetType()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long WrapFormat::GetSide()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetSide(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float WrapFormat::GetDistanceTop()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetDistanceTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float WrapFormat::GetDistanceBottom()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetDistanceBottom(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float WrapFormat::GetDistanceLeft()
	{
		float result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetDistanceLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float WrapFormat::GetDistanceRight()
	{
		float result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetDistanceRight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long WrapFormat::GetAllowOverlap()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WrapFormat::SetAllowOverlap(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// HangulAndAlphabetExceptions properties

	/////////////////////////////////////////////////////////////////////////////
	// HangulAndAlphabetExceptions operations

	LPDISPATCH HangulAndAlphabetExceptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HangulAndAlphabetExceptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulAndAlphabetExceptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN HangulAndAlphabetExceptions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long HangulAndAlphabetExceptions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulAndAlphabetExceptions::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH HangulAndAlphabetExceptions::Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// HangulAndAlphabetException properties

	/////////////////////////////////////////////////////////////////////////////
	// HangulAndAlphabetException operations

	LPDISPATCH HangulAndAlphabetException::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HangulAndAlphabetException::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HangulAndAlphabetException::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HangulAndAlphabetException::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString HangulAndAlphabetException::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void HangulAndAlphabetException::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Adjustments properties

	/////////////////////////////////////////////////////////////////////////////
	// Adjustments operations

	LPDISPATCH Adjustments::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Adjustments::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Adjustments::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Adjustments::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float Adjustments::GetItem(long Index)
	{
		float result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, parms,
			Index);
		return result;
	}

	void Adjustments::SetItem(long Index, float newValue)
	{
		static BYTE parms[] =
			VTS_I4 VTS_R4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 Index, newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// CalloutFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// CalloutFormat operations

	LPDISPATCH CalloutFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CalloutFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH CalloutFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long CalloutFormat::GetAccent()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetAccent(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CalloutFormat::GetAngle()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetAngle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CalloutFormat::GetAutoAttach()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetAutoAttach(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long CalloutFormat::GetAutoLength()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long CalloutFormat::GetBorder()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetBorder(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float CalloutFormat::GetDrop()
	{
		float result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	long CalloutFormat::GetDropType()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float CalloutFormat::GetGap()
	{
		float result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetGap(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float CalloutFormat::GetLength()
	{
		float result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	long CalloutFormat::GetType()
	{
		long result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void CalloutFormat::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void CalloutFormat::AutomaticLength()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void CalloutFormat::CustomDrop(float Drop)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Drop);
	}

	void CalloutFormat::CustomLength(float Length)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Length);
	}

	void CalloutFormat::PresetDrop(long DropType)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 DropType);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ColorFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// ColorFormat operations

	LPDISPATCH ColorFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ColorFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ColorFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ColorFormat::GetRgb()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ColorFormat::SetRgb(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ColorFormat::GetType()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ConnectorFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// ConnectorFormat operations

	LPDISPATCH ConnectorFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetBeginConnected()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ConnectorFormat::GetBeginConnectedShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetBeginConnectionSite()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetEndConnected()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ConnectorFormat::GetEndConnectedShape()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetEndConnectionSite()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ConnectorFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ConnectorFormat::GetType()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ConnectorFormat::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void ConnectorFormat::BeginConnect(LPDISPATCH* ConnectedShape, long ConnectionSite)
	{
		static BYTE parms[] =
			VTS_PDISPATCH VTS_I4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ConnectedShape, ConnectionSite);
	}

	void ConnectorFormat::BeginDisconnect()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ConnectorFormat::EndConnect(LPDISPATCH* ConnectedShape, long ConnectionSite)
	{
		static BYTE parms[] =
			VTS_PDISPATCH VTS_I4;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 ConnectedShape, ConnectionSite);
	}

	void ConnectorFormat::EndDisconnect()
	{
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// FillFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// FillFormat operations

	LPDISPATCH FillFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FillFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FillFormat::GetBackColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FillFormat::GetForeColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetGradientColorType()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float FillFormat::GetGradientDegree()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetGradientStyle()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetGradientVariant()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetPattern()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetPresetGradientType()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetPresetTexture()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString FillFormat::GetTextureName()
	{
		CString result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetTextureType()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float FillFormat::GetTransparency()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void FillFormat::SetTransparency(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long FillFormat::GetType()
	{
		long result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long FillFormat::GetVisible()
	{
		long result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void FillFormat::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void FillFormat::OneColorGradient(long Style, long Variant, float Degree)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_R4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Style, Variant, Degree);
	}

	void FillFormat::Patterned(long Pattern)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Pattern);
	}

	void FillFormat::PresetGradient(long Style, long Variant, long PresetGradientType)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Style, Variant, PresetGradientType);
	}

	void FillFormat::PresetTextured(long PresetTexture)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 PresetTexture);
	}

	void FillFormat::Solid()
	{
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void FillFormat::TwoColorGradient(long Style, long Variant)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Style, Variant);
	}

	void FillFormat::UserPicture(LPCTSTR PictureFile)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 PictureFile);
	}

	void FillFormat::UserTextured(LPCTSTR TextureFile)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 TextureFile);
	}


	/////////////////////////////////////////////////////////////////////////////
	// FreeformBuilder properties

	/////////////////////////////////////////////////////////////////////////////
	// FreeformBuilder operations

	LPDISPATCH FreeformBuilder::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long FreeformBuilder::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH FreeformBuilder::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	void FreeformBuilder::AddNodes(long SegmentType, long EditingType, float X1, float Y1, float X2, float Y2, float X3, float Y3)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 SegmentType, EditingType, X1, Y1, X2, Y2, X3, Y3);
	}

	LPDISPATCH FreeformBuilder::ConvertToShape(VARIANT* Anchor)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Anchor);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// LineFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// LineFormat operations

	LPDISPATCH LineFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LineFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH LineFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH LineFormat::GetBackColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LineFormat::GetBeginArrowheadLength()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetBeginArrowheadLength(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetBeginArrowheadStyle()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetBeginArrowheadStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetBeginArrowheadWidth()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetBeginArrowheadWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetDashStyle()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetDashStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetEndArrowheadLength()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetEndArrowheadLength(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetEndArrowheadStyle()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetEndArrowheadStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetEndArrowheadWidth()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetEndArrowheadWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	LPDISPATCH LineFormat::GetForeColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long LineFormat::GetPattern()
	{
		long result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetPattern(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long LineFormat::GetStyle()
	{
		long result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetStyle(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float LineFormat::GetTransparency()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetTransparency(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long LineFormat::GetVisible()
	{
		long result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x70, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float LineFormat::GetWeight()
	{
		float result;
		InvokeHelper(0x71, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void LineFormat::SetWeight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x71, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// PictureFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// PictureFormat operations

	LPDISPATCH PictureFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long PictureFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH PictureFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float PictureFormat::GetBrightness()
	{
		float result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetBrightness(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long PictureFormat::GetColorType()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetColorType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float PictureFormat::GetContrast()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetContrast(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PictureFormat::GetCropBottom()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetCropBottom(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PictureFormat::GetCropLeft()
	{
		float result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetCropLeft(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PictureFormat::GetCropRight()
	{
		float result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetCropRight(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float PictureFormat::GetCropTop()
	{
		float result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetCropTop(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long PictureFormat::GetTransparencyColor()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetTransparencyColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long PictureFormat::GetTransparentBackground()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void PictureFormat::SetTransparentBackground(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void PictureFormat::IncrementBrightness(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void PictureFormat::IncrementContrast(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ShadowFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// ShadowFormat operations

	LPDISPATCH ShadowFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShadowFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShadowFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShadowFormat::GetForeColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShadowFormat::GetObscured()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetObscured(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	float ShadowFormat::GetOffsetX()
	{
		float result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetOffsetX(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float ShadowFormat::GetOffsetY()
	{
		float result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetOffsetY(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float ShadowFormat::GetTransparency()
	{
		float result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetTransparency(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ShadowFormat::GetType()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ShadowFormat::GetVisible()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ShadowFormat::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void ShadowFormat::IncrementOffsetX(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void ShadowFormat::IncrementOffsetY(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ShapeNode properties

	/////////////////////////////////////////////////////////////////////////////
	// ShapeNode operations

	LPDISPATCH ShapeNode::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeNode::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeNode::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeNode::GetEditingType()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	VARIANT ShapeNode::GetPoints()
	{
		VARIANT result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	long ShapeNode::GetSegmentType()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// ShapeNodes properties

	/////////////////////////////////////////////////////////////////////////////
	// ShapeNodes operations

	LPDISPATCH ShapeNodes::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeNodes::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ShapeNodes::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ShapeNodes::GetCount()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN ShapeNodes::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	void ShapeNodes::Delete(long Index)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index);
	}

	LPDISPATCH ShapeNodes::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	void ShapeNodes::SetEditingType(long Index, long EditingType)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index, EditingType);
	}

	void ShapeNodes::SetPosition(long Index, float X1, float Y1)
	{
		static BYTE parms[] =
			VTS_I4 VTS_R4 VTS_R4;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index, X1, Y1);
	}

	void ShapeNodes::SetSegmentType(long Index, long SegmentType)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index, SegmentType);
	}

	void ShapeNodes::Insert(long Index, long SegmentType, long EditingType, float X1, float Y1, float X2, float Y2, float X3, float Y3)
	{
		static BYTE parms[] =
			VTS_I4 VTS_I4 VTS_I4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4 VTS_R4;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Index, SegmentType, EditingType, X1, Y1, X2, Y2, X3, Y3);
	}


	/////////////////////////////////////////////////////////////////////////////
	// TextEffectFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// TextEffectFormat operations

	LPDISPATCH TextEffectFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextEffectFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH TextEffectFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long TextEffectFormat::GetAlignment()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetFontBold()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetFontBold(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x65, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetFontItalic()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetFontItalic(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString TextEffectFormat::GetFontName()
	{
		CString result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetFontName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	float TextEffectFormat::GetFontSize()
	{
		float result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetFontSize(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long TextEffectFormat::GetKernedPairs()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetKernedPairs(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetNormalizedHeight()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetNormalizedHeight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetPresetShape()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetPresetShape(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetPresetTextEffect()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetPresetTextEffect(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long TextEffectFormat::GetRotatedChars()
	{
		long result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetRotatedChars(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString TextEffectFormat::GetText()
	{
		CString result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetText(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	float TextEffectFormat::GetTracking()
	{
		float result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void TextEffectFormat::SetTracking(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	void TextEffectFormat::ToggleVerticalText()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ThreeDFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// ThreeDFormat operations

	LPDISPATCH ThreeDFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ThreeDFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH ThreeDFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float ThreeDFormat::GetDepth()
	{
		float result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetDepth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	LPDISPATCH ThreeDFormat::GetExtrusionColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long ThreeDFormat::GetExtrusionColorType()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetExtrusionColorType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ThreeDFormat::GetPerspective()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetPerspective(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ThreeDFormat::GetPresetExtrusionDirection()
	{
		long result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long ThreeDFormat::GetPresetLightingDirection()
	{
		long result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetPresetLightingDirection(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x69, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ThreeDFormat::GetPresetLightingSoftness()
	{
		long result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetPresetLightingSoftness(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ThreeDFormat::GetPresetMaterial()
	{
		long result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetPresetMaterial(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long ThreeDFormat::GetPresetThreeDFormat()
	{
		long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	float ThreeDFormat::GetRotationX()
	{
		float result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetRotationX(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	float ThreeDFormat::GetRotationY()
	{
		float result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetRotationY(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x6e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long ThreeDFormat::GetVisible()
	{
		long result;
		InvokeHelper(0x6f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void ThreeDFormat::SetVisible(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	void ThreeDFormat::IncrementRotationX(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void ThreeDFormat::IncrementRotationY(float Increment)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Increment);
	}

	void ThreeDFormat::ResetRotation()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ThreeDFormat::SetExtrusionDirection(long PresetExtrusionDirection)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 PresetExtrusionDirection);
	}

	void ThreeDFormat::SetThreeDFormat(long PresetThreeDFormat)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 PresetThreeDFormat);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ApplicationEvents properties

	/////////////////////////////////////////////////////////////////////////////
	// ApplicationEvents operations


	/////////////////////////////////////////////////////////////////////////////
	// DocumentEvents properties

	/////////////////////////////////////////////////////////////////////////////
	// DocumentEvents operations

	void DocumentEvents::New()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void DocumentEvents::Open()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void DocumentEvents::Close()
	{
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// OCXEvents properties

	/////////////////////////////////////////////////////////////////////////////
	// OCXEvents operations

	void OCXEvents::GotFocus()
	{
		InvokeHelper(0x800100e0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void OCXEvents::LostFocus()
	{
		InvokeHelper(0x800100e1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// IApplicationEvents properties

	/////////////////////////////////////////////////////////////////////////////
	// IApplicationEvents operations

	void IApplicationEvents::Quit()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void IApplicationEvents::DocumentChange()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// IApplicationEvents2 properties

	/////////////////////////////////////////////////////////////////////////////
	// IApplicationEvents2 operations

	void IApplicationEvents2::Quit()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void IApplicationEvents2::DocumentChange()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void IApplicationEvents2::DocumentOpen(LPDISPATCH Doc)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc);
	}

	void IApplicationEvents2::DocumentBeforeClose(LPDISPATCH Doc, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Cancel);
	}

	void IApplicationEvents2::DocumentBeforePrint(LPDISPATCH Doc, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Cancel);
	}

	void IApplicationEvents2::DocumentBeforeSave(LPDISPATCH Doc, BOOL* SaveAsUI, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL VTS_PBOOL;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, SaveAsUI, Cancel);
	}

	void IApplicationEvents2::NewDocument(LPDISPATCH Doc)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc);
	}

	void IApplicationEvents2::WindowActivate(LPDISPATCH Doc, LPDISPATCH Wn)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Wn);
	}

	void IApplicationEvents2::WindowDeactivate(LPDISPATCH Doc, LPDISPATCH Wn)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_DISPATCH;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Wn);
	}

	void IApplicationEvents2::WindowSelectionChange(LPDISPATCH Sel)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel);
	}

	void IApplicationEvents2::WindowBeforeRightClick(LPDISPATCH Sel, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel, Cancel);
	}

	void IApplicationEvents2::WindowBeforeDoubleClick(LPDISPATCH Sel, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel, Cancel);
	}


	/////////////////////////////////////////////////////////////////////////////
	// ApplicationEvents2 properties

	/////////////////////////////////////////////////////////////////////////////
	// ApplicationEvents2 operations

	void ApplicationEvents2::Quit()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ApplicationEvents2::DocumentChange()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	void ApplicationEvents2::DocumentOpen(LPDISPATCH Doc)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc);
	}

	void ApplicationEvents2::DocumentBeforeClose(LPDISPATCH Doc, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Cancel);
	}

	void ApplicationEvents2::DocumentBeforePrint(LPDISPATCH Doc, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Cancel);
	}

	void ApplicationEvents2::DocumentBeforeSave(LPDISPATCH Doc, BOOL* SaveAsUI, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL VTS_PBOOL;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, SaveAsUI, Cancel);
	}

	void ApplicationEvents2::NewDocument(LPDISPATCH Doc)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc);
	}

	void ApplicationEvents2::WindowActivate(LPDISPATCH Doc, LPDISPATCH Wn)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Wn);
	}

	void ApplicationEvents2::WindowDeactivate(LPDISPATCH Doc, LPDISPATCH Wn)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_DISPATCH;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Doc, Wn);
	}

	void ApplicationEvents2::WindowSelectionChange(LPDISPATCH Sel)
	{
		static BYTE parms[] =
			VTS_DISPATCH;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel);
	}

	void ApplicationEvents2::WindowBeforeRightClick(LPDISPATCH Sel, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel, Cancel);
	}

	void ApplicationEvents2::WindowBeforeDoubleClick(LPDISPATCH Sel, BOOL* Cancel)
	{
		static BYTE parms[] =
			VTS_DISPATCH VTS_PBOOL;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
			 Sel, Cancel);
	}


	/////////////////////////////////////////////////////////////////////////////
	// EmailAuthor properties

	/////////////////////////////////////////////////////////////////////////////
	// EmailAuthor operations

	LPDISPATCH EmailAuthor::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long EmailAuthor::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailAuthor::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailAuthor::GetStyle()
	{
		LPDISPATCH result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// EmailOptions properties

	/////////////////////////////////////////////////////////////////////////////
	// EmailOptions operations

	LPDISPATCH EmailOptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long EmailOptions::GetCreator()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailOptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL EmailOptions::GetUseThemeStyle()
	{
		BOOL result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void EmailOptions::SetUseThemeStyle(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString EmailOptions::GetMarkCommentsWith()
	{
		CString result;
		InvokeHelper(0x6a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void EmailOptions::SetMarkCommentsWith(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x6a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL EmailOptions::GetMarkComments()
	{
		BOOL result;
		InvokeHelper(0x6b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void EmailOptions::SetMarkComments(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH EmailOptions::GetEmailSignature()
	{
		LPDISPATCH result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailOptions::GetComposeStyle()
	{
		LPDISPATCH result;
		InvokeHelper(0x6d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailOptions::GetReplyStyle()
	{
		LPDISPATCH result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString EmailOptions::GetThemeName()
	{
		CString result;
		InvokeHelper(0x72, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void EmailOptions::SetThemeName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x72, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// EmailSignature properties

	/////////////////////////////////////////////////////////////////////////////
	// EmailSignature operations

	LPDISPATCH EmailSignature::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long EmailSignature::GetCreator()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH EmailSignature::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString EmailSignature::GetNewMessageSignature()
	{
		CString result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void EmailSignature::SetNewMessageSignature(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	CString EmailSignature::GetReplyMessageSignature()
	{
		CString result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void EmailSignature::SetReplyMessageSignature(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Email properties

	/////////////////////////////////////////////////////////////////////////////
	// Email operations

	LPDISPATCH Email::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Email::GetCreator()
	{
		long result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Email::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Email::GetCurrentEmailAuthor()
	{
		LPDISPATCH result;
		InvokeHelper(0x69, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// HorizontalLineFormat properties

	/////////////////////////////////////////////////////////////////////////////
	// HorizontalLineFormat operations

	LPDISPATCH HorizontalLineFormat::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long HorizontalLineFormat::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH HorizontalLineFormat::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	float HorizontalLineFormat::GetPercentWidth()
	{
		float result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void HorizontalLineFormat::SetPercentWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	BOOL HorizontalLineFormat::GetNoShade()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void HorizontalLineFormat::SetNoShade(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long HorizontalLineFormat::GetAlignment()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void HorizontalLineFormat::SetAlignment(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long HorizontalLineFormat::GetWidthType()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void HorizontalLineFormat::SetWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}


	/////////////////////////////////////////////////////////////////////////////
	// Frameset properties

	/////////////////////////////////////////////////////////////////////////////
	// Frameset operations

	LPDISPATCH Frameset::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Frameset::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frameset::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN Frameset::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frameset::GetParentFrameset()
	{
		LPDISPATCH result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long Frameset::GetType()
	{
		long result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	long Frameset::GetWidthType()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetWidthType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frameset::GetHeightType()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetHeightType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frameset::GetWidth()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetWidth(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frameset::GetHeight()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetHeight(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frameset::GetChildFramesetCount()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH Frameset::GetChildFramesetItem(long Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	float Frameset::GetFramesetBorderWidth()
	{
		float result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFramesetBorderWidth(float newValue)
	{
		static BYTE parms[] =
			VTS_R4;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 newValue);
	}

	long Frameset::GetFramesetBorderColor()
	{
		long result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFramesetBorderColor(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long Frameset::GetFrameScrollbarType()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameScrollbarType(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL Frameset::GetFrameResizable()
	{
		BOOL result;
		InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameResizable(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString Frameset::GetFrameName()
	{
		CString result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameName(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL Frameset::GetFrameDisplayBorders()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameDisplayBorders(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	CString Frameset::GetFrameDefaultURL()
	{
		CString result;
		InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameDefaultURL(LPCTSTR lpszNewValue)
	{
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x24, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 lpszNewValue);
	}

	BOOL Frameset::GetFrameLinkToFile()
	{
		BOOL result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void Frameset::SetFrameLinkToFile(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH Frameset::AddNewFrame(long Where)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Where);
		return result;
	}

	void Frameset::Delete()
	{
		InvokeHelper(0x33, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// DefaultWebOptions properties

	/////////////////////////////////////////////////////////////////////////////
	// DefaultWebOptions operations

	LPDISPATCH DefaultWebOptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long DefaultWebOptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH DefaultWebOptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL DefaultWebOptions::GetOptimizeForBrowser()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetOptimizeForBrowser(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long DefaultWebOptions::GetBrowserLevel()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetBrowserLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL DefaultWebOptions::GetRelyOnCSS()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetRelyOnCSS(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetOrganizeInFolder()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetOrganizeInFolder(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetUpdateLinksOnSave()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetUpdateLinksOnSave(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetUseLongFileNames()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetUseLongFileNames(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetCheckIfOfficeIsHTMLEditor()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetCheckIfOfficeIsHTMLEditor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetCheckIfWordIsDefaultHTMLEditor()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetCheckIfWordIsDefaultHTMLEditor(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetRelyOnVML()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetRelyOnVML(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL DefaultWebOptions::GetAllowPNG()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetAllowPNG(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long DefaultWebOptions::GetScreenSize()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetScreenSize(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long DefaultWebOptions::GetPixelsPerInch()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetPixelsPerInch(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long DefaultWebOptions::GetEncoding()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetEncoding(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL DefaultWebOptions::GetAlwaysSaveInDefaultEncoding()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void DefaultWebOptions::SetAlwaysSaveInDefaultEncoding(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	LPDISPATCH DefaultWebOptions::GetFonts()
	{
		LPDISPATCH result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	CString DefaultWebOptions::GetFolderSuffix()
	{
		CString result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// WebOptions properties

	/////////////////////////////////////////////////////////////////////////////
	// WebOptions operations

	LPDISPATCH WebOptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long WebOptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH WebOptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	BOOL WebOptions::GetOptimizeForBrowser()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetOptimizeForBrowser(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long WebOptions::GetBrowserLevel()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetBrowserLevel(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	BOOL WebOptions::GetRelyOnCSS()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetRelyOnCSS(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL WebOptions::GetOrganizeInFolder()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetOrganizeInFolder(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL WebOptions::GetUseLongFileNames()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetUseLongFileNames(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL WebOptions::GetRelyOnVML()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetRelyOnVML(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	BOOL WebOptions::GetAllowPNG()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetAllowPNG(BOOL bNewValue)
	{
		static BYTE parms[] =
			VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 bNewValue);
	}

	long WebOptions::GetScreenSize()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetScreenSize(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long WebOptions::GetPixelsPerInch()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetPixelsPerInch(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	long WebOptions::GetEncoding()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	void WebOptions::SetEncoding(long nNewValue)
	{
		static BYTE parms[] =
			VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
			 nNewValue);
	}

	CString WebOptions::GetFolderSuffix()
	{
		CString result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void WebOptions::UseDefaultFolderSuffix()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	/////////////////////////////////////////////////////////////////////////////
	// OtherCorrectionsExceptions properties

	/////////////////////////////////////////////////////////////////////////////
	// OtherCorrectionsExceptions operations

	LPDISPATCH OtherCorrectionsExceptions::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long OtherCorrectionsExceptions::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH OtherCorrectionsExceptions::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	LPUNKNOWN OtherCorrectionsExceptions::Get_NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	long OtherCorrectionsExceptions::GetCount()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH OtherCorrectionsExceptions::Item(VARIANT* Index)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_PVARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Index);
		return result;
	}

	LPDISPATCH OtherCorrectionsExceptions::Add(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] =
			VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
			Name);
		return result;
	}


	/////////////////////////////////////////////////////////////////////////////
	// OtherCorrectionsException properties

	/////////////////////////////////////////////////////////////////////////////
	// OtherCorrectionsException operations

	LPDISPATCH OtherCorrectionsException::GetApplication()
	{
		LPDISPATCH result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long OtherCorrectionsException::GetCreator()
	{
		long result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	LPDISPATCH OtherCorrectionsException::GetParent()
	{
		LPDISPATCH result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	long OtherCorrectionsException::GetIndex()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	CString OtherCorrectionsException::GetName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	void OtherCorrectionsException::Delete()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
}
