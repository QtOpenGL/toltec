#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		10 IX 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <vector>

#include "math.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TPM
*-----------------------------------------------------------------------------*/
namespace tpm
{
	/*-----------------------------------------------------------------------------
	*	STRUCTS
	*-----------------------------------------------------------------------------*/
	struct Vertex {
		Point3D						position;
		std::vector<std::uint32_t>	faceVertexIDList;
	};

	struct FaceVertex {
		std::uint32_t				vertexID;
		Vector3D					normal;
		Point2D						uv;
	};

	struct Face {
		std::vector<std::uint32_t>	faceVertexIDList;
	};

	/*-----------------------------------------------------------------------------
	*	CLASS DECLARATIONS
	*	MESH
	*-----------------------------------------------------------------------------*/
	class Mesh
	{
	public:
		//CONSTRUCTORS
		virtual		~Mesh();

		//ADD
		Vertex*		addVertex(Point3D& point3D);
		Vertex*		addVertex(float x, float y, float z);
		Face*		addFace(std::vector<Vertex*>& vertexList);

		//OTHER
		void		zeroUVs();
		void		calcNormals();
		void		triangulate();
		void		collectGarbage();

	private:
		std::vector<Vertex*>		m_vertexList;
		std::vector<FaceVertex*>	m_faceVertexList;
		std::vector<Face*>			m_faceList;
	};
} //NAMESPACE: TPM