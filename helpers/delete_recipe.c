#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../globals/recipe.h"

struct recipe *get_recipe_by_id(int id);
void delete_recipe_by_id(int id);
void mv(char *p_from, char *p_to);

FILE *p_file;
FILE *p_tmp_file;

struct recipe *p_current_recipe;

void delete_recipe(int id, char *p_filename) {
    char *p_tmp_filename = malloc((strlen(p_filename) + strlen(".tmp")) * sizeof(char));
    strcpy(p_tmp_filename, p_filename);
    strcpy(p_tmp_filename, ".tmp");

    p_file = fopen(p_filename, "r+");
    if (p_file == NULL)
        return;

    p_tmp_file = fopen(p_tmp_filename, "w+");
    if (p_tmp_file == NULL)
        return;

    p_current_recipe = get_recipe_by_id(id);

    if (p_current_recipe != NULL)
        delete_recipe_by_id(id);

    fclose(p_file);
    fclose(p_tmp_file);

    mv(p_filename, p_tmp_filename);
}

void mv(char *p_from, char *p_to) {
    remove(p_from);
    rename(p_to, p_from);
}

void delete_recipe_by_id(int id) {
    char word_buffer[1024];

    bool is_reading_current_recipe = false;
    int current_recipe_index = 0;

    while (!feof(p_file)) {
        strcpy(word_buffer, "");

        fgets(word_buffer, 1024, p_file);

        if (strstr(word_buffer, "<recipe>") != NULL && current_recipe_index == p_current_recipe->id)
            is_reading_current_recipe = true;

        if (is_reading_current_recipe == false)
            fputs(word_buffer, p_tmp_file);
        else
            fputs("", p_tmp_file);

        if (strstr(word_buffer, "</recipe>") != NULL) {
            if (current_recipe_index == p_current_recipe->id)
                is_reading_current_recipe = false;

            current_recipe_index++;
        }
    }
}

struct recipe *get_recipe_by_id(int id) {
    struct recipe *p_head = g_recipe;
    p_current_recipe = malloc(sizeof(struct recipe));
    if (p_current_recipe == NULL)
        return NULL;

    while (p_head != NULL) {
        if (p_head->id == id) {
            p_current_recipe = p_head;
            break;
        }
        p_head = p_head->p_next;
    }

    return p_current_recipe;
}
