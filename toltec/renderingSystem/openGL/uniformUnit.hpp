#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       20 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

#include <string>

#include <glbinding/gl/types.h>
#include <glm/glm.hpp>

#include "renderingSystem/openGL/uniform.hpp"

namespace gl
{
class UniformUnit : public Uniform
{
public:
    enum Type {
        NONE,
        BOOL,
        INT,
        FLOAT,
        VEC_2,
        VEC_3,
        MAT_4
    };

    explicit        UniformUnit(const std::string& name);
                    UniformUnit(const std::string& name, GLuint shaderProgramID);
    virtual         ~UniformUnit() {}

    void                    setLocation(GLint location);

    UniformUnit::Type       getType() const;
    GLint                   getLocation() const;

    bool                    findLocation(GLuint shaderProgramID);
    virtual void            update() const {}

protected:
    UniformUnit::Type   m_type;
    GLint               m_location;
};

inline UniformUnit::Type UniformUnit::getType() const
{
    return m_type;
}

inline GLint UniformUnit::getLocation() const
{
    return m_location;
}

class UniformBool : public UniformUnit
{
public:
    explicit        UniformBool(
                        const std::string&      name);
                    UniformBool(
                        const std::string&      name,
                        GLuint                  shaderProgramID);
                    UniformBool(
                        const std::string&      name,
                        const bool&             value,
                        GLuint                  shaderProgramID);
    virtual         ~UniformBool() {}

    void            setValue(const bool& value);
    const bool&     getValue() const;
    virtual void    update() const;

private:
    bool            m_value;
};

inline const bool& UniformBool::getValue() const
{
    return m_value;
}

class UniformInt : public UniformUnit
{
public:
    explicit        UniformInt(
                        const std::string&      name);
                    UniformInt(
                        const std::string&      name, 
                        GLuint                  shaderProgramID);
                    UniformInt(
                        const std::string&      name, 
                        const int&              value, 
                        GLuint                  shaderProgramID);
    virtual         ~UniformInt() {}

    void            setValue(const int& value);
    const int&      getValue() const;
    virtual void    update() const;

private:
    int             m_value;
};

inline const int& UniformInt::getValue() const
{
    return m_value;
}

class UniformFloat : public UniformUnit
{
public:
    explicit        UniformFloat(
                        const std::string&      name);
                    UniformFloat(
                        const std::string&      name, 
                        GLuint                  shaderProgramID);
                    UniformFloat(
                        const std::string&      name, 
                        const float&            value, 
                        GLuint                  shaderProgramID);
    virtual         ~UniformFloat() {}

    void            setValue(const float& value);
    const float&    getValue() const;
    virtual void    update() const;

private:
    float           m_value;
};

inline const float& UniformFloat::getValue() const
{
    return m_value;
}

class UniformVec2 : public UniformUnit
{
public:
    explicit        UniformVec2(
                        const std::string&      name);
                    UniformVec2(
                        const std::string&      name, 
                        GLuint                  shaderProgramID);
                    UniformVec2(
                        const std::string&      name,
                        const glm::vec2&        value,
                        GLuint                  shaderProgramID);
                    UniformVec2(
                        const std::string&      name, 
                        const float&            value1, 
                        const float&            value2,
                        GLuint                  shaderProgramID);
    virtual         ~UniformVec2() {}

    void                setValue(const glm::vec2& value);
    void                setValue(const float& value1, const float& value2);
    const glm::vec2&    getValue() const;
    virtual void        update() const;

private:
    glm::vec2       m_value;
};

inline const glm::vec2& UniformVec2::getValue() const
{
    return m_value;
}

class UniformVec3 : public UniformUnit
{
public:
    explicit        UniformVec3(
                        const std::string&      name);
                    UniformVec3(
                        const std::string&      name,
                        GLuint                  shaderProgramID);
                    UniformVec3(
                        const std::string&      name,
                        const glm::vec3&        value,
                        GLuint                  shaderProgramID);
                    UniformVec3(
                        const std::string&      name,
                        const float&            value1,
                        const float&            value2,
                        const float&            value3,
                        GLuint                  shaderProgramID);
    virtual         ~UniformVec3() {}

    void                setValue(const glm::vec3& value);
    void                setValue(const float& value1, const float& value2, const float& value3);
    const glm::vec3&    getValue() const;
    virtual void        update() const;

private:
    glm::vec3       m_value;
};

inline const glm::vec3& UniformVec3::getValue() const
{
    return m_value;
}

class UniformMat4 : public UniformUnit
{
public:
    explicit        UniformMat4(
                        const std::string&      name);
                    UniformMat4(
                        const std::string&      name,
                        GLuint                  shaderProgramID);
                    UniformMat4(
                        const std::string&      name,
                        const glm::mat4&        value,
                        GLuint                  shaderProgramID);
                    UniformMat4(
                        const std::string&      name,
                        const float&            value,
                        GLuint                  shaderProgramID);
    virtual         ~UniformMat4() {}

    void                setValue(const glm::mat4& value);
    const glm::mat4&    getValue() const;
    virtual void        update() const;

private:
    glm::mat4       m_value;
};

inline const glm::mat4& UniformMat4::getValue() const
{
    return m_value;
}
} //NAMESPACE: GL
