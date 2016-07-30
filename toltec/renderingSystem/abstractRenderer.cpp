/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "abstractRenderer.hpp"

#include <cstdlib>

#include "viewport.hpp"

/*-----------------------------------------------------------------------------
*	ADD VIEWPORT
*-----------------------------------------------------------------------------*/
void AbstractRenderer::addViewport(Viewport* p_viewport)
{
	m_viewportList.push_back(p_viewport);
}

/*-----------------------------------------------------------------------------
*	REMOVE VIEWPORT
*-----------------------------------------------------------------------------*/
void AbstractRenderer::removeViewport(Viewport* p_viewport)
{
	std::size_t numViewports = m_viewportList.size();
	for (std::size_t i = 0; i < numViewports; i++)
	{
		if (m_viewportList[i] == p_viewport)
			m_viewportList.erase(m_viewportList.begin() + i);
	}
}
