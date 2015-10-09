#if !defined(IOQ_H)
#define IOQ_H

#include "../include/util.h"
#include <vector>
#include <iostream>

CEXT struct ioq {
	
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

CEXT std::ostream& operator<< 
	(std::ostream& rhs, const ioq& io); 

#endif
