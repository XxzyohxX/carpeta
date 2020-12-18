#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <assert.h>

#define MASK_AFT 0x80
#define MASK_BAND 0x40
#define MASK_SYN 0x01
#define MASK_FDIV 0x3E
#define SHIFT_FDIV 1

typedef enum {AM, FM} band_t;

const char *bandas[] = {"AM", "FM"};

band_t get_band(uint8_t *registro) {
    return (*registro & MASK_BAND) ? FM : AM;
}

void set_band(uint8_t *registro, band_t band) {
    if(band == FM)
        *registro |= MASK_BAND; // setear un 1
    else
        *registro &= ~MASK_BAND; // setear un 0
}

int get_synthesizer_divider(uint8_t *registro) {
                                // El +1 es porque 00000 representa 1 y así.
    return ((*registro & MASK_FDIV) >> SHIFT_FDIV) + 1;
}

void set_synthesizer_divider(uint8_t *registro, int fdiv) {
    *registro &= ~MASK_FDIV;
                       // El -1 es porque 1 implica 00000 y así.
    *registro |= (fdiv - 1) << SHIFT_FDIV;
}

int main(void) {
    uint8_t registro = rand();

    set_band(&registro, AM);
    //printf("La banda está puesta en %s\n", get_band(&registro)]);
    assert(get_band(&registro) == AM);

    set_band(&registro, FM);
    assert(get_band(&registro) == FM);

    set_synthesizer_divider(&registro, 25);
    assert(get_synthesizer_divider(&registro) == 25);

    return 0;
}
