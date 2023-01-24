/**
* \file all.h
* \brief This functions draw boxes with ncurses in different use cases.
*
*/

#ifndef NCURSES_ALL_H
#define NCURSES_ALL_H
#include <stdio.h>
#include "../structs/ingredient.h"
#include "../structs/recipe.h"

/**
* \fn void show_help_with_ncurses()
* \brief Draw a help box with ncurses.
*
*/
void show_help_with_ncurses();

/**
* \fn void show_main_menu_with_ncurses()
* \brief Draw main menu box with ncurses.
*
* \param p_filename
*/
void show_main_menu_with_ncurses(char *p_filename);

/**
* \fn void show_search_by_ingredient_with_ncurses()
* \brief Draw a search box for ingredients included in recipes with ncurses.
*
*/
int show_search_by_ingredient_with_ncurses();

/**
* \fn void show_search_by_recipe_name_with_ncurses()
* \brief Draw a search box by recipe name with ncurses.
*
*/
int show_search_by_recipe_name_with_ncurses();

/**
* \fn void show_selectable_menu_with_ncurses()
* \brief Draw a selectable menu box with ncurses.
*
* \param name
* \param options
* \param options_count
*/
int show_selectable_menu_with_ncurses(char *name, char *options[], int options_count);

/**
* \fn void show_single_recipe_with_ncurses()
* \brief Draw a single recipe box with ncurses to display a recipe with ingredients.
*
* \param p_recipe_name
* \param id
*/
void show_single_recipe_with_ncurses(char *p_recipe_name, int id);

#endif //NCURSES_ALL_H
