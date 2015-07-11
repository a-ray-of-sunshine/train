#if !defined(AFX_COURSEMANAGE_H__06F21077_1243_4A34_ABBA_6640D83278E1__INCLUDED_)
#define AFX_COURSEMANAGE_H__06F21077_1243_4A34_ABBA_6640D83278E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseManage dialog

class CCourseManage : public CDialog
{
// Construction
public:
	CCourseManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCourseManage)
	enum { IDD = IDD_DIALOG9 };
	CListCtrl	m_CourseList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCourseManage)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSEMANAGE_H__06F21077_1243_4A34_ABBA_6640D83278E1__INCLUDED_)
