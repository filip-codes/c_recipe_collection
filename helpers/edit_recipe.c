#include <ncurses.h>
#include "../globals/window.h"
#include "../globals/terminal.h"
#include "../globals/recipe.h"
#include "all.h"

void edit_recipe(char *p_filename, int recipe_id) {
    reset_box();

    FILE *p_file = fopen(p_filename, "r+");

    struct recipe *p_recipe = NULL;
    while (g_recipe != NULL) {
        if (g_recipe->id == recipe_id) {
            p_recipe = g_recipe;
            break;
        }

        g_recipe = g_recipe->p_next;
    }

    if (p_recipe == NULL)
        return;

    echo();
    mvwprintw(g_window, 1, 1, "Edit the recipe name:");

    mvwaddstr(g_window, 2, 1, p_recipe->p_name);
    mvwgetstr(g_window, 3, 1, p_recipe->p_name);
    noecho();

    reset_box();

    mvwprintw(g_window, 1, 1, "%s", p_recipe->p_name);
    wgetch(g_window);

    fclose(p_file);
}
