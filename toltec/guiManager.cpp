/*-----------------------------------------------------------------------------
*   CREATED:
*       08 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include "guiManager.hpp"

#include "ui/gui/outputLineWidget.hpp"
#include "ui/gui/panelContainer.hpp"
#include "ui/gui/viewportPanel.hpp"

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
GUIManager::GUIManager()
    :
    m_viewportPanelList{{ nullptr, nullptr, nullptr, nullptr }},
    mp_outputLineWidget(nullptr)
{
}

/*-----------------------------------------------------------------------------
*   SET OUTPUT BAR
*-----------------------------------------------------------------------------*/
void GUIManager::setOutputLineWidget(gui::OutputLineWidget* p_outputStreamWidget)
{
    if (mp_outputLineWidget == nullptr)
        mp_outputLineWidget = p_outputStreamWidget;
}

/*-----------------------------------------------------------------------------
*   DISPLAY MESSAGE
*-----------------------------------------------------------------------------*/
void GUIManager::displayMessage(const std::string& message)
{
    mp_outputLineWidget->setText(message, gui::OutputLineWidget::MessageType::NORMAL);
}

/*-----------------------------------------------------------------------------
*   DISPLAY WARNING
*-----------------------------------------------------------------------------*/
void GUIManager::displayWarning(const std::string& warning)
{
    mp_outputLineWidget->setText(warning, gui::OutputLineWidget::MessageType::WARNING);
}

/*-----------------------------------------------------------------------------
*   DISPLAY ERROR
*-----------------------------------------------------------------------------*/
void GUIManager::displayError(const std::string& error)
{
    mp_outputLineWidget->setText(error, gui::OutputLineWidget::MessageType::ERROR);
}

/*-----------------------------------------------------------------------------
*   CREATE PANEL
*-----------------------------------------------------------------------------*/
gui::Panel* GUIManager::createPanel(GUIManager::PanelType panelType)
{
    switch (panelType)
    {
        case GUIManager::PanelType::VIEWPORT:
        {
            if (m_viewportPanelList.size() >= GUIManager::MAX_VIEWPORT_PANELS)
                return nullptr;

            gui::ViewportPanel* p_viewportPanel = new gui::ViewportPanel();
            return p_viewportPanel;
        }

        case GUIManager::PanelType::SCENE_TREE:
        {
            //...
        }
    }
}
