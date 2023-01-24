#include <string.h>
#include <stdlib.h>
#include "../globals/recipe.h"
#include "../structs/ingredient.h"

void init_recipe(struct recipe **p_current_recipe, char word[50], int recipe_count) {
    if (strcmp(word, "<recipe>") == 0) {
        if (g_recipe == NULL) {
            g_recipe = malloc(sizeof(struct recipe));
            if (g_recipe == NULL)
                return;

            g_recipe->p_next = NULL;

            (*(p_current_recipe)) = g_recipe;
        }
        (*(p_current_recipe))->p_name = malloc(strlen(word) * sizeof(char));
        if ((*(p_current_recipe))->p_name == NULL)
            return;

        (*(p_current_recipe))->p_instruction = malloc(strlen(word) * sizeof(char));
        if ((*(p_current_recipe))->p_instruction == NULL)
            return;

        (*(p_current_recipe))->p_ingredient = malloc(sizeof(struct ingredient));
        if ((*(p_current_recipe))->p_ingredient == NULL)
            return;

        (*(p_current_recipe))->id = recipe_count;
        (*(p_current_recipe))->ingredients_count = 0;
    }
}
