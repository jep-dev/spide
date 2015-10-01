#ifndef SCRIPTS_HPP
#define SCRIPTS_HPP

#ifdef __cplusplus
#define CEXT extern "C"
#else
#define CEXT
#endif

CEXT { 
	#include "string.h"
	#include "stdio.h"

	using cbyte = const unsigned char; // [-128, 127]
	using cstr = const char *;
	using flags = unsigned int; 
	flags OK = 0, FATAL = 1, WARNING = 2, TODO = 4; 

	struct Externalizer {
		static bool prevalidate(cstr msg){
			return msg!=NULL && strlen(msg)>0; 
		}
		static flags push(cstr line,
				flags (*onSuccess)(cstr), 
				flags (*onFailure)(cstr)){
			if(prevalidate(line))
				return onSuccess(line);
			return onFailure("<Error>");  // TODO
		}
	};

#include "Python.h"
	struct Python {
		static flags expr(const char *line){
			return TODO; // TODO 
		}
		static bool validate(const char *line){
			if(line == NULL || strlen(line) == 0){
				return false;
			}
			return true;
		}
		static flags run(const char **filenames){
			return OK; // TODO 
		}
	}; 
}; 

#endif
