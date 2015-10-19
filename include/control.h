#ifndef CONTROL_H
#define CONTROL_H

#include "../include/util.h"
#include "../include/term.h"

#include <SFML/Window.h>

extern typedef union {
	sfEvent evt;
	long int time;
} Trigger;

extern typedef union {
	evt match;
	int (*callback)(Trigger trigger);
} Reaction;

typedef const sfEvent *const cevt;
typedef const Trigger *const ctrig;
typedef const Reaction *const creact;

/**\brief Compares the given events.
 * \param lhs The subject in the comparison.
 * \param rhs The object in the comparison.
 * \return -1 for lhs<rhs, 0 for lhs==rhs, 
 * 		1 for lhs>rhs. */
extern int Ctrl_compare(cevt lhs, cevt rhs);

/**\brief Sorts and handles generic events.
 * \param trigger The original event (read-only). */
void Ctrl_react(ctrig trigger);

/**\brief Replaces future matching events.
 * \param evtMatch Template for a matching event.
 * \param evtRepl The event to use instead. */
void Ctrl_registerEventMap(cevt evtMatch, 
		cevt evtRepl);

/**\brief Replaces or preserves the input event.
 * \param evt The input event.
 * \return The replacement or the original. */
cevt Ctrl_mapEvent(cevt event);

/**\brief Maps any matching event to the given response.
 * \param evtMatch The template for a matching event.
 * \param reaction The callback to use when */
void Ctrl_registerReactionMap(cevt evtMatch, 
		creact reaction);



#endif
