#if !defined(ENABLE_LOGGING)
#define ENABLE_LOGGING true
#endif

#include <vector>
#include <iostream>
#include "../include/utilities.hpp"
#include "../include/ioq.hpp"

ioq::ioq(void) {}

std::ostream& operator<<
		(std::ostream& os, const ioq& io) {
	const char *msg = io.outbox.back(); 
	os << msg << std::endl; 
	return os; 
	//return os << line << std::endl; 
}


int ioq::size(void){
	return outbox.size();
}
