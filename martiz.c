#include <stdint.h>

void rotar(size_t n, int m[n][n], size_t a, size_t b){
	for(size_t i = 0, i < n, i++){
		float vector[i] = matriz[i][a];
		matriz[i][a] = matriz[i][a];
		matriz[i][b] = vector[i];
	}
}