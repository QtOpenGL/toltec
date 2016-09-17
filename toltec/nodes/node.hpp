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
#include <string>

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	NODE
*-----------------------------------------------------------------------------*/
class Node
{
public:
	//CONSTRUCTORS
	virtual					~Node() {}

	//SET
	void					setName(const std::string& name);

	//GET
	const std::string&		getName() const;

protected:
	std::string				m_name;
};

/*----------------------------------------------------------------------------*/

inline const std::string& Node::getName() const
{
	return m_name;
}