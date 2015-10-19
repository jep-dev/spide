#include "../include/util.h"
#include "../include/term.h"
#include "../include/control.h"

#include <SFML/Window.h>

extern int Ctrl_compare(cevt lhs, cevt rhs) {
	/*void *lhsPtr = (void*)(lhs ->type),
		 *rhsPtr = (void*)(rhs ->type);
	for(int i = 0, max = sizeof(cevt);
			i < max; ++i, ++lhsPtr, ++rhsPtr){
		if(*lhsPtr < *rhsPtr){
			return -1;
		} else if(*lhsPtr > *rhsPtr){
			return 1;
		}
	}*/
	return 0;
}

void Ctrl_react(ctrig trigger){
	/* TODO */
}

void Ctrl_registerEventMap(
	cevt evtMatch, cevt evtRepl) {
	/* TODO */
}

cevt Ctrl_mapEvent(cevt event) {
	return event;
}

void Ctrl_registerReactionMap(
		cevt evtMatch, creact reaction) {
	
}
