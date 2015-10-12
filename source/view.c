#include <stdlib.h>

#include "../include/main.h"
// LOG*
#include "../include/util.h"
#include "../include/view.h"

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/OpenGL.h>

bool View_init(int width, int height, 
		const char *title, View *view){
//	LOG_ME();
	sfRenderWindow *window = view -> window;
	sfRenderWindow_setVerticalSyncEnabled(
			window, true);
	sfRenderWindow_setFramerateLimit(
			window, 58);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE); // TODO

	return true;
}

void View_quit(View *view){
//	LOG_ME();
	sfRenderWindow_close(view -> window);
	//free(view);
}

bool View_digestKeyPress(sfRenderWindow *win,
		const sfKeyEvent *ev) {
	switch(ev -> code){
		case sfKeyEscape:
			// Exit FS? Prompt for close?
			return false;
		
		case sfKeyF4: // Toggle FS
		case sfKeyF11: // Toggle FS

		default:
			return true; 
	}
}

bool View_digestMousePress(sfRenderWindow *win, 
		int x, int y, sfMouseButton button) {
	switch(button){
		case sfMouseLeft:
			LOG_PRESS("Left press", x, y);
			break;
		case sfMouseMiddle:
			LOG_PRESS("Middle press", x, y);
			break; 
			case sfMouseRight:
			LOG_PRESS("Right press", x, y);
			break;
		default:
			LOG_PRESS("Other press", x, y);
			break; 
	}
	return true; 
}

bool View_digestEvent(sfRenderWindow *win, 
		const sfEvent *ev){
	switch(ev -> type){
		case sfEvtClosed:
			return false;
			break;
		case sfEvtResized: 
			glViewport(0, 0, ev -> size.width, 
					ev -> size.height);
			break; 
		case sfEvtMouseButtonPressed: {
			const sfMouseButtonEvent mbev 
				= ev -> mouseButton;
			return View_digestMousePress(win, 
					mbev.x, mbev.y, mbev.button);
			}
		case sfEvtKeyPressed:
			return View_digestKeyPress(win, &(ev -> key));
			break;
		default:
			break; 
	}
	return true; 
}

bool View_digestEvents(sfRenderWindow *win) {
	sfEvent ev;
	sfRenderWindow_setActive(win, true);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	while(sfRenderWindow_isOpen(win) 
			&& sfRenderWindow_pollEvent(win, &ev)){
		if(!View_digestEvent(win, &ev))
			return false;
		View_draw(win, 0);
	}
	return true; 
}

void View_draw(sfRenderWindow *win, int ticks) {
	sfRenderWindow_setActive(win, true);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(0,0,0, 0,1,0, 0,0,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	float w=.5, h=.5;
	glVertex3f(w,0,-h);
	glVertex3f(-w,0,-h);
	glVertex3f(-w,0,h);
	glVertex3f(w,0,h);
	glEnd();
	
	glTranslatef(0,-2,0);
	sfRenderWindow_display(win);
	//win -> display();
}
