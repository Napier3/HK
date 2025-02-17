#include "StdAfx.h"
#include "IEDGrid.h"

#define ROW_HEIGHT  20


// CIEDGrid

IMPLEMENT_DYNCREATE(CIEDGrid, CGridCtrl)

	CIEDGrid::CIEDGrid()
	:m_nRowCurSel(1)
	,m_nType(0)
	,m_strIEDDes(_T(""))
	,m_strIEDName(_T(""))
{

}

CIEDGrid::~CIEDGrid()
{
}


BEGIN_MESSAGE_MAP(CIEDGrid, CGridCtrl)
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CIEDGrid message handlers
void CIEDGrid::CreateGrid(int nRow,int nCol,int nFixedRow /* = 0 */,int nFixedCol /* = 0 */)
{
	DeleteAllItems();
	SetEditable(FALSE);

//	try {
		SetRowCount(nRow);
		SetColumnCount(nCol);
		SetFixedRowCount(nFixedRow);
		SetFixedColumnCount(nFixedCol);
// 	}
// 	catch (CMemoryException* e)
// 	{
// 		e->ReportError();
// 		e->Delete();
// 	}
}

void CIEDGrid::SetGridHead(const CString* pCstr, const int nCount)
{
	SetListMode();
	ASSERT(pCstr);
	ASSERT(nCount);
	if (pCstr && nCount > 0)
	{
		// 初始化列表头 
		int Col = GetColumnCount();
		if (nCount == Col)
		{
			GV_ITEM Item;
			for (int i = 0;  i< Col; i++)
			{
				Item.mask = GVIF_TEXT|GVIF_FORMAT;
				Item.row = 0;
				Item.col = i;
				Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
				Item.szText = pCstr[i];
				SetItem(&Item);
			}
		}else
		{
			AfxMessageBox(_T("传入字符串数组个数与行数不同，请确认"));
		}
	}

	SetRowHeight(0, ROW_HEIGHT);
}


