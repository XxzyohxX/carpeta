#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const void *bin_search(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *)) {
    const char *v = base;

    size_t inicio = 0;
    size_t fin = nmemb;

    while(fin > inicio) {
        size_t medio = (fin + inicio) / 2;

        int res = compar(key, v + medio * size);

        if(res == 0)
            return v + medio * size;
        if(res < 0)
            fin = medio;
        else
            inicio = medio + 1;
    }
    return NULL;
}



int comparar(const void *pa, const void *pb) {
    const float *a = pa;
    const float *b = pb;

    if(*a == *b)
        return 0;
    else if(*a < *b)
        return -1;
    return 1;
}

int main(void) {
    float vector[10] = {-2, -1.2, -.3, 0, 5, 6.1, 7.8, 8, 9.1, 10};
    float val;
    const float *p;

    val = 0;
    p = bin_search(&val, vector, 10, sizeof(float), comparar);
    if(p != NULL) {
        printf("Valor: %f\n", *p);
        printf("Posicion: %ld\n", (p - vector)); // En C se puede restar punteros del mismo tipo al mismo bloque de memoria.
    }

    val = 1;
    p = bin_search(&val, vector, 10, sizeof(float), comparar);
    if(p == NULL)
        printf("No esta\n");

    return 0;
}

