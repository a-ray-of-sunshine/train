// trainDlg.h : header file
//

#if !defined(AFX_TRAINDLG_H__0A553EC9_6FA8_4095_9031_C6C4303FAE57__INCLUDED_)
#define AFX_TRAINDLG_H__0A553EC9_6FA8_4095_9031_C6C4303FAE57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CTrainDlg dialog

class CTrainDlg : public CDialog
{
// Construction
public:
	CTrainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrainDlg)
	enum { IDD = IDD_TRAIN_DIALOG };
	CString	m_Password;
	CString	m_UserName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	MainDialog * md;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINDLG_H__0A553EC9_6FA8_4095_9031_C6C4303FAE57__INCLUDED_)
