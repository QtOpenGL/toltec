#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		08 VIII 2016
*	CONTRIBUTORS:
*		PIOTR MAKAL
*	INFO:
*		GUIManager is a singleton class that is responsible for holding GUI
*		state, creating GUI objects, displaying information to a user, etc.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <string>

/*-----------------------------------------------------------------------------
*	FORWARD DECLARATIONS
*-----------------------------------------------------------------------------*/
class OutputLineWidget;

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
	void	setOutputLineWidget(OutputLineWidget* p_outputLineWidget);

	//OTHER
	void	displayMessage(const std::string& message);
	void	displayWarning(const std::string& warning);
	void	displayError(const std::string& error);

private:
	//SINGLETON
	GUIManager();

private:
	OutputLineWidget*	mp_outputStreamWidget;
};