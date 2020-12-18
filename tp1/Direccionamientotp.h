#ifndef DIRECCIONAMIENTO_H
#define DIRECCIONAMIENTO_H
#include "estructuras.h"

// NO INDEXADOS, NO EN MEMORIA
void modo_implicito(mos6502_t *m, instruccion_t *i);

void modo_acumulador(mos6502_t *m, instruccion_t *i);

void modo_inmediato(mos6502_t *m, instruccion_t *i);

//NO INDEXADOS, EN MEMORIA
void modo_relativo(mos6502_t *m, instruccion_t *i);

void modo_absoluto(mos6502_t *m, instruccion_t *i);

void modo_pagina_cero(mos6502_t *m, instruccion_t *i);

void modo_indirecto(mos6502_t *m, instruccion_t *i);

//INDEXADOS
void modo_absoluto_X(mos6502_t *m, instruccion_t *i);

void modo_absoluto_Y(mos6502_t *m, instruccion_t *i);

void modo_pagina_cero_X(mos6502_t *m, instruccion_t *i);

void modo_pagina_cero_Y(mos6502_t *m, instruccion_t *i);

void modo_indexado_indirecto_X(mos6502_t *m, instruccion_t *i);

void modo_indexado_indirecto_Y(mos6502_t *m, instruccion_t *i);

#endif
