#pragma once

#include "..\..\Module\GridBase\ExBaseListGrid.h"
#include "..\Module\Characteristic\CharElementTestPoint.h"

class CInvOwnDefGrid : public CExBaseListGrid
{
public:
	CInvOwnDefGrid();
	virtual ~CInvOwnDefGrid();

	virtual void InitGrid();
	virtual void InitGridTitle();

	//÷ÿ‘ÿ∫Ø ˝
protected: 
	virtual void ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow=TRUE);
};
