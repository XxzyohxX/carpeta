#include <stdio.h>
#include <stdlib.h>
int imprimir_casa(char c) {
    c = cat_getchar();
    switch(c) {
        case 'A':
            puts("House Arryn");
            break;
        case 'B':
            puts("House Baratheon");
            break;
        case 'F':
            puts("House Frey");
            break;
        case 'G':
            puts("House greyjoy");
            break;
        case 'L':
            puts("House Lannister");
            break;
        case 'M':
            puts("House Martell");
            break;
        case 'S':
            puts("House Stark");
            break;
        case 'T':
            puts("House Targaryen");
            break;
        default:
            puts("No lo conozco");
            break;
    }
}

int main(){
char c;
imprimir_casa(c);
return 0 ;
}

