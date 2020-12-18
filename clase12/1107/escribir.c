#include <stdio.h>

int main(void) {
    int vector[] = {5, 2, 4, 8, 16, 23};

    FILE *f = fopen("vector.bin", "wb");
    if(f == NULL)
        return 1;

    //for(size_t i = 0; i < sizeof(vector) / sizeof(vector[0]); i++)
    //    fwrite(&vector[i], sizeof(int), 1, f);
    fwrite(vector, sizeof(int), 6, f);

    fclose(f);

    return 0;
}
