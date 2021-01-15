#include "Resource.h"

#include <vector>
#include <memory>
#include <string>

namespace myengine
{
	struct Resource;

	struct Resources
	{
		/**
		* add resource to vector if not already added previously
		*/
		template <typename T>
		std::shared_ptr<T> load(const std::string& path)
		{
			std::shared_ptr<T> rtn;

			for (int i = 0; i < resources.size(); i++)
			{
				if (resources.at(i)->getPath() == path)
				{
					rtn = std::dynamic_pointer_cast<T>(resources.at(i));
					if (!rtn)
					{
						continue;
					}
					return rtn;
				}
			}
			rtn = std::make_shared<T>();

#ifdef EMSCRIPTEN
			rtn->setPath(path);
			rtn->onLoad(path);
#else
			rtn->setPath("../resources/" + path);
			rtn->onLoad("../resources/" + path);
#endif
			resources.push_back(rtn);

			return rtn;
		}

	private:
		std::vector<std::shared_ptr<Resource>> resources;
	};
}