#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       15 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <map>
#include <memory>
#include <vector>

#include <glbinding/gl/types.h>

#include "renderingSystem/openGL/uniform.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl
{
    class ShaderInstance;
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   SHADER PROGRAM
    *-----------------------------------------------------------------------------*/
    class ShaderProgram
    {
    public:
        //TYPES
        enum ShaderType {
            VERTEX,
            GEOMETRY,
            FRAGMENT
        };

        //CONSTRUCTORS
                        ShaderProgram();
        virtual         ~ShaderProgram() {}

        //OTHER
        virtual ShaderInstance*     createShaderInstance() { return nullptr; }
        virtual void                updateUniforms() {}

    protected:
        void            createShader(const std::string& shaderFilePath, ShaderProgram::ShaderType shaderType);
        void            linkAndValidate();
        virtual std::vector<std::unique_ptr<gl::Uniform>> setupUniforms() { return {}; }

    protected:
        gl::GLuint                  m_id;
        std::vector<gl::GLuint>     m_unattachedShaderIDList;

    private:
        bool            checkForErrors(bool isShaderProgram, gl::GLuint id, gl::GLenum flag,
                            const std::string& errorMessage);
    };
} //NAMESPACE: TGL