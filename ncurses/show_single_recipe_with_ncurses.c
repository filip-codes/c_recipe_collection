#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../structs/recipe.h"
#include "../structs/ingredient.h"
#include "../globals/window.h"
#include "../globals/recipe.h"
#include "../helpers/all.h"

void show_single_recipe_with_ncurses(char *p_recipe_name, int id) {
    reset_box();
    //scrollok(g_window, TRUE);

    mvwprintw(g_window, 0, 3, "%s", p_recipe_name);
    wrefresh(g_window);

    struct recipe *head = g_recipe;
    struct recipe *current_recipe = malloc(sizeof(struct recipe));
    if (current_recipe == NULL) {
        return;
    }
    while (head != NULL) {
        if (head->id == id) {
            current_recipe = head;
            break;
        }

        head = head->p_next;
    }

    mvwprintw(g_window, 1, 1, "Ingredients:");
    int ingredient_lines = 0;
    for(int i = 0; i < current_recipe->ingredients_count; i++) {
        struct ingredient *p_ingredient = &current_recipe->p_ingredient[i];
        if (p_ingredient == NULL)
            continue;

        char *p_ingredient_name = malloc(strlen(p_ingredient->p_amount) + sizeof(char) + strlen(p_ingredient->p_name) + sizeof(char));
        if (p_ingredient_name == NULL)
            continue;

        strcat(p_ingredient_name, p_ingredient->p_amount);
        strcat(p_ingredient_name, " ");
        strcat(p_ingredient_name, p_ingredient->p_name);

        mvwprintw(g_window, ingredient_lines + 2, 1, "%s", p_ingredient_name);

        ingredient_lines++;
    }

    mvwprintw(g_window, ingredient_lines + 3, 1, "Instruction:");
    mvwprintw(g_window, ingredient_lines + 4, 1, "%s", current_recipe->p_instruction);

    int ch;
    while((ch = wgetch(g_window)) != 'q');
}
