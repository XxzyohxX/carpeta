#include "lista.h"
#include <stdlib.h>
#include <stdint.h>

struct nodo {
    struct nodo *sig;
    void *dato;
};

struct lista {
    struct nodo *prim;
};

typedef struct nodo nodo_t;

lista_t *lista_crear() {
    lista_t *l = malloc(sizeof(lista_t));
    if(l == NULL)
        return NULL;

    l->prim = NULL;

    return l;
}

void lista_destruir(lista_t *l, void (*f)(void *)) {
    nodo_t *n = l->prim;
    while(n != NULL) {
        if(f != NULL)
            f(n->dato);

        nodo_t *sig = n->sig;
        free(n);
        n = sig;
    }

    free(l);
}

size_t contar(nodo_t *n){
    if(n->sig == NULL)
        return 1;

    return 1 + contar(n->sig);
}

size_t lista_longitud(lista_t *l){
    size_t long = contar(l->prim);
}


static nodo_t *crear_nodo(nodo_t *sig, void *dato) {
    nodo_t *n = malloc(sizeof(nodo_t));
    if(n == NULL)
        return NULL;

    n->sig = sig;
    n->dato = dato;

    return n;
}

bool lista_insertar_comienzo(lista_t *l, void *dato) {
    nodo_t *n = crear_nodo(l->prim, dato);
    if(n == NULL)
        return false;

    l->prim = n;
    return true;
}

void lista_recorrer(const lista_t *l, bool (*visitar)(void *elem, void *extra), void *extra) {
    nodo_t *n = l->prim;
    while(n != NULL) {
        if(!visitar(n->dato, extra)) return;

        n = n->sig;
    }
}

bool floyd(lista_t *l){


bool lista_es_vacia(const lista_t *l) {
    return l->prim == NULL;
}

void *lista_borrar(lista_t *l, const void *dato, int (*cmp)(const void *a, const void *b)) {
    if(l->prim == NULL)
        return NULL;

    if(cmp(l->prim->dato, dato) == 0) {
        void *retorno = l->prim->dato;

        nodo_t *prim = l->prim;
        l->prim = prim->sig;
        free(prim);

        return retorno;
    }

    nodo_t *ant = l->prim;
    while(ant->sig != NULL) {
        nodo_t *actual = ant->sig;
        if(cmp(actual->dato, dato) == 0) {
            void *retorno = actual->dato;

            ant->sig = actual->sig;
            free(actual);

            return retorno;
        }

        ant = actual;
    }

    return NULL;

}

