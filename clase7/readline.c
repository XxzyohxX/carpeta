#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOQUE 5
#define INICIAL 8


// Forma 1: Pedimos de a uno por vez.
// No guardamos el '\n' por lo que de devolver línea vacía no sabemos si es una
// línea en blanco o se terminó la entrada.
char *readline() {
    char *s;

    if((s = malloc(1 * sizeof(char))) == NULL)
        return NULL;

    int c;
    size_t i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        s[i++] = c;

        char *aux = realloc(s, (i + 1) * sizeof(char));
        if(aux == NULL) {
            free(s);
            return NULL;
        }
        s = aux;
    }

    s[i] = '\0';

    return s;
}


// Forma 2: Pedido de memoria por bloques constantes.
// Se guarda el '\n'.
char *readline2() {
    char *s = NULL;
    size_t usados = 0;
    size_t pedidos = 0;

    int c;
    while(1) {
        c = getchar();
        if(usados + 1 >= pedidos) {
            char *aux = realloc(s, (pedidos + BLOQUE) * sizeof(char));
            if(aux == NULL) {
                free(s);
                return NULL;
            }
            s = aux;
            pedidos += BLOQUE;
        }
        s[usados++] = c;

        if(c == EOF) {
            s[usados - 1] = '\0';
            return s;
        }
        if(c == '\n') {
            s[usados] = '\0';
            return s;
        }
    }

    return s;
}


// Forma 3: Pedido de memoria incremental exponencialmente.
char *readline3() {
    char *s = malloc(INICIAL);
    size_t inicio = 0;
    size_t pedida = INICIAL;

    if(s == NULL)
        return NULL;

    while(fgets(s + inicio, pedida - inicio, stdin) != NULL && s[strlen(s + inicio) + inicio - 1] != '\n') {
        char *aux = realloc(s, pedida * 2 * sizeof(char));
        if(aux == NULL) {
            free(s);
            return NULL;
        }
        s = aux;
        inicio = pedida - 1;
        pedida *= 2;
    }

    return s;
}


int main(void) {

    while(1) {
        char *s = readline3();

        if(s == NULL)
            return 1;

        if(s[0] == '\0') {
            free(s);
            break;
        }

        printf("%s", s);

        free(s);
    }

    return 0;
}
