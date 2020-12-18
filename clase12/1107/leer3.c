#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("vector.bin", "rb");
    if(f == NULL)
        return 1;

    int n;
    fread(&n, sizeof(int), 1, f);

    int *vector = malloc(n * sizeof(int));

    fread(vector, sizeof(int), n, f);

    fclose(f);

    for(int i = 0; i < n; i++)
        printf("%d\n", vector[i]);

    free(vector);

    return 0;
}
