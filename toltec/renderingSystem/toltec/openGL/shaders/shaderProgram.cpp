/*-----------------------------------------------------------------------------
*   CREATED:
*       15 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "shaderProgram.hpp"

#include <glbinding/gl/boolean.h>
#include <glbinding/gl/enum.h>
#include <glbinding/gl/functions.h>
#include <glbinding/Binding.h>

#include "utils.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    ShaderProgram::ShaderProgram()
        :
        m_id(gl::glCreateProgram())
    {
    }

    /*-----------------------------------------------------------------------------
    *   CREATE SHADER
    *-----------------------------------------------------------------------------*/
    void ShaderProgram::createShader(const std::string& shaderFilePath, 
        ShaderProgram::ShaderType shaderType)
    {
        //CREATE SHADER
        gl::GLuint shaderID = 0;
        switch (shaderType)
        {
            case ShaderProgram::ShaderType::VERTEX:
            {
                shaderID = gl::glCreateShader(gl::GLenum::GL_VERTEX_SHADER);
                break;
            }
            case ShaderProgram::ShaderType::GEOMETRY:
            {
                shaderID = gl::glCreateShader(gl::GLenum::GL_GEOMETRY_SHADER);
                break;
            }
            case ShaderProgram::ShaderType::FRAGMENT:
            {
                shaderID = gl::glCreateShader(gl::GLenum::GL_FRAGMENT_SHADER);
                break;
            }
        }

        //CHECK
        if (shaderID == 0)
        {
            DEBUG_ERR("Shader creation failed!");
            return;
        }

        //COMPILE SHADER
        const std::string& shaderCode =         utils::loadTextFile(shaderFilePath, true);
        const gl::GLchar* shaderSourceCode =    shaderCode.c_str();
        gl::GLint shaderSourceCodeLength =      shaderCode.length();

        gl::glShaderSource(shaderID, 1, &shaderSourceCode, &shaderSourceCodeLength);
        gl::glCompileShader(shaderID);

        bool failureFlag = this->checkForErrors(false, shaderID, gl::GLenum::GL_COMPILE_STATUS, 
            "Shader compilation failed!");
        if (failureFlag == false)
            m_unattachedShaderIDList.push_back(shaderID);
    }

    /*-----------------------------------------------------------------------------
    *   LINK AND VALIDATE
    *-----------------------------------------------------------------------------*/
    void ShaderProgram::linkAndValidate()
    {
        //ATTACH SHADERS
        for (const auto& shaderID : m_unattachedShaderIDList)
            gl::glAttachShader(m_id, shaderID);

        //LINK SHADER PROGRAM
        gl::glLinkProgram(m_id);

        bool failureFlag = this->checkForErrors(true, m_id, gl::GLenum::GL_LINK_STATUS, 
            "Program linking failed!");

        //VALIDATE SHADER PROGRAM
        if (failureFlag == false)
        {
            gl::glValidateProgram(m_id);

            this->checkForErrors(true, m_id, gl::GLenum::GL_VALIDATE_STATUS,
                "Program is invalid!");

            //detach and delete shaders
            for (const auto& shaderID : m_unattachedShaderIDList)
            {
                gl::glDetachShader(m_id, shaderID);
                gl::glDeleteShader(shaderID);
            }
            m_unattachedShaderIDList.clear();
        }
    }

    /*-----------------------------------------------------------------------------
    *   CHECK FOR ERRORS
    *-----------------------------------------------------------------------------*/
    bool ShaderProgram::checkForErrors(bool isShaderProgram, gl::GLuint id, gl::GLenum flag, 
        const std::string& errorMessage)
    {
        gl::GLint success =         0;
        gl::GLchar error[2048] =    { 0 };

        if (isShaderProgram)
            gl::glGetProgramiv(id, flag, &success);
        else
            gl::glGetShaderiv(id, flag, &success);

        if (success == gl::GLint(gl::GL_FALSE))
        {
            if (isShaderProgram)
                gl::glGetProgramInfoLog(id, sizeof(error), nullptr, error);
            else
                gl::glGetShaderInfoLog(id, sizeof(error), nullptr, error);

            DEBUG_ERR(errorMessage << " " << error);
            return true;
        }
        else
        {
            return false;
        }
    }
} //NAMESPACE: TGL
