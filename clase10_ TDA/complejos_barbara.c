#include "complejos.h"
#include <stdio.h>

#define PI 3.14159265358979323846

int main(void) {
    complejo_t *a, *b, *c;

    a = complejo_crear(0, 1);
    b = complejo_crear2(1, PI/2);

    c = complejo_suma(a, b);

    printf("%f + j%f\n", complejo_real(c), complejo_imag(c));

    complejo_destruir(a);
    complejo_destruir(b);
    complejo_destruir(c);

    return 0;
}
