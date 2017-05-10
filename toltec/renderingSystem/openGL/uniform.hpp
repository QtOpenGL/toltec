#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       25 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   UNIFORM
    *-----------------------------------------------------------------------------*/
    class Uniform
    {
    public:
        //TYPES
        enum Classification {
            NONE,
            UNIT,
            CONTAINER
        };

        //CONSTRUCTORS
        explicit        Uniform(const std::string& name);
        virtual         ~Uniform() {}

        //SET
        void            setName(const std::string& name);

        //GET
        Uniform::Classification     getClassification() const;
        const std::string&          getName() const;

        //OTHER
        virtual void    update() const {}

    protected:
        Uniform::Classification     m_classification;
        std::string                 m_name;
    };

    /*----------------------------------------------------------------------------*/

    inline Uniform::Classification Uniform::getClassification() const
    {
        return m_classification;
    }

    inline const std::string& Uniform::getName() const
    {
        return m_name;
    }
} //NAMESPACE: GL