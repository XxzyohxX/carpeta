#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

float promediar(int *v, size_t n) {
    int suma = 0;
    for(size_t i = 0; i < n; i++)
        suma += v[i];

    return (float)suma / n;
}

int main(void) {
    char aux[MAX_STR];

    printf("Ingrese el número de notas: ");
    fgets(aux, MAX_STR, stdin);
    int n = atoi(aux);

    int *v = malloc(n * sizeof(int));
    if(v == NULL) {
        return 1;
    }

    for(int i = 0; i < n; i++) {
        printf("Ingrese la nota %d: ", i + 1);
        fgets(aux, MAX_STR, stdin);
        v[i] = atoi(aux);
    }

    printf("El promedio es %f\n", promediar(v, n));

    free(v);

    return 0;
}
