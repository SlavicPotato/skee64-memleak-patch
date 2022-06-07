#pragma once

#include <ext/Events.h>
#include <ext/SKSEMessagingEvents.h>

namespace smp
{
	class Patcher :
		::Events::EventSink<SKSEMessagingEvent>
	{
		inline static constexpr std::size_t    EXPECTED_IMAGE_SIZE              = 0x1E4000;
		inline static constexpr std::uintptr_t NIOVTaskDeferredMask_VTBL_RVA    = 0x17FC10;
		inline static constexpr std::uintptr_t NIOVTaskDeferredMask_Run_RVA     = 0xDF8B0;
		inline static constexpr std::uintptr_t NIOVTaskDeferredMask_Dispose_RVA = 0x3060;
		inline static constexpr std::uintptr_t OPERATOR_DELETE_RVA              = 0xFE1B0;

	public:
		[[nodiscard]] inline static constexpr auto& GetSingleton() noexcept
		{
			return m_Instance;
		}

		void Sink();

	private:
		void    Run();
		HMODULE DllGetHandleAndValidate();

		virtual void Receive(const SKSEMessagingEvent& a_evn) override;

		static Patcher m_Instance;
	};
}