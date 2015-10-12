#include "../include/main.h"

// Uses ENABLE_LOGGING if present
#include "../include/util.h"

#include "../include/view.h"


#include <SFML/Window.h>

/** Include standard i/o channels */
//#include "stdio.h"


/** 
 * Program entry point
 * @param argc Number of arguments, 1 or greater.
 * @param argv Command line arguments, nonnull.
 *		The first is always the executable name.
 * @return 0 success / 1 failure */
int main(int argc, const char **argv){
	//LOG_ME();

	/*View view(View::DEFAULT_WIDTH,
			View::DEFAULT_HEIGHT,
			"Untitled Window");*/
	sfVideoMode mode = {
		.width = 640,
		.height = 480,
		.bitsPerPixel = 32
	};
	sfContextSettings settings = {
		.depthBits = 24,
		.stencilBits = 8,
		.antialiasingLevel = 2,
		.majorVersion = 3,
		.minorVersion = 0
	};
	View view = {
		.mode = mode, 
		.settings = settings,
		.window = sfRenderWindow_create(
				mode, "CSFML!", 
				sfResize|sfClose, &settings)
	};
	View_init(640, 480, "CSFML", &view);
	while(View_digestEvents(view.window)){
		// TODO
	}
	View_quit(&view);
	return 0; 
}
