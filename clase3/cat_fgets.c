#include <stdio.h>

#define MAX_CADENA 256

int main(void) {
    char aux[MAX_CADENA];
    while(fgets(aux, MAX_CADENA, stdin) != NULL){
        printf("%s", aux);
        
    }
    return 0;
}
