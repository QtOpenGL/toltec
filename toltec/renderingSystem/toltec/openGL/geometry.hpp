#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		16 I 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		tgl::Geometry class holds all vertex and index buffers needed to render
*		all visual aspects of an object (faces, wireframe, vertices, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

#include "renderingSystem/openGL/vertexBuffer.hpp"
#include "renderingSystem/openGL/indexBuffer.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	GEOMETRY
    *-----------------------------------------------------------------------------*/
    class Geometry
    {
    public:
        //CONSTRUCTORS
        virtual			~Geometry() {}

        //ADD
        void			addVertexBuffer(const gl::VertexBuffer& vertexBuffer);
        void			addIndexBuffer(const gl::IndexBuffer& indexBuffer);

    private:
        std::vector<gl::VertexBuffer>	m_vertexBufferList;
        std::vector<gl::IndexBuffer>	m_indexBufferList;
    };
} //NAMESPACE: TGL