void CIEDGrid::SetGridRowData_GooseInput(const PGOOSEIN giptitr,int nRow)
{
	DWORD dwTemp = 0;
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT|GVIF_DATATYPE|GVIF_PARAM;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	Item.nDataType = GVET_NOEDIT;
	Item.lParam = (LPARAM)giptitr;
	SetItem(&Item);

	// AppID
	Item.nDataType = GVET_NOEDIT;
	Item.col++;// = 2;
	dwTemp = ST_StringToHex(giptitr->strAppID);
	Item.szText.Format(_T("0x%.4X"),dwTemp);
	SetItem(&Item);

	// MAC
	Item.col++;// = 3;
	Item.szText = giptitr->strMac;
	SetItem(&Item);

	// 通道数目
	Item.col++;// = 4;
	Item.szText.Format(_T("%d"),giptitr->nChnCount);
	SetItem(&Item);

	// 引用数目
	Item.col++;// = 5;
	Item.szText.Format(_T("%d"),giptitr->GetCount());//list_gseinputchn.size());
	SetItem(&Item);

	// 控制块所在IED
	Item.col++;// = 6;
	Item.szText.Format(_T("输出自%s-%s"),giptitr->strOutputIEDName,giptitr->strOutputIEDDesc);
	SetItem(&Item);

	// 数据集描述
	Item.col++;// = 7;
	Item.szText = giptitr->strDes;
	SetItem(&Item);

	// gocbRef
	Item.col++;// = 8;
	Item.szText = giptitr->strgocbRef;
	SetItem(&Item);

	// Dataset
	Item.col++;// = 9;
	Item.szText = giptitr->strDataSet;
	SetItem(&Item);

	// goID
	Item.col++;// = 10;
	Item.szText = giptitr->strgoID;
	SetItem(&Item);

	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDGrid::SetGridRowData_GooseOutput(PGOOSEOUT goptitr,int nRow)
{
	DWORD dwTemp = 0;
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT|GVIF_DATATYPE|GVIF_PARAM;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	Item.nDataType = GVET_NOEDIT;
	Item.lParam = (LPARAM)goptitr;
	SetItem(&Item);

	// 选择
// 	Item.nDataType = GVET_CHECKBOX;
// 	Item.dwValue = goptitr->bSelect;
// 	Item.col = 1;
// 	SetItem(&Item);

	// AppID
	Item.nDataType = GVET_NOEDIT;
	Item.col++;// = 2;
	dwTemp = ST_StringToHex(goptitr->scgsData.address.AppID);
	Item.szText.Format(_T("0x%.4X"),dwTemp);
	SetItem(&Item);

	// MAC
	Item.col++;// = 3;
	Item.szText = goptitr->scgsData.address.MacAddress;
	SetItem(&Item);

	// 通道数目
	Item.col++;// = 4;
	Item.szText.Format(_T("%d"),goptitr->GetCount());//gseoutputchn.size());
	SetItem(&Item);

	// gocbRef
	Item.col++;// = 5;
	Item.szText = goptitr->strgocbRef;
	SetItem(&Item);

	// Dataset
	Item.col++;// = 6;
	Item.szText = goptitr->strDataset;
	SetItem(&Item);

	// goID
	Item.col++;// = 7;
	Item.szText = goptitr->strgoID;
	SetItem(&Item);

	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDGrid::SetGridRowData_SMVInput(PSMVIN smviptitr,int nRow)
{
	DWORD dwTemp = 0;
	CString str;
	GV_ITEM Item;
	// 序号
	Item.nDataType = GVET_NOEDIT;
	Item.mask = GVIF_TEXT|GVIF_FORMAT|GVIF_DATATYPE|GVIF_PARAM;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	Item.lParam = (LPARAM)smviptitr;
	SetItem(&Item);

	// 选择
// 	Item.nDataType = GVET_CHECKBOX;
// 	Item.dwValue = smviptitr->bSelect;
// 	Item.col = 1;
// 	SetItem(&Item);

	// AppID
	Item.nDataType = GVET_NOEDIT;
	Item.col++;// = 2;
	dwTemp = ST_StringToHex(smviptitr->strAppID);
	Item.szText.Format(_T("0x%.4X"),dwTemp);
	SetItem(&Item);

	// MAC
	Item.col++;// = 3;
	Item.szText = smviptitr->strMac;
	SetItem(&Item);

	// 通道数目
	Item.col++;// = 4;
	Item.szText.Format(_T("%d"),smviptitr->nChnCount);
	SetItem(&Item);

	// 引用数目
	Item.col++;// = 5;
	Item.szText.Format(_T("%d"),smviptitr->GetCount());//list_smvinputchn.size());
	SetItem(&Item);

	// 控制块所在IED
	Item.col++;// = 6;
	Item.szText.Format(_T("输出自%s-%s"),smviptitr->strOutputIEDName,smviptitr->strOutputIEDDesc);
	SetItem(&Item);

	// smvID
	Item.col++;// = 7;
	Item.szText = smviptitr->strsmvID;
	SetItem(&Item);
	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDGrid::SetGridRowData_SMVOutput(PSMVOUT smvoptitr,int nRow)
{
	
	DWORD dwTemp = 0;
	CString str;
	GV_ITEM Item;
	// 序号
	Item.nDataType = GVET_NOEDIT;
	Item.mask = GVIF_TEXT|GVIF_FORMAT|GVIF_DATATYPE|GVIF_PARAM;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	Item.lParam = (LPARAM)smvoptitr;
	SetItem(&Item);

	// 选择
// 	Item.nDataType = GVET_CHECKBOX;
// 	Item.dwValue = smvoptitr->bSelect;
// 	Item.col = 1;
// 	SetItem(&Item);

	// AppID
	Item.nDataType = GVET_NOEDIT;
	Item.col++;// = 2;
	dwTemp = ST_StringToHex(smvoptitr->scgsData.address.AppID);
	Item.szText.Format(_T("0x%.4X"),dwTemp);
	SetItem(&Item);

	// MAC
	Item.col++;// = 3;
	Item.szText = smvoptitr->scgsData.address.MacAddress;
	SetItem(&Item);

	// 条目数
	Item.col++;// = 4;
	Item.szText.Format(_T("%d"),smvoptitr->GetCount());//smvoutputchn.size());
	SetItem(&Item);

	// svID
	Item.col++;// = 5;
	Item.szText = smvoptitr->strsmvID;
	SetItem(&Item);

	// 优先级
	Item.col++;// = 6;
	Item.szText = smvoptitr->scgsData.address.VLanpriority;
	SetItem(&Item);

	// VLanID
	Item.col++;// = 7;
	Item.szText.Format(_T("%.04X"), smvoptitr->scgsData.address.VLanID);
	SetItem(&Item);

	// 版本号
	Item.col++;// = 8;
	Item.szText = smvoptitr->strVersion;
	SetItem(&Item);
	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDGrid::InitGrid(int nimportfiletype,const CLIENTIEDPTR& showiedPtr)
{
	m_nRowCurSel = 0;
	DWORD Ptraddr = 0;
	switch (nimportfiletype)
	{
	case 2:
		ShowGooseInput(showiedPtr->list_gooseinput);
		break;
	case 0:
		ShowGooseOutput(showiedPtr->list_gooseoutput);
		break;
	case 3:
		ShowSMVInput(showiedPtr->list_smvinput);
		break;
	case 1:
		ShowSMVOutput(showiedPtr->list_smvoutput);
		break;
	default:
		DeleteAllItems();
		break;
	}

	AutoSize(FALSE, TRUE);

	if (GetRowCount() > 1)
	{
		m_nRowCurSel = 1;
		Ptraddr = GetItemData(m_nRowCurSel, 0);
		m_nType = nimportfiletype;
		
		SelectRow(m_nRowCurSel);
		::SendMessage(GetParent()->GetSafeHwnd(),WM_USERUPDATECHN,Ptraddr,nimportfiletype);
	}
	else
	{
		m_nRowCurSel = 0;
	}
}

void CIEDGrid::ShowGooseInput(CScdDataList& listGooseIn)
{
	PGOOSEIN giptitr=NULL,giptitrT=NULL;

	// 检查各个逻辑设备间是否有相同的控制块输出
	if (listGooseIn.GetCount() > 1)//size() > 1)
	{
		//giptitrB = listGooseIn.begin();
		//giptitrE = listGooseIn.end();
		long nIndex=0;

		while(TRUE)//for (giptitr = giptitrB; giptitr != giptitrE; giptitr++)
		{
			giptitr = (PGOOSEIN)listGooseIn.GetAtIndex(nIndex);
			if (giptitr == NULL)
			{
				break;
			}

			//giptitrT = giptitr;
			//advance(giptitrT,1);
			long nIndex2 = nIndex+1;
			while (TRUE)//for (;giptitrT != giptitrE;)
			{
				giptitrT = (PGOOSEIN)listGooseIn.GetAtIndex(nIndex2);

				if (giptitrT == NULL)
				{
					break;
				}

				// 相同则删除此ldevice内的goosein,添加到giptitrT
				if (giptitrT->strAppID == giptitr->strAppID && 
					giptitrT->strMac == giptitr->strMac &&
					giptitrT->nChnCount == giptitr->nChnCount &&
					giptitrT->strgocbRef == giptitr->strgocbRef &&
					giptitrT->strDataSet == giptitr->strDataSet && 
					giptitrT->strgoID == giptitr->strgoID)
				{
					//giptitr->list_gseinputchn.insert(giptitr->list_gseinputchn.end(),
					//	giptitrT->list_gseinputchn.begin(),giptitrT->list_gseinputchn.end());
					giptitr->Append(*giptitrT);

					listGooseIn.DeleteAtIndex(nIndex2);//giptitrT = listGooseIn.erase(giptitrT);
				}
				else
				{
					nIndex2++;
				}
			}

		}

	}


	// 统计个数
	int nSize = listGooseIn.GetCount();//.size();


	// 创建列表
	CreateGrid(nSize+1,nFileGIn,1);
	SetGridHead(strFileGIn,nFileGIn);

	// 设置数据
	int nCount = 1;
	//giptitrB = listGooseIn.begin();
	//giptitrE = listGooseIn.end();

	TPOS pos = listGooseIn.GetHeadPosition();

	// 在此范围内查找,判断MAC,gocbRef,DataSet,goID
	while (pos != NULL)//for (giptitr = giptitrB; giptitr != giptitrE; giptitr++)
	{
		giptitr = (PGOOSEIN)listGooseIn.GetNext(pos);
		giptitr->bSelect = FALSE;

		// 检测是否有选中项（以APPID为键值）
		SetGridRowData_GooseInput(giptitr,nCount++);
	}
}


void CIEDGrid::ShowGooseOutput(CScdDataList& listGooseOut)
{
	PGOOSEOUT goptitr=NULL,goptitrB=NULL,goptitrE=NULL;
	int nSize = listGooseOut.GetCount();//.size();
	//goptitr = listGooseOut.begin();
	//goptitrE = listGooseOut.end();

	// 创建列表
	CreateGrid(nSize+1,nFileGOut,1);
	SetGridHead(strFileGOut,nFileGOut);

	nSize = 1;
	TPOS pos = listGooseOut.GetHeadPosition();

	while (pos != NULL)//for (;goptitr != goptitrE; goptitr++)
	{
		goptitr = (PGOOSEOUT)listGooseOut.GetNext(pos);
		goptitr->bSelect = FALSE;
		SetGridRowData_GooseOutput(goptitr,nSize++);
	}
}

void CIEDGrid::ShowSMVInput(CScdDataList& listSMVIn)
{
	PSMVIN smviptitr=NULL,smviptitrT=NULL;

	CString str;
	// 检查各个逻辑设备间是否有相同的控制块输出
	if (listSMVIn.GetCount() > 1)//size() > 1)
	{
		//smviptitrB = listSMVIn.begin();
		//smviptitrE = listSMVIn.begin();
		long nIndex = 0;


		while (TRUE)//for (smviptitr = smviptitrB; smviptitr != smviptitrE; smviptitr++)
		{
			smviptitr = (PSMVIN)listSMVIn.GetAtIndex(nIndex);

			if (smviptitr == NULL)
			{
				break;
			}

			//smviptitrT = smviptitr;
			//advance(smviptitrT,1);
			long nIndex2 = nIndex + 1;
			while (TRUE)//for (; smviptitrT != smviptitrE;)
			{
				smviptitrT = (PSMVIN)listSMVIn.GetAtIndex(nIndex2);

				if (smviptitrT == NULL)
				{
					break;
				}

				// 相同则删除此ldevice内的goosein,添加到giptitrT
				if (smviptitrT->strAppID == smviptitr->strAppID && 
					smviptitrT->strMac == smviptitr->strMac &&
					smviptitrT->nChnCount == smviptitr->nChnCount &&
					smviptitrT->strsmvID == smviptitr->strsmvID)
				{

					//smviptitr->list_smvinputchn.insert(smviptitr->list_smvinputchn.end(),
					//	smviptitrT->list_smvinputchn.begin(),smviptitrT->list_smvinputchn.end());
					smviptitr->Append(*smviptitrT);
			
					listSMVIn.DeleteAtIndex(nIndex2);//smviptitrT = listSMVIn.erase(smviptitrT);
				}else
				{
					nIndex2++;//smviptitrT++;
				}
			}

		}
	}


	int nSize = listSMVIn.GetCount();//.size();


	// 创建列表
	CreateGrid(nSize+1,nFileSmvIn,1);
	SetGridHead(strFileSmvIn,nFileSmvIn);

	// 设置数据
	int nCount = 1;

	//smviptitrB = listSMVIn.begin();
	//smviptitrE = listSMVIn.end();
	TPOS pos = listSMVIn.GetHeadPosition();

	while (pos != NULL)//for (smviptitr = smviptitrB; smviptitr != smviptitrE; smviptitr++)
	{
		smviptitr = (PSMVIN)listSMVIn.GetNext(pos);
		smviptitr->bSelect = FALSE;
		SetGridRowData_SMVInput(smviptitr,nCount++);
	}

}

void CIEDGrid::ShowSMVOutput(CScdDataList& listSMVOut)
{
	PSMVOUT smvoptitr=NULL,smvoptitrB=NULL,smvoptitrE=NULL;
	int nSize = listSMVOut.GetCount();//size();

	// 创建列表
	int nCount = 1;
	CreateGrid(nSize+1,nFIleSmvOut,1);
	SetGridHead(strFileSmvOut,nFIleSmvOut);

	// 设置数据
	//smvoptitrB = listSMVOut.begin();
	//smvoptitrE = listSMVOut.end();
	TPOS pos = listSMVOut.GetHeadPosition();
	
	while (pos != NULL)//for (smvoptitr = smvoptitrB; smvoptitr != smvoptitrE; smvoptitr++)
	{
		smvoptitr = (PSMVOUT)listSMVOut.GetNext(pos);
		smvoptitr->bSelect = FALSE;
		SetGridRowData_SMVOutput(smvoptitr,nCount);
		nCount++;
	}
}


void CIEDGrid::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CGridCtrl::OnKeyDown(nChar, nRepCnt, nFlags);


	if ((nChar == VK_DOWN || nChar == VK_UP) && m_nRowCurSel != m_idCurrentCell.row)
	{

		m_nRowCurSel = m_idCurrentCell.row;
		DWORD Ptraddr = GetItemData(m_nRowCurSel, 0);
		::SendMessage(GetParent()->GetSafeHwnd(),WM_USERUPDATECHN,Ptraddr,m_nType);

	}
}

void CIEDGrid::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (st_IsInLoadScdXmlFile())
	{
		return;
	}

	int nType = -1;
	BOOL bOldCheck;
	CGridCell* pCell = GetCell(m_LeftClickDownCell.row, m_LeftClickDownCell.col);
	if (pCell)
	{
		if (pCell->nDataType == GVET_CHECKBOX)
		{
			nType = 1;
			bOldCheck = pCell->dwValue;
		}
	}

	CGridCtrl::OnLButtonUp(nFlags,point);

	if (pCell && m_nRowCurSel > 0)
	{
		BOOL bUpdataChn = FALSE;
		if (m_nRowCurSel != m_LeftClickDownCell.row )
		{
			bUpdataChn = TRUE;
		}

		if (bUpdataChn == TRUE || nType == 1)
		{
			m_nRowCurSel = m_LeftClickDownCell.row;
			if (m_nRowCurSel > 0)
			{
				
				// 更新通道数据
				DWORD dwPtrAddr = pCell->lParam;
				if (nType == 1)
				{
					BOOL bCheck = pCell->dwValue;

					if (bCheck != bOldCheck)
					{
						SetIEDCtrlCheck(bCheck,dwPtrAddr);
					}
				}

				if (bUpdataChn == TRUE)
				{
					::SendMessage(GetParent()->GetSafeHwnd(),WM_USERUPDATECHN,dwPtrAddr,m_nType);
				}
			}	
		}
	}
}

void CIEDGrid::DeleteAllItems()
{
	CGridCtrl::DeleteAllItems();
}


void CIEDGrid::SetIEDCtrlCheck(BOOL bCheck,DWORD dwPtrAddr)
{

	switch (m_nType)
	{
	case 2:
		{
			GOOSEINPtr gseinputptr = (GOOSEINPtr)dwPtrAddr;
			(gseinputptr)->bSelect = bCheck;
		}
		break;
	case 0:
		{
			GOOSEOUTPtr gseoutputPtr = (GOOSEOUTPtr)dwPtrAddr;
			(gseoutputPtr)->bSelect = bCheck;

		}
		break;
	case 3:
		{
			SMVINPtr smvinputPtr= (SMVINPtr)dwPtrAddr;
			(smvinputPtr)->bSelect = bCheck;
		}
		break;
	case  1:
		{
			SMVOUTPtr smvoutputPtr = (SMVOUTPtr)dwPtrAddr;
			(smvoutputPtr)->bSelect = bCheck;
		}
		break;
	}


}



// CIEDChnGrid

IMPLEMENT_DYNCREATE(CIEDChnGrid, CGridCtrl)

	CIEDChnGrid::CIEDChnGrid()
{

}

CIEDChnGrid::~CIEDChnGrid()
{
}


BEGIN_MESSAGE_MAP(CIEDChnGrid, CGridCtrl)
END_MESSAGE_MAP()



// CIEDChnGrid message handlers
void CIEDChnGrid::CreateGrid(int nRow,int nCol,int nFixedRow /* = 0 */,int nFixedCol /* = 0 */)
{
	DeleteAllItems();
	SetEditable(FALSE);

// 	try {
		SetRowCount(nRow);
		SetColumnCount(nCol);
		SetFixedRowCount(nFixedRow);
		SetFixedColumnCount(nFixedCol);
// 	}
// 	catch (CMemoryException* e)
// 	{
// 		e->ReportError();
// 		e->Delete();
// 	}
}

void CIEDChnGrid::DeleteAllItems()
{
	CGridCtrl::DeleteAllItems();
}


void CIEDChnGrid::SetGridHead(const CString* pCstr, const int nCount)
{
	ASSERT(pCstr);
	ASSERT(nCount);
	if (pCstr && nCount > 0)
	{
		// 初始化列表头 
		int Col = GetColumnCount();
		if (nCount == Col)
		{
			GV_ITEM Item;
			for (int i = 0;  i< Col; i++)
			{
				Item.mask = GVIF_TEXT|GVIF_FORMAT;
				Item.row = 0;
				Item.col = i;
				Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
				Item.szText = pCstr[i];
				SetItem(&Item);
			}
		}
		else
		{
			AfxMessageBox(_T("传入字符串数组个数与行数不同，请确认"));
		}
	}

	SetRowHeight(0, ROW_HEIGHT);
}

void CIEDChnGrid::SetGridRowData_GooseInputChn(const INPUTCHNPtr& giptchnPtr,int nRow)
{
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	SetItem(&Item);

	// 内部地址
	Item.col = 1;
	Item.szText = giptchnPtr->strIntAddress;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 内部信号描述
	Item.col = 2;
	Item.szText = giptchnPtr->strIntSigDes;
	SetItem(&Item);

	// 外部信号序号
	Item.col = 3;
	Item.szText.Format(_T("%d"),giptchnPtr->nExtSigIndex);
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 外部信号地址
	Item.col = 4;
	Item.szText = giptchnPtr->strExtSigAddress;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 外部信号描述
	Item.col = 5;
	Item.szText = giptchnPtr->strExtSigDes;
	SetItem(&Item);

	// 开出量映射
	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDChnGrid::SetGridRowData_GooseOutputChn(const GOOSEOUTPUTCHNPtr& goptchnPtr,int nRow)
{
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	SetItem(&Item);

	// LN描述
	Item.col = 1;
	Item.szText = goptchnPtr->strLNDes;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// DOI描述
	Item.col = 2;
	Item.szText = goptchnPtr->strDOIDes;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// DAI描述
	Item.col = 3;
	Item.szText = goptchnPtr->strDAIDes;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 类型
	Item.col = 4;
	Item.szText = goptchnPtr->strType;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 地址
	Item.col = 5;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText = goptchnPtr->strAddress;
	SetItem(&Item);

	SetRowHeight(nRow, ROW_HEIGHT);
}
void CIEDChnGrid::SetGridRowData_SMVInputChn(const INPUTCHNPtr& smviptchnPtr,int nRow)
{
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	SetItem(&Item);

	// 内部地址
	Item.col = 1;
	Item.szText = smviptchnPtr->strIntAddress;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 内部信号描述
	Item.col = 2;
	Item.szText = smviptchnPtr->strIntSigDes;
	SetItem(&Item);

	// 外部信号序号
	Item.col = 3;
	Item.szText.Format(_T("%d"),smviptchnPtr->nExtSigIndex);
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 外部信号地址
	Item.col = 4;
	Item.szText = smviptchnPtr->strExtSigAddress;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// 外部信号描述
	Item.col = 5;
	Item.szText = smviptchnPtr->strExtSigDes;
	SetItem(&Item);

	SetRowHeight(nRow, ROW_HEIGHT);
}
void CIEDChnGrid::SetGridRowData_SMVOutputChn(const SMVOUTPUTCHNPtr& smvoptchnPtr,int nRow)
{
	CString str;
	GV_ITEM Item;
	// 序号
	Item.mask = GVIF_TEXT|GVIF_FORMAT;
	Item.row = nRow;
	Item.col = 0;
	Item.nFormat = DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	Item.szText.Format(_T("%d"),nRow);
	SetItem(&Item);

	// LN描述
	Item.col = 1;
	Item.szText = smvoptchnPtr->strLNDes;
	Item.nFormat = DT_LEFT|DT_VCENTER|DT_SINGLELINE|DT_END_ELLIPSIS|DT_NOPREFIX;
	SetItem(&Item);

	// DOI描述
	Item.col = 2;
	Item.szText = smvoptchnPtr->strDOIDes;
	SetItem(&Item);

	// 地址
	Item.col = 3;
	Item.szText = smvoptchnPtr->strAddress;
	SetItem(&Item);

	SetRowHeight(nRow, ROW_HEIGHT);
}

void CIEDChnGrid::ShowGooseInputChn(const GOOSEINPtr& giptPtr)
{
	PINPUTCHN giptchnitr=NULL,giptchnitrB=NULL,giptchnitrE=NULL;

	int nSize = giptPtr->GetCount();//list_gseinputchn.size();
	CreateGrid(nSize+1,nFileGInChn,1);
	SetGridHead(strFileGInChn,nFileGInChn);

	//giptchnitrB = giptPtr->list_gseinputchn.begin();
	//giptchnitrE = giptPtr->list_gseinputchn.end();

	int nRow = 1;
	TPOS pos = giptPtr->GetHeadPosition();
	while (pos != NULL)//for (giptchnitr = giptchnitrB; giptchnitr != giptchnitrE; giptchnitr++)
	{
		giptchnitr = (PINPUTCHN)giptPtr->GetNext(pos);
		SetGridRowData_GooseInputChn(giptchnitr,nRow);
		nRow++;
	}
}
void CIEDChnGrid::ShowGooseOutputChn(const GOOSEOUTPtr& goptPtr)
{
	int nSize = goptPtr->GetCount();//gseoutputchn.size();
	CreateGrid(nSize+1,nFileGOutChn,1);
	SetGridHead(strFileGOutChn,nFileGOutChn);

	std::list<CString>::iterator lstr,lstrE;
	lstr = goptPtr->chnAddr.begin();
	lstrE = goptPtr->chnAddr.end();

	int nRow = 1;
	GOOSEOUTPUTCHNPtr goptchnPtr;
	for (; lstr != lstrE; lstr++)
	{
		goptchnPtr = (GOOSEOUTPUTCHNPtr)goptPtr->FindByAddress((*lstr));//gseoutputchn[(*lstr)];
		SetGridRowData_GooseOutputChn(goptchnPtr,nRow);
		nRow++;
	}

	AutoSize(FALSE, TRUE);

}
void CIEDChnGrid::ShowSMVInputChn(const SMVINPtr& smviptPtr)
{
	PINPUTCHN smviptchnitr=NULL;

	int nSize = smviptPtr->GetCount();//list_smvinputchn.size();
	CreateGrid(nSize+1,nFileSmvInChn,1);
	SetGridHead(strFileSmvInChn,nFileSmvInChn);

	//smviptchnitrB = smviptPtr->list_smvinputchn.begin();
	//smviptchnitrE = smviptPtr->list_smvinputchn.end();
	TPOS pos = smviptPtr->GetHeadPosition();
	int nRow = 1;

	while (pos != NULL)//for (smviptchnitr = smviptchnitrB; smviptchnitr != smviptchnitrE; smviptchnitr++)
	{
		smviptchnitr = (PINPUTCHN)smviptPtr->GetNext(pos);
		SetGridRowData_SMVInputChn(smviptchnitr,nRow);
		nRow++;
	}
}
void CIEDChnGrid::ShowSMVOutputChn(const SMVOUTPtr& smvoptPtr)
{
	int nSize = smvoptPtr->GetCount();//smvoutputchn.size();
	CreateGrid(nSize+1,nFileSmvOutChn,1);
	SetGridHead(strFileSmvOutChn,nFileSmvOutChn);

	std::list<CString>::iterator lstr,lstrE;
	lstr = smvoptPtr->chnAddr.begin();
	lstrE = smvoptPtr->chnAddr.end();;

	int nRow = 1;
	SMVOUTPUTCHNPtr smvoptchnPtr;
	for (; lstr != lstrE; lstr++)
	{
		smvoptchnPtr = smvoptPtr->FindByAddress((*lstr));//smvoutputchn[(*lstr)];
		SetGridRowData_SMVOutputChn(smvoptchnPtr,nRow);
		nRow++;
	}
}

void CIEDChnGrid::InitGrid(const DWORD dwPtr,const UINT showType)
{
	if (dwPtr == 0)
	{
		return;
	}

	switch (showType)
	{
	case 2:
		{
			GOOSEINPtr gseinputptr = (GOOSEINPtr)dwPtr;
			ShowGooseInputChn(gseinputptr);
		}
		break;
	case 0:
		{
			GOOSEOUTPtr gseoutputptr = (GOOSEOUTPtr)dwPtr;
			int i = 0;

			ShowGooseOutputChn(gseoutputptr);		
		}
		break;
	case 3:
		{
			SMVINPtr smvinputptr = (SMVINPtr)dwPtr;
			ShowSMVInputChn(smvinputptr);
		}
		break;
	case 1:
		{
			SMVOUTPtr smvoutputptr = (SMVOUTPtr)dwPtr;
			ShowSMVOutputChn(smvoutputptr);
		}
		break;
	default:
		DeleteAllItems();
		break;
	}

	AutoSize(FALSE, TRUE);
}