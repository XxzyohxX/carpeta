#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stdint.h>

struct lista;
typedef struct lista lista_t;

lista_t *lista_crear();
void lista_destruir(lista_t *l, void (*f)(void *));
bool lista_insertar_comienzo(lista_t *l, void *dato);
void lista_recorrer(const lista_t *l, bool (*visitar)(void *elem, void *extra), void *extra);
bool lista_es_vacia(const lista_t *l);
void *lista_borrar(lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b));
size_t contar(nodo_t *n);
size_t longitud_lista(lista_t *l);

#endif
