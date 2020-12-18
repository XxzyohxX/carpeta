#include "complejos.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


void complejo_destruir_void(void *c) {
    complejo_destruir(c);
}

vector_t *leer_complejos(FILE *f) {
    vector_t *v = vector_crear(2);
    if(v == NULL) return NULL;

    size_t cant = 0;
    char aux[200];

    while(fgets(aux, 200, f) != NULL) {
        /*char *p;
        double real = strtod(aux, &p);
        if(*p != ',') { continue; }
        double imag = strtod(p + 1, &p);
        if(*p != '\n') { continue; }*/

        float real, imag;
        if(sscanf(aux, "%f,%f", &real, &imag) != 2)
            continue;

        complejo_t *c = complejo_crear(real, imag);
        if(c == NULL) {
            //vector_destruir(v, (void (*)(void*))complejo_destruir);
            vector_destruir(v, complejo_destruir_void);
            return NULL;
        }
        if(!vector_guardar(v, cant++, c)) {
            vector_destruir(v, complejo_destruir_void);
            return NULL;
        }

        if(cant == vector_largo(v)) {
            if(!vector_redimensionar(v, vector_largo(v) * 2)) {
                vector_destruir(v, complejo_destruir_void);
                return NULL;
            }
        }
    }

    vector_redimensionar(v, cant);

    return v;
}

int main(void) {
    FILE *f = fopen("complejos.txt", "rt");
    if(f == NULL) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    vector_t *v = leer_complejos(f);

    fclose(f);

    /* ... */

    for(size_t i = 0; i < vector_largo(v); i++) {
        complejo_t *c = vector_obtener(v, i);
        printf("%f %+fj\n", complejo_real(c), complejo_imag(c));
    }

    vector_destruir(v, complejo_destruir_void);

    return 0;
}
