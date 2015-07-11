#if !defined(AFX_LOGINSET_H__CCC90745_52B6_4795_BA7A_BB834B387C5D__INCLUDED_)
#define AFX_LOGINSET_H__CCC90745_52B6_4795_BA7A_BB834B387C5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginSet recordset

class CLoginSet : public CRecordset
{
public:
	CLoginSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLoginSet)

// Field/Param Data
	//{{AFX_FIELD(CLoginSet, CRecordset)
	CString	m_TMS_User;
	CString	m_TMS_Pswd;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginSet)
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

#endif // !defined(AFX_LOGINSET_H__CCC90745_52B6_4795_BA7A_BB834B387C5D__INCLUDED_)
