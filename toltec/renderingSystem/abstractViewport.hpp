#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       02 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       AbstractViewport class is a base class for all viewports and holds
*       common interface for them.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtGui/qwindow.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractRenderer;
class TransformNode;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   ABSTRACT VIEWPORT
*-----------------------------------------------------------------------------*/
class AbstractViewport : public QWindow //THIS INHARITANCE SHOULD BE CHANGED IN THE FUTURE!
{
    Q_OBJECT

public:
    //CONSTRUCTORS
                        AbstractViewport();
    virtual             ~AbstractViewport() {}

    //EVENTS
    virtual void        mousePressEvent(QMouseEvent* p_mouseEvent);
    virtual void        mouseReleaseEvent(QMouseEvent* p_mouseEvent);
    virtual void        mouseMoveEvent(QMouseEvent* p_mouseEvent);

    //SET
    void                setRenderer(AbstractRenderer* p_renderer);
    void                setCamera(TransformNode* p_camera);

    //GET
    AbstractRenderer*   getRenderer() const;
    TransformNode*      getCamera() const;

protected:
    AbstractRenderer*   mp_renderer;
    TransformNode*      mp_camera;

private:
    void                tumble(int x, int y);
    void                track(int x, int y);
    void                dolly(int x, int y);

private:
    bool    m_isLeftMouseButtonPressed,
            m_isMiddleMouseButtonPressed,
            m_isRightMouseButtonPressed;

    int     m_mouseLocalXPosition,
            m_mouseLocalYPosition,
            m_mouseRelativeXPosition,
            m_mouseRelativeYPosition;

    float   m_mouseSensitivity;
};

/*----------------------------------------------------------------------------*/

inline AbstractRenderer* AbstractViewport::getRenderer() const
{
    return mp_renderer;
}

inline TransformNode* AbstractViewport::getCamera() const
{
    return mp_camera;
}
