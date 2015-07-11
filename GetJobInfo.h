#if !defined(AFX_GETJOBINFO_H__BE514065_F32F_41D4_972F_7459DC31C546__INCLUDED_)
#define AFX_GETJOBINFO_H__BE514065_F32F_41D4_972F_7459DC31C546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetJobInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGetJobInfo dialog

class CGetJobInfo : public CDialog
{
// Construction
public:
	CGetJobInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGetJobInfo)
	enum { IDD = IDD_DIALOG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetJobInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetJobInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnReset();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETJOBINFO_H__BE514065_F32F_41D4_972F_7459DC31C546__INCLUDED_)
