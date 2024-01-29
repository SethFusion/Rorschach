#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Rorschach {
	class RORSCHACH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};


}

// core log macros
#define RSC_CORE_TRACE(...)      ::Rorschach::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RSC_CORE_INFO(...)       ::Rorschach::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RSC_CORE_WARN(...)       ::Rorschach::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RSC_CORE_ERROR(...)      ::Rorschach::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RSC_CORE_CRITICAL(...)   ::Rorschach::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define RSC_TRACE(...)      ::Rorschach::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RSC_INFO(...)       ::Rorschach::Log::GetClientLogger()->info(__VA_ARGS__)
#define RSC_WARN(...)       ::Rorschach::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RSC_ERROR(...)      ::Rorschach::Log::GetClientLogger()->error(__VA_ARGS__)
#define RSC_CRITICAL(...)   ::Rorschach::Log::GetClientLogger()->critical(__VA_ARGS__)
