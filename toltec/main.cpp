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
#include "nodes/shaders/pointCSPNode.hpp"
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
    *	CORE ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //GLOBAL EVENT FILTER
    GlobalEventFilter globalEventFilter;
    application.installEventFilter(&globalEventFilter);
     
    //CREATE CORE OBJECTS
    //root transform node
    TransformNode rootTransformNode;
    rootTransformNode.setShortName("root");
    ResourceManager::getInstance().setRootTransformNode(&rootTransformNode);

    //default camera node
    CameraNode defaultCameraNode;
    defaultCameraNode.setShortName("defaultCam");
    ResourceManager::getInstance().setDefaultCameraNode(&defaultCameraNode);

    //default shader
    LambertSSPNode lambertShaderProgramNode;
    lambertShaderProgramNode.setShortName("defaultShader");
    ResourceManager::getInstance().setDefaultSSPNode(&lambertShaderProgramNode);

    //poly vertex component shader - inactive
    PointCSPNode polyVertexShaderInactive;
    polyVertexShaderInactive.setShortName("polyVertexShaderInactive");
    polyVertexShaderInactive.setColor(1.0f, 0.0f, 1.0f);
    polyVertexShaderInactive.setSize(2);
    ResourceManager::getInstance().addComponentShaderProgramNode(&polyVertexShaderInactive);

    //vertex component shader - inactive hover
    //...
    //vertex component shader - active
    //...
    //vertex component shader - active hover
    //...

    //poly edge component shader - inactive
    PointCSPNode polyEdgeShaderInactive;
    polyEdgeShaderInactive.setShortName("polyEdgeShaderInactive");
    polyEdgeShaderInactive.setColor(1.0f, 0.0f, 1.0f);
    polyEdgeShaderInactive.setSize(1);
    ResourceManager::getInstance().addComponentShaderProgramNode(&polyEdgeShaderInactive);

    //poly edge component shader - inactive hover
    //...
    //poly edge component shader - active
    //...
    //poly edge component shader - active hover
    //...

    /*-----------------------------------------------------------------------------
    *	RENDERING ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //TOLTEC RENDERING SYSTEM
    RenderingSystem toltecRenderingSystem("toltec");
    //opengl
    tgl::ToltecOpenGLRenderer toltecOpenGLRenderer;
    RenderingAPI toltecOpenGLRenderingAPI(RenderingAPI::OPENGL_API, &toltecOpenGLRenderer);
    toltecRenderingSystem.addRenderingAPI(&toltecOpenGLRenderingAPI);

    //ADD RENDERING SYSTEMS TO THE RENDER MANAGER
    RenderManager::getInstance().addRenderingSystem(&toltecRenderingSystem);

    /*-----------------------------------------------------------------------------
    *	GUI
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
    *	PRINT DATA
    *-----------------------------------------------------------------------------*/
    toltecRenderingSystem.printOpenGLData();

    /*-----------------------------------------------------------------------------
    *	EXECUTE
    *-----------------------------------------------------------------------------*/
    return application.exec();
}
