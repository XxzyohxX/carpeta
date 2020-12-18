#define INICIO -10
#define FIN 10
#define PASO 0.001
#define N_MAX 10
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define E 2.7182818284595
double factorial(unsigned int n){
    double nfactorial = sqrt(2*PI*n)*pow(n/E, n);
    return nfactorial;
}
double seno(double x, unsigned int n_max){
    double seno = 0;
    for(int n = 0; n < n_max; n++){
        seno += pow(-1, n)*pow(x, 2*n+1)/factorial(2*n+1);
    }
  return seno;
}
int main () {
    double x = INICIO;
    while(x <= FIN){
        printf("%f, %f\n", x, seno(x,N_MAX));
        x += PASO;	
    } 
  return 0;
}
