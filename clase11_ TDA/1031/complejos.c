#include "complejos.h"

#include <stdlib.h>
#include <math.h>

struct complejo {
    float real, imag;
};

/*struct complejo {
    float mod, arg;
};*/

complejo_t *complejo_crear(float real, float imag) {
    complejo_t *c = malloc(sizeof(complejo_t));
    if(c == NULL)
        return NULL;

    c->real = real;
    c->imag = imag;

    return c;
}

void complejo_destruir(complejo_t *c) {
    free(c);
}

complejo_t *complejo_crear2(float mod, float arg) {
    return complejo_crear(mod * cos(arg), mod * sin(arg));
}

complejo_t *complejo_suma(const complejo_t *a, const complejo_t *b) {
    return complejo_crear(a->real + b->real, a->imag + b->imag);
}

complejo_t *complejo_resta(const complejo_t *a, const complejo_t *b) {
    return complejo_crear(a->real - b->real, a->imag - b->imag);
}

complejo_t *complejo_producto(const complejo_t *a, const complejo_t *b) {
    //return complejo_crear(a->real * b->real - a->imag * b->imag,
    //    a->real * b->imag + b->real * a->imag);
    float ma = complejo_modulo(a);
    float mb = complejo_modulo(b);
    float aa = complejo_argumento(a);
    float ab = complejo_argumento(b);

    return complejo_crear2(ma * mb, aa + ab);
}

complejo_t *complejo_division(const complejo_t *a, const complejo_t *b);

complejo_t *complejo_conjugado(const complejo_t *c) {
    return complejo_crear(c->real, -(c->imag));
}

complejo_t *complejo_inverso(const complejo_t *c);

float complejo_real(const complejo_t *c) {
    return c->real;
}

float complejo_imag(const complejo_t *c) {
    return c->imag;
}

float complejo_modulo(const complejo_t *c) {
    return sqrt(c->real * c->real + c->imag * c->imag);
}

float complejo_argumento(const complejo_t *c) {
    return atan2(c->imag, c->real);
}


#ifdef DEBUG_COMPLEJOS

#include <assert.h>
#include <stdio.h>

int main(void) {
    // Acá meto pruebas
}

#endif
