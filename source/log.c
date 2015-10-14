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
	return printf("| %46s press | %4d | %4d |\n",
			szLabel, x, y);
}

int LOG_SYSTEM(void) {
	// TODO return LOG(...)?
	#if defined(__cplusplus)
		return Streams_fpush(1, "| %66s |\n", "Compiled as C++.");
	#else
		return Streams_fpush(1, "| %66s |\n", "Compiled as C.");
	#endif
}
