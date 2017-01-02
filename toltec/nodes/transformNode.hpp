#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		30 VIII 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		TransformNode class holds main model matrix that any vertex of a
*		partcular object can be multiply with to place it in world coordinates. 
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <vector>
#include <glm/glm.hpp>
#include "sceneNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	TRANSFORM NODE
*-----------------------------------------------------------------------------*/
class TransformNode : public SceneNode
{
public:
	//CONSTRUCTORS
				TransformNode();
	virtual		~TransformNode() {}

	//ADD
	void		addChild(SceneNode* p_sceneNode);

	//REMOVE
	bool		removeChild(SceneNode* p_sceneNode);

	//SET
	void		setTranslation(const glm::vec3& translation);
	void		setTranslation(float x, float y, float z);
	void		setRotation(const glm::vec3& rotation);
	void		setRotation(float x, float y, float z);
	void		setScale(float uniformScale);
	void		setScale(const glm::vec3& scale);
	void		setScale(float x, float y, float z);

	//GET
	const std::vector<SceneNode*>&	getChildList() const;

	const glm::vec3&				getTranslation() const;
	const glm::vec3&				getRotation() const;
	const glm::vec3&				getScale() const;
	const glm::mat4&				getModelMatrix();

private:
	std::vector<SceneNode*>		m_childList;

	glm::vec3					m_translation;
	glm::vec3					m_rotation;
	glm::vec3					m_scale;

	glm::mat4					m_modelMatrix;

	bool						m_updateModelMatrixFlag;
};

/*----------------------------------------------------------------------------*/

inline const std::vector<SceneNode*>& TransformNode::getChildList() const
{
	return m_childList;
}

inline const glm::vec3& TransformNode::getTranslation() const
{
	return m_translation;
}

inline const glm::vec3& TransformNode::getRotation() const
{
	return m_rotation;
}

inline const glm::vec3& TransformNode::getScale() const
{
	return m_scale;
}
