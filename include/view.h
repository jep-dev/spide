#ifndef VIEW_H
#define VIEW_H

// Event, KeyEvent, Mouse::Button, Window
#include <SFML/Graphics.h>

CEXT struct View {
	static const int 
		MIN_WIDTH = 480,
 		MIN_HEIGHT = 480,
		DEFAULT_DEPTH = 24, 
		DEFAULT_STENCIL = 8, 
		DEFAULT_ANTIALIASING = 2,
		DEFAULT_MAJOR = 3,
		DEFAULT_MINOR = 0;
	
	/** \brief Handles a single keypress.
	 * \param ev The information associated with the key.
	 * \return True unless the window should/will close. */
	static bool digestKeyPress(sfWindow *const win,
			const sfKeyEvent &ev);

	static sfRenderWindow *const init(void);

	/** \brief Consume a single mouse button event.
	 * \param The information associated with the press.
	 * \return true, unless the window should/will close. */
	static bool digestMousePress(sfWindow *const win,
			int width, int height, sfMouseButton button);  

	/** \brief Consume a single window event.
	 * \param ev An event to handle.
	 * \return true, unless the window should/will close. */
	static bool digestEvent(sfWindow *const win, 
			const sfEvent &ev);

	/**\brief Consume all events in the queue.
	 * \return true, unless the window is closing. */
	static bool digestEvents(sfWindow *const win);

	/** \brief Draw one frame to the screen.
	 * \param delta Time since the last frame in ms. */
	static void draw(sfWindow *const win, 
			int milliDelta); 
};
#endif
