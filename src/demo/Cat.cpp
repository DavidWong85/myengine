#include "Cat.h"

#include <myengine/myengine.h>

void Cat::onInitialize()
{
	std::shared_ptr<Renderer> rendererComponent = getEntity()->addComponent<Renderer>();
	rendererComponent->setModel(getCore()->getResources()->load<Model>("curuthers.obj"));
	rendererComponent->setTexture(getCore()->getResources()->load<Texture>("Whiskers_diffuse.png"));
}