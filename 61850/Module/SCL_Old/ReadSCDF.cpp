#include "StdAfx.h"
#include "ReadSCDF.h"
#include <set>
using namespace std;

const CString NS_PREFIX = _T("ST");

#define _trim_extref_intAddr

CReadSCDF::CReadSCDF(void)
	: m_strNameSpace(_T(""))
// 	, m_xmlDTT(NULL)
// 	, m_xmlroot(NULL)
{
	m_pReadProgress = NULL;
}


CReadSCDF::~CReadSCDF(void)
{
//	Close();	
}


BOOL CReadSCDF::OpenSCDFile(LPCTSTR lpszXmlFilePath)
{
	Close();
	ShowInfor(_T("��SCL�ļ�......"));
	BOOL bRead = FALSE;
	CString xmlfilepath;
	xmlfilepath.Format(_T("%s"),lpszXmlFilePath);

	if (xmlfilepath == GetXmlFile())
	{
		bRead = FALSE;
	}else
	{
		bRead = m_xmlfile.Open(lpszXmlFilePath);
	}

	StepIt();

	if (bRead)
	{
		// ��ȡ�����ռ�
		m_xmlroot = m_xmlfile.GetRoot();
		if (m_xmlroot->IsNull() == FALSE)
		{
			m_strNameSpace = m_xmlroot->GetAttribute(_T("xmlns"));
			m_xmlfile.AddSelectionNamespace(NS_PREFIX, m_strNameSpace);
			return bRead;
		}

		return FALSE;
	}

	return bRead;
}

CString CReadSCDF::GetXmlFile(void) const
{
	return m_xmlfile.GetXmlFile();
}


void CReadSCDF::ReadCommunication(const CXmlNodePtr& CommNodePtr)
{	
	CXmlNodesPtr ConNodes;

	ShowInfor(_T("��ȡCommunication......"));
	CString strNameSpace = CommNodePtr->GetAttribute(_T("xmlns"));
	if (strNameSpace.IsEmpty())
	{
		strNameSpace = m_strNameSpace;
	}

	m_xmlfile.AddSelectionNamespace(NS_PREFIX, m_strNameSpace);
	CXmlNodes SNWNodes = CommNodePtr->SelectNodes(_T("ST:SubNetwork"));
	int nSizes = SNWNodes.GetCount();

	DWORD time = GetTickCount();

	for (int i = 0; i < nSizes; i++)
	{
		// ��ȡSubNewWork�ڵ�
		ConNodes = SNWNodes[i]->SelectNodes(_T("ST:ConnectedAP"));
		ReadSubNetWork(ConNodes);
	}

	StepIt();
	TRACE("��ȡCommunication��ʱ���%d ms \r\n",GetTickCount()-time);
}


void CReadSCDF::ReadSubNetWork(const CXmlNodesPtr& ConNodesPtr)
{
	int nSizes = ConNodesPtr->GetCount();
	CXmlNodePtr ConNodptr;

	for (int i = 0; i < nSizes; i++)
	{
		// ��ȡConnectedAP�ڵ�
		ConNodptr = ConNodesPtr->GetItem(i);
		if (ConNodptr)
		{
			ReadConnectedAP(ConNodptr);
		}
	}
}


void CReadSCDF::ReadConnectedAP(const CXmlNodePtr& ConNodePtr)
{
	CSConnectedAP oConnectedAP;//SCONNECTEDAPPtr sconapPtr(new SCONNECTEDAP);
	oConnectedAP.desc = ConNodePtr->GetAttribute(_T("desc"));
	oConnectedAP.iedName = ConNodePtr->GetAttribute(_T("iedName"));
	oConnectedAP.apName =  ConNodePtr->GetAttribute(_T("apName"));

	CXmlNodes gseDataNodes = ConNodePtr->SelectNodes(_T("ST:GSE"));
	int nSizes = gseDataNodes.GetCount();

	CString strName;
	CXmlNodePtr gsDataPtr;
	CShowIEDR *showIEDPtr = NULL;	//ShowIEDRPtr showIEDPtr;


	CShowIEDR *itr = NULL; //SHOWIEDMAP::iterator itr;
	
	for (int i = 0;  i < nSizes; i++)
	{
		CSCGSData *scgsDataPtr = new CSCGSData();//SCGSDATAPtr scgsDataPtr(new SCGSDATA);
		gsDataPtr = gseDataNodes.GetItem(i);
		ReadGSE(gsDataPtr,*scgsDataPtr);
		
		if (!scgsDataPtr->address.AppID.IsEmpty())
		{
			// ���
			itr = (CShowIEDR*)m_showiedleft.FindByID2(oConnectedAP.iedName);//itr = m_showiedleft.find(oConnectedAP.iedName);
			
			if (itr != NULL)//if (itr != m_showiedleft.end())
			{
				scgsDataPtr->strAPName = oConnectedAP.apName;
				itr->list_gooseoutput.AddTail(scgsDataPtr);//showIEDPtr->list_gooseoutput.push_back(scgsDataPtr);
				continue;
// 				showIEDPtr = itr;//showIEDPtr = itr->second;
// 
// 				if (showIEDPtr != NULL)
// 				{
// 					scgsDataPtr->strAPName = oConnectedAP.apName;
// 					showIEDPtr->list_gooseoutput.AddTail(scgsDataPtr);//showIEDPtr->list_gooseoutput.push_back(scgsDataPtr);
// 					continue;
// 				}
			}
		}
		
		delete scgsDataPtr;
	}


	gseDataNodes = ConNodePtr->SelectNodes(_T("ST:SMV"));
	nSizes = gseDataNodes.GetCount();
	
	for (int i = 0; i < nSizes; i++)
	{
		CSCGSData *scgsDataPtr = new CSCGSData;//SCGSDATAPtr scgsDataPtr(new SCGSDATA);
		gsDataPtr = gseDataNodes.GetItem(i);
		ReadSMV(gsDataPtr,*scgsDataPtr);
		if (!scgsDataPtr->address.AppID.IsEmpty())
		{
			itr = (CShowIEDR*)m_showiedleft.FindByID2(oConnectedAP.iedName);
			if (itr != NULL)//if (itr != m_showiedleft.end())
			{
				scgsDataPtr->strAPName = oConnectedAP.apName;
				itr->list_smvoutput.AddTail(scgsDataPtr);//showIEDPtr->list_smvoutput.push_back(scgsDataPtr);
				continue;
// 				showIEDPtr = itr;//showIEDPtr = itr->second;
// 
// 				if (showIEDPtr != NULL)
// 				{
// 					scgsDataPtr->strAPName = oConnectedAP.apName;
// 					showIEDPtr->list_smvoutput.AddTail(scgsDataPtr);//showIEDPtr->list_smvoutput.push_back(scgsDataPtr);
// 					continue;
// 				}
			}	
		}

		delete scgsDataPtr;
	}
	
}


void CReadSCDF::ReadGSE(const CXmlNodePtr& gsDataNodePtr,CSCGSData& scgsDataPtr)
{
	scgsDataPtr.nType = 0;

	// ����
	scgsDataPtr.cbName = gsDataNodePtr->GetAttribute(_T("cbName"));
	scgsDataPtr.ldInst = gsDataNodePtr->GetAttribute(_T("ldInst"));

	// ��ȡAddress�ڵ�
	CXmlNodePtr addressPtr = gsDataNodePtr->GetChild(_T("Address"),FALSE);
	if (!addressPtr->IsNull())
	{
		ReadAddress(addressPtr,scgsDataPtr.address);
	}


	// ��ȡMinTime��MaxTime
	CXmlNodePtr MinTimeNodePtr = gsDataNodePtr->GetChild(_T("MinTime"),FALSE);
	if(!MinTimeNodePtr->IsNull())
	{
		scgsDataPtr.MinTime = MinTimeNodePtr->GetValue();
	}

	CXmlNodePtr MaxTimeNodePtr = gsDataNodePtr->GetChild(_T("MaxTime"),FALSE);
	if(!MinTimeNodePtr->IsNull())
	{
		scgsDataPtr.MaxTime = MaxTimeNodePtr->GetValue();
	}
}


void CReadSCDF::ReadSMV(const CXmlNodePtr& gsDataPtr,CSCGSData& scgsDataPtr)
{
	scgsDataPtr.nType = 1;
	// ����
	scgsDataPtr.cbName = gsDataPtr->GetAttribute(_T("cbName"));
	scgsDataPtr.ldInst = gsDataPtr->GetAttribute(_T("ldInst"));


	// ��ȡAddress�ڵ�
	CXmlNodePtr addressPtr = gsDataPtr->GetChild(_T("Address"),FALSE);
	ReadAddress(addressPtr,scgsDataPtr.address);
}

