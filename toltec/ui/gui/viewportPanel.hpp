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

#include "ui/gui/panel.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;
class QComboBox;
class RenderingSystem;

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CLASS DECLARATIONS
    *   VIEWPORT PANEL
    *-----------------------------------------------------------------------------*/
    class ViewportPanel : public Panel
    {
        Q_OBJECT

    public:
        //CONSTRUCTORS
                    ViewportPanel();
        explicit    ViewportPanel(const unsigned int idNumber);
        virtual     ~ViewportPanel();

        //GET
        AbstractViewport*   getViewport() const;

    private:
        void        setupUI();

    private:
        unsigned int                m_idNumber;

        RenderingSystem*            mp_activeRenderingSystem;   
        AbstractViewport*           mp_viewport;

        QComboBox*                  mp_activeCameraComboBox;
    };

    /*----------------------------------------------------------------------------*/

    inline AbstractViewport* ViewportPanel::getViewport() const
    {
        return mp_viewport;
    }
}
