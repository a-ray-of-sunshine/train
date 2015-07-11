// GetPersonnelInfo.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "GetPersonnelInfo.h"
#include "PersonSet.h"
#include "JobSet.h"
#include "DeptSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetPersonnelInfo dialog


CGetPersonnelInfo::CGetPersonnelInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CGetPersonnelInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetPersonnelInfo)
	m_Name = _T("");
	m_Birthday = 0;
	m_Hometown = _T("");
	m_Country = _T("");
	m_Nation = _T("");
	m_ID = _T("");
	m_WorkTime = 0;
	m_StateTime = 0;
	m_HomeAddress = _T("");
	m_Phone = _T("");
	m_E_mail = _T("");
	//}}AFX_DATA_INIT
}


void CGetPersonnelInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetPersonnelInfo)
	DDX_Control(pDX, IDC_EDIT15, m_Job_ID);
	DDX_Control(pDX, IDC_EDIT2, m_DeptID);
	DDX_Control(pDX, IDC_EDIT10, m_State);
	DDX_Control(pDX, IDC_EDIT8, m_Health);
	DDX_Control(pDX, IDC_COMBO6, m_Marriage);
	DDX_Control(pDX, IDC_COMBO2, m_Gender);
	DDX_Control(pDX, IDC_COMBO1, m_XL);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_DateTimeCtrl(pDX, IDC_EDIT3, m_Birthday);
	DDX_Text(pDX, IDC_EDIT4, m_Hometown);
	DDX_Text(pDX, IDC_EDIT5, m_Country);
	DDX_Text(pDX, IDC_EDIT6, m_Nation);
	DDX_Text(pDX, IDC_EDIT7, m_ID);
	DDX_DateTimeCtrl(pDX, IDC_EDIT9, m_WorkTime);
	DDX_DateTimeCtrl(pDX, IDC_EDIT11, m_StateTime);
	DDX_Text(pDX, IDC_EDIT12, m_HomeAddress);
	DDX_Text(pDX, IDC_EDIT13, m_Phone);
	DDX_Text(pDX, IDC_EDIT14, m_E_mail);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetPersonnelInfo, CDialog)
	//{{AFX_MSG_MAP(CGetPersonnelInfo)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetPersonnelInfo message handlers

BOOL CGetPersonnelInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem(IDC_EDIT1)->SetFocus();

	m_XL.AddString(TEXT("本科"));
	m_XL.AddString(TEXT("硕士"));
	m_XL.AddString(TEXT("博士"));
	m_XL.AddString(TEXT("其他"));
	m_XL.SelectString(-1, TEXT("本科"));

	m_Gender.AddString(TEXT("男"));
	m_Gender.AddString(TEXT("女"));
	m_Gender.SelectString(-1, TEXT("男"));

	m_Marriage.AddString(TEXT("已婚"));
	m_Marriage.AddString(TEXT("未婚"));
	m_Marriage.AddString(TEXT("离异"));
	m_Marriage.SelectString(-1, TEXT("已婚"));

	m_State.SelectString(-1, TEXT("在职"));
	m_Health.SelectString(-1, TEXT("健康"));
	
	TCHAR buffer[32];
	CJobSet *js = new CJobSet(((CTrainApp*)AfxGetApp())->m_connector);
	js->Open();
	for(int i = 0; i < js->GetRecordCount(); i++)
	{
		m_Job_ID.AddString(_itot(js->m_Job_ID, buffer, 10));
		js->MoveNext();
	}
	js->Close();

	CDeptSet *ds = new CDeptSet(((CTrainApp*)AfxGetApp())->m_connector);
	ds->Open();
	for(int j = 0; j < ds->GetRecordCount(); j++)
	{
		m_DeptID.AddString(_itot(ds->m_Dept_ID, buffer, 10));
		ds->MoveNext();
	}
	ds->Close();

	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGetPersonnelInfo::OnReset() 
{
	m_Name = _T("");
	m_Hometown = _T("");
	m_Country = _T("");
	m_Nation = _T("");
	m_ID = _T("");
	m_HomeAddress = _T("");
	m_Phone = _T("");
	m_E_mail = _T("");
	UpdateData(FALSE);

	m_XL.SelectString(-1, TEXT("本科"));
	m_Gender.SelectString(-1, TEXT("男"));
	m_Marriage.SelectString(-1, TEXT("已婚"));
	m_State.SelectString(-1, TEXT("在职"));
	m_Health.SelectString(-1, TEXT("健康"));
}

void CGetPersonnelInfo::OnOK() 
{	
	CPersonSet *ps = new CPersonSet(((CTrainApp*)AfxGetApp())->m_connector);
	ps->Open();
	ps->AddNew();

	UpdateData();

	ps->m_Emp_Name = m_Name;

	CString value;
	m_XL.GetLBText(m_XL.GetCurSel(), value);
	ps->m_Emp_XL = value;

	m_Gender.GetLBText(m_Gender.GetCurSel(), value);
	ps->m_Emp_Gender = value;

	#pragma warning(disable: 4244)
	ps->m_Dept_ID = (BYTE)GetDlgItemInt(IDC_EDIT2);
	ps->m_Job_ID = (BYTE)GetDlgItemInt(IDC_EDIT15);

	ps->m_Emp_Hometown = m_Hometown;

	ps->m_Emp_Country = m_Country;

	ps->m_Emp_Nation = m_Nation;

	ps->m_Emp_ID = m_ID;

	m_Marriage.GetLBText(m_Marriage.GetCurSel(), value);
	ps->m_Emp_Marriage = value;

	m_Health.GetLBText(m_Health.GetCurSel(), value);
	ps->m_Emp_Health = value;

	m_State.GetLBText(m_State.GetCurSel(), value);
	ps->m_Emp_State = value;

	ps->m_Emp_HomeAddress = m_HomeAddress;

	ps->m_Emp_Teleno = m_Phone;

	ps->m_Emp_Email = m_E_mail;

	ps->m_Emp_Birthday = m_Birthday.Format(TEXT("%Y-%m-%d"));
	ps->m_Emp_StartWork = m_WorkTime.Format(TEXT("%Y-%m-%d"));
	ps->m_Emp_State_Date = m_StateTime.Format(TEXT("%Y-%m-%d"));

	if(ps->Update())
	{
		ps->Close();
		MessageBox(TEXT("添加员工成功"));
		CDialog::OnOK();
	}
	else
	{
		MessageBox(TEXT("添加员工失败"));
		CDialog::OnCancel();
	}
}
