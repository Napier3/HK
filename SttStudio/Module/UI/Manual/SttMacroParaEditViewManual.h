#pragma once

#include "../Interface/SttMacroParaEditViewOriginal.h"
#include "../Controls/SttLineEdit.h"
#include "../Module/GooseParaWidget/qgooseparawidget.h"
#include "ManualView_Paras.h"
#include "ManualView_IV.h"
#include "QSttMUParasWidget.h"
#include "QSttMUTimeTestWidget.h"

//#include "../../Module/SttTest/Common/tmt_state_test.h"

#include "QSttManualBinBoutDlg.h"
#include "../Module/CommonCtrl_QT/SttDiffCurrCalDlg.h"
#include "../Module/FT3Widget/FT3OutParaWidget.h"
#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QLabel>
#include <QGroupBox>

#include "../Controls/SttCheckBox.h"
#include "../Module/ScrollCtrl/ScrollComboBox.h"
#include "ManualEstimateDlg.h"
#include "../Controls/SttGroupBox.h"

namespace Ui {
class QSttMacroParaEditViewManual;
}

#define FILE_MANUTEST		"ManualTest"
#define POSTFIX_MANUTEST    "mntxml"

class QSttMacroParaEditViewManual : public CSttMacroParaEditViewOriginal
{
    Q_OBJECT

public:
    Ui::QSttMacroParaEditViewManual *m_pManualTest_UI;
	QManualView_Paras m_oParas;
	QManualView_IV m_oIV;
	QSttMUTimeTestWidget *m_pSttMUTimeTestWidget;
	ShortCalcuPara m_ShortCalcuPara; 
	tmt_manual_test m_oManualTest;
	tmt_ManualParas *m_pManualParas;
	Stt_DiffCurrCalParas m_oDiffCurrCalParas;
	bool m_bIsChanging;//判断+和-按钮所造成的更改是否已经完成,未完成时不允许发送下一次SetItemPara
	QGooseParaWidget* m_pGooseParaWidget;
	QFT3OutParaWidget* m_pFT3OutParaWidget;
	CString m_strCbbChannel;//通道选择
public:
	QGridLayout *m_pMainVBoxLayout;
	QGridLayout* m_pGridLayoutLeft;
	QSttGroupBox *m_pManualGroupBox;
	QSttCheckBox *m_pHarm_CheckBox;
	QScrollComboBox *m_pHarm_ComboBox;
	QLabel *m_pTestMethod_Label;
	QScrollComboBox *m_pTestMethod_ComboBox;
	QLabel *m_pMeasType_Label;
	QScrollComboBox *m_pMeasType_ComboBox;
	QLabel *m_pBCode_Label;
	QScrollComboBox *m_pBCode_ComboBox;
	QSttGroupBox *m_pOutSetGroupBox;
	QCheckBox *m_pOutCheckBox[10];
	QGridLayout *m_pOutSetGridLayout;
	QSttGroupBox *m_pTestGroupBox;
	QSttCheckBox *m_pSetMUTestRpt_CheckBox;//设置合并单元测试报告测试次数和每次使用时间
	QSttLineEdit *m_pMUAccuracyTestNum_Edit;
	QLabel *m_pMUTestNumUnit_Label;
	QSttLineEdit *m_pMUTestTime_Edit;
	QLabel *m_pMUTestTimeUnit_Label;
	QPushButton *m_pRefresh_Button;//刷新
	int m_nBCodeMode,m_nIecFormatMeas; //2023-5-31 suyang 用于系统参数与合并单元B码、报文类型判断
public:
    explicit QSttMacroParaEditViewManual(QWidget *parent = nullptr);
    virtual ~QSttMacroParaEditViewManual() override;
private:
	void SendUpdateParameter();
	void InitBinaryInBinaryOutUI();
	void InitOtherParasUI();
	void SetManualOtherParasFont();
	void InitStyle();
	void VisibleCtrlsByFuncType();//根据功能类型显示界面内容
	// 2023-06-1 suyang 合并单元
	void InitMuUI();
	void InitMuComboBoxItem();
	void UpdateMUAccurData();
	void UpdateMURptUI();
	void SetWinMuTestFont_1024_768();//20230724 适用1024 X768 分辨率
public:
    virtual void SerializeTestParas(CSttXmlSerializeBase *pMacroParas, PTMT_PARAS_HEAD pParas, long nVolRsNum,long nCurRsNum,long nBinExNum,long nBoutExNum,BOOL bHasGoosePub) override;
    virtual bool PrepStartTest() override;//zhouhj 20230704 开始测试前的准备工作
    virtual void UpdateTestResource(BOOL bCreateChMaps) override;
    virtual void UpdateGoutTab(BOOL bUpdateList = FALSE) override;
    virtual void UpdateFT3Tab(BOOL bUpdateList = FALSE) override;
    virtual void UpdateBinBoutExTab() override;//更新开关量扩展界面
    virtual CString GetDefaultParaFile() override;
    virtual bool IsValidTestParasFile(const CString& strParasFile,bool bOpen = true) override;
    virtual PTMT_PARAS_HEAD GetTestParas()  override { return &m_oManualTest;}
    virtual char* GetMacroID() override { return "ManualTest"; }
    virtual void OnViewTestLink(BOOL b) override;
    virtual void OnViewTestStart() override;
    virtual void OnViewTestStop() override;
    virtual void ShowReport(CDvmValues *pValues) override;
    virtual void GetDatas(CDataGroup *pParas) override;
    virtual void SetDatas(CDataGroup *pParas) override;
    virtual BOOL SetValues_dsRcdStep6U6I(CDvmDataset *pDsRcdStep6U6I) override;
    virtual void UpdateAuxDCEdit() override;//20240613 suyang 新增用于更新L336D 状态序列 通用 辅助直流编辑框