void CReadSCDF::ReadAddress(const CXmlNodePtr& AddressNodePtr,SCGADDRESS& scgaddress)
{
	// ��ȡ�ж��ٸ�P�ڵ�
	CXmlNodes pNodes = AddressNodePtr->SelectNodes(_T("ST:P"));
	int nSizes = pNodes.GetCount();
	CString strType;
	scgaddress.AppID = _T("");
	for (int i = 0; i < nSizes; i++)
	{
		// ��ȡP��type
		strType = pNodes[i]->GetAttribute(_T("type"));
		if (strType == _T("MAC-Address"))
			scgaddress.MacAddress = pNodes[i]->GetValue();
		if (strType == _T("VLAN-ID"))
			scgaddress.VLanID = pNodes[i]->GetValue((long)0);
		if (strType == _T("VLAN-PRIORITY"))
			scgaddress.VLanpriority = pNodes[i]->GetValue();
		if (strType == _T("APPID"))
			scgaddress.AppID = pNodes[i]->GetValue();
	}
}


// ��ȡIED�Ļ�����Ϣ������IEDName��Desc
void CReadSCDF::ReadIEDNameAndDesc(const CXmlNodePtr& iedNodePtr,ShowIEDRPtr iedPtr)
{
	iedPtr->iedDesc = iedNodePtr->GetAttribute(_T("desc"));
	iedPtr->iedName = iedNodePtr->GetAttribute(_T("name"));
}


void CReadSCDF::ReadFCDA(const CXmlNodePtr& FCDANodePtr, const FCDAPtr& fcdaPtr)
{
	fcdaPtr->daName = FCDANodePtr->GetAttribute(_T("daName"));
	fcdaPtr->doName = FCDANodePtr->GetAttribute(_T("doName"));
	fcdaPtr->fc = FCDANodePtr->GetAttribute(_T("fc"));
	fcdaPtr->ldInst = FCDANodePtr->GetAttribute(_T("ldInst"));
	fcdaPtr->lnClass = FCDANodePtr->GetAttribute(_T("lnClass"));
	fcdaPtr->lnInst = FCDANodePtr->GetAttribute(_T("lnInst"));
	fcdaPtr->prefix = FCDANodePtr->GetAttribute(_T("prefix"));
}

void CReadSCDF::GetAllIEDName(std::list<CString>& IEDName)
{
	ReadNeedInfo(IEDName);
}


BOOL CReadSCDF::GetIEDNeedInfo(std::list<CString>& IEDName,CScdDataMapList &ClientIEDMap)
{
	ReadNeedInfo(IEDName);

	CScdDataMapBase *itr = NULL;   // 	SHOWIEDMAP::iterator itr,itrE;
	CGooseOut *GoosePtr = NULL;//	GOOSEOUTPtr GoosePtr;
	CSmvOut *SMVPtr = NULL;// 	SMVOUTPtr SMVPtr;
	CShowIEDR *showIEDptr = NULL;    //ShowIEDRPtr showIEDptr;
	
	CSCGSData *itrg = NULL;  //CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) itrg;
	CSCGSData *itrs = NULL;  //CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) itrs;

	ShowInfor(_T("��ȡ����......"));
	CClientIED *ClientIEDptr = NULL; //	CLIENTIEDPTR ClientIEDptr;
	
	TPOS pos = m_showiedleft.GetHeadPosition();
	//for (itr = m_showiedleft.begin(); itr != m_showiedleft.end(); itr++)
	while (pos != NULL)
	{

		itr = m_showiedleft.GetNext(pos);
		ClientIEDptr =new CClientIED();
		showIEDptr = (CShowIEDR *)itr->m_pData;

		TPOS posGout = showIEDptr->list_gooseoutput.GetHeadPosition();
		while (posGout != NULL)//for (itrg = showIEDptr->list_gooseoutput.begin(); itrg != showIEDptr->list_gooseoutput.end(); itrg++)
		{
			itrg = (CSCGSData *)showIEDptr->list_gooseoutput.GetNext(posGout);
			GoosePtr = new CGooseOut();
			GoosePtr->bRead = FALSE;
			GetSCGSData(GoosePtr->scgsData,*itrg);
			ClientIEDptr->list_gooseoutput.AddTail(GoosePtr);
		}

		TPOS posSmv = showIEDptr->list_smvoutput.GetHeadPosition();
		//for (itrs = showIEDptr->list_smvoutput.begin(); itrs != showIEDptr->list_smvoutput.end(); itrs++)
		while (posSmv != NULL)
		{
			itrs = (CSCGSData *)showIEDptr->list_smvoutput.GetNext(posSmv);
			SMVPtr = new CSmvOut();//SMVPtr = SMVOUTPtr(new SMVOUT);
			GetSCGSData(SMVPtr->scgsData,*itrs);//GetSCGSData(SMVPtr->scgsData,(*itrs));

			SMVPtr->bRead = FALSE;
			ClientIEDptr->list_smvoutput.AddTail(SMVPtr);//ClientIEDptr->list_smvoutput.push_back(SMVPtr);
		}

		ClientIEDptr->iedName = showIEDptr->iedName;
		ClientIEDptr->iedDesc = showIEDptr->iedDesc;
		ClientIEDptr->bReadIN = FALSE;
		ClientIEDptr->bReadOUT = FALSE;
		
		ClientIEDMap.AddNewMap(showIEDptr->iedName,ClientIEDptr);//ClientIEDMap.insert(make_pair(showIEDptr->iedName,ClientIEDptr));
	}

	StepIt();
	return TRUE;
}


UINT CReadSCDF::GetGooseOutSize(LPCTSTR strIEDName)
{
	CShowIEDR *itr = (CShowIEDR*)m_showiedleft.FindByID2(strIEDName);//SHOWIEDMAP::iterator itr = m_showiedleft.find(strIEDName);
	ShowIEDRPtr showIEDPtr=NULL;
	if (itr == NULL)//if (itr == m_showiedleft.end())
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return -1;
	}

	
	showIEDPtr = itr;//showIEDPtr = itr->second;

	if (showIEDPtr == NULL)
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return -1;
	}

	return showIEDPtr->list_gooseoutput.GetCount();//showIEDPtr->list_gooseoutput.size();
}

UINT CReadSCDF::GetSMVOutSize(LPCTSTR strIEDName)
{
	CShowIEDR *itr = (CShowIEDR*)m_showiedleft.FindByID2(strIEDName);//SHOWIEDMAP::iterator itr = m_showiedleft.find(strIEDName);
	ShowIEDRPtr showIEDPtr=NULL;
	if (itr == NULL)//if (itr == m_showiedleft.end())
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return -1;
	}


	showIEDPtr = itr;//showIEDPtr = itr->second;

	if (showIEDPtr == NULL)
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return -1;
	}

	return showIEDPtr->list_smvoutput.GetCount();//showIEDPtr->list_smvoutput.size();
}

BOOL CReadSCDF::ReadNeedInfo(std::list<CString>& listIEDName)
{

	// ���ȶ�ȡIED�����Ϣ
	CXmlNodePtr CommNode = m_xmlroot->GetChild(_T("Communication"),FALSE);
	if (!CommNode->IsNull())
	{
		ShowIEDRPtr iedPtr=NULL;
		CString strText,strURL;
		CXmlNodePtr sibling = CommNode->GetNextSibling();

		ShowInfor(_T("��ȡIED����������......"));
		// ���MAP
		m_showiedleft.DeleteAll();//m_showiedleft.clear();
		listIEDName.clear();
		DWORD time = GetTickCount();
		int nCount = 0;
		
		while(!sibling->IsNull())
		{
			strText = sibling->GetName();
			if (strText == _T("IED"))
			{
				strURL = sibling->GetAttribute(_T("xmlns"));
				if (strURL.IsEmpty())
				{
					strURL = m_strNameSpace;
				}

				m_xmlfile.AddSelectionNamespace(NS_PREFIX, strURL);
				iedPtr =  new CShowIEDR(); //ShowIEDRPtr(new SHOWIEDR);
				ReadIEDNameAndDesc(sibling,iedPtr);
				iedPtr->iedNodePtr = sibling;
				listIEDName.push_back(iedPtr->iedName);
				m_showiedleft.AddNewMap(iedPtr->iedName,iedPtr);//m_showiedleft.insert(make_pair(iedPtr->iedName,iedPtr));
			}

			sibling = sibling->GetNextSibling();
		}
		
		StepIt();
		TRACE("��ȡIED���������ֵ�ʱ���%d ms \r\n",GetTickCount()-time);

		// ��ȡCommunication
//		CXmlNodePtr CommNode = m_xmlroot->GetChild(_T("Communication"),FALSE);
		if (!CommNode->IsNull())
		{
			ReadCommunication(CommNode);
		}

		// ��ȡDataTypeTemplates
		m_xmlDTT = m_xmlroot->GetChild(_T("DataTypeTemplates"));
		if (m_xmlDTT->IsNull())
		{
			AfxMessageBox(_T("û�ж�ȡDataTypeTemplates"));
			return FALSE;
		}

		m_LNodeType.clear();
		m_DAType.clear();
		m_DOType.clear();

		ShowInfor(_T("��ȡ�������Ͷ���......"));
		ENUMTYPE enumtype;
		CXmlNodesPtr children =  m_xmlDTT->GetChildren();

		for (int i = 0; i < children->GetCount(); i++)
		{
			sibling = children->GetItem(i);
			strText = sibling->GetName();
			strURL = sibling->GetAttribute(_T("xmlns"));
			if (strURL.IsEmpty())
			{
				strURL = m_strNameSpace;
			}

			m_xmlfile.AddSelectionNamespace(NS_PREFIX, strURL);


			if (strText == _T("LNodeType"))
			{
				ReadLNodeType(sibling,strURL);
				m_LNodeType.insert(make_pair(strURL,sibling));
			}
			else
			{
				if (strText == _T("DOType"))
				{
					ReadDOType(sibling,strURL);
					m_DOType.insert(make_pair(strURL,sibling));
				}else
				{
					if (strText == _T("DAType"))
					{
						ReadDAType(sibling,strURL);
						m_DAType.insert(make_pair(strURL,sibling));
					}
					else
					{
						if (strText == _T("EnumType"))
						{
							ReadEnumType(sibling,&enumtype);
						}
					}
				}
			}
		}

		StepIt();
		return TRUE;
	}

	return FALSE;
}


