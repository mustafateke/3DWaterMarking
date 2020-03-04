// TSPS.cpp: implementation of the TSPS class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "dlgogl.h"
#include "math.h"
#include "TSPS.h"

#include <stdio.h>

#include <stdlib.h>
#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TSPS::TSPS()
{

}

TSPS::~TSPS()
{

}

int TSPS::getSmallestTraingle()
{
	/*
	 *	Aim of this function is to determine the start triangle
	 *	It finds the smallest  triangle.
	 */
	float tempA = 100000;
	float AREA;

	for(int i = 0; i < Triangles.size(); i++){

		AREA = getArea(i);

		if (AREA < tempA){
			tempA = fabs(AREA);
			startTriangleIndex = i;			
		}
	}
	
	return startTriangleIndex;
}

float TSPS::getLength(CVector3 pointA, CVector3 pointB)
{	
/*
 *	Gets the lenght between two points
 */
	int a,b,c;
	a = abs(pointA.x - pointB.x);
	b = abs(pointA.y - pointB.y);
	c = abs(pointA.z - pointB.z);

	return sqrt(double(a*a + b*b + c*c));
}

float TSPS::getArea(int index)
{
/*
 *	Gets Area of a Triangle
 *	Simply function return area of the trinagle referenced by index.
 *	Area found here by analytically.
 */
	float a = 0,b = 0,c = 0,cevre = 0;
	
	a = getLength(	Vertices[ Triangles[index].x ],
					Vertices[ Triangles[index].y ]	);

	b = getLength(	Vertices[ Triangles[index].x ],
					Vertices[ Triangles[index].z ]	);

	c = getLength(	Vertices[ Triangles[index].y ],
					Vertices[ Triangles[index].z ]	);

	cevre = (a + b + c)/2.0;
	float area = sqrt(abs(cevre*(cevre - a)*(cevre - b)*(cevre - c)));	
	return area;
}

float TSPS::getHeight(int index)
// get height of the current triangle
{
	float tempArea = 0,height;
	float a = 0;

	a = getLength(	Vertices[ Triangles[dataKey[index]].x ],
					Vertices[ Triangles[dataKey[index]].y ]	);
	tempArea = areas[index];
	height = 2*tempArea/a;

	return height;
}

void TSPS::setGeometry(vector<CVector3> triangles, vector<CVector3> vertices, vector<CVector4> quads,int Faces)
// Set Triangles and Vertices information from Obj_Loader
{
	Triangles = triangles;
	Vertices = vertices;
	Quads = quads;
	NumberOfFaces = Faces;
}

