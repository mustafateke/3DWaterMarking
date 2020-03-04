// TSPS.h: interface for the TSPS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TSPS_H__AA031EF1_F79A_467B_B037_37889A92F5BD__INCLUDED_)
#define AFX_TSPS_H__AA031EF1_F79A_467B_B037_37889A92F5BD__INCLUDED_
#include <TIME.H>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
using namespace std;
//
class TSPS  
{
public:
	void writeModel(vector<CVector3> TVec, vector<CVector3> PVec);
	void addNoise(int noiseLevel);
	int payLoadSize;
	int outsides;
	int errCounter;// Error Counter
	int quantizeTop(int index);
	void initTSPS();
	void getData();
	void HideData(int index);
	void topProjection(int index);
	void createDataKey();
	int tempArray[100];
	int tempArrayPath[100];
	void reorderTriangle(CVector2 vectorEdge,int iTriangleIndex);
	void setPath();
	CVector3 tempVector;
	int startTriangleIndex;
	vector<int> eraseKey;// Erase Key, holds Changes;
	vector<int> dataKey;// path of the triangles
	vector<int> passKey; // passed triangles
	vector<BOOL> outsideKey; //if top points's projection is outside of the base.
	vector<float> areas;// Holds Area information of the triangles
	vector<float> heights; // Heights of The triangles
	vector<CVector3> pOfC; //Projection of Top(C) on |AB|
	vector<CVector3> pOfCRecover;
	vector<float> lambdas;
	vector<float> lambdasY;
	vector<float> lambdasRecover;
	vector<CVector3> centers;	// centers of the triangles
	vector<int> key;// Key Data To bo Watermarked
	vector<int> recoverKey; // recovered data after watermark process.
	vector<int> modifiedTops; // Tops of the modified triangles
	vector<CVector3> Triangles;
	vector<CVector4> Quads;
	vector<CVector3> Vertices;
	void setGeometry(vector<CVector3> Triangles, vector<CVector3> Vertices, vector<CVector4> quads,int Faces);
	float getHeight(int index);
	float getArea(int index);
	float getLength(CVector3 pointA,CVector3 pointB);
	int getSmallestTraingle();
	int NumberOfFaces;
	TSPS();
	virtual ~TSPS();

};

#endif // !defined(AFX_TSPS_H__AA031EF1_F79A_467B_B037_37889A92F5BD__INCLUDED_)
