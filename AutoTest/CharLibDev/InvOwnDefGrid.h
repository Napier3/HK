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

	//���غ���
protected: 
	virtual void ShowData(CExBaseObject *pData, int& nRow, BOOL bInsertRow=TRUE);
};
