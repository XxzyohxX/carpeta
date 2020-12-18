#include <stdio.h>

int main(void) {
    int vector[] = {2, 4, 8, 16, 23};
    int n = sizeof(vector) / sizeof(vector[0]);

    FILE *f = fopen("vector.bin", "wb");
    if(f == NULL)
        return 1;

    fwrite(&n, sizeof(int), 1, f);
    fwrite(vector, sizeof(int), n, f);
	
    fclose(f);

    return 0;
}
