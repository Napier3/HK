#include "SttFileMoveDlg.h"
#include "SttXFolderButton.h"

#include "../../../../../Module/XLanguage/QT/XLanguageAPI_QT.h"
#include "../../../../../Module/API/GlobalConfigApi.h"
#include "../../../SttTestResourceMngr/SttTestResourceMngr.h"
#include "../../../../../Module/OSInterface/QT/XMessageBox.h"
#include "../../Module/CommonMethod/CommonMethod.h"
#include "../../../../../Module/XfileMngrBase/XFolder.h"
#include "../../Module/PopupDialog/SttPopupOpenDialog.h"
#include "../../Module/PopupDialog/SttPopupSaveAsDialog.h"
#include "../../../../../Module/OSInterface/QT/XMessageBox.h"
#include "../../Module/XLangResource_Native.h"

#ifdef _USE_SoftKeyBoard_
#include "../../SoftKeyboard/SoftKeyBoard.h"
#endif

#include <QDir>


QSttFileMoveDlg::QSttFileMoveDlg(QWidget *parent )
: QDialog(parent)
{
	setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint); 
// 	this->setWindowFlags(Qt::Window);
// 	this->showFullScreen();//全屏显示

	m_pMain_VLayout = NULL;
	m_pImport_PushButton = NULL;
	m_pExport_PushButton = NULL;
	m_pDelete_PushButton = NULL;
	m_pBack_PushButton = NULL;
	m_pFileMngrGrid = NULL;
	m_pCurrSelData = NULL;
	m_pSttProgDlg = NULL;
//	m_pOpenCurrData = NULL;
	m_pFileMngrTypeData = NULL;
	
	InitUI();
	initConnections();
	
}

QSttFileMoveDlg::~QSttFileMoveDlg()
{
	if (m_pSttProgDlg != NULL)
	{
		delete m_pSttProgDlg;
		m_pSttProgDlg = NULL;
	}

}

void QSttFileMoveDlg::InitUI()
{
        //20230829 suyang  336D 分辨率1024x600 
	QDesktopWidget* desktopWidget = QApplication::desktop(); 
	QRect rect = desktopWidget->screenGeometry();
	if(rect.height()<650)
	{
		resize(850,500);
		this->setFixedWidth(850);
		this->setFixedHeight(500);

	}
	else
	{
		resize(850,700);
		this->setFixedWidth(850);
		this->setFixedHeight(700);
	}

	
	m_pImport_PushButton = new QPushButton(g_sLangTxt_Import);
	xlang_SetLangStrToWidget(m_pImport_PushButton, "sImport", XLang_Ctrls_QPushButton);
	m_pExport_PushButton = new QPushButton(g_sLangTxt_Export);
	xlang_SetLangStrToWidget(m_pExport_PushButton, "sExport", XLang_Ctrls_QPushButton);
	m_pDelete_PushButton = new QPushButton(g_sLangTxt_Delete);
	xlang_SetLangStrToWidget(m_pDelete_PushButton, "sDelete", XLang_Ctrls_QPushButton);
	CString strTemp;
	strTemp = g_sLangTxt_return ;
	m_pBack_PushButton = new QPushButton(strTemp);

	m_pFileMngrSetHLayout = new QHBoxLayout();
	m_pFileMngrSetHLayout->addWidget(m_pImport_PushButton);
	m_pFileMngrSetHLayout->addWidget(m_pExport_PushButton);
	m_pFileMngrSetHLayout->addWidget(m_pDelete_PushButton);
	m_pFileMngrSetHLayout->addStretch();
	m_pFileMngrSetHLayout->addWidget(m_pBack_PushButton);

	m_pFileMngrGrid = new CSttFileViewGrid();
	m_pFileMngrGrid->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
	m_pFileMngrGrid->SetTableFont(*g_pSttGlobalFont);
	m_pFileMngrGrid->InitGrid();
	m_pFileMngrGrid->AttachDataViewOptrInterface(this);

	m_pMain_VLayout = new QVBoxLayout(this);
	m_pMain_VLayout->addWidget(m_pFileMngrGrid);
	m_pMain_VLayout->addLayout(m_pFileMngrSetHLayout);
	setLayout(m_pMain_VLayout);
}

