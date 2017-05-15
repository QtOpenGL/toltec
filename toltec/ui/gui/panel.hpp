#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       14 V 2017
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       Panel is a base class for all Panel widgets (those widgets can be placed
*       with drag-and-drop behaviour inside PanelContainer.
*-----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------    ---
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   PANEL
    *-----------------------------------------------------------------------------*/
    class Panel : public QWidget
    {
        Q_OBJECT

    public:
        //CONSTRUCTORS
        virtual         ~Panel() {}

    protected:
        virtual void    setupUI() {}
    };
}