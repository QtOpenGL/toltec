#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		08 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		GUIManager is a singleton class that is responsible for holding GUI
*		state, creating GUI objects, displaying information to a user, etc.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
//...

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class QLabel;

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	GUI MANAGER
*-----------------------------------------------------------------------------*/
class GUIManager
{
public:
	//SINGLETON
	static GUIManager& getInstance()
	{
		static GUIManager instance;
		return instance;
	}
	GUIManager(const GUIManager&) = delete;
	void operator=(const GUIManager&) = delete;

	//SET
	void	setOutputStreamWidget(QLabel* p_outputStreamWidget);

private:
	//SINGLETON
	GUIManager();

private:
	QLabel*		mp_outputStreamWidget;
};