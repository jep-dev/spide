/*#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif*/
#include "../include/main.h"

#include "../include/util.h"
#include "../include/streams.h"

#include <stdio.h>

int Streams::push(char *const msg) {
	// TODO -- enqueue and defer printing
	return puts(msg);
}

int Streams::format(char *const format, 
		char *const msg, char *dest) {
	return sprintf(dest, format, msg);
}

int Streams::fpush(
		char *const fmt,
		char *const msg) {
	char *dest = new char[80];
	int written = format(dest, fmt, msg);
	if(written<=0){
		written = 0;
	} else {
		push(dest);
	}
	delete [] dest;
	return written;
}
