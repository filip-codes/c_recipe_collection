#include <stdio.h>

void mk_file(char *filename) {
    FILE *p_file = fopen(filename, "w");
    fclose(p_file);
}
