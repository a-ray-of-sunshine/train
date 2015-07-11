#if !defined(AFX_JOBSET_H__092E827C_03A0_468F_B7A8_0A96743DBBFD__INCLUDED_)
#define AFX_JOBSET_H__092E827C_03A0_468F_B7A8_0A96743DBBFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JobSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJobSet recordset

class CJobSet : public CRecordset
{
public:
	CJobSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CJobSet)

// Field/Param Data
	//{{AFX_FIELD(CJobSet, CRecordset)
	BYTE	m_Job_ID;
	CString	m_Job_Name;
	CString	m_Job_Power;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobSet)
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
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBSET_H__092E827C_03A0_468F_B7A8_0A96743DBBFD__INCLUDED_)
