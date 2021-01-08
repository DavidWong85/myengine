#include "Listener.h"

#include "Entity.h"
#include "Sound.h"
#include "Transform.h"

#include <iostream>


namespace myengine
{
	void Listener::onInitialize()
	{
		//alGenSources(1, &sid);
		position = getEntity()->getTransform()->getPosition();
		alListener3f(AL_POSITION, position.x, position.y, position.z);
	}

	void Listener::onTick()
	{
		setPosition(getEntity()->getTransform()->getPosition());
		std::cout << "Position : " << position.x << " " << position.y << " " << position.z << std::endl;
	}

	void Listener::setPosition(glm::vec3 _position)
	{
		position = _position;
	}
}