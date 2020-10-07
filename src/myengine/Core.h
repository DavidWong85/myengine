#include <Memory>
#include <vector>

namespace myengine {

	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void start();
		std::shared_ptr<Entity> addEntity();

	private:
		Core();

		std::vector<std::shared_ptr<Entity>> entities;
	};
}

