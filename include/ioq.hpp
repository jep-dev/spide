#if !defined(IOQ_HPP)
#define IOQ_HPP

#include "../include/utilities.hpp"
#include <vector>
#include <iostream>

struct ioq {
	
	std::vector<const char*> inbox, outbox;

	//void push(const char* msg); 
	//const char* pull(void);
	//const char* poll(void); 
	int size(void); 
	
	friend std::ostream& operator<< 
		(std::ostream& os, const ioq& io); 

	ioq(void); 
	~ioq(void);
};

std::ostream& operator<< 
	(std::ostream& rhs, const ioq& io); 

#endif
