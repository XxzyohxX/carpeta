#include "vector2.h"
#include <stdlib.h>
#include <string.h>


struct vector {
    void **v;
    size_t s;
};

vector_t *vector_crear(size_t largo) {
    vector_t *v = malloc(sizeof(vector_t));
    if(v == NULL)
        return NULL;

    v->s = largo;
    v->v = calloc(largo, sizeof(void*));
    if(v->v == NULL) {
        free(v);
        return NULL;
    }

    //v->v = malloc(largo * sizeof(void*));
    //for(size_t i = 0; i < largo; i++)
    //    v->v[i] = NULL;
    //memset(v->v, 0, largo * sizeof(void*));

    return v;
}

void vector_destruir(vector_t *v, void (*f)(void *)) {
    if(f != NULL)
        for(size_t i = 0; i < v->s; i++)
            if(v->v[i] != NULL)
                f(v->v[i]);

    free(v->v);
    free(v);
}

size_t vector_largo(const vector_t *v) {
    return v->s;
}

bool vector_guardar(vector_t *v, size_t pos, void *dato) {
    v->v[pos] = dato;
    return true;
}

void *vector_obtener(const vector_t *v, size_t pos) {
    return v->v[pos];
}

bool vector_redimensionar(vector_t *v, size_t largo) {
    void **aux = realloc(v->v, largo * sizeof(void*));
    if(aux == NULL)
        return false;

    v->v = aux;

    for(size_t i = v->s; i < largo; i++)
        v->v[i] = NULL;
    //if(largo > v->s)
    //    memset(v->v + v->s, 0, (largo - v->s) * sizeof(void*));

    v->s = largo;

    return true;
}

int main(){
return 0;
}

