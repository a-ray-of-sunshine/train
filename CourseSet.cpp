// CourseSet.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseSet

IMPLEMENT_DYNAMIC(CCourseSet, CRecordset)

CCourseSet::CCourseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCourseSet)
	m_Course_ID = 0;
	m_Subject = _T("");
	m_Course_Cname = _T("");
	m_Course_Ename = _T("");
	m_Course_Desc = _T("");
	m_Course_Duration = 0;
	m_Course_Book = _T("");
	m_Course_Equ = 0;
	m_Course_Before = 0;
	m_Course_Mark = 0;
	m_Dept_ID = 0;
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCourseSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=DataSource2MySQL");
}

CString CCourseSet::GetDefaultSQL()
{
	return _T("[course]");
}

void CCourseSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCourseSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Byte(pFX, _T("[Course_ID]"), m_Course_ID);
	RFX_Text(pFX, _T("[Subject]"), m_Subject);
	RFX_Text(pFX, _T("[Course_Cname]"), m_Course_Cname);
	RFX_Text(pFX, _T("[Course_Ename]"), m_Course_Ename);
	RFX_Text(pFX, _T("[Course_Desc]"), m_Course_Desc);
	RFX_Byte(pFX, _T("[Course_Duration]"), m_Course_Duration);
	RFX_Text(pFX, _T("[Course_Book]"), m_Course_Book);
	RFX_Byte(pFX, _T("[Course_Equ]"), m_Course_Equ);
	RFX_Byte(pFX, _T("[Course_Before]"), m_Course_Before);
	RFX_Byte(pFX, _T("[Course_Mark]"), m_Course_Mark);
	RFX_Byte(pFX, _T("[Dept_ID]"), m_Dept_ID);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCourseSet diagnostics

#ifdef _DEBUG
void CCourseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
