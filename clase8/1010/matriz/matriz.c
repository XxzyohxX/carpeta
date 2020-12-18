#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz {
    int **m;
    size_t filas, columnas;
};

matriz_t *matriz_crear(size_t filas, size_t columnas) {
    matriz_t *m = malloc(sizeof(matriz_t));
    if(m == NULL)
        return NULL;

    m->filas = filas;
    m->columnas = columnas;

    m->m = malloc(filas * sizeof(int*));
    if(m->m == NULL) {
        free(m);
        return NULL;
    }

    for(size_t i = 0; i < filas; i++) {
        m->m[i] = calloc(columnas, sizeof(int));
        if(m->m[i] == NULL) {
            m->filas = i;
            matriz_destruir(m);
            /*while(i--) free(m->m[i]);
            free(m->m);
            free(m);*/
            return NULL;
        }
    }

    return m;
}

void matriz_destruir(matriz_t *m) {
    for(size_t i = 0; i < m->filas; i++)
        free(m->m[i]);

    free(m->m);
    free(m);
}

void matriz_imprimir(matriz_t *m) {
    for(size_t i = 0; i < m->filas; i++) {
        for(size_t j = 0; j < m->columnas; j++)
            printf("%d ", m->m[i][j]);
        putchar('\n');
    }
}

