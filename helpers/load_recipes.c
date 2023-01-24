#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../globals/recipe.h"
#include "../globals/recipe_names.h"
#include "../globals/recipes_count.h"
#include "all.h"

void read_recipes(FILE *p_file);
void set_recipe_names();

void load_recipes(char *filename) {
    // Check if file exists
    if (access(filename, F_OK) != 0)
        mk_file(filename);

    // Open file in read mode
    FILE *p_file = fopen(filename, "r");
    if (p_file == NULL) {
        puts("File could not be opened");
        exit(0);
    }

    // Read all recipes from file
    read_recipes(p_file);

    // Set all recipe names to be globally available
    set_recipe_names();
}

void read_recipes(FILE *p_file) {
    char word_buffer[100];
    int count = 0;

    int number_of_recipes = get_recipes_count(p_file);
    recipes_count = number_of_recipes;

    // Set cursor position at the beginning of p_file
    rewind(p_file);

    struct recipe *current_recipe = NULL;
    while (fscanf(p_file, "%s", word_buffer) != EOF) {
        init_recipe(&current_recipe, word_buffer, count);
        read_recipe_name(&current_recipe, word_buffer);
        read_recipe_ingredient(&current_recipe, word_buffer);
        read_recipe_instruction(&current_recipe, word_buffer);
        count = finish_recipe(&current_recipe, word_buffer, count, number_of_recipes);
    }
}

void set_recipe_names() {
    struct recipe *head = g_recipe;
    int recipe_counter = 0;
    if (head != NULL && head->p_name != NULL) {
        g_recipe_names = malloc(strlen(head->p_name) * sizeof(char *));

        while(head != NULL) {
            g_recipe_names[recipe_counter] = malloc((strlen(head->p_name) + 1) * sizeof(char));
            strcpy(g_recipe_names[recipe_counter], head->p_name);
            head = head->p_next;

            recipe_counter++;
        }
    }
}
