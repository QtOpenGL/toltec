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
namespace gui
{
    class AbstractPanel;
}

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
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
        //CONSTRUCTORS
                    PanelContainer();
        virtual     ~PanelContainer() {}

        //ADD
        void        addPanel(AbstractPanel* p_panel);

    private:
        QVBoxLayout*    mp_mainLayout;
    };
} //NAMESPACE: GUI