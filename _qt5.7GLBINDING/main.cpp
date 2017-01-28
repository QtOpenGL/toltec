/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qapplication.h>

#include "renderer.hpp"
#include "window.hpp"

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	QApplication qApplication(argc, argv);

	int width = 800;
	int height = 500;

	Window window("QT 5.7 / GLBINDING", width, height);
	Renderer renderer(&window);

	renderer.requestRender();

	return qApplication.exec();
}
