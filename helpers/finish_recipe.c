#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../globals/recipe.h"

int finish_recipe(struct recipe **p_current_recipe, char word[50], int recipe_count, int recipe_amount) {
    if (strcmp(word, "</recipe>") == 0) {
        recipe_count++;
        struct recipe *p_next_recipe = malloc(sizeof(struct recipe));
        if (p_next_recipe == NULL)
            printf("finish_recipe: Could not allocate memory for 'p_next_recipe'\n");

        p_next_recipe->p_next = NULL;

        if (recipe_amount == recipe_count)
            (*(p_current_recipe))->p_next = NULL;
        else
            (*(p_current_recipe))->p_next = p_next_recipe;

        (*(p_current_recipe)) = p_next_recipe;
    }
    return recipe_count;
}
