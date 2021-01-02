#include "Resource.h"

namespace myengine
{
	Resource::~Resource()
	{

	}

	void Resource::onLoad(const std::string& path) 
	{

	}

	void Resource::setPath(std::string path)
	{
		this->path = path;
	}

	std::string Resource::getPath()
	{
		return path;
	}
}