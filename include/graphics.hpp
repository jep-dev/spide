#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
// #include "SFML/Window.hpp" // Event, KeyEvent types

struct Display {
	static const int
		MIN_WIDTH = 480,
		MIN_HEIGHT = 480,
		DEFAULT_WIDTH = 640,
		DEFAULT_HEIGHT = 480,
		DEFAULT_DEPTH = 24,
		DEFAULT_STENCIL = 8,
		DEFAULT_ANTIALIASING = 2,
		DEFAULT_MAJOR = 3,
		DEFAULT_MINOR = 0;
	int width, height;
	sf::VideoMode mode;
	sf::ContextSettings con; 
	sf::RenderWindow win;
	
	/** \brief Initializes a window.
	 * \param width The intended width of the frame.
	 * \param height The intended height of the frame.
	 * \param title The text for the title bar. */
	Display(int width, int height, const char *title); 

	/** \brief Initializes a default window. */
	Display(void);

	/** \brief Destructor (releases resources). */
	~Display(void);
	
	/** \brief Handles a single keypress.
	 * \param ev The information associated with the key.
	 * \return True unless the window should/will close. */
	static bool digestKeyPress(sf::Window *const win,
			const sf::Event::KeyEvent &ev);

	/** \brief Consume a single mouse button event.
	 * \param The information associated with the press.
	 * \return true, unless the window should/will close. */
	static bool digestMousePress(sf::Window *const win,
			int width, int height, sf::Mouse::Button button);  

	/** \brief Consume a single window event.
	 * \param ev An event to handle.
	 * \return true, unless the window should/will close. */
	static bool digestEvent(sf::Window *const win, 
			const sf::Event &ev);

	/**\brief Consume all events in the queue.
	 * \return true, unless the window is closing. */
	static bool digestEvents(sf::Window *const win);

	/** \brief Draw one frame to the screen.
	 * \param delta Time since the last frame in ms. */
	static void draw(sf::Window *const win, 
			int milliDelta); 

}; 

#endif
