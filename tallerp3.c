#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 1. a)
struct polinomio{
    size_t grado; //grado del polinomio, de 0 a n
    float * coeficientes; // vector con los valores del polinomio del menor orden al mayor
};
typedef struct polinomio polinomio_t;


// 1. b)
size_t polinomio_grado(const polinomio_t *p){
    return p->grado;
}

// 1. c)
static polinomio_t * _polinomio_crear(size_t n){
    polinomio_t *p = malloc(sizeof(polinomio_t));
    if(p == NULL){
        return NULL;
    }
    p->grado = n;
    p->coeficientes = calloc(n, sizeof(float));
    if(p->coeficientes == NULL){
        free(p);
        return NULL;
    }
    return p;
}

polinomio_t *polinomio_derivar(const polinomio_t *p){
    polinomio_t *derivada = _polinomio_crear(p->grado - 1);
    if(derivada == NULL){
        return NULL;
    }
    for (size_t i = 0; i < p->grado; i++) {
        derivada->coeficientes[i] = p->coeficientes[i+1] * (i+1);
    }
    return derivada;
}

// 2.
#define MAX 50
typedef unsigned int uint;

typedef struct{
    char nombre[MAX];
    uint dni;
    float altura;
} persona_t;

// 2. a)
bool leer_persona(FILE *f, persona_t *p){
    if(fread(p, sizeof(persona_t), 1, f) != 1){
        return false;
    }
    return true;
}

// 2. b)
void escribir_persona(FILE *f, const persona_t *p){
    fwrite(&p->nombre,sizeof(char),sizeof(p->nombre),f);
    fwrite(&p->dni,sizeof(unsigned int),sizeof(p->dni),f);
    fwrite(&p->altura,sizeof(float),sizeof(p->altura),f);
    //fprintf(f, "%s;%ui;%f\n", p->nombre, p->dni, p->altura);
}

// 2. c)
bool leer_personas(const char *r, persona_t v[], size_t max, size_t *n){
    FILE *f = fopen(r, "rb");
    if(f == NULL){
        return false;
    }
    size_t i;
    for (i = 0; i < max; i++) {
        if(fread(&v[i], sizeof(persona_t), 1, f) != 1){
            break;
        }
    }
    *n = i;
    fclose(f);
    return true;
}

// 3.
int main(int argc, char *argv[]){
    //FILE *f;
    persona_t p[MAX];
    size_t n;
    if(argc != 2){
        return 1;
    }
    if(!strcmp(argv[1], "--help")){
        fprintf(stdout, "blabla\n");
        return 0;
    }
    if(!leer_personas(argv[1], p, MAX, &n)){
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        escribir_persona(stdout, &p[i]);
    }

    return 0;
}
