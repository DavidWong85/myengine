#include "Resource.h"

#include <graphics/graphics.h>

#include <memory>
#include <string>

namespace myengine
{
	struct Renderer;

	struct Texture : public Resource
	{
		friend struct Renderer;
		void onLoad(const std::string path);

	private:
		std::shared_ptr<graphics::Texture> texture;
	};
}