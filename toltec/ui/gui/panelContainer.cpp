/*-----------------------------------------------------------------------------
*   CREATED:
*       16 V 2017
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "panelContainer.hpp"

#include "ui/gui/abstractPanel.hpp"

/*-----------------------------------------------------------------------------
*   NAMESPACE: GUI
*-----------------------------------------------------------------------------*/
namespace gui
{
    /*-----------------------------------------------------------------------------
    *   CONSTRUCTOR
    *-----------------------------------------------------------------------------*/
    PanelContainer::PanelContainer()
        :
        mp_mainLayout(new QVBoxLayout())
    {   
        //SETUP
        mp_mainLayout->setContentsMargins(0, 0, 0, 0);
        mp_mainLayout->setSpacing(0);
        this->setLayout(mp_mainLayout);
    }

    /*-----------------------------------------------------------------------------
    *   ADD PANEL
    *-----------------------------------------------------------------------------*/
    void PanelContainer::addPanel(AbstractPanel* p_panel)
    {
        mp_mainLayout->addWidget(p_panel);
    }
} //NAMESPACE: GUI