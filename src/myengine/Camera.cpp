#include "Camera.h"

#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	void Camera::onInitialize()
	{
		getCore()->camera = getEntity()->getComponent<Camera>();
	}

	glm::mat4 Camera::getView()
	{
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, getEntity()->getTransform()->getPosition());
		view = glm::rotate(view, glm::radians(rotation), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(angle / 2), glm::vec3(1, 0, 0));

		return glm::inverse(view);
	}

	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(fov), (float)camWidth / (float)camHeight, 0.1f, 100.0f);
	}

	void Camera::setAngle(float _angle)
	{
		angle = _angle;
	}

	void Camera::setRotation(float _rotation)
	{
		rotation = _rotation;
	}

	float Camera::getAngle()
	{
		return angle;
	}

	float Camera::getRotation()
	{
		return rotation;
	}
}