void CReadSCDF::GetIEDGOOSEOutData(GOOSEOUTPtr gooseOutPtr,SCGSDATAPtr scgsDataPtr,const CXmlNodePtr& iedNodePtr)
{
	if (gooseOutPtr->bRead)
	{
		return;
	}

	CString strNameSpace = _T("");
	strNameSpace = iedNodePtr->GetAttribute(_T("xmlns"));

	if (strNameSpace.IsEmpty())
	{
		strNameSpace = m_strNameSpace;
	}

	m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

	CString strXPath = _T("");
	CString strTemp = _T("");
	int nType = -2;  // -2 û�в��ҵ���-1 ���ҵ�������δ֪����

	//
	strXPath.Format(_T("ST:AccessPoint[@name=\"%s\"]/ST:Server/ST:LDevice[@inst=\"%s\"]/ST:LN0"),
		scgsDataPtr->strAPName,scgsDataPtr->ldInst);

	gooseOutPtr->bSelect = FALSE;

	// ����ȡ��LN0�ڵ�
	CXmlNodePtr LN0NOdePtr = iedNodePtr->SelectSingleNode(strXPath);

	if (!LN0NOdePtr->IsNull())
	{
		// ȡGSEControl
		strXPath.Format(_T("ST:GSEControl[@name=\"%s\"]"),scgsDataPtr->cbName);
		gooseOutPtr->strgocbRef.Format(_T("%s%s/%s$GO$%s"),iedNodePtr->GetAttribute(_T("name")),
			scgsDataPtr->ldInst,LN0NOdePtr->GetAttribute(_T("lnClass")),scgsDataPtr->cbName);

		CXmlNodePtr GSENodePtr = LN0NOdePtr->SelectSingleNode(strXPath);

		if (!GSENodePtr->IsNull())
		{
			CString DataSetName = GSENodePtr->GetAttribute(_T("datSet"));
			strXPath.Format(_T("ST:DataSet[@name=\"%s\"]"),DataSetName);
			gooseOutPtr->strDataset.Format(_T("%s%s/%s$%s"),iedNodePtr->GetAttribute(_T("name")),
				scgsDataPtr->ldInst,LN0NOdePtr->GetAttribute(_T("lnClass")),DataSetName);
			gooseOutPtr->strgoID = GSENodePtr->GetAttribute(_T("appID"));
			gooseOutPtr->strVersion = GSENodePtr->GetAttribute(_T("confRev"));
			CXmlNodePtr DataSetNodePtr = LN0NOdePtr->SelectSingleNode(strXPath);
			
			if (!DataSetNodePtr->IsNull())
			{
				// ��ȡFCDA
				CXmlNodePtr DOINodePtr;
				CXmlNodePtr FCDANodePtr;
				CXmlNodePtr LNNodePtr;
				CXmlNodesPtr LNNodesPtr;
				CXmlNodePtr TempPtr,TempPtr1;
				TempPtr = TempPtr1;

				// ���ݼ�����
				gooseOutPtr->strDes = DataSetNodePtr->GetAttribute(_T("desc"));

				CXmlNodesPtr FCDANodesPtr = DataSetNodePtr->GetChildren();
				int nSizes = FCDANodesPtr->GetCount();
				FCDA oFcda;
				// ��ȡ���ڵ�
				CXmlNodePtr LDeviceNodePtr = LN0NOdePtr->GetParent();
				GOOSEOUTPUTCHNPtr gseopchnPtr;

				for (int i = 0; i < nSizes; i++)
				{
					gseopchnPtr = new GOOSEOUTPUTCHN;

					FCDANodePtr = FCDANodesPtr->GetItem(i);
					ReadFCDA(FCDANodePtr,&oFcda);
					oFcda.nIndex = i+1;
					gseopchnPtr->nIndex = i+1;
					gseopchnPtr->strAddress.Format(_T("%s/%s%s%s.%s.%s"),oFcda.ldInst,oFcda.prefix,
						oFcda.lnClass,oFcda.lnInst,oFcda.doName,
						oFcda.daName);
					// Ĭ��һ������
					gseopchnPtr->strType = _T("����");
					gseopchnPtr->nType = 0;
					gseopchnPtr->strValue = _T("FALSE");

					// ��ѯLN���,��ȡlnType.
					if (oFcda.prefix.IsEmpty())
					{
						strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"]"),oFcda.lnInst,oFcda.lnClass);
					}
					else
					{
						strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"][@prefix=\"%s\"]"),
							oFcda.lnInst,oFcda.lnClass,oFcda.prefix);
					}

					nType = -2;
//					LNNodePtr = LDeviceNodePtr->SelectSingleNode(strXPath);
					LNNodesPtr = LDeviceNodePtr->SelectNodes(strXPath);
					while(nType < 0)
					{
						for (int i = 0; i < LNNodesPtr->GetCount(); i++)
						{
							LNNodePtr = LNNodesPtr->GetItem(i);
							if(!LN0NOdePtr->IsNull())
							{
								strTemp = LNNodePtr->GetAttribute(_T("lnType"));
								gseopchnPtr->strLNDes = LNNodePtr->GetAttribute(_T("desc"));
// 								strXPath.Format(_T("ST:DOI[@name=\"%s\"]/ST:DAI[@name=\"%s\"]"),fcdaPtr->doName,fcdaPtr->daName);
// 								TempPtr = LNNodePtr->SelectSingleNode(strXPath);

								strXPath.Format(_T("ST:DOI[@name=\"%s\"]"),oFcda.doName);
								DOINodePtr = LNNodePtr->SelectSingleNode(strXPath);

								if (!DOINodePtr->IsNull())
								{
									// ��ȡDOI name
									gseopchnPtr->strDOIDes = DOINodePtr->GetAttribute(_T("desc"));
									strXPath.Format(_T("ST:DAI[@name=\"%s\"]"),oFcda.daName);
									TempPtr = DOINodePtr->SelectSingleNode(strXPath);
//									if (!TempPtr->IsNull())
									{
										// ����DO��ȡ��type
										strXPath.Format(_T("%s.%s"),strTemp,oFcda.lnClass);
										TempPtr = m_LNodeType[strXPath];
										if (!TempPtr->IsNull())
										{
											strNameSpace = TempPtr->GetAttribute(_T("xmlns"));
											if (strNameSpace.IsEmpty())
											{
												strNameSpace = m_strNameSpace;
											}

											m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

											strXPath.Format(_T("ST:DO[@name=\"%s\"]"),oFcda.doName);
											TempPtr1 = TempPtr->SelectSingleNode(strXPath);
											if (!TempPtr1->IsNull())
											{
												strTemp = TempPtr1->GetAttribute(_T("type"));

												// ����DOtype
												TempPtr = m_DOType[strTemp];
												if (!TempPtr->IsNull())
												{
													strNameSpace = TempPtr->GetAttribute(_T("xmlns"));
													if (strNameSpace.IsEmpty())
													{
														strNameSpace = m_strNameSpace;
													}

													m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

													strXPath.Format(_T("ST:DA[@name=\"%s\"]"),oFcda.daName);
													TempPtr1 = TempPtr->SelectSingleNode(strXPath);
													if (!TempPtr1->IsNull())
													{
														//DWORD dwType;
														nType = -1;
														strTemp = TempPtr1->GetAttribute(_T("bType"));
														if(strTemp==_T("BOOLEAN")||strTemp==_T("BOOL"))
														{
															//dwType=0x83;
															gseopchnPtr->strType = _T("����");
															gseopchnPtr->nType = 0;
															gseopchnPtr->strValue = _T("FALSE");
														}
														else if(strTemp==_T("Dbpos")||strTemp==_T("BIT_STRING"))	
														{
															//dwType=0x84;														
															gseopchnPtr->strType = _T("˫��");
															gseopchnPtr->strValue = _T("01");
															gseopchnPtr->nType = 1;
														}
														else if(strTemp==_T("Enum"))
														{
															//dwType=0x85;	
															gseopchnPtr->strType = _T("ö��");
														}
														else if(strTemp==_T("INT32"))	
														{
															//dwType=0x85;															
															gseopchnPtr->strType = _T("INT32");
														}
														else if(strTemp==_T("INT32U")||strTemp==_T("UINT"))		
														{
															//dwType=0x86;															
															gseopchnPtr->strType = _T("INT32U");
														}
														else if(strTemp==_T("Timestamp")||strTemp==_T("TIMESTAMP"))		
														{
															//dwType=0x91;	
															gseopchnPtr->strType = _T("ʱ��");
															gseopchnPtr->nType = 2;
															gseopchnPtr->strValue = _T("");

														}
														else if(strTemp==_T("FLOAT32"))	
														{
															//dwType=0x07;															
															gseopchnPtr->strType = _T("����");
															gseopchnPtr->strValue = _T("0.0000");
															gseopchnPtr->nType = 4;
														}
														else if(strTemp==_T("STRUCT"))
														{
															//dwType=0xa2;
															gseopchnPtr->strType = _T("�ṹ");
															gseopchnPtr->nType = 6;
														}
														else if(strTemp == _T("Quality"))
														{
															gseopchnPtr->strType = _T("Ʒ��");
															gseopchnPtr->strValue = _T("0X0000");
															gseopchnPtr->nType = 3;
														}

														nType = 0;;
														break;
													}
												}
											}
										}

									}
								}
							}

						}

						if (nType <= -2)
						{
							strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"][@prefix=\"%s\"]"),
								oFcda.lnInst,oFcda.lnClass,oFcda.prefix);
							LNNodesPtr = LDeviceNodePtr->SelectNodes(strXPath);
							nType++;
						}else
						{
							break;
						}
					}
					
					gooseOutPtr->chnAddr.push_back(gseopchnPtr->strAddress);
					gooseOutPtr->AddTail(gseopchnPtr);//gooseOutPtr->gseoutputchn.insert(make_pair(gseopchnPtr->strAddress,gseopchnPtr));
				}

				gooseOutPtr->bRead = TRUE;
			}
		}

		// ��ȡSCGSDATA
		GetSCGSData(gooseOutPtr->scgsData,*scgsDataPtr);
		
	}

}


