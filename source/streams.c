#include "../include/main.h"
#include "../include/streams.h"
#include "../include/util.h"

#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

int Streams_push(cstr msg) {
	// TODO -- enqueue and defer printing
	int output = printf("%70s", msg);
	fflush(stdout);
	return output;
}

int Streams_format(cstr format, 
		cstr msg, char *dest) {
	return sprintf(dest, format, msg);
}

int Streams_fpush(int n, cstr szFormat, ...) {
	va_list args;
	va_start(args, szFormat);
	int total = vprintf(szFormat, args);
	va_end(args);

	return total;
}
