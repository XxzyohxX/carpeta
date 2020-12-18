#include <stdio.h>
#include "vector1.h"
#include <stdlib.h>
#include <string.h>

/*
    INVARIANTE:
        *) largo contiene el largo de v.
        *) Si largo = 0 => v = NULL.
        *) v está ordenado
*/
struct vector_ord {
    int *v;
    size_t largo;
};

vecord_t *vecord_crear() {
    vecord_t *vo = malloc(sizeof(vecord_t));
    if(vo == NULL)
        return NULL;

    vo->v = NULL;
    vo->largo = 0;

    return vo;
}

/*bool vecord_es_vacio(const vecord_t *vo) {
    return vo->largo == 0;
}*/

void vecord_destruir(vecord_t *vo) {
    free(vo->v);
    free(vo);
}

bool vecord_insertar(vecord_t *vo, int val) {
    int *aux = realloc(vo->v, sizeof(int) * (vo->largo + 1));
    if(aux == NULL)
        return false;

    vo->v = aux;

    size_t i;
    for(i = 0; i < vo->largo && vo->v[i] < val; i++) {}
    memmove(vo->v + i + 1, vo->v + i, (vo->largo - i) * sizeof(int));
    vo->v[i] = val;

    vo->largo++;

    return true;
}

int _comparar(const void *va, const void *vb) {
    const int *a = va;
    const int *b = vb;
    return *a - *b;
}

bool vecord_contiene(const vecord_t *vo, int val) {
    void *p = bsearch(&val, vo->v, vo->largo, sizeof(int), _comparar);
    return p != NULL;
}

int vecord_valor_en(const vecord_t *vo, size_t pos) {
    return vo->v[pos];
}

size_t vecord_largo(const vecord_t *vo) {
    return vo->largo;
}



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

