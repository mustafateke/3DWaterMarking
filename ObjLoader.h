// ObjLoader.h: interface for the ObjLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJLOADER_H__38AB7DA5_2806_4E99_8B76_58E4E65C9886__INCLUDED_)
#define AFX_OBJLOADER_H__38AB7DA5_2806_4E99_8B76_58E4E65C9886__INCLUDED_

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



class ObjLoader  
{
public:
	BOOL loadFlag;
	CString objProperties;
	void ReadFaceInfo();
	void ReadFaceInfo4();
	void ReadVertexInfo();
	void ReadObjFile();
	FILE *m_FilePointer;
	vector<CVector3> vertices;
	vector<CVector3> triangles;
	vector<CVector4> quads;
	char strMessage[255];	
	char strLine[255];
	char ch ;
	bool loadModel(char *strFileName);
	ObjLoader();
	virtual ~ObjLoader();
	int NumberOfVertices;

};

#endif // !defined(AFX_OBJLOADER_H__38AB7DA5_2806_4E99_8B76_58E4E65C9886__INCLUDED_)
