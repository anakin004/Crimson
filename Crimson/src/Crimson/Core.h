#pragma once


#ifdef CN_PLATFORM_WINDOWS
#if CN_DYANMIC_LINK
	#ifdef CN_BUILD_DLL
		#define CRIMSON_API __declspec(dllexport)
	#else
		#define CRIMSON_API __declspec(dllimport)
	#endif
#else
	#define CRIMSON_API 
#endif 


#else 
	#error Crimson only supports windows!
#endif


#ifdef CN_ENABLE_ASSERTS
	#define CN_ASSERT(x, ...) {if(!(x)) { CN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CN_CORE_ASSERT(x, ...) {if(!(x)) { CN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CN_ASSERT(x, ...)
	#define CN_CORE_ASSERT(x, ...) 
#endif


#define BIT(x) (1 << x )


#define	CN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)