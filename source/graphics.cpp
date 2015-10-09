#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif
// LOG*
#include "../include/utilities.hpp"

#include "../include/graphics.hpp"

#include <SFML/OpenGL.hpp>

Display::Display(int width, int height, const char *title):
	width(width >= MIN_WIDTH ? width : MIN_WIDTH),
	height(height >= MIN_HEIGHT ? height : MIN_HEIGHT),
	mode(width, height), 
	con(DEFAULT_DEPTH, DEFAULT_STENCIL, DEFAULT_ANTIALIASING, 
			DEFAULT_MAJOR, DEFAULT_MINOR),
	win(mode, title, sf::Style::Default, con) {
	LOG_ME();
	win.setVerticalSyncEnabled(true);
	win.setFramerateLimit(58);
	//win.setFramerateLimit(16);
	
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

}

Display::~Display(void) {
	LOG_ME();
}

bool Display::digestKeyPress(sf::Window *const win,
		const sf::Event::KeyEvent &ev) {
	switch(ev.code){
		case sf::Keyboard::Escape:
			return false;
		case sf::Keyboard::F4:
			// TODO	
		default:
			return true; 
	}
}

bool Display::digestMousePress(sf::Window *const win, 
		int x, int y, sf::Mouse::Button button) {
	switch(button){
		case sf::Mouse::Left:
			LOG_PRESS("Left press", x, y);
			break;
		case sf::Mouse::Middle:
			LOG_PRESS("Middle press", x, y);
			break; 
			case sf::Mouse::Right:
			LOG_PRESS("Right press", x, y);
			break;
		default:
			LOG_PRESS("Other press", x, y);
			break; 
	}
	return true; 
}

bool Display::digestEvent(sf::Window *const win, 
		const sf::Event &ev){
	switch(ev.type){
		case sf::Event::Closed:
			return false;
			break;
		case sf::Event::Resized: 
			glViewport(0, 0, ev.size.width, 
					ev.size.height);
			break; 
		case sf::Event::MouseButtonPressed: {
			const sf::Event::MouseButtonEvent mbev 
				= ev.mouseButton;
			return digestMousePress(win, 
					mbev.x, mbev.y, mbev.button);
			}
		case sf::Event::KeyPressed:
			return digestKeyPress(win, ev.key);
			break;
		default:
			break; 
	}
	return true; 
}

bool Display::digestEvents(sf::Window *const win) {
	sf::Event ev;
	//sf::Window win = display.win;
	win -> setActive(true);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	while(win -> isOpen() && win -> pollEvent(ev)) {
		if(!digestEvent(win, ev))
			return false;
		draw(win, 0);
	}
	return true; 
}

void Display::draw(sf::Window *const win, int ticks) {
	//sf::Window win = display.win;
	win -> setActive(true);
	
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
	win -> display();
}
