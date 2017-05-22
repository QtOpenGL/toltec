#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       14 V 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       AbstractPanel is a base class for all Panel widgets (those widgets can
*       be placed with drag-and-drop behaviour inside PanelContainer.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>

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
*   ABSTRACT PANEL
*-----------------------------------------------------------------------------*/
class AbstractPanel : public QWidget
{
    Q_OBJECT

public:
    //TYPES
    enum PanelType {
        VIEWPORT,
        SCENE_TREE
    };

    //CONSTRUCTORS
    virtual         ~AbstractPanel() {}

protected:
    virtual void    setupUI() = 0;

protected:
    AbstractPanel::PanelType m_type;
};
} //NAMESPACE: GUI
} //NAMESPACE: UI