/*-----------------------------------------------------------------------------
*   CREATED:
*       20 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "uniformUnit.hpp"

#include <glbinding/gl/functions.h>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformUnit::UniformUnit(const std::string& name)
        :
        Uniform(name),
        m_type(UniformUnit::Type::NONE),
        m_location(-1)
    {
        //INITIALIZE
        m_classification = Uniform::Classification::UNIT;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformUnit::UniformUnit(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name),
        m_type(UniformUnit::Type::NONE),
        m_location(-1)
    {
        //INITIALIZE
        m_classification =  Uniform::Classification::UNIT;
        m_location =        gl::glGetUniformLocation(shaderProgramID, m_name.c_str());
    }

    /*-----------------------------------------------------------------------------
    *   SET LOCATION
    *-----------------------------------------------------------------------------*/
    void UniformUnit::setLocation(gl::GLint location)
    {
        m_location = location;
    }

    /*-----------------------------------------------------------------------------
    *   FIND LOCATION
    *-----------------------------------------------------------------------------*/
    bool UniformUnit::findLocation(gl::GLuint shaderProgramID)
    {
        m_location = gl::glGetUniformLocation(shaderProgramID, m_name.c_str());

        if (m_location != -1)
            return true;
        else
            return false;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name)
        :
        UniformUnit(name),
        m_value(false),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::BOOL;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(false),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::BOOL;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const bool&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name, const bool& value, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::BOOL;
    }

    /*-----------------------------------------------------------------------------
    *   SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformBool::setValue(const bool& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *   GET VALUE
    *-----------------------------------------------------------------------------*/
    const bool& UniformBool::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformBool::update() const
    {
        gl::glUniform1i(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name)
        :
        UniformUnit(name),
        m_value(0),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::INT;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(0),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::INT;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const int&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name, const int& value, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::INT;
    }

    /*-----------------------------------------------------------------------------
    *   SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformInt::setValue(const int& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *   GET VALUE
    *-----------------------------------------------------------------------------*/
    const int& UniformInt::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformInt::update() const
    {
        gl::glUniform1i(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name)
        :
        UniformUnit(name),
        m_value(0.0f),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::FLOAT;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(0.0f),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::FLOAT;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name, const float& value, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::FLOAT;
    }

    /*-----------------------------------------------------------------------------
    *   SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformFloat::setValue(const float& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *   GET VALUE
    *-----------------------------------------------------------------------------*/
    const float& UniformFloat::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformFloat::update() const
    {
        gl::glUniform1f(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name)
        :
        UniformUnit(name),
        m_value(glm::vec2()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_2;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(glm::vec2()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_2;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const glm::vec2&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, const glm::vec2& value, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_2;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const float&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, const float& value1, const float& value2, 
        gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(glm::vec2(value1, value2)),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
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
    *   GET VALUE
    *-----------------------------------------------------------------------------*/
    const glm::vec2& UniformVec2::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformVec2::update() const
    {
        gl::glUniform2fv(m_location, 1, &m_value[0]);
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name)
        :
        UniformUnit(name),
        m_value(glm::vec3()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_3;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(glm::vec3()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_3;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const glm::vec2&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, const glm::vec3& value, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = UniformUnit::Type::VEC_3;
    }

    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *   (const std::string&, const float&, const float&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, const float& value1, const float& value2, 
        const float& value3, gl::GLuint shaderProgramID)
        :
        UniformUnit(name, shaderProgramID),
        m_value(glm::vec3(value1, value2, value3)),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
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
    *   GET VALUE
    *-----------------------------------------------------------------------------*/
    const glm::vec3& UniformVec3::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *   UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformVec3::update() const
    {
        gl::glUniform3fv(m_location, 1, &m_value[0]);
    }
} //NAMESPACE: GL