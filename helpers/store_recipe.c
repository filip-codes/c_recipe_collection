#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "../globals/window.h"
#include "../globals/terminal.h"

#include "all.h"

void store_recipe(char *p_filename) {
    reset_box();

    FILE *p_file = fopen(p_filename, "a");

    struct recipe *p_recipe = new_recipe();
    echo();
    mvwprintw(g_window, 1, 1, "Enter a recipe name:");
    mvwgetstr(g_window, 2, 1, p_recipe->p_name);

    struct ingredient **ingredients = malloc(sizeof(struct ingredient *));
    int ingredients_counter = 0;
    while(1) {
        g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
        box(g_window, 0, 0);
        refresh();
        wrefresh(g_window);

        mvwprintw(g_window, 1, 1, "%s", "Do you want to add an ingredient? (Y/n)");

        char c = wgetch(g_window);
        if (c == 'n' || c == 'N')
            break;

        ingredients_counter++;
        *ingredients = realloc(*ingredients, ingredients_counter * sizeof(struct ingredient));

        struct ingredient *tmp_ingredient = new_ingredient();
        if (tmp_ingredient == NULL)
            continue;

        (*ingredients)[ingredients_counter - 1] = *tmp_ingredient;

        g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
        box(g_window, 0, 0);
        refresh();
        wrefresh(g_window);

        mvwprintw(g_window, 1, 1, "Enter an ingredient name:");
        mvwgetstr(g_window, 2, 1, (*ingredients)[ingredients_counter - 1].p_name);

        g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
        box(g_window, 0, 0);
        refresh();
        wrefresh(g_window);

        mvwprintw(g_window, 1, 1, "Enter an ingredient amount:");
        mvwgetstr(g_window, 2, 1, (*ingredients)[ingredients_counter - 1].p_amount);
    }

    g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
    box(g_window, 0, 0);
    refresh();
    wrefresh(g_window);

    mvwprintw(g_window, 1, 1, "Enter a recipe instruction:");
    mvwgetstr(g_window, 2, 1, p_recipe->p_instruction);
    noecho();

    reset_box();

    mvwprintw(g_window, 1, 1, "Done. ;)");
    wgetch(g_window);

    fputs("<recipe>\n", p_file);
    fputs("\t<name>\n", p_file);
    fputs("\t\t", p_file);
    fputs(p_recipe->p_name, p_file);
    fputs("\n", p_file);
    fputs("\t</name>\n", p_file);

    if (ingredients_counter > 0) {
        fputs("\t<ingredients>\n", p_file);
        for(int i = 0; i < ingredients_counter; i++) {
            fputs("\t\t<ingredient>\n", p_file);
            fputs("\t\t\t<ingredient_amount>\n", p_file);
            fputs("\t\t\t\t", p_file);
            fputs((*ingredients)[i].p_amount, p_file);
            fputs("\n", p_file);
            fputs("\t\t\t</ingredient_amount>\n", p_file);
            fputs("\t\t\t<ingredient_name>\n", p_file);
            fputs("\t\t\t\t", p_file);
            fputs((*ingredients)[i].p_name, p_file);
            fputs("\n", p_file);
            fputs("\t\t\t</ingredient_name>\n", p_file);
            fputs("\t\t</ingredient>\n", p_file);
        }
        fputs("\t</ingredients>\n", p_file);
    }

    fputs("\t<instruction>\n", p_file);
    fputs("\t\t", p_file);
    fputs(p_recipe->p_instruction, p_file);
    fputs("\n", p_file);
    fputs("\t</instruction>\n", p_file);
    fputs("</recipe>\n", p_file);

    fclose(p_file);
}
