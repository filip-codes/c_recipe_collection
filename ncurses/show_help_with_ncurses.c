#include <ncurses.h>
#include "../globals/window.h"
#include "../helpers/all.h"

/**
* \fn void show_help_with_ncurses()
* \brief Draw a help box with ncurses.
*
*/
void show_help_with_ncurses() {
    reset_box();

    mvwprintw(g_window, 0, 3, "Help");
    wrefresh(g_window);

    wattr_on(g_window, A_REVERSE, NULL);
    mvwprintw(g_window, 1, 1, "USAGE");
    wattr_off(g_window, A_REVERSE, NULL);
    mvwprintw(g_window, 2, 1, "./recipe_collection [filename]");

    wattr_on(g_window, A_REVERSE, NULL);
    mvwprintw(g_window, 4, 1, "SHORTCUTS");
    wattr_off(g_window, A_REVERSE, NULL);
    mvwprintw(g_window, 5, 1, "- q: Quit program");

    wrefresh(g_window);

    int ch;
    while ((ch = wgetch(g_window)) != 'q');
}
