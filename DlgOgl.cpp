// DlgOgl.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DlgOgl.h"
#include "DlgOglDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOglApp

BEGIN_MESSAGE_MAP(CDlgOglApp, CWinApp)
	//{{AFX_MSG_MAP(CDlgOglApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOglApp construction

CDlgOglApp::CDlgOglApp()
{

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDlgOglApp object

CDlgOglApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDlgOglApp initialization

BOOL CDlgOglApp::InitInstance()
{


	SetDialogBkColor(RGB(100,110,200), RGB(0, 0, 0));	// Respectivly Background and Foreground Colors 
	/*******************/
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CDlgOglDlg dlg;
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

	return FALSE;
}
