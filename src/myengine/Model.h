#include "Resource.h"

#include <graphics/graphics.h>

#include <memory>
#include <string>

namespace myengine
{
	struct Renderer;

	struct Model : public Resource
	{
		friend struct Renderer;
		/**
		* set mesh
		*/
		void onLoad(const std::string path);

	private:
		std::shared_ptr<graphics::Model> mesh;
	};
}