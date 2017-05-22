#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       31 VII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       ViewportPanel is a class that holds Viewport and menus associated with
*       it.
*   
*       IMPORTANT: Do not create instance of this class directly! Use 
*       GUIManager::createViewportPanel() function!
*-----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------    ---
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>
#include "ui/gui/abstractPanel.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;
class QComboBox;
class RenderingSystem;

/*-----------------------------------------------------------------------------
*   NAMESPACE: UI (USER INTERFACE)
*-----------------------------------------------------------------------------*/
namespace ui
{
/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI (GRAPHICAL USER INTERFACE)
*-----------------------------------------------------------------------------*/
namespace gui
{
/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
class ViewportPanel : public AbstractPanel
{
    Q_OBJECT

public:
    //CONSTRUCTORS
    ViewportPanel();
    virtual             ~ViewportPanel();

    //GET
    AbstractViewport*   getViewport() const;

private:
    virtual void        setupUI();

private:
    RenderingSystem*            mp_activeRenderingSystem;
    AbstractViewport*           mp_viewport;

    QComboBox*                  mp_activeCameraComboBox;
};

/*----------------------------------------------------------------------------*/

inline AbstractViewport* ViewportPanel::getViewport() const
{
    return mp_viewport;
}
} //NAMESPACE: GUI
} //NAMESPACE: UI
