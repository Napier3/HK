#include "stdafx.h"
#include "SttTestResource_Sync.h"

CSttTestResource_Sync::CSttTestResource_Sync(void)
{
}

CSttTestResource_Sync::~CSttTestResource_Sync(void)
{
}

void CSttTestResource_Sync::CreateSoftResource()
{
	DeleteAll();
	AddNewData(_T("Ua1"), _T("U1"));
	AddNewData(_T("Ub1"), _T("U2"));
	AddNewData(_T("Uc1"), _T("U3"));
	AddNewData(_T("Ua2"), _T("U4"));
	AddNewData(_T("Ub2"), _T("U5"));
	AddNewData(_T("Uc2"), _T("U6"));

	AddNewData(_T("Ia1"), _T("I1"));
	AddNewData(_T("Ib1"), _T("I2"));
	AddNewData(_T("Ic1"), _T("I3"));
	AddNewData(_T("Ia2"), _T("I4"));
	AddNewData(_T("Ib2"), _T("I5"));
	AddNewData(_T("Ic2"), _T("I6"));
}

