#include "pch.h"

#include "Main.h"

extern "C" {
	bool SKSEPlugin_Query(const SKSEInterface* a_skse, PluginInfo* a_info)
	{
		a_info->infoVersion = PluginInfo::kInfoVersion;
		a_info->name        = PLUGIN_NAME;
		a_info->version     = MAKE_PLUGIN_VERSION(
            PLUGIN_VERSION_MAJOR,
            PLUGIN_VERSION_MINOR,
            PLUGIN_VERSION_REVISION);

		return !a_skse->isEditor && a_skse->runtimeVersion == RUNTIME_VERSION_1_5_97;
	}

	bool SKSEPlugin_Load(const SKSEInterface* a_skse)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, PLUGIN_LOG_PATH);
		gLog.SetLogLevel(LogLevel::Debug);

		return smp::Initialize(a_skse);
	}
};