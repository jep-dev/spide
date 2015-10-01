#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include "../include/graphics.hpp"
#include "../include/utilities.hpp" // LOG, LOG_ME

Display::Display(int width, int height, const char *title):
	width(width >= MIN_WIDTH ? width : MIN_WIDTH),
	height(height >= MIN_HEIGHT ? height : MIN_HEIGHT),
	mode(width, height), win(mode, title) {
	LOG_ME();

	win.setVerticalSyncEnabled(true); 
	//win.setFramerateLimit(58);
	win.setFramerateLimit(1); 
}

Display::Display(void):	Display(DEFAULT_WIDTH, 
		DEFAULT_HEIGHT, "Untitled") {
	LOG_ME(); 
}

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

//bool Display::digestMousePress(const sf::Event::MouseButtonEvent &ev){
bool Display::digestMousePress(int x, int y, sf::Mouse::Button button) {
	//LOG_ME(); too long.
	const char *fmt = "# %52s @(%04d, %04d) #\n";

	switch(button){
		case sf::Mouse::Left:
			LOG(fmt, "Left press", x, y);
			break;
		case sf::Mouse::Middle:
			LOG(fmt, "Middle press", x, y);
			break; 
		case sf::Mouse::Right:
			LOG(fmt, "Right press", x, y);
			break; 
		default:
			LOG(fmt, "Other press", x, y);
			break; 
	}
	return true; 
}

bool Display::digestEvent(const sf::Event &ev){
	//LOG_ME(); 
	switch(ev.type){
		case sf::Event::Closed:
			return false;
		case sf::Event::MouseButtonPressed:
			return digestMousePress(ev.mouseButton.x, 
					ev.mouseButton.y, ev.mouseButton.button); 
		case sf::Event::KeyPressed:
			return digestKeyPress(ev.key);
		default:
			return true; 
	}
}

bool Display::digestEvents(void) {
	// LOG_ME(); 
	sf::Event ev;
	win.setActive(); 
	while(win.isOpen() && win.pollEvent(ev)) {
		if(!digestEvent(ev)){
			sf::Time t; 
			LOG_TIME("Exiting with status ", 
					t.asMilliseconds()); 
			return false; 
		}
	}
	return true; 
}

void Display::draw(int ticks) {
	win.clear(sf::Color::Black);
	win.display(); 
}
