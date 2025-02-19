#include <QDir>
#include "HKWgtFileMngrGrid.h"
#include "../SttXuiData/SttXuiDataFileMngrGrid.h"
#include "../../../../Module/API/GlobalConfigApi.h"
#include "../../XLangResource_Native.h"
#include <QHeaderView>
#include "../../../../61850/Module/XLanguageResourcePp_Mms.h"


HKWgtFileMngrGrid::HKWgtFileMngrGrid(QWidget* pParent)
{
	m_pParent = pParent;
	setParent(pParent);
}

HKWgtFileMngrGrid::~HKWgtFileMngrGrid(){}

void HKWgtFileMngrGrid::InitUI(CExBaseObject *pSttXuiData)
{
	setRowCount(0);
	setColumnCount(4);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	QStringList listHeader;

	listHeader << /*"����"*/ g_sLangTxt_Name<< /*"��ʽ"*/g_sLangTxt_Format <</* "��С(KB)"*/g_sLangTxt_Size << /*"����"*/g_sLangTxt_Dates; 

	setHorizontalHeaderLabels(listHeader);
	setColumnWidth(0, 300);
	setColumnWidth(1, 200);
	setColumnWidth(2, 200);
	setColumnWidth(3, 200);
	setCornerButtonEnabled(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void HKWgtFileMngrGrid::Clear()
{
	long nCount = rowCount();
	for (int i = nCount - 1; i >= 0; i--)
	{
		removeRow(i);
	}
}

void HKWgtFileMngrGrid::LoadFiles(const CString& strPath, const CString& strStyle)
{
	CString strFilePath = strPath;
	if(strPath.Find(":") == -1)
	{
		strFilePath = _P_GetBinPath() + strFilePath;
	}

	QDir dir(strFilePath);
	if(!dir.exists())
	{
		return ;
	}

	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);//ʵ�ֶ��ļ��Ĺ���
	dir.setSorting(QDir::Size | QDir::Reversed);//ʵ�ֶ��ļ����������

	QFileInfoList list = dir.entryInfoList();
	for (int i = 0; i < list.size(); ++i)
	{
		QFileInfo fileInfo = list.at(i);
		QString suffix = fileInfo.suffix();
		if(QString::compare(suffix, strStyle, Qt::CaseInsensitive) ==  0)//ͨ��QFileInfo��ʵ�ֶ��ļ����͵Ĺ���
		{
			QString absolute_file_path = fileInfo.absoluteFilePath();
			long nIndex = this->rowCount();
			insertRow(nIndex);

			QString strName = fileInfo.baseName();	
			strName = strName.toLocal8Bit();
			strName = QString::fromUtf8(strName.toStdString().c_str());
			setItem(nIndex, 0, new QTableWidgetItem(strName));
			setItem(nIndex, 1, new QTableWidgetItem(fileInfo.completeSuffix()));
			setItem(nIndex, 2, new QTableWidgetItem(QString::number(fileInfo.size() / 1024)));
			setItem(nIndex, 3, new QTableWidgetItem(fileInfo.created().toString("yyyy-MM-dd hh:mm:ss")));
		}
	}
}

void HKWgtFileMngrGrid::InitUIOwn(CExBaseObject *pSttXuiData)
{
	setRowCount(0);
	setColumnCount(4);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	QStringList listHeader;
	listHeader <<g_sLangTxt_Name <</* "��ʽ" */g_sLangTxt_Format<< /*"��С(KB)"*/g_sLangTxt_Size << /*"����"*/g_sLangTxt_Dates; 

	setHorizontalHeaderLabels(listHeader);
	setCornerButtonEnabled(false);
	if(pSttXuiData)
	{
		CSttXuiDataFileMngrGrid* pData = (CSttXuiDataFileMngrGrid*)pSttXuiData;
		setObjectName(pData->m_strID);
		setGeometry(pData->m_nX*g_dUIShowCoef, pData->m_nY*g_dUIShowCoef, pData->m_nCx*g_dUIShowCoef, pData->m_nCy*g_dUIShowCoef);
		long nWidth = this->width();
		setColumnWidth(0, nWidth / 3);
		setColumnWidth(1, nWidth / 8);
		setColumnWidth(2, nWidth / 8);
		setColumnWidth(3, nWidth / 4);
		//����ָ��types���ļ�
		CSttXuiDataFileTypes* pTypes = (CSttXuiDataFileTypes*)pData->FindByClassID(MNGRCLASSID_CSTTXUIDATAFILETYPES);
		if(pTypes)
		{
			POS pos = pTypes->GetHeadPosition();
			while (pos)
			{
				CSttXuiDataFileType* pType = (CSttXuiDataFileType*)pTypes->GetNext(pos);
				LoadFiles(pType->m_strRoot, pType->m_strType);
			}
		}
	}
}
