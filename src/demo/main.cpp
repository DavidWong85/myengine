#include "player.h"
#include <myengine/myengine.h>
#include <iostream>

using namespace myengine;

int main() {
    std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> pe = core->addEntity();
	std::shared_ptr<Component> pc = pe->addComponent<Player>();

	core->start();

	return 0;
}