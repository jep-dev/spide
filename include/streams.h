#if !defined(STREAMS_H)
#define STREAMS_H

#include "../include/util.h"

int Streams_push(cstr msg);

int Streams_format(cstr format, 
		cstr msg, str dest);

int Streams_fpush(int n, cstr format, ...);

#endif
