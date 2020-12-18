#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool es_primo(int n) {
    if(n == 1)
        return false;

    for(int i = 2; i < sqrt(n); i++)
        if(n % i == 0)
            return false;

    return true;
}

int main(void) {
    for(int i = 1; i < 10; i++)
        printf("El numero %d %ses primo\n", i, es_primo(i) ? "" : "no ");

    return 0;
}

