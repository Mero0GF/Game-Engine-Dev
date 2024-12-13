#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Rend {

	class REND_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define RD_CORE_TRACE(...)		::Rend::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RD_CORE_INFO(...)		::Rend::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RD_CORE_WARN(...)		::Rend::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RD_CORE_ERROR(...)		::Rend::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RD_CORE_FATAL(...)		::Rend::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define RD_TRACE(...)			::Rend::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RD_INFO(...)			::Rend::Log::GetClientLogger()->info(__VA_ARGS__)
#define RD_WARN(...)			::Rend::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RD_ERROR(...)			::Rend::Log::GetClientLogger()->error(__VA_ARGS__)
#define RD_FATAL(...)			::Rend::Log::GetClientLogger()->critical(__VA_ARGS__)