void QSttFileMoveDlg::initConnections()
{
	connect(m_pImport_PushButton,SIGNAL(clicked()),SLOT(slot_ImportClicked()));
	connect(m_pExport_PushButton,SIGNAL(clicked()),SLOT(slot_ExportClicked()));
	connect(m_pDelete_PushButton,SIGNAL(clicked()),SLOT(slot_DeleteClicked()));
	connect(m_pBack_PushButton,SIGNAL(clicked()),SLOT(slot_BackClicked()));
	connect(this,SIGNAL(sig_UpdateImprotFile(int)),this,SLOT(slot_UpdateImprotFile(int)),Qt::QueuedConnection);
	connect(this,SIGNAL(sig_UpdateExportFile(int)),this,SLOT(slot_UpdateExportFile(int)),Qt::QueuedConnection);
}

BOOL QSttFileMoveDlg::IsUsbFolder(const CString &strPath)
{
#ifdef _PSX_QT_LINUX_
	if (strPath.Find(_T("/Usb/sda")) >0)
	{
        return TRUE;
	}
#endif

	return FALSE;
}

void QSttFileMoveDlg::OnDataSelChanged(QTableWidget *pGridCtrl, int nRow, int nCol)
{
	EnableButtons();
}

void QSttFileMoveDlg::SetCurrFileMnrTypeData(CDvmData* pObj)
{
	CString strFilePath ;
	m_pFileMngrTypeData = pObj;
	//CDvmData *pDvmData =(CDvmData *)pObj;
	strFilePath = m_pFileMngrTypeData->m_strDefaultValue;

	m_oFileMngr.DeleteAll();
	SetFileMngrSuffix(pObj->m_strValue,pObj->m_strFormat);

	m_oFileMngr.SetLibraryPath(strFilePath,TRUE,FALSE,FALSE);
	m_pFileMngrGrid->ShowDatas(&m_oFileMngr);
	EnableButtons();
	SetItemIcon();
}

void QSttFileMoveDlg::slot_ImportClicked()
{
	CString strUsbPath,strFilePath,strTip,strUsb;

#ifdef _PSX_QT_LINUX_
	if (!Global_GetUsbRootFolderPath(strUsbPath))
	{
		CXMessageBox::information(this,g_sLangTxt_Message,g_sLangTxt_USBFile );
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("未识别USB，请插入USB."));
		return;
	}
#else
	strUsbPath = _P_GetInstallPath();
#endif
	
	CString strTemp;
	QSttPopupOpenDialog oOpenDlg(strUsbPath,m_astrFileTypesPostfix,this);
	oOpenDlg.InitUI();
	oOpenDlg.InitTitle(g_sLangTxt_USB);
	oOpenDlg.IniOpenSavetBtn(g_sLangTxt_Select);
	oOpenDlg.m_pExternalPathCheckBox->hide();
	
	if (oOpenDlg.exec() != QDialog::Accepted)
	{
		return;
	}

	if (!oOpenDlg.GetFilePath(strFilePath))
	{
		//CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("获取文件路径失败(%s)."),strFilePath.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,g_sLangTxt_Gradient_FailedGfp.GetString(),strFilePath.GetString()); //lcq
		return;
	}

	m_strMoveFilePath = strFilePath;
//	m_pOpenCurrData = oOpenDlg.m_pCurrSelObj;

	m_pCurrSelData = m_pFileMngrGrid->GetCurrSelData();

	CString strMoveFileName,strCurObjFileName;
	strMoveFileName = GetFileNameFromFilePath(m_strMoveFilePath);
	strMoveFileName.MakeLower();
	CXFile *pFileName = NULL;
	CExBaseObject *pCurObj = NULL;
	POS pos = m_oFileMngr.GetHeadPosition();

	while(pos)
	{
		pCurObj = m_oFileMngr.GetNext(pos);

		if (pCurObj->GetClassID() != CLASSID_XFILE)
		{
			continue;
		}

		pFileName = (CXFile *)pCurObj;
		strCurObjFileName = pFileName->m_strName;
		strCurObjFileName.MakeLower();

		if (strCurObjFileName == strMoveFileName)//文件名相同
		{
			CString strMsg;
			strMsg = g_sLangTxt_RepalceFile ;
			int result = CXMessageBox::information(this,g_sLangTxt_Message, strMsg, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

			if (result == QMessageBox::Yes)
			{	
				if (m_pCurrSelData != NULL)
				{
					if (m_pCurrSelData->m_strName == pFileName->m_strName)
					{
						m_pCurrSelData = NULL;
					}
				}

				CString strSrcFile;
				strSrcFile = pFileName->GetTotalFileName(); 
				m_oFileMngr.Delete(pFileName);
				X_DeleteFile(strSrcFile);
				//m_pCurrFolder->DeleteFile(pFileName);//2023.6.27  zhouhj 调用此函数会导致重复删除

			}
			else
			{
				return ;			
			}
		}
	}

#ifdef _PSX_QT_LINUX_
	pthread_create(&m_pSttOpenFileThread,NULL,SttOpenFileThread,(LPVOID)this );
#else
	m_pSttOpenFileThread =  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)SttOpenFileThread,(LPVOID)this,0,NULL);
