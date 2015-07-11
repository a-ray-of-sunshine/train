#if !defined(AFX_MAINDIALOG_H__B4E56126_0C32_46B7_81E9_03F7B0AC400C__INCLUDED_)
#define AFX_MAINDIALOG_H__B4E56126_0C32_46B7_81E9_03F7B0AC400C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MainDialog dialog

class MainDialog : public CDialog
{
// Construction
public:
	MainDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MainDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MainDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MainDialog)
	virtual void OnCancel();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnPersonnelManage();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDIALOG_H__B4E56126_0C32_46B7_81E9_03F7B0AC400C__INCLUDED_)
