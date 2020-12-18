#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *repetir(int n, char *s) {
    const size_t largo = strlen(s);
    char *r = malloc((n * largo + 1) * sizeof(char));
    if (r == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < n; i++) {
        strcpy(r + (i * largo), s);
    }

    return r;
}

int main() {
    char *s = repetir(3, "hola");
    if (s == NULL) {
        return 1;
    }
    printf("%s\n", s);
    free(s);
    return 0;
}