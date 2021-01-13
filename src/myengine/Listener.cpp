#include "Listener.h"

#include "Sound.h"
#include "Core.h"
#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>


namespace myengine
{
	void Listener::onInitialize()
	{
		//alGenSources(1, &sid);
		position = getEntity()->getTransform()->getPosition();
		angle = getCore()->getCamera()->getAngle();
		rotation = getCore()->getCamera()->getRotation();
		alListener3f(AL_POSITION, position.x, position.y, position.z);
	}

	void Listener::onTick()
	{
		position = getEntity()->getTransform()->getPosition();
		angle = getCore()->getCamera()->getAngle();
		rotation = getCore()->getCamera()->getRotation();

		glm::mat4 Direction(1.0f);
		Direction = glm::rotate(Direction, glm::radians(angle), glm::vec3(1, 0, 0));
		Direction = glm::rotate(Direction, glm::radians(rotation), glm::vec3(0, 1, 0));

		foward = glm::vec3(Direction * glm::vec4(0, 0, -1, 1));
		up = glm::vec3(Direction * glm::vec4(0, 1, 0, 1));

		alListener3f(AL_POSITION, position.x, position.y, position.z);
		float vals[6] = { foward.x , foward.y , foward.z, up.x, up.y, up.z };
		alListenerfv(AL_ORIENTATION, vals);
	}

	void Listener::setAngle(float _angle)
	{
		angle = _angle;
	}

	void Listener::setRotation(float _rotation)
	{

	}
}