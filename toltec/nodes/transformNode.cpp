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

#include "utils.hpp"

/*-----------------------------------------------------------------------------
*	CONSTRUCTOR
*-----------------------------------------------------------------------------*/
TransformNode::TransformNode()
	:
	m_translation(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_scale(glm::vec3(1.0f, 1.0f, 1.0f)),

	m_updateModelMatrixFlag(false),

	m_localX(glm::vec3(1.0f, 0.0f, 0.0f)),
	m_localY(glm::vec3(0.0f, 1.0f, 0.0f)),
	m_localZ(glm::vec3(0.0f, 0.0f, 1.0f)),

	m_targetPosition(glm::vec3(0.0f, 0.0f, -1.0f))
{
	//INITIALIZE
	this->setShortName("transformNode");
	m_modelMatrix = utils::calcModelMatrix(m_translation, m_rotation, m_scale);
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
	m_translation =				translation;
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET TRANSLATION
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setTranslation(float x, float y, float z)
{
	m_translation =				glm::vec3(x, y, z);
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET ROTATION
*	(const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(const glm::vec3& rotation)
{
	m_rotation =				rotation;
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET ROTATION
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setRotation(float x, float y, float z)
{
	m_rotation =				glm::vec3(x, y, z);
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float uniformScale)
{
	m_scale =					glm::vec3(uniformScale);
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(const glm::vec3& rotation)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(const glm::vec3& scale)
{
	m_scale =					scale;
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	SET SCALE
*	(float, float, float)
*-----------------------------------------------------------------------------*/
void TransformNode::setScale(float x, float y, float z)
{
	m_scale =					glm::vec3(x, y, z);
	m_updateModelMatrixFlag =	true;
}

/*-----------------------------------------------------------------------------
*	GET MODEL MATRIX
*-----------------------------------------------------------------------------*/
const glm::mat4& TransformNode::getModelMatrix()
{
	if (m_updateModelMatrixFlag == true)
	{
		m_modelMatrix =				utils::calcModelMatrix(m_translation, m_rotation, m_scale);
		m_updateModelMatrixFlag =	false;
	}

	return m_modelMatrix;
}