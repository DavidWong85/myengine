#include "Room.h"

#include <myengine/myengine.h>

void Room::onInitialize()
{
	std::shared_ptr<Renderer> rendererComponent = getEntity()->addComponent<Renderer>();
	rendererComponent->setModel(getCore()->getResources()->load<Model>("../resources/Room.obj"));
	rendererComponent->setTexture(getCore()->getResources()->load<Texture>("../resources/Dark Room.png"));
}