    void InitLanuage();
    void CopyBinaryConfig(BOOL b=TRUE);
    void InitBinStateOnStarting();
    void InitConnect();
    CSttTestResourceBase* CreateTestResource();
    void ClearResult(PTMT_PARAS_HEAD pHead);
    void OnTestResults(CDataGroup *pResults);
    void UpdateManualParas(bool bUpdateParasData = TRUE);
    void UpdateGoutTab_UI(CIecCfgGoutDatas* pCfgGoutDatas);
    void UpdateFT3Tab_UI(CIecCfgDatasSMV* pIecCfgDatasSMV);
    void InitParasView();
    void InitIVView();
    void slot_SwitchStateChanged();
	void AddGooseParaWidget(CIecCfgGoutDatas* pCfgGoutDatas);
	void RemoveGooseParaWidget();
	void EnableGooseParaWidget(bool b);
	bool ExistGooseParaWidget();
    void slot_edit_changed(QSttLineEdit* pEditLine, bool bIsNor = FALSE);
	//chenling20230516
	void AddFT3OutParaWidget(CIecCfgDatasSMV* pIecCfgDatasSMV);
	void RemoveFT3OutParaWidget(); 
	void EnableFT3OutParaWidget(bool b);
	bool ExistFT3OutParaWidget();

	void UpdateHarmCheckComboxUI(BOOL bClearItems);

signals:
	void sig_updataParas();

private slots:
    void on_m_btnLock_clicked();
    void on_m_btnAdd_clicked();
    void on_m_btnMinus_clicked();
	void on_m_editIintVal_editingFinished();
	void on_m_editFinishVal_editingFinished();
	void on_m_editTime_editingFinished();
	void on_m_editUdc_editingFinished();
	void on_m_editStep_editingFinished();
	void on_m_cbOld_clicked();
	void on_m_cbAuto_clicked();
	void on_m_cbDC_clicked();
	void on_m_cbbSelect_currentIndexChanged(int index);
	void on_m_cbbChannel_currentIndexChanged(int index);
	void on_m_cbbChangeType_currentIndexChanged(int index);
	void on_m_cbOut1_clicked();
	void on_m_cbOut2_clicked();
	void on_m_cbOut3_clicked();
	void on_m_cbOut4_clicked();
	void on_m_editTimeChanged();
	void on_m_editStepChanged();
	void on_m_editInitValueChanged();
	void on_m_editFinishValueChanged();
	//void on_m_editDelayChanged();
	void slot_HarmCheck_stateChanged(int nState);
	void slot_cmbHarm_SelChanged(int nCurrIndex);
	void slot_currentChangedTabWidget(int nCurrIndex);
	void on_m_btnShortCalcu_clicked();
    void on_m_btnInBinaryOutSet_clicked();
    void on_m_btnDiffCalc_clicked();
	void slot_Estimate();

	virtual void slot_ShortCalcuOk(ShortCalcuPara &para);

private slots:
	void slot_cbbTestMethod_currentIndexChanged(int index);
	void slot_cbbMeasType_currentIndexChanged(int index);
	void slot_cbbBCode_currentIndexChanged(int index);

	void slot_editTestNumChanged();
	void slot_editTestTimeChanged();
	void slot_editTestNumFinished();
	void slot_editTestTimeFinished();

	void slot_OnTestCheckChanged();
	void slot_RefreshClicked();
	void slot_OnOutCheckChanged();

protected slots:
	void slot_updateParas();
	void slot_ChannelTableItemValue(QString str,float fstep,int valueFlag,int AddOrMinus,bool bDC);
	void slot_GooseDataChanged();
    void slot_FT3DataChanged(); 
};

extern QSttMacroParaEditViewManual* g_pManualTest;
