// StringSerialBuffer.h : CStringSerialBuffer 的声明

#pragma once
#include "resource.h"       // 主符号

#include "SystemTool_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CStringSerialBuffer

class ATL_NO_VTABLE CStringSerialBuffer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStringSerialBuffer, &CLSID_StringSerialBuffer>,
	public IDispatchImpl<IStringSerialBuffer, &IID_IStringSerialBuffer, &LIBID_SystemTool, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CStringSerialBuffer()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STRINGSERIALBUFFER)


BEGIN_COM_MAP(CStringSerialBuffer)
	COM_INTERFACE_ENTRY(IStringSerialBuffer)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(get_VBuffer)(VARIANT* pVal);
	STDMETHOD(put_VBuffer)(VARIANT newVal);
	STDMETHOD(get_String)(BSTR* pVal);
	STDMETHOD(put_String)(BSTR newVal);
	STDMETHOD(AddBufferLength)(LONG nLen);
	STDMETHOD(SetBufferLength)(LONG nLen, LONG* pnReturn);
	STDMETHOD(AllocBuffer)(LONG* pnReturn);
	STDMETHOD(SetReadMode)(void);
	STDMETHOD(SetWriteMode)(void);
	STDMETHOD(SetCalSizeMode)(void);
	STDMETHOD(IsReadMode)(LONG* pnReturn);
	STDMETHOD(IsWriteMode)(LONG* pnReturn);
	STDMETHOD(IsCalSizeMode)(LONG* pnReturn);
	STDMETHOD(WriteString)(BSTR bstrWrite);
	STDMETHOD(SaveToFile)(BSTR bstrFile, LONG* pnReturn);
	STDMETHOD(OpenFromFile)(BSTR bstrFile, LONG* pnReturn);
};

OBJECT_ENTRY_AUTO(__uuidof(StringSerialBuffer), CStringSerialBuffer)
