#include <stdlib.h>
#include "../globals/recipe_names.h"
#include "../globals/recipes_count.h"
#include "../globals/menu_choices.h"
#include "../enums/menu.h"
#include "../helpers/all.h"
#include "all.h"

void refresh_recipes(char *p_filename);

void show_main_menu_with_ncurses(char *p_filename) {
    int selected_recipe_id;
    while(1) {
        switch (show_selectable_menu_with_ncurses(p_filename, menu_choices, 6)) {
            case ALL_RECIPES:
                selected_recipe_id = show_selectable_menu_with_ncurses("All recipes", g_recipe_names, recipes_count);
                if (selected_recipe_id < recipes_count)
                    show_single_recipe_with_ncurses(g_recipe_names[selected_recipe_id], selected_recipe_id);

                break;
            case CREATE_RECIPE:
                store_recipe(p_filename);

                // Refresh recipe names after creating one recipe
                refresh_recipes(p_filename);
                break;
            case DELETE_RECIPE:
                selected_recipe_id = show_selectable_menu_with_ncurses("All recipes", g_recipe_names, recipes_count);
                if (selected_recipe_id < recipes_count) {
                    delete_recipe(selected_recipe_id, p_filename);

                    // Refresh recipe names after removing one from file
                    refresh_recipes(p_filename);
                }
                break;
            case SEARCH_BY_RECIPE:
                selected_recipe_id = show_search_by_recipe_name_with_ncurses();
                if (selected_recipe_id != -1)
                    show_single_recipe_with_ncurses(g_recipe_names[selected_recipe_id], selected_recipe_id);

                break;
            case SEARCH_BY_INGREDIENT:
                selected_recipe_id = show_search_by_ingredient_with_ncurses();
                if (selected_recipe_id != -1)
                    show_single_recipe_with_ncurses(g_recipe_names[selected_recipe_id], selected_recipe_id);

                break;
            case HELP:
                show_help_with_ncurses();
                break;
        }
    }
}

void refresh_recipes(char *p_filename) {
    clear_recipes();
    if (g_recipe_names != NULL)
        free(g_recipe_names);

    load_recipes(p_filename);
}
