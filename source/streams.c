#include "../include/main.h"

#include "../include/util.h"
#include "../include/streams.h"

#include "stdio.h"
#include "stdlib.h"

int Streams_push(const char *msg) {
	// TODO -- enqueue and defer printing
	return puts(msg);
}

int Streams_format(const char *format, 
		const char *msg, char *dest) {
	return sprintf(dest, format, msg);
}

int Streams_fpush(const char *fmt,
		const char *msg) {
	char *dest = malloc(80*sizeof(char));
	int written = Streams_format(fmt, msg, dest);
	if(written<=0){
		written = 0;
	} else {
		Streams_push(dest);
	}
	free(dest);
	return written;
}
