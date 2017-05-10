/*-----------------------------------------------------------------------------
*   CREATED:
*       06 V 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "uniformContainer.hpp"

#include "renderingSystem/openGL/uniformUnit.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GL (OPENGL)
*-----------------------------------------------------------------------------*/
namespace gl
{
    /*-----------------------------------------------------------------------------
    *   UNIFORM CONTAINER
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformContainer::UniformContainer(const std::string& name)
        :
        Uniform(name),
        m_type(UniformContainer::Type::NONE)
    {
        //INITIALIZE
        m_classification = Uniform::Classification::CONTAINER;
    }

    /*-----------------------------------------------------------------------------
    *   UNIFORM ARRAY
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformArray::UniformArray(const std::string& name)
        :
        UniformContainer(name),
        m_arrayTypeContainer(UniformContainer::Type::NONE),
        m_arrayTypeUnit(UniformUnit::Type::NONE)
    {
        //INITIALIZE
        m_type = UniformContainer::Type::ARRAY;
    }

    /*-----------------------------------------------------------------------------
    *   ADD UNIFORM
    *-----------------------------------------------------------------------------*/
    void UniformArray::addUniform(std::unique_ptr<Uniform> p_uniform, gl::GLuint shaderProgramID)
    {
        std::string uniformName = m_name + "[" + std::to_string(m_uniformList.size()) + "]";

        //CHECK ARRAY TYPE
        //initial addition
        if (m_uniformList.size() == 0)
        {
            //unit
            if (p_uniform->getClassification() == Uniform::Classification::UNIT)
            {
                UniformUnit* p_unifromUnit = static_cast<UniformUnit*>(p_uniform.get());
                m_arrayTypeUnit = p_unifromUnit->getType();
            }
            //container
            else if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
            {
                UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform.get());
                if (p_uniformContainer->getType() == UniformContainer::Type::ARRAY)
                    return;     //don't allow multiple dimension arrays
                else if (p_uniformContainer->getType() == UniformContainer::Type::STRUCT)
                    m_arrayTypeContainer = UniformContainer::Type::STRUCT;
            }
        }
        //check type
        {
            //unit
            if (p_uniform->getClassification() == Uniform::Classification::UNIT)
            {
                UniformUnit* p_unifromUnit = static_cast<UniformUnit*>(p_uniform.get());
                if (p_unifromUnit->getType() != m_arrayTypeUnit) 
                    return;

                gl::GLint location = gl::glGetUniformLocation(shaderProgramID, uniformName.c_str());
                p_unifromUnit->setLocation(location);
            }
            //container
            else if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
            {
                UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform.get());
                if (p_uniformContainer->getType() != m_arrayTypeContainer)
                    return;

                p_uniformContainer->findLocations(uniformName, shaderProgramID);
            }
        }

        //ADD
        m_uniformList.push_back(std::move(p_uniform));
    }

    /*-----------------------------------------------------------------------------
    *   FIND LOCATIONS
    *-----------------------------------------------------------------------------*/
    void UniformArray::findLocations(const std::string& baseUniformName, gl::GLuint shaderProgramID)
    {
        //This function serves the purpose of finding locations for uniforms inside
        //array when array is nested in bigger structures. Mainly invoked from
        //UniformContainer::addUniform and UniformContainer::findLocations virtual 
        //functions (so in some way it's a recursive function).


        for (std::size_t i = 0; i < m_uniformList.size(); i++)
        {
            Uniform* p_uniform =        m_uniformList[i].get();
            std::string uniformName =   baseUniformName + "[" + std::to_string(i) + "]";

            //UNIT
            if (p_uniform->getClassification() == Uniform::Classification::UNIT)
            {
                UniformUnit* p_unifromUnit = static_cast<UniformUnit*>(p_uniform);
                gl::GLint location = gl::glGetUniformLocation(shaderProgramID, uniformName.c_str());

                p_unifromUnit->setLocation(location);
            }
            //CONTAINER
            if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
            {
                UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform);
                p_uniformContainer->findLocations(uniformName, shaderProgramID);
            }
        }
    }

    /*-----------------------------------------------------------------------------
    *   UNIFORM STRUCT
    *   CONSTRUCTOR
    *   (const std::string&)
    *-----------------------------------------------------------------------------*/
    UniformStruct::UniformStruct(const std::string& name)
        :
        UniformContainer(name)
    {
        //INITIALIZE
        m_type = UniformContainer::Type::STRUCT;
    }

    /*-----------------------------------------------------------------------------
    *   ADD UNIFORM
    *-----------------------------------------------------------------------------*/
    void UniformStruct::addUniform(std::unique_ptr<Uniform> p_uniform, gl::GLuint shaderProgramID)
    {
        std::string uniformName = m_name + "." + p_uniform->getName();

        //CHECK CLASSIFICATION
        //unit
        if (p_uniform->getClassification() == Uniform::Classification::UNIT)
        {
            UniformUnit* p_unifromUnit = static_cast<UniformUnit*>(p_uniform.get());
            gl::GLint location = gl::glGetUniformLocation(shaderProgramID, uniformName.c_str());

            p_unifromUnit->setLocation(location);
        }
        //container
        else if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
        {
            UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform.get());
            p_uniformContainer->findLocations(uniformName, shaderProgramID);
        }

        //ADD
        m_uniformList.push_back(std::move(p_uniform));
    }

    /*-----------------------------------------------------------------------------
    *   FIND LOCATIONS
    *-----------------------------------------------------------------------------*/
    void UniformStruct::findLocations(const std::string& baseUniformName, gl::GLuint shaderProgramID)
    {
        //This function serves the purpose of finding locations for uniforms inside
        //struct when struct is nested in bigger structures. Mainly invoked from
        //UniformContainer::addUniform and UniformContainer::findLocations virtual 
        //functions (so in some way it's a recursive function).


        for (std::size_t i = 0; i < m_uniformList.size(); i++)
        {
            Uniform* p_uniform = m_uniformList[i].get();
            std::string uniformName = baseUniformName + "." + p_uniform->getName();

            //unit
            if (p_uniform->getClassification() == Uniform::Classification::UNIT)
            {
                UniformUnit* p_unifromUnit = static_cast<UniformUnit*>(p_uniform);
                gl::GLint location = gl::glGetUniformLocation(shaderProgramID, uniformName.c_str());

                p_unifromUnit->setLocation(location);
            }
            //container
            if (p_uniform->getClassification() == Uniform::Classification::CONTAINER)
            {
                UniformContainer* p_uniformContainer = static_cast<UniformContainer*>(p_uniform);
                p_uniformContainer->findLocations(uniformName, shaderProgramID);
            }
        }
    }
} //NAMESPACE: GL