#endif
	CString strProgTitle;
	strProgTitle = g_sLangTxt_import;
	StartProgDlg(strProgTitle);
	EnableButtons();
}

#ifdef _PSX_QT_LINUX_
void* QSttFileMoveDlg::SttOpenFileThread(LPVOID pParam)
#else
UINT QSttFileMoveDlg::SttOpenFileThread(LPVOID pParam)
#endif
{
	QSttFileMoveDlg *pFileChilder  = (QSttFileMoveDlg *)pParam;
	int bRet = pFileChilder->ImprotFile_Thread();
	emit pFileChilder->sig_UpdateImprotFile(bRet);


#ifndef _PSX_QT_LINUX_
	return 0;
#endif

}




void QSttFileMoveDlg::slot_ExportClicked()
{
	CString strUsbPath,strTip,strUsb;
	
	//strTip =_T("提示");
	//strUsb = _T("未检测到U盘,请插入U盘");
#ifdef _PSX_QT_LINUX_
	if (!Global_GetUsbRootFolderPath(strUsbPath))
	{
		CXMessageBox::information(this,g_sLangTxt_Message ,g_sLangTxt_USBFile );
		//CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,_T("未识别USB，请插入USB."));
		return;
	}
#endif

	if (strUsbPath == NULL)
	{
		CLogPrint::LogFormatString(XLOGLEVEL_ASSIST,g_sLangTxt_export.GetString());
		return;
	}

	CString strFilePath;
	m_pCurrSelData = m_pFileMngrGrid->GetCurrSelData();

	if (m_pCurrSelData == NULL)
	{
		return;
	}

	QSttPopupSaveAsDialog oSavedlg(strUsbPath, m_astrFileTypesPostfix,m_pCurrSelData->m_strName, this);
	oSavedlg.InitUI();

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::AttachObj(&oSavedlg,Keyboard::ENGLISH);
#endif

	if (oSavedlg.exec() != QDialog::Accepted)
	{
#ifdef _USE_SoftKeyBoard_
		QSoftKeyBoard::ReAttachObj();
#endif
		return;
	}

#ifdef _USE_SoftKeyBoard_
	QSoftKeyBoard::ReAttachObj();
#endif
 
	strFilePath = oSavedlg.GetFilePath();
	m_strMoveFilePath = strFilePath;


#ifdef _PSX_QT_LINUX_
	pthread_create(&m_pSttExportFileThread,NULL,SttExportFileThread,(LPVOID)this );
#else
	m_pSttExportFileThread =  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)SttExportFileThread,(LPVOID)this,0,NULL);
#endif

	CString strProgTitle;
	strProgTitle = g_sLangTxt_exportbar ;
	StartProgDlg(strProgTitle);
}


#ifdef _PSX_QT_LINUX_
void* QSttFileMoveDlg::SttExportFileThread(LPVOID pParam)
#else
UINT QSttFileMoveDlg::SttExportFileThread(LPVOID pParam)
#endif
{
	QSttFileMoveDlg *pFileChilder  = (QSttFileMoveDlg *)pParam;
	int bRet = pFileChilder->ExportFile_Thread();
	emit pFileChilder->sig_UpdateExportFile(bRet);


#ifndef _PSX_QT_LINUX_
	return 0;
#endif

}


