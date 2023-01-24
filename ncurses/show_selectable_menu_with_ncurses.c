#include <stdlib.h>
#include "../globals/window.h"
#include "../globals/terminal.h"
#include "../enums/menu.h"
#include "../helpers/all.h"

enum menu show_selectable_menu_with_ncurses(char *name, char *options[], int options_count) {
    reset_box();

    int choice, highlight_position = 0;

    mvwprintw(g_window, 0, 3, "%s", name);
    wrefresh(g_window);

    while(1) {
        for (int i = 0; i < options_count; i++) {
            if (i == highlight_position)
                wattr_on(g_window, A_STANDOUT, NULL);

            mvwprintw(g_window, i + 1, 1, "%s", options[i]);
            wattr_off(g_window, A_STANDOUT, NULL);
        }

        choice = wgetch(g_window);
        switch (choice) {
            case KEY_UP:
                highlight_position--;
                if (highlight_position == -1)
                    highlight_position = 0;
                break;
            case KEY_DOWN:
                highlight_position++;
                if (highlight_position == options_count)
                    highlight_position = options_count - 1;
                break;
            default:
                break;
        }

        if (choice == 113) {
            quit();
            exit(0);
        }

        if (choice == 10)
            break;
    }
    return (enum menu)highlight_position;
}
