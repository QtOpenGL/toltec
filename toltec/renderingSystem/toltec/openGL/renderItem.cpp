/*-----------------------------------------------------------------------------
*   CREATED:
*       08 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderItem.hpp"

#include <glbinding/gl/enum.h>

#include "renderingSystem/openGL/indexBuffer.hpp"
#include "renderingSystem/toltec/openGL/shaders/shaderInstance.hpp"
#include "renderingSystem/toltec/openGL/shaders/shaderProgram.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
RenderItem::RenderItem(gl::GLuint vaoID, gl::IndexBuffer* p_indexBuffer, 
    ShaderInstance* p_shaderInstance, RenderItem::DrawMode drawMode)
    :
    m_vaoID(vaoID),
    mp_indexBuffer(p_indexBuffer),
    mp_shaderInstance(p_shaderInstance),
    m_drawMode(drawMode)
{
}

/*-----------------------------------------------------------------------------
*   DRAW
*-----------------------------------------------------------------------------*/
void RenderItem::draw() const
{
    //BIND
    mp_shaderInstance->getShaderProgram().bind();
    gl::glBindVertexArray(m_vaoID);
    mp_indexBuffer->bind();

    //UPDATE UNIFORMS
    mp_shaderInstance->updateUniforms();

    //DRAW
    gl::GLenum drawMode;
    switch (m_drawMode)
    {
        case RenderItem::DrawMode::POINTS:      drawMode = gl::GLenum::GL_POINTS;       break;
        case RenderItem::DrawMode::LINES:       drawMode = gl::GLenum::GL_LINES;        break;
        case RenderItem::DrawMode::TRIANGLES:   drawMode = gl::GLenum::GL_TRIANGLES;    break;
        default:                                drawMode = gl::GLenum::GL_POINTS;       break;
    }
    gl::glDrawElements(drawMode, mp_indexBuffer->getIndexCount(), gl::GLenum::GL_UNSIGNED_INT, 0);

    //UNBIND
    mp_indexBuffer->unbind();
    gl::glBindVertexArray(0);
    mp_shaderInstance->getShaderProgram().unbind();
}
} //NAMESPACE: TGL