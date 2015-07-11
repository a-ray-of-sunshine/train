// helo.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "helo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// helo

IMPLEMENT_DYNAMIC(helo, CRecordset)

helo::helo(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(helo)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString helo::GetDefaultConnect()
{
	return _T("ODBC;DSN=DataSource2MySQL");
}

CString helo::GetDefaultSQL()
{
	return _T("");
}

void helo::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(helo)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// helo diagnostics

#ifdef _DEBUG
void helo::AssertValid() const
{
	CRecordset::AssertValid();
}

void helo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
