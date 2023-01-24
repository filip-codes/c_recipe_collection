#include "stdlib.h"
#include "../structs/ingredient.h"
#include "../globals/recipe.h"

void clear_ingredients();
void clear_recipe();

void clear_recipes() {
    while (g_recipe != NULL) {
        struct recipe *p_next_recipe = g_recipe->p_next;

        clear_ingredients();
        clear_recipe();

        g_recipe = p_next_recipe;
    }
}

void clear_recipe() {
    if (g_recipe->p_ingredient != NULL)
        free(g_recipe->p_ingredient);

    if (g_recipe->p_name != NULL)
        free(g_recipe->p_name);

    if (g_recipe->p_instruction != NULL)
        free(g_recipe->p_instruction);

    if (g_recipe != NULL)
        free(g_recipe);
}

void clear_ingredients() {
    for (int i = 0; i < g_recipe->ingredients_count; i++) {
        struct ingredient *p_ingredient = &g_recipe->p_ingredient[i];
        if (p_ingredient->p_name != NULL)
            free(p_ingredient->p_name);

        if (p_ingredient->p_amount != NULL)
            free(p_ingredient->p_amount);
    }
}
