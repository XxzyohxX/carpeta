#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 100
#define MAX_NOTAS 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int padron;
    size_t cant_notas;
    int notas[MAX_NOTAS];
} alumno_t;


alumno_t *alumno_crear(const char *nombre, int padron) {
    alumno_t *a = malloc(sizeof(alumno_t));
    if(a == NULL)
        return NULL;

    strcpy(a->nombre, nombre);
    a->padron = padron;
    a->cant_notas = 0;

    return a;
}


int main(void) {
    alumno_t **alumnos; // alumnos es un arreglo dinámico de punteros a alumnos
    size_t cant_alumnos = 91;

    alumnos = malloc(cant_alumnos * sizeof(alumno_t*));
    if(alumnos == NULL)
        return 1;

    for(size_t i = 0; i < cant_alumnos; i++) {
        //fgets()
        alumnos[i] = alumno_crear("Juan", 1000);
        if(alumnos[i] == NULL) {
            while(i--)
                free(alumnos[i]);
            free(alumnos);
        }
    }

    for(size_t i = 0; i < cant_alumnos; i++) {
        printf("%s %d\n", alumnos[i]->nombre, alumnos[i]->padron);
    }

    for(size_t i = 0; i < cant_alumnos; i++) {
        free(alumnos[i]);
    }

    free(alumnos);

    return 0;
}
