#include <stdlib.h>
#include "color.h"
#include "common.h"

static tcolor _color(color_name, tbool, uchar, tcolor (*)(tcolor));

tcolor color_from_name(color_name cn, uchar max) {
	return _color(cn, FALSE, max, NULL);
}

tcolor color_monochrome(color_name cn) {
	return _color(cn, TRUE, 1, NULL);
}

static tcolor _color(color_name cn, tbool inverted, uchar max, tcolor (*transform)(tcolor)) {
	tcolor c;

	c = max * (float)cn / COLOR_BLACK;

	if(inverted)
		c = max - c;

	if(transform != NULL)
		c = transform(c);

	return c;
}

