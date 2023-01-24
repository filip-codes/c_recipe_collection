#include <string.h>
#include <stdlib.h>
#include "../globals/recipe_states.h"
#include "../structs/recipe.h"

void read_recipe_instruction(struct recipe **p_current_recipe, char word[50]) {
    if (strcmp(word, "<instruction>") == 0)
        g_recipe_instructions = true;

    if (strcmp(word, "</instruction>") == 0)
        g_recipe_instructions = false;

    if (g_recipe_instructions == true && strcmp(word, "<instruction>") != 0) {
        (*(p_current_recipe))->p_instruction = realloc((*(p_current_recipe))->p_instruction, (strlen(word) + sizeof(char) + strlen((*(p_current_recipe))->p_instruction) + sizeof(char)) * sizeof(char));

        if (strcmp((*(p_current_recipe))->p_instruction, "") != 0)
            strcat((*(p_current_recipe))->p_instruction, " ");

        strcat((*(p_current_recipe))->p_instruction, word);
    }
}
