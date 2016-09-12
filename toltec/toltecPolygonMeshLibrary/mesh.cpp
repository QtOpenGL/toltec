#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		10 IX 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "mesh.hpp"

#include <algorithm>
#include <cstdlib>
#include <iterator>

/*-----------------------------------------------------------------------------
*	NAMESPACE: TPM
*-----------------------------------------------------------------------------*/
namespace tpm
{
	/*-----------------------------------------------------------------------------
	*	DESTRUCTOR
	*-----------------------------------------------------------------------------*/
	Mesh::~Mesh()
	{
		//CLEAN-UP
		for (Vertex* p_vertex : m_vertexList)
			delete p_vertex;

		for (FaceVertex* p_faceVertex : m_faceVertexList)
			delete p_faceVertex;

		for (Face* p_face : m_faceList)
			delete p_face;
	}

	/*-----------------------------------------------------------------------------
	*	ADD VERTEX
	*	(Point3D&)
	*-----------------------------------------------------------------------------*/
	Vertex* Mesh::addVertex(Point3D& point3D)
	{
		Vertex* p_vertex = new Vertex{ point3D };
		m_vertexList.push_back(p_vertex);

		return p_vertex;
	}

	/*-----------------------------------------------------------------------------
	*	ADD VERTEX
	*	(float, float, float)
	*-----------------------------------------------------------------------------*/
	Vertex* Mesh::addVertex(float x, float y, float z)
	{
		Point3D point3D{ x, y, z };
		Vertex* p_vertex = new Vertex{ point3D };
		m_vertexList.push_back(p_vertex);

		return p_vertex;
	}

	/*-----------------------------------------------------------------------------
	*	ADD FACE
	*-----------------------------------------------------------------------------*/
	Face* Mesh::addFace(std::vector<Vertex*>& vertexList)
	{
		//ADD FACE
		Face* p_face = new Face{};
		m_faceList.push_back(p_face);

		std::size_t faceVertexIndex = m_faceList.size() - 1;

		//ADD FACE VERTICES
		for (Vertex* p_vertex : vertexList)
		{
			//CREATE FACE VERTEX
			FaceVertex* p_faceVertex = new FaceVertex{};
			m_faceVertexList.push_back(p_faceVertex);

			//FIND VERTEX
			std::vector<Vertex*>::iterator vertexIter = std::find(m_vertexList.begin(), 
				m_vertexList.end(), p_vertex);

			//GET VERTEX INDEX
			std::size_t vertexIndex;

			//vertex does't exist
			if (vertexIter == m_vertexList.end())
			{
				//create a copy of a passed vertex (without passing face vertex id list)
				Vertex* p_newVertex = new Vertex{ p_vertex->position };
				m_vertexList.push_back(p_newVertex);

				//fetch index
				vertexIndex = m_vertexList.size() - 1;

				//add face vertex index to vertex
				p_newVertex->faceVertexIDList.push_back(faceVertexIndex);
			}
			//vertex already exists
			else
			{
				//fetch index
				vertexIndex = std::distance(m_vertexList.begin(), vertexIter);

				//add face vertex index to vertex
				p_vertex->faceVertexIDList.push_back(faceVertexIndex);
			}

			//APPLY VERTEX INDEX
			p_faceVertex->vertexID = std::uint32_t(vertexIndex);
		}

		return p_face;
	}
} //NAMESPACE: TPM