// train.h : main header file for the TRAIN application
//

#if !defined(AFX_TRAIN_H__FAE2DDA1_678D_49E5_A30E_56C9E5E1594E__INCLUDED_)
#define AFX_TRAIN_H__FAE2DDA1_678D_49E5_A30E_56C9E5E1594E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrainApp:
// See train.cpp for the implementation of this class
//

class CTrainApp : public CWinApp
{
public:
	CDatabase *m_connector;
	CTrainApp();
	~CTrainApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrainApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAIN_H__FAE2DDA1_678D_49E5_A30E_56C9E5E1594E__INCLUDED_)
