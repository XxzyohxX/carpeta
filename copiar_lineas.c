/*
a.  Implementar una función `char **leer_lineas(size_t *n);` que lea líneas
    de `stdin` hasta que se termine la entrada estándar y que devuelva un
    arreglo de cadenas que contenga cada una de esas líneas. Debe
    devolverse la cantidad de líneas leídas a través de `n`.

b.  Implementar la función `void liberar_lineas(char **lineas, size_t n);`
    que reciba un arreglo dinámico de cadenas `lineas` de longitud `n` y
    libere la memoria asociada.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 200
#define CHOP 1

void liberar_lineas(char **strings, size_t n);
char ** leer_lineas(size_t *n);
void imprimir(char **strings, size_t n);
/*
//lee líneas de stdin y las devuelve por el nombre, devuelve la cantidad de líneas por la interfaz
//si hay un error devuelve NULL
char ** leer_lineas(size_t *n){
    char ** pstr = NULL;    //inicializo en NULL para usar realloc y poder liberar aun si no pedí nada
    char buffer[MAX_STR];
    char **aux = NULL;      //puntero auxiliar para pedir memoria
    size_t alloc = 0, used = 0;     //variables de control de memoria (pedido y usado)

    while(fgets(buffer, MAX_STR, stdin) != NULL){   //leo por stdin hasta eof

        if(alloc == used){      //si la cantidad de punteros pedidos ya los usé entonces...
            aux = realloc(pstr, sizeof(char *) * (alloc + CHOP));
            if(aux == NULL){
                liberar_lineas(pstr, used);      //si falló, tengo que liberar lo que pedí hasta el momento
                return NULL;
            }
            pstr = aux;
            alloc += CHOP;
        }
        if((pstr[used] = malloc(sizeof(char) * MAX_STR)) == NULL){   //pido espacio para la cadena almacenada en buffer
            liberar_lineas(pstr, used);      //libera el intervalo [0; used)
            return NULL;
        }
        strncpy(pstr[used], buffer, MAX_STR);   //copio de buffer a el puntero actual
        used++;
    }
    *n = used;      //guardo la cantidad de líneas al final, para no tener que volverlo a 0 si falla en el medio
    return pstr;
}
*/

char **leer_lineas(size_t *n) {
   *n = 0;

   char aux[MAX_STR];
   size_t i = 0;
   char **ss = NULL;

   while(fgets(aux, MAX_STR, stdin) != NULL) {
      char **auxaux = realloc(ss, (i + 1) * sizeof(char *));
      if(auxaux == NULL) {
          liberar_lineas(ss, i);
          return NULL;
      }
      ss = auxaux;

      ss[i] = malloc((strlen(aux) + 1) * sizeof(char));
      if(ss[i] == NULL) {
          liberar_lineas(ss, i);
          return NULL;
      }

      strcpy(ss[i], aux);
      i++;
   }

   *n = i;
   return ss;
}



void liberar_lineas(char **strings, size_t n){
    for(size_t i = 0; i < n; i++){
        free(strings[i]);   //libero los punteros a char
        strings[i] = NULL;  //seteo en NULL para evitar un doble free
    }
    free(strings);  //libero el puntero doble
    strings = NULL;
}

void imprimir(char **strings, size_t n){
    for (size_t i = 0; i < n; i++){
        printf("%s", strings[i]);
    }
}

int main(void){
    char **pstring;
    size_t n;
    pstring = leer_lineas(&n);
    if(pstring == NULL) 
        return EXIT_FAILURE;
    imprimir(pstring, n);
    liberar_lineas(pstring, n);
    return EXIT_SUCCESS;
}
