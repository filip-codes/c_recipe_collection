#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <getopt.h>

#include "globals/recipe.h"
#include "structs/terminal.h"
#include "ncurses/all.h"
#include "helpers/all.h"

WINDOW *g_window;
char **g_recipe_names;
int recipes_count = 0;
struct recipe *g_recipe = NULL;
struct terminal *g_terminal = NULL;
bool g_recipe_name, g_recipe_instructions, g_recipe_single_ingredient, g_recipe_single_ingredient_amount, g_recipe_single_ingredient_name = false;

char *menu_choices[] = {
        "All recipes",
        "Create recipe",
        "Delete recipe",
        "Search recipes by recipe name",
        "Search recipes by ingredient",
        "Help"
};

int main(int argc, char *argv[]) {
    initscr();
    noecho();
    cbreak();

    get_terminal_size();

    bool has_h_option = false;
    int c;

    while ((c = getopt(argc, argv, "f:h")) != -1)
        switch (c) {
            case 'h':
                has_h_option = true;
                break;
            case 'f':
                argv[1] = optarg;
                break;
        }

    if (has_h_option || argc != 2) {
        show_help_with_ncurses();
        quit();
        exit(0);
    }

    load_recipes(argv[1]);
    show_main_menu_with_ncurses(argv[1]);
    quit();

    return 0;
}
