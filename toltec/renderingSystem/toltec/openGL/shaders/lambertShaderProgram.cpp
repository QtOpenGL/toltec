/*-----------------------------------------------------------------------------
*   CREATED:
*       22 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "lambertShaderProgram.hpp"

#include "renderingSystem/openGL/uniformUnit.hpp"
#include "renderingSystem/toltec/openGL/shaders/shaderInstance.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    LambertShaderProgram::LambertShaderProgram()
    {
        //SETUP
        this->createShader("../data/shaders/lambert.vert", ShaderProgram::ShaderType::VERTEX);
        this->createShader("../data/shaders/lambert.frag", ShaderProgram::ShaderType::FRAGMENT);
        this->linkAndValidate();
    }

    /*-----------------------------------------------------------------------------
    *   CREATE SHADER INSTANCE
    *-----------------------------------------------------------------------------*/
    ShaderInstance* LambertShaderProgram::createShaderInstance()
    {
        ShaderInstance* p_shaderInstance = new ShaderInstance(this);
        p_shaderInstance->setUniformList(std::move(this->setupUniforms()));

        return p_shaderInstance;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE UNIFORMS
    *-----------------------------------------------------------------------------*/
    void LambertShaderProgram::updateUniforms()
    {
        //...
    }

    /*-----------------------------------------------------------------------------
    *   SETUP UNIFORMS
    *-----------------------------------------------------------------------------*/
    std::vector<std::unique_ptr<gl::Uniform>> LambertShaderProgram::setupUniforms()
    {
        std::vector<std::unique_ptr<gl::Uniform>> uniformList;

        //CREATE
        std::unique_ptr<gl::UniformVec3> p_diffuseColor(new gl::UniformVec3(
            "g_diffuseColor", 
            0.5f, 0.5f, 0.5f, 
            m_id
        ));
        std::unique_ptr<gl::UniformBool> p_isDiffuseMapConnected(new gl::UniformBool(
            "g_isDiffuseMapConnected", 
            false, 
            m_id
        ));
        std::unique_ptr<gl::UniformVec3> p_transparencyColor(new gl::UniformVec3(
            "g_transparencyColor", 
            0.0f, 0.0f, 0.0f, 
            m_id
        ));
        std::unique_ptr<gl::UniformBool> p_isTransparencyMapConnected(new gl::UniformBool(
            "g_isTransparencyMapConnected", 
            false, 
            m_id
        ));
        std::unique_ptr<gl::UniformVec3> p_ambientColor(new gl::UniformVec3(
            "g_ambientColor", 
            0.0f, 0.0f, 0.0f,
            m_id
        ));
        std::unique_ptr<gl::UniformBool> p_isAmbientMapConnected(new gl::UniformBool(
            "g_isAmbientMapConnected", 
            false,
            m_id
        ));

        //ADD
        uniformList.push_back(std::move(p_diffuseColor));
        uniformList.push_back(std::move(p_isDiffuseMapConnected));
        uniformList.push_back(std::move(p_transparencyColor));
        uniformList.push_back(std::move(p_isTransparencyMapConnected));
        uniformList.push_back(std::move(p_ambientColor));
        uniformList.push_back(std::move(p_isAmbientMapConnected));

        return std::move(uniformList);
    }
} //NAMESPACE: TGL