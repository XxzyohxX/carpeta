#include <stdio.h>

int main(int argc, char *argv[]) {

    // Forma 1:
    for(size_t i = 0; i < argc; i++)
        printf("%zd: %s\n", i, argv[i]);

    // Forma 2:
    for(size_t i = 0; argv[i] != NULL; i++)
        printf("%zd: %s\n", i, argv[i]);

    // Forma 3:
    for(char **s = argv; *s != NULL; s++)
        puts(*s);

    return 0;
}
