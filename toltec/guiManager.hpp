#pragma once

/*-----------------------------------------------------------------------------
*   CREATED:
*       08 VIII 2016
*   CONTRIBUTORS:
*       Piotr Makal
*   INFO:
*       GUIManager is a singleton class that is responsible for holding GUI
*       state, creating GUI objects, displaying information to a user, etc.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "ui/gui/abstractPanel.hpp"
#include "ui/gui/panelContainer.hpp"

/*-----------------------------------------------------------------------------
*   FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
namespace ui
{
    namespace gui
    {
        class OutputLineWidget;
        class AbstractPanel;
        class ViewportPanel;
    }
}
class AbstractViewport;

/*-----------------------------------------------------------------------------
*   CLASS DECLARATIONS
*   GUI MANAGER
*-----------------------------------------------------------------------------*/
class GUIManager
{
public:
    static const unsigned int MAX_VIEWPORT_PANELS =     4;
    static const unsigned int MAX_SCENE_TREE_PANELS =   2;

public:
    //SINGLETON
    static GUIManager& getInstance()
    {
        static GUIManager instance;
        return instance;
    }
    GUIManager(const GUIManager&) = delete;
    void operator=(const GUIManager&) = delete;

    //SET
    void            setOutputLineWidget(ui::gui::OutputLineWidget* p_outputLineWidget);

    //GET
    std::vector<std::unique_ptr<ui::gui::PanelContainer>>&                  getFloatingPanelContainerList();
    std::array<ui::gui::ViewportPanel*, GUIManager::MAX_VIEWPORT_PANELS>&   getViewportPanelList();

    //OTHER
    void            displayMessage(const std::string& message);
    void            displayWarning(const std::string& warning);
    void            displayError(const std::string& error);

    //create
    ui::gui::AbstractPanel* createPanel(ui::gui::AbstractPanel::PanelType panelType);
    ui::gui::AbstractPanel& createPanelWithContainer(ui::gui::AbstractPanel::PanelType panelType);

private:
    //SINGLETON
    GUIManager();

private:
    ui::gui::OutputLineWidget*                                              mp_outputLineWidget;

    std::vector<std::unique_ptr<ui::gui::PanelContainer>>                   m_floatingPanelContainerList;
    std::array<ui::gui::ViewportPanel*, GUIManager::MAX_VIEWPORT_PANELS>    m_viewportPanelList;
};

/*----------------------------------------------------------------------------*/

inline std::vector<std::unique_ptr<ui::gui::PanelContainer>>& GUIManager::getFloatingPanelContainerList()
{
    return m_floatingPanelContainerList;
}

inline std::array<ui::gui::ViewportPanel*, GUIManager::MAX_VIEWPORT_PANELS>& GUIManager::getViewportPanelList()
{
    return m_viewportPanelList;
}