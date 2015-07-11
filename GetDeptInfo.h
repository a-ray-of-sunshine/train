#if !defined(AFX_GETDEPTINFO_H__ED7BB663_95BF_46D6_B33A_B3EE4CCEEC23__INCLUDED_)
#define AFX_GETDEPTINFO_H__ED7BB663_95BF_46D6_B33A_B3EE4CCEEC23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetDeptInfo.h : header file
//

#include "PersonSet.h"
#include "DeptSet.h"
/////////////////////////////////////////////////////////////////////////////
// CGetDeptInfo dialog

class CGetDeptInfo : public CDialog
{
// Construction
public:
	~CGetDeptInfo();
	CGetDeptInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGetDeptInfo)
	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetDeptInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetDeptInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnReset();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDeptSet* m_ds;
	void UpdateDept();
	CPersonSet * m_ps;
	void GetEmpName();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETDEPTINFO_H__ED7BB663_95BF_46D6_B33A_B3EE4CCEEC23__INCLUDED_)
