#include <string.h>
#include <stdlib.h>
#include "../structs/recipe.h"
#include "../structs/ingredient.h"
#include "../globals/recipe_states.h"

void read_recipe_ingredient(struct recipe **p_current_recipe, char word[50]) {
    if ((*(p_current_recipe)) == NULL)
        return;

    if (strcmp(word, "<ingredient>") == 0) {
        (*(p_current_recipe))->p_ingredient = realloc((*(p_current_recipe))->p_ingredient, sizeof(struct ingredient) * ((*(p_current_recipe))->ingredients_count + 1));

        struct ingredient *p_ingredient = &(*(p_current_recipe))->p_ingredient[(*(p_current_recipe))->ingredients_count];

        p_ingredient->p_name = calloc(1, sizeof(char));
        p_ingredient->p_amount = calloc(1, sizeof(char));
        p_ingredient->id = (*(p_current_recipe))->ingredients_count;

        g_recipe_single_ingredient = true;
    }

    if (strcmp(word, "</ingredient>") == 0) {
        g_recipe_single_ingredient = false;

        (*p_current_recipe)->ingredients_count++;
    }

    if (g_recipe_single_ingredient == true && strcmp(word, "<ingredient>") != 0) {
        if (strcmp(word, "<ingredient_amount>") == 0)
            g_recipe_single_ingredient_amount = true;

        if (strcmp(word, "</ingredient_amount>") == 0)
            g_recipe_single_ingredient_amount = false;

        if (g_recipe_single_ingredient_amount == true && strcmp(word, "<ingredient_amount>") != 0) {
            struct ingredient *p_ingredient = &(*(p_current_recipe))->p_ingredient[(*(p_current_recipe))->ingredients_count];

            if (p_ingredient->p_amount != NULL) {
                strcat(p_ingredient->p_amount, " ");
                strcat(p_ingredient->p_amount, word);
            }
        }

        if (strcmp(word, "<ingredient_name>") == 0)
            g_recipe_single_ingredient_name = true;

        if (strcmp(word, "</ingredient_name>") == 0)
            g_recipe_single_ingredient_name = false;

        if (g_recipe_single_ingredient_name == true && strcmp(word, "<ingredient_name>") != 0) {
            struct ingredient *p_ingredient = &(*(p_current_recipe))->p_ingredient[(*(p_current_recipe))->ingredients_count];

            if (p_ingredient->p_name != NULL) {
                strcat(p_ingredient->p_name, " ");
                strcat(p_ingredient->p_name, word);
            }
        }
    }
}
