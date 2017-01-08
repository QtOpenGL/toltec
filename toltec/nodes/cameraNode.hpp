#pragma once

/*-----------------------------------------------------------------------------
*	CREATED:
*		18 IX 2016
*	CONTRIBUTORS:
*		PETER MAKAL
*	INFO:
*		Camera node is responsible for storing information about camera (local
*		z, y and z axes, field of view, z near and far clipping, target, etc.).
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
*	IMPORTS
*-----------------------------------------------------------------------------*/
#include <glm/glm.hpp>
#include "renderableObjectNode.hpp"

/*-----------------------------------------------------------------------------
*	CLASS DECLARATIONS
*	CAMERA NODE
*-----------------------------------------------------------------------------*/
class CameraNode : public RenderableObjectNode
{
public:
	//TYPES
	enum Type {
		PERSPECTIVE_CAMERA,
		ORTHOGRAPHIC_CAMERA
	};

	//CONSTRUCTORS
					CameraNode();
	virtual			~CameraNode() {}

	//SET
	void			setType(const CameraNode::Type cameraType);
	void			setFieldOfView(const float fieldOfView);
	void			setOrthographicArea(const float orthographicArea);
	void			setZNear(const float zNear);
	void			setZFar(const float zFar);

	//GET
	const glm::mat4&	getViewMatrix();
	const glm::mat4&	getProjectionMatrix();		//either perspective or orthographic matrix
	const glm::mat4&	getPerspectiveMatrix();
	const glm::mat4&	getOrthographicMatrix();

	//OTHER
	void			updateViewMatrix();
	void			updateViewMatrix(
		const glm::vec3& cameraPosition, 
		const glm::vec3& targetPosition,
		const glm::vec3& localY);
	void			updatePerspectiveMatrix(const float aspectRatio);
	void			updateOrthographicMatrix(const float aspectRatio);

private:
	CameraNode::Type	m_type;

	float				m_fieldOfView;			//CHANGE ONLY WITH CameraNode::setFieldOfView()!
	float				m_orthographicArea;		//CHANGE ONLY WITH CameraNode::setOrthographicArea()!

	float				m_zNear;				//CHANGE ONLY WITH CameraNode::setZNear()!
	float				m_zFar;					//CHANGE ONLY WITH CameraNode::setZFar()!

	float				m_aspectRatio;

	glm::mat4			m_viewMatrix;

	bool				m_updatePerspectiveMatrixFlag;
	glm::mat4			m_perspectiveMatrix;

	bool				m_updateOrthographicMatrixFlag;
	glm::mat4			m_orthographicMatrix;
};

/*----------------------------------------------------------------------------*/

inline const glm::mat4& CameraNode::getViewMatrix()
{
	return m_viewMatrix;
}