void TSPS::setPath()
// Simply Set the Path the triangles will pass
// Triangle Vertices are ordered no Quantization
// Path Lenght is about 100 triangles including outside top projections.
// Path setting is done according to pass dataKey
{
	int Flag = 0;
	float a = 0,b = 0,c = 0;
	CVector2 tempVector2D;

	passKey.push_back(startTriangleIndex);
	dataKey.push_back(startTriangleIndex);

	a = getLength(	Vertices[ Triangles[ startTriangleIndex ].x ],
					Vertices[ Triangles[ startTriangleIndex ].y ]	);

	b = getLength(	Vertices[ Triangles[ startTriangleIndex ].x ],
					Vertices[ Triangles[ startTriangleIndex ].z ]	);

	c = getLength(	Vertices[ Triangles[ startTriangleIndex ].y ],
					Vertices[ Triangles[ startTriangleIndex ].z ]	);

	if(a>=b && a>=c)
	{
		tempVector.x = Triangles[ startTriangleIndex ].x;
		tempVector.y = Triangles[ startTriangleIndex ].y;
		tempVector.z = Triangles[ startTriangleIndex ].z;
	}

	else if(b>=a && b>=c)
	{
		tempVector.x = Triangles[ startTriangleIndex ].z;
		tempVector.y = Triangles[ startTriangleIndex ].x;
		tempVector.z = Triangles[ startTriangleIndex ].y;
	}

	else if (c>=a && c>=b) 
	{
		tempVector.x = Triangles[ startTriangleIndex ].y;
		tempVector.y = Triangles[ startTriangleIndex ].z;
		tempVector.z = Triangles[ startTriangleIndex ].x;		
	}

	Triangles[ startTriangleIndex ].x = tempVector.x;
	Triangles[ startTriangleIndex ].y = tempVector.y;
	Triangles[ startTriangleIndex ].z = tempVector.z;

	int data_count = 0;
	int path_count = 0;
	for(int i = 0; i < key.size(); i++)
	{
		int tempPassKey = passKey[i];
		int keyLenght = passKey.size();

		int tempKey = key[i];
		if (tempKey) 
		{
			tempVector2D.x = tempVector.z;
			tempVector2D.y = tempVector.y;
		}
		else
		{
			tempVector2D.x = tempVector.x;
			tempVector2D.y = tempVector.z;
		}

		for(int j = 0; j <Triangles.size() ; j++)
		{
			if (data_count >= dataKey.size()) {
				break;
			}
			
			if ((	(	tempVector2D.x == Triangles[j].x	)||
					(	tempVector2D.x == Triangles[j].y	)||
					(	tempVector2D.x == Triangles[j].z	)
				)&&
				(	(	tempVector2D.y == Triangles[j].x	)||
					(	tempVector2D.y == Triangles[j].y	)||
					(	tempVector2D.y == Triangles[j].z	)
				)&& j != dataKey[data_count]
				) 
			{

				// Check if I had passed before.
				for(int k = 0; k < passKey.size(); k++){
					if ( j == passKey[k] ) {
						Flag = 1;
					} 
				}

					passKey.push_back(j);
					//tempArrayPath[path_count] = passKey[path_count];
					path_count++;									
					
				if(!Flag){

					tempVector.x = Triangles[j].x;
					tempVector.y = Triangles[j].y;
					tempVector.z = Triangles[j].z;
				
					reorderTriangle(tempVector2D,j);

					dataKey.push_back(j);
					keyLenght = dataKey.size();
					tempArray[data_count] = dataKey[data_count];	
					data_count++;
					
					tempVector.x = Triangles[j].x;
					tempVector.y = Triangles[j].y;
					tempVector.z = Triangles[j].z;
					
					break;
				}
				else if(Flag == 1)
				{
					Flag = 0;
				}

			}
		}

	}

}

void TSPS::reorderTriangle(CVector2 vectorEdge,int iTriangleIndex)
{
/*
 *	The aim of this function is arrange vertices order given 
 *	in .obj file so that it will be easy to use them.
 *	Entering a triangle if its vertice order is not ordered
 *	this function orders vertices such as the edge that you enter
 *	becomes x and y and the other is z
 */
	CVector3 temp;
	if (vectorEdge.x == Triangles[iTriangleIndex].x) {
		if(vectorEdge.y == Triangles[iTriangleIndex].y)
		{
			temp.y = Triangles[iTriangleIndex].y;
			temp.z = Triangles[iTriangleIndex].z;
		}
		else if (vectorEdge.y == Triangles[iTriangleIndex].z)
			
		{
			temp.y = Triangles[iTriangleIndex].z;
			temp.z = Triangles[iTriangleIndex].y;
		}

		temp.x = Triangles[iTriangleIndex].x;

	}

	else if (vectorEdge.x == Triangles[iTriangleIndex].y) {
		if(vectorEdge.y == Triangles[iTriangleIndex].x)
		{
			temp.y = Triangles[iTriangleIndex].x;
			temp.z = Triangles[iTriangleIndex].z;
		}
		else if (vectorEdge.y == Triangles[iTriangleIndex].z)
			
		{
			temp.y = Triangles[iTriangleIndex].z;
			temp.z = Triangles[iTriangleIndex].x;
		}

		temp.x = Triangles[iTriangleIndex].y;

	}

	else if(vectorEdge.x == Triangles[iTriangleIndex].z) {
		if(vectorEdge.y == Triangles[iTriangleIndex].x)
		{
			temp.y = Triangles[iTriangleIndex].x;
			temp.z = Triangles[iTriangleIndex].y;
		}
		else if (vectorEdge.y == Triangles[iTriangleIndex].y)
			
		{
			temp.y = Triangles[iTriangleIndex].y;
			temp.z = Triangles[iTriangleIndex].x;
		}

		temp.x = Triangles[iTriangleIndex].z;

	}

	Triangles[iTriangleIndex].x = temp.x;
	Triangles[iTriangleIndex].y = temp.y;
	Triangles[iTriangleIndex].z = temp.z;

}

