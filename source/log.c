#include "../include/main.h"

#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include "../include/streams.h"
#include "../include/util.h"

#include "../include/log.h"
#include <stdarg.h>
#include <stdio.h>

int LOG(cstr format, ...) {
	return 0; // ?
}

int LOG_FUNC(cstr szFile, cstr szFunc, int line) {
	// TODO return LOG(...)?
	return Streams_fpush(3, "| %66s |\n"
			"| %-55s | Line %3d |\n",
			szFile, szFunc, line);
}

int LOG_PRESS(cstr szLabel, int x, int y) {
	return Streams_fpush(3, "| %47s press "
			"(%4d, %-4d) |\n", szLabel, x, y);
}

int LOG_SYSTEM(void) {
	// TODO return LOG(...)?
	int output = 0;
	cstr szFormat = "| %38s %-27s |\n";
	#if defined(__cplusplus)
		cstr szCompiled = "Compiled as C++ for";
	#else
		cstr szCompiled = "Compiled as C for";
	#endif

	#if defined(__linux__)
		cstr szOS = "Linux.";
	#elif defined(_WIN64)
		cstr szOS = "64-bit Windows.";
	#elif defined(_WIN32)
		cstr szOS = "32-bit or 64-bit Windows.";
	#else
		cstr szOS = "undefined operating system.";
	#endif

	return Streams_fpush(3, szFormat, 
			szCompiled, szOS);
}
