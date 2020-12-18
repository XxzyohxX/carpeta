#ifndef COLOR_H
#define COLOR_H

#include "common.h"

typedef uchar tcolor;

typedef enum {
	COLOR_WHITE,
	COLOR_LIGHT_GRAY,
	COLOR_GRAY,
	COLOR_DARK_GRAY,
	COLOR_BLACK
} color_name;

/* Recibe el nombre de un valor y su maximo y devuelve un color que lo represente */
tcolor color_from_name(color_name, uchar);

/* Recibe el valor blanco o negro y devuelve el color monocromo que lo representa */
tcolor color_monochrome(color_name);

#endif /* COLOR_H */
