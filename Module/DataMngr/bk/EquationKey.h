// EquationKey.h : CEquationKey 的声明

#pragma once
#include "resource.h"       // 主符号

#include "SystemTool_i.h"
#include "..\..\Module\AtlMemBuffer\WEquationBuffer.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CEquationKey

class ATL_NO_VTABLE CEquationKey :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEquationKey, &CLSID_EquationKey>,
	public IDispatchImpl<IEquationKey, &IID_IEquationKey, &LIBID_SystemTool, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CEquationKey()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_EQUATIONKEY)


BEGIN_COM_MAP(CEquationKey)
	COM_INTERFACE_ENTRY(IEquationKey)
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

	CWEqtnKey *m_pEqtnKey;

	void AttachEqtnKey(CWEqtnKey *pKey)  
	{
		m_pEqtnKey = pKey;
	}
public:

	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(get_Value)(BSTR* pVal);
	STDMETHOD(put_Value)(BSTR newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(EquationKey), CEquationKey)
