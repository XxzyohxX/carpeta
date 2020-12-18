#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("vector.bin", "rb");
    if(f == NULL)
        return 1;

    int *vector = malloc(sizeof(int));
    if(vector == NULL) {
        fclose(f);
        return 1;
    }

    int n = 0;
    while(fread(vector + n, sizeof(int), 1, f) == 1) {
        n++;
        int *aux = realloc(vector, sizeof(int) * (n + 1));
        if(aux == NULL) {
            free(vector);
            fclose(f);
            return 1;
        }
        vector = aux;
    }

    fclose(f);

    for(int i = 0; i < n; i++)
        printf("%d\n", vector[i]);

    free(vector);

    return 0;
}
