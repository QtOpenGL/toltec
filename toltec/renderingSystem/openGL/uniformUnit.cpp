/*-----------------------------------------------------------------------------
*   CREATED:
*       20 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

#include "uniformUnit.hpp"

#include <glbinding/gl/boolean.h>
#include <glbinding/gl/functions.h>

namespace gl
{
UniformUnit::UniformUnit(const std::string& name)
    :
    Uniform(name),
    m_type(UniformUnit::Type::NONE),
    m_location(-1)
{
    m_classification = Uniform::Classification::UNIT;
}

UniformUnit::UniformUnit(const std::string& name, GLuint shaderProgramID)
    :
    Uniform(name),
    m_type(UniformUnit::Type::NONE),
    m_location(-1)
{
    m_classification =  Uniform::Classification::UNIT;
    m_location =        glGetUniformLocation(shaderProgramID, m_name.c_str());
}

void UniformUnit::setLocation(GLint location)
{
    m_location = location;
}

bool UniformUnit::findLocation(GLuint shaderProgramID)
{
    m_location = glGetUniformLocation(shaderProgramID, m_name.c_str());

    if (m_location != -1) return true;
    else return false;
}

UniformBool::UniformBool(const std::string& name)
    :
    UniformUnit(name),
    m_value(false)
{
    m_type = UniformUnit::Type::BOOL;
}

UniformBool::UniformBool(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(false)
{
    m_type = UniformUnit::Type::BOOL;
}

UniformBool::UniformBool(const std::string& name, const bool& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::BOOL;
}

void UniformBool::setValue(const bool& value)
{
    m_value = value;
}

void UniformBool::update() const
{
    glUniform1i(m_location, m_value);
}

UniformInt::UniformInt(const std::string& name)
    :
    UniformUnit(name),
    m_value(0)
{
    m_type = UniformUnit::Type::INT;
}

UniformInt::UniformInt(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(0)
{
    m_type = UniformUnit::Type::INT;
}

UniformInt::UniformInt(const std::string& name, const int& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::INT;
}

void UniformInt::setValue(const int& value)
{
    m_value = value;
}

void UniformInt::update() const
{
    glUniform1i(m_location, m_value);
}

UniformFloat::UniformFloat(const std::string& name)
    :
    UniformUnit(name),
    m_value(0.0f)
{
    m_type = UniformUnit::Type::FLOAT;
}

UniformFloat::UniformFloat(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(0.0f)
{
    m_type = UniformUnit::Type::FLOAT;
}

UniformFloat::UniformFloat(const std::string& name, const float& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::FLOAT;
}

void UniformFloat::setValue(const float& value)
{
    m_value = value;
}

void UniformFloat::update() const
{
    glUniform1f(m_location, m_value);
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&)
*-----------------------------------------------------------------------------*/
UniformVec2::UniformVec2(const std::string& name)
    :
    UniformUnit(name),
    m_value(glm::vec2())
{
    m_type = UniformUnit::Type::VEC_2;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec2::UniformVec2(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::vec2())
{
    m_type = UniformUnit::Type::VEC_2;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const glm::vec2&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec2::UniformVec2(const std::string& name, const glm::vec2& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::VEC_2;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const float&, const float&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec2::UniformVec2(const std::string& name, const float& value1, const float& value2, 
    GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::vec2(value1, value2))
{
    m_type = UniformUnit::Type::VEC_2;
}

/*-----------------------------------------------------------------------------
*   SET VALUE
*   (const glm::vec2&)
*-----------------------------------------------------------------------------*/
void UniformVec2::setValue(const glm::vec2& value)
{
    m_value = value;
}

/*-----------------------------------------------------------------------------
*   SET VALUE
*   (const float&, const float&)
*-----------------------------------------------------------------------------*/
void UniformVec2::setValue(const float& value1, const float& value2)
{
    m_value = glm::vec2(value1, value2);
}

/*-----------------------------------------------------------------------------
*   UPDATE
*-----------------------------------------------------------------------------*/
void UniformVec2::update() const
{
    glUniform2fv(m_location, 1, &m_value[0]);
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&)
*-----------------------------------------------------------------------------*/
UniformVec3::UniformVec3(const std::string& name)
    :
    UniformUnit(name),
    m_value(glm::vec3())
{
    m_type = UniformUnit::Type::VEC_3;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec3::UniformVec3(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::vec3())
{
    m_type = UniformUnit::Type::VEC_3;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const glm::vec3&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec3::UniformVec3(const std::string& name, const glm::vec3& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::VEC_3;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const float&, const float&, const float&, GLuint)
*-----------------------------------------------------------------------------*/
UniformVec3::UniformVec3(const std::string& name, const float& value1, const float& value2, 
    const float& value3, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::vec3(value1, value2, value3))
{
    m_type = UniformUnit::Type::VEC_3;
}

/*-----------------------------------------------------------------------------
*   SET VALUE
*   (const glm::vec3&)
*-----------------------------------------------------------------------------*/
void UniformVec3::setValue(const glm::vec3& value)
{
    m_value = value;
}

/*-----------------------------------------------------------------------------
*   SET VALUE
*   (const float&, const float&, const float&)
*-----------------------------------------------------------------------------*/
void UniformVec3::setValue(const float& value1, const float& value2, const float& value3)
{
    m_value = glm::vec3(value1, value2, value3);
}

/*-----------------------------------------------------------------------------
*   UPDATE
*-----------------------------------------------------------------------------*/
void UniformVec3::update() const
{
    glUniform3fv(m_location, 1, &m_value[0]);
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&)
*-----------------------------------------------------------------------------*/
UniformMat4::UniformMat4(const std::string& name)
    :
    UniformUnit(name),
    m_value(glm::mat4())
{
    m_type = UniformUnit::Type::MAT_4;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, GLuint)
*-----------------------------------------------------------------------------*/
UniformMat4::UniformMat4(const std::string& name, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::mat4())
{
    m_type = UniformUnit::Type::MAT_4;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const glm::mat4&, GLuint)
*-----------------------------------------------------------------------------*/
UniformMat4::UniformMat4(const std::string& name, const glm::mat4& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(value)
{
    m_type = UniformUnit::Type::MAT_4;
}

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*   (const std::string&, const float&, GLuint)
*-----------------------------------------------------------------------------*/
UniformMat4::UniformMat4(const std::string& name, const float& value, GLuint shaderProgramID)
    :
    UniformUnit(name, shaderProgramID),
    m_value(glm::mat4(value))
{
    m_type = UniformUnit::Type::MAT_4;
}

/*-----------------------------------------------------------------------------
*   SET VALUE
*   (const glm::vec4&)
*-----------------------------------------------------------------------------*/
void UniformMat4::setValue(const glm::mat4& value)
{
    m_value = value;
}

/*-----------------------------------------------------------------------------
*   UPDATE
*-----------------------------------------------------------------------------*/
void UniformMat4::update() const
{
    glUniformMatrix4fv(m_location, 1, GL_FALSE, &m_value[0][0]);
}
} //NAMESPACE: GL
