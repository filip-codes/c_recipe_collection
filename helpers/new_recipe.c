#include <stdio.h>
#include <stdlib.h>
#include "../structs/ingredient.h"
#include "../structs/recipe.h"

struct recipe *new_recipe() {
    struct recipe *p_recipe = malloc(sizeof(struct recipe));
    if(p_recipe == NULL)
        exit(0);

    p_recipe->p_ingredient = malloc(sizeof(struct ingredient));
    if(p_recipe->p_ingredient == NULL)
        exit(0);

    p_recipe->p_name = malloc(sizeof(char));
    if(p_recipe->p_name == NULL)
        exit(0);

    p_recipe->p_instruction = malloc(sizeof(char));
    if(p_recipe->p_instruction == NULL)
        exit(0);

    p_recipe->p_next = NULL;

    return p_recipe;
}
