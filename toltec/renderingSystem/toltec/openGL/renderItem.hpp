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
namespace gl
{
    class IndexBuffer;
}
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
                        gl::GLuint              vaoID,
                        gl::IndexBuffer*        p_indexBuffer,
                        ShaderInstance*         p_shaderInstance,
                        RenderItem::DrawMode    drawMode);
    virtual         ~RenderItem() {}

    //OTHER
    void            draw() const;

private:
    gl::GLuint              m_vaoID;
    gl::IndexBuffer*        mp_indexBuffer;
    ShaderInstance*         mp_shaderInstance;
    RenderItem::DrawMode    m_drawMode;
};
} //NAMESPACE: TGL