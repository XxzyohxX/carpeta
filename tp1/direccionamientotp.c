#include "Direccionamientotp.h"
#include"estructuras.h"


void modo_implicito(mos6502_t *m, instruccion_t *i) {
	i->m = NULL;
}

void modo_acumulador(mos6502_t *mos, instruccion_t *i){
    i->m = &(mos->a);
}

void modo_inmediato(mos6502_t *mos, instruccion_t *i){
    i->m = &(mos->mem[mos->pc]);
    mos->pc++;
}

void modo_absoluto(mos6502_t *mos, instruccion_t *i){ 
    uint16_t byte1 = mos->mem[mos->pc++];
    i->direccion = byte1 | mos->mem[mos->pc++] << 8;
    i->m = &(mos->mem[i->direccion]);
}

void modo_relativo(mos6502_t *mos, instruccion_t *i){
//	uint8_t byte_signado = mos->mem[mos->pc++];
//	i->m = byte_signado;
	//duda sumar pc byte signaddo??
}

void modo_pagina_cero(mos6502_t *mos, instruccion_t *i){
	uint8_t cte = mos->mem[mos->pc++];
	i->direccion = cte | 0x00 << 8;
	i->m = &(mos->mem[i->direccion]);
}

void modo_indirecto(mos6502_t *mos, instruccion_t *i){
	uint16_t byte1 = mos->mem[mos->pc++];
	uint16_t posicion_de_memoria = byte1 | mos->mem[mos->pc++] << 8; 
	uint16_t contenido = mos->mem[posicion_de_memoria];
	mos->pc = contenido;
	i->m = &(mos->mem[mos->pc++]);
}

void modo_absoluto_X(mos6502_t *mos, instruccion_t *i){
	uint16_t byte1 = mos->mem[mos->pc++];
    i->direccion = (byte1 | mos->mem[mos->pc++] << 8) + mos->x;
    i->m = &(mos->mem[i->direccion]);
}

void modo_absoluto_Y(mos6502_t *mos, instruccion_t *i){
	uint16_t byte1 = mos->mem[mos->pc++];
    i->direccion = (byte1 | mos->mem[mos->pc++] << 8) + mos->y;
    i->m = &(mos->mem[i->direccion]);
}

void modo_pagina_cero_X(mos6502_t *mos, instruccion_t *i){
	uint8_t cte = mos->mem[mos->pc++];
	if((i->direccion = (cte | 0x00 << 8) + mos->x) )
	i->m = &(mos->mem[i->direccion]);//hago como pagina cero pero al primer byte si es 16bits lo meto en uno de 8bits o hago un and
}

void modo_pagina_cero_Y(){

}

void 

// en vez de meter & agarro el valor y se lo meto a pc

 	mos->pc = mos->mem[mos->pc] & 0x00ff;
 	uint16_t aux2 = mos->mem[mos->pc] | mos->mem[mos->pc + 1] << 8;
 	aux2 += mos->y;
