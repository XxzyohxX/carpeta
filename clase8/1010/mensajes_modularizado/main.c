#include <stdio.h>
#include <math.h>
#include "mensajes.h"
#include "mensajes.h"


void imprimir_mensaje(enum saludo s) {
    printf("%s\n", mensajes[s]);
}

int main(void) {
    imprimir_mensaje(HOLA);

    printf("%d\n", (int)sqrt(36));
    printf("%d\n", 6);

    imprimir_mensaje(CHAU);
    return 0;
}

