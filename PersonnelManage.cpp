// PersonnelManage.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "PersonnelManage.h"
#include "personset.h"
#include "GetPersonnelInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonnelManage dialog


CPersonnelManage::CPersonnelManage(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonnelManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonnelManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_operate = CPersonnelManage::PERSONNEL_INFO;
}


void CPersonnelManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonnelManage)
	DDX_Control(pDX, IDC_Personnel, m_PersonnelInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonnelManage, CDialog)
	//{{AFX_MSG_MAP(CPersonnelManage)
	ON_BN_CLICKED(IDC_RADIO1, IsInfoCheck)
	ON_BN_CLICKED(IDC_RADIO2, IsPlanCheck)
	ON_BN_CLICKED(IDC_RADIO3, IsScoreCheck)
	ON_BN_CLICKED(IDC_RADIO4, IsDemandCheck)
	ON_BN_CLICKED(IDB_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDB_DELETE, OnDelete)
	ON_NOTIFY(NM_CLICK, IDC_Personnel, ClickHandler)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonnelManage message handlers

void CPersonnelManage::GetPersonnelInfo()
{
	CPersonSet *ps = new CPersonSet(reinterpret_cast<CTrainApp*>(AfxGetApp())->m_connector);
	ps->Open();

	LVCOLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	
	// 设置列标题
	CODBCFieldInfo fieldinfo;
	for(int i = 0; i < (signed)ps->m_nFields; i++)
	{
		ps->GetODBCFieldInfo((short)i, fieldinfo);
		col.pszText = fieldinfo.m_strName.GetBuffer(fieldinfo.m_strName.GetLength());
		col.cx = lstrlen(col.pszText) * 12;
		this->m_PersonnelInfo.InsertColumn(i, &col);
	}

	// 设置每一列的数据
	TCHAR str[32];
	for(int j = 0; j < ps->GetRecordCount(); j++)
	{
		this->m_PersonnelInfo.InsertItem(j, _itot(ps->m_Emp_NO, str, 10));
		this->m_PersonnelInfo.SetItemText(j, 1, ps->m_Emp_Name);
		this->m_PersonnelInfo.SetItemText(j, 2, _itot(ps->m_Dept_ID, str, 10));
		this->m_PersonnelInfo.SetItemText(j, 3, ps->m_Emp_XL);
		this->m_PersonnelInfo.SetItemText(j, 4, ps->m_Emp_Gender);
		this->m_PersonnelInfo.SetItemText(j, 5, ps->m_Emp_Birthday);
		this->m_PersonnelInfo.SetItemText(j, 6, ps->m_Emp_Hometown);
		this->m_PersonnelInfo.SetItemText(j, 7, ps->m_Emp_Country);
		this->m_PersonnelInfo.SetItemText(j, 8, ps->m_Emp_Nation);
		this->m_PersonnelInfo.SetItemText(j, 9, ps->m_Emp_ID);
		this->m_PersonnelInfo.SetItemText(j, 10, ps->m_Emp_Marriage);
		this->m_PersonnelInfo.SetItemText(j, 11, ps->m_Emp_Health);
		this->m_PersonnelInfo.SetItemText(j, 12, ps->m_Emp_StartWork);
		this->m_PersonnelInfo.SetItemText(j, 13, ps->m_Emp_State);
		this->m_PersonnelInfo.SetItemText(j, 14, ps->m_Emp_State_Date);
		this->m_PersonnelInfo.SetItemText(j, 15, ps->m_Emp_HomeAddress);
		this->m_PersonnelInfo.SetItemText(j, 16, ps->m_Emp_Teleno);
		this->m_PersonnelInfo.SetItemText(j, 17, ps->m_Emp_Email);
		this->m_PersonnelInfo.SetItemText(j, 18, _itot(ps->m_Job_ID, str, 10));

		ps->MoveNext();
	}

	ps->Close();
}

