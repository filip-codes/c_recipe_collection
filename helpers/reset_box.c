#include "../globals/window.h"
#include "../globals/terminal.h"

void reset_box(bool reset_keypad) {
    g_window = newwin(g_terminal->height - 1, g_terminal->width - 2, 1, 1);
    box(g_window, 0, 0);
    refresh();
    wrefresh(g_window);
    keypad(g_window, true);
}
