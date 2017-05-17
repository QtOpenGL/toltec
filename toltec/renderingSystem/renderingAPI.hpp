#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       02 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       RenderingAPI class defines specific rendering API: OpenGL, Vulkan, 
*       Direct3D, etc.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>
#include <vector>

#include "renderingSystem/abstractRenderer.hpp"

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   ABSTRACT RENDERING SYSTEM
*-----------------------------------------------------------------------------*/
class RenderingAPI
{
public:
    //TYPES
    enum Type {
        OPENGL_API,
        VULKAN_API,
        DIRECT3D_API,
        METAL_API,
        UNSPECIFIED_API
    };

    //CONSTRUCTORS
                RenderingAPI(RenderingAPI::Type type, AbstractRenderer* p_renderer);
    virtual     ~RenderingAPI() {};

    //GET
    RenderingAPI::Type              getType() const;
    AbstractRenderer&           getRenderer();

private:
    RenderingAPI::Type                  m_type;
    std::unique_ptr<AbstractRenderer>   mp_renderer;
};

/*----------------------------------------------------------------------------*/

inline RenderingAPI::Type RenderingAPI::getType() const
{
    return m_type;
}

inline AbstractRenderer& RenderingAPI::getRenderer()
{
    return *mp_renderer;
}