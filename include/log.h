#if !defined(LOG_H)
#define LOG_H

#ifndef ENABLE_LOGGING
#define ENABLE_LOGGING 1
#endif

#include "../include/util.h"

/**\brief Format/print the given message(s)
 * \return The number of characters written. */
int LOG(cstr szLine);

/**\brief Print the given paragraph.
 * \param szPara The message not within the
 * 		console margins.
 * \return The number of characters written. */
int LOG_PARA(cstr szPara);

/**\brief Log the current function by name.
 * \param szFile filename \
 * 		(as expanded from call site).
 * \param szFunc Function name \
 * 		(as expanded from call site).
 * \param line Line number
 * 		(as expanded/calculated from call site).
 * \return The number of characters written. */
int LOG_FUNC(cstr szFile, cstr szFunc, int line);

/**\brief Log the compiler, system info, etc.
 * \return The number of characters written. */
int LOG_SYSTEM(void);

/**\brief Log a mouse press (label/coord pair).
 * \brief label The label (Left, Right, etc.)
 * \brief x The x coordinate in [0,width-1]
 * \brief y The y coordinate in [0,height-1]
 * \return The number of characters written. */
int LOG_PRESS(cstr label, int x, int y);

#endif
