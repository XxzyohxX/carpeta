#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

void mi_fgets(char s[], int n) {
    int i = 0;

    int c;
    while(i < n - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';
}


int main(void) {
    int dia;
    char dias[] = {'D', 'L', 'M', 'X', 'J', 'V', 'S'};

    char aux[MAX_STR];
    //fgets(aux, MAX_STR, stdin);
    mi_fgets(aux, MAX_STR);

    dia = atoi(aux);

    if(dia < 1 || dia > 366)
        return 1;

    printf("El dia es %c\n", dias[(dia - 1) % 7]);

    return 0;
}

