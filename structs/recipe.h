/**
* \file recipe.h
* \brief
*
*/

#ifndef STRUCTS_RECIPE_H
#define STRUCTS_RECIPE_H
/**
* \struct recipe
* \brief This struct holds the declaration of a recipe. It possibly has a list of ingredients, if specified.
*
*/
struct recipe {
    int id;
    int ingredients_count;
    char *p_name;
    char *p_instruction;
    struct recipe *p_next;
    struct ingredient *p_ingredient;
};
#endif //STRUCTS_RECIPE_H
