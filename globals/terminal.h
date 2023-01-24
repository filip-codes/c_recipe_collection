/**
 * \file terminal.h
 * \brief
 */

#ifndef GLOBALS_TERMINAL_H
#define GLOBALS_TERMINAL_H
#include <ncurses.h>
#include "../structs/terminal.h"

/**
* \var g_terminal
* \brief Holds the global terminal height and width.
*
*/
extern struct terminal *g_terminal;
#endif //GLOBALS_TERMINAL_H