void TSPS::createDataKey()
// Creates data key for triangles
// Key holds binary data
{
	//int limit = Triangles.size();
	srand((unsigned)time(NULL));//initialize randomly using current time.
	for(int i = 0;i < Triangles.size() ; i++)
	{
		key.push_back(rand()%2);// Add the current value to the key.
		//int temp = key[i];
	}
}

void TSPS::topProjection(int index)
// get the projection of the top point
// on to base |AB| of the triangle referenced by index.
{
	float thetaX,thetaY,a,b,c,_arcsinX,_arcsinY,komsuX,komsuY,oran,tempHeight;
	CVector3 tempVector = {0,0,0};

	a = getLength(	Vertices[ Triangles[ dataKey[index] ].x ],
					Vertices[ Triangles[ dataKey[index] ].y ]	);

	b = getLength(	Vertices[ Triangles[ dataKey[index] ].x ],
					Vertices[ Triangles[ dataKey[index] ].z ]	);

	c = getLength(	Vertices[ Triangles[ dataKey[index] ].y ],
					Vertices[ Triangles[ dataKey[index] ].z ]	);
	
	tempVector = Vertices[ Triangles[ dataKey[index] ].x ];
	tempVector = Vertices[ Triangles[ dataKey[index] ].y ];
	tempVector = Vertices[ Triangles[ dataKey[index] ].z ];

	tempHeight = heights[ index ];	// Get height of the triangle
	int tempArea = getArea(dataKey[index]);	// Get area of the triangle
	// find left and right angles correspondingly.
	_arcsinX = tempHeight/b;
	_arcsinY = tempHeight/c;
	thetaX = fabs(asin(_arcsinX));
	thetaY = fabs(asin(_arcsinY));

	// calculate projections on the base |AB|
	komsuX = heights[ index ]/tan(thetaX);
	komsuY = heights[ index ]/tan(thetaY);
	oran = komsuX/a;
	
	float tempLamdaX = komsuX - a*0.5f;
	float tempLamdaY = komsuY - a*0.5f;

	tempLamdaX = tempLamdaX/a; 
	tempLamdaY = tempLamdaY/a;
	// See lambda values valid only when they are btw -0.5 and 0.5
	lambdas.push_back(tempLamdaX);
	
	// If any projection is outside flag that triangle as "outside" triangle.
	if ((komsuX>a || komsuX<0)||(komsuY>a || komsuY<0)) // Check if the porjection is on the base |AB|
	{
		outsideKey.push_back(1);
	}
	else
	{
		outsideKey.push_back(0);
	}

	//	if (fabsf(tempLamda)<0.1 && fabsf(tempLamda)>.45) {
	//		outsideKey[index] = 1;
	//	}

}

void TSPS::HideData(int index)
{
/*
 *	Hada Hiding Handledin this function, Hide Data
 *	The Trick here is if you first find all height and areas 
 *	in case of quantization i.e movement of top point of a triangle
 *	you'll get wrong results,since you are assuming previous coordinates
 */
	setPath();//Determine the path where the information will be watermarked

	for(int i = 0; i < dataKey.size(); i++){
		areas.push_back(getArea(dataKey[i]));	// Get area of current triangle
		heights.push_back(getHeight(i));		// Get height of the triangle
		topProjection(i);						// Get state of the triangle
		quantizeTop(i);							// If necessary make quantization
	}
	

}

