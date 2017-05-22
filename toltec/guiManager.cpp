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
void GUIManager::setOutputLineWidget(ui::gui::OutputLineWidget* p_outputStreamWidget)
{
    if (mp_outputLineWidget == nullptr)
        mp_outputLineWidget = p_outputStreamWidget;
}

/*-----------------------------------------------------------------------------
*   DISPLAY MESSAGE
*-----------------------------------------------------------------------------*/
void GUIManager::displayMessage(const std::string& message)
{
    mp_outputLineWidget->setText(message, ui::gui::OutputLineWidget::MessageType::NORMAL);
}

/*-----------------------------------------------------------------------------
*   DISPLAY WARNING
*-----------------------------------------------------------------------------*/
void GUIManager::displayWarning(const std::string& warning)
{
    mp_outputLineWidget->setText(warning, ui::gui::OutputLineWidget::MessageType::WARNING);
}

/*-----------------------------------------------------------------------------
*   DISPLAY ERROR
*-----------------------------------------------------------------------------*/
void GUIManager::displayError(const std::string& error)
{
    mp_outputLineWidget->setText(error, ui::gui::OutputLineWidget::MessageType::ERROR);
}

/*-----------------------------------------------------------------------------
*   CREATE PANEL
*-----------------------------------------------------------------------------*/
ui::gui::AbstractPanel* GUIManager::createPanel(ui::gui::AbstractPanel::PanelType panelType)
{
    switch (panelType)
    {
        case ui::gui::AbstractPanel::PanelType::VIEWPORT:
        {
            ui::gui::ViewportPanel* p_viewportPanel = nullptr;
            for (auto p_viewportPanelListElement : m_viewportPanelList)
            {
                if (p_viewportPanelListElement == nullptr)
                {
                    p_viewportPanelListElement =    new ui::gui::ViewportPanel();
                    p_viewportPanel =               p_viewportPanelListElement;

                    break;
                }
            }

            return p_viewportPanel;
        }

        case ui::gui::AbstractPanel::PanelType::SCENE_TREE:
        {
            //...
        }
    }
}
