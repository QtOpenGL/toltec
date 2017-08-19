/*-----------------------------------------------------------------------------
*   CREATED:
*       14 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "shaderInstance.hpp"

#include "renderingSystem/openGL/uniform.hpp" 
#include "renderingSystem/toltec/openGL/shaders/shaderProgram.hpp" 
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (ShaderProgram*)
*-----------------------------------------------------------------------------*/
ShaderInstance::ShaderInstance(ShaderProgram* p_shaderProgram)
    :
    mp_shaderProgram(p_shaderProgram),
    m_drawMode()
{
}

/*-----------------------------------------------------------------------------
*   SET DRAW MODE
*-----------------------------------------------------------------------------*/
void ShaderInstance::setDrawMode(const gl::GLenum& drawMode)
{
    m_drawMode = drawMode;
}

/*-----------------------------------------------------------------------------
*   SET DRAW MODE
*-----------------------------------------------------------------------------*/
void ShaderInstance::setDrawMode(const core::nodes::ShaderProgramNode::DrawMode& drawMode)
{
    switch (drawMode)
    {
        case core::nodes::ShaderProgramNode::DrawMode::POINTS:      
            m_drawMode = gl::GLenum::GL_POINTS;     
            break;

        case core::nodes::ShaderProgramNode::DrawMode::LINES:       
            m_drawMode = gl::GLenum::GL_LINES;      
            break;

        case core::nodes::ShaderProgramNode::DrawMode::TRIANGLES:   
            m_drawMode = gl::GLenum::GL_TRIANGLES;  
            break;

        default:                                                    
            m_drawMode = gl::GLenum::GL_TRIANGLES;  
            break;

    }
}

/*-----------------------------------------------------------------------------
*   SET UNIFORM LIST
*-----------------------------------------------------------------------------*/
void ShaderInstance::setUniformList(std::vector<std::unique_ptr<gl::Uniform>> uniformList)
{
    m_uniformList = std::move(uniformList);
}

/*-----------------------------------------------------------------------------
*   UPDATE UNIFORMS
*-----------------------------------------------------------------------------*/
void ShaderInstance::updateUniforms()
{
    mp_shaderProgram->updateUniforms();

    for (auto& p_uniform : m_uniformList)
        p_uniform->update();
}
} //NAMESPACE: TGL
