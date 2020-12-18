#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdlib.h>

struct matriz;
typedef struct matriz matriz_t;

matriz_t *matriz_crear(size_t filas, size_t columnas);
void matriz_destruir(matriz_t *m);
void matriz_imprimir(matriz_t *m);

#endif
