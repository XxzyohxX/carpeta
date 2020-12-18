#include <stdio.h>
#include "vector.h"
#include <stdlib.h>
#include <string.h>

int main() {
    vecord_t *v = vecord_crear();
    if(v == NULL)
        return 1;

    printf("%zd\n", vecord_largo(v));

    printf("%s\n", vecord_contiene(v, 1) ? "Esta" : "No esta");

    vecord_insertar(v, 1);
    vecord_insertar(v, 10);
    vecord_insertar(v, 2);
    vecord_insertar(v, -2);
    vecord_insertar(v, 5);

    printf("%s\n", vecord_contiene(v, 1) ? "Esta" : "No esta");
    printf("%s\n", vecord_contiene(v, 4) ? "Esta" : "No esta");
    printf("%s\n", vecord_contiene(v, -10) ? "Esta" : "No esta");
    printf("%s\n", vecord_contiene(v, 199) ? "Esta" : "No esta");

    for(size_t i = 0; i < vecord_largo(v); i++)
        printf("%zd: %i\n", i, vecord_valor_en(v, i));

    vecord_destruir(v);

    return 0;
}

