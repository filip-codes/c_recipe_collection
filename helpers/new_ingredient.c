#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structs/ingredient.h"

struct ingredient *new_ingredient() {
    struct ingredient *p_ingredient = malloc(sizeof(struct ingredient));
    if (p_ingredient == NULL)
        exit(0);
    
    p_ingredient->p_name = malloc(sizeof(char));
    if (p_ingredient->p_name == NULL)
        exit(0);

    strcpy(p_ingredient->p_name, "");

    p_ingredient->p_amount = malloc(sizeof(char));
    if (p_ingredient->p_amount == NULL)
        exit(0);

    strcpy(p_ingredient->p_amount, "");

    return p_ingredient;
}
