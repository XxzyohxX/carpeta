#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *strdup(const char *s) {
    char *copia = malloc((strlen(s) + 1) * sizeof(char));

    if(copia == NULL)
        return NULL;

    strcpy(copia, s);
    return copia;
}

int main() {
    char *s2;

    s2 = strdup("hola");
    if(s2 == NULL) {
        printf("No había memoria\n");
        return 1;
    }

    printf("%p\n", s2);

    free(s2);

    return 0;
}



