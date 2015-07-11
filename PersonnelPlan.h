#if !defined(AFX_PERSONNELPLAN_H__4CE0D94C_B3C8_48D8_8840_A0DEC7988FF0__INCLUDED_)
#define AFX_PERSONNELPLAN_H__4CE0D94C_B3C8_48D8_8840_A0DEC7988FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonnelPlan.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonnelPlan dialog

class CPersonnelPlan : public CDialog
{
// Construction
public:
	CPersonnelPlan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonnelPlan)
	enum { IDD = IDD_DIALOG8 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonnelPlan)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonnelPlan)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONNELPLAN_H__4CE0D94C_B3C8_48D8_8840_A0DEC7988FF0__INCLUDED_)
