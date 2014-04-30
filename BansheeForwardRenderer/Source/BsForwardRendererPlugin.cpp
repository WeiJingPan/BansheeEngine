#include "BsForwardRendererPrerequisites.h"
#include "BsForwardRendererFactory.h"
#include "CmRendererManager.h"

namespace BansheeEngine
{
	extern "C" BS_FWDRND_EXPORT const String& getPluginName()
	{
		return SystemName;
	}

	extern "C" BS_FWDRND_EXPORT void* loadPlugin()
	{
		RendererManager::instance()._registerFactory(cm_shared_ptr<ForwardRendererFactory>());

		return nullptr;
	}
}