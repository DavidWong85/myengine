#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H

#include <string>

namespace myengine
{
	struct Resource
	{
		virtual ~Resource();
		virtual void onLoad(const std::string& path);
		//virtual void onCreate();
		void setPath(std::string path);
		std::string getPath();

	private:
		std::string path;
	};
}

#endif