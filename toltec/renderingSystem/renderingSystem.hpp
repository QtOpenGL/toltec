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
#include <string>

#include "renderingSystem/renderingAPI.hpp"

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
class RenderingSystem
{
public:
    //CTOR DTOR
    explicit            RenderingSystem(const std::string& name);
    virtual             ~RenderingSystem() {};

    //ADD
    void                addRenderingAPI(RenderingAPI* p_renderingAPI);

    //GET
    const std::string&      getName() const;
    RenderingAPI&           getActiveRenderingAPI();

    //OTHER
    void                switchToRenderingAPI(RenderingAPI::Type renderingAPIType);
    AbstractViewport*   createViewport();
    void                printContextInfo() const;

private:
    std::string                                 m_name;

    std::map<RenderingAPI::Type, RenderingAPI*> m_renderingAPIMap;
    RenderingAPI*                               mp_activeRenderingAPI;
};

/*----------------------------------------------------------------------------*/

inline const std::string& RenderingSystem::getName() const
{
    return m_name;
}

inline RenderingAPI& RenderingSystem::getActiveRenderingAPI()
{
    return *mp_activeRenderingAPI;
}
