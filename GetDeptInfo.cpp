// GetDeptInfo.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "GetDeptInfo.h"
#include "PersonSet.h"
#include "DeptSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetDeptInfo dialog


CGetDeptInfo::CGetDeptInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CGetDeptInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetDeptInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_ps = new CPersonSet(((CTrainApp*)AfxGetApp())->m_connector);
	m_ds = new CDeptSet(((CTrainApp*)AfxGetApp())->m_connector);
}


void CGetDeptInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetDeptInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetDeptInfo, CDialog)
	//{{AFX_MSG_MAP(CGetDeptInfo)
	ON_BN_CLICKED(IDB_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetDeptInfo message handlers

BOOL CGetDeptInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();

	GetDlgItem(IDC_COMBO1)->SetFocus();
	OnReset();
	GetEmpName();

	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGetDeptInfo::OnReset() 
{
	reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1))->SelectString(-1, TEXT("业务部"));
}

void CGetDeptInfo::GetEmpName()
{
	m_ps->Open();

	for(int i = 0; i < m_ps->GetRecordCount(); i++)
	{
		reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO3))->InsertString(-1, m_ps->m_Emp_Name);
		reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO4))->InsertString(-1, m_ps->m_Emp_Name);
		m_ps->MoveNext();
	}

	m_ps->Close();
}

CGetDeptInfo::~CGetDeptInfo()
{
	if(m_ps)
	{
		delete m_ps;
		m_ps = NULL;
	}

	if(m_ds)
	{
		delete m_ds;
		m_ds = NULL;
	}
}

void CGetDeptInfo::OnOK()
{
	UpdateDept();
	CDialog::OnOK();
}

void CGetDeptInfo::UpdateDept()
{
	CComboBox *pname = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	CString deptname;
	pname->GetLBText(pname->GetCurSel(), deptname);

	BYTE manager_id;
	// 添加新的部门总经理
	CComboBox *pmanage = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO3));
	CString name, sql(TEXT("'"));
	pmanage->GetLBText(pmanage->GetCurSel(), name);
	sql += name;
	sql += TEXT("");
	m_ps->m_strFilter = TEXT("Emp_Name =") + sql + TEXT("'");
	m_ps->Open();
	manager_id = m_ps->m_Emp_NO;
	m_ps->Close();

	// 添加新的部门副经理
	CComboBox *pvicemanage = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO4));
	CString name1, sql1(TEXT("'"));
	pvicemanage->GetLBText(pvicemanage->GetCurSel(), name1);
	sql1 += name1;
	sql1 += TEXT("");
	m_ps->m_strFilter = TEXT("Emp_Name =") + sql1 + TEXT("'");
	m_ps->Open();
	m_ds->Open();

	// 更新dept表
	m_ds->AddNew();
	m_ds->m_Dept_Name = deptname;
	m_ds->m_Dept_Manager = manager_id;
	m_ds->m_Dept_ViceManager = m_ps->m_Emp_NO;
	m_ds->Update();

	m_ds->Close();
	m_ps->Close();

	// 更新personnel表
	m_ds->m_strFilter = TEXT("Dept_Name = '") + deptname + TEXT("'");
	m_ds->Open();

	CPersonSet *ps = new CPersonSet(((CTrainApp*)AfxGetApp())->m_connector);
	ps->m_strFilter = TEXT("Emp_Name =") + sql + TEXT("'");
	ps->Open();
	ps->Edit();
	ps->m_Dept_ID = m_ds->m_Dept_ID;
	ps->Update();
	ps->Close();

	ps->m_strFilter = TEXT("Emp_Name = ") + sql1 + TEXT("'");
	ps->Open();
	ps->Edit();
	ps->m_Dept_ID = m_ds->m_Dept_ID;
	ps->Update();
	ps->Close();

	m_ds->Close();
}
