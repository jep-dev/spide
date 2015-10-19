#if !defined(STREAMS_H)
#define STREAMS_H

#include "../include/util.h"
#include <stdbool.h>

typedef struct Format {
	FILE *target;
	const char *left, *right;
	int lenOuter, lenLeft, lenRight, lenInner;
} Format;

/**\brief Write to the members in the format struct.
 * \param lenOuter The length of an entire line.
 * \param lBorder The left border string.
 * \param rBorder The right border string.
 * \return The same format struct pointer. */
Format *const Format_init(
		Format *const fmtDest, 
		int lenOuter, 
		const char *const lBorder,
		const char *const rBorder);

/**\brief Push a fixed-width message to stdout.
 * \param fmt The format struct to use.
 * \param szMessage A single line to print.
 * \return The number of characters printed. */
int Term_push(const Format *const fmt,
		cstr szMessage);

/**\brief Adds a border to the given message.
 * \param fmt The format struct to use.
 * \param szDest Destination of the output.
 * \param szMessage Message to be bordered.
 * \return The pointer to the destination string. */
str Term_border(const Format *const fmt,
		str szDest, cstr szMessage);

/**\brief Pads the given message (left/right).
 * \param fmt The format struct to use.
 * \param szDest The string to receive the result.
 * \param szMessage The message to align.
 * \param left True to align left, false otherwise.
 * \return The pointer to the destination string. */
str Term_align(const Format *const fmt,
		str szDest, cstr szMessage, bool left);

/**\brief Pads, borders, and prints the given message.
 * \param fmt The format struct to use.
 * \param szMessage The message to print. 
 * \return The number of characters printed. */
int Term_pushBordered(const Format *const fmt,
		cstr szMessage);

/**\brief Format, pad, border, and print the args.
 * \param fmt The format struct to use.
 * \param szFormat The formatting to unpack the 
 * 		following args.
 * \return The number of characters printed. */
int Term_fpush(const Format *const fmt,
		cstr szFormat, ...);

#endif
