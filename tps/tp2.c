#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 256

typedef enum {HAL, INC, DEC, ADD, SUB, PUT, GET, JMP, BEQ} mnemonicos_de_las_instrucciones;

bool leer_instrucciones(uint8_t instrucciones[MAX]) {
    char aux[MAX];
 
    for(size_t i = 0; i < MAX; i++) {                                       
        
        fgets(aux, MAX, stdin);       

        if(fgets(aux, MAX, stdin) == NULL) {
        	break;
        }        	                                                          
        instrucciones[i] = atoi(aux);                                                                                                                                    
        
        return true;
        
        if(instrucciones[i] >= MAX) {                                         
    	    return false;
        }
    }   
}

int main() {
	uint8_t instrucciones[256];
    uint8_t datos[256] = {0};
    uint8_t contador_instrucciones = 0;
    uint8_t contador_datos = 0;
    datos[contador_datos] = 0;                                                                   
    
    leer_instrucciones(instrucciones);

	for(contador_instrucciones = 0; contador_instrucciones <= MAX; contador_instrucciones++) {   
                                                                                            	                                                                                                                                                                                    
        switch(instrucciones[contador_instrucciones]) {
        	case HAL :
        	    EOF;
        	    break;
        	case INC :
        	    contador_datos++;
        	    break;
        	case DEC :
        	    contador_datos--;
        	    break;
        	case ADD :
        	    datos[contador_datos] += 1;
        	    break;
        	case SUB :
        	    datos[contador_datos] -= 1;
        	    break;
        	case PUT :
                printf("%c\n",datos[contador_datos] );
        	case GET :
        	    leer_instrucciones(datos);
        	    break;
        	case JMP :
        	    contador_instrucciones += 2;
        	     break;
        	case BEQ :
        	    if(datos[contador_datos] = 0) {
        	     	
        	     	contador_instrucciones += 2;
        	     }

        	     else {
        	           
        	           contador_instrucciones++;
        	     }

        }


	}
} 