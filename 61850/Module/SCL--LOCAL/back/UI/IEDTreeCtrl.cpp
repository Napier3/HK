// D:\WorkSun\Source\61850\Module\SCL\UI\IEDTreeCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IEDTreeCtrl.h"


// CIEDTreeCtrl

IMPLEMENT_DYNAMIC(CIEDTreeCtrl, CTreeCtrl)

CIEDTreeCtrl::CIEDTreeCtrl()
{
	m_pAllIEDName = NULL;
	m_pReadFile = NULL;
	m_pClientIEDMap = NULL;
	m_pAllIEDName = NULL;
}

CIEDTreeCtrl::~CIEDTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CIEDTreeCtrl, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CIEDTreeCtrl::OnTvnSelchanged)
END_MESSAGE_MAP()



// CIEDTreeCtrl ��Ϣ�������

void CIEDTreeCtrl::UpdataIEDList(std::list<CString>& IEDList,CLIENTIEDMAP& ClientIEDMap,CThreadProgressInterface *pProgress)
{
	if (IEDList.size() <= 0 || ClientIEDMap.GetCount() <= 0 || IEDList.size() != ClientIEDMap.GetCount())
	{
		TRACE("IED�б�Ϊ�ջ������ݲ�ƥ��\r\n");
		return;
	}


	DeleteAllItems();

	if (pProgress != NULL)
	{
		pProgress->SetMaxRange(IEDList.size());
		pProgress->ResetProcess();
	}

	CString str;
	CLIENTIEDPTR IEDPtr;
	std::list<CString>::iterator strItr,strItrE;
	CScdDataBase *IEDMapItr,*IEDMapItrE;
	strItr = IEDList.begin();
	strItrE = IEDList.end();
	IEDMapItrE = NULL;//ClientIEDMap.end();

	HTREEITEM hgsData;
	UINT nSize = 0;
	UINT nSize1 = 0;
	for (; strItr != strItrE; strItr++)
	{
		nSize = 0;
		nSize = 0;
		IEDMapItr = ClientIEDMap.FindByID2(*strItr);

		if (IEDMapItr != IEDMapItrE)
		{
			IEDPtr = (CLIENTIEDPTR)IEDMapItr;//->second;
			str.Format(_T("%s:%s"),IEDPtr->iedName,IEDPtr->iedDesc);
			hgsData = InsertItem(str,1,1);

			// ����Ƿ���GOOSE����������Լ�SMV�������
			nSize = m_pReadFile->GetGooseOutSize(IEDPtr->iedName);
			if (nSize > 0)
			{
				InsertItem(g_strSclTypeTitle_GOUT,2,2,hgsData);
			}

			nSize = m_pReadFile->GetSMVOutSize(IEDPtr->iedName);
			if (nSize > 0)
			{
				InsertItem(g_strSclTypeTitle_SMVOUT,2,2,hgsData);
			}

			nSize = nSize1 = 0;
			m_pReadFile->CheckIEDSMVAndGSEInput(IEDPtr->iedName,ClientIEDMap,nSize,nSize1);

			if (nSize > 0)
			{
				InsertItem(g_strSclTypeTitle_GIN,2,2,hgsData);
			}

			if (nSize1 > 0)
			{
				InsertItem(g_strSclTypeTitle_SMVIN,2,2,hgsData);
			}

		}

		if (pProgress != NULL)
		{
			pProgress->StepIt();
		}
	}

	// ����ѡ����
	HTREEITEM hSel = GetFirstVisibleItem();
	while(hSel)
	{
		if (ItemHasChildren(hSel) != 0)
		{
			HTREEITEM hChildItem = GetChildItem(hSel);
			if(hChildItem)
			{
				Expand(hSel,TVE_EXPAND);	
				Select(hChildItem, TVGN_DROPHILITE); 
				break;
			}
		}
		hSel = GetNextVisibleItem(hSel);	
	}
}

void CIEDTreeCtrl::UpdataIEDList()
{
	m_pReadFile = NULL;
	m_pClientIEDMap = NULL;
	m_pAllIEDName = NULL;
	m_strSelIEDName.Empty();
	m_strSelGsName.Empty();
	DeleteAllItems();
}

