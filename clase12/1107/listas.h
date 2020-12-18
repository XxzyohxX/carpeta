#ifndef LISTAS_H
#define LISTAS_H
#include <stdbool.h>

struct lista_simple;
typedef struct lista_simple lista;

lista *inicializar_lista();
lista *solicitar_nodo ();
lista *insertar_inicio (lista *inicio, int valor)
lista *eliminar_inicio (lista *inicio)
lista *insertar_final (lista *inicio, int valor)
void imprimir_lista (lista *inicio)
lista *eliminar_final (lista *inicio)
lista *eliminar_final_r (lista *inicio)
lista *insertar_final_r(lista *inicio, int valor)



#endif