#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <stdint.h>

typedef struct {
    uint8_t a, x, y;    // Registros A, X e Y.
    uint16_t pc;        // Program counter.
    uint8_t status;     // Registro de status.
    uint8_t sp;         // Stack pointer.
    uint8_t *mem;       // Memoria.

    long ciclos;        // Cantidad de ciclos totales de ejecución.
} mos6502_t;

typedef struct {
    uint8_t codigo;     // Opcode.
    short ciclos;       // Cantidad de ciclos de la instrucción.
    uint8_t *m;         // Puntero al operando (registro o memoria).
    uint16_t direccion; // Dirección del operando (si corresponde).
} instruccion_t;

typedef struct {
    char ciclos;
    void (*direccionamiento)(mos6502_t *m, instruccion_t *i);
    void (*operacion)(mos6502_t *m, instruccion_t *i);
} diccionario_t;

#endif
