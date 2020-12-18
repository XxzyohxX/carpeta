#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

struct vector;
typedef struct vector vector_t;

vector_t *vector_crear(size_t largo);
void vector_destruir(vector_t *v, void (*f)(void *));

size_t vector_largo(const vector_t *v);
bool vector_guardar(vector_t *v, size_t pos, void *dato);
void *vector_obtener(const vector_t *v, size_t pos);
bool vector_redimensionar(vector_t *v, size_t largo);

#endif
