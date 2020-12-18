/*
Ejercicio 1: BitSpeak.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define DELIM ' '
#define SHIFT_SILABA 8
#define MASK_SILABA 0XFF
#define SHIFT_CONS 4
#define MASK_VOCAL 0x0F

typedef struct {
    uint32_t n_n;
    char *caracter;

}dictionary_t;

const dictionary_t consonantes[] = 
{
    {0x0,"p"},
    {0x1,"b"},
    {0x2,"t"},
    {0x3,"d"},
    {0x4,"k"},
    {0x5,"g"},
    {0x6,"sh"},
    {0x7,"j"},
    {0x8,"f"},
    {0x9,"v"},
    {0xa,"l"},
    {0xb,"r"},
    {0xc,"m"},
    {0xd,"y"},
    {0xe,"s"},
    {0xf,"z"}
};

const dictionary_t vocales[] =
{
    {0x0,"a"},
    {0x1,"e"},
    {0x2,"i"},
    {0x3,"o"},
    {0x4,"u"},
    {0x5,"an"},
    {0x6,"en"},
    {0x7,"in"},
    {0x8,"un"},
    {0x9,"on"},
    {0xa,"ai"},
    {0xb,"ei"},
    {0xc,"oi"},
    {0xd,"ui"},
    {0xe,"aw"},
    {0xf,"ow"}

};

/*Devuelve la codificacion BitSpeak correspondiente al numero de 32 bitsdaod
utilizando los diccionarios previamente declarados
*/
char *bitspeak(uint32_t n){
    char *cod_sib = malloc(sizeof(char) * n);
    char *cod_sib1 = malloc(sizeof(char)* n/2);
    char *cod_sib2 = malloc(sizeof(char)* n/2);
    size_t tam_consonantes = sizeof(consonantes) / sizeof(consonantes[0]);
    size_t tam_vocales = sizeof(vocales) / sizeof(vocales[0]);
    size_t i;
    uint8_t sib1 = n >> SHIFT_SILABA;
    uint8_t sib2 = n & MASK_SILABA;
    char *aux = malloc(sizeof(char) * 4);
    for(i = 0; i<tam_consonantes; i++){
        if(consonantes[i].n_n == (sib1 >> SHIFT_CONS)){
            aux = consonantes[i].caracter;
            strcat(cod_sib1,aux);
            //printf("%s\n",cod_sib1);
        }
        if(consonantes[i].n_n == (sib2 >> SHIFT_CONS )){
            aux = consonantes[i].caracter;
            strcat(cod_sib2,aux);
            //printf("%s\n",cod_sib2);
        }
    }
    for(i = 0; i< tam_vocales; i++){
        if(vocales[i].n_n == (sib1 & MASK_VOCAL) ){
            aux = vocales[i].caracter;
            strcat(cod_sib1,aux);
           // printf("%s\n",cod_sib1);
        }
        if(vocales[i].n_n == (sib2 & MASK_VOCAL)){
            aux = vocales[i].caracter;
            strcat(cod_sib2,aux);
           // printf("%s\n",cod_sib2);
        }

    }

    strcat(cod_sib,cod_sib1);
    //printf("%s \n",cod_sib);
    strcat(cod_sib,cod_sib2);

    return cod_sib;

}

int main(void){
    char *ej = bitspeak(0x00ff);
    printf("%s \n",ej);

    free(ej);

    return EXIT_SUCCESS;
}

