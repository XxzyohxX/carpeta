#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 256

#define TAMANIO 12

int contar_elementos(int a[TAMANIO]);

int main()
{
    int a[ TAMANIO ] = { 1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45};
    printf( "El total de los elementos del arreglo es %d\n", contar_elementos(a));
    printf("%zd\n %zd\n", sizeof(uint8_t), sizeof(int));
    return 0;
}

int contar_elementos(int a[TAMANIO]){
    int i, total = 0;
    for ( i = 0; i < TAMANIO; i++ ) {
        total = total + 1;
    }
    return total;
}