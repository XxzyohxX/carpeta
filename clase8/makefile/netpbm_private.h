#ifndef NETPBM_PRIVATE_H
#define NETPBM_PRIVATE_H

/* OJO: No entregar este .h, aca esta la posta! */

#include "netpbm.h"

struct netpbm {
	netpbm_mode mode;
	tcolor canvas[NETPBM_MAX_DIM][NETPBM_MAX_DIM];
	size_t width, height;
	uchar max;
};

#define PBM_HEADER	"P1"
#define PGM_HEADER	"P2"
#define LINE_WIDTH	80

#endif /* NETPBM_PRIVATE_H */
