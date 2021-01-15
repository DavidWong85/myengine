#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H

#include <string>

namespace myengine
{
	struct Resource
	{
		virtual void onLoad(const std::string& path);
		/**
		* set path
		*/
		void setPath(std::string path);
		/**
		* return path
		*/
		std::string getPath();

	private:
		std::string path;
	};
}

#endif