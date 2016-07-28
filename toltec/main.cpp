/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qapplication.h>

#include "gui/mainWindow.hpp"
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
	*	CREATE GUI
	*-----------------------------------------------------------------------------*/
	MainWindow mainWindow("Toltec", 960, 600);
	
	//CREATE VIEWPORTS

	//mainWindow.setMainPanel();
	DEBUG_MSG("Creating MainWindow.");
	//SHOW MAIN WINDOW
	mainWindow.show();

	return application.exec();
}
