/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <memory>

#include <QtWidgets/qapplication.h>

#include "gui/mainWindow.hpp"
#include "renderingSystem/viewport.hpp"
#include "renderingSystem/renderManager.hpp"
#include "renderingSystem/toltecRenderer.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	/*-----------------------------------------------------------------------------
	*	START QT
	*-----------------------------------------------------------------------------*/
	QApplication application(argc, argv);

	/*-----------------------------------------------------------------------------
	*	CREATE CORE OBJECTS
	*-----------------------------------------------------------------------------*/
	//RENDERERS
	ToltecRenderer toltecRenderer;
	//add
	RenderManager::getInstance().addRenderer(&toltecRenderer, RenderManager::TOLTEC_RENDERER);

	/*-----------------------------------------------------------------------------
	*	CREATE GUI
	*-----------------------------------------------------------------------------*/
	MainWindow mainWindow("Toltec", 960, 600);
	
	//CREATE VIEWPORTS
	Viewport* p_viewport1 = new Viewport();

	//SET MAIN PANEL
	mainWindow.setMainPanel(p_viewport1);

	//SHOW MAIN WINDOW
	mainWindow.show();

	return application.exec();
}
