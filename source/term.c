#include "../include/util.h"
#include "../include/term.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Format *const Format_init(
		Format *const fmt,
		int lenOuter, 
		const char *lBorder, 
		const char *rBorder) {

	int llen = strlen(lBorder),
		rlen = strlen(rBorder);
	
	fmt ->target = stdout;
	fmt ->lenOuter = lenOuter;
	fmt ->left = lBorder;
	fmt ->right = rBorder;
	fmt ->lenLeft = llen;
	fmt ->lenRight = rlen;
	fmt ->lenInner = lenOuter 
		- llen - rlen - 1;

	return fmt;
}

int Term_push(
		const Format *const fmt,
		cstr szMessage) {

	int lenMsg = strlen(szMessage),
		written = 0;
	bool finish = false;
	
	const char *const breaks = "\r\n";
	char line[fmt->lenOuter],
		 copy[lenMsg];
	strcpy(copy, szMessage);
	
	char *token = strtok(copy, " ");
	while(token != NULL) {
		finish = true;
		if(strlen(line) + strlen(token)
				>= fmt->lenInner) {
			strcat(line, token);
			written += Term_pushBordered(fmt, line);
			line[0] = '\0';
		}
		strcat(line, token);
		strcat(line, " ");

		token = strtok(NULL, " ");
	}
	if(finish)
		written += Term_pushBordered(fmt, line);
	
	fflush(fmt->target);
	return written;
}

str Term_border(
		const Format *const fmt,
		str szDest,
		cstr szMessage) {

	snprintf(szDest, 
			fmt->lenOuter, "%s%.*s%s", 
			fmt->left, fmt->lenInner, 
			szMessage, fmt->right);
	return szDest;
}

str Term_align(
		const Format *const fmt, str szDest,
		cstr szMessage, bool left) {
	cstr szFormat = left ? "%-*s" : "%*s";
	snprintf(szDest, fmt->lenInner,
			szFormat, fmt->lenInner, szMessage);
	return szDest;
}

int Term_pushBordered(
		const Format *const fmt,
		cstr szMessage) {
	char szBuffer[fmt->lenOuter];
	
	int output = fprintf(
			fmt->target, "%s%-*s%s", 
			fmt->left, fmt->lenInner,
			szMessage, fmt->right);
	fflush(fmt->target);
	return output;
}

int Term_fpush(const Format *const fmt,
		cstr szFormat, ...) {
	va_list args;
	va_start(args, szFormat);
	int total = vfprintf(fmt->target, 
			szFormat, args);
	va_end(args);

	fflush(fmt->target);
	return total;
}
