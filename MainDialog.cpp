// MainDialog.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "MainDialog.h"
#include "ChangePassword.h"
#include "PersonnelManage.h"
#include "JobDeptManage.h"
#include "CourseManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MainDialog dialog


MainDialog::MainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MainDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(MainDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	this->Create(IDD, pParent);
}


void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MainDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MainDialog, CDialog)
	//{{AFX_MSG_MAP(MainDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnPersonnelManage)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MainDialog message handlers

//DEL BOOL MainDialog::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	//return CDialog::Create(IDD, pParentWnd);
//DEL 	return this->CreateIndirect(IDD, pParentWnd);
//DEL }

void MainDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
	//this->DestroyWindow();
	this->OnClose();
}

void MainDialog::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;
	CDialog::PostNcDestroy();
}

void MainDialog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	this->DestroyWindow();
	CDialog::OnClose();
	this->GetOwner()->SendMessage(WM_CLOSE);
}

BOOL MainDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->GetOwner()->ShowWindow(SW_HIDE);
	this->GetDlgItem(IDC_BUTTON1)->SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void MainDialog::OnOK() 
{
	// TODO: Add extra validation here
	CChangePassword cp;
	cp.DoModal();
}

void MainDialog::OnPersonnelManage() 
{
	CPersonnelManage pm;
	pm.DoModal();
}

void MainDialog::OnButton3() 
{
	CJobDeptManage jdm;
	jdm.DoModal();
}

void MainDialog::OnButton2() 
{
	CCourseManage cm;
	cm.DoModal();
}