BOOL CReadSCDF::GetIEDSMVOutData(const SMVOUTPtr& smvOutPtr,const SCGSDATAPtr scgsDataPtr,const CXmlNodePtr& iedNodePtr)
{
	if (smvOutPtr->bRead)
	{
		return TRUE;
	}

	CString strNameSpace = _T("");
	strNameSpace = iedNodePtr->GetAttribute(_T("xmlns"));
	if (strNameSpace.IsEmpty())
	{
		strNameSpace = m_strNameSpace;
	}

	m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

	CString strXPath = _T("");
	CString strTemp = _T("");

	int nType = -2;

	//
	strXPath.Format(_T("ST:AccessPoint[@name=\"%s\"]/ST:Server/ST:LDevice[@inst=\"%s\"]/ST:LN0"),
		smvOutPtr->scgsData.strAPName,smvOutPtr->scgsData.ldInst);

	smvOutPtr->bSelect = FALSE;

	// ����ȡ��LN0�ڵ�
	CXmlNodePtr LN0NodePtr = iedNodePtr->SelectSingleNode(strXPath);

	if (!LN0NodePtr->IsNull())
	{
		// ȡSampledValueControl
		strXPath.Format(_T("ST:SampledValueControl[@name=\"%s\"]"),smvOutPtr->scgsData.cbName);

		CXmlNodePtr SMVNodePtr = LN0NodePtr->SelectSingleNode(strXPath);
		if (!SMVNodePtr->IsNull())
		{
			CString DataSetName = SMVNodePtr->GetAttribute(_T("datSet"));
			strXPath.Format(_T("ST:DataSet[@name=\"%s\"]"),DataSetName);;
			CXmlNodePtr DataSetNodePtr = LN0NodePtr->SelectSingleNode(strXPath);
			smvOutPtr->strVersion = SMVNodePtr->GetAttribute(_T("confRev"));
			smvOutPtr->strsmvID = SMVNodePtr->GetAttribute(_T("smvID"));
			if (!DataSetNodePtr->IsNull())
			{
				// ��ȡFCDA
				CXmlNodePtr DOINodePtr;
				CXmlNodePtr FCDANodePtr;
				CXmlNodePtr LNNodePtr;
				CXmlNodesPtr LNNodesPtr;
				CXmlNodePtr TempPtr,TempPtr1;
				TempPtr = TempPtr1;

				CXmlNodesPtr FCDANodesPtr = DataSetNodePtr->GetChildren();
				int nSizes = FCDANodesPtr->GetCount();
				FCDA oFcda;
				// ��ȡ���ڵ�
				CXmlNodePtr LDeviceNodePtr = LN0NodePtr->GetParent();
				SMVOUTPUTCHNPtr smvopchnPtr;
				for (int i = 0; i < nSizes; i++)
				{
					smvopchnPtr = new SMVOUTPUTCHN;
					FCDANodePtr = FCDANodesPtr->GetItem(i);
					ReadFCDA(FCDANodePtr,&oFcda);
					oFcda.nIndex = i+1;
					smvopchnPtr->nIndex = i+1;
					// ��ַ
					smvopchnPtr->strAddress.Format(_T("%s/%s%s%s.%s.%s"),oFcda.ldInst,oFcda.prefix,
						oFcda.lnClass,oFcda.lnInst,oFcda.doName,
						oFcda.daName);

					// lnClass�Ƿ���LLN0
					if (oFcda.lnClass == _T("LLN0"))
					{
						// ��ѯLN0�ڵ�
						strXPath.Format(_T("ST:DOI[@name=\"%s\"]"),oFcda.doName);
						smvopchnPtr->strLNDes = LN0NodePtr->GetAttribute(_T("desc"));

						DOINodePtr = LN0NodePtr->SelectSingleNode(strXPath);
						if (!DOINodePtr->IsNull())
						{
							smvopchnPtr->strDOIDes = DOINodePtr->GetAttribute(_T("desc"));
						}
					}
					else
					{
						// ��ѯLN�ڵ�,

						if (oFcda.prefix.IsEmpty())
						{
							strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"]"),oFcda.lnInst,oFcda.lnClass);
						}else
						{
							strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"][@prefix=\"%s\"]"),
								oFcda.lnInst,oFcda.lnClass,oFcda.prefix);
						}


						nType = -2;
//						LNNodePtr = LDeviceNodePtr->SelectSingleNode(strXPath);
						LNNodesPtr = LDeviceNodePtr->SelectNodes(strXPath);

						while(nType < 0)
						{
							for (int i = 0; i < LNNodesPtr->GetCount(); i++)
							{
								LNNodePtr = LNNodesPtr->GetItem(i);

								if (!LNNodePtr->IsNull())
								{
									// ��ȡLN����
									smvopchnPtr->strLNDes = LNNodePtr->GetAttribute(_T("desc"));
									strXPath.Format(_T("ST:DOI[@name=\"%s\"]"),oFcda.doName);
									DOINodePtr = LNNodePtr->SelectSingleNode(strXPath);

									if (!DOINodePtr->IsNull())
									{
										smvopchnPtr->strDOIDes = DOINodePtr->GetAttribute(_T("desc"));
										nType = 0;
										break;
									}

								}
							}

							if (nType <= -2)
							{
								strXPath.Format(_T("ST:LN[@inst=\"%s\"][@lnClass=\"%s\"][@prefix=\"%s\"]"),
									oFcda.lnInst,oFcda.lnClass,oFcda.prefix);
								LNNodesPtr = LDeviceNodePtr->SelectNodes(strXPath);
							}
							else
							{
								break;
							}

							nType++;
						}
					}

					smvOutPtr->chnAddr.push_back(smvopchnPtr->strAddress);
					smvOutPtr->AddTail(smvopchnPtr);	//smvOutPtr->smvoutputchn.insert(make_pair(smvopchnPtr->strAddress,smvopchnPtr));	
				}

				smvOutPtr->bRead = TRUE;
			}
		}

		// ��ȡSCGSDATA
		GetSCGSData(smvOutPtr->scgsData,*scgsDataPtr);
	}

	return TRUE;
}



