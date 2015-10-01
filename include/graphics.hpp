#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
// #include "SFML/Window.hpp" // Event, KeyEvent types

struct Display {
private:
	static const int
		MIN_WIDTH = 320, 
		MIN_HEIGHT = 320, 
		DEFAULT_WIDTH = 640, 
		DEFAULT_HEIGHT = 480;
public:
	int width, height;
	sf::VideoMode mode;
	sf::RenderWindow win;
	
	/** \brief Initializes a window.
	 * \param width The intended width of the frame.
	 * \param height The intended height of the frame.
	 * \param title The text for the title bar. */
	Display(int width, int height, const char *title);

	/** \brief Initializes a default window. */
	Display(void);

	/** \brief Releases resources. */
	~Display(void);
	
	/** \brief Handles a single keypress.
	 * \param ev The information associated with the key.
	 * \return True unless the window should/will close. */
	bool digestKeyPress(const sf::Event::KeyEvent &ev);

	/**\brief Consume a single mouse button event.
	 * \param The information associated with the press.
	 * \return true, unless the window should/will close. */
	bool digestMousePress(int width, int height, 
			sf::Mouse::Button button);  

	/**\brief Consume a single window event.
	 * \param ev An event to handle.
	 * \return true, unless the window should/will close. */
	bool digestEvent(const sf::Event &ev);

	/**\brief Consume all events in the queue.
	 * \return true, unless the window is closing. */
	bool digestEvents(void);

	void draw(int delta); 

}; 

#endif
