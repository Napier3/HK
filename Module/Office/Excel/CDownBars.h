// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "I:\\EXCEL.EXE" no_namespace
// CDownBars 包装类

class CDownBars : public COleDispatchDriver
{
public:
	CDownBars(){} // 调用 COleDispatchDriver 默认构造函数
	CDownBars(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDownBars(const CDownBars& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 属性
public:

	// 操作
public:


	// DownBars 方法
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	VARIANT Select()
	{
		VARIANT result;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Border()
	{
		LPDISPATCH result;
		InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT Delete()
	{
		VARIANT result;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Interior()
	{
		LPDISPATCH result;
		InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Fill()
	{
		LPDISPATCH result;
		InvokeHelper(0x67f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Format()
	{
		LPDISPATCH result;
		InvokeHelper(0x74, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// DownBars 属性
public:

};
