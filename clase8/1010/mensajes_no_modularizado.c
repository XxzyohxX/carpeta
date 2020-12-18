#include <stdio.h>
#include <math.h>

enum saludo {HOLA, CHAU, QUE_TAL, ECHAR};

#ifdef ENGLISH
const char *mensajes[] = {
    [HOLA] = "Hello",
    [CHAU] = "Goodbye",
    [QUE_TAL] = "Jaguar iu",
    [ECHAR] = "Get out!",
};
#elif defined SPANISH
const char *mensajes[] = {
    [HOLA] = "Hola",
    [CHAU] = "Chau",
    [QUE_TAL] = "Que tal",
    [ECHAR] = "Andate!",
};
#else
#error "Falta definir un mensaje"
#endif

void imprimir_mensaje(enum saludo s) {
    printf("%s\n", mensajes[s]);
}

int main(void) {
    imprimir_mensaje(HOLA);

    imprimir_mensaje(CHAU);
    return 0;
}

