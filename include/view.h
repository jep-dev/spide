#ifndef VIEW_H
#define VIEW_H

#include "../include/util.h"
#include <SFML/Graphics.h>
#include <stdbool.h>


typedef struct View {
	sfVideoMode mode;
	sfContextSettings settings;
	sfRenderWindow *window;
} View;

bool View_init(int width, int height, 
		const char *title, View *view);
void View_quit(View *view);

bool View_digestKeyPress(sfRenderWindow *win, 
		const sfKeyEvent *ev);
bool View_digestMousePress(sfRenderWindow *win,
		int x, int y, sfMouseButton button);
bool View_digestEvent(sfRenderWindow *win, 
		const sfEvent *ev);
bool View_digestEvents(sfRenderWindow *win);
void View_draw(sfRenderWindow *win, 
		int milliDelta);


#endif
