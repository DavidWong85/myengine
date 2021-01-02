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
		return glm::inverse(getTransform()->getModel());
	}

	glm::mat4 Camera::getProjection()
	{
		return glm::perspective(glm::radians(fov), (float)camWidth / (float)camHeight, 0.1f, 100.0f);
	}
}