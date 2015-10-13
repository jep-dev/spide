#if !defined(LOG_H)
#define LOG_H

#include "../include/util.h"

/**\brief Format/print the given message(s)
 * \param n The number of following arguments. 
 * \param __VA_ARGS A formatting string, 
 * 		then the corresponding arguments.
 * \return 0 for success, non-zero flags otherwise. */
int LOG(cstr fmt, ...);

/**\brief Log the current function by name.
 * \return 0 for success, non-zero flags otherwise. */
int LOG_FUNC(cstr szFile, cstr szFunc, int line);

/**\brief Log the compiler, system info, etc.
 * \return 0 for success, non-zero flags otherwise. */
int LOG_SYSTEM(void);

/**\brief Log a mouse press (label/coord pair).
 * \brief label The label (Left, Right, etc.)
 * \brief x The x coordinate in [0,width-1]
 * \brief y The y coordinate in [0,height-1]
 * \return 0 for success, non-zero flags otherwise. */
int LOG_PRESS(cstr label, int x, int y);

#endif
