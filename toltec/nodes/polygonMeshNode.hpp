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
#include "renderableObjectNode.hpp"

#include "toltecPolygonMeshLibrary/mesh.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATION
*-----------------------------------------------------------------------------*/
class TransformNode;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SCENE 3D NODE
*-----------------------------------------------------------------------------*/
class PolygonMeshNode : public RenderableObjecNode
{
public:
	//CONSTRUCTORS
				PolygonMeshNode();
	virtual		~PolygonMeshNode() {}

	//OTHER
	bool		create(
		std::vector<tpm::Point3D>&	point3DList, 
		std::vector<unsigned int>&	vertexSequence,
		std::vector<unsigned int>&	polygonOffsets,
		TransformNode*				p_parent = nullptr);

private:
	tpm::Mesh	m_mesh;
};