#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		PolygonMeshNode class holds information about mesh data structure 
*		(vertices, edges, triangles, faces, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "surfaceNode.hpp"
#include "toltecPolygonMeshLibrary/math.hpp"
#include "toltecPolygonMeshLibrary/mesh.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SCENE 3D NODE
*-----------------------------------------------------------------------------*/
class PolygonMeshNode : public SurfaceNode
{
public:
	//CONSTRUCTORS
				PolygonMeshNode();
	virtual		~PolygonMeshNode() {}

	//STATIC
	bool		createMesh(
		std::vector<tpm::Point3D>&	point3DList, 
		std::vector<unsigned int>&	vertexSequence,
		std::vector<unsigned int>&	polygonOffsets);

private:
	tpm::Mesh		m_mesh;
};