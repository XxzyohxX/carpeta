#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 256

enum {HAL, INC, DEC, ADD, SUB, PUT, GET, JMP, BEQ};
 
bool leer_instrucciones(uint8_t instrucciones[MAX]) {
 
    for(size_t i = 0; i < MAX; i++) {                                       
        
        char aux[10];

        if(fgets(aux, 10, stdin) == NULL) 
            return true; 

        int n = atoi(aux);
        
        if(n > 255 || n < 0)
        	return false;
        	
     	instrucciones[i] = n;       
    }

    return false;
}



 int main() {
    uint8_t instrucciones[MAX];
    uint8_t datos[MAX] = {0};
    uint8_t contador_instrucciones = 0;
    uint8_t contador_datos = 0;

    if(leer_instrucciones(instrucciones) == false)
        return 1;

        for(contador_instrucciones = 0; contador_instrucciones < MAX; contador_instrucciones++){
    	    switch(instrucciones[contador_instrucciones]) {
    		    case HAL:
    		        return 0;
    		        break;
    		    case INC:
    		        contador_datos++;
    		        break;
    		    case DEC:
    		        contador_datos--;
    		        break;
    		    case ADD:
    		        datos[contador_datos]++;
    		        break;
    		    case SUB:
    		        datos[contador_datos]--;
    		        break;
    		    case PUT:
    		        putchar(datos[contador_datos]);
    		        break;
    		    case GET:
    		        datos[contador_datos] = getchar();
    		        break;
    		    case JMP:
    		        contador_instrucciones = instrucciones[contador_instrucciones + 1] - 1;
    		        break;
    		    case BEQ:
    		        if(datos[contador_datos] == 0){
    		    	    contador_instrucciones = instrucciones[contador_instrucciones + 1] - 1;
                        break;
    		        }
    		        else {
    		    	    contador_instrucciones++;
                        break;
    		    }
    	     }
        }
     
 return 0;
}
