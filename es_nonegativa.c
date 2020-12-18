#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define n 4
#define m 4

bool es_nonegativa(float matriz[n][m]){
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < m; j++){
			if(matriz[i][j] < 0)
				return false;
		}
	}
	return true;
}

int main(){
	float matriz[n][m] = {
		{1.0,2.0,3.0,4.0},
		{5.0,6.0,7.0,-8.0},
		{9.0,10.0,11.0,12.0}
	};

	bool aux = es_nonegativa(matriz);
	printf("%d\n", aux );
	
	return 0;

}