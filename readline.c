#include <stdio.h>
#include <stdlib.h>

#define MAX 200

char *readline(FILE *f) {

	char *str;
	size_t i = 0;

	str = malloc(sizeof(char) * 1);
	
	if(str == NULL)
		return NULL;

	while(fgets(str, MAX, f) != NULL) {
		i++;

		char *aux = realloc(str, sizeof(char) * i);
		if(aux == NULL) {
			free(str);
			return NULL;
		}

		str = aux;
	}

	return str;
}

int main() {

	FILE *f = fopen("entrada.txt", "r");
	if(f == NULL)
		return 1;

	char *s = readline(f);
	if(s == NULL)
		return 1;

	printf("%s\n", s);

	fclose(f);
	free(s);

	return 0;
}