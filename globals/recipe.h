/**
 * \file recipe.h
 *
 */

#ifndef GLOBALS_RECIPE_H
#define GLOBALS_RECIPE_H
#include <ncurses.h>
#include "../structs/recipe.h"
/**
* \var g_recipe
* \brief The g_recipe is a global variable that holds the head of our linked list used in our program.
*
*/
extern struct recipe *g_recipe;

#endif //GLOBALS_RECIPE_H
