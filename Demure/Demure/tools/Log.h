//File		  : Log.h 
//Programmer  : Erik Holmes
//Last Editted: Aug 23,2025
//Description : This file contains the Logging class.   


#pragma once
#include<Engine.h>
#include<spdlog/spdlog.h>
#include<spdlog/sinks/stdout_color_sinks.h>


//Class         :Log
//Description	: This class will contain our logging tool used for debugging and working through problems. 
	class DEMURE_API Log
	{
	public:


		//Method	 : Init
		//Description: This method will initalize our Logger 
		static void Init()
		{

			if (!s_Logger)  // ensure only initialized once
				s_Logger = spdlog::stdout_color_mt("CORE");

#ifdef DEMURE_DEBUG
			spdlog::set_level(spdlog::level::trace);
#else 
			spdlog::set_level(spdlog::level::warn);

#endif

		}
		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }


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



