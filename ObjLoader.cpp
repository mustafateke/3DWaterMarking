// ObjLoader.cpp: implementation of the ObjLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "dlgogl.h"
#include "ObjLoader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ObjLoader::ObjLoader()
{
	NumberOfVertices = 3;
}

ObjLoader::~ObjLoader()
{

}

bool ObjLoader::loadModel(char *strFileName)
{
	// Make sure we have a valid model and file name
	if(!strFileName) return false;

	// Here we open the desired file for read only and return the file pointer
	m_FilePointer = fopen(strFileName, "r");

	// Check to make sure we have a valid file pointer
	if(!m_FilePointer) {
		// Create an error message for the attempted file
		sprintf(strMessage, "Unable to find or open the file: %s", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		return false;
	}

	ReadObjFile();
	fclose(m_FilePointer);

	if (NumberOfVertices == 4) {
		objProperties.Format("File Name: %s\nVertices: %d\nFaces: %d",strFileName,vertices.size(),quads.size());
	}
	else 
		objProperties.Format("File Name: %s\nVertices: %d\nFaces: %d",strFileName,vertices.size(),triangles.size());
	return true;
}

void ObjLoader::ReadObjFile()
{
	CVector3 vNewVertex		= {0,0,0};
	vertices.push_back(vNewVertex);// Durumu kurtarmak için yaptým
	while(!feof(m_FilePointer))
	{
		// Get the beginning character of the current line in the .obj file
		ch = fgetc(m_FilePointer);

		switch(ch)
		{
		case 'v':						// Check if we just read in a 'v' (Could be a vertice/normal/textureCoord)

			// Decipher this line to see if it's a vertex ("v"), normal ("vn"), or UV coordinate ("vt")
			ReadVertexInfo();
			break;

		case 'f':						// Check if we just read in a face header ('f')
			
			ReadFaceInfo();
			break;

		case '\n':
			break;

		default:

			// If we get here then we don't care about the line being read, so read past it.
			fgets(strLine, 100, m_FilePointer);
			break;
		}
	}
}

void ObjLoader::ReadVertexInfo()
{
	CVector3 vNewVertex		= {0};
	// Read the next character in the file to see if it's a vertice/normal/UVCoord
	ch = fgetc(m_FilePointer);

	if(ch == ' ')				// If we get a space it must have been a vertex ("v")
	{
		// Here we read in a vertice.  The format is "v x y z"
		fscanf(m_FilePointer, "%f %f %f", &vNewVertex.x, &vNewVertex.y, &vNewVertex.z);

		// Read the rest of the line so the file pointer returns to the next line.
		fgets(strLine, 100, m_FilePointer);

		// Add a new vertice to our list
		vertices.push_back(vNewVertex);
	}

	else if( ch == 'n')
	{
		// Normals Defined:
		NumberOfVertices = 4;
	}
	else						// Otherwise it's probably a normal so we don't care ("vn")
	{
		
		fgets(strLine, 100, m_FilePointer);
	}
	int deubg_point = 0;
}

void ObjLoader::ReadFaceInfo()
{
	CVector3 newFace;//			= {0};
	char strLine[255]	= {0};



		// Here we read in just the object's vertex indices.
		// Here is the format: "f vertexIndex1 vertexIndex2 vertexIndex3"
	if(NumberOfVertices == 3){
		fscanf(m_FilePointer, "%f %f %f",&newFace.x,
										 &newFace.y,
										 &newFace.z);
		triangles.push_back(newFace);
	}
	else{
		CVector4 new4Face = {0,0,0,0};
		CVector4 new4Text;
		fscanf(m_FilePointer, "%f//%f %f//%f %f//%f %f//%f",	&new4Face.x,&new4Text.x,
																&new4Face.y,&new4Text.y,
																&new4Face.z,&new4Text.z,
																&new4Face.w,&new4Text.w);
		quads.push_back(new4Face);
	}
	// Read the rest of the line so the file pointer returns to the next line.
	fgets(strLine, 100, m_FilePointer);
				
	// Add the new face to our face list
	
	//	pObject->numOfFaces   = m_pFaces.size();
	int debug_point = 0;

}

void ObjLoader::ReadFaceInfo4()
{

}