/**
* \file all.h
* \brief All helper functions used in this program.
*
*/

#ifndef HELPERS_ALL_H
#define HELPERS_ALL_H
#include <stdio.h>
#include "../structs/ingredient.h"
#include "../structs/recipe.h"

/**
* \fn void reset_box()
* \brief Reset ncurses box.
*
* \return void
*/
void reset_box(void);

/**
* \fn void quit()
* \brief Quit program.
*
* \return void
*/
void quit(void);

/**
* \fn void load_recipes()
* \brief Load all recipes from file.
*
* \return void
*/
void load_recipes(char *filename);

/**
* \fn void mk_file()
* \brief Makes a new file.
*
* \param filename
*/
void mk_file(char *filename);

/**
* \fn void show_recipe()
* \brief Load all recipes from file.
*
* \var p_recipe_name
* \var id
*
* \return void
*/
void show_recipe(char *p_recipe_name, int id);

/**
* @fn void clear_recipes()
* @brief Frees the recipe linked list.
*
* @return void
*/
void clear_recipes(void);

/**
* \fn void get_terminal_size()
* \brief Initializes global struct terminal with height and width.
*
* \return void
*/
void get_terminal_size(void);

/**
* \fn int get_recipes_count()
* \brief Gets the count of all recipes contained in file.
*
* \param p_file
*
* \return int
*/
int get_recipes_count(FILE *p_file);

/**
* \fn void init_recipe()
* \brief Initializes a recipe struct, when a start block was found in file.\n
* It also allocates memory for it's members.
*
* \param p_current_recipe
* \param word
* \param recipe_count
*
* \return void
*/
void init_recipe(struct recipe **p_current_recipe, char word[50], int recipe_count);

/**
* \fn void read_recipe_name()
* \brief Reads a <name> & </name> block and fills it into the recipe struct.
*
* \param p_current_recipe
* \param word
*
* \return void
*/
void read_recipe_name(struct recipe **p_current_recipe, char word[50]);

/**
* \fn void read_recipe_ingredient()
* \brief Reads an <ingredients> & </ingredients> block and fills it into the recipe struct.
*
* \param p_current_recipe
* \param word
*
* \return void
*/
void read_recipe_ingredient(struct recipe **p_current_recipe, char word[50]);

/**
* \fn void read_recipe_instruction()
* \brief Reads an <instruction> & </instruction> block and fills it into the recipe struct.
*
* \param p_current_recipe
* \param word
*
* \return void
*/
void read_recipe_instruction(struct recipe **p_current_recipe, char word[50]);

/**
* \fn int finish_recipe()
* \brief Reads a </recipe> block and finishes the recipe. It links a new struct to our linked list.
*
* \param p_current_recipe
* \param word
* \param recipe_count
* \param recipe_amount
*
* \return int
*/
int finish_recipe(struct recipe **p_current_recipe, char word[50], int recipe_count, int recipe_amount);

/**
* \fn void delete_recipe()
* \brief Deletes a recipe from file.
*
* \param id
* \param p_filename
*
* \return void
*/
void delete_recipe(int id, char *p_filename);

/**
* \fn void add_recipe_to_file()
* \brief Reads an <instruction> & </instruction> block and fills it into the recipe struct.
*
* \param p_filename
*
* \return void
*/
void store_recipe(char *p_filename);

/**
* \fn void new_ingredient()
* \brief Initializes new ingredient struct.
*
* \return struct ingredient
*/
struct ingredient *new_ingredient(void);

/**
* \fn void new_recipe()
* \brief Initializes new recipe struct.
*
* \return struct recipe
*/
struct recipe *new_recipe(void);

/**
* \fn void edit_recipe()
* \brief Edit a single recipe.
*
* \param p_filename
* \param recipe_id
*
* \return void
*/
void edit_recipe(char *p_filename, int recipe_id);

#endif //HELPERS_ALL_H
