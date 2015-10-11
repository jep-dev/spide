#include "../include/main.h"

// Uses ENABLE_LOGGING if present
#include "../include/util.h"

#include "../include/view.h"


/** Include standard i/o channels */
//#include "stdio.h"


/** 
 * Program entry point
 * @param argc Number of arguments, 1 or greater.
 * @param argv Command line arguments, nonnull.
 *		The first is always the executable name.
 * @return 0 success / 1 failure */
int main(int argc, const char **argv){
	LOG_ME();

	View view(View::DEFAULT_WIDTH,
			View::DEFAULT_HEIGHT,
			"Untitled Window");
	while(View::digestEvents(&view.win)){
		
		// TODO
	}
	return 0; 
}
