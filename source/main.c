
// Defines ENABLE_LOGGING
#include "../include/main.h"
// Uses ENABLE_LOGGING if present
#include "../include/util.h"
#include "../include/log.h"


#include "../include/view.h"

#include <stdlib.h>
#include <SFML/Window.h>

extern void exitCB(void) {
	LOG_FUNC(__FILE__, __PRETTY_FUNCTION__,
			__LINE__-1);
}

/**\brief Program entry point
 * \param argc Number of arguments, 1 or greater.
 * \param argv Command line arguments, app. name first.
 * \return 0 success / 1 failure */
extern int main(int argc, const char **argv){
	LOG("\n");
	LOG_SYSTEM();
	LOG_FUNC(__FILE__, __PRETTY_FUNCTION__, __LINE__-2);
	atexit(&exitCB);
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
