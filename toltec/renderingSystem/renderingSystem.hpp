#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       02 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "renderingSystem/abstractViewport.hpp"
#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
class RenderingSystem
{
public:
    //CONSTRUCTORS
    explicit            RenderingSystem(const std::string& name);
    virtual             ~RenderingSystem() {};

    //ADD
    void                addRenderingAPI(RenderingAPI* p_renderingAPI);

    //GET
    const std::string&                                      getName() const;
    const RenderingAPI&                                     getActiveRenderingAPI() const;
    const std::vector<std::unique_ptr<AbstractViewport>>&   getViewportList() const;

    //OTHER
    void                switchToRenderingAPI(RenderingAPI::Type renderingAPIType);
    AbstractViewport*   createViewport();

private:
    std::string                                     m_name;

    std::map<RenderingAPI::Type, RenderingAPI*>     m_renderingAPIMap;
    RenderingAPI*                                   mp_activeRenderingAPI;

    std::vector<std::unique_ptr<AbstractViewport>>  m_viewportList;
};

/*----------------------------------------------------------------------------*/

inline const std::string& RenderingSystem::getName() const
{
    return m_name;
}

inline const RenderingAPI& RenderingSystem::getActiveRenderingAPI() const
{
    return *mp_activeRenderingAPI;
}

inline const std::vector<std::unique_ptr<AbstractViewport>>& RenderingSystem::getViewportList() const
{
    return m_viewportList;
}
