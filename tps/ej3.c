#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#define MASK_CARRY_OPERACION 0x100
#define MASK_NEGATIVE_OPERACION 0X80
#define MASK_OVERFLOW_OPERACION 0X80

typedef enum {CARRY, ZERO, INTERRUPT_DISABLE, DECIMAL , BREAK, OVERFLOW = 6, NEGATIVE = 7} flag_t; //status

bool get_status(uint8_t *reg, flag_t flag) {
	return *reg & 1 << flag;
}

void set_status(uint8_t *reg, flag_t flag, bool status) {
    if(status == true)
    	*reg |= (1 << flag); //setea un 1
    else
        *reg &= (~(1 << flag)); // setea un 0
}

void set_zero(uint8_t *reg, uint8_t res) {
	set_status(reg, ZERO, res == 0);

}

void set_negative(uint8_t *reg, uint8_t res) {
	set_status(reg, NEGATIVE, (res & MASK_NEGATIVE_OPERACION) != 0);

}

void set_carry(uint8_t *reg, uint16_t res) {
	set_status(reg, CARRY, (res & MASK_CARRY_OPERACION) != 0);

}

void set_overflow(uint8_t *reg, uint8_t a, uint8_t b, uint8_t res) {
	set_status(reg, OVERFLOW, ((a & MASK_OVERFLOW_OPERACION) == (b & MASK_OVERFLOW_OPERACION) && ((res & MASK_OVERFLOW_OPERACION) != (a & MASK_OVERFLOW_OPERACION) || (res & MASK_OVERFLOW_OPERACION) != (b & MASK_OVERFLOW_OPERACION))));

}

void rotate_left(uint8_t *reg, uint8_t *x) {
    bool aux = get_status(reg, CARRY);   
    bool aux2 = get_status(x, NEGATIVE);
    *x = *x << ZERO;
    set_status(x, CARRY, aux);       
    set_status(reg, CARRY, aux2);

}

void rotate_right(uint8_t *reg, uint8_t *x) {
    bool aux = get_status(reg, CARRY);
    uint8_t aux2 = get_status(x, CARRY);
    *x = *x >> ZERO;
    set_status(x, NEGATIVE, aux);
    set_status(reg, CARRY, aux2);
  
}

int main(void) {
    
    uint8_t reg = rand();

    set_status(&reg, CARRY, false);
    set_status(&reg, ZERO, true);
    set_status(&reg, INTERRUPT_DISABLE, false);
    set_status(&reg, DECIMAL, true);
    set_status(&reg, BREAK, false);
    set_status(&reg, OVERFLOW, true);
    set_status(&reg, NEGATIVE, false);

    assert((reg & 0xDF) == 0x4A);

    assert(!get_status(&reg, CARRY));
    assert(get_status(&reg, ZERO));
    assert(!get_status(&reg, INTERRUPT_DISABLE));
    assert(get_status(&reg, DECIMAL));
    assert(!get_status(&reg, BREAK));
    assert(get_status(&reg, OVERFLOW));
    assert(!get_status(&reg, NEGATIVE));


    set_zero(&reg, 1);
    assert(!get_status(&reg, ZERO));
    set_zero(&reg, 0);
    assert(get_status(&reg, ZERO));


    set_negative(&reg, -1);
    assert(get_status(&reg, NEGATIVE));
    set_negative(&reg, 127);
    assert(!get_status(&reg, NEGATIVE));
    set_negative(&reg, 128);
    assert(get_status(&reg, NEGATIVE));


    set_carry(&reg, 168 + 33);
    assert(!get_status(&reg, CARRY));
    set_carry(&reg, 168 + 97);
    assert(get_status(&reg, CARRY));

  
    set_overflow(&reg, 76, 41, 76 + 41);
    assert(!get_status(&reg, OVERFLOW));
    set_overflow(&reg, 108, 41, 108 + 41);
    assert(get_status(&reg, OVERFLOW));
    set_overflow(&reg, -10, -20, (-10) + (-20));
    assert(!get_status(&reg, OVERFLOW));
    // El casteo está sólo para callar el warning de overflow ;)
    set_overflow(&reg, -100, -29, (uint8_t)((-100) + (-29)));
    assert(get_status(&reg, OVERFLOW));
    set_overflow(&reg, 127, -128, 127 + (-128));
    assert(!get_status(&reg, OVERFLOW));
    set_overflow(&reg, -128, 127, (-128) + 127);
    assert(!get_status(&reg, OVERFLOW));


    uint8_t x = 0xBF;
    set_status(&reg, CARRY, false);
    rotate_left(&reg, &x);
    assert(get_status(&reg, CARRY));
    assert(x == 0x7E);
    rotate_left(&reg, &x);
    assert(!get_status(&reg, CARRY));
    assert(x == 0xFD);

    rotate_right(&reg, &x);
    assert(get_status(&reg, CARRY));
    assert(x == 0x7E);
    rotate_right(&reg, &x);
    assert(!get_status(&reg, CARRY));
    assert(x == 0xBF);


    printf("Todo OK\n");

    return 0;
   }