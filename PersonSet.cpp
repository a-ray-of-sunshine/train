// PersonSet.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "PersonSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonSet

IMPLEMENT_DYNAMIC(CPersonSet, CRecordset)

CPersonSet::CPersonSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPersonSet)
	m_Emp_NO = 0;
	m_Emp_Name = _T("");
	m_Dept_ID = 0;
	m_Emp_XL = _T("");
	m_Emp_Gender = _T("");
	m_Emp_Hometown = _T("");
	m_Emp_Country = _T("");
	m_Emp_Nation = _T("");
	m_Emp_ID = _T("");
	m_Emp_Marriage = _T("");
	m_Emp_Health = _T("");
	m_Emp_State = _T("");
	m_Emp_HomeAddress = _T("");
	m_Emp_Teleno = _T("");
	m_Emp_Email = _T("");
	m_Job_ID = 0;
	m_nFields = 19;
	m_Emp_Birthday = _T("");
	m_Emp_StartWork = _T("");
	m_Emp_State_Date = _T("");
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;

	m_Emp_NO_Param = 0;
	this->m_nParams = 1;
}


CString CPersonSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=DataSource2MySQL");
}

CString CPersonSet::GetDefaultSQL()
{
	return _T("[personnel]");
}

void CPersonSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPersonSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Byte(pFX, _T("[Emp_NO]"), m_Emp_NO);
	RFX_Text(pFX, _T("[Emp_Name]"), m_Emp_Name);
	RFX_Byte(pFX, _T("[Dept_ID]"), m_Dept_ID);
	RFX_Text(pFX, _T("[Emp_XL]"), m_Emp_XL);
	RFX_Text(pFX, _T("[Emp_Gender]"), m_Emp_Gender);
	RFX_Text(pFX, _T("[Emp_Birthday]"), m_Emp_Birthday);
	RFX_Text(pFX, _T("[Emp_Hometown]"), m_Emp_Hometown);
	RFX_Text(pFX, _T("[Emp_Country]"), m_Emp_Country);
	RFX_Text(pFX, _T("[Emp_Nation]"), m_Emp_Nation);
	RFX_Text(pFX, _T("[Emp_ID]"), m_Emp_ID);
	RFX_Text(pFX, _T("[Emp_Marriage]"), m_Emp_Marriage);
	RFX_Text(pFX, _T("[Emp_Health]"), m_Emp_Health);
	RFX_Text(pFX, _T("[Emp_StartWork]"), m_Emp_StartWork);
	RFX_Text(pFX, _T("[Emp_State]"), m_Emp_State);
	RFX_Text(pFX, _T("[Emp_State_Date]"), m_Emp_State_Date);
	RFX_Text(pFX, _T("[Emp_HomeAddress]"), m_Emp_HomeAddress);
	RFX_Text(pFX, _T("[Emp_Teleno]"), m_Emp_Teleno);
	RFX_Text(pFX, _T("[Emp_Email]"), m_Emp_Email);
	RFX_Byte(pFX, _T("[Job_ID]"), m_Job_ID);
	//}}AFX_FIELD_MAP

	pFX->SetFieldType(CFieldExchange::param);
	RFX_Byte(pFX, _T(""), m_Emp_NO_Param);
}

/////////////////////////////////////////////////////////////////////////////
// CPersonSet diagnostics

#ifdef _DEBUG
void CPersonSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPersonSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