void CReadSCDF::ReadExtRef(const CXmlNodePtr& ExtRefNodePtr, EXTREFPtr extrefPtr)
{
	extrefPtr->daName = ExtRefNodePtr->GetAttribute(_T("daName"));
	extrefPtr->doName = ExtRefNodePtr->GetAttribute(_T("doName"));
	extrefPtr->iedName = ExtRefNodePtr->GetAttribute(_T("iedName"));
	extrefPtr->intAddr = ExtRefNodePtr->GetAttribute(_T("intAddr"));
	extrefPtr->ldInst = ExtRefNodePtr->GetAttribute(_T("ldInst"));
	extrefPtr->lnClass = ExtRefNodePtr->GetAttribute(_T("lnClass"));
	extrefPtr->lnInst = ExtRefNodePtr->GetAttribute(_T("lnInst"));
	extrefPtr->prefix = ExtRefNodePtr->GetAttribute(_T("prefix"));
}


void CReadSCDF::CheckIEDSMVAndGSEInput(LPCTSTR strIEDName,CScdDataMapList &ClientMap, UINT& nGSE,UINT& nSMV)
{
	CGooseOutputChn* GSEMapItr;//GSEOUTPUTMAP::iterator GSEMapItr;
	CSMVOutputChn* SMVMapItr;//SMVOUTPUTMAP::iterator SMVMapItr;

	CString strNameSpace = _T("");

	CLIENTIEDPTR ClientPtr;
	CShowIEDR * itr = (CShowIEDR *)m_showiedleft.FindByID2(strIEDName);
	ShowIEDRPtr sIEDPtr;
	ShowIEDRPtr sTempIEDPtr;
	if (itr == NULL)//m_showiedleft.end())
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return;
	}


	sIEDPtr = itr;//->second;

	if (sIEDPtr == NULL)
	{
		TRACE("�Ҳ�����ǰIED\r\n");
		return;
	}
	strNameSpace = sIEDPtr->iedNodePtr->GetAttribute(_T("xmlns"));

	if (strNameSpace.IsEmpty())
	{
		strNameSpace = m_strNameSpace;
	}

	m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

	// ��ȡInputs
	CString strXPath = _T("");
	strXPath.Format(_T("ST:AccessPoint"));
	CXmlNodesPtr NodeSPtr,NodesPtr1,NodesPtr2;
	CXmlNodePtr TempNodePtr1,TempNodePtr2,TempNodePtr3;

	EXTREF extrefPtr;
	NodeSPtr = sIEDPtr->iedNodePtr->SelectNodes(strXPath);
	UINT nSize1,nSize2;
	nSize1 = NodeSPtr->GetCount();
	nGSE = nSMV = 0;


	int nPos = 0;
	CString strText;
	CSCGSData *scgsItr = NULL;//CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) scgsItr;
	CGooseOut *itrgo,*itrgoE;//CONTAINER_LIST_TYPE_ITERATOR(GOOSEOUT) itrgo,itrgoE;
	CSmvOut *itrsm,*itrsmE; //CONTAINER_LIST_TYPE_ITERATOR(SMVOUT) itrsm,itrsmE; 

	UINT i = 0;

	for (i = 0; i < nSize1 && (nGSE == 0 || nSMV == 0); i++)
	{
		TempNodePtr1 = NodeSPtr->GetItem(i);
		strXPath.Format(_T("ST:Server/ST:LDevice"));
		NodesPtr1 = TempNodePtr1->SelectNodes(strXPath);
		nSize2 = NodesPtr1->GetCount();
	
		for (UINT j = 0; j < nSize2 && (nGSE == 0 || nSMV == 0); j++)
		{
			TempNodePtr2 = NodesPtr1->GetItem(j);  //LDevice
			strXPath.Format(_T("ST:LN0/ST:Inputs/ST:ExtRef"));
			NodesPtr2 = TempNodePtr2->SelectNodes(strXPath);
			int nSize3 = NodesPtr2->GetCount();
	
			for (int k = 0; k < nSize3 && (nGSE == 0 || nSMV == 0); k++)
			{
				//  ����ExtRef�ڵ�,��ȡ
				TempNodePtr3 = NodesPtr2->GetItem(k);
				ReadExtRef(TempNodePtr3,&extrefPtr);//extrefPtr);
				// �ж�Inputs�ڵ�ĵ�һ���ӽڵ���GOOSE����SMV��
				// ���µ��ӽڵ����һ���ӽڵ���ͬ������

				/************************************************************************/
				/* 2012-05-16 ��ȡ��ʽ�ı䣬      */
				/************************************************************************/

// 				if (extrefPtr->ldInst == _T("") || extrefPtr->lnClass == _T("") || 
// 					/*extrefPtr->lnInst == _T("") ||*/ extrefPtr->iedName == _T(""))
				if (extrefPtr.ldInst == _T("") || extrefPtr.lnClass == _T("") || 
					/*extrefPtr->lnInst == _T("") ||*/ extrefPtr.iedName == _T(""))
				{
					ClientPtr = NULL;
				}
				else
				{
					// ��������IED
					strText.Format(_T("%s/%s%s%s.%s.%s"),extrefPtr.ldInst,extrefPtr.prefix,
						extrefPtr.lnClass,extrefPtr.lnInst,extrefPtr.doName,extrefPtr.daName);
					ClientPtr = (CLIENTIEDPTR)ClientMap.FindByID2(extrefPtr.iedName);//[extrefPtr->iedName];
				}

				if (ClientPtr != NULL)
				{
					// ����GOOSE
					TPOS posgo = ClientPtr->list_gooseoutput.GetHeadPosition();// itrgo = ClientPtr->list_gooseoutput.begin();
					itrgoE = NULL;//ClientPtr->list_gooseoutput.end();

					TPOS possm = ClientPtr->list_smvoutput.GetHeadPosition();//itrsm = ClientPtr->list_smvoutput.begin();
					itrsmE = NULL;//ClientPtr->list_smvoutput.end();

					//for (;itrgo != itrgoE && nGSE == 0; itrgo++)
					while (posgo != NULL && nGSE == 0)
					{
						itrgo = (CGooseOut*)ClientPtr->list_gooseoutput.GetNext(posgo);
						
						// �ҵ���Ӧ��GOOSE���
						if (itrgo->scgsData.ldInst == extrefPtr.ldInst)
						{
							// ��ȡ
							if (itrgo->bRead == FALSE)
							{
								nPos = ClientPtr->list_gooseoutput.FindIndex(itrgo);//distance(ClientPtr->list_gooseoutput.begin(),itrgo);
								sTempIEDPtr = (ShowIEDRPtr)m_showiedleft.FindByID2(ClientPtr->iedName);//[ClientPtr->iedName];
								scgsItr = (CSCGSData*)sTempIEDPtr->list_gooseoutput.GetAtIndex(nPos);//sTempIEDPtr->list_gooseoutput.begin();
								//advance(scgsItr,nPos);
								GetIEDGOOSEOutData(itrgo,scgsItr,sTempIEDPtr->iedNodePtr);//GetIEDGOOSEOutData(*itrgo,(*scgsItr),sTempIEDPtr->iedNodePtr);
							}

							GSEMapItr = itrgo->FindByAddress(strText);//itrgo->gseoutputchn.find(strText);

							// �ҵ���Ӧ�����ͨ��
							//if (GSEMapItr != itrgo->gseoutputchn.end() && GSEMapItr->second != NULL)
							if (GSEMapItr != NULL)
							{
								nGSE = 1;
								break;
							}

						}
					}


					// ����SMV
					//for (; itrsm != itrsmE && nSMV == 0; itrsm++)
					while (possm != NULL && nSMV == 0)
					{
						itrsm = (CSmvOut *)ClientPtr->list_smvoutput.GetNext(possm);
						// �ҵ���Ӧ��SMV���
						if (itrsm->scgsData.ldInst == extrefPtr.ldInst)
						{
							// �жϴ˿��ƿ��Ƿ��Ѿ���ȡ
							if (itrsm->bRead == FALSE)
							{
								// ��ȡ
								nPos = ClientPtr->list_smvoutput.FindIndex(itrsm);//distance(ClientPtr->list_smvoutput.begin(),itrsm);
								sTempIEDPtr = (ShowIEDRPtr)m_showiedleft.FindByID2(ClientPtr->iedName);//[ClientPtr->iedName];
								scgsItr = (CSCGSData*)sTempIEDPtr->list_smvoutput.GetAtIndex(nPos);//begin();
								//advance(scgsItr,nPos);

								GetIEDSMVOutData(itrsm,scgsItr,sTempIEDPtr->iedNodePtr);
							}

							SMVMapItr = itrsm->FindByAddress(strText);

							// �ҵ���Ӧ�����ͨ��
							if (SMVMapItr != NULL)
							{
								nSMV = TRUE;
								break;
							}
						}
					}
				}
			}
		}
	}

}

