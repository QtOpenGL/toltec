/*-----------------------------------------------------------------------------
*	CREATED:
*		14 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include "transformNode.hpp"

#include <cstddef>

#include "sceneNode.hpp"
#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
TransformNode::TransformNode()
	:
	m_scale(glm::vec3(1.0f, 1.0f, 1.0f))
{
}

/*-----------------------------------------------------------------------------
*	ADD CHILD
*-----------------------------------------------------------------------------*/
void TransformNode::addChild(SceneNode* p_sceneNode)
{
	//CHECK IF ALREADY ON THE CHILD LIST
	for (SceneNode* p_childListItem : m_childList)
		if (p_childListItem == p_sceneNode)
			return;

	//ADD CHILD
	m_childList.push_back(p_sceneNode);

	//SET PARENT
	p_sceneNode->setParent(this);
}

/*-----------------------------------------------------------------------------
*	REMOVE CHILD
*-----------------------------------------------------------------------------*/
bool TransformNode::removeChild(SceneNode* p_sceneNode)
{
	bool isRemoved = false;

	for (std::size_t i = 0; i < m_childList.size(); i++)
	{
		if (m_childList[i] == p_sceneNode)
		{
			m_childList.erase(m_childList.begin() + i);
			p_sceneNode->setParent(nullptr);

			isRemoved = true;
		}
	}
	
	return isRemoved;
}

/*-----------------------------------------------------------------------------
*	SET TRANSLATION
*	(const glm::vec3&)
*-----------------------------------------------------------------------------*/
void TransformNode::setTranslation(const glm::vec3& translation)
{
	m_translation = translation;
}

/*-----------------------------------------------------------------------------
*	SET TRANSLATION
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setTranslation(float x, float y, float z)
{
	m_translation = glm::vec3(x, y, z);
}

/*-----------------------------------------------------------------------------
*	SET ROTATION
*	(const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(const glm::vec3& rotation)
{
	m_rotation = rotation;
}

/*-----------------------------------------------------------------------------
*	SET ROTATION
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(float x, float y, float z)
{
	m_rotation = glm::vec3(x, y, z);
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float uniformScale)
{
	m_scale = glm::vec3(uniformScale);
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(const glm::vec3& scale)
{
	m_scale = scale;
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float x, float y, float z)
{
	m_scale = glm::vec3(x, y, z);
}

const glm::mat4& TransformNode::getModelMatrix()
{
	m_modelMatrix = utils::calcModelMatrix(m_translation, m_rotation, m_scale);
	return m_modelMatrix;
}