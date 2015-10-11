#if !defined(STREAMS_H)
#define STREAMS_H

#include "../include/util.h"
//#include <vector>
//#include <iostream>

CEXT struct Streams {

	static int push(char *const msg);

	static int format(char *const format,
			char *const msg, char *dest);

	static int fpush(char *const format, 
			char *const msg);
};

#endif
