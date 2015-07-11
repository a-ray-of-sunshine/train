#if !defined(AFX_JOBDEPTMANAGE_H__408CF4A5_4B59_4FA5_80FA_BA0ADFF12D70__INCLUDED_)
#define AFX_JOBDEPTMANAGE_H__408CF4A5_4B59_4FA5_80FA_BA0ADFF12D70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JobDeptManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJobDeptManage dialog

class CJobDeptManage : public CDialog
{
// Construction
public:
	CJobDeptManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJobDeptManage)
	enum { IDD = IDD_DIALOG5 };
	CListCtrl	m_DeptInfo;
	CListCtrl	m_JobInfo;
	//}}AFX_DATA
	
	enum
	{
		JOBDEPT_JOBINFO,
		JOBDEPT_DEPTINFO
	};

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobDeptManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJobDeptManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_operate;
	void GetDeptInfo();
	void GetJobInfo();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBDEPTMANAGE_H__408CF4A5_4B59_4FA5_80FA_BA0ADFF12D70__INCLUDED_)