void QSttFileMoveDlg::slot_DeleteClicked()
{
	CExBaseObject *pCurrSelData = m_pFileMngrGrid->GetCurrSelData();

	if (pCurrSelData == NULL)
	{
		return;
	}

	if (xfile_IsFile(pCurrSelData->GetClassID()))
	{
		CXFile *pFile = (CXFile *)pCurrSelData;

		CString strFileName,strRootPath,strValue,strTmp;

		strFileName = pFile->GetRelativePath();
		strRootPath =pFile->GetFolderPath(TRUE);

		if (m_astrFormatPostfix.size()>0)
		{
			CString strPostfix,strExtension,ostrFileValue,strPath;

			for (int nIndex = 0;nIndex<m_astrFormatPostfix.size();nIndex++)
			{
				strPostfix = m_astrFormatPostfix.at(nIndex);
				strExtension =  ChangeFilePostfix(strFileName,strPostfix);
				strPath = strRootPath+strExtension;
				X_DeleteFile(strPath);
			}

			int row = m_pFileMngrGrid->currentRow();
			m_pFileMngrGrid->removeRow(row);
			m_oFileMngr.Delete(pFile);
		}
		else
		{
			int row = m_pFileMngrGrid->currentRow();
			m_pFileMngrGrid->removeRow(row);
			CString strSrcFile;
			strSrcFile = pFile->GetTotalFileName();
            //m_pCurrFolder->DeleteFile(pFile);  //2023.6.27  zhouhj 调用此函数会导致重复删除
           m_oFileMngr.Delete(pFile);
			X_DeleteFile(strSrcFile);
		}

		EnableButtons();
	}
}

void QSttFileMoveDlg::slot_BackClicked()
{
	close();
}

void QSttFileMoveDlg::SetFileMngrSuffix(const CString &strSuffixText,const CString &strFormatSuffixText)
{
	QStringList astrPostfix;
	CString strValue,strTmp;
	strValue = strSuffixText;
	CXFileTypes oXFileTypes;
	CXFileType *pXFileType = oXFileTypes.AddFileType(_T(""), _T("Files"), _T(""), _T(""));
	long nIndex = 0;

	while (strValue.Find(";") != -1)
	{
		nIndex = strValue.Find(';');
		astrPostfix << strValue.Mid(0, nIndex);
		strTmp = strValue.Mid(nIndex + 1);
		strValue = strTmp;
	}

	if(strValue.GetLength()>0)
	{
		astrPostfix << strValue;
	}

	m_astrFileTypesPostfix.clear();

	for (int nIndex = 0;nIndex<astrPostfix.size();nIndex++)
	{
		strValue = astrPostfix.at(nIndex);
		strValue.Replace("*.","");
		pXFileType->AddNewPostfix(_T(""), strValue);

		strTmp = _T("*.") + strValue;
		m_astrFileTypesPostfix<<strTmp;

	}
	m_oFileMngr.SetOnllySearchMainTypeFile(FALSE);
	m_oFileMngr.SetXFileTypes(&oXFileTypes);
	m_oFileMngr.InitByXFileTypes();

	m_astrFormatPostfix.clear();
	strValue = strFormatSuffixText;
	strValue = strValue + _T(";") + strSuffixText;//chenling2024.4.28

	while (strValue.Find(";") != -1)
	{
		nIndex = strValue.Find(';');
		strTmp = strValue.Mid(0, nIndex);
		strTmp.Replace("*.","");
		m_astrFormatPostfix << strTmp;
		strTmp = strValue.Mid(nIndex + 1);
		strValue = strTmp;
	}

	if(strValue.GetLength())
	{
		strValue.Replace("*.","");
		m_astrFormatPostfix << strValue;
	}
}

