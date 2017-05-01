#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		04 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include <glm/glm.hpp>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class TransformNode;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT RENDERER RESOURCE
*-----------------------------------------------------------------------------*/
class AbstractRendererResource
{
public:
    //CONSTRUCTORS
                    AbstractRendererResource();
    virtual			~AbstractRendererResource() {}

    //GET
    bool			areResourcesInitialized();

    //OTHER
    virtual void	initializeResources() = 0;
    virtual void	updateResources() = 0;
    virtual void	deleteResources() = 0;

protected:
    virtual void	scanSceneTree(
                        TransformNode* p_transformNode,
                        int& treeDepthLevel,
                        std::vector<glm::mat4>* p_modelMatrixList,
                        bool& calculateFinalModelMatrixFlag,
                        const bool& initializeRendererResourceFlag) = 0;

protected:
    bool			m_areResourcesInitialized;

private:
    //...
};

/*----------------------------------------------------------------------------*/

inline bool AbstractRendererResource::areResourcesInitialized()
{
    return m_areResourcesInitialized;
}