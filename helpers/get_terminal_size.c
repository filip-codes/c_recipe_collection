#include <stdlib.h>
#include "../globals/terminal.h"

void get_terminal_size() {
    g_terminal = malloc(sizeof(struct terminal));
    getmaxyx(stdscr, g_terminal->height, g_terminal->width);
}