void CReadSCDF::GetIEDInData(LPCTSTR strIEDName,CScdDataMapList &ClientMap)
{

	// ��ȡ����LDevice�µ�Inputs�ڵ�,��ѯ�ڲ��ź�����,���ڶ�ȡInputs�µ�ExtRef�ڵ�ʱ����֪�˽ڵ��Ƿ���SMV���뻹��GOOSE����
	// ����SMV��GOOSEһ�����

	typedef CScdDataMapList STRINPUTCHN;//typedef map<CString, SHARED_PTR(INPUTCHN)> STRINPUTCHN;
	CScdDataMapBase *StrInputItr=NULL;//STRINPUTCHN::iterator StrInputItr;
	GOOSEOUTPUTCHN *GSEMapItr=NULL;//GSEOUTPUTMAP::iterator GSEMapItr;
	SMVOUTPUTCHN *SMVMapItr=NULL;//SMVOUTPUTMAP::iterator SMVMapItr;


	CString strNameSpace = _T("");
	ShowIEDRPtr sTempIEDPtr=NULL;
	CLIENTIEDPTR ClientPtr=NULL;
	CLIENTIEDPTR ClientIPtr = (CLIENTIEDPTR)ClientMap[strIEDName];


	// �ж��Ƿ��Ѿ���ȡ��GOOSEIN��SMVIN
	if (ClientIPtr->bReadIN)
	{
		TRACE("��IEC��IN�Ѿ���ȡ\r\n");
		return;
	}

	ClientIPtr->bReadIN = TRUE;

	CShowIEDR * itr = (CShowIEDR*)m_showiedleft.FindByID2(strIEDName);
	ShowIEDRPtr sIEDPtr=NULL;
	if (itr == NULL)//m_showiedleft.end())
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return;
	}


	sIEDPtr = itr;//->second;

	if (sIEDPtr == NULL)
	{
		TRACE("�Ҳ�����ǰIED\r\n");
		return;
	}

	strNameSpace = sIEDPtr->iedNodePtr->GetAttribute(_T("xmlns"));
	if (strNameSpace.IsEmpty())
	{
		strNameSpace = m_strNameSpace;
	}

	m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);

	// ��ȡInputs
	int nType = -1; // -1 ûȷ�����ͣ�0---SMV 1---GOOSE
	int nPos = 0;
	CString strXPath = _T("");
	CString ldInst = _T("");
	CString addr = _T("");
	CString addr1,addr2,addr3;
	strXPath.Format(_T("ST:AccessPoint"));
	CXmlNodesPtr NodeSPtr,NodesPtr1,NodesPtr2;
	CXmlNodePtr TempNodePtr1,TempNodePtr2,TempNodePtr3;

	EXTREF extrefPtr;
	NodeSPtr = sIEDPtr->iedNodePtr->SelectNodes(strXPath);
	UINT nSize1,nSize2,nSize3,nSize4,nSize5;
	nSize1 = NodeSPtr->GetCount();

	if (nSize1 > 0)
	{
		CString strText;
		CXmlNodePtr doiNodePtr;
		CXmlNodePtr daiNodePtr;
		CXmlNodesPtr daiNodesPtr;
		CXmlNodesPtr doiNodesPtr;

		PSCGSDATA scgsItr;//CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) scgsItr;

		int nPos = 0;
		int nPos2 = 0;
		STRINPUTCHN inchMapList;
		INPUTCHNPtr inputPtr=NULL;
		CScdDataList listInputChn;//CONTAINER_LIST_TYPE(INPUTCHN) listInputChn;
		CScdDataList listInputChnUse;//CONTAINER_LIST_TYPE(INPUTCHN) listInputChn;

		for (UINT i = 0; i < nSize1; i++)
		{
			TempNodePtr1 = NodeSPtr->GetItem(i);
			strXPath.Format(_T("ST:Server/ST:LDevice"));
			m_xmlfile.AddSelectionNamespace(NS_PREFIX,strNameSpace);
			NodesPtr1 = TempNodePtr1->SelectNodes(strXPath);
			nSize2 = NodesPtr1->GetCount();

			for (UINT j = 0; j < nSize2; j++)
			{
				TempNodePtr2 = NodesPtr1->GetItem(j);  //LDevice
				ldInst = TempNodePtr2->GetAttribute(_T("inst"));
				strXPath.Format(_T("ST:LN0/ST:Inputs/ST:ExtRef"));
				NodesPtr2 = TempNodePtr2->SelectNodes(strXPath);
				nSize3 = NodesPtr2->GetCount();

				if (nSize3 > 0)
				{
					listInputChn.RemoveAll();//listInputChn.clear();
					listInputChnUse.RemoveAll();//listInputChn.clear();
					inchMapList.DeleteAllOnllyMap();//sti1.clear();

					nType = -1;
					//  ����ExtRef�ڵ�,��ȡ
					for (UINT k = 0; k < nSize3; k++)
					{
						inputPtr = new INPUTCHN;//inputPtr = INPUTCHNPtr(new INPUTCHN);
						TempNodePtr3 = NodesPtr2->GetItem(k);
						//extrefPtr = EXTREFPtr(new EXTREF);
						ReadExtRef(TempNodePtr3,&extrefPtr);
						inputPtr->strIntAddress = extrefPtr.intAddr;
						eq_EXTREF(extrefPtr, inputPtr->extrefPtr) ;
#ifdef _trim_extref_intAddr
						// �����ַ����ĵڶ����㣬ȡ��ǰ���ַ���
						nPos = extrefPtr.intAddr.Find(_T('.'));
						if (nPos != -1)
						{
							nPos2 = extrefPtr.intAddr.Find(_T('.'),nPos+1);
						}

						if (nPos2 != -1)
						{
							extrefPtr.intAddr = extrefPtr.intAddr.Left(nPos2);
						}
#endif
						inchMapList.AddNewMap(extrefPtr.intAddr,inputPtr);//sti1.insert(make_pair(extrefPtr.intAddr,inputPtr));
						listInputChn.AddTail(inputPtr); //push_back(inputPtr);
					}


					// ��ȡ��LDevice�µ�LN�ڵ�Ƚϣ�ȡ���ڲ��ź�����
					strXPath.Format(_T("ST:LN"));
					NodesPtr2 = TempNodePtr2->SelectNodes(strXPath);
					strText = TempNodePtr2->GetAttribute(_T("inst"));

					nSize3 = NodesPtr2->GetCount();
					if(nSize3 > 0)
					{
						//
						for (UINT k = 0; k < nSize3; k++)
						{
							addr = _T("");
							addr += ldInst;
							addr += _T("/");
							TempNodePtr3 = NodesPtr2->GetItem(k);
							addr += TempNodePtr3->GetAttribute(_T("prefix"));
							addr += TempNodePtr3->GetAttribute(_T("lnClass"));
							addr += TempNodePtr3->GetAttribute(_T("inst"));

							doiNodesPtr = TempNodePtr3->SelectNodes(_T("ST:DOI"));
							nSize4 = doiNodesPtr->GetCount();
							for (UINT m = 0; m < nSize4; m++ )
							{
								doiNodePtr = doiNodesPtr->GetItem(m);

								addr1 = addr;
								strText = doiNodePtr->GetAttribute(_T("desc"));

								addr1 += _T(".");
								addr1 += doiNodePtr->GetAttribute(_T("name"));

								StrInputItr = inchMapList.FindByID(addr1);
								if (StrInputItr != NULL)//if (StrInputItr != sti1.end())
								{
									inputPtr = (INPUTCHNPtr)StrInputItr->m_pData;//inputPtr = StrInputItr->second;
									inputPtr->strIntSigDes = strText;
								}
								else
								{
									// DAI
									daiNodesPtr = doiNodePtr->SelectNodes(_T("ST:DAI"));
									nSize5 = daiNodesPtr->GetCount();
									for (UINT n = 0; n < nSize5; n++ )
									{	
										addr2 = addr1;
										daiNodePtr = daiNodesPtr->GetItem(n);
										addr2 += _T(".");
										addr2 += daiNodePtr->GetAttribute(_T("name"));

										StrInputItr = inchMapList.FindByID(addr2);
										if (StrInputItr != NULL)//sti1.end())
										{
											inputPtr = (INPUTCHNPtr)StrInputItr->m_pData;//inputPtr = StrInputItr->second;
											inputPtr->strIntSigDes = strText;
											// �ҵ��˳�
											n = nSize5;
										}
									}
								}

							}
						}
					}

					// �������
					PINPUTCHN pInCh=NULL,itrE=NULL;//CONTAINER_LIST_TYPE_ITERATOR(INPUTCHN) itr,itrE;
					PGOOSEOUT itrgo=NULL,itrgoE=NULL;//CONTAINER_LIST_TYPE_ITERATOR(GOOSEOUT) itrgo,itrgoE;
					PSMVOUT itrsm=NULL,itrsmE=NULL; //CONTAINER_LIST_TYPE_ITERATOR(SMVOUT) itrsm,itrsmE; 
					PGOOSEIN itrIn=NULL,itrInE=NULL;//CONTAINER_LIST_TYPE_ITERATOR(GOOSEIN) itrIn,itrInE;
					PSMVIN itrIns=NULL,itrInsE=NULL;//CONTAINER_LIST_TYPE_ITERATOR(SMVIN) itrIns,itrInsE;
					GOOSEOUTPUTCHNPtr gsechnPtr=NULL;
					SMVOUTPUTCHNPtr smvchnPtr=NULL;
					TPOS posE = listInputChn.GetHeadPosition();
					

					// �ж�Inputs�ڵ�ĵ�һ���ӽڵ���GOOSE����SMV��
					// ���µ��ӽڵ����һ���ӽڵ���ͬ������
					//for (; itr != itrE; itr++)
					while (posE != NULL)
					{
						BOOL b_pInCh_use = FALSE;
						pInCh = (PINPUTCHN)listInputChn.GetNext(posE);
						// ��������IED
						nType = -1;
						strText.Format(_T("%s/%s%s%s.%s.%s"),pInCh->extrefPtr.ldInst,pInCh->extrefPtr.prefix,
							pInCh->extrefPtr.lnClass,pInCh->extrefPtr.lnInst,pInCh->extrefPtr.doName,
							pInCh->extrefPtr.daName);
						ClientPtr = (CLIENTIEDPTR)ClientMap[pInCh->extrefPtr.iedName];

						if (ClientPtr != NULL)
						{
							// ����GOOSE
							TPOS posgo=ClientPtr->list_gooseoutput.GetHeadPosition();
							TPOS possm = ClientPtr->list_smvoutput.GetHeadPosition();

							if (nType == -1 || nType == 0)
							{
								while (posgo != NULL)
								{
									itrgo = (PGOOSEOUT)ClientPtr->list_gooseoutput.GetNext(posgo);
									// �ҵ���Ӧ��GOOSE���
									if (itrgo->scgsData.ldInst == pInCh->extrefPtr.ldInst)
									{
										// ��ȡ
										if (itrgo->bRead == FALSE)
										{
											nPos = ClientPtr->list_gooseoutput.FindIndex(itrgo);//distance(ClientPtr->list_gooseoutput.begin(),itrgo);
											sTempIEDPtr = (ShowIEDRPtr)m_showiedleft[ClientPtr->iedName];
											//scgsItr = sTempIEDPtr->list_gooseoutput.begin();
											//advance(scgsItr,nPos);
											scgsItr = (PSCGSDATA)sTempIEDPtr->list_gooseoutput.GetAtIndex(nPos);

											GetIEDGOOSEOutData(itrgo,scgsItr,sTempIEDPtr->iedNodePtr);
										}
									
										GSEMapItr = itrgo->FindByAddress(strText);//itrgo->gseoutputchn.find(strText);

										// �ҵ���Ӧ�����ͨ��
										//if (GSEMapItr != itrgo->gseoutputchn.end() && GSEMapItr->second != NULL)
										if (GSEMapItr != NULL)
										{
											gsechnPtr = GSEMapItr;//->second;

											pInCh->strExtSigAddress = gsechnPtr->strAddress;
											pInCh->strExtSigDes = gsechnPtr->strDOIDes;
											pInCh->nExtSigIndex = gsechnPtr->nIndex;

											// �Ƿ���Ҫ����GOOSE IN���ƿ�
											TPOS posIn = ClientIPtr->list_gooseinput.GetHeadPosition();
											//itrIn = ClientIPtr->list_gooseinput.begin();
											//itrInE = ClientIPtr->list_gooseinput.end();
											while (posIn != NULL)//for (; itrIn != itrInE; itrIn++)
											{
												itrIn = (PGOOSEIN)ClientIPtr->list_gooseinput.GetNext(posIn);
												// �ж��Ƿ���ͬһ��GOOSE IN���ƿ�
												if (itrIn->strAppID == itrgo->scgsData.address.AppID 
													&& itrIn->strOutputIEDName == pInCh->extrefPtr.iedName
													&& itrIn->strMac == itrgo->scgsData.address.MacAddress)
												{
													itrIn->AddTail(pInCh);//itrIn->list_gseinputchn.push_back(*itr);
													b_pInCh_use = TRUE;
													itrgo = itrgoE;
													itrgo--;
													nType = 0;
													itrsm = itrsmE;
													break;
												}
											}

											// ����
											if (itrIn == itrInE)
											{
												PGOOSEIN gipPtr = new CGooseIn();//GOOSEIN SHARED_PTR(GOOSEIN) gipPtr(new GOOSEIN);
												gipPtr->AddTail(pInCh);////gipPtr->list_gseinputchn.push_back(*itr);
												b_pInCh_use = TRUE;
												gipPtr->bSelect = FALSE;
												gipPtr->strAppID = itrgo->scgsData.address.AppID ;
												gipPtr->strMac = itrgo->scgsData.address.MacAddress;
												gipPtr->strOutputIEDName = ClientPtr->iedName;
												gipPtr->strOutputIEDDesc = ClientPtr->iedDesc;
												gipPtr->strDes = itrgo->strDes;
												gipPtr->nChnCount = itrgo->GetCount();//itrgo->gseoutputchn.size();
												gipPtr->strgocbRef = itrgo->strgocbRef;
												gipPtr->strDataSet = itrgo->strDataset;
												gipPtr->strgoID = itrgo->strgoID;
												ClientIPtr->list_gooseinput.AddTail(gipPtr);//ClientIPtr->list_gooseinput.push_back(gipPtr);
											}
										}
									}
								}
							}


							// ����SMV
							if (nType == -1 || nType == 1)
							{
								possm = ClientPtr->list_smvoutput.GetHeadPosition();
								while (possm != NULL)//for (; itrsm != itrsmE; itrsm++)
								{
									itrsm = (PSMVOUT)ClientPtr->list_smvoutput.GetNext(possm);

									// �ҵ���Ӧ��SMV���
									if (itrsm->scgsData.ldInst == pInCh->extrefPtr.ldInst)
									{
										// �жϴ˿��ƿ��Ƿ��Ѿ���ȡ
										if (itrsm->bRead == FALSE)
										{
											// ��ȡ
											nPos = ClientPtr->list_smvoutput.FindIndex(itrsm); //distance(ClientPtr->list_smvoutput.begin(),itrsm);
											sTempIEDPtr = (ShowIEDRPtr)m_showiedleft[ClientPtr->iedName];
											//scgsItr = sTempIEDPtr->list_smvoutput.begin();
											//advance(scgsItr,nPos);
											scgsItr = (PSCGSDATA)sTempIEDPtr->list_smvoutput.GetAtIndex(nPos);

											GetIEDSMVOutData(itrsm,scgsItr,sTempIEDPtr->iedNodePtr);
										}


										SMVMapItr = itrsm->FindByAddress(strText);//itrsm->smvoutputchn.find(strText);

										// �ҵ���Ӧ�����ͨ��
										if (SMVMapItr != NULL)// itrsm->smvoutputchn.end() && SMVMapItr->second != NULL)
										{
											smvchnPtr = SMVMapItr;//->second;

											pInCh->strExtSigAddress = smvchnPtr->strAddress;
											pInCh->strExtSigDes = smvchnPtr->strDOIDes;
											pInCh->nExtSigIndex = smvchnPtr->nIndex;

											// �Ƿ���Ҫ����GOOSE IN���ƿ�
											TPOS posIns = ClientIPtr->list_smvinput.GetHeadPosition();
											//itrIns = ClientIPtr->list_smvinput.begin();
											//itrInsE = ClientIPtr->list_smvinput.end();
											while (posIns != NULL)//for (; itrIns != itrInsE; itrIns++)
											{
												itrIns = (PSMVIN)ClientIPtr->list_smvinput.GetNext(posIns);
												// �ж��Ƿ���ͬһ��GOOSE IN���ƿ�
												if (itrIns->strAppID == itrsm->scgsData.address.AppID 
													&& itrIns->strOutputIEDName == pInCh->extrefPtr.iedName
													&& itrIns->strMac == itrsm->scgsData.address.MacAddress)
												{
													itrIns->AddTail(pInCh);//list_smvinputchn.push_back(*itr);
													b_pInCh_use = TRUE;
													itrsm = itrsmE;
													itrsm--;
													nType = 1;
													break;
												}
											}

											// ����
											if (itrIns == itrInsE)
											{
												PSMVIN sipPtr = new CSmvIn();//SHARED_PTR(SMVIN) sipPtr(new SMVIN);
												sipPtr->AddTail(pInCh);//list_smvinputchn.push_back(*itr);
												b_pInCh_use = TRUE;
												sipPtr->bSelect = FALSE;
												sipPtr->strsmvID = itrsm->strsmvID;
												sipPtr->strAppID = itrsm->scgsData.address.AppID ;
												sipPtr->strMac = itrsm->scgsData.address.MacAddress;
												sipPtr->strOutputIEDName = ClientPtr->iedName;
												sipPtr->strOutputIEDDesc = ClientPtr->iedDesc;
												sipPtr->nChnCount = itrsm->GetCount();//smvoutputchn.size();
												ClientIPtr->list_smvinput.AddTail(sipPtr);//.push_back(sipPtr);
												break;
											}
										}
									}
								}
							}
						}//ClientPtr = (CLIENTIEDPTR)ClientMap[pInCh->extrefPtr.iedName];						if (ClientPtr != NULL)
						
						if (b_pInCh_use)
						{
							listInputChnUse.AddTail(pInCh);
						}
					}//end of ����listInputChn

					//����û��ʹ�õ�pInCh
					TPOS posUse = listInputChnUse.GetHeadPosition();
					while (posUse != NULL)
					{
						pInCh = (PINPUTCHN)listInputChnUse.GetNext(posUse);
						TPOS tpos = listInputChn.Find(pInCh);
						if (tpos != NULL)
						{
							listInputChn.RemoveAt(tpos);
						}
					}
					listInputChn.DeleteAll();//ɾ����ʹ�õ�INPUTCH
				}
			}
		}

		listInputChn.RemoveAll();//listInputChn.clear();
		listInputChnUse.RemoveAll();//listInputChn.clear();
		inchMapList.DeleteAllOnllyMap();//sti1.clear();
	}
}


