#include "Player.h"
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
			std::cout << "Killed" << std::endl;
			getEntity()->destroy();
		}
	}
};

int main() {
    std::shared_ptr<Core> core = Core::initialize();
	/*
	* Add Cat Object
	*/
	std::shared_ptr<Entity> entity = core->addEntity();
	entity->getTransform()->setPosition(glm::vec3(0, 0, 10));
	std::shared_ptr<Player> cat = entity->addComponent<Player>();
	std::shared_ptr<SoundSource> ss = entity->addComponent<SoundSource>(core->getResources()->load<Sound>("../resources/dixie_horn"));
	std::shared_ptr<Killer> killer = entity->addComponent<Killer>();

	std::shared_ptr<Entity> re = core->addEntity();
	re->getTransform()->setPosition(glm::vec3(0, -5, -10));
	std::shared_ptr<Room> room = re->addComponent<Room>();
	std::shared_ptr<Killer> rkiller = re->addComponent<Killer>();

	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	cameraEntity->addComponent<Camera>();
	cameraEntity->addComponent<CameraController>();
	cameraEntity->addComponent<Listener>();
	//std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	//std::shared_ptr<CameraController> cameraController = cameraEntity->addComponent<CameraController>();

	core->start();

	return 0;
}