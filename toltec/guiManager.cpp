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

/*-----------------------------------------------------------------------------
*   CONSTRUCTOR
*-----------------------------------------------------------------------------*/
GUIManager::GUIManager()
    :
    mp_outputStreamWidget(nullptr)
{
}

/*-----------------------------------------------------------------------------
*   SET OUTPUT BAR
*-----------------------------------------------------------------------------*/
void GUIManager::setOutputLineWidget(OutputLineWidget* p_outputStreamWidget)
{
    if (mp_outputStreamWidget == nullptr)
        mp_outputStreamWidget = p_outputStreamWidget;
}

/*-----------------------------------------------------------------------------
*   DISPLAY MESSAGE
*-----------------------------------------------------------------------------*/
void GUIManager::displayMessage(const std::string& message)
{
    mp_outputStreamWidget->setText(message, OutputLineWidget::NORMAL_MESSAGE);
}

/*-----------------------------------------------------------------------------
*   DISPLAY WARNING
*-----------------------------------------------------------------------------*/
void GUIManager::displayWarning(const std::string& warning)
{
    mp_outputStreamWidget->setText(warning, OutputLineWidget::WARNING_MESSAGE);
}

/*-----------------------------------------------------------------------------
*   DISPLAY ERROR
*-----------------------------------------------------------------------------*/
void GUIManager::displayError(const std::string& error)
{
    mp_outputStreamWidget->setText(error, OutputLineWidget::ERROR_MESSAGE);
}
