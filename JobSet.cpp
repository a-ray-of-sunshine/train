// JobSet.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "JobSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobSet

IMPLEMENT_DYNAMIC(CJobSet, CRecordset)

CJobSet::CJobSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CJobSet)
	m_Job_ID = 0;
	m_Job_Name = _T("");
	m_Job_Power = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CJobSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=DataSource2MySQL");
}

CString CJobSet::GetDefaultSQL()
{
	return _T("[job]");
}

void CJobSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CJobSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Byte(pFX, _T("[Job_ID]"), m_Job_ID);
	RFX_Text(pFX, _T("[Job_Name]"), m_Job_Name);
	RFX_Text(pFX, _T("[Job_Power]"), m_Job_Power);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CJobSet diagnostics

#ifdef _DEBUG
void CJobSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CJobSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

