#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		31 VII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		ViewportPanel is a class that holds Viewport and menus associated with
*		it.
*-----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------	---
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class AbstractViewport;
class QComboBox;
class RenderingSystem;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
class ViewportPanel : public QWidget
{
    Q_OBJECT

public:
    //CONSTRUCTORS
                ViewportPanel();
    virtual		~ViewportPanel();

    //GET
    AbstractViewport*	getViewport() const;

private:
    void		setupViewport();
    void		setupUI();

private:
    RenderingSystem*			mp_activeRenderingSystem;	
    AbstractViewport*			mp_viewport;

    QComboBox*					mp_activeCameraComboBox;
};

/*----------------------------------------------------------------------------*/

inline AbstractViewport* ViewportPanel::getViewport() const
{
    return mp_viewport;
}