void QSttFileMoveDlg::EnableButtons()
{
	if (m_pFileMngrGrid == NULL)
	{
		m_pDelete_PushButton->setEnabled(FALSE);
		m_pExport_PushButton->setEnabled(FALSE);
		return;
	}

	if (m_pFileMngrGrid->GetCurrSelData() == NULL)
	{
		m_pDelete_PushButton->setEnabled(FALSE);
		m_pExport_PushButton->setEnabled(FALSE);
	}
	else
	{
		m_pDelete_PushButton->setEnabled(TRUE);
		m_pExport_PushButton->setEnabled(TRUE);
	}
}

 void QSttFileMoveDlg::SetItemIcon()
 {
// 	 for (int i = 0;i<= m_pFileMngrGrid->rowCount();i++)
// 	 {
// 		 QGV_ITEM *pItem = m_pFileMngrGrid->GetCell(i,2); 
// 		 QGV_ITEM *pItem2 = m_pFileMngrGrid->GetCell(i,0); 
// 
// 		 CString strPicPath;
// 		 strPicPath = _P_GetResourcePath();
// 
// 		 if (pItem == NULL)
// 		 {
// 			 return ;
// 		 }
// 		 CString strValue = pItem->text();
// 
// 		 if (strValue ==g_sLangTxt_Folder)
// 		 {
// 			 //pItem->setTextColor(RGB(220, 220, 220));
// 			 strPicPath.AppendFormat(_T("folder.png"));
// 			 pItem2->setIcon(QIcon(strPicPath));
// 		 }
// 		 else
// 		 {
// 			 strPicPath.AppendFormat(_T("file.png"));
// 			 pItem2->setIcon(QIcon(strPicPath));
// 		 }
// 
// 	 }
 }

void QSttFileMoveDlg:: StartProgDlg(const CString &strTitle)
 {
	 if (m_pSttProgDlg == NULL)
	 {
		 m_pSttProgDlg = new QSttProgDlg(NULL);
		 m_pSttProgDlg->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
		 m_pSttProgDlg->initUI(g_sLangTxt_Fileguid);
		 m_pSttProgDlg->setModal(false);
		 m_pSttProgDlg->move((this->width() - m_pSttProgDlg->width())/2,
			 (this->height() - m_pSttProgDlg->height())/2);
	 }

	 m_pSttProgDlg->setWindowTitle(strTitle);
	 m_pSttProgDlg->Start();
	 m_pSttProgDlg->show();
	 setEnabled(false);
 }

// QString gbkToUtf8(const CString &strText)
// {
// 	QTextCodec *pGbkCodec = QTextCodec::codecForName("GBK");
// 	QTextCodec *pUft8Codec = QTextCodec::codecForName("utf-8");
// 	char *pCharData /*= strText.data()*/;
// 	QString strRet /*= pGbkCodec->toUnicode(strText)*/;
// 	QByteArray oUft8Bytes = pUft8Codec->fromUnicode(strText);
// 	pCharData = oUft8Bytes.data();
// 	strRet = pCharData;
// 	pGbkCodec = QTextCodec::codecForName("GBK");
// 	return strRet;
// }

#define STT_FILE_MNGR_MaxReadLenth     1024*1024+10

