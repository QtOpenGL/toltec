/*-----------------------------------------------------------------------------
*	CREATED:
*		20 II 2017
*	CONTRIBUTORS:
*		Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "uniform.hpp"

#include <glbinding/gl/functions.h>

/*-----------------------------------------------------------------------------
*	NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    Uniform::Uniform(const std::string& name)
        :
        UniformContainer(name),
        m_type(Uniform::NONE_TYPE),
        m_location(-1),
        m_isValueLinked(false)
    {
        //INITIALIZE
        m_containerType = UniformContainer::SINGLE_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    Uniform::Uniform(const std::string& name, gl::GLuint shaderProgramID)
        :
        UniformContainer(name),
        m_type(Uniform::NONE_TYPE),
        m_location(-1),
        m_isValueLinked(false)
    {
        //INITIALIZE
        m_containerType =	UniformContainer::SINGLE_TYPE;
        m_location =		gl::glGetUniformLocation(shaderProgramID, m_name.c_str());
    }

    /*-----------------------------------------------------------------------------
    *	FIND LOCATION
    *-----------------------------------------------------------------------------*/
    bool Uniform::findLocation(gl::GLuint shaderProgramID)
    {
        m_location = gl::glGetUniformLocation(shaderProgramID, m_name.c_str());

        if (m_location != -1)
            return true;
        else
            return false;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name)
        :
        Uniform(name),
        m_value(false),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::BOOL_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(false),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::BOOL_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const bool&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformBool::UniformBool(const std::string& name, const bool& value, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::BOOL_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformBool::setValue(const bool& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformBool::setValueLink(const bool* p_valueLink)
    {
        mp_valueLink = p_valueLink;
        m_isValueLinked = true;
    }

    /*-----------------------------------------------------------------------------
    *	GET VALUE
    *-----------------------------------------------------------------------------*/
    const bool& UniformBool::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *	UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformBool::update() const
    {
        if (m_isValueLinked)
            gl::glUniform1i(m_location, *mp_valueLink);
        else
            gl::glUniform1i(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *	REMOVE VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformBool::removeValueLink()
    {
        mp_valueLink = nullptr;
        m_isValueLinked = false;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name)
        :
        Uniform(name),
        m_value(0),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::INT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(0),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::INT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const int&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformInt::UniformInt(const std::string& name, const int& value, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::INT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformInt::setValue(const int& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformInt::setValueLink(const int* p_valueLink)
    {
        mp_valueLink = p_valueLink;
        m_isValueLinked = true;
    }

    /*-----------------------------------------------------------------------------
    *	GET VALUE
    *-----------------------------------------------------------------------------*/
    const int& UniformInt::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *	UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformInt::update() const
    {
        if (m_isValueLinked)
            gl::glUniform1i(m_location, *mp_valueLink);
        else
            gl::glUniform1i(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *	REMOVE VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformInt::removeValueLink()
    {
        mp_valueLink = nullptr;
        m_isValueLinked = false;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name)
        :
        Uniform(name),
        m_value(0.0f),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::FLOAT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(0.0f),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::FLOAT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformFloat::UniformFloat(const std::string& name, const float& value, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::FLOAT_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *-----------------------------------------------------------------------------*/
    void UniformFloat::setValue(const float& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformFloat::setValueLink(const float* p_valueLink)
    {
        mp_valueLink = p_valueLink;
        m_isValueLinked = true;
    }

    /*-----------------------------------------------------------------------------
    *	GET VALUE
    *-----------------------------------------------------------------------------*/
    const float& UniformFloat::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *	UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformFloat::update() const
    {
        if (m_isValueLinked)
            gl::glUniform1f(m_location, *mp_valueLink);
        else
            gl::glUniform1f(m_location, m_value);
    }

    /*-----------------------------------------------------------------------------
    *	REMOVE VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformFloat::removeValueLink()
    {
        mp_valueLink = nullptr;
        m_isValueLinked = false;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name)
        :
        Uniform(name),
        m_value(glm::vec2()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_2_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(glm::vec2()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_2_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const glm::vec2&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, const glm::vec2& value, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_2_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const float&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec2::UniformVec2(const std::string& name, const float& value1, const float& value2, 
        gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(glm::vec2(value1, value2)),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_2_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *	(const glm::vec2&)
    *-----------------------------------------------------------------------------*/
    void UniformVec2::setValue(const glm::vec2& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *	(const float&, const float&)
    *-----------------------------------------------------------------------------*/
    void UniformVec2::setValue(const float& value1, const float& value2)
    {
        m_value = glm::vec2(value1, value2);
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformVec2::setValueLink(const glm::vec2* p_valueLink)
    {
        mp_valueLink = p_valueLink;
        m_isValueLinked = true;
    }

    /*-----------------------------------------------------------------------------
    *	GET VALUE
    *-----------------------------------------------------------------------------*/
    const glm::vec2& UniformVec2::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *	UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformVec2::update() const
    {
        if (m_isValueLinked)
            gl::glUniform2fv(m_location, 1, &(*mp_valueLink)[0]);
        else
            gl::glUniform2fv(m_location, 1, &m_value[0]);
    }

    /*-----------------------------------------------------------------------------
    *	REMOVE VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformVec2::removeValueLink()
    {
        mp_valueLink = nullptr;
        m_isValueLinked = false;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name)
        :
        Uniform(name),
        m_value(glm::vec3()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_3_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(glm::vec3()),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_3_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const glm::vec2&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, const glm::vec3& value, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(value),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_3_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	CONSTRUCTOR
    *	(const std::string&, const float&, const float&, const float&, gl::GLuint)
    *-----------------------------------------------------------------------------*/
    UniformVec3::UniformVec3(const std::string& name, const float& value1, const float& value2, 
        const float& value3, gl::GLuint shaderProgramID)
        :
        Uniform(name, shaderProgramID),
        m_value(glm::vec3(value1, value2, value3)),
        mp_valueLink(nullptr)
    {
        //INITIALIZE
        m_type = Uniform::VEC_3_TYPE;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *	(const glm::vec3&)
    *-----------------------------------------------------------------------------*/
    void UniformVec3::setValue(const glm::vec3& value)
    {
        m_value = value;
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE
    *	(const float&, const float&, const float&)
    *-----------------------------------------------------------------------------*/
    void UniformVec3::setValue(const float& value1, const float& value2, const float& value3)
    {
        m_value = glm::vec3(value1, value2, value3);
    }

    /*-----------------------------------------------------------------------------
    *	SET VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformVec3::setValueLink(const glm::vec3* p_valueLink)
    {
        mp_valueLink = p_valueLink;
        m_isValueLinked = true;
    }

    /*-----------------------------------------------------------------------------
    *	GET VALUE
    *-----------------------------------------------------------------------------*/
    const glm::vec3& UniformVec3::getValue() const
    {
        if (mp_valueLink != nullptr)
            return *mp_valueLink;
        else
            return m_value;
    }

    /*-----------------------------------------------------------------------------
    *	UPDATE
    *-----------------------------------------------------------------------------*/
    void UniformVec3::update() const
    {
        if (m_isValueLinked)
            gl::glUniform3fv(m_location, 1, &(*mp_valueLink)[0]);
        else
            gl::glUniform3fv(m_location, 1, &m_value[0]);
    }

    /*-----------------------------------------------------------------------------
    *	REMOVE VALUE LINK
    *-----------------------------------------------------------------------------*/
    void UniformVec3::removeValueLink()
    {
        mp_valueLink = nullptr;
        m_isValueLinked = false;
    }
} //NAMESPACE: GL