void TSPS::getData()
/*
 *	get quantized information
 */
{
	float thetaX,a,b,c,_arcsin,komsu,oran,tempHeight;
	CVector3 tempVector = {0,0,0};
	for(int i = 0; i < dataKey.size(); i++){

		if (!outsideKey[i]) {

			a = getLength(	Vertices[ Triangles[ dataKey[i] ].x ],
							Vertices[ Triangles[ dataKey[i] ].y ]	);
			
			b = getLength(	Vertices[ Triangles[ dataKey[i] ].x ],
							Vertices[ Triangles[ dataKey[i] ].z ]	);

			c = getLength(	Vertices[ Triangles[ dataKey[i] ].y ],
							Vertices[ Triangles[ dataKey[i] ].z ]	);

			// int temp = dataKey[i]; // get key value
			
			areas[i] = getArea(dataKey[i]);
			int tempArea = getArea(dataKey[i]);
			tempHeight = getHeight(i);

			_arcsin = tempHeight/b;
			thetaX = asin(_arcsin);
			komsu = tempHeight/tan(thetaX);
			oran = komsu/a;

			if (komsu>a || komsu<0) // Check if the projection is still on the base |AB|
			{
				outsideKey[i] = 1;			
			}
			else{
				// No problem before going on.
				/*
				tempVector.x = Vertices[ Triangles[ dataKey[i] ].x ].x + oran*(Vertices[ Triangles[ dataKey[i] ].y ].x - Vertices[ Triangles[ dataKey[i] ].x ].x);
				tempVector.y = Vertices[ Triangles[ dataKey[i] ].x ].y + oran*(Vertices[ Triangles[ dataKey[i] ].y ].y - Vertices[ Triangles[ dataKey[i] ].x ].y);
				tempVector.z = Vertices[ Triangles[ dataKey[i] ].x ].z + oran*(Vertices[ Triangles[ dataKey[i] ].y ].z - Vertices[ Triangles[ dataKey[i] ].x ].z);
				
				tempVector = Vertices[ Triangles[ dataKey[i] ].x ];
				tempVector = Vertices[ Triangles[ dataKey[i] ].y ];
				tempVector = Vertices[ Triangles[ dataKey[i] ].z ];
			
				pOfCRecover.push_back(tempVector);
				*/
				float tempLamda = komsu - a*.5f;
				tempLamda = tempLamda/a; 
				//lambdasRecover.push_back(tempLamda);// recover key saklanan bilgiyi alýr.

				if (tempLamda > 0)
				{
					tempArray[i] = 1;
				}
				else if(tempLamda < 0)
				{
					tempArray[i] = 0;
				}
			}
		}
		else
		{
			tempArray[i] = -1;
		}
		
		
	}
	errCounter = 0;
	for(int i = 0; i < dataKey.size(); i++)
	{
		int keyTemp = key[i];
		int recoverKeyTemp = tempArray[i];
		if (key[i] != tempArray[i]){
			if(!outsideKey[i]) {
			errCounter++;
			}
		}
	}
	outsides = 0;
	for(int i = 0; i< outsideKey.size(); i++)
		if (outsideKey[i]) {
			outsides++;
		}
	payLoadSize = dataKey.size();
}

void TSPS::initTSPS()
// Made some initialization here.
{


}

int TSPS::quantizeTop(int index)
/*
 *	quanztization of top points of the triangles made here.
 *	Quantization done according to the paper 
 */
{
	float oran = 0;
	int Flag = 0;// used for modifiedTops
	int tempKey = key[index];
	tempKey = dataKey[index];

	//Check if the point to be quantized already passed or registered.
	for(int i = 0;i< modifiedTops.size(); i++){ // && !outsideKey(dataKey[index]);
		if (Triangles[ dataKey[index] ].z == modifiedTops[i] ) {
			int x = Triangles[ dataKey[index] ].z;
			int y = modifiedTops[i];
			Flag = 1;
			break;
		}
	}

	//CVector3 tempTri = Triangles[ dataKey[index] ];//not needed for control only
	
	// insert a triangle that is passed into modified tops list so that never use it again.
	modifiedTops.push_back(Triangles[ dataKey[index] ].x);
	modifiedTops.push_back(Triangles[ dataKey[index] ].y);
	modifiedTops.push_back(Triangles[ dataKey[index] ].z);

	if(!outsideKey[index]){		

		if (key[index])
		{
			if (lambdas[index]>0) {
				eraseKey.push_back(0);
			}
			else if(lambdas[index]<0)
			{
				if (!Flag) 
				{					
					eraseKey.push_back(1);

					oran = fabsf(2*lambdas[index]);
					tempVector = Vertices[ Triangles[ dataKey[index] ].z ];

					// quantization made here.
					Vertices[ Triangles[ dataKey[index] ].z ].x += oran*(Vertices[ Triangles[ dataKey[index] ].y ].x - Vertices[ Triangles[ dataKey[index] ].x ].x);;
					Vertices[ Triangles[ dataKey[index] ].z ].y += oran*(Vertices[ Triangles[ dataKey[index] ].y ].y - Vertices[ Triangles[ dataKey[index] ].x ].y);;
					Vertices[ Triangles[ dataKey[index] ].z ].z += oran*(Vertices[ Triangles[ dataKey[index] ].y ].z - Vertices[ Triangles[ dataKey[index] ].x ].z);;
					tempVector = Vertices[ Triangles[ dataKey[index] ].z ];

				}
				else
				{
					outsideKey[index] = 1;
					Flag = 0;
				}
			}
		}
		else if (key[index] == 0) {
			if (lambdas[index]<0) {
				eraseKey.push_back(0);
				// no modification necessary , already in the region
			}
			else if (lambdas[index]>0) 
			{
				if (!Flag) 
				{
					eraseKey.push_back(1);// It is modified now

					oran = fabsf(2*lambdas[index]);
					
					// quantization made here.
					Vertices[ Triangles[ dataKey[index] ].z ].x += -oran*(Vertices[ Triangles[ dataKey[index] ].y ].x - Vertices[ Triangles[ dataKey[index] ].x ].x);
					Vertices[ Triangles[ dataKey[index] ].z ].y += -oran*(Vertices[ Triangles[ dataKey[index] ].y ].y - Vertices[ Triangles[ dataKey[index] ].x ].y);
					Vertices[ Triangles[ dataKey[index] ].z ].z += -oran*(Vertices[ Triangles[ dataKey[index] ].y ].z - Vertices[ Triangles[ dataKey[index] ].x ].z);
				}
				else
				{
					outsideKey[index] = 1;
					Flag = 0;
				}
							
			}
		}
	}
	return 0;
}

void TSPS::addNoise(int noiseLevel)
{
/*
 *	Add Random Noise to each vertex point in the model.
 */
	int sign = 1;
	for(int i = 0; i < Vertices.size(); i++)
	{
		if (rand()%2) {
			sign = 1;// Çiftler artý
		}
		else
		{
			sign = -1;
		}

		Vertices[i].x += sign*(rand()%noiseLevel)*0.5;

		if (rand()%2) {
			sign = 1;// Çiftler artý
		}
		else
		{
			sign = -1;
		}

		Vertices[i].y += sign*(rand()%noiseLevel)*0.5;

		if (rand()%2) {
			sign = 1;// Çiftler artý
		}
		else
		{
			sign = -1;
		}

		Vertices[i].z += sign*(rand()%noiseLevel)*0.5;
	}
}

void TSPS::writeModel(vector<CVector3> TVec, vector<CVector3> PVec)
{
	char* filename = "c:\\temp.obj";

	FILE* fp;
	fp = fopen(filename, "w+t");
	fprintf(fp,"# By Mustafa Teke\n");
	fprintf(fp,"\n### Triangles ###\n");
	for(int i = 0; i < TVec.size(); i++)
	{
		fprintf(fp,"\nf %f %f %f",TVec[i].x + 1 ,TVec[i].y + 1, TVec[i].z + 1);
	}

	fprintf(fp,"\n\n\n### Vertices ###\n");
	
	for(int i = i; i < PVec.size(); i++)
	{
		fprintf(fp,"\nv %f %f %f",PVec[i].x ,PVec[i].y, PVec[i].z);
	}	
	fclose(fp);

}
