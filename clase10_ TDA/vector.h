#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

struct vector_ord;
typedef struct vector_ord vecord_t;

vecord_t *vecord_crear();
void vecord_destruir(vecord_t *vo);

bool vecord_insertar(vecord_t *vo, int val);
bool vecord_contiene(const vecord_t *vo, int val);
int vecord_valor_en(const vecord_t *vo, size_t pos);
size_t vecord_largo(const vecord_t *vo);

#endif
