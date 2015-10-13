#if !defined(STREAMS_H)
#define STREAMS_H

#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include "../include/util.h"

int Streams_push(cstr msg);

//int Streams_format(cstr format, 
//		cstr msg, str dest);

int Streams_fpush(int n, cstr format, ...);

#endif
