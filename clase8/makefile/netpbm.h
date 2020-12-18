#ifndef NETPBM_H
#define NETPBM_H

#include "color.h"
#include <stdio.h>

#define NETPBM_MAX_OPEN	8
#define NETPBM_MAX_DIM	200

/* ATENCION: Ocultamos la implementacion!!! */
typedef struct netpbm netpbm;

typedef enum {
	NETPBM_MODE_PBM,
	NETPBM_MODE_PGM
} netpbm_mode;

/* Crea un nuevo PBM desde su color de fondo, sus dimensiones, tipo y maximo.
   Si modo es PBM, maximo es ignorado. */
netpbm *netpbm_create(size_t, size_t, tcolor, netpbm_mode, uchar);

/* Escribe el PBM en un archivo */
void netpbm_write(netpbm *, FILE *);

/* Libera al PBM usado */
void netpbm_release(netpbm *);

#endif /* NETPBM_H */
