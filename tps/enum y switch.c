#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main()
{
	enum dia_t {LUN, MAR, MIE, JUE, VIE, SAB, DOM};
    dia_t = 6;
    switch(dia_t) {
    	case VIE:
    	printf("ya se termina\n");
    	break;
    	case SAB:
    	case DOM:
    	printf("finde\n");
    	break;
    	default:
    	printf("uff\n");
    	break;

    }
	return 0;
}