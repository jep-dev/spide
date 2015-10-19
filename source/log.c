#include "../include/util.h"
#include "../include/term.h"
#include "../include/log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int LOG(cstr szMessage) {
#if !ENABLE_LOGGING
	return 0;
#else
	return Streams_push(szMessage);
#endif
}

int LOG_PARA(cstr szPara) {
#if !ENABLE_LOGGING
	return 0;
#else
	int len = strlen(szPara), 
		written = 0;
	cstr whitespace = " \r\n";
	char line[LEN_OUTER], copy[len];
	strcpy(copy, szPara);

	char *token = strtok(copy, whitespace);
	int remainder = 0;
	while(token != NULL){
		remainder = 1;
		if(strlen(line) + strlen(token) >= LINE_LENGTH-6){
			strcat(line, token);
			written += Streams_pushBordered(line);
			line[0] = '\0';
		}
		strcat(line, token);
		strcat(line, " ");
		
		token = strtok(NULL, whitespace);
	}
	if(remainder > 0){
		written += Streams_pushBordered(line);
	}
	fflush(stdout);
	return written;
#endif
}

int LOG_FUNC(cstr szFile, cstr szFunc, int line) {
#if !ENABLE_LOGGING
	return 0;
#else
	char szLoc[LEN_INNER];
	
	int len1 = snprintf(szLoc, LEN_INNER,
			"(%s, line %d)", szFile, line),
		len2 = strlen(szFunc),
		output = 0;
	if(len1 + len2 < LEN_INNER - 1){
		char szAccum[LEN_INNER], 
			 szRight[LEN_INNER];
		snprintf(szAccum, LEN_INNER, 
				"%s %s", szFunc, szLoc);
		snprintf(szRight, LEN_INNER, 
				"%-.*s", LEN_INNER, szAccum);
		output += Streams_pushBordered(szRight);
	} else {
		char szAligned[LEN_INNER];
		Streams_align(szAligned, szLoc, false);
		output += Streams_pushBordered(szAligned);
		Streams_align(szAligned, szFunc, true);
		output += Streams_pushBordered(szAligned);
	}
	fflush(stdout);
	return output;
#endif
}

int LOG_PRESS(cstr szLabel, int x, int y) {
#if !ENABLE_LOGGING
	return 0;
#else
	return Streams_fpush(3, "| %47s press "
			"(%4d, %-4d) |\n", szLabel, x, y);
#endif
}

int LOG_SYSTEM(void) {
#if !ENABLE_LOGGING
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
	return Streams_pushBordered(szBuffered);
	/*return printf("| %-66s |\n", 
			szBuffered);*/
#endif
}
