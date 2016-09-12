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
#include "scene3DNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	SCENE 3D NODE
*-----------------------------------------------------------------------------*/
class PolygonMeshNode : public Scene3DNode
{
public:
	//CONSTRUCTORS
				PolygonMeshNode();
	virtual		~PolygonMeshNode() {}

private:
	//...
};