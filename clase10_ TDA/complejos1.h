#ifndef _COMPLEJOS_H_
#define _COMPLEJOS_H_

struct complejo;
typedef struct complejo complejo_t;

complejo_t *complejo_crear(float real, float imag);

// Crea un complejo en base al modulo y el argumento en radianes.
complejo_t *complejo_crear2(float mod, float arg);
void complejo_destruir(complejo_t *c);

complejo_t *complejo_suma(const complejo_t *a, const complejo_t *b);
complejo_t *complejo_resta(const complejo_t *a, const complejo_t *b);
complejo_t *complejo_producto(const complejo_t *a, const complejo_t *b);
complejo_t *complejo_division(const complejo_t *a, const complejo_t *b);
complejo_t *complejo_conjugado(const complejo_t *c);
complejo_t *complejo_inverso(const complejo_t *c);

float complejo_real(const complejo_t *c);
float complejo_imag(const complejo_t *c);
float complejo_modulo(const complejo_t *c);

// Devuelve el valor principal del argumento de c.
float complejo_argumento(const complejo_t *c);

#endif
