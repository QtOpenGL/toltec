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

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace gl 
{
    class Uniform;
}

class ShaderProgram;

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
        void            setUniformList(std::vector<std::unique_ptr<gl::Uniform>>& uniformList);

        //OTHER
        void            updateUniforms();

    private:
        ShaderProgram*                              mp_shaderProgram;
        std::vector<std::unique_ptr<gl::Uniform>>   m_uniformList;
    };
} //NAMESPACE: TGL