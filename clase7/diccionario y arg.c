#include <stdio.h>
#include <string.h>


typedef void (*funcion_t)(void);


void saludar_es() {
    printf("Hola");
}

void saludar_en() {
    printf("Hello");
}

void saludar_pt() {
    printf("Olá");
}

void saludar_fr() {
    printf("Bonjourrrrrr!");
}


// Forma 1: Con enum más vectores sueltos:
typedef enum {ES, PT, EN, FR, _LAST} lang_t;
const char *parametro[] = {"es", "pt", "en", "fr"};

funcion_t funciones[] = {saludar_es, saludar_pt, saludar_en, saludar_fr};


// Forma 2: Con una estructura que vincula las cosas (preferible):
typedef struct {
    char *parametro;
    funcion_t funcion;
} dicc_t;

dicc_t diccionario[] = {
    {"es", saludar_es},
    {"pt", saludar_pt},
    {"en", saludar_en},
    {"fr", saludar_fr},
};


int main(int argc, char *argv[]) {
    lang_t lenguaje;
    size_t i;

    if(argc == 1) {
        // Forma 1:
        printf("Uso:\n");
        for(i = 0; i < _LAST; i++)
            printf("\t%s %s\n", argv[0], parametro[i]);

        // Forma 2:
        printf("Uso:\n");
        for(i = 0; i < sizeof(diccionario) / sizeof(diccionario[0]); i++)
            printf("\t%s %s\n", argv[0], diccionario[i].parametro);

        return 1;
    }

    // Forma 1:
    for(i = 0; i < _LAST; i++) {
        if(!strcmp(argv[1], parametro[i])) {
            lenguaje = i;
            break;
        }
    }
    if(i == _LAST) {
        printf("Uso incorrecto\n");
        return 1;
    }

    funciones[lenguaje]();
    putchar('\n');


    // Forma 2:
    size_t indice;

    for(i = 0; i < sizeof(diccionario) / sizeof(diccionario[0]); i++)
        if(!strcmp(diccionario[i].parametro, argv[1]))
            break;
    if(i == sizeof(diccionario) / sizeof(diccionario[0])) {
        printf("Uso incorrecto\n");
        return 1;
    }
    indice = i;


    diccionario[indice].funcion();
    putchar('\n');

    return 0;
}
