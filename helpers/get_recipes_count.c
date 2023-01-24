#include <stdio.h>
#include <string.h>

int get_recipes_count(FILE *p_file) {
    char word_buffer[100];
    int recipe_count = 0;
    while (fscanf(p_file, "%s", word_buffer) != EOF)
        if (strcmp(word_buffer, "</recipe>") == 0)
            recipe_count++;

    return recipe_count;
}
