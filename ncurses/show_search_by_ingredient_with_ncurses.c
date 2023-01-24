#include <string.h>
#include <stdlib.h>
#include "../structs/ingredient.h"
#include "../structs/recipe.h"
#include "../globals/recipe.h"
#include "../globals/window.h"
#include "../globals/terminal.h"
#include "../helpers/all.h"

int show_search_by_ingredient_with_ncurses() {
    char *p_ingredient_prompt = malloc(sizeof(char));
    if (p_ingredient_prompt == NULL)
        exit(0);

    strcpy(p_ingredient_prompt, "");

    g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
    box(g_window, 0, 0);
    refresh();
    wrefresh(g_window);

    echo();
    mvwprintw(g_window, 1, 1, "Search by ingredient full name:");
    mvwgetstr(g_window, 2, 1, p_ingredient_prompt);

    int recipes_count = 0;
    struct recipe *p_head = g_recipe;
    struct recipe *tmp_recipe = NULL;
    while(p_head != NULL) {
        for(int i = 0; i < p_head->ingredients_count; i++) {
            struct ingredient *p_current_ingredient = &p_head->p_ingredient[i];
            if (p_current_ingredient == NULL)
                continue;

            char *p_ingredient_full_name = malloc((strlen(p_current_ingredient->p_amount) + strlen(p_current_ingredient->p_name)) * sizeof(char));

            strcat(p_ingredient_full_name, p_current_ingredient->p_amount);
            strcat(p_ingredient_full_name, p_current_ingredient->p_name);

            if (strstr(p_ingredient_full_name, p_ingredient_prompt) != NULL) {
                // Check if p_head equals tmp_recipe. If not, push it.
                struct recipe *tmp = tmp_recipe;
                bool recipe_was_found = false;
                while(tmp != NULL) {
                    if (tmp->id == p_head->id)
                        recipe_was_found = true;

                    tmp = tmp->p_next;
                }
                if (recipe_was_found == false) {
                    struct recipe *new_recipe = malloc(sizeof(struct recipe));
                    new_recipe->id = p_head->id;
                    new_recipe->p_name = p_head->p_name;
                    new_recipe->p_instruction = p_head->p_instruction;
                    new_recipe->p_next = tmp_recipe;
                    tmp_recipe = new_recipe;
                    recipes_count++;
                }
            }
        }
        p_head = p_head->p_next;
    }

    wclear(g_window);
    box(g_window, 0, 0);
    refresh();
    wrefresh(g_window);
    keypad(g_window, true);

    int choice, highlight_position = 0;

    mvwprintw(g_window, 0, 3, "Choose a recipe");
    wrefresh(g_window);

    struct recipe *rcp = tmp_recipe;
    while(1) {
        rcp = tmp_recipe;
        for(int i = 0; i < recipes_count; rcp = rcp->p_next) {
            if (i == highlight_position)
                wattr_on(g_window, A_REVERSE, NULL);

            mvwprintw(g_window, i + 1, 1, "%s", rcp->p_name);
            wattr_off(g_window, A_REVERSE, NULL);
            i++;
        }

        choice = wgetch(g_window);
        switch (choice) {
            case KEY_UP:
                highlight_position--;
                if (highlight_position == -1)
                    highlight_position = recipes_count - 1;
                break;
            case KEY_DOWN:
                highlight_position++;
                if (highlight_position == recipes_count)
                    highlight_position = 0;
                break;
            default:
                break;
        }

        if (choice == 113) { // 'q'
            quit();
            exit(0);
        }

        if (choice == 10) // Enter
            break;
    }
    rcp = tmp_recipe;
    int rcp_count = -1;
    while(rcp != NULL) {
        rcp_count++;
        if (rcp_count == highlight_position)
            return rcp->id;
        rcp = rcp->p_next;
    }
    return -1;
}
