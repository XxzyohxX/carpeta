#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool imprimir(void *elem, void *extra) {
    fprintf(extra, "%s\n", elem);
    return true;
}

bool sumar(void *elem, void *extra) {
    *((float*)extra) += *((float*)elem);
    return true;
}
int main(void) {
    vector_t *v = vector_crear(10);

    for(size_t i = 0; i < 10; i++) {
        float *p = malloc(sizeof(float));
        *p = cos(i);
        vector_guardar(v, i, p);
    }

    float suma = 0;
/*    for(size_t i = 0; i < vector_largo(v); i++) {
        float *p = vector_obtener(v, i);
        suma += *p;
    }*/
    vector_recorrer(v, sumar, &suma);

    printf("La suma es %f\n", suma);

    vector_destruir(v, free);


    v = vector_crear(5);
    for(size_t i = 0; i < 5; i++)
        vector_guardar(v, i, "hola");

/*    for(size_t i = 0; i < vector_largo(v); i++)
        //puts(vector_obtener(v, i));
        printf("%s\n", (char*)vector_obtener(v, i));*/
    vector_recorrer(v, imprimir, stdout);

    FILE *f = fopen("archivo.txt", "wt");
    vector_recorrer(v, imprimir, f);
    fclose(f);

    vector_destruir(v, NULL);

    return 0;
}

