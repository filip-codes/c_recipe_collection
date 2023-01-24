#include <ncurses.h>
#include <stdlib.h>
#include "../globals/window.h"
#include "../globals/terminal.h"
#include "../globals/recipe_names.h"
#include "all.h"

void quit() {
    endwin();
    clear_recipes();

    if (g_recipe_names != NULL)
        free(g_recipe_names);

    if (g_terminal != NULL)
        free(g_terminal);

    g_window = NULL;
}
