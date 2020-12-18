// Función "wrapper" (envoltorio)
float potencia(float x, int n) {
    if(n == 0) return 1;
    if(x == 0) return 0;
    if(x == 1) return 1;

    if(n < 0) return potencia_(1 / x, -n);

    return potencia_(x, n);
}
/*
float potencia_(float x, int n) {
    if(n == 1)
        return x;

    float aux = potencia_(x, n/2);

    return aux * aux * (n % 2 ? x : 1);
}
*/

unsigned int potencia(unsigned int b, unsigned int n) {
    if (n == 0)
        return 1;
    unsigned int r;
    if (n % 2 == 0) {
        r = potencia(b, n / 2);
        return r * r;
    } else {
        r = potencia(b, (n-1) / 2);
        return r * r * b;
    }
}


