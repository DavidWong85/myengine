#include "Player.h"

#include <myengine/myengine.h>

void Player::onInitialize()
{
	std::shared_ptr<Renderer> rendererComponent = getEntity()->addComponent<Renderer>();
	rendererComponent->setModel(getCore()->getResources()->load<Model>("../resources/curuthers.obj"));
	rendererComponent->setTexture(getCore()->getResources()->load<Texture>("../resources/Whiskers_diffuse.png"));
}