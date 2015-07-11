#if !defined(AFX_PERSONNELMANAGE_H__2235C30A_888A_42A0_A1A6_C656DA71328F__INCLUDED_)
#define AFX_PERSONNELMANAGE_H__2235C30A_888A_42A0_A1A6_C656DA71328F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonnelManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonnelManage dialog

class CPersonnelManage : public CDialog
{
// Construction
public:
	CPersonnelManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonnelManage)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_PersonnelInfo;
	//}}AFX_DATA

	enum
	{
		PERSONNEL_INFO,
		PERSONNEL_PLAN,
		PERSONNEL_SCORE,
		PERSONNEL_DEMAND,
		PERSONNEL_NONE = -1
	};

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonnelManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonnelManage)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void IsInfoCheck();
	afx_msg void IsPlanCheck();
	afx_msg void IsScoreCheck();
	afx_msg void IsDemandCheck();
	afx_msg void OnUpdate();
	afx_msg void OnDelete();
	afx_msg void ClickHandler();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdatePersonnel();
	void DeletePersonnel();
	int m_operate;
	void GetPersonnelInfo();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONNELMANAGE_H__2235C30A_888A_42A0_A1A6_C656DA71328F__INCLUDED_)
