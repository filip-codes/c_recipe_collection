#include <string.h>
#include <stdlib.h>
#include "../structs/recipe.h"
#include "../globals/recipe_states.h"

void read_recipe_name(struct recipe **p_current_recipe, char word[50]) {
    if (strcmp(word, "<name>") == 0)
        g_recipe_name = true;

    if (strcmp(word, "</name>") == 0)
        g_recipe_name = false;

    if (g_recipe_name == true && strcmp(word, "<name>") != 0) {
        (*(p_current_recipe))->p_name = realloc((*(p_current_recipe))->p_name, strlen(word) + strlen((*(p_current_recipe))->p_name) + sizeof(char));

        if (strcmp((*(p_current_recipe))->p_name, "") != 0)
            strcat((*(p_current_recipe))->p_name, " ");

        strcat((*(p_current_recipe))->p_name, word);
    }
}
