#include "pch.h"

ISKSE ISKSE::m_Instance;

const char* ISKSE::GetLogPath() const
{
	return PLUGIN_LOG_PATH;
}

const char* ISKSE::GetPluginName() const
{
	return PLUGIN_NAME;
};

std::uint32_t ISKSE::GetPluginVersion() const
{
	return MAKE_PLUGIN_VERSION(
		PLUGIN_VERSION_MAJOR,
		PLUGIN_VERSION_MINOR,
		PLUGIN_VERSION_REVISION);
};

bool ISKSE::CheckRuntimeVersion(std::uint32_t a_version) const
{
	return true;
}
