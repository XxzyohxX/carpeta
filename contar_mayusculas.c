#include <stdio.h>
#include <ctype.h>

int contar_mayuscular(const char cadena[]){
	int cant = 0;
	int c = 0;
	for(size_t i = 0; cadena[i] != '\0'; i++){
		if((c) = (isupper(cadena[i]))){
			cant += c;
		}
	}

	return cant;

}

int main (){
	const char cadena[] = "Algoritmos y Programacion I";
	int c = contar_mayuscular(cadena);
	printf("%d\n", c );

	return 0;
}