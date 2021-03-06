// train.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "train.h"
#include "trainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrainApp

BEGIN_MESSAGE_MAP(CTrainApp, CWinApp)
	//{{AFX_MSG_MAP(CTrainApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainApp construction

CTrainApp::CTrainApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	MessageBox(NULL, TEXT("tianxi"), TEXT("tip"), 0);

	m_connector = new CDatabase;
	if(!(m_connector->Open(TEXT("DataSource2MySQL")/*, FALSE, FALSE, TEXT("ODBC;"), FALSE*/)))
	{
		AfxMessageBox(TEXT("open the database fail."), 0, 0);
	}
	else
	{
		AfxMessageBox(TEXT("open databse success"));
	}
}

CTrainApp::~CTrainApp()
{
	if(m_connector)
	{
		m_connector->Close();
		delete m_connector;
		m_connector = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTrainApp object

CTrainApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTrainApp initialization

BOOL CTrainApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTrainDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
