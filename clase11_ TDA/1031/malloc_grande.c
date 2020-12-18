#include <stdlib.h>

int main(void) {
    int *v = malloc(-1 * sizeof(int));

    v[0] = 10;

    return 0;
}

