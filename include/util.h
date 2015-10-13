#if !defined(UTIL_H)
#define UTIL_H

#define DO_LOG defined(ENABLE_LOGGING) && \
		ENABLE_LOGGING

#include <stdio.h>
#include <stdarg.h>

typedef char* str;
typedef const char* cstr;

#if defined(__cplusplus)
	#if !defined(CEXT)
		#define CEXT extern "C"
	#endif
#else
	#if !defined(CEXT)
		#define CEXT
	#endif
#endif

#endif
