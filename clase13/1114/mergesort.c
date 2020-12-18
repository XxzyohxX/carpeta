#include <stdlib.h>
#include <string.h>

// Recibe l1 y l2 listas ordenadas de tamaños n1 y n2 respectivamente.
int *merge(int l1[], size_t n1, int l2[], size_t n2) {
    size_t i1, i2;

    int *res = malloc((n1 + n2) * sizeof(int));
    if(res == NULL)
        return NULL;
    size_t i = 0;

    i1 = i2 = 0;
    while(i1 < n1 && i2 < n2) {
        if(l1[i1] < l2[i2]) {
            res[i++] = l1[i1++];
        }
        else
            res[i++] = l2[i2++];
    }

    while(i1 < n1) {
        res[i++] = l1[i1++];
    }

    while(i2 < n2) {
        res[i++] = l2[i2++];
    }

    return res;
}


static int *mergesort_(int l[], size_t n) {
    if(n == 1) {
        int *r = malloc(sizeof(int));
        *r = l[0];
        return r;
    }

    size_t medio = n / 2;
    int *izq = mergesort_(l, medio);
    int *der = mergesort_(l + medio, n - medio);

    int *completo = merge(izq, medio, der, n - medio);

    free(izq);
    free(der);

    return completo;
}

void mergesort(int l[], size_t n) {
    int *r = mergesort_(l, n);
    memcpy(l, r, n * sizeof(int));
    free(r);
}

#ifdef DEBUG

#include <stdio.h>
#include <time.h>

#define CANT 100

void print_arr(int l[], size_t n) {
    char *cat = "";
    for(size_t i = 0; i < n; i++) {
        printf("%s%d", cat, l[i]);
        cat = ", ";
    }
    putchar('\n');
}

int main(void) {
    int vector[CANT];
    srand(time(NULL));

    for(size_t i = 0; i < CANT; i++)
        vector[i] = rand() % 100;

    print_arr(vector, CANT);

    mergesort(vector, CANT);

    print_arr(vector, CANT);

    return 0;
}

#endif
