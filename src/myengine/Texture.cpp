#include "Texture.h"

#include <iostream>

namespace myengine
{
	void Texture::onLoad(const std::string path)
	{
		texture = std::make_shared<graphics::Texture>(path);
	}
}