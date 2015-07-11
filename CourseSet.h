#if !defined(AFX_COURSESET_H__13A646B7_7356_4FB0_9FB4_C878389C56B1__INCLUDED_)
#define AFX_COURSESET_H__13A646B7_7356_4FB0_9FB4_C878389C56B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseSet recordset

class CCourseSet : public CRecordset
{
public:
	CCourseSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseSet, CRecordset)
	BYTE	m_Course_ID;
	CString	m_Subject;
	CString	m_Course_Cname;
	CString	m_Course_Ename;
	CString	m_Course_Desc;
	BYTE	m_Course_Duration;
	CString	m_Course_Book;
	BYTE	m_Course_Equ;
	BYTE	m_Course_Before;
	BYTE	m_Course_Mark;
	BYTE	m_Dept_ID;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESET_H__13A646B7_7356_4FB0_9FB4_C878389C56B1__INCLUDED_)
