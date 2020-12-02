#ifndef _RESOURCE_MANAGER__H
#define _RESOURCE_MANAGER__H
#include "ResourceHolder.h"

namespace Singletons
{
	//meyers singleton
	class ResourceManager
	{

	public:
		static ResourceManager& GetInstance()
		{
			static ResourceManager instance;
			return instance;
		}

		ResourceHolder holder;

	private:
		
		ResourceManager()= default;
		~ResourceManager() = default;
		ResourceManager& operator = (const ResourceManager&) = delete;
		ResourceManager(const ResourceManager&) = delete;

	};
}
#endif //_RESOURCE_MANAGER__H
