#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       08 II 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ...
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <glbinding/gl/types.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace tgl
{
    class ShaderInstance;
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: TGL (TOLTEC OPENGL)
*-----------------------------------------------------------------------------*/
namespace tgl
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   RENDER ITEM
    *-----------------------------------------------------------------------------*/
    class RenderItem
    {
    public:
        //TYPES
        enum DrawMode {
            POINTS,
            LINES,
            TRIANGLES
        };

        //CONSTRUCTORS
                        RenderItem(
                            gl::GLuint vaoID,
                            gl::GLuint indexBufferID,
                            ShaderInstance* p_shaderInstance,
                            RenderItem::DrawMode drawMode);
        virtual         ~RenderItem() {}

    private:
        gl::GLuint              m_vaoID;
        gl::GLuint              m_indexBufferID;
        ShaderInstance*         mp_shaderInstance;
        RenderItem::DrawMode    m_drawMode;
    };
} //NAMESPACE: TGL