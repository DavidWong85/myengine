#include "Model.h"

#include <iostream>

namespace myengine
{
	void Model::onLoad(const std::string path)
	{
		mesh = std::make_shared<graphics::Model>(path);
	}
}