#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("vector.txt", "r");
    if(f == NULL)
        return 1;

    int pedidos = 1;
    int *vector = malloc(sizeof(int) * pedidos);

    int n = 0;
    int leidos;
    while((leidos = fread(vector + n, sizeof(int), pedidos, f)) == pedidos) {
        n += leidos;
        pedidos *= 2;
        vector = realloc(vector, (n + pedidos) * sizeof(int));
    }
    n += leidos;

    fclose(f);

    for(int i = 0; i < n; i++)
        printf("%d\n", vector[i]);

    free(vector);
    
    return 0;
}
