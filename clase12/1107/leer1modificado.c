#include <stdio.h>
#include <stdlib.h>
void cargar(char *archivo){
FILE *f = fopen(archivo, "rb");
    if(f == NULL)
        return;

    int *vector = malloc(sizeof(int));
    if(vector == NULL) {
        fclose(f);
        return;
    }

    int n = 0;
    while(fread(vector + n, sizeof(int), 1, f) == 1) {
        n++;
        int *aux = realloc(vector, sizeof(int) * (n + 1));
        if(aux == NULL) {
            free(vector);
            fclose(f);
            return;
        }
        vector = aux;
    }

    fclose(f);

    for(int i = 0; i < n; i++)
        printf("%d\n", vector[i]);

    free(vector);
}
int main(int argc, char *argv[]) {
    cargar(argv[1]);   
    return 0;
}
