#if !defined(AFX_WIREFRAME_H__B7FB2AAE_9E88_493F_B79F_7471EB1DB80F__INCLUDED_)
#define AFX_WIREFRAME_H__B7FB2AAE_9E88_493F_B79F_7471EB1DB80F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WireFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WireFrame window

class WireFrame : public CWnd
{
// Construction
public:
	WireFrame();
	float Points[ 68 ][ 3 ];		// Coordinates of Points
	int TRIANGLES[ 100 ][ 3 ];		// Shows Which Triangle has Which Vertices
	int refPoints[ 10 ];			// Holds Ref Points Number(ie. Nose = 17)
	CPoint refPixel[ 10 ];			// Holds refPoints Pixel Data
	int refFlag[10];
	int Cevre[15];					// Holds Circumference Points

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WireFrame)
	//}}AFX_VIRTUAL

// Implementation
public:

	virtual ~WireFrame();

	// Generated message map functions
protected:
	//{{AFX_MSG(WireFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIREFRAME_H__B7FB2AAE_9E88_493F_B79F_7471EB1DB80F__INCLUDED_)
