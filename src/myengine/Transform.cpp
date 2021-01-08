#include "Transform.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace myengine
{
	void Transform::onInitialize()
	{
		scale = glm::vec3(1, 1, 1);
	}

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, scale);

		return rtn;
	}
	
	void Transform::setPosition(glm::vec3 _position)
	{
		position = _position;
	}

	void Transform::translate(float x, float y, float z)
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
		
		glm::vec4 fwd = rtn * glm::vec4(x, y, z, 1);

		position = glm::vec3(fwd);
	}

	glm::vec3 Transform::getPosition()
	{
		return position;
	}
}