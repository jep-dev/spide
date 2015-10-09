/** Include standard i/o channels */
#include "stdio.h"
#include "../include/main.hpp"

// Uses ENABLE_LOGGING if present
#include "../include/utilities.hpp"

#include "../include/graphics.hpp"

/** 
 * Program entry point
 * @param argc Number of arguments, 1 or greater.
 * @param argv Command line arguments, nonnull.
 *		The first is always the executable name.
 * @return 0 success / 1 failure */
int main(int argc, const char **argv){
	LOG_ME();

	Display disp(400,400,"Untitled Window");
	while(Display::digestEvents(&disp.win)){
		
		// TODO
	}
	return 0; 
}
