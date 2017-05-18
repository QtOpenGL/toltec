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
#include "renderingSystem/abstractRendererResource.hpp"

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
                    RenderingAPI(
                        RenderingAPI::Type                          type,
                        std::unique_ptr<AbstractRendererResource>   p_abstractRendererResource,
                        std::unique_ptr<AbstractRenderer>           p_renderer);
    virtual         ~RenderingAPI() {};

    //ADD
    void            addRenderer(std::unique_ptr<AbstractRenderer> p_renderer);

    //GET
    RenderingAPI::Type      getType() const;
    AbstractRenderer&       getActiveRenderer();

private:
    RenderingAPI::Type                              m_type;
    std::unique_ptr<AbstractRendererResource>       mp_rendererResource;
    std::vector<std::unique_ptr<AbstractRenderer>>  mp_rendererList;
    AbstractRenderer*                               mp_activeRenderer;
};

/*----------------------------------------------------------------------------*/

inline RenderingAPI::Type RenderingAPI::getType() const
{
    return m_type;
}

inline AbstractRenderer& RenderingAPI::getActiveRenderer()
{
    return *mp_activeRenderer;
}