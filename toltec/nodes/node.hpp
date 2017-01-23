#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Base class for the node system.
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <cstdint>
#include <string>

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	NODE
*-----------------------------------------------------------------------------*/
class Node
{
public:
	//CONSTRUCTORS
							Node();
	virtual					~Node();

	//SET
	void					setShortName(const std::string& shortName);
	void					setInitializeFlag(bool value);
	void					setUpdateFlag(bool value);

	//GET
	const std::string&		getShortName() const;
	std::string				getFullName() const;

private:
	std::string				m_shortName;
	const std::uint32_t		m_id;

	bool					m_initializeFlag;
	bool					m_updateFlag;
};

/*----------------------------------------------------------------------------*/

inline const std::string& Node::getShortName() const
{
	return m_shortName;
}