// void CReadSCDF::GetIEDSMVInData(const SMVINPtr& smvInPtr,const CXmlNodePtr& iedNodePtr)
// {
// 
// }

void CReadSCDF::ReadLNodeType(const CXmlNodePtr& LNTNodePtr,CString& idClass)
{
	idClass = LNTNodePtr->GetAttribute(_T("id"));
	idClass += _T(".");
	idClass += LNTNodePtr->GetAttribute(_T("lnClass"));
}

void CReadSCDF::ReadDAType(const CXmlNodePtr& DATypeNodePtr,CString& id)
{
	id = DATypeNodePtr->GetAttribute(_T("id"));
}

void CReadSCDF::ReadEnumType(const CXmlNodePtr& ETNodePtr,const ENUMTYPEPtr& enumtypePtr)
{
	enumtypePtr->id = ETNodePtr->GetAttribute(_T("id"));
	enumtypePtr->desc = ETNodePtr->GetAttribute(_T("desc"));
}


void CReadSCDF::ReadDOType(const CXmlNodePtr& DOTypeNodePtr,CString& id)
{
	id = DOTypeNodePtr->GetAttribute(_T("id"));
}


void CReadSCDF::Close()
{
	if (!m_xmlfile.GetXmlFile().IsEmpty())
	{
		if (!m_xmlDTT->IsNull())
		{
			m_xmlDTT->Release();
		}

		if (!m_xmlroot->IsNull())
		{
			m_xmlroot->Release();
		}

		m_LNodeType.clear();
		m_DAType.clear();
		m_DOType.clear();
		m_showiedleft.DeleteAll();//.clear();
		m_xmlfile.Close();
	}
}


