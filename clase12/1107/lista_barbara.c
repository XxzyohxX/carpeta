#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

bool imprimir(void *elem, void *extra) {
    printf("%i\n", *((int*)elem));
    return true;
}

struct busqueda {
    int buscado;
    int *encontrado;
};

bool buscar(void *elem, void *extra) {
    struct busqueda *b = extra;
    if(*(int*)(elem) == b->buscado) {
        b->encontrado = extra;
        return false;
    }
    return true;
}

int comparar(const void *l, const void *r) {
    const int *il = l;
    const int *ir = r;

    return *ir - *il;
}

int main(void) {
    lista_t *l = lista_crear();
    if(l == NULL)
        return 1;

    for(size_t i = 0; i < 10; i++) {
        int *elem = malloc(sizeof(int));
        if(elem == NULL) break;

        *elem = i;
        if(! lista_insertar_comienzo(l, elem)) break;
    }

    lista_recorrer(l, imprimir, NULL);
   // l = insertar_final(l, 20);
   /* struct busqueda b;

    b.buscado = 5;
    b.encontrado = NULL;
    lista_recorrer(l, buscar, &b);
    if(b.encontrado != NULL)
        printf("Lo encontre: %i\n", *b.encontrado);
    else
        printf("No lo encontre\n");*/

    int a_borrar = 5;
    int *borrado = lista_borrar(l, &a_borrar, comparar);
    if(borrado != NULL) {
        printf("Lo borro\n");
        free(borrado);
    }

    lista_recorrer(l, imprimir, NULL);

    lista_destruir(l, free);

    return 0;
}

