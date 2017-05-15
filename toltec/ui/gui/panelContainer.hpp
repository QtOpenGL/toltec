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

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace gui
{
    class Panel;
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
        virtual     ~PanelContainer() {}
    };
}