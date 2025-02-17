#pragma once
// CCharElmentBaseDlg
#include "..\Module\Characteristic\CharElement.h"

class CCharElmentBaseDlg : public CExBaseObject
{
public:
	CCharElmentBaseDlg();
	virtual ~CCharElmentBaseDlg();

	CDialog *m_pDialog;
	CCharElement *m_pCharElementBase;

	virtual void CreateDlg(CWnd *pParent)=0 ; //�����Ի���
	virtual void GetData()=0; //��ȡ����
	virtual void ShowData()=0;  //��ʾ����	
	virtual BOOL IsEnable()=0;  //�����Ƿ���Ч��������Ч���ݣ��򲻱�������

	virtual void Hide(); //���ضԻ���
	virtual void SetWindowPos(const CRect &rcWnd); //��ȡ�Ի���λ��
	virtual void ShowCharElement(CCharElement *pObj);

};


class CCharElementMngrDlg : public CTLinkListEx<CCharElmentBaseDlg>
{
public:
	CCharElementMngrDlg();
	virtual ~CCharElementMngrDlg();
};

