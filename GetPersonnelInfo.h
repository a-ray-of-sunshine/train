#if !defined(AFX_GETPERSONNELINFO_H__402A5D6B_6BBF_4A79_9037_5BBB0424C97E__INCLUDED_)
#define AFX_GETPERSONNELINFO_H__402A5D6B_6BBF_4A79_9037_5BBB0424C97E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetPersonnelInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGetPersonnelInfo dialog

class CGetPersonnelInfo : public CDialog
{
// Construction
public:
	CGetPersonnelInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGetPersonnelInfo)
	enum { IDD = IDD_DIALOG4 };
	CComboBox	m_Job_ID;
	CComboBox	m_DeptID;
	CComboBox	m_State;
	CComboBox	m_Health;
	CComboBox	m_Marriage;
	CComboBox	m_Gender;
	CComboBox	m_XL;
	CString	m_Name;
	CTime	m_Birthday;
	CString	m_Hometown;
	CString	m_Country;
	CString	m_Nation;
	CString	m_ID;
	CTime	m_WorkTime;
	CTime	m_StateTime;
	CString	m_HomeAddress;
	CString	m_Phone;
	CString	m_E_mail;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPersonnelInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetPersonnelInfo)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPERSONNELINFO_H__402A5D6B_6BBF_4A79_9037_5BBB0424C97E__INCLUDED_)
