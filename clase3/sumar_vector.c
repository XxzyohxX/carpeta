#include <stdio.h>
#include <stdlib.h>

#define TAM_VECTOR 5
#define MAX_CADENA 256

int sumar(int v[], size_t n) {
    int suma = 0;
    for(size_t i = 0; i < n; i++)
        suma += v[i];

    return suma;
}


int main(void) {
    int v[TAM_VECTOR];

    for(size_t i = 0; i < TAM_VECTOR; i++) {
        char aux[MAX_CADENA];
        fgets(aux, MAX_CADENA, stdin);

       v[i] = atoi(aux);
    }

    printf("La suma es %d\n", sumar(v, TAM_VECTOR));

    return 0;
}
