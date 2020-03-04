/*
  Name: GlView.cpp
  Author: Mustafa Teke
  Description: Implementation File
  Date: 09.09.02 16:14
  Copyright: GNU
*/

#include <vector>
#include "stdafx.h"
#include "DlgOgl.h"
#include "GlView.h"
#include <gl\glaux.h>								// Header File For The Glaux Library
#include <gl\gl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GLuint	texture[1];								// Storage For One Texture 
AUX_RGBImageRec* TextureImage[1];				// Create Storage Space For The Texture



/////////////////////////////////////////////////////////////////////////////
// CGlView

CGlView::CGlView(CWnd *pclWnd)					// Contructor
{

    m_pclWnd = pclWnd;
    m_hWnd   = pclWnd->m_hWnd;
    m_hDC    = ::GetDC(m_hWnd);
	/*******************/
	spaceFlag = 0;								// Don't Rotate at Start Up
	spaceCoor[0] = 0;
	spaceCoor[1] = 0;
	spaceCoor[2] = 0;
	my_string = "test.bmp";
	zoom_factor = 0;
}

CGlView::~CGlView()
{
}


BEGIN_MESSAGE_MAP(CGlView, CWnd)
	//{{AFX_MSG_MAP(CGlView)
//	ON_WM_DESTROY()
//	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CGlView message handlers


int CGlView::OnCreate() 
{

    m_hDC = ::GetDC(this->m_hWnd);

    if(!SetPixelformat(m_hDC))
    {
		::MessageBox(::GetFocus(),"SetPixelformat Failed!","Error",MB_OK);
		return -1;
    }

    m_hglRC = wglCreateContext(m_hDC);
    int i= wglMakeCurrent(m_hDC,m_hglRC);

	InitGL();	

	return 0;
}

/*******************/

BOOL CGlView::SetPixelformat(HDC hdc)			// Pixel Formating Vital for Displaying
{

    PIXELFORMATDESCRIPTOR *ppfd; 
    int pixelformat; 
 
    PIXELFORMATDESCRIPTOR pfd = { 
    sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
    1,                     // version number 
    PFD_DRAW_TO_WINDOW |   // support window 
    PFD_SUPPORT_OPENGL |   // support OpenGL 
    PFD_GENERIC_FORMAT |
    PFD_DOUBLEBUFFER,      // double buffered 
    PFD_TYPE_RGBA,         // RGBA type 
    32,                    // 24-bit color depth 
    0, 0, 0, 0, 0, 0,      // color bits ignored 
    8,                     // no alpha buffer 
    0,                     // shift bit ignored 
    8,                     // no accumulation buffer 
    0, 0, 0, 0,            // accum bits ignored 
    64,                    // 32-bit z-buffer	 
    8,                     // no stencil buffer 
    8,                     // no auxiliary buffer 
    PFD_MAIN_PLANE,        // main layer 
    0,                     // reserved 
    0, 0, 0                // layer masks ignored 
    }; 

   
    ppfd = &pfd;

 
    if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 ) 
    { 
        ::MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE) 
    { 
        ::MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    return TRUE; 

}

/*******************/

GLvoid CGlView::ReSizeGLScene(GLsizei width, GLsizei height)	// Resize And Initialize The GL Window
{

	if (height == 0)							// Prevent A Divide By Zero By
	{
		height = 1;								// Making Height Equal One
	}

	glViewport(0,0,width,height);				// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);				// Select The Projection Matrix
	glLoadIdentity();							// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);					// Select The Modelview Matrix
	glLoadIdentity();							// Reset The Modelview Matrix

}

/*******************/

int CGlView::InitGL(GLvoid)						// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);					// Enable Smooth Shading
	glEnable(GL_TEXTURE_2D);					// Enable Texture Mapping
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);		// Black Background
	glClearDepth(1.0f);							// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);					// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);						// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	return TRUE;								// Initialization Went OK
}

/*******************/

int CGlView::LoadGLTextures()					// Load Textures for Texture Mapping, load image
{

	AUX_RGBImageRec *TextureImage[1];			// Create Storage Space For The Texture
	memset(TextureImage,0,sizeof(void *)*1);	// Set The Pointer To NULL

	if(my_string != "test.bmp")
		file = my_string.GetBuffer(100);
	else
		file = "test.bmp";
	
	if (TextureImage[0] = auxDIBImageLoad(file))	// Use a Temporary File
	{
		glGenTextures(1, &texture[0]);			// Create The Texture

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, 
					TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}
	/*******************/
	if (TextureImage[0])									// If Texture Exists
	{
		if (TextureImage[0]->data)							// If Texture Image Exists
		{
			free(TextureImage[0]->data);					// Free The Texture Image Memory
		}

		free(TextureImage[0]);								// Free The Image Structure
	}														// See nehe.gamedev.net for more information

	return 0;	
}

/*******************/

