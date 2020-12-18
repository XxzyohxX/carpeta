#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_CADENA 20

typedef struct {
    char nombre [MAX_CADENA];
    unsigned int padron;
    float promedio_general; 
} alumno_t;

bool alumno_son_iguales(const alumno_t *a, const alumno_t *b){
    if((strcmp(a->nombre, b->nombre) == 0) && a->padron == b->padron && a->promedio_general == b->promedio_general)
	return true;
    return false;
}

int main(){
    alumno_t julio = {"julio", 102805, 3.0};
    alumno_t jorge = {"julio", 102805, 6.66};
    bool a = alumno_son_iguales(&julio, &jorge);
    printf("%d\n", a );
    return 0
;
}
