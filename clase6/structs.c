#include <stdio.h>
#include <math.h>

struct punto {
    float x, y, z;
};

float distancia(struct punto *p1, struct punto *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}

int main() {
    struct punto p1;
    struct punto p2 = {1, 2, 3};

    p1.x = 1;
    p1.y = 2;
    p1.z = 3;

    printf("%f\n", distancia(&p1, &p2));

    if(p1.x == p2.x && p1.y == p2.y && p1.z == p2.z)
        printf("Son iguales");

    return 0;
}
