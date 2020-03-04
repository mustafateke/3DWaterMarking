// DlgOgl.h : main header file for the DLGOGL application
//

#if !defined(AFX_DLGOGL_H__C6288FC5_B215_49A5_9AB0_61AB83CA4C38__INCLUDED_)
#define AFX_DLGOGL_H__C6288FC5_B215_49A5_9AB0_61AB83CA4C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"							// main symbols
#define xCor 0									// To make Arrays more Readable 
#define yCor 1
#define zCor 2
//#include <Magick++.h>							// Use ImageMagick
//using namespace Magick;
#include <vector>

class CVector3 
{
public:
	float x, y, z;
};

// This is our 2D point class.  This will be used to store the UV coordinates.
class CVector2 
{
public:
	float x, y;
};

class CVector4 
{
public:
	float x, y, z, w;
};

/////////////////////////////////////////////////////////////////////////////
// CDlgOglApp:
// See DlgOgl.cpp for the implementation of this class
//

class CDlgOglApp : public CWinApp
{
public:
	CDlgOglApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOglApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgOglApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOGL_H__C6288FC5_B215_49A5_9AB0_61AB83CA4C38__INCLUDED_)
