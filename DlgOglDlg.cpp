#include "stdafx.h"
#include "DlgOgl.h"
#include "DlgOglDlg.h"
#include <stdio.h>
#include "WireFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDlgOglDlg dialog

CDlgOglDlg::CDlgOglDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOglDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOglDlg)
	m_strFileInfo = _T("");
	m_strWatermarkResults = _T("");
	m_iNoiseLevel = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	spaceFlag = 0;								// No Rotation
	for(int i =0; i<3;i++)						// Set Turn Angles To Zero Degre
		spaceCoor[i]=0;

	/*******************/
	mouseXref = 20;								// Mouse offset from x
	mouseYref = 20;								// Mouse offset from y		
	mouseFlag = 0;								// Left Button is not Clicked
	moveFlag = 0;
	TSPS_OBJ = new TSPS;
	ObjLoader_OBJ = new ObjLoader;
	sayac = 0;
	zoom = 0;									// Used in zooming the model
	posChange.x = 0;
	posChange.y = 0;
	scale = 1;
	

}

void CDlgOglDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOglDlg)
	DDX_Control(pDX, IDC_MouseCoord, m_mouseCoordinates);
	DDX_Control(pDX, IDC_ROTSLIDER2, m_RotSlider2);
	DDX_Text(pDX, IDC_STATIC_FILE_INFO, m_strFileInfo);
	DDX_Text(pDX, IDC_STATIC_WAT_RESULT, m_strWatermarkResults);
	DDX_Text(pDX, IDC_EDIT_NOISE, m_iNoiseLevel);
	DDV_MinMaxInt(pDX, m_iNoiseLevel, 0, 1000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgOglDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgOglDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, OnAbout)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, OnReset)
	ON_BN_CLICKED(IDC_FILE_OPEN, OnFileOpen)
	ON_BN_CLICKED(IDC_OBJ_OPEN, OnObjOpen)
	ON_BN_CLICKED(IDC_BUTTON_WATERMARK, OnButtonWatermark)
	ON_BN_CLICKED(IDC_BUTTON_GET_DATA, OnButtonGetData)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NOISE, OnButtonAddNoise)
	ON_BN_CLICKED(IDC_BUTTON_Zoom_In, OnBUTTONZoomIn)
	ON_BN_CLICKED(IDC_BUTTON_Zoom_Out, OnBUTTONZoomOut)
	ON_EN_CHANGE(IDC_EDIT_NOISE, OnChangeEditNoise)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_OBJ_Caller, OnOBJCaller)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOglDlg message handlers

