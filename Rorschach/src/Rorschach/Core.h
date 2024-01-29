#pragma once

#ifdef RSC_PLATFORM_WINDOWS
	#ifdef RSC_BUILD_DLL
		#define RORSCHACH_API __declspec(dllexport)
	#else
		#define RORSCHACH_API __declspec(dllimport)
	#endif
#else
	#error Rorchach only supports windows!
#endif