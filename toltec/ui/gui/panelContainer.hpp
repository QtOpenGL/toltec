#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       14 V 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       PanelContainer is a visual container for all sorts of classes that 
*       inherit from Panel. Those panels can be arranged inside container in 
*       a multiple different ways (creating on the spot vertical and 
*       horizontal layouts).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace ui
{
    namespace gui
    {
        class AbstractPanel;
    }
}

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
*   PANEL CONTAINER
*-----------------------------------------------------------------------------*/
class PanelContainer : public QWidget
{
    Q_OBJECT

public:
    //CTOR DTOR
                PanelContainer();
    virtual     ~PanelContainer() {}

    //ADD
    void        addPanel(AbstractPanel* p_panel);

private:
    QVBoxLayout*    mp_mainLayout;
};
} //NAMESPACE: GUI
} //NAMESPACE: UI
