// GetJobInfo.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "GetJobInfo.h"
#include "JobSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetJobInfo dialog


CGetJobInfo::CGetJobInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CGetJobInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetJobInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGetJobInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetJobInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetJobInfo, CDialog)
	//{{AFX_MSG_MAP(CGetJobInfo)
	ON_BN_CLICKED(IDB_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetJobInfo message handlers

BOOL CGetJobInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem(IDC_COMBO1)->SetFocus();

	OnReset();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGetJobInfo::OnReset() 
{
	reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1))->SelectString(-1, TEXT("普通职员"));
	reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO2))->SelectString(-1, TEXT("无权利"));
}

void CGetJobInfo::OnOK() 
{
	CJobSet *js = new CJobSet(reinterpret_cast<CTrainApp*>(AfxGetApp())->m_connector);
	js->Open();
	js->AddNew();

	GetDlgItemText(IDC_COMBO1, js->m_Job_Name);
	GetDlgItemText(IDC_COMBO2, js->m_Job_Power);

	if(js->Update())
	{
		MessageBox(TEXT("岗位添加成功"));
	}
	js->Close();
	CDialog::OnOK();
}
