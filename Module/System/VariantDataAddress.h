// VariantDataAddress.h: interface for the CVariantDataAddress class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VARIANTDATAADDRESS_H__)
#define AFX_VARIANTDATAADDRESS_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVariantDataAddress  
{
public:
	enum eVDOT
	{
		VDOT_NULL = 0,
		VDOT_UNSIGNEDCHAR = 1,
		VDOT_SHORT = 2,
		VDOT_LONG = 3,
		VDOT_FLOAT = 4,
		VDOT_DOUBLE = 5,
		VDOT_INT = 6,
		VDOT_CHARSTR = 7,
		VDOT_BOOL = 8,
		VDOT_N64 = 9,
		VDOT_CSTRING=10,
		VDOT_DWORD=11
	};
public:
	eVDOT vt;
	union 
	{
		long	*lVal; 
		DWORD	*dwVal; 
		float	*fltVal;
		double	*dblVal; 
		int	*intVal;
		char *pszVal;
		unsigned char	*bVal;
		short	*nVal;
		volatile __int64 *n64Val;
		CString *pString;
	};

	union 
	{
		long	_lVal; 
		DWORD	_dwVal; 
		float	_fltVal;
		double	_dblVal; 
		int	_intVal;
		unsigned char	_bVal;
		short	_nVal;
		volatile __int64 _n64Val;
	};

public:
	CVariantDataAddress();
	virtual ~CVariantDataAddress();

	CVariantDataAddress(unsigned char *val);
	CVariantDataAddress(short *val);
	CVariantDataAddress(long *val);
	CVariantDataAddress(DWORD *val);
	CVariantDataAddress(float *val);
	CVariantDataAddress(double *val);
	CVariantDataAddress(int *val);
	CVariantDataAddress(volatile __int64 *val);
	CVariantDataAddress(char *val);
	CVariantDataAddress(const char *val);
	CVariantDataAddress(CString *val);
	CVariantDataAddress(const CVariantDataAddress &val);

	void operator= (unsigned char *val);
	void operator= (short *val);
	void operator= (long *val);
	void operator= (DWORD *val);
	void operator= (float *val);
	void operator= (double *val);
	void operator= (int *val);
	void operator= (volatile __int64 *val);
	void operator= (char *val);
	void operator= (const char *val);
	void operator= (CString *val);
	void operator= (const CVariantDataAddress &val);

	int operator== (unsigned char val);
	int operator== (short val);
	int operator== (long val);
	int operator== (DWORD val);
	int operator== (float val);
	int operator== (double val);
	int operator== (int val);
	int operator== (volatile __int64 val);
	int operator== (char *val);
	int operator== (const CString &val);
	int operator== (const CVariantDataAddress &val);
	
	long Compare(unsigned char val);
	long Compare(short val);
	long Compare(long val);
	long Compare(DWORD val);
	long Compare(float val);
	long Compare(double val);
	long Compare(int val);
	long Compare(volatile __int64 val);
	long Compare(char *val);
	long Compare(const CString &val);
	long Compare(const CVariantDataAddress &val);
	 
	CString ToString(const CString &strFormat);
	CString ToString();
	void FromString(char *pszValue);
	void FromString(const char *pszValue)
	{
		FromString((char*)pszValue);
	}
	BOOL CompareValAddr(LPVOID pValAddr);

	BOOL IsCString()	{	return (vt == VDOT_CSTRING);	}
	void UpdateDefaultValue();
	BOOL IsValueChange();
	void InitByDefault();

	DWORD str_to_dword(const char *pstrValue);
};

#endif // !defined(AFX_VARIANTDATAADDRESS_H__)
