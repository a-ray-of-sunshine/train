// JobDeptManage.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "JobDeptManage.h"
#include "JobSet.h"
#include "DeptSet.h"
#include "GetJobInfo.h"
#include "GetDeptInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobDeptManage dialog


CJobDeptManage::CJobDeptManage(CWnd* pParent /*=NULL*/)
	: CDialog(CJobDeptManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJobDeptManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_operate = CJobDeptManage::JOBDEPT_JOBINFO;
}


void CJobDeptManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJobDeptManage)
	DDX_Control(pDX, IDC_LIST2, m_DeptInfo);
	DDX_Control(pDX, IDC_LIST1, m_JobInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJobDeptManage, CDialog)
	//{{AFX_MSG_MAP(CJobDeptManage)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDCANCEL2, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJobDeptManage message handlers

BOOL CJobDeptManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);

	GetJobInfo();
	GetDeptInfo();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CJobDeptManage::GetJobInfo()
{
	CJobSet *js = new CJobSet(reinterpret_cast<CTrainApp*>(AfxGetApp())->m_connector);
	js->Open();

	LVCOLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	
	// 设置列标题
	CODBCFieldInfo fieldinfo;
	for(int i = 0; i < (signed)js->m_nFields; i++)
	{
		js->GetODBCFieldInfo((short)i, fieldinfo);
		col.pszText = fieldinfo.m_strName.GetBuffer(fieldinfo.m_strName.GetLength());
		col.cx = lstrlen(col.pszText) * 13;
		this->m_JobInfo.InsertColumn(i, &col);
	}

	// 设置每一列的数据
	TCHAR str[32];
	for(int j = 0; j < js->GetRecordCount(); j++)
	{
		this->m_JobInfo.InsertItem(j, _itot(js->m_Job_ID, str, 10));
		this->m_JobInfo.SetItemText(j, 1, js->m_Job_Name);
		this->m_JobInfo.SetItemText(j, 2, js->m_Job_Power);

		js->MoveNext();
	}

	js->Close();
}

void CJobDeptManage::GetDeptInfo()
{
	CDeptSet *ds = new CDeptSet(reinterpret_cast<CTrainApp*>(AfxGetApp())->m_connector);
	ds->Open();

	LVCOLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	
	// 设置列标题
	CODBCFieldInfo fieldinfo;
	for(int i = 0; i < (signed)ds->m_nFields; i++)
	{
		ds->GetODBCFieldInfo((short)i, fieldinfo);
		col.pszText = fieldinfo.m_strName.GetBuffer(fieldinfo.m_strName.GetLength());
		col.cx = lstrlen(col.pszText) * 10;
		this->m_DeptInfo.InsertColumn(i, &col);
	}

	// 设置每一列的数据
	TCHAR str[32];
	for(int j = 0; j < ds->GetRecordCount(); j++)
	{
		this->m_DeptInfo.InsertItem(j, _itot(ds->m_Dept_ID, str, 10));
		this->m_DeptInfo.SetItemText(j, 1, ds->m_Dept_Name);
		this->m_DeptInfo.SetItemText(j, 2, _itot(ds->m_Dept_Manager, str, 10));
		this->m_DeptInfo.SetItemText(j, 3, _itot(ds->m_Dept_ViceManager, str, 10));

		ds->MoveNext();
	}

	ds->Close();
}

void CJobDeptManage::OnRadio1()
{
	this->m_operate = CJobDeptManage::JOBDEPT_JOBINFO;	
}

void CJobDeptManage::OnRadio2() 
{
	this->m_operate = CJobDeptManage::JOBDEPT_DEPTINFO;	
}

void CJobDeptManage::OnOK() 
{
	CGetJobInfo gji;
	CGetDeptInfo gdi;

	switch(m_operate)
	{
		case CJobDeptManage::JOBDEPT_JOBINFO:
			gji.DoModal();
			//CDialog::OnOK();
			break;
		case CJobDeptManage::JOBDEPT_DEPTINFO:
			gdi.DoModal();
			break;
	}
}



void CJobDeptManage::OnDelete() 
{
	switch(m_operate)
	{
		case CJobDeptManage::JOBDEPT_JOBINFO:

			break;
		case CJobDeptManage::JOBDEPT_DEPTINFO:
			break;
	}
}
