#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		31 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		ViewportPanel is a class that holds Viewport and menus associated with
*		it.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <QtWidgets/qwidget.h>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QComboBox;
class AbstractViewport;
//class AbstractRenderingSystem;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	VIEWPORT PANEL
*-----------------------------------------------------------------------------*/
class ViewportPanel : public QWidget
{
	Q_OBJECT

public:
	//CONSTRUCTORS AND DESTRUCTORS
				ViewportPanel();
	virtual		~ViewportPanel();

	//GET
	AbstractViewport* getViewport() const;

private:
	void		setupViewport();
	void		setupUI();

private:
	AbstractViewport*			mp_viewport;
	QComboBox*					mp_activeCameraComboBox;
	//AbstractRenderingSystem*	mp_activeRenderingSystem;		//exactly why?
};

/*----------------------------------------------------------------------------*/

inline AbstractViewport* ViewportPanel::getViewport() const
{
	return mp_viewport;
}

