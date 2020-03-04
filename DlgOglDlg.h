// DlgOglDlg.h : header file
//

#if !defined(AFX_DLGOGLDLG_H__358FE25E_7791_497E_8082_0F3AECB38D87__INCLUDED_)
#define AFX_DLGOGLDLG_H__358FE25E_7791_497E_8082_0F3AECB38D87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <vector>
using namespace std;
#include "variables.h"
#include "GlView.h"
#include "ObjLoader.h"
#include "TSPS.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgOglDlg dialog

class CDlgOglDlg : public CDialog
{
// Construction
public:
	void reScaleModel();
	int sayac;
	ObjLoader *ObjLoader_OBJ;
	TSPS *TSPS_OBJ;
	int spaceCoor[3];							// Rotating in 3D
	int spaceFlag;								// Set Active if Rotated
	/*******************/
	CPoint temp;								// Temporary varible to hold which Point is 
	CStatic *pclStatic;							// Picture( openGL ) holder
	CDlgOglDlg(CWnd* pParent = NULL);			// standard constructor
	
	char buf[200];								// Buffer Used To Hold and Display Mouse Coord.
	
	/*******************/
	int mouseXref;								// Offset Distance from X
	int mouseYref;								// Offset Distance from Y
	int mouseFlag;								// Flag gets Active if Left Mouse Button is Clicked
	int moveFlag;
	/*******************/
	CString m_szFile;							// String to a File
	CString m_szFile_obj;
	/*******************/

	float zoom;
	float scale;								// Scale 3D Model by that value
	CPoint mousePosition;						// Holds mouse position
	CPoint posChange;
	

// Dialog Data
	//{{AFX_DATA(CDlgOglDlg)
	enum { IDD = IDD_DLGOGL_DIALOG };
	CStatic	m_mouseCoordinates;		// Object Displays Mouse Coordinates
	CSliderCtrl	m_RotSlider2;		// Rot Slider ( Y )
	CString m_Ref_Point;			// Name of The Selected Point
	CSliderCtrl *m_pRotSlider;		// Variable Holds Information from Rot Sliders
	CString	m_strFileInfo;
	CString	m_strWatermarkResults;
	int		m_iNoiseLevel;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOglDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgOglDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);	// Mouse Move MFC Funtion
	afx_msg void OnAbout();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnReset();									// Resets View
	afx_msg void OnFileOpen();
	afx_msg void OnObjOpen();
	afx_msg void OnButtonWatermark();
	afx_msg void OnButtonGetData();
	afx_msg void OnButtonAddNoise();
	afx_msg void OnBUTTONZoomIn();
	afx_msg void OnBUTTONZoomOut();
	afx_msg void OnChangeEditNoise();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnOBJCaller();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOGLDLG_H__358FE25E_7791_497E_8082_0F3AECB38D87__INCLUDED_)
