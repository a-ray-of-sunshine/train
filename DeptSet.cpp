// DeptSet.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "DeptSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptSet

IMPLEMENT_DYNAMIC(CDeptSet, CRecordset)

CDeptSet::CDeptSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDeptSet)
	m_Dept_ID = 0;
	m_Dept_Name = _T("");
	m_Dept_Manager = 0;
	m_Dept_ViceManager = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDeptSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=DataSource2MySQL");
}

CString CDeptSet::GetDefaultSQL()
{
	return _T("[dept]");
}

void CDeptSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDeptSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Byte(pFX, _T("[Dept_ID]"), m_Dept_ID);
	RFX_Text(pFX, _T("[Dept_Name]"), m_Dept_Name);
	RFX_Byte(pFX, _T("[Dept_Manager]"), m_Dept_Manager);
	RFX_Byte(pFX, _T("[Dept_ViceManager]"), m_Dept_ViceManager);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDeptSet diagnostics

#ifdef _DEBUG
void CDeptSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDeptSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
