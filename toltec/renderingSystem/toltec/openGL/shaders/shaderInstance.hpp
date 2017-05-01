#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		14 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace gl 
{
    class Uniform;
    class UniformArray;
    class UniformStruct;
}

class ShaderProgram;

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	SHADER INSTANCE
    *-----------------------------------------------------------------------------*/
    class ShaderInstance
    {
    public:
        //CONSTRUCTORS
        explicit		ShaderInstance(ShaderProgram* p_shaderProgram);
        virtual			~ShaderInstance() {}

        //GET
        Uniform*		getUniform(const std::string& name);
        UniformArray*	getUniformArray(const std::string& name);
        UniformStruct*	getUniformStruct(const std::string& name);

        //OTHER
        void			updateUniforms();

    private:
        ShaderProgram*	mp_shaderProgram;
    };
} //NAMESPACE: TGL