BOOL QSttFileMoveDlg::CopyFile_FileMngr(const CString &strSrcFilePath,const CString &strDestFilePath)
{
	CFile oFileRead,oFileWrite;

#ifdef _PSX_QT_LINUX_
    QTextCodec *pOldTextCodec = NULL;
    InitLocalCodec_BeforeReadWrite(strSrcFilePath,&pOldTextCodec);
#endif

	if (!oFileRead.Open(strSrcFilePath,CFile::modeRead))
	{
#ifdef _PSX_QT_LINUX_
        ResetLocalCodec(pOldTextCodec);
#endif
		//CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("打开文件失败(%s)."),strSrcFilePath.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_ERROR,g_sLangTxt_Gradient_FailedTof.GetString(),strSrcFilePath.GetString()); //lcq
		return FALSE;
	}
#ifdef _PSX_QT_LINUX_
        ResetLocalCodec(pOldTextCodec);
#endif
	UINT nOpenMode = CFile::modeCreate | CFile::modeWrite | CFile::shareExclusive;
#ifdef _PSX_IDE_QT_
	nOpenMode |= CFile::modeTruncate;
#endif

// 	CString strDestFilePath_Utf8;
// 	strDestFilePath_Utf8 = gbkToUtf8(strDestFilePath);

#ifdef _PSX_QT_LINUX_
    pOldTextCodec = NULL;
    InitLocalCodec_BeforeReadWrite(strDestFilePath,&pOldTextCodec);
#endif

	BOOL bRet = oFileWrite.Open(strDestFilePath, nOpenMode);

#ifdef _PSX_QT_LINUX_
	ResetLocalCodec(pOldTextCodec);
#endif

	if (!bRet)
	{
		oFileRead.Close();
		//CLogPrint::LogFormatString(XLOGLEVEL_INFOR,_T("[%s]创建写文件失败."),strDestFilePath.GetString());
		CLogPrint::LogFormatString(XLOGLEVEL_INFOR,g_sLangTxt_Gradient_FailedCwf.GetString(),strDestFilePath.GetString()); //lcq
		return FALSE;
	}

	long nTotalLenth = oFileRead.GetLength();
	long nCurrReadLenth = 0,nTotalReadLenth = 0,nActReadLenth = 0;
	BYTE *pFileReadBuffer = new BYTE[STT_FILE_MNGR_MaxReadLenth+10];
	memset(pFileReadBuffer,0,STT_FILE_MNGR_MaxReadLenth+10);
	//CLogPrint::LogFormatString(XLOGLEVEL_RESULT,_T("文件[%s]大小为(%ld)."),strSrcFilePath.GetString(),nTotalLenth);
	CLogPrint::LogFormatString(XLOGLEVEL_RESULT,g_sLangTxt_Gradient_FileIsize.GetString(),strSrcFilePath.GetString(),nTotalLenth); //lcq

	while(nTotalReadLenth<nTotalLenth)
	{
		if ((nTotalLenth-nTotalReadLenth)>STT_FILE_MNGR_MaxReadLenth)
		{
			nCurrReadLenth = STT_FILE_MNGR_MaxReadLenth;
		} 
		else
		{
			nCurrReadLenth = nTotalLenth-nTotalReadLenth;
		}

		nActReadLenth = oFileRead.Read(pFileReadBuffer,nCurrReadLenth);

		if (nActReadLenth<0)
		{
			//CLogPrint::LogString(XLOGLEVEL_ERROR,_T("读取指定长度的大文件内容失败."));
			CLogPrint::LogString(XLOGLEVEL_ERROR,g_sLangTxt_Gradient_FailedTRlfile.GetString()); //lcq
			return FALSE;
		}
		else if (nActReadLenth != nCurrReadLenth)
		{
			CLogPrint::LogFormatString(XLOGLEVEL_ERROR, _T("nActReadLenth=%ld;nCurrReadLenth=%ld;(nActReadLenth != nCurrReadLenth)"), nActReadLenth,nCurrReadLenth);
			return FALSE;
		}

		oFileWrite.Write(pFileReadBuffer, nActReadLenth);
		nTotalReadLenth += nActReadLenth;
	}

	delete pFileReadBuffer;
	oFileRead.Close();
	oFileWrite.Close();
	return TRUE;
}

BOOL QSttFileMoveDlg::ImprotFile_Thread()
{
	CString strFilePath;
	strFilePath = m_strMoveFilePath;

	CString strDestPath,strDestRootPath;
	strDestRootPath = m_oFileMngr.GetFolderPath();

	//对于录波文件类,多个扩展名文件同步导入的情况进行处理
	if (m_astrFormatPostfix.size()>0)
	{
		CString strPostfix,strExtensionFilePath,strFileName;

		for (int nIndex = 0;nIndex<m_astrFormatPostfix.size();nIndex++)
		{
			strPostfix = m_astrFormatPostfix.at(nIndex);
			strExtensionFilePath =  ChangeFilePostfix(strFilePath,strPostfix);

			if (IsFileExist(strExtensionFilePath))
			{
				strFileName = GetFileNameFromFilePath(strExtensionFilePath);
				strDestPath = strDestRootPath + strFileName;
				CopyFile_FileMngr(strExtensionFilePath,strDestPath);

			}
			else
			{
				//CLogPrint::LogFormatString(XLOGLEVEL_ERROR,_T("文件不存在(%s)."),strExtensionFilePath.GetString());
				CLogPrint::LogFormatString(XLOGLEVEL_ERROR,g_sLangTxt_Gradient_FileNoexist.GetString(),strExtensionFilePath.GetString()); //lcq
			}
		}
	}

	//对于导入前表格内容为空的情况,进行特殊处理
	if ( m_pFileMngrGrid->GetDatas() == NULL)
	{
		m_oFileMngr.AddFile(strFilePath);
// 		m_pFileMngrGrid->ShowDatas(&m_oFileMngr);
// 		SetItemIcon();
		return TRUE;
	}

	CXFile *pSelData  = new CXFile();
	pSelData->SetParent(&m_oFileMngr);
	pSelData->m_strName = GetFileNameFromFilePath(m_strMoveFilePath);
	pSelData->m_strID = pSelData->m_strName;
	strDestPath = strDestRootPath + pSelData->m_strName;
	m_oFileMngr.InsertAfter(m_oFileMngr.Find(m_pCurrSelData),pSelData);
	CopyFile_FileMngr(strFilePath,strDestPath);
// 	m_pFileMngrGrid->ShowDatas(m_pCurrFolder);
// 	SetItemIcon();
	return TRUE;
}

void QSttFileMoveDlg::slot_UpdateImprotFile(int bRet)
{
	setEnabled(true);
	m_pSttProgDlg->Stop();

	m_pFileMngrGrid->ShowDatas(&m_oFileMngr);
	SetItemIcon();
	CString strMsg;

	if (bRet)
	{
		//导入、导出文件成功，刷新界面
		strMsg = g_sLangTxt_Importflie + m_strMoveFilePath + g_sLangTxt_Win;
		CLogPrint::LogString(XLOGLEVEL_RESULT, strMsg);
		CXMessageBox::information(this,g_sLangTxt_Message,/* "导入成功"*/g_sLangTxt_ImpSucc.GetString());   //20240508 xueyangfan 文件导入导出成功的提示信息
	}
	else
	{
		strMsg = g_sLangTxt_Importflie + m_strMoveFilePath + g_sLangTxt_Lose;
		CLogPrint::LogString(XLOGLEVEL_RESULT, strMsg);
		CXMessageBox::information(this,g_sLangTxt_Message,/* "导入失败"*/g_sLangTxt_ImpFail.GetString());
	}
}


BOOL QSttFileMoveDlg::ExportFile_Thread()
{
	CString strFilePath;
	strFilePath = m_strMoveFilePath;
	CXFile *pXFile = (CXFile *)m_pCurrSelData;
	CString strSrcFilePath = pXFile->GetRelativePath(TRUE);

	if (m_astrFormatPostfix.size()>0)
	{
		CString strPostfix,strExtensionFilePath, strDestPath,strDestFile,strDestFileName,strReplaceName,strReplaceFilePath;

		for (int nIndex = 0;nIndex<m_astrFormatPostfix.size();nIndex++)
		{
			strPostfix = m_astrFormatPostfix.at(nIndex);
			strExtensionFilePath = ChangeFilePostfix(strSrcFilePath,strPostfix);

			if (IsFileExist(strExtensionFilePath))
			{
				strDestFileName = GetFileNameFromFilePath(strExtensionFilePath);
				strDestFile= GetPathFromFilePathName(strFilePath);
				strDestPath = strDestFile + strDestFileName;

				strReplaceName = GetFileTitleFromFilePath(strFilePath);
				strReplaceFilePath = ChangeFileName(strDestPath,strReplaceName);
				CopyFile_FileMngr(strExtensionFilePath,strReplaceFilePath);
				//::X_CopyFile(strExtensionFilePath,strReplaceFilePath , FALSE);
			}
		}
	}
	
	if (xfile_IsFile(m_pCurrSelData->GetClassID()))
	{
		CXFile *pXFile = (CXFile *)m_pCurrSelData;
		CString strSrcFile = pXFile->GetRelativePath(TRUE);

		CopyFile_FileMngr(strSrcFile,strFilePath);
		//::X_CopyFile(strSrcFile, strFilePath, FALSE);
		return TRUE;
	}

	return TRUE;
}


void QSttFileMoveDlg::slot_UpdateExportFile(int bRet)
{
	setEnabled(true);
	m_pSttProgDlg->Stop();
	CString strMsg;

	if (bRet)
	{
		//导入、导出文件成功，刷新界面
		strMsg = g_sLangTxt_Importflie + m_strMoveFilePath + g_sLangTxt_Win;
		CLogPrint::LogString(XLOGLEVEL_RESULT, strMsg);
		CXMessageBox::information(this,g_sLangTxt_Message.GetString(), /*"导出成功"*/g_sLangTxt_ExpSucc.GetString());//dingxy 20240708
	}
	else
	{
		strMsg = g_sLangTxt_Importflie  + m_strMoveFilePath + g_sLangTxt_Lose;
		CLogPrint::LogString(XLOGLEVEL_RESULT, strMsg);
		CXMessageBox::information(this,g_sLangTxt_Message.GetString(),/* "导出失败"*/g_sLangTxt_ExpFail.GetString());
	}
}

