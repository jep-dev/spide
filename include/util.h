#ifndef UTIL_H
#define UTIL_H

//#include <vector>
#include "stdio.h"

#if defined(__cplusplus)
	#if !defined(CEXT)
		#define CEXT extern "C"
	#endif
#else
	#if !defined(CEXT)
		#define CEXT
	#endif
#endif

#if !defined(sz)
	/// C string shorthand
	#define sz const char*
#endif

#if defined(ENABLE_LOGGING) && ENABLE_LOGGING
	#if !defined(LOG)
		#define LOG(...) printf(__VA_ARGS__)
	#endif
	#if !defined(LOG_ME)
	#define LOG_ME() LOG( \
		"| %66s |\n%-57s | Line %03d |\n", \
		__FILE__, __PRETTY_FUNCTION__, \
		__LINE__-1 )
	#endif
	#if !defined(LOG_PRESS) 
		#define LOG_PRESS(MSG, X, Y) LOG( \
				"| %52s | %4d | %4d |\n", \
				MSG, X, Y)
	#endif
	#if !defined(LOG_TIME)
		#define LOG_TIME(MSG, T) LOG("| %64s %-1d |\n", MSG, T)
	#endif
	#if !defined(LOG_ENV)
		#if !defined(__cplusplus)
			#define LOG_ENV() LOG("| %66s |\n", "Compiled as C")
		#else
			#define LOG_ENV() LOG("| %66S |\n", "Compiled as C++")
		#endif
	#endif
#else
	#if !defined(LOG)
		#define LOG(...) do{} while(0) 
	#endif
	#if defined(LOG_ME)
		#define LOG_ME() do{} while(0) 
	#endif
	#if !defined(LOG_TIME)
		#define LOG_TIME(MSG, T) do{} while(0)
	#endif
	#if !defined(LOG_PRESS)
		#define LOG_PRESS(MSG, X, Y) do{} while(0)
	#endif
	#if !defined(LOG_ENV)
		#define LOG_ENV() do{} while(0)
	#endif
#endif

#endif
