#if !defined(MAIN_H)
#define MAIN_H

// #define SFML_DYNAMIC

#if !defined(ENABLE_LOGGING)
	#define ENABLE_LOGGING true
#endif

#include "../include/util.h"

CEXT int main(int argc, const char **argv); 

#endif