BOOL CDlgOglDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	/*******************/	

	m_pRotSlider = &m_RotSlider2;				// Y scroll
	/*******************/
	m_pRotSlider->SetRange(-100, 100, TRUE);

	/*******************/
	m_pRotSlider->SetPos(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgOglDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


void CDlgOglDlg::OnPaint() 
{


	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

														
	CPaintDC dc(this);							// device context for painting
	CStatic	*pclStatic = (CStatic *)GetDlgItem(IDC_OPENGLWIN);// Create Handle for OpenGL view
	CGlView *pclGlView = new CGlView(pclStatic);
	
	/*******************/
	if(ObjLoader_OBJ->loadFlag)
	{
		if (TSPS_OBJ !=NULL) {
			pclGlView->loadTriangleData(TSPS_OBJ->Triangles,TSPS_OBJ->Vertices, TSPS_OBJ->Quads);
		}
		else
			pclGlView->loadTriangleData(ObjLoader_OBJ->triangles,ObjLoader_OBJ->vertices, ObjLoader_OBJ->quads);
		pclGlView->rotater = posChange;
		pclGlView->zoom_factor = zoom;
		pclGlView->sclae_factor = scale;
		pclGlView->_dataKey = TSPS_OBJ->dataKey;
		pclGlView->_outsideKey = TSPS_OBJ->outsideKey;
		pclGlView->movement = posChange;

	}
	
	
	/*******************/
	HDC m_hDC;
    m_hDC = ::GetDC(this->m_hWnd);
	
	RECT rect;
	GetClientRect(&rect);

    int iWidth = -(rect.right - rect.left);
    int iHeight = rect.top - rect.bottom;

	/*******************/
	
	pclGlView->OnCreate();
	pclGlView->ReSizeGLScene(iWidth, iHeight);
	pclGlView->InitGL();
	
	/*******************/
	
	if( m_szFile != "")
		pclGlView->my_string = m_szFile;


	UpdateData( true );
	/*******************/

	/*******************/
	pclGlView->rotateSpace(spaceCoor[0],spaceCoor[1],spaceCoor[2],spaceFlag);
	/*******************/
	
	pclGlView->LoadGLTextures();				// Load Texture Map
	pclGlView->DrawGLScene();					// Draw OpenGL Scene
	
	/*******************/

	delete pclGlView;							// Free dynamically allocated storage
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgOglDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgOglDlg::OnCancel() 
{
	// Closes the Dialog,used for test Purposes
	
	CDialog::OnCancel();
}

void CDlgOglDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
		
//	point.x = point.x-mouseXref;				// Set the Reference Points
//	point.y = point.y-mouseYref;				// since Our Image Begins from (55,55)
	/*******************/
	
	if( (point.x > 10 && point.x <530 ) && (point.y > 10 && point.y < 530) )
	{							// Set Cursor If Left Click On a Reference Point
		if (!moveFlag) {
			HCURSOR lhCursor; 
			
			 lhCursor = AfxGetApp()->LoadCursor(IDC_CURSOR3);
			  // Set the screen cursor
			 SetCursor(lhCursor);
			 
		}
		if (moveFlag) {
			HCURSOR lhCursor;    
				 lhCursor = AfxGetApp()->LoadCursor(IDC_CURSOR4);
				  // Set the screen cursor
				 SetCursor(lhCursor);
		}
		mouseFlag = 1;
	}

	sprintf(buf,"\t[Mouse Coordinates] \tx:%d, y:%d",point.x,point.y); 
	m_mouseCoordinates.SetWindowText(buf);	  	// Call of Set Window Text Function

	CDialog::OnMouseMove(nFlags, point);
}


void CDlgOglDlg::OnAbout()						// About Dialog Box Opens
{
		CAboutDlg dlg;
	    dlg.DoModal();	
}


void CDlgOglDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CSliderCtrl *pSlide = (CSliderCtrl *)pScrollBar;
	//for (int i = 0; i < 3; i++){
		if (m_pRotSlider == pSlide)
		{
			spaceCoor[1] = m_pRotSlider->GetPos();// Get the Value Of the Sliders
		
		}
		else
			spaceCoor[1] = 0;
//	}

	/*******************/
	spaceFlag=1;								// Set Rotate Flag

	OnPaint();									// Drawn Scene with new rotating information
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDlgOglDlg::OnReset() 						// Resets the View
{
	spaceFlag = 0;								// Don't Rotate since Spece flag is zero
	
	/*******************/
	for(int i =0; i<3;i++)							// Set Turn Angles To Zero Degre
		spaceCoor[i]=0;
	/*******************/

	m_pRotSlider->SetPos(0);
	zoom = 0;
	delete TSPS_OBJ;
	delete ObjLoader_OBJ;

	TSPS_OBJ = new TSPS;
	ObjLoader_OBJ = new ObjLoader;
	posChange = 0;

	OnPaint();									// Render Scene

}


/*******************/

void CDlgOglDlg::OnFileOpen()					// File Open Func. Uses ImageMagick
{

	CFileDialog dlg(TRUE,"*.* *.*","",OFN_HIDEREADONLY,"Bitmap Files (*.bmp)|*.bmp|GIF Files (*.gif)|*.gif|JPEG Files(*.jpg)|*.jpeg||",this);
	dlg.m_ofn.lpstrTitle = "Select Bitmap";
	if(dlg.DoModal() == IDOK){
		m_szFile=dlg.GetPathName();

		BeginWaitCursor();	

	}
		 
    EndWaitCursor();

	OnPaint();									// Draw the Scene
	
}

void CDlgOglDlg::OnObjOpen() 
{
	CFileDialog dlg(TRUE,"*.* *.*","",OFN_HIDEREADONLY,"Object Files (*.obj)|*.obj||",this);
	dlg.m_ofn.lpstrTitle = "Object Open";
	if(dlg.DoModal() == IDOK){
		m_szFile_obj=dlg.GetPathName();

		delete TSPS_OBJ;
		delete ObjLoader_OBJ;

		TSPS_OBJ = new TSPS;
		ObjLoader_OBJ = new ObjLoader;
		
		BeginWaitCursor();	
		ObjLoader_OBJ->loadModel(m_szFile_obj.GetBuffer(100));
		//MessageBox(ObjLoader_OBJ->objProperties);
		ObjLoader_OBJ->loadFlag = 1;
		m_strFileInfo = ObjLoader_OBJ->objProperties;
		UpdateData(FALSE);

		
	}
	if (TSPS_OBJ != NULL) {
		delete TSPS_OBJ;
		TSPS_OBJ = new TSPS;
	}
	TSPS_OBJ->setGeometry(ObjLoader_OBJ->triangles,ObjLoader_OBJ->vertices,ObjLoader_OBJ->quads,ObjLoader_OBJ->NumberOfVertices);
    EndWaitCursor();
	float x1 = ObjLoader_OBJ->triangles.size();
	reScaleModel();
	OnPaint();

}

void CDlgOglDlg::OnButtonWatermark() 
{	
/*
 *	Data Hiding performed by this function
 *	-It loads the geometry in the file to
 *	TSPS objects
 *	-Creates the data key
 *	-Find out smallest triangle
 *	-Set Path at which information will be watermarked
 *	-Hide Data to Triangles
 */

	if (TSPS_OBJ != NULL) {
		//delete TSPS_OBJ;
		TSPS_OBJ = NULL;
	}
	TSPS_OBJ = new TSPS;
	TSPS_OBJ->setGeometry(ObjLoader_OBJ->triangles,ObjLoader_OBJ->vertices,ObjLoader_OBJ->quads,ObjLoader_OBJ->NumberOfVertices);
	TSPS_OBJ->createDataKey();
	TSPS_OBJ->getSmallestTraingle();
	TSPS_OBJ->setPath();
	TSPS_OBJ->HideData(0);

	OnPaint();
}

void CDlgOglDlg::OnButtonGetData() 
{
	TSPS_OBJ->getData();	
	TSPS_OBJ->errCounter;
	CString output;
	output.Format("Error: %d\nOutside Triangles: %d\nTotal Load: %d",TSPS_OBJ->errCounter,TSPS_OBJ->outsides,TSPS_OBJ->payLoadSize);
	//MessageBox(output);
	m_strWatermarkResults = output;
	UpdateData(FALSE);


}

void  CDlgOglDlg::OnButtonAddNoise() 
{
	TSPS_OBJ->addNoise(m_iNoiseLevel);
	OnPaint();
}


void CDlgOglDlg::OnBUTTONZoomIn() 
{
	zoom += 5.0f;
	scale += 0.1f;
	OnPaint();
}

void CDlgOglDlg::OnBUTTONZoomOut() 
{
	zoom += -5.0f;
	scale += -0.1f;
	OnPaint();
}


void CDlgOglDlg::OnChangeEditNoise() 
{
	UpdateData(TRUE);
}
/*
void CDlgOglDlg::OnObjWireframe() 
{
	WireFrame my_WireFrame;
	vector<CVector3>		tempTriangles;
	vector<CVector3>		tempPoints;
	CVector3	tempVector;

	for(int i = 0; i < 100; i++)
	{
		tempVector.x = my_WireFrame.TRIANGLES[i][0];
		tempVector.y = my_WireFrame.TRIANGLES[i][1];
		tempVector.z = my_WireFrame.TRIANGLES[i][2];

		tempTriangles.push_back(tempVector);
	}

	

	for(i = 0; i < 68; i++)
	{
		tempVector.x = my_WireFrame.Points[i][0];
		tempVector.y = my_WireFrame.Points[i][1];
		tempVector.z = my_WireFrame.Points[i][2];

		tempPoints.push_back(tempVector);
	}

	TSPS_OBJ->writeModel(tempTriangles,tempPoints);
}*/

void CDlgOglDlg::reScaleModel()
{
	float maxPoint = 0;
	if(TSPS_OBJ->NumberOfFaces == 3)
		for(int i = 0; i < 10 ; i++)
		{	
			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].x))
				maxPoint = abs(TSPS_OBJ->Vertices[i].x);

			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].y))
				maxPoint = abs(TSPS_OBJ->Vertices[i].y);

			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].z))
				maxPoint = abs(TSPS_OBJ->Vertices[i].z);
		}

	else
		for(int i = 0; i < TSPS_OBJ->Vertices.size()-10 ; i++)
		{	
			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].x))
				maxPoint = abs(TSPS_OBJ->Vertices[i].x);

			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].y))
				maxPoint = abs(TSPS_OBJ->Vertices[i].y);

			if(maxPoint <= abs(TSPS_OBJ->Vertices[i].z))
				maxPoint = abs(TSPS_OBJ->Vertices[i].z);
		}

	scale = 100.0f/maxPoint;
	
}

void CDlgOglDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( mouseFlag )						
		 moveFlag = 1;
	mousePosition = point;
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgOglDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (moveFlag) {
		posChange.x -= mousePosition.x - point.x;
		posChange.y += mousePosition.y - point.y;
		posChange.x /= 3;
		posChange.y /= 3;
		moveFlag = 0;
	}
	CDialog::OnLButtonUp(nFlags, point);
	OnPaint();
}

void CDlgOglDlg::OnOBJCaller() 
{
	vector<CVector3>		tempTriangles;
	vector<CVector3>		tempPoints;
	CVector3	tempVector;

	for(int i = 0; i < TSPS_OBJ->Quads.size(); i++)
	{
		tempVector.x = TSPS_OBJ->Quads[i].x;
		tempVector.y = TSPS_OBJ->Quads[i].y;
		tempVector.z = TSPS_OBJ->Quads[i].z;

		tempTriangles.push_back(tempVector);
	}

	

	for(int i = 0; i < TSPS_OBJ->Vertices.size(); i++)
	{
		tempVector.x = TSPS_OBJ->Vertices[i].x;
		tempVector.y = TSPS_OBJ->Vertices[i].y;
		tempVector.z = TSPS_OBJ->Vertices[i].z;

		tempPoints.push_back(tempVector);
	}

	TSPS_OBJ->writeModel(tempTriangles,tempPoints);	
}