BOOL CPersonnelManage::OnInitDialog() 
{
	CDialog::OnInitDialog();

	reinterpret_cast<CButton*>(GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
	
	this->GetPersonnelInfo();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPersonnelManage::IsInfoCheck()
{
	m_operate = CPersonnelManage::PERSONNEL_INFO;
}

void CPersonnelManage::IsPlanCheck()
{
	m_operate = CPersonnelManage::PERSONNEL_PLAN;
}

void CPersonnelManage::IsScoreCheck()
{
	m_operate = CPersonnelManage::PERSONNEL_SCORE;
}

void CPersonnelManage::IsDemandCheck()
{
	m_operate = CPersonnelManage::PERSONNEL_DEMAND;
}

void CPersonnelManage::OnOK() 
{	
	CGetPersonnelInfo pi;

	switch(m_operate)
	{
		// 添加新员工
		case CPersonnelManage::PERSONNEL_INFO:
			pi.DoModal();
			break;
		// 添加新员工的培训计划
		case CPersonnelManage::PERSONNEL_PLAN:
			break;

		// 添加新员工的成绩
		case CPersonnelManage::PERSONNEL_SCORE:
			break;

		// 添加新员工的需求
		case CPersonnelManage::PERSONNEL_DEMAND:
			break;
	}
}

void CPersonnelManage::OnUpdate() 
{
	switch(m_operate)
	{
		// 更新员工信息
		case CPersonnelManage::PERSONNEL_INFO:
			UpdatePersonnel();
			break;
		// 更新员工的培训计划
		case CPersonnelManage::PERSONNEL_PLAN:
			break;

		// 更新员工的成绩
		case CPersonnelManage::PERSONNEL_SCORE:
			break;

		// 更新员工的需求
		case CPersonnelManage::PERSONNEL_DEMAND:
			break;
	}
}

void CPersonnelManage::OnDelete() 
{
	switch(m_operate)
	{
		// 删除员工
		case CPersonnelManage::PERSONNEL_INFO:
			DeletePersonnel();
			break;
		// 删除员工的培训计划
		case CPersonnelManage::PERSONNEL_PLAN:
			break;

		// 删除员工的成绩
		case CPersonnelManage::PERSONNEL_SCORE:
			break;

		// 删除员工的需求
		case CPersonnelManage::PERSONNEL_DEMAND:
			break;
	}
}

void CPersonnelManage::DeletePersonnel()
{
	CString id;
	POSITION pos;
	int index;
	LPTSTR lpstr;
	BYTE no;

	pos = m_PersonnelInfo.GetFirstSelectedItemPosition();
	index = m_PersonnelInfo.GetNextSelectedItem(pos);
	id = m_PersonnelInfo.GetItemText(index, 0);
	lpstr = id.GetBuffer(id.GetLength());

	no = (BYTE)_ttoi(lpstr);

	CPersonSet *ps = new CPersonSet(((CTrainApp*)AfxGetApp())->m_connector);

	ps->m_strFilter = TEXT("Emp_NO=?");
	ps->m_Emp_NO_Param = no;

	if(IDYES == MessageBox(TEXT("确实要删除该行吗?"), TEXT("提示"), MB_YESNO))
	{
		ps->Open();
		ps->Delete();
		ps->Close();
		m_PersonnelInfo.DeleteItem(index);
		MessageBox(TEXT("已成功删除!"));
	}
}

void CPersonnelManage::UpdatePersonnel()
{
	CString id;
	POSITION pos;
	int index;
	LPTSTR lpstr;
	CGetPersonnelInfo pi;
	CPersonSet *ps = new CPersonSet(((CTrainApp*)AfxGetApp())->m_connector);

	pos = m_PersonnelInfo.GetFirstSelectedItemPosition();
	index = m_PersonnelInfo.GetNextSelectedItem(pos);
	id = m_PersonnelInfo.GetItemText(index, 0);
	lpstr = id.GetBuffer(id.GetLength());

	ps->m_strFilter = TEXT("Emp_NO=?");
	ps->m_Emp_NO_Param = (BYTE)_ttoi(lpstr);

	ps->Open();
	pi.m_Name = ps->m_Emp_Name;
	pi.m_Hometown = ps->m_Emp_Hometown;
	pi.m_Country = ps->m_Emp_Country;
	pi.m_Nation = ps->m_Emp_Nation;
	pi.m_ID = ps->m_Emp_ID;
	pi.m_HomeAddress = ps->m_Emp_HomeAddress;
	pi.m_Phone = ps->m_Emp_Teleno;
	pi.m_E_mail = ps->m_Emp_Email;

	/*
	TCHAR buffer[64];
	//MessageBox(_itot(ps->m_Job_ID, buffer, 10));
	_itot(ps->m_Job_ID, buffer, 10);
	pi.m_Job_ID.SelectString(-1, buffer);
	_itot(ps->m_Dept_ID, buffer, 10);
	pi.m_DeptID.SelectString(-1, buffer);
	*/

	MessageBox(ps->m_Emp_State);
	/*
	pi.m_State.SelectString(-1, ps->m_Emp_State);
	pi.m_Health.SelectString(-1, ps->m_Emp_Health);
	pi.m_Marriage.SelectString(-1, ps->m_Emp_Marriage);
	pi.m_Gender.SelectString(-1, ps->m_Emp_Gender);
	pi.m_XL.SelectString(-1, ps->m_Emp_XL);
	pi.UpdateData(FALSE);
*/
	ps->Close();
	pi.DoModal();
}

void CPersonnelManage::ClickHandler()
{
	// MessageBox(TEXT("Click Handler"));
	CString id;
	POSITION pos;
	int index;
	LPTSTR lpstr;

	pos = m_PersonnelInfo.GetFirstSelectedItemPosition();
	index = m_PersonnelInfo.GetNextSelectedItem(pos);
	id = m_PersonnelInfo.GetItemText(index, 0);
	lpstr = id.GetBuffer(id.GetLength());

	if(lstrcmp(TEXT(""), lpstr))
	{
		//MessageBox(lpstr);
	}
}