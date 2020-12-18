#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

float promediar(int valores[], size_t n);
size_t leer_notas(int notas[], size_t max);

int main() {
    int notas[MAX];
    size_t n;

    n = leer_notas(notas, MAX);
    if(n == 0)
        return 1;

    float promedio = promediar(notas, n);

    printf("%f\n", promedio);

    return 0;
}


size_t leer_notas(int notas[], size_t max) {
    for(size_t i = 0; i < max; i++) {
        char aux[1000];
        if(fgets(aux, 1000, stdin) == NULL)
            return i;
        char *p;
        strtol(aux, &p, 10);
        int n = atoi(aux);
        if(*p != '\n' || n < 0 || n > 10)
            return i;

        notas[i] = n;
    }

    return max;
}


float promediar(int valores[], size_t n) {
    int suma = 0;
    for(size_t i = 0; i < n; i++)
        suma += valores[i];

    return (float)suma / n;
}

