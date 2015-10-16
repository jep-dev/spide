#include "../include/main.h"

#include "../include/streams.h"
#include "../include/util.h"

#include "../include/log.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int LOG(cstr sz) {
#ifndef ENABLE_LOGGING
	return 0;
#elif !ENABLE_LOGGING
	return 0;
#else
	return Streams_push(sz);
#endif
}

int LOG_PARA(cstr szPara) {
#ifndef ENABLE_LOGGING
	return 0;
#elif !ENABLE_LOGGING
	return 0;
#else
	int len = strlen(szPara), 
		written = 0;

	char line[66], copy[len];
	strcpy(copy, szPara);

	cstr whitespace = " ";
	char *token = strtok(copy, whitespace);
	int remainder = 0;
	while(token != NULL){
		remainder = 1;
		if(strlen(line)+strlen(token)>=65){
			written += printf("| %-66s |\n", line);
			line[0] = '\0';
		}
		strcat(line, token);
		strcat(line, " ");
		
		token = strtok(NULL, whitespace);
	}
	if(remainder > 0){
		printf("| %-66s |\n", line);
	}
	fflush(stdout);
	return written;
#endif
}

int LOG_FUNC(cstr szFile, cstr szFunc, int line) {
#ifndef ENABLE_LOGGING
	return 0;
#elif !ENABLE_LOGGING
	return 0;
#else
	char szLoc[66];
	snprintf(szLoc, 66, "%s, line %d", 
			szFile, line);
	return printf("| %-66s |\n| %-66s |\n", 
			szLoc, szFunc);
#endif
}

int LOG_PRESS(cstr szLabel, int x, int y) {
#ifndef ENABLE_LOGGING
	return 0;
#elif !ENABLE_LOGGING
	return 0;
#else
	return Streams_fpush(3, "| %47s press "
			"(%4d, %-4d) |\n", szLabel, x, y);
#endif
}

int LOG_SYSTEM(void) {

#ifndef ENABLE_LOGGING
	return 0;
#elif !ENABLE_LOGGING
	return 0;
#else
	char szBuffered[66];
	strcpy(szBuffered, "Compiled as C");
	
	#if defined(__cplusplus)
		strcat(szBuffered, "++");
	#endif
	strcat(szBuffered, " for ");
	#if defined(__linux__)
		strcat(szBuffered, "Linux.");
	#elif defined(_WIN64)
		strcat(szBuffered, 
			"64-bit Windows.");
	#elif defined(_WIN32)
		strcat(szBuffered, 
			"32-bit or 64-bit Windows.");
	#else
		strcat(szBuffered,
			"an unknown operating system!");
	#endif
	
	return printf("| %-66s |\n", 
			szBuffered);
#endif
}