// ����������ȡGOOSEOUT���ƿ�����
BOOL CReadSCDF::GetGooseOutData(LPCTSTR IEDName,UINT nIndex,CScdDataList &listGooseOut)//CONTAINER_LIST_TYPE(GOOSEOUT)& listGooseOut)
{
	ShowIEDRPtr showIEDPtr = (ShowIEDRPtr)m_showiedleft[IEDName];

	if (showIEDPtr == NULL)
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return FALSE;
	}

// 	CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) scgsDataItr = showIEDPtr->list_gooseoutput.begin();
// 	CONTAINER_LIST_TYPE_ITERATOR(GOOSEOUT) GooseItr = listGooseOut.begin();
	PSCGSDATA scgsDataItr = (PSCGSDATA)showIEDPtr->list_gooseoutput.GetHead();
	PGOOSEOUT GooseItr = (PGOOSEOUT)listGooseOut.GetHead();

	if (scgsDataItr != NULL)//showIEDPtr->list_gooseoutput.end())
	{
		UINT nSize = showIEDPtr->list_gooseoutput.GetCount();//.size();
		if (nIndex >= nSize)
		{
			TRACE("���������ֵ����ʵ�ʵ�SMVOUT�ĸ���\r\n");
			return FALSE;
		}

		scgsDataItr = (PSCGSDATA)showIEDPtr->list_gooseoutput.GetAtIndex(nIndex);//advance(scgsDataItr,nIndex);
		GooseItr = (PGOOSEOUT)listGooseOut.GetAtIndex(nIndex);//advance(GooseItr,nIndex);

		GetIEDGOOSEOutData(GooseItr,scgsDataItr,showIEDPtr->iedNodePtr);
	}else
	{
		TRACE("��ǰIED��GOOSEOUT���ƿ�Ϊ��\r\n");
		return FALSE;
	}

	return FALSE;
}

BOOL CReadSCDF::GetSMVOutData(LPCTSTR IEDName,UINT nIndex,CScdDataList &listSMVOut)//CONTAINER_LIST_TYPE(SMVOUT)& listSMVOut)
{

	ShowIEDRPtr showIEDPtr = (ShowIEDRPtr)m_showiedleft[IEDName];

	if (showIEDPtr == NULL)
	{
		TRACE("����ָ��IEDNAMEʧ��\r\n");
		return FALSE;
	}

// 	CONTAINER_LIST_TYPE_ITERATOR(SCGSDATA) scgsDataItr = showIEDPtr->list_smvoutput.begin();
// 	CONTAINER_LIST_TYPE_ITERATOR(SMVOUT) SMVItr = listSMVOut.begin();
	PSCGSDATA scgsDataItr = (PSCGSDATA)showIEDPtr->list_smvoutput.GetHead();
	PSMVOUT SMVItr = (PSMVOUT)listSMVOut.GetHead();

	if (scgsDataItr != NULL)//showIEDPtr->list_smvoutput.end())
	{
		UINT nSize = showIEDPtr->list_smvoutput.GetCount();//.size();
		if (nIndex >= nSize)
		{
			TRACE("���������ֵ����ʵ�ʵ�SMVOUT�ĸ���\r\n");
			return FALSE;
		}

		scgsDataItr = (PSCGSDATA)showIEDPtr->list_smvoutput.GetAtIndex(nIndex);//advance(scgsDataItr,nIndex);
		SMVItr = (PSMVOUT)listSMVOut.GetAtIndex(nIndex);//advance(SMVItr,nIndex);

		GetIEDSMVOutData(SMVItr,scgsDataItr,showIEDPtr->iedNodePtr);
	}
	else
	{
		TRACE("��ǰIED��GOOSEOUT���ƿ�Ϊ��\r\n");
		return FALSE;
	}

	return FALSE;
}

void CReadSCDF::GetSCGSData(SCGSDATA& scgsData,CSCGSData& scgsDataPtr)
{
// 	ASSERT(scgsDataPtr);
// 
// 	if (scgsDataPtr)
	{
		scgsData.cbName = scgsDataPtr.cbName;
		scgsData.ldInst = scgsDataPtr.ldInst;
		scgsData.MaxTime = scgsDataPtr.MaxTime;
		scgsData.MinTime = scgsDataPtr.MinTime;
		scgsData.nType = scgsDataPtr.nType;
		scgsData.strAPName = scgsDataPtr.strAPName;

		scgsData.address = scgsDataPtr.address;
	}
}