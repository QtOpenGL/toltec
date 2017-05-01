#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		AbstractRenderer class is a base class for all renderers inside program.
*	
*	RAW POINTER MANAGER:
*		- mp_rendererResource	(AbstractRendererResource)
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>

#include <QtCore/qobject.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;
class AbstractRendererResource;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	ABSTRACT RENDERER
*-----------------------------------------------------------------------------*/
class AbstractRenderer : public QObject
{
    Q_OBJECT

public:
    //CONSTRUCTORS
                    AbstractRenderer();
    virtual			~AbstractRenderer();

    //EVENTS
    virtual bool	event(QEvent* p_event) = 0;

    //GET
    AbstractRendererResource*	getRendererResource();

    //OTHER
    virtual void	requestRender(AbstractViewport* p_viewport) = 0;

protected:
    virtual void	prepareForRendering() = 0;
    virtual void	render(AbstractViewport* p_viewport) = 0;

protected:
    AbstractRendererResource*	mp_rendererResource;
};

/*----------------------------------------------------------------------------*/

inline AbstractRendererResource* AbstractRenderer::getRendererResource()
{
    return mp_rendererResource;
}