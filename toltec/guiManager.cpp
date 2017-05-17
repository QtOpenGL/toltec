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
#include "utils.hpp"

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
gui::AbstractPanel* GUIManager::createPanel(gui::AbstractPanel::PanelType panelType)
{
    switch (panelType)
    {
        case gui::AbstractPanel::PanelType::VIEWPORT:
        {
            gui::ViewportPanel* p_viewportPanel = nullptr;
            for (auto p_viewportPanelListElement : m_viewportPanelList)
            {
                if (p_viewportPanelListElement == nullptr)
                {
                    p_viewportPanelListElement =    new gui::ViewportPanel();
                    p_viewportPanel =               p_viewportPanelListElement;

                    break;
                }
            }

            return p_viewportPanel;
        }

        case gui::AbstractPanel::PanelType::SCENE_TREE:
        {
            //...
        }
    }
}
