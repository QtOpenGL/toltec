/*-----------------------------------------------------------------------------
*   IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>
#include <memory>

#include <QtWidgets/qapplication.h>
#include <glm/glm.hpp>

#include "events/globalEventFilter.hpp"
#include "ui/commands/creationCommands.hpp"
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
*   FUNCTION DEFINITIONS
*   MAIN
*-----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{ 
    /*-----------------------------------------------------------------------------
    *   START QT
    *-----------------------------------------------------------------------------*/
    QApplication application(argc, argv);

    /*-----------------------------------------------------------------------------
    *   CORE ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //GLOBAL EVENT FILTER
    GlobalEventFilter globalEventFilter;
    application.installEventFilter(&globalEventFilter);
     
    //CREATE PRIMARY OBJECTS
    //root transform node
    std::unique_ptr<TransformNode> p_rootTransformNode(new TransformNode());
    p_rootTransformNode->setShortName("root");
    ResourceManager::getInstance().setRootTransformNode(p_rootTransformNode.get());
    ResourceManager::getInstance().addTransformNode(std::move(p_rootTransformNode));

    //default camera node
    std::unique_ptr<CameraNode> p_defaultCameraNode(new CameraNode());
    p_defaultCameraNode->setShortName("defaultCam");
    ResourceManager::getInstance().setDefaultCameraNode(p_defaultCameraNode.get());
    ResourceManager::getInstance().addCameraNode(std::move(p_defaultCameraNode));

    //default shader
    std::unique_ptr<LambertSSPNode> p_lambertShaderProgramNode(new LambertSSPNode());
    p_lambertShaderProgramNode->setShortName("defaultShader");
    ResourceManager::getInstance().setDefaultSSPNode(p_lambertShaderProgramNode.get());
    ResourceManager::getInstance().addSurfaceShaderProgramNode(std::move(p_lambertShaderProgramNode));

    //poly vertex component shader - inactive
    std::unique_ptr<PointCSPNode> p_polyVertexShaderInactive(new PointCSPNode());
    p_polyVertexShaderInactive->setShortName("polyVertexShaderInactive");
    p_polyVertexShaderInactive->setColor(1.0f, 0.0f, 1.0f);
    p_polyVertexShaderInactive->setSize(2);
    ResourceManager::getInstance().addComponentShaderProgramNode(std::move(p_polyVertexShaderInactive));

    //vertex component shader - inactive hover
    //...
    //vertex component shader - active
    //...
    //vertex component shader - active hover
    //...

    //poly edge component shader - inactive
    //PointCSPNode polyEdgeShaderInactive;
    //polyEdgeShaderInactive.setShortName("polyEdgeShaderInactive");
    //polyEdgeShaderInactive.setColor(1.0f, 0.0f, 1.0f);
    //polyEdgeShaderInactive.setSize(1);
    //ResourceManager::getInstance().addComponentShaderProgramNode(&polyEdgeShaderInactive);

    //poly edge component shader - inactive hover
    //...
    //poly edge component shader - active
    //...
    //poly edge component shader - active hover
    //...

    /*-----------------------------------------------------------------------------
    *   RENDERING ARCHITECTURE
    *-----------------------------------------------------------------------------*/
    //TOLTEC RENDERING SYSTEM
    RenderingSystem toltecRenderingSystem("toltec");

    //opengl
    std::unique_ptr<tgl::ToltecOpenGLRendererResource> p_toltecRendererResource(
        new tgl::ToltecOpenGLRendererResource());
    std::unique_ptr<tgl::ToltecOpenGLRenderer> p_toltecOpenGLRenderer(
        new tgl::ToltecOpenGLRenderer(p_toltecRendererResource.get()));
    RenderingAPI toltecOpenGLRenderingAPI(
        RenderingAPI::OPENGL_API, 
        std::move(p_toltecRendererResource),
        std::move(p_toltecOpenGLRenderer)
    );

    //add
    toltecRenderingSystem.addRenderingAPI(&toltecOpenGLRenderingAPI);

    //ADD RENDERING SYSTEMS TO THE RENDER MANAGER
    RenderManager::getInstance().addRenderingSystem(&toltecRenderingSystem);

    /*-----------------------------------------------------------------------------
    *   GUI
    *-----------------------------------------------------------------------------*/
    ui::gui::MainWindow mainWindow("Toltec", 960, 600);
    mainWindow.show();

    /*-----------------------------------------------------------------------------
    *   CREATE SECONDARY OBJECTS
    *-----------------------------------------------------------------------------*/
    ui::cmds::createCube();

    /*-----------------------------------------------------------------------------
    *   EXECUTE
    *-----------------------------------------------------------------------------*/
    return application.exec();
}
