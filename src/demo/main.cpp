#include "Cat.h"
#include "Room.h"
#include "CameraController.h"
#include <myengine/myengine.h>

#include <iostream>

#define shared std::shared_ptr

using namespace myengine;

struct Killer : public Component
{
	void onTick()
	{
		if (getCore()->getKeyboard()->getKey('k'))
		{
			getEntity()->destroy();
		}
	}
};

int main() {
    std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> cat = core->addEntity();
	cat->getTransform()->setPosition(glm::vec3(0, 0, 10));
	cat->addComponent<Cat>();
	cat->addComponent<SoundSource>(core->getResources()->load<Sound>("../resources/dixie_horn"));
	cat->addComponent<Killer>();

	std::shared_ptr<Entity> room = core->addEntity();
	room->getTransform()->setPosition(glm::vec3(0, -5, -10));
	room->addComponent<Room>();

	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	camera->addComponent<CameraController>();
	camera->addComponent<Listener>();

	core->start();

	return 0;
}