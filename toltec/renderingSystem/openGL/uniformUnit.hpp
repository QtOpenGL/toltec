#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       20 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

#include <glbinding/gl/types.h>
#include <glm/glm.hpp>

#include "renderingSystem/openGL/uniform.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   UNIFORM UNIT
    *-----------------------------------------------------------------------------*/
    class UniformUnit : public Uniform
    {
    public:
        //TYPES
        enum Type {
            NONE,
            BOOL,
            INT,
            FLOAT,
            VEC_2,
            VEC_3
        };

        //CONSTRUCTORS
        explicit        UniformUnit(const std::string& name);
                        UniformUnit(const std::string& name, gl::GLuint shaderProgramID);
        virtual         ~UniformUnit() {}

        //SET
        void                    setLocation(gl::GLint location);

        //GET
        UniformUnit::Type       getType() const;
        gl::GLint               getLocation() const;

        //OTHER
        bool            findLocation(gl::GLuint shaderProgramID);
        virtual void    update() const {}

    protected:
        UniformUnit::Type   m_type;
        gl::GLint           m_location;
    };

    /*----------------------------------------------------------------------------*/

    inline UniformUnit::Type UniformUnit::getType() const
    {
        return m_type;
    }

    inline gl::GLint UniformUnit::getLocation() const
    {
        return m_location;
    }

    /*-----------------------------------------------------------------------------
    *   UNIFORM BOOL
    *-----------------------------------------------------------------------------*/
    class UniformBool : public UniformUnit
    {
    public:
        //CONSTRUCTORS
        explicit        UniformBool(
                            const std::string&      name);
                        UniformBool(
                            const std::string&      name,
                            gl::GLuint              shaderProgramID);
                        UniformBool(
                            const std::string&      name,
                            const bool&             value,
                            gl::GLuint              shaderProgramID);
        virtual         ~UniformBool() {}

        //SET
        void            setValue(const bool& value);

        //GET
        const bool&     getValue() const;

        //OTHER 
        virtual void    update() const;

    private:
        bool            m_value;
        const bool*     mp_valueLink;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM INT
    *-----------------------------------------------------------------------------*/
    class UniformInt : public UniformUnit
    {
    public:
        //CONSTRUCTORS
        explicit        UniformInt(
                            const std::string&      name);
                        UniformInt(
                            const std::string&      name, 
                            gl::GLuint              shaderProgramID);
                        UniformInt(
                            const std::string&      name, 
                            const int&              value, 
                            gl::GLuint              shaderProgramID);
        virtual         ~UniformInt() {}

        //SET
        void            setValue(const int& value);

        //GET
        const int&      getValue() const;

        //OTHER
        virtual void    update() const;

    private:
        int             m_value;
        const int*      mp_valueLink;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM FLOAT
    *-----------------------------------------------------------------------------*/
    class UniformFloat : public UniformUnit
    {
    public:
        //CONSTRUCTORS
        explicit        UniformFloat(
                            const std::string&      name);
                        UniformFloat(
                            const std::string&      name, 
                            gl::GLuint              shaderProgramID);
                        UniformFloat(
                            const std::string&      name, 
                            const float&            value, 
                            gl::GLuint              shaderProgramID);
        virtual         ~UniformFloat() {}

        //SET
        void            setValue(const float& value);

        //GET
        const float&    getValue() const;

        //OTHER
        virtual void    update() const;

    private:
        float           m_value;
        const float*    mp_valueLink;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM VECTOR 2
    *-----------------------------------------------------------------------------*/
    class UniformVec2 : public UniformUnit
    {
    public:
        //CONSTRUCTORS
        explicit        UniformVec2(
                            const std::string&      name);
                        UniformVec2(
                            const std::string&      name, 
                            gl::GLuint              shaderProgramID);
                        UniformVec2(
                            const std::string&      name,
                            const glm::vec2&        value,
                            gl::GLuint              shaderProgramID);
                        UniformVec2(
                            const std::string&      name, 
                            const float&            value1, 
                            const float&            value2,
                            gl::GLuint              shaderProgramID);
        virtual         ~UniformVec2() {}

        //SET
        void            setValue(const glm::vec2& value);
        void            setValue(const float& value1, const float& value2);

        //GET
        const glm::vec2&    getValue() const;

        //OTHER 
        virtual void    update() const;

    private:
        glm::vec2           m_value;
        const glm::vec2*    mp_valueLink;
    };

    /*-----------------------------------------------------------------------------
    *   UNIFORM VECTOR 3
    *-----------------------------------------------------------------------------*/
    class UniformVec3 : public UniformUnit
    {
    public:
        //CONSTRUCTORS
        explicit        UniformVec3(
                            const std::string&      name);
                        UniformVec3(
                            const std::string&      name,
                            gl::GLuint              shaderProgramID);
                        UniformVec3(
                            const std::string&      name,
                            const glm::vec3&        value,
                            gl::GLuint              shaderProgramID);
                        UniformVec3(
                            const std::string&      name,
                            const float&            value1,
                            const float&            value2,
                            const float&            value3,
                            gl::GLuint              shaderProgramID);
        virtual         ~UniformVec3() {}

        //SET
        void            setValue(const glm::vec3& value);
        void            setValue(const float& value1, const float& value2, const float& value3);

        //GET
        const glm::vec3&    getValue() const;

        //OTHER 
        virtual void    update() const;

    private:
        glm::vec3           m_value;
        const glm::vec3*    mp_valueLink;
    };
} //NAMESPACE: GL