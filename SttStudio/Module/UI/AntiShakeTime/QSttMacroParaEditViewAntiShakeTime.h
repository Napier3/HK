#ifndef STTMACROPARAEDITVIEWANTISHAKETIME_H
#define STTMACROPARAEDITVIEWANTISHAKETIME_H
#include "../Interface/SttMacroParaEditViewOriginal.h"
#include "../SttTestCntrCmdDefine.h"
#include "Grid/QSttAntiShakeTimeTestItemsGroupGrid.h"
#include "Grid/QSttAntiShakeTimeDinEventGroupGrid.h"
#include "../Module/CommonCtrl_QT/QLongLineEdit.h"
#include "../../../Module/BaseClass/QT/ExBaseListComboBox.h"

#define STT_ANTISHAKE_TIME_INIT_INTERVAL_SELECT		 "InitIntervalSelect"              //间隔选择
#define STT_ANTISHAKE_TIME_INIT_TEST_OBJECT			 "InitTestObject"				   //测试对象
#define STT_ANTISHAKE_TIME_ANTI_SHAKE_TIME             "AntiShakeTime"				   //防抖时间
#define STT_ANTISHAKE_TIME_SOE_RESOLUTION			 "SOEresolution"                   //SOE分辨率
#define STT_ANTISHAKE_TIME_INIT_BOUT_SET			 "InitBoutSet"                     //开出设置
#define STT_ANTISHAKE_TIME_INIT_STATE1				"InitState1"                       //初始状态
#define STT_ANTISHAKE_TIME_ITEM_NUM					"ItemNum"						   //测试项数量

#define STT_ANTISHAKE_TIME_Dataset_ID				"Din"								//遥信

#define STT_ANTISHAKE_TIME_TESTITEM_NUMBER			 10					                //测试项数量

class QSttMacroParaEditViewAntiShakeTime : public CSttMacroParaEditViewOriginal
{
	Q_OBJECT

public:
	QSttMacroParaEditViewAntiShakeTime(QWidget *parent = 0);
	virtual ~QSttMacroParaEditViewAntiShakeTime();

public:
    virtual char* GetMacroID(){ return STT_ORG_MACRO_AntiShakeTimeTest; }

 	void InitUI();						 //初始化界面
	void InitFont();                     //初始化字体
	void InitConnections();              
 	void InitComboBox();                 //初始化下拉框
	void SaveXmlParas();
	void OpenXmlFile();
	void UpDataTestItemName();
	void UpDateItemNumValue(int nNewValue);
	void InitData();
	void DeleteIntervalListDatas();
	void InitIntervalListDatas();
	void InitTestObjectListDatas();
	void InitBoutSetListDatas();
	void UpDateButtonState();
	void OpenXml();
	virtual void UpdateDeviceModelRef();
	void DelCmbBoutSetData();
	void AddCmbBoutSetData(QList<QString> oList);
	int FindBoutChans(CString strName);
	virtual void GetDatas(CDataGroup *pParas);
	virtual void SetDatas(CDataGroup *pParas);
	virtual void ShowReport(CDvmValues *pValues);
	virtual void AddShowSoeReports(CDvmDataset *pSoeRptDataset);
	virtual void UpdateDinCount(CDvmValues *pValues,CDvmDataset *pSoeRptDataset,CString strItemID);
	virtual void OnViewTestStart();
	virtual void OnViewTestStop();
	void GetSelectObject();
	virtual BOOL GetDatas_Reports( CSttReport *pReport,const CString &strItemID = "");


public:
	QLabel *m_pLabelInterval;         //间隔选择标签
	QLabel *m_pLabelTestObject;       //测试对象标签
	QLabel *m_pLabelAntiShakeTime;    //防抖时间标签
	QLabel *m_pLabelTimeMsec;         //防抖时间毫秒标签
	QLabel *m_pLabelSOEResolution;	  //SOE分辨率标签
	QLabel *m_pLabelSOEMsec;		  //SOE分辨率毫秒标签
	QLabel *m_pLabelBoutSet;		  //开出设置
	QLabel *m_pLabelInitState;		  //初始状态
	CExBaseListComboBox *m_pCmbIntervalSelect;  //间隔选择下拉框
	CExBaseListComboBox *m_pCmbTestObject;	  //测试对象下拉框
	CExBaseListComboBox *m_pCmbBoutSet;		  //开出设置下拉框
	QComboBox *m_pCmbInitState;		  //初始状态下拉框
	QSttLineEdit *m_pEditAntiShakeTime;  //防抖时间编辑框
	QSttLineEdit *m_pEditSOEResolution;  //SOE分辨率编辑框
	QPushButton *m_pBtnAddTestItem;   //添加测试项按钮
	QPushButton *m_pBtnDeleteTestItem;//删除测试项按钮

 	QSttAntiShakeTimeTestItemsGroupGrid *m_pTestRecordsGroupGrid;  //测试记录表格
    QSttAntiShakeTimeDinEventGroupGrid *m_pDinEventGroupGrid;      //遥信时间表格

	CExBaseList m_oTestObjectList;	     //测试对象
	CExBaseList m_oIntervalList;         //间隔选择
	CExBaseList m_oBoutSetList;		     //开出设置
 	CDataGroup m_oTestRecordsDataGroup;  //测试记录表的数据对象
	QList<CString> m_SelectTestObjetcList;


public slots:
	void slot_AddTestItem();
	void slot_DeleteTestItem();

	void slot_CmbIntervalSelect(int nIndex);
	void slot_CmbTestObject(int nIndex);
	void slot_CmbBoutSet(int nIndex);
	void slot_CmbInitState(int nIndex);

	void slot_EditAntiShakeTime();
	void slot_EditSOEResolution();
};


extern QSttMacroParaEditViewAntiShakeTime* g_pAntiShakeTime;


#endif 
