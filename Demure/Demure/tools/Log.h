#pragma once
#include<Engine.h>
#include<spdlog/spdlog.h>
#include<spdlog/sinks/stdout_color_sinks.h>
class Log
{
public:
	static void Init()
	{
#ifdef DEMURE_DEBUG
		spdlog::set_level(spdlog::level::trace); 


#else 
		spdlog::set_level(spdlog::level::warn);

#endif
			
	}
	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger;  }


private:
	static std::shared_ptr<spdlog::logger>s_Logger; 
};

#ifdef DEMURE_DEBUG
#define DM_CORE_TRACE(...) ::Log::GetLogger()->trace(__VA_ARGS__)
#define DM_CORE_INFO(...)  ::Log::GetLogger()->info(__VA_ARGS__)
#define DM_CORE_WARN(...)  ::Log::GetLogger()->warn(__VA_ARGS__)
#define DM_CORE_ERROR(...) ::Log::GetLogger()->error(__VA_ARGS__)
#else
// Disable in release builds
#define DM_CORE_TRACE(...)
#define DM_CORE_INFO(...)
#define DM_CORE_WARN(...)
#define DM_CORE_ERROR(...)
#endif