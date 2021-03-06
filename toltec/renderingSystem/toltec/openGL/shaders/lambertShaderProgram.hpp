#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       22 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "renderingSystem/toltec/openGL/shaders/shaderProgram.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   LAMBERT SHADER PROGRAM
    *-----------------------------------------------------------------------------*/
    class LambertShaderProgram : public ShaderProgram
    {
    public:
        //CTOR DTOR
                        LambertShaderProgram();
        virtual         ~LambertShaderProgram() {}

        //OTHER
        virtual ShaderInstance*     createShaderInstance();
        virtual void                updateUniforms();

    private:
        virtual std::vector<std::unique_ptr<gl::Uniform>> setupUniforms();
    };
} //NAMESPACE: TGL
