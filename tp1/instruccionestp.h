#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
#include "estructuras.h"
void ADC(mos6502_t *m, instruccion_t *i);

void AND(mos6502_t *m, instruccion_t *i);

void ASL(mos6502_t *m, instruccion_t *i);

void BCC(mos6502_t *m, instruccion_t *i);

void BCS(mos6502_t *m, instruccion_t *i);

void BEQ(mos6502_t *m, instruccion_t *i);

void BIT(mos6502_t *m, instruccion_t *i);

void BMI(mos6502_t *m, instruccion_t *i);

void BNE(mos6502_t *m, instruccion_t *i);

void BPL(mos6502_t *m, instruccion_t *i);

void BRK(mos6502_t *m, instruccion_t *i);

void BVC(mos6502_t *m, instruccion_t *i);

void BVS(mos6502_t *m, instruccion_t *i);

void CLC(mos6502_t *m, instruccion_t *i);

void CLD(mos6502_t *m, instruccion_t *i);

void CLI(mos6502_t *m, instruccion_t *i);

void CLV(mos6502_t *m, instruccion_t *i);

void CMP(mos6502_t *m, instruccion_t *i);

void CPX(mos6502_t *m, instruccion_t *i);

void CPY(mos6502_t *m, instruccion_t *i);

void DEC(mos6502_t *m, instruccion_t *i);

void DEX(mos6502_t *m, instruccion_t *i);

void DEY(mos6502_t *m, instruccion_t *i);

void EOR(mos6502_t *m, instruccion_t *i);

void INC(mos6502_t *m, instruccion_t *i);

void INX(mos6502_t *m, instruccion_t *i);

void INY(mos6502_t *m, instruccion_t *i);

void JMP(mos6502_t *m, instruccion_t *i);

void JSR(mos6502_t *m, instruccion_t *i);

void LDA(mos6502_t *m, instruccion_t *i);

void LDX(mos6502_t *m, instruccion_t *i);

void LDY(mos6502_t *m, instruccion_t *i);

void LSR(mos6502_t *m, instruccion_t *i);

void NOP(mos6502_t *m, instruccion_t *i);

void ORA(mos6502_t *m, instruccion_t *i);

void PHA(mos6502_t *m, instruccion_t *i);

void PHP(mos6502_t *m, instruccion_t *i);

void PLA(mos6502_t *m, instruccion_t *i);

void PLP(mos6502_t *m, instruccion_t *i);

void ROL(mos6502_t *m, instruccion_t *i);

void ROR(mos6502_t *m, instruccion_t *i);

void RTI(mos6502_t *m, instruccion_t *i);

void RTS(mos6502_t *m, instruccion_t *i);

void SBC(mos6502_t *m, instruccion_t *i);

void SEC(mos6502_t *m, instruccion_t *i);

void SED(mos6502_t *m, instruccion_t *i);

void SEI(mos6502_t *m, instruccion_t *i);

void STA(mos6502_t *m, instruccion_t *i);

void STX(mos6502_t *m, instruccion_t *i);

void STY(mos6502_t *m, instruccion_t *i);

void TAX(mos6502_t *m, instruccion_t *i);

void TAY(mos6502_t *m, instruccion_t *i);

void TSX(mos6502_t *m, instruccion_t *i);

void TXA(mos6502_t *m, instruccion_t *i);

void TXS(mos6502_t *m, instruccion_t *i);

void TYA(mos6502_t *m, instruccion_t *i);


#endif