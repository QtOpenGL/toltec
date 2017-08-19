#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       14 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>
#include <string>
#include <vector>

#include <glbinding/gl/enum.h>

#include "nodes/shaders/shaderProgramNode.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace gl 
{
    class Uniform;
}

namespace tgl
{
    class ShaderProgram;
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   SHADER INSTANCE
*-----------------------------------------------------------------------------*/
class ShaderInstance
{
public:
    //CONSTRUCTORS
    explicit        ShaderInstance(ShaderProgram* p_shaderProgram);
    virtual         ~ShaderInstance() {}

    //SET
    void            setDrawMode(const gl::GLenum& drawMode);
    void            setDrawMode(const core::nodes::ShaderProgramNode::DrawMode& drawMode);
    void            setUniformList(std::vector<std::unique_ptr<gl::Uniform>> uniformList);

    //GET
    const ShaderProgram&    getShaderProgram() const;
    const gl::GLenum&       getDrawMode() const;

    //OTHER
    void            updateUniforms();

private:
    ShaderProgram*                              mp_shaderProgram;
    gl::GLenum                                  m_drawMode;
    std::vector<std::unique_ptr<gl::Uniform>>   m_uniformList;
};

/*----------------------------------------------------------------------------*/

inline const ShaderProgram& ShaderInstance::getShaderProgram() const
{
    return *mp_shaderProgram;
}

inline const gl::GLenum& ShaderInstance::getDrawMode() const
{
    return m_drawMode;
}

} //NAMESPACE: TGL
