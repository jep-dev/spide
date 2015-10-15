#include "../include/main.h"
#include "../include/streams.h"
#include "../include/util.h"

#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

int Streams_push(cstr msg) {
	// TODO -- enqueue and defer printing
	int output = printf("%s", msg);
	fflush(stdout);
	return output;
}

/*int Streams_format(cstr format, 
		cstr msg, char *dest) {
	// TODO: remove?
	return output = sprintf(dest, format, msg);
}*/

int Streams_fpush(int n, cstr szFormat, ...) {
	const int consoleSize = 70, bufferSize = 1024;
	//str szFull = malloc(bufferSize * sizeof(char));
	
	str szBuffer = (str) malloc(bufferSize 
			* sizeof(char));

	va_list args; // '...' unpacking
	va_start(args, szFormat);
	int total = vprintf(szFormat, args);
	//int total = vsprintf(szBuffer, szFormat, args);
	va_end(args);
/*
	for(int i = 0; i < total; i += consoleSize) {
		cstr line = &szBuffer[i];
		Streams_push(line);
	}*/
	
	free(szBuffer);
	return total;
}
