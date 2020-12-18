#include <stdio.h>

// memset pertenece a string.h, esta es una posible implementación
void memset(char *s, int c, size_t n) {
    for(size_t i = 0; i < n; i++)
        s[i] = c;
}

int main() {
    int matriz_que_essplota[10000][1000] = {0};
    //memset(matriz_que_essplota, 0, sizeof(int)*10000*1000);

    printf("%d\n", matriz_que_essplota[0][0]);

    return 0;
}
