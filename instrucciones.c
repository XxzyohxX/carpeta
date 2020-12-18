#include "instrucciones.h"
#include "ej3.h"
#include "estructuras.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

void ADC(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = mos->a + *i->m + get_status(&mos->status, CARRY);
    
    mos->a = aux;

   
    set_zero(&mos->status, aux);
    set_carry(&mos->status, aux);
    set_negative(&mos->status, aux);
}

void AND(mos6502_t *mos,instruccion_t *i){
    uint8_t aux = (mos->a) & (*i->m);

    mos->a = aux;

    set_zero(&mos->status, aux);
    set_negative(&mos->status, aux); 
}

void ASL(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = *i->m << 1;
    *i->m = aux;

    set_zero(&mos->status, aux);
    set_carry(&mos->status, aux);
    set_negative(&mos->status, aux);

}

void CLC(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, false);
}

void CMP(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, (mos->a) >= (*i->m) );

    set_status(&mos->status, ZERO, (mos->a) == (*i->m));

    set_status(&mos->status, NEGATIVE, (mos->a - *i->m) < 0);
}

void DEC(mos6502_t *mos,instruccion_t *i){
    *i->m -=1;

    set_zero(&mos->status, *i->m);
    set_negative(&mos->status, *i->m);
}

void DEX(mos6502_t *mos,instruccion_t *i){
    mos->x -= 1;

    set_zero(&mos->status, mos->x);
    set_negative(&mos->status, mos->x);

}

void DEY(mos6502_t *mos,instruccion_t *i){
    mos->y -=1;

    set_zero(&mos->status, mos->y);
    set_negative(&mos->status, mos->y);
}

void EOR(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = (mos->a) ^ (*i->m);

    mos->a = aux;

    set_zero(&mos->status, aux);
    set_negative(&mos->status, aux);
}

void JMP(mos6502_t *mos,instruccion_t *i){
    mos->pc = i->direccion;
}

void LDA(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = *i->m;

    mos->a = aux;

    set_zero(&mos->status, mos->a);
    set_negative(&mos->status, mos->a);
}

void LDX(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = *i->m;

    mos->x = aux;


    set_zero(&mos->status, mos->x);
    set_negative(&mos->status, mos->x);
}

void LDY(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = *i->m;

    mos->y = aux;

    set_zero(&mos->status, mos->y);
    set_negative(&mos->status, mos->y);
}

void NOP(mos6502_t *mos,instruccion_t *i){

}


void SEC(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, true);
}

void STA(mos6502_t *mos,instruccion_t *i){
    *i->m = mos->a;
}

void STX(mos6502_t *mos,instruccion_t *i){
    *i->m = mos->x;
}

void STY(mos6502_t *mos,instruccion_t *i){
    *i->m = mos->y;
}