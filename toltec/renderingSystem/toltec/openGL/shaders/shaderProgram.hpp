#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		15 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <map>
#include <vector>

#include <glbinding/gl/types.h>

#include "renderingSystem/openGL/uniform.hpp"

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl
{
    class ShaderInstance;
}

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CLASS DECLARATIONS
    *	SHADER PROGRAM
    *-----------------------------------------------------------------------------*/
    class ShaderProgram
    {
    public:
        //TYPES
        enum ShaderType {
            VERTEX_SHADER,
            GEOMETRY_SHADER,
            FRAGMENT_SHADER
        };

        //CONSTRUCTORS
                        ShaderProgram();
        virtual			~ShaderProgram() {}

        //REMOVE
        void			removeShaderInstance(ShaderInstance* p_shaderInstance);

        //OTHER
        virtual ShaderInstance*		createShaderInstance() {}
        void						updateUniform(gl::Uniform* p_uniform);
        void						updateUniforms(ShaderInstance* p_shaderInstance);

    protected:
        void			createShader(const std::string& path, ShaderProgram::ShaderType shaderType);
        void			linkAndValidate();
        virtual void	setUpUniforms() {}

    protected:
        gl::GLuint					m_id;
        std::vector<gl::GLuint>		m_unattachedShaderIDList;

        std::vector<gl::Uniform>								m_shaderProgramUniformList;
        std::map<ShaderInstance*, std::vector<gl::Uniform*>>	m_shaderInstanceUniformMap;

    private:
        bool			checkForErrors(bool isShaderProgram, gl::GLuint id, gl::GLenum flag,
                            const std::string& errorMessage);
    };
} //NAMESPACE: TGL