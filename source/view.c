/*#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif*/
#include "../include/main.h"
// LOG*
#include "../include/util.h"

#include "../include/view.h"

#include <SFML/Graphics.h>
#include <SFML/OpenGL.h>

sfRenderWindow *const View::init(void){
	LOG_ME();
	
	sfVideoMode winMode = {640, 480, 32};
	sfContextSettings winContext;
	winContext.depthBits = 24;
	winContext.stencilBits = 8;
	winContext.antialiasingLevel = 2;
	winContext.majorVersion = 3;
	winContext.minorVersion = 0;
	
	sfUint8 flags = sfResize | sfClose;
	sfRenderWindow *const win = sfRenderWindow_create(
			winMode, "CSFML", flags, &winContext);

	sfRenderWindow_setVerticalSyncEnabled(win, true);
	sfRenderWindow_setFramerateLimit(win, 58);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE); // TODO -- check windings
	return win;
}

bool View::digestKeyPress(sfWindow *const win,
		const sfKeyEvent &ev) {
	switch(ev.code){
		case sfKeyEscape:
			return false;
		
		case sfKeyF4: case sfKeyF11:
		

		default:
			return true; 
	}
}

bool View::digestMousePress(sfWindow *const win, 
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

bool View::digestEvent(sfWindow *const win, 
		const sfEvent &ev){
	switch(ev.type){
		case sfEventClosed:
			return false;
			break;
		case sfEventResized: 
			glViewport(0, 0, ev.size.width, 
					ev.size.height);
			break; 
		case sfEventMouseButtonPressed: {
			const sfEventMouseButtonEvent mbev 
				= ev.mouseButton;
			return digestMousePress(win, 
					mbev.x, mbev.y, mbev.button);
			}
		case sfEventKeyPressed:
			return digestKeyPress(win, ev.key);
			break;
		default:
			break; 
	}
	return true; 
}

bool View::digestEvents(sfWindow *const win) {
	sfEvent ev;
	sfWindow_setActive(win, true);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	while(sfWindow_isOpen(win) 
			&& sfWindow_pollEvent(win,ev)){
		if(!digestEvent(win, ev))
			return false;
		draw(win, 0);
	}
	return true; 
}

void View::draw(sfWindow *const win, int ticks) {
	sfWindow_setActive(win, true);
	
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
	sfWindow_display(win);
	//win -> display();
}
