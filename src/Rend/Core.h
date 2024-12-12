#pragma once

#ifdef RD_PLATFORM_WINDOWS
	#ifdef RD_BUILD_DLL
		#define REND_API __declspec(dllexport)
	#else
		#define REND_API __declspec(dllimport)
	#endif
#else
	#error Rend only support windows
#endif
