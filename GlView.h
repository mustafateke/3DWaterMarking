#if !defined(AFX_GLVIEW_H__6A408C2D_B713_4D84_8500_C4FD27AB2713__INCLUDED_)
#define AFX_GLVIEW_H__6A408C2D_B713_4D84_8500_C4FD27AB2713__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGlView window
#include <vector>
using namespace std;
#include "dlgogl.h"
#include <gl/gl.h> 
#include <gl/glu.h> 


class CGlView : public CWnd
{
// Construction
public:
	CGlView(CWnd *pclWnd);

// Attributes
public:
 	HDC  m_hDC;					// GDI Device Context 
    HGLRC	m_hglRC;			// Rendering Context

    CWnd *m_pclWnd;
    HWND m_hWnd;

	
// Operations
public:
	BOOL SetPixelformat(HDC hdc);		// Set Pixel Format Required for Rendering
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height); // On Resize Call this Function and reRender
	int InitGL(GLvoid);			// Initialize openGL
	int DrawGLScene(GLvoid);	// Draw Objects
	void rotateSpace(int x,int y,int z,int flag);
	void updateVertex( int x, int y, int point );
	int LoadGLTextures();
	int OnCreate();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlView)
	protected:
//	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGlView();

	// Generated message map functions
protected:

public:
	int traiangleSayac;
	void loadTriangleData(vector<CVector3> triangles, vector<CVector3> vertices, vector<CVector4> quads);
	int refFlag;							// Set to 1 if any Reference Points is Setted
	int spaceCoor[3];						// Angles of Turn
	int spaceFlag;							// Set to 1 if Rotated

	CStatic *pclStatic;
	char* file;					// Pointer Holds the Name of the File
	CString my_string;			// Temp string
	float zoom_factor;
	float sclae_factor;			// Scaler for 3D models.
	CPoint rotater;
	CPoint movement;
	vector<CVector3> Triangles;
	vector<CVector3> Vertices;
	vector<CVector4> Quads;
	vector<int> _dataKey; // passed triangles
	vector<int> _outsideKey;// path of the triangles


	//{{AFX_MSG(CGlView)
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnDestroy();
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLVIEW_H__6A408C2D_B713_4D84_8500_C4FD27AB2713__INCLUDED_)