int CGlView::DrawGLScene(GLvoid)						// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
	//float zoom = -15.8f;
	glTranslatef(movement.x,movement.y,zoom_factor - 60.0f);						// Move Left 1.5 Units And Into The Screen 6.0
	glScalef(sclae_factor*.300f,sclae_factor*.200f,sclae_factor*.200f);								// Scale The Screen


	if(spaceFlag != 0){
			glRotatef((float)spaceCoor[0],1.0,0,0);		// Rotate the Shape at given angle and at given Angles
			glRotatef((float)spaceCoor[1],0,1.0,0);
			glRotatef((float)spaceCoor[2],0,0,1.0);
	}
	else glRotatef(0,0,0,0.0);
	
	float scalerx = 0.0023f;
	float scalery = 0.0019f;

	float diffTextX= 0.5f, diffTextY = 0.55f;

	/*******************/


	glBegin(GL_QUADS);								// To Show the Picture draw a Square
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.f, -100.f,  0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 100.f, -100.f,  0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 100.f,  100.f,  0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-100.f,  100.f,  0.0f);
	glEnd();


	/*******************/
	for(int i = 0; i < Triangles.size(); i++){
		glColor3f(1.0f,1.0f,1.0f);

		for(int j = 0; j < _dataKey.size(); j++)
			if (i == _dataKey[j]) {
				glColor3f(1.0f,0.1f,0.7f);

			if (_outsideKey[j]) {
				glColor3f(.50f,0.1f,0.7f);
			}
			}

		glBegin(GL_TRIANGLES);

			glTexCoord2f(scalerx*Vertices[Triangles[i].x ].x - diffTextX,
						 scalery*Vertices[Triangles[i].x ].y - diffTextY);
					
			glVertex3f(	Vertices[Triangles[i].x ].x,
						Vertices[Triangles[i].x ].y,
						Vertices[Triangles[i].x ].z);

			glTexCoord2f(scalerx*Vertices[Triangles[i].y ].x - diffTextX,
						 scalery*Vertices[Triangles[i].y ].y - diffTextY);

			glVertex3f(	Vertices[Triangles[i].y ].x,
						Vertices[Triangles[i].y ].y,
						Vertices[Triangles[i].y ].z);

			glTexCoord2f(scalerx*Vertices[Triangles[i].z ].x - diffTextX,
						 scalery*Vertices[Triangles[i].z ].y - diffTextY);

			glVertex3f(	Vertices[Triangles[i].z ].x,
						Vertices[Triangles[i].z ].y,
						Vertices[Triangles[i].z ].z);
						
			glEnd();
	}


	for(int i = 0; i < Quads.size(); i++){
	
		float a = Quads[i].x;

		glBegin(GL_POLYGON);
			glVertex3f(	Vertices[Quads[i].x ].x,
						Vertices[Quads[i].x ].y,
						Vertices[Quads[i].x ].z);

			glVertex3f(	Vertices[Quads[i].y ].x,
						Vertices[Quads[i].y ].y,
						Vertices[Quads[i].y ].z);

			glVertex3f(	Vertices[Quads[i].z ].x,
						Vertices[Quads[i].z ].y,
						Vertices[Quads[i].z ].z);
			if(Quads[i].w != 0){
				glVertex3f(	Vertices[Quads[i].w ].x,
							Vertices[Quads[i].w ].y,
							Vertices[Quads[i].w ].z);
			}
		glEnd();
	}
	
	glColor3f(1.0f,1.0f,1.0f);
	for(int i = 0; i < Triangles.size(); i++){
		glBegin(GL_LINES);
			glVertex3f(	Vertices[Triangles[i].x ].x,
						Vertices[Triangles[i].x ].y,
						Vertices[Triangles[i].x ].z);

			glVertex3f(	Vertices[Triangles[i].y ].x,
						Vertices[Triangles[i].y ].y,
						Vertices[Triangles[i].y ].z);

		glEnd();

		glBegin(GL_LINES);

			glVertex3f(	Vertices[Triangles[i].x ].x,
						Vertices[Triangles[i].x ].y,
						Vertices[Triangles[i].x ].z);

			glVertex3f(	Vertices[Triangles[i].z ].x,
						Vertices[Triangles[i].z ].y,
						Vertices[Triangles[i].z ].z);
		glEnd();

		glBegin(GL_LINES);

			glVertex3f(	Vertices[Triangles[i].y ].x,
						Vertices[Triangles[i].y ].y,
						Vertices[Triangles[i].y ].z);

			glVertex3f(	Vertices[Triangles[i].z ].x,
						Vertices[Triangles[i].z ].y,
						Vertices[Triangles[i].z ].z);
		glEnd();
	}
	


 
    SwapBuffers(m_hDC);							// Double Buffering

	return TRUE;	
}

void CGlView::rotateSpace( int x, int y, int z, int flag )// Functions for Rotating
{
	spaceCoor[ xCor ] = x;
	spaceCoor[ yCor ] = y;
	spaceCoor[ zCor ] = z;

	spaceFlag = flag;
}

void CGlView::loadTriangleData(vector<CVector3> triangles, vector<CVector3> vertices, vector<CVector4> quads)
{
	Triangles = triangles;
	Vertices = vertices;
	Quads = quads;
}