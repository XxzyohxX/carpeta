#include "matriz.h"

int main(void) {
    matriz_t *m = matriz_crear(5, 4);
    if(m == NULL) return 1;

    matriz_imprimir(m);
    matriz_destruir(m);

    return 0;
}

