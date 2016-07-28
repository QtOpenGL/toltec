#pragma once

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <iostream>

/*-----------------------------------------------------------------------------
*	MACROS
*-----------------------------------------------------------------------------*/
#define DEBUG_BUILD

#ifdef DEBUG_BUILD
#define LOG_DEBUG(x) do { std::cerr << __FILE__ << "(" << __LINE__ << ") : " << x << "\n"; } \
	while (false)
#else
#define LOG_DEBUG(x) do {} while (false)
#endif

