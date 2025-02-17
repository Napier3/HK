#pragma once

#include "SetsFileToolInterface.h"

#include "../../../../Module/Acrobat/PdfTextParseSets.h"
#include "../../../../Module/Acrobat/PdfXmlParseSets.h"
#include "../Cpus.h"

class CStesFilePdfTool :public CSetsFileToolInterface
{
public:
	CStesFilePdfTool(void);
	virtual ~CStesFilePdfTool(void);

	static CFileToolInterface* Create()
	{
		return new CStesFilePdfTool();
	}

	//20230728 huangliang …Ë÷√–ﬁ∂©±‰¡ø
	bool m_bCorrect;

	virtual BOOL ExportFile(const CString &strFile, LPDISPATCH lpDispatch=NULL);
	virtual BOOL ImportFile(const CString &strFile, LPDISPATCH lpDispatch=NULL);

public:
	
private:
	
};

