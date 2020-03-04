// WireFrame.cpp : implementation file
//

#include "stdafx.h"
#include "DlgOgl.h"
#include "WireFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WireFrame

WireFrame::WireFrame()
{
	Points[0][xCor] =  0;
	Points[0][yCor] =  250;
	Points[0][zCor] =  40;
	
	Points[1][xCor] =  40;
	Points[1][yCor] =  190;
	Points[1][zCor] =  90;
	
	Points[2][xCor] =  0;
	Points[2][yCor] =  130;
	Points[2][zCor] =  120;
	
	Points[3][xCor] =  0;
	Points[3][yCor] =  70;
	Points[3][zCor] =  130;
	
	Points[4][xCor] =  0;
	Points[4][yCor] =  40;
	Points[4][zCor] =  120;
	
	Points[5][xCor] =  0;
	Points[5][yCor] =  -50;
	Points[5][zCor] =  180;
	
	Points[6][xCor] =  0;
	Points[6][yCor] =  -70;
	Points[6][zCor] =  130;
	
	Points[7][xCor] =  0;
	Points[7][yCor] =  -100;
	Points[7][zCor] =  137;
	
	Points[8][xCor] =  0;
	Points[8][yCor] =  -120;
	Points[8][zCor] =  138;
	
	Points[9][xCor] =  0;
	Points[9][yCor] =  -160;
	Points[9][zCor] =  120;
	
	Points[10][xCor] =  0;
	Points[10][yCor] =  -210;
	Points[10][zCor] =  140;
	
	Points[11][xCor] =  50;
	Points[11][yCor] =  245;
	Points[11][zCor] =  10;
	
	Points[12][xCor] =  105;
	Points[12][yCor] =  215;
	Points[12][zCor] =  20;
	
	Points[13][xCor] =  100;
	Points[13][yCor] =  150;
	Points[13][zCor] =  70;
	
	Points[14][xCor] =  146;
	Points[14][yCor] =  130;
	Points[14][zCor] =  20;
	
	Points[15][xCor] =  120;
	Points[15][yCor] =  70;
	Points[15][zCor] =  70;
	
	Points[16][xCor] =  90;
	Points[16][yCor] =  92;
	Points[16][zCor] =  110;
	
	Points[17][xCor] =  30;
	Points[17][yCor] =  70;
	Points[17][zCor] =  120;
	
	Points[18][xCor] =  90;
	Points[18][yCor] =  80;
	Points[18][zCor] =  110;
		
	
	Points[19][xCor] =  70;
	Points[19][yCor] =  60;
	Points[19][zCor] =  100;
	
	Points[20][xCor] =  108;
	Points[20][yCor] =  40;
	Points[20][zCor] =  80;
	
	Points[21][xCor] =  70;
	Points[21][yCor] =  53;
	Points[21][zCor] =  104;
	
	Points[22][xCor] =  70;
	Points[22][yCor] =  34;
	Points[22][zCor] =  103;
	
	Points[23][xCor] = 40;
	Points[23][yCor] =  40;
	Points[23][zCor] =  100;
	
	Points[24][xCor] = 70;
	Points[24][yCor] =  30;
	Points[24][zCor] =  100;
	
	Points[25][xCor] =  30;
	Points[25][yCor] =  -40;
	Points[25][zCor] =  110;
	
	Points[26][xCor] =  50;
	Points[26][yCor] =  -60;
	Points[26][zCor] =  104;
	
	Points[27][xCor] =  120;
	Points[27][yCor] =  -40;
	Points[27][zCor] =  50;
	
	Points[28][xCor] =  150;
	Points[28][yCor] =  -30;
	Points[28][zCor] =  20;
	
	Points[29][xCor] =  140;
	Points[29][yCor] =  40;
	Points[29][zCor] =  20;
	
	Points[30][xCor] =  110;
	Points[30][yCor] =  -190;
	Points[30][zCor] =  60;
	
	Points[31][xCor] =  70;
	Points[31][yCor] =  -110;
	Points[31][zCor] =  80;
	
	Points[32][xCor] =  40;
	Points[32][yCor] =  -180;
	Points[32][zCor] =  100;
	
	Points[33][xCor] =  10;
	Points[33][yCor] =  -90;
	Points[33][zCor] =  136;
	
	Points[34][xCor] =  -40;   ///rýght half face
	Points[34][yCor] =  190;
	Points[34][zCor] =  90;
	
	Points[35][xCor] =  0;
	Points[35][yCor] =  130;
	Points[35][zCor] =  120;
	
	Points[36][xCor] =  0;
	Points[36][yCor] =  70;
	Points[36][zCor] =  130;
	
	Points[37][xCor] =  0;
	Points[37][yCor] =  40;
	Points[37][zCor] =  120;
	
	Points[38][xCor] =  0;
	Points[38][yCor] =  -50;
	Points[38][zCor] =  180;
	
	Points[39][xCor] =  0 ;
	Points[39][yCor] = -70;
	Points[39][zCor] =  130;
	
	Points[40][xCor] =  0;						//this vertex is the upper most part of the lower lip 
	Points[40][yCor] =  -100;
	Points[40][zCor] =  137;
	
	Points[41][xCor] =  0;
	Points[41][yCor] =  -120;
	Points[41][zCor] =  138;
	
	Points[42][xCor] =  0;
	Points[42][yCor] =  -160;
	Points[42][zCor] =  120;
	
	Points[43][xCor] =  0;
	Points[43][yCor] =  -210;
	Points[43][zCor] =  140;
	
	Points[44][xCor] =  -50;
	Points[44][yCor] =  245;
	Points[44][zCor] =  10;

	Points[45][xCor] =  -105;
	Points[45][yCor] =  215;
	Points[45][zCor] =  20;
	
	Points[46][xCor] =  -100;
	Points[46][yCor] =  150;
	Points[46][zCor] =  70;
	
	Points[47][xCor] =  -146;
	Points[47][yCor] =  130;
	Points[47][zCor] =  20;
	
	Points[48][xCor] =  -120;
	Points[48][yCor] =  70;
	Points[48][zCor] =  70;
	
	Points[49][xCor] =  -90;
	Points[49][yCor] =  92;
	Points[49][zCor] =  110;
	
	Points[50][xCor] =  -30;
	Points[50][yCor] =  70;
	Points[50][zCor] =  120;
	
	Points[51][xCor] =  -90;
	Points[51][yCor] =  80;
	Points[51][zCor] =  110;
	
	Points[52][xCor] =  -70;
	Points[52][yCor] =  60;
	Points[52][zCor] =  100;
	
	Points[53][xCor] =  -108;
	Points[53][yCor] =  40;
	Points[53][zCor] =  80;
	
	Points[54][xCor] =  -70;
	Points[54][yCor] =  53;
	Points[54][zCor] =  104;
	
	Points[55][xCor] =  -70;
	Points[55][yCor] =  34;
	Points[55][zCor] =  103;
	
	Points[56][xCor] =  -40;
	Points[56][yCor] =  40;
	Points[56][zCor] =  100;
	
	Points[57][xCor] =  -70;
	Points[57][yCor] =  30;
	Points[57][zCor] =  100;
	
	Points[58][xCor] =  -30;
	Points[58][yCor] =  -40;
	Points[58][zCor] =  110;
	
	Points[59][xCor] =  -50;
	Points[59][yCor] =  -60;
	Points[59][zCor] =  104;
	
	Points[60][xCor] =  -120;
	Points[60][yCor] =  -40;
	Points[60][zCor] =  50;
	
	Points[61][xCor] =  -150;
	Points[61][yCor] =  -30;
	Points[61][zCor] =  20;


	Points[62][xCor] =  -140;
	Points[62][yCor] =  40;
	Points[62][zCor] =  20;

	Points[63][xCor] =  -110;
	Points[63][yCor] =  -190;
	Points[63][zCor] =  60;
	
	Points[64][xCor] =  -70;
	Points[64][yCor] =  -110;
	Points[64][zCor] =  80;
	
	Points[65][xCor] =  -40;
	Points[65][yCor] =  -180;
	Points[65][zCor] =  100;
	
	Points[66][xCor] =  -10;
	Points[66][yCor] =  -90;
	Points[66][zCor] =  136;
		
	Points[67][xCor] =  0;
	Points[67][yCor] =  0;
	Points[67][zCor] =  181;


	TRIANGLES[0][0]=12;
	TRIANGLES[0][1]=13;
	TRIANGLES[0][2]=14;

	TRIANGLES[1][0]=12;
	TRIANGLES[1][1]=13;
	TRIANGLES[1][2]=1;


	TRIANGLES[2][0]=1;
	TRIANGLES[2][1]=11;
	TRIANGLES[2][2]=12;

	TRIANGLES[3][0]=0;
	TRIANGLES[3][1]=1;
	TRIANGLES[3][2]=11;

	TRIANGLES[4][0]=1;
	TRIANGLES[4][1]=0;
	TRIANGLES[4][2]=34;

	TRIANGLES[5][0]=0;
	TRIANGLES[5][1]=34;
	TRIANGLES[5][2]=44;

	TRIANGLES[6][0]=34;
	TRIANGLES[6][1]=44;
	TRIANGLES[6][2]=45;

	TRIANGLES[7][0]=34;
	TRIANGLES[7][1]=45;
	TRIANGLES[7][2]=46;

	TRIANGLES[8][0]=45;
	TRIANGLES[8][1]=46;
	TRIANGLES[8][2]=47;

	TRIANGLES[9][0]=14;
	TRIANGLES[9][1]=15;
	TRIANGLES[9][2]=29;

	TRIANGLES[10][0]=13;
	TRIANGLES[10][1]=14;
	TRIANGLES[10][2]=15;

	TRIANGLES[11][0]=13;
	TRIANGLES[11][1]=15;
	TRIANGLES[11][2]=16;

	TRIANGLES[12][0]=13;
	TRIANGLES[12][1]=16;
	TRIANGLES[12][2]=2;

	TRIANGLES[13][0]=13;
	TRIANGLES[13][1]=1;
	TRIANGLES[13][2]=2;

	TRIANGLES[14][0]=1;
	TRIANGLES[14][1]=2;
	TRIANGLES[14][2]=34;

	TRIANGLES[15][0]=2;
	TRIANGLES[15][1]=34;
	TRIANGLES[15][2]=46;

	TRIANGLES[16][0]=2;
	TRIANGLES[16][1]=46;
	TRIANGLES[16][2]=49;

	TRIANGLES[17][0]=46;
	TRIANGLES[17][1]=48;
	TRIANGLES[17][2]=49;

	TRIANGLES[18][0]=46;
	TRIANGLES[18][1]=47;
	TRIANGLES[18][2]=48;

	TRIANGLES[19][0]=47;
	TRIANGLES[19][1]=48;
	TRIANGLES[19][2]=62;

	TRIANGLES[20][0]=15;
	TRIANGLES[20][1]=20;
	TRIANGLES[20][2]=29;

	TRIANGLES[21][0]=15;
	TRIANGLES[21][1]=20;
	TRIANGLES[21][2]=19;

	TRIANGLES[22][0]=15;
	TRIANGLES[22][1]=18;
	TRIANGLES[22][2]=19;

	TRIANGLES[23][0]=15;
	TRIANGLES[23][1]=16;
	TRIANGLES[23][2]=18;

	TRIANGLES[24][0]=16;
	TRIANGLES[24][1]=17;
	TRIANGLES[24][2]=18;

	TRIANGLES[25][0]=2;
	TRIANGLES[25][1]=16;
	TRIANGLES[25][2]=17;

	TRIANGLES[26][0]=2;
	TRIANGLES[26][1]=3;
	TRIANGLES[26][2]=17;

	TRIANGLES[27][0]=2;
	TRIANGLES[27][1]=3;
	TRIANGLES[27][2]=50;

	TRIANGLES[28][0]=2;
	TRIANGLES[28][1]=50;
	TRIANGLES[28][2]=49;

	TRIANGLES[29][0]=50;
	TRIANGLES[29][1]=49;
	TRIANGLES[29][2]=51;

	TRIANGLES[30][0]=51;
	TRIANGLES[30][1]=49;
	TRIANGLES[30][2]=48;

	TRIANGLES[31][0]=51;
	TRIANGLES[31][1]=52;
	TRIANGLES[31][2]=48;

	TRIANGLES[32][0]=52;
	TRIANGLES[32][1]=48;
	TRIANGLES[32][2]=53;

	TRIANGLES[33][0]=48;
	TRIANGLES[33][1]=53;
	TRIANGLES[33][2]=62;

	TRIANGLES[34][0]=19;
	TRIANGLES[34][1]=20;
	TRIANGLES[34][2]=21;

	TRIANGLES[35][0]=20;
	TRIANGLES[35][1]=24;
	TRIANGLES[35][2]=22;

	TRIANGLES[36][0]=20;
	TRIANGLES[36][1]=21;
	TRIANGLES[36][2]=22;

	TRIANGLES[37][0]=21;
	TRIANGLES[37][1]=22;
	TRIANGLES[37][2]=23;

	TRIANGLES[38][0]=22;
	TRIANGLES[38][1]=23;
	TRIANGLES[38][2]=24;

	TRIANGLES[39][0]=19;
	TRIANGLES[39][1]=21;
	TRIANGLES[39][2]=23;

	TRIANGLES[40][0]=19;
	TRIANGLES[40][1]=17;
	TRIANGLES[40][2]=23;

	TRIANGLES[41][0]=17;
	TRIANGLES[41][1]=4;
	TRIANGLES[41][2]=23;

	TRIANGLES[42][0]=3;
	TRIANGLES[42][1]=4;
	TRIANGLES[42][2]=17;

	TRIANGLES[43][0]=3;
	TRIANGLES[43][1]=4;
	TRIANGLES[43][2]=50;

	TRIANGLES[44][0]=4;
	TRIANGLES[44][1]=50;
	TRIANGLES[44][2]=56;

	TRIANGLES[45][0]=50;
	TRIANGLES[45][1]=56;
	TRIANGLES[45][2]=52;

	TRIANGLES[46][0]=52;
	TRIANGLES[46][1]=54;
	TRIANGLES[46][2]=56;

	TRIANGLES[47][0]=56;
	TRIANGLES[47][1]=55;
	TRIANGLES[47][2]=57;

	TRIANGLES[48][0]=54;
	TRIANGLES[48][1]=55;
	TRIANGLES[48][2]=56;

	TRIANGLES[49][0]=53;
	TRIANGLES[49][1]=54;
	TRIANGLES[49][2]=55;

	TRIANGLES[50][0]=52;
	TRIANGLES[50][1]=53;
	TRIANGLES[50][2]=54;

	TRIANGLES[51][0]=53;
	TRIANGLES[51][1]=55;
	TRIANGLES[51][2]=57;

	TRIANGLES[52][0]=17;
	TRIANGLES[52][1]=18;
	TRIANGLES[52][2]=19;

	TRIANGLES[53][0]=50;
	TRIANGLES[53][1]=52;
	TRIANGLES[53][2]=51;

	TRIANGLES[54][0]=27;
	TRIANGLES[54][1]=28;
	TRIANGLES[54][2]=29;

	TRIANGLES[55][0]=27;
	TRIANGLES[55][1]=29;
	TRIANGLES[55][2]=20;

	TRIANGLES[56][0]=20;
	TRIANGLES[56][1]=27;
	TRIANGLES[56][2]=26;

	TRIANGLES[57][0]=20;
	TRIANGLES[57][1]=26;
	TRIANGLES[57][2]=24;

	TRIANGLES[58][0]=24;
	TRIANGLES[58][1]=25;
	TRIANGLES[58][2]=26;

	TRIANGLES[59][0]=23;
	TRIANGLES[59][1]=24;
	TRIANGLES[59][2]=25;

	TRIANGLES[60][0]=23;
	TRIANGLES[60][1]=4;
	TRIANGLES[60][2]=25;

	TRIANGLES[61][0]=4;
	TRIANGLES[61][1]=5;
	TRIANGLES[61][2]=25;

	TRIANGLES[62][0]=4;
	TRIANGLES[62][1]=5;
	TRIANGLES[62][2]=58;

	TRIANGLES[63][0]=4;
	TRIANGLES[63][1]=56;
	TRIANGLES[63][2]=58;

	TRIANGLES[64][0]=57;
	TRIANGLES[64][1]=58;
	TRIANGLES[64][2]=56;

	TRIANGLES[65][0]=57;
	TRIANGLES[65][1]=58;
	TRIANGLES[65][2]=59;

	TRIANGLES[66][0]=57;
	TRIANGLES[66][1]=53;
	TRIANGLES[66][2]=59;

	TRIANGLES[67][0]=53;
	TRIANGLES[67][1]=59;
	TRIANGLES[67][2]=60;

	TRIANGLES[68][0]=53;
	TRIANGLES[68][1]=60;
	TRIANGLES[68][2]=62;

	TRIANGLES[69][0]=60;
	TRIANGLES[69][1]=61;
	TRIANGLES[69][2]=62;

	TRIANGLES[70][0]=5;
	TRIANGLES[70][1]=25;
	TRIANGLES[70][2]=26;

	TRIANGLES[71][0]=5;
	TRIANGLES[71][1]=58;
	TRIANGLES[71][2]=59;

	TRIANGLES[72][0]=5;
	TRIANGLES[72][1]=6;
	TRIANGLES[72][2]=26;

	TRIANGLES[73][0]=5;
	TRIANGLES[73][1]=6;
	TRIANGLES[73][2]=59;

	TRIANGLES[74][0]=27;
	TRIANGLES[74][1]=28;
	TRIANGLES[74][2]=30;

	TRIANGLES[75][0]=27;
	TRIANGLES[75][1]=30;
	TRIANGLES[75][2]=31;

	TRIANGLES[76][0]=26;
	TRIANGLES[76][1]=27;
	TRIANGLES[76][2]=31;

	TRIANGLES[77][0]=26;
	TRIANGLES[77][1]=31;
	TRIANGLES[77][2]=33;

	TRIANGLES[78][0]=26;
	TRIANGLES[78][1]=33;
	TRIANGLES[78][2]=6;

	TRIANGLES[79][0]=33;
	TRIANGLES[79][1]=6;
	TRIANGLES[79][2]=7;

	TRIANGLES[80][0]=6;
	TRIANGLES[80][1]=7;
	TRIANGLES[80][2]=66;

	TRIANGLES[81][0]=6;
	TRIANGLES[81][1]=66;
	TRIANGLES[81][2]=59;

	TRIANGLES[82][0]=59;
	TRIANGLES[82][1]=64;
	TRIANGLES[82][2]=66;

	TRIANGLES[83][0]=59;
	TRIANGLES[83][1]=60;
	TRIANGLES[83][2]=64;

	TRIANGLES[84][0]=60;
	TRIANGLES[84][1]=63;
	TRIANGLES[84][2]=64;

	TRIANGLES[85][0]=60;
	TRIANGLES[85][1]=61;
	TRIANGLES[85][2]=63;

	TRIANGLES[86][0]=7;
	TRIANGLES[86][1]=31;
	TRIANGLES[86][2]=33;

	TRIANGLES[87][0]=7;
	TRIANGLES[87][1]=8;
	TRIANGLES[87][2]=31;

	TRIANGLES[88][0]=7;
	TRIANGLES[88][1]=66;
	TRIANGLES[88][2]=64;

	TRIANGLES[89][0]=7;
	TRIANGLES[89][1]=8;
	TRIANGLES[89][2]=64;

	TRIANGLES[90][0]=30;
	TRIANGLES[90][1]=31;
	TRIANGLES[90][2]=32;

	TRIANGLES[91][0]=31;
	TRIANGLES[91][1]=32;
	TRIANGLES[91][2]=9;

	TRIANGLES[92][0]=8;
	TRIANGLES[92][1]=9;
	TRIANGLES[92][2]=31;

	TRIANGLES[93][0]=8;
	TRIANGLES[93][1]=9;
	TRIANGLES[93][2]=64;

	TRIANGLES[94][0]=9;
	TRIANGLES[94][1]=64;
	TRIANGLES[94][2]=65;

	TRIANGLES[95][0]=63;
	TRIANGLES[95][1]=64;
	TRIANGLES[95][2]=65;

	TRIANGLES[96][0]=10;
	TRIANGLES[96][1]=30;
	TRIANGLES[96][2]=32;

	TRIANGLES[97][0]=9;
	TRIANGLES[97][1]=10;
	TRIANGLES[97][2]=32;

	TRIANGLES[98][0]=9;
	TRIANGLES[98][1]=10;
	TRIANGLES[98][2]=65;

	TRIANGLES[99][0]=10;
	TRIANGLES[99][1]=63;
	TRIANGLES[99][2]=65;




	refPoints[ 0 ] =  10;						// Bottom

	refPoints[ 1 ] =   0;						// Top 

	refPoints[ 2 ] =  61;						// Left

	refPoints[ 3 ] =  28;						// Right 

	refPoints[ 4 ] =  64;						// Mouth Left

	refPoints[ 5 ] =  31;						// Mouth Right

	refPoints[ 6 ] =  55;						// Left Eye

	refPoints[ 7 ] =  22;						// Right Eye

	refPoints[ 8 ] =   6;						// Nose

	refPoints[ 9 ] =  67;						// Center


	for(int i=0; i<10; i++){					// Initialize Pixel Values to Zero
		refPixel[ i ].x = 0.0;
		refPixel[ i ].y = 0.0;
	}

	for(int i = 0; i<10 ;i++)						// Set Flags to Zero
		refFlag[i] = 0;



	Cevre [ 0 ] = 0;							// Points that are at the 
	Cevre [ 1 ] = 11;							// Circumference
	Cevre [ 2 ] = 12;
	Cevre [ 3 ] = 14;
	Cevre [ 4 ] = 29;
	Cevre [ 5 ] = 28;
	Cevre [ 6 ] = 30;
	Cevre [ 7 ] = 10;
	Cevre [ 8 ] = 63;
	Cevre [ 9 ] = 61;
	Cevre [ 10 ] = 62;
	Cevre [ 11 ] = 47;
	Cevre [ 12 ] = 45;
	Cevre [ 13 ] = 44;
	Cevre [ 14 ] = 0;

}

WireFrame::~WireFrame()
{
}


BEGIN_MESSAGE_MAP(WireFrame, CWnd)
	//{{AFX_MSG_MAP(WireFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// WireFrame message handlers
