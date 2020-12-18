#include "instruccionestp.h"
#include "ej3.h"
#include "estructuras.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint8_t desapilar(mos6502_t *mos){
	sp++;
	return mos->mem[0x01 | sp];
}

void ADC(mos6502_t *mos,instruccion_t *i){
    uint16_t aux = mos->a + *i->m + get_status(&mos->status, CARRY);
    
    mos->a = aux;

   
    set_zero(&mos->status, aux);
    set_carry(&mos->status, aux);
    set_negative(&mos->status, aux);
    set_overflow(&mos->status, aux);
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

void BCC(mos6502_t *mos,instruccion_t *i){
	if(!get_status(&mos->status, CARRY)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BCS(mos6502_t *mos,instruccion_t *i){
	if(get_status(&mos->status, CARRY)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BEQ(mos6502_t *mos,instruccion_t *i){
	if(get_status(&mos->status, ZERO)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BIT(mos6502_t *mos,instruccion_t *i){
	set_zero(&mos->status, mos->a & *i->m);
	set_negative(&mos->status, mos->a & *i->m);
	set_overflow(&mos->status, mos->a, *i->m, mos->a & *i->m);
}

void BMI(mos6502_t *mos,instruccion_t *i){
	if(get_status(&mos->status, NEGATIVE)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BNE(mos6502_t *mos,instruccion_t *i){
	if(!get_status(&mos->status, ZERO)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BPL(mos6502_t *mos,instruccion_t *i){
	if(!get_status(&mos->status, NEGATIVE)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BRK(mos6502_t *mos,instruccion_t *i){
	//mos->mem[0x01 | mos->sp] = 
}

void BVC(mos6502_t *mos,instruccion_t *i){
	if(!get_status(&mos->status, OVERFLOW)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void BVS(mos6502_t *mos,instruccion_t *i){
	if(get_status(&mos->status, OVERFLOW)){
		uint16_t aux = *i->m;
		mos->pc += aux;
	}
}

void CLC(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, false);
}

void CLD(mos6502_t *mos,instruccion_t *i){
	set_status(&mos->status, DECIMAL, false);
}

void CLI(mos6502_t *mos,instruccion_t *i){
	set_status(&mos->status, INTERRUPT_DISABLE, false);
}

void CLV(mos6502_t *mos,instruccion_t *i){
	set_status(&mos->status, OVERFLOW, false);
}

void CMP(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, (mos->a) >= (*i->m) );

    set_status(&mos->status, ZERO, (mos->a) == (*i->m));

    set_status(&mos->status, NEGATIVE, (mos->a - *i->m) < 0);
}

void CPX(mos6502_t *mos,instruccion_t *i){
	set_status(&mos->status, CARRY, (mos->x) >= (*i->m) );

    set_status(&mos->status, ZERO, (mos->x) == (*i->m));

    set_status(&mos->status, NEGATIVE, (mos->x - *i->m) < 0);
}

void CPY(mos6502_t *mos, instruccion_t *i){
	set_status(&mos->status, CARRY, (mos->y) >= (*i->m) );

    set_status(&mos->status, ZERO, (mos->y) == (*i->m));

    set_status(&mos->status, NEGATIVE, (mos->y - *i->m) < 0);
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

void INC(mos6502_t *mos,instruccion_t *i){
	*i->m += 1;

	set_zero(&mos->status, *i->m);
    set_negative(&mos->status, *i->m);
}

void INX(mos6502_t *mos,instruccion_t *i){
	mos->x += 1;

	set_zero(&mos->status, mos->x);
    set_negative(&mos->status, mos->x);
}

void INY(mos6502_t *mos,instruccion_t *i){
	mos->y += 1;

	set_zero(&mos->status, mos->y);
    set_negative(&mos->status, mos->y);
}

void JMP(mos6502_t *mos,instruccion_t *i){
    mos->pc = i->direccion;
}

void JSR(mos6502_t *mos,instruccion_t *i){ //duda

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

void LSR(mos6502_t *mos,instruccion_t *i){  //copiaste de ASL sin mirar nada
	uint16_t aux = *i->m >> 1; 
    *i->m = aux;

    set_zero(&mos->status, aux);
    set_carry(&mos->status, aux);
    set_negative(&mos->status, aux);
}

void NOP(mos6502_t *mos,instruccion_t *i){

}

void ORA(mos6502_t *mos, instruccion_t *i){
	uint16_t aux = (mos->a) | (*i->m);

	mos->a = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void PHA(mos6502_t *mos, instruccion_t *i){ //duda
	mos->mem[0x01 | mos->sp] = mos->a;
	mos->sp--;
}

void PHP(mos6502_t *mos, instruccion_t *i){ //duda
	mos->mem[0x01 | mos->sp] = mos->status | (1 << 4) | (1 << 5);
	mos->sp--;
}

void PLA(mos6502_t *mos, instruccion_t *i){ //duda
	mos->sp++;

}

void PLP(mos6502_t *mos, instruccion_t *i){ //duda

}

void ROL(mos6502_t *mos, instruccion_t *i){ //duda
//	rotate_left(&mos->status, *i->m);

//	set_zero(&mos->status, )
}

void ROR(mos6502_t *mos, instruccion_t *i){ //duda
	//rotate_left(i->m,...);
}

void RTI(mos6502_t *mos, instruccion_t *i){ //duda
	//decrementar sp-=2 y nisiquiera hay que borrar porque despues se sobreescribe el valor donde estamos parados
}

void RTS(mos6502_t *mos, instruccion_t *i){ //duda

}

void SBC(mos6502_t *mos, instruccion_t *i){
	uint16_t aux = mos->a - *i->m - (1 - get_status(&mos->status, CARRY));

	mos->a = aux;

	set_zero(&mos->status, aux);
	set_carry(&mos->status, aux);
	set_negative(&mos->status, aux);
	set_overflow(&mos->status, aux);
}

void SEC(mos6502_t *mos,instruccion_t *i){
    set_status(&mos->status, CARRY, true);
}

void SED(mos6502_t *mos, instruccion_t *i){
	set_status(&mos->status, DECIMAL, true);
}

void SEI(mos6502_t *mos, instruccion_t *i){
	set_status(&mos->status, INTERRUPT_DISABLE, true);
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

void TAX(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->a;

	mos->x = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void TAY(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->a;

	mos->y = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void TSX(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->sp;

	mos->x = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void  TXA(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->x;

	mos->a = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void TXS(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->x;

	mos->sp = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

void TYA(mos6502_t *mos, instruccion_t *i){
	uint8_t aux = mos->y;

	mos->a = aux;

	set_zero(&mos->status, aux);
	set_negative(&mos->status, aux);
}

