#include <stdio.h>
#include "netpbm.h"
#include "netpbm_private.h"

static netpbm images[NETPBM_MAX_OPEN];
static short image_in_use[NETPBM_MAX_OPEN] = {0};

static const char *headers[] = {
	PBM_HEADER,
	PGM_HEADER
};

static void _fill(size_t, tcolor);

netpbm *netpbm_create(size_t w, size_t h, tcolor c, netpbm_mode m, uchar max) {
	size_t i;

	if(w > NETPBM_MAX_DIM || h > NETPBM_MAX_DIM)
		return NULL;

	for(i = 0; i < NETPBM_MAX_OPEN; i++)
		if(! image_in_use[i])
			break;

	if(i == NETPBM_MAX_OPEN)
		return NULL;

	image_in_use[i] = 1;

	images[i].width = w;
	images[i].height = h;
	images[i].mode = m;
	images[i].max = max;

	_fill(i, c);

	return images + i;
}

void netpbm_release(netpbm *n) {
	image_in_use[n - images] = 0;
}

static void _fill(size_t index, tcolor c) {
	register size_t i, j;

	for(i = 0; i < images[index].height; i++)
		for(j = 0; j < images[index].width; j++)
			images[index].canvas[i][j] = c;
}

void netpbm_write(netpbm *n, FILE *f) {
	register size_t i, j, c;

	fprintf(f, "%s\n", headers[n->mode]);
	fprintf(f, "%lu %lu\n", (unsigned long)n->width, (unsigned long)n->height);

	if(n->mode != NETPBM_MODE_PBM)
		fprintf(f, "%d\n", (int)n->max);

	for(i = 0; i < n->height; i++) {
		c = 0;
		for(j = 0; j < n->width; j++) {
			c += fprintf(f, "%d ", n->canvas[i][j]);

			if(c >= LINE_WIDTH) {
				fputc('\n', f);
				c = 0;
			}
		}
		fputc('\n', f);
	}
}

