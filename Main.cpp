#include "pch.h"

#include "Main.h"
#include "Patcher.h"

#include <ext/SKSEMessagingHandler.h>

namespace smp
{
	bool Initialize(const SKSEInterface* a_skse)
	{
		auto mi = a_skse->GetInterface<SKSEMessagingInterface>();
		if (!mi)
		{
			return false;
		}

		SKSEMessagingHandler::GetSingleton().Setup(a_skse->GetPluginHandle(), mi);

		Patcher::GetSingleton().Sink();

		return true;
	}
}