#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t mi_strlen(const char *s) {
	if(*s == '\0')
		return 0;

	return mi_strlen(s + 1) + 1;
}


bool esta_ordenado(const int *v, size_t n) {
	// Reduccion lineal
	if(n <= 1)
		return true;

	if(v[0] > v[1])
		return false;

	return esta_ordenado(v + 1, n - 1);
}


bool esta_ordenado2(const int *v, size_t n) {
	// Division y conquista
	if(n <= 1)
		return true;

	size_t medio = n / 2;

	if(v[medio - 1] > v[medio])
		return false;

	return esta_ordenado2(v, medio) && esta_ordenado2(v + medio, n - medio);
}


// Esta funcion es la que realmente hace la recursividad, pero es una funcion
// privada que no deberia ser llamada.
static bool es_palindromo_(const char *s, size_t len) {
	if(len < 2)
		return true;

	if(s[0] != s[len - 1])
		return false;

	return es_palindromo_(s + 1, len - 2);
}

// Esta funcion es la cara publica, no es recursiva pero acomoda los parametros
// para llamar a la funcion recursiva.
// Este tipo de funciones se denominan "wrapper" (envoltorio).
bool es_palindromo(const char *s) {
	return es_palindromo_(s, strlen(s));
}


int main() {
	printf("%zd\n", mi_strlen("hola"));


	int ordenado[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
	int desordenado[10] = {1, 2, 4, 3, 5, 6, 7, 8, 9, 10};

	printf("Esta %s\n", esta_ordenado(ordenado, 10) ? "ordenado" : "desordenado");
	printf("Esta %s\n", esta_ordenado(desordenado, 10) ? "ordenado" : "desordenado");
	printf("Esta %s\n", esta_ordenado2(ordenado, 10) ? "ordenado" : "desordenado");
	printf("Esta %s\n", esta_ordenado2(desordenado, 10) ? "ordenado" : "desordenado");


	// Lo anterior es una oda al copypaste... como hariamos si quisieramos
	// testear n funciones con m vectores???
	int *vectores[] = {ordenado, desordenado};
	bool (*funciones[])(const int *, size_t) = {esta_ordenado, esta_ordenado2};

	for(size_t i = 0; i < sizeof(funciones) / sizeof(funciones[0]); i++)
		for(size_t j = 0; j < sizeof(vectores) / sizeof(vectores[0]); j++)
			printf("Esta %s\n", funciones[i](vectores[j], 10) ? "ordenado" : "desordenado");


	printf("%s palindromo\n", es_palindromo("menem") ? "Es" : "No es");
	printf("%s palindromo\n", es_palindromo("macri") ? "Es" : "No es");
}
