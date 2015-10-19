#include "../include/main.h"
/* Uses ENABLE_LOGGING if present */
#include "../include/util.h"
#include "../include/term.h"
#include "../include/view.h"

#include <stdlib.h>
#include <SFML/Window.h>

static Format fmt;

extern void quit(void) {
	Term_pushBordered(&fmt, __PRETTY_FUNCTION__);
}

extern int main(int argc, const char **argv){
	Format_init(&fmt, 50, "| ", " |\n");
	Term_pushBordered(&fmt, "Initializing SPIDE");

	atexit(&quit);
	
	sfVideoMode mode = {640, 480, 32};
	sfContextSettings settings = {24, 8, 2, 3, 0};

	sfRenderWindow *window = 
		sfRenderWindow_create(mode, "CSFML!",
				sfResize | sfClose, &settings);

	View view = {mode, settings, window};
	View_init(640, 480, "CSFML", &view);

	while(View_digestEvents(view.window)){
		/* TODO */
	}

	View_quit(&view);
	return 0; 
}
