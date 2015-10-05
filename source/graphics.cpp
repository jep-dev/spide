#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include <SFML/OpenGL.hpp>
#include "../include/graphics.hpp"
#include "../include/utilities.hpp" // LOG, LOG_ME

Display::Display(int width, int height, const char *title):
	width(width >= MIN_WIDTH ? width : MIN_WIDTH),
	height(height >= MIN_HEIGHT ? height : MIN_HEIGHT),
	mode(width, height), con(DEFAULT_DEPTH, 
			DEFAULT_STENCIL, DEFAULT_ANTIALIASING, 
			DEFAULT_MAJOR, DEFAULT_MINOR),
	win(mode, title, sf::Style::Default, con) {
	LOG_ME();
	
	win.setVerticalSyncEnabled(true); 
	//win.setFramerateLimit(58);
	win.setFramerateLimit(32); 
}

Display::Display(void):	Display(DEFAULT_WIDTH, 
		DEFAULT_HEIGHT, "Untitled") {}

Display::~Display(void) {
	LOG_ME();
	// Dispose of resources
}

bool Display::digestKeyPress(const sf::Event::KeyEvent &ev) {
	//LOG_ME(); 
	switch(ev.code){
		case sf::Keyboard::Escape:
			return false;
		case sf::Keyboard::F4:
			// fullscreen
			
		default:
			return true; 
	}
}

bool Display::digestMousePress(int x, int y, 
		sf::Mouse::Button button) {
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

bool Display::digestEvent(const sf::Event &ev){
	//LOG_ME(); 
	switch(ev.type){
		case sf::Event::Closed:
			return false;
		case sf::Event::Resized: 
			glViewport(0, 0,
					ev.size.width, 
					ev.size.height); 
			break; 
		case sf::Event::MouseButtonPressed:
			return digestMousePress(ev.mouseButton.x, 
					ev.mouseButton.y, ev.mouseButton.button); 
		case sf::Event::KeyPressed:
			return digestKeyPress(ev.key);
		default:
			break; 
	}
	return true; 
}

bool Display::digestEvents(void) {
	// LOG_ME(); 
	sf::Event ev; 	
	win.setActive(); 
	while(win.isOpen() && win.pollEvent(ev)) {
		if(!digestEvent(ev)) 
			return false;
		draw(0);
	}
	return true; 
}

void Display::draw(int ticks){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT); 
	win.display(); 
}
