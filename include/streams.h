#if !defined(STREAMS_H)
#define STREAMS_H

#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include "../include/util.h"
//#include <vector>
//#include <iostream>

int Streams_push(const char *msg);
int Streams_format(const char *format,
		const char *msg, char *dest);
int Streams_fpush(const char *format, 
		const char *msg);


#endif
