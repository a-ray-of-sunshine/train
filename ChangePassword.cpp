// ChangePassword.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "ChangePassword.h"
#include "loginset.h"
#include "trainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangePassword dialog


CChangePassword::CChangePassword(CWnd* pParent /*=NULL*/)
	: CDialog(CChangePassword::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangePassword)
	m_OldPassword = _T("");
	m_NewPassword = _T("");
	m_RepeatPassword = _T("");
	//}}AFX_DATA_INIT
}


void CChangePassword::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangePassword)
	DDX_Text(pDX, IDC_EDIT1, m_OldPassword);
	DDX_Text(pDX, IDC_EDIT2, m_NewPassword);
	DDX_Text(pDX, IDC_EDIT3, m_RepeatPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangePassword, CDialog)
	//{{AFX_MSG_MAP(CChangePassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangePassword message handlers

void CChangePassword::OnOK() 
{
	// TODO: Add extra validation here
	CTrainDlg *pmainwnd = (CTrainDlg*)AfxGetApp()->m_pMainWnd;

	UpdateData();
	if(pmainwnd->m_Password.Compare(this->m_OldPassword.GetBuffer(this->m_OldPassword.GetLength())))
	{
		MessageBox(TEXT("对不起，你输入的原始密码错误！请重新输入"));
		UpdateData(FALSE);
		return;
	}
	else
	{
		if(m_NewPassword.Compare(m_RepeatPassword.GetBuffer(m_RepeatPassword.GetLength())))
		{
			MessageBox(TEXT("对不起，两次输入的新密码不一致！请重新输入"));
		}
		else
		{
			// 真正完成修改密码
			CLoginSet *loginset = new CLoginSet(((CTrainApp*)AfxGetApp())->m_connector);
			CString sql;
			// 这里有问题，此时的结果集，应该按照用户名来查，
			// 而不是密码，因为不同用户的密码有可能相同
			// sql.Format(TEXT("select * from user_pswd where TMS_Pswd = '%s'"), m_OldPassword);
			sql.Format(TEXT("select * from user_pswd where TMS_User = '%s'"), pmainwnd->m_UserName);
			loginset->Open(AFX_DB_USE_DEFAULT_TYPE, sql);
			loginset->Edit();
			loginset->m_TMS_Pswd = m_NewPassword;
			//MessageBox(loginset->m_TMS_Pswd);
			if(loginset->Update())
			{
				MessageBox(TEXT("密码修改成功"));
				loginset->Close();
				if(loginset)
				{
					delete loginset;
					loginset = NULL;
				}
				CDialog::OnOK();

			}
			else
			{
				loginset->Close();
				if(loginset)
				{
					delete loginset;
					loginset = NULL;
				}
				MessageBox(TEXT("密码修改失败，请重试"));
			}
		}
	}
}

BOOL CChangePassword::OnInitDialog() 
{
	CDialog::OnInitDialog();
	this->GetDlgItem(IDC_EDIT1)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
