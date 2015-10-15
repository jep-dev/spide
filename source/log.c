#include "../include/main.h"

#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include "../include/streams.h"
#include "../include/util.h"

#include "../include/log.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int LOG(cstr format, ...) {
	return 0; // ?
}

int LOG_PARA(cstr szPara) {
	return 0; // TODO
}

int LOG_FUNC(cstr szFile, cstr szFunc, int line) {
/*#ifndef ENABLE_LOGGING
	return 0;
#elif ENABLE_LOGGING*/
		char szLoc[66];
		snprintf(szLoc, 66, "%s, line %d", 
				szFile, line);
		return printf("| %-66s |\n| %-66s |\n", 
				szLoc, szFunc);
/*#else
		return 0;
#endif*/
}

int LOG_PRESS(cstr szLabel, int x, int y) {
	return Streams_fpush(3, "| %47s press "
			"(%4d, %-4d) |\n", szLabel, x, y);
}

int LOG_SYSTEM(void) {
#ifdef ENABLE_LOGGING
	printf("| %-66s |\n", "ENABLE_LOGGING defined");
#endif
	char szBuffered[66];
	strcpy(szBuffered, "Compiled as C");
	
	#if defined(__cplusplus)
		strcat(szBuffered, "++");
	#endif
	strcat(szBuffered, " for ");
	#if defined(__linux__)
		strcat(szBuffered, "Linux.");
	#elif defined(_WIN64)
		strcat(szBuffered, "64-bit Windows.");
	#elif defined(_WIN32)
		strcat(szBuffered, "32-bit or 64-bit Windows.");
	#else
		strcat("an unknown operating system!");
	#endif
	
	return printf("| %-66s |\n", szBuffered);
}
