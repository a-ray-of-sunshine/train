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
		MessageBox(TEXT("�Բ����������ԭʼ�����������������"));
		UpdateData(FALSE);
		return;
	}
	else
	{
		if(m_NewPassword.Compare(m_RepeatPassword.GetBuffer(m_RepeatPassword.GetLength())))
		{
			MessageBox(TEXT("�Բ�����������������벻һ�£�����������"));
		}
		else
		{
			// ��������޸�����
			CLoginSet *loginset = new CLoginSet(((CTrainApp*)AfxGetApp())->m_connector);
			CString sql;
			// ���������⣬��ʱ�Ľ������Ӧ�ð����û������飬
			// ���������룬��Ϊ��ͬ�û��������п�����ͬ
			// sql.Format(TEXT("select * from user_pswd where TMS_Pswd = '%s'"), m_OldPassword);
			sql.Format(TEXT("select * from user_pswd where TMS_User = '%s'"), pmainwnd->m_UserName);
			loginset->Open(AFX_DB_USE_DEFAULT_TYPE, sql);
			loginset->Edit();
			loginset->m_TMS_Pswd = m_NewPassword;
			//MessageBox(loginset->m_TMS_Pswd);
			if(loginset->Update())
			{
				MessageBox(TEXT("�����޸ĳɹ�"));
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
				MessageBox(TEXT("�����޸�ʧ�ܣ�������"));
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
