/*-----------------------------------------------------------------------------
*	CREATED:
*		22 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "lambertShaderProgram.hpp"

#include "renderingSystem/toltec/openGL/shaders/shaderInstance.hpp"

/*-----------------------------------------------------------------------------
*	NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    LambertShaderProgram::LambertShaderProgram()
    {
        //SETUP
        this->createShader("../data/shaders/lambert.vert", ShaderProgram::VERTEX_SHADER);
        this->createShader("../data/shaders/lambert.frag", ShaderProgram::VERTEX_SHADER);
        this->linkAndValidate();

        this->setUpUniforms();
    }

    /*-----------------------------------------------------------------------------
    *	CREATE SHADER INSTANCE
    *-----------------------------------------------------------------------------*/
    ShaderInstance* LambertShaderProgram::createShaderInstance()
    {
        ShaderInstance* p_shaderInstance = new ShaderInstance(this);

        gl::UniformVec3* p_diffuseColorUniform =		new gl::UniformVec3("g_diffuseColor", m_id);
        gl::UniformBool* p_isDiffuseMapConnected =		new gl::UniformBool("g_isDiffuseMapConnected", m_id);

        gl::UniformVec3* p_transparencyColorUniform =	new gl::UniformVec3("g_transparencyColor", m_id);
        gl::UniformBool* p_isDiffuseMapConnected =		new gl::UniformBool("g_isTransparencyMapConnected", m_id);

        gl::UniformVec3* p_ambientColorUniform =		new gl::UniformVec3("g_ambientColor", m_id);
        gl::UniformBool* p_isDiffuseMapConnected =		new gl::UniformBool("g_isAmbientMapConnected", m_id);



        return p_shaderInstance;
    }

    /*-----------------------------------------------------------------------------
    *	SET UP UNIFORMS
    *-----------------------------------------------------------------------------*/
    void LambertShaderProgram::setUpUniforms()
    {
        //...
    }
} //NAMESPACE: TGL