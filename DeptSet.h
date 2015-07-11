#if !defined(AFX_DEPTSET_H__7F2DCFDE_CCF4_4697_AD28_220C3980E1F0__INCLUDED_)
#define AFX_DEPTSET_H__7F2DCFDE_CCF4_4697_AD28_220C3980E1F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptSet recordset

class CDeptSet : public CRecordset
{
public:
	CDeptSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDeptSet)

// Field/Param Data
	//{{AFX_FIELD(CDeptSet, CRecordset)
	BYTE	m_Dept_ID;
	CString	m_Dept_Name;
	BYTE	m_Dept_Manager;
	BYTE	m_Dept_ViceManager;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptSet)
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

#endif // !defined(AFX_DEPTSET_H__7F2DCFDE_CCF4_4697_AD28_220C3980E1F0__INCLUDED_)
