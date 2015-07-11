// PersonnelPlan.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "PersonnelPlan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonnelPlan dialog


CPersonnelPlan::CPersonnelPlan(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonnelPlan::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonnelPlan)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPersonnelPlan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonnelPlan)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonnelPlan, CDialog)
	//{{AFX_MSG_MAP(CPersonnelPlan)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonnelPlan message handlers
