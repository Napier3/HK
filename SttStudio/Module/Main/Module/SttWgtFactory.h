#pragma once

#include "SttWgtBase.h"
#include "../SttXuiData/SttXuiDataBase.h"

class QSttWgtFactory : public CExBaseList
{
public:
	QSttWgtFactory(void);
	virtual ~QSttWgtFactory(void);

	static QSttWgtFactory *Create();
	static void Release();

public:
	static QSttWgtBase* CreateSttWgt(CSttXuiDataBase *pSttXuiData, QWidget* pParent);
};

extern QSttWgtFactory* g_pSttWgtFactory;
extern long g_nSttWgtFactoryRef;
