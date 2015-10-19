#if !defined(UTIL_H)
#define UTIL_H

#include <stdio.h>
#include <stdarg.h>

typedef char* str;
typedef char const *const cstr;

#ifndef __cplusplus
	#ifndef CEXT
		#define CEXT extern
	#endif
#else
	#ifndef CEXT
		#define CEXT extern "C"
	#endif
#endif

#endif
