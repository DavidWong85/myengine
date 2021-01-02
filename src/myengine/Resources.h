#include "Resource.h"

#include <vector>
#include <memory>
#include <string>

namespace myengine
{
	struct Resource;

	struct Resources
	{
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
			rtn->setPath(path);
			rtn->onLoad(path);
			resources.push_back(rtn);

			return rtn;
		}

	private:
		std::vector<std::shared_ptr<Resource>> resources;
	};
}