#if !defined(AFX_PERSONSET_H__33D1FDA6_6E2D_4623_BF72_88AF5489C734__INCLUDED_)
#define AFX_PERSONSET_H__33D1FDA6_6E2D_4623_BF72_88AF5489C734__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonSet recordset

class CPersonSet : public CRecordset
{
public:
	CPersonSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPersonSet)

// Field/Param Data
	//{{AFX_FIELD(CPersonSet, CRecordset)
	BYTE	m_Emp_NO;
	CString	m_Emp_Name;
	BYTE	m_Dept_ID;
	CString	m_Emp_XL;
	CString	m_Emp_Gender;
	CString	m_Emp_Birthday;
	CString	m_Emp_Hometown;
	CString	m_Emp_Country;
	CString	m_Emp_Nation;
	CString	m_Emp_ID;
	CString	m_Emp_Marriage;
	CString	m_Emp_Health;
	CString	m_Emp_StartWork;
	CString	m_Emp_State;
	CString	m_Emp_State_Date;
	CString	m_Emp_HomeAddress;
	CString	m_Emp_Teleno;
	CString	m_Emp_Email;
	BYTE	m_Job_ID;
	BYTE m_Emp_NO_Param;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonSet)
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

#endif // !defined(AFX_PERSONSET_H__33D1FDA6_6E2D_4623_BF72_88AF5489C734__INCLUDED_)
