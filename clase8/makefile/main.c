#include <stdio.h>
#include <assert.h>
#include "color.h"
#include "netpbm.h"

int main(void) {
	FILE *f;
	netpbm *n;

	n = netpbm_create(35, 30, color_monochrome(COLOR_BLACK), NETPBM_MODE_PBM, 0);
	f = fopen("test.pbm", "wt");
	assert(n != NULL && f != NULL);
	netpbm_write(n, f);
	netpbm_release(n);
	fclose(f);

	n = netpbm_create(20, 30, color_from_name(COLOR_GRAY, 30), NETPBM_MODE_PGM, 30);
	f = fopen("test.pgm", "wt");
	assert(n != NULL && f != NULL);
	netpbm_write(n, f);
	netpbm_release(n);
	fclose(f);

	return 0;
}
