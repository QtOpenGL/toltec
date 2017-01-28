/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <memory>

#include <QtWidgets/qapplication.h>
#include <glm/glm.hpp>

#include "events/globalEventFilter.hpp"
#include "ui/commands/createCube.hpp"
#include "ui/gui/mainWindow.hpp"
#include "ui/gui/viewportPanel.hpp"
#include "nodes/cameraNode.hpp"
#include "nodes/polygonMeshNode.hpp"
#include "nodes/transformNode.hpp"
#include "nodes/shaders/lambertSSPNode.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRenderer.hpp"
#include "renderingSystem/toltec/openGL/toltecOpenGLRendererResource.hpp"
#include "renderingSystem/renderingAPI.hpp"
#include "renderingSystem/renderingSystem.hpp"
#include "renderManager.hpp"
#include "resourceManager.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	FUNCTION DEFINITIONS
*	MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{
	/*-----------------------------------------------------------------------------
	*	START QT
	*-----------------------------------------------------------------------------*/
	QApplication application(argc, argv);

	/*-----------------------------------------------------------------------------
	*	CREATE CORE OBJECTS
	*-----------------------------------------------------------------------------*/
	//GLOBAL EVENT FILTER
	GlobalEventFilter globalEventFilter;
	application.installEventFilter(&globalEventFilter);

	//ROOT TRANSFORM NODE
	TransformNode rootTransformNode;
	rootTransformNode.setShortName("root");
	//add
	ResourceManager::getInstance().setRootTransformNode(&rootTransformNode);

	//DEFAULT CAMERA NODE
	CameraNode defaultCameraNode;
	defaultCameraNode.setShortName("defaultCam");
	//add
	ResourceManager::getInstance().setDefaultCameraNode(&defaultCameraNode);

	//DEFAULT SHADER
	LambertSSPNode lambertShaderProgramNode;
	lambertShaderProgramNode.setShortName("defaultShader");
	//add
	ResourceManager::getInstance().setDefaultSSPNode(&lambertShaderProgramNode);
	
	//TOLTEC RENDERING SYSTEM
	RenderingSystem toltecRenderingSystem("toltec");
	//opengl
	tgl::ToltecOpenGLRenderer toltecOpenGLRenderer;
	RenderingAPI toltecOpenGLRenderingAPI(RenderingAPI::OPENGL_API, &toltecOpenGLRenderer);
	//add
	toltecRenderingSystem.addRenderingAPI(&toltecOpenGLRenderingAPI);

	//ADD RENDERING SYSTEMS TO THE RENDER MANAGER
	RenderManager::getInstance().addRenderingSystem(&toltecRenderingSystem);

	/*-----------------------------------------------------------------------------
	*	CREATE GUI
	*-----------------------------------------------------------------------------*/
	MainWindow mainWindow("Toltec", 960, 600);
	
	//VIEWPORT PANEL
	ViewportPanel viewportPanel0;

	//SET MAIN PANEL
	mainWindow.setMainPanel(&viewportPanel0);

	//SHOW MAIN WINDOW
	mainWindow.show();

	/*-----------------------------------------------------------------------------
	*	CREATE SECONDARY OBJECTS
	*-----------------------------------------------------------------------------*/
	createCube();

	/*-----------------------------------------------------------------------------
	*	EXECUTE
	*-----------------------------------------------------------------------------*/
	return application.exec();
}