void CIEDTreeCtrl::Filter(const CString &strFilter)
{
	if (m_pAllIEDName == NULL)
	{
		return;
	}

	// ���ұ༭������ַ���
	BOOL bEmpty = FALSE;
	CString str;

	if (strFilter.IsEmpty())
	{
		bEmpty = TRUE;
	}

	LockWindowUpdate();
	DeleteAllItems();

	CLIENTIEDPTR IEDPtr;
	CScdDataBase *showieditr,*showieditrE;

	showieditrE = NULL;//m_pClientIEDMap->end();
	std::list<CString>::iterator strItr,strItrE;
	strItr = m_pAllIEDName->begin();
	strItrE = m_pAllIEDName->end();

	HTREEITEM hgsData;
	UINT nSize = 0;
	UINT nSize1 = 0;

	for (; strItr != strItrE; strItr++)
	{
		nSize = 0;
		nSize = 0;
		showieditr = (CScdDataBase*)m_pClientIEDMap->FindByID2((*strItr));

		if (showieditr != showieditrE)
		{
			IEDPtr = (CLIENTIEDPTR)showieditr;//->second;
			str.Format(_T("%s:%s"),IEDPtr->iedName,IEDPtr->iedDesc);

			if (str.Find(strFilter) != -1 || bEmpty == TRUE)
			{
				hgsData = InsertItem(str,1,1);

				// ����Ƿ���GOOSE����������Լ�SMV�������
				nSize = m_pReadFile->GetGooseOutSize(IEDPtr->iedName);
				if (nSize > 0)
				{
					InsertItem(g_strSclTypeTitle_GOUT,2,2,hgsData);
				}

				nSize = m_pReadFile->GetSMVOutSize(IEDPtr->iedName);
				if (nSize > 0)
				{
					InsertItem(g_strSclTypeTitle_SMVOUT,2,2,hgsData);
				}

				m_pReadFile->CheckIEDSMVAndGSEInput(IEDPtr->iedName,*m_pClientIEDMap,nSize,nSize1);

				if (nSize > 0)
				{
					InsertItem(g_strSclTypeTitle_GIN,2,2,hgsData);
				}

				if (nSize1 > 0)
				{
					InsertItem(g_strSclTypeTitle_SMVIN,2,2,hgsData);
				}
			}
		}
	}


	// �����б�
	CString strIEDName,strgsName;
	HTREEITEM hChildItem,hNextItem;
	HTREEITEM hRootItem = GetRootItem();

	hNextItem = hRootItem;

	while (hNextItem)
	{
		str = GetItemText(hNextItem);
		hChildItem = GetChildItem(hNextItem);

		// ��ʾ
		if (hChildItem)
		{
			// ����ð��ǰ���IEDNAME
			int nPos = str.Find(':');
			if (nPos != -1)
			{
				strIEDName = str.Left(nPos);
				strgsName = GetItemText(hChildItem);
			}
			break;
		}

		hNextItem = GetNextItem(hNextItem,TVGN_NEXT);

	}
	UnlockWindowUpdate();
}


void CIEDTreeCtrl::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (st_IsInLoadScdXmlFile())
	{
		return;
	}

	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	DWORD   dwpos = GetMessagePos();   
	HTREEITEM hItem = GetSelectedItem();

	if (hItem)
	{
		HTREEITEM hChildItem = GetChildItem(hItem);
		CString strIEDNameAndDes,strIEDName,strgsName;
		strgsName = _T("");
		
		if (hChildItem != NULL)  // ���ӽڵ�
		{
			strIEDNameAndDes = GetItemText(hItem);	
			strgsName = GetItemText(hChildItem);
			// չ��
			Expand(hItem,TVE_EXPAND);
			Select(hChildItem, TVGN_DROPHILITE); 
		}
		else                   
		{
			// ��ø��ڵ�
			strgsName = GetItemText(hItem);
			Select(hItem, TVGN_DROPHILITE); 
			HTREEITEM hParItem = GetParentItem(hItem);
			
			if (hParItem)
			{
				strIEDNameAndDes = GetItemText(hParItem);
			}
			else
			{
				strIEDNameAndDes = strgsName;
				strgsName = _T("");
			}
		}

		// ����ð��ǰ���IEDNAME
		int nPos = strIEDNameAndDes.Find(':');

		if (nPos != -1)
		{
			strIEDName = strIEDNameAndDes.Left(nPos);
			//theApp.ShowGS(strIEDName,strgsName);
			m_strSelIEDName = strIEDName;
			m_strSelGsName = strgsName;

			CWnd *pParent = GetParent();
			pParent->PostMessage(WM_SHOW_IED_DETAIL, 0, 0);
		}
	}

	*pResult = 0;
}
