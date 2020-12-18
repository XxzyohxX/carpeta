#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

char *join(char *strs[],size_t n, char delim){
    size_t longitud = 0;
    for(size_t i = 0; i < n; i++)
        longitud += strlen(strs[i]);
    longitud += n;

    char *s = malloc(longitud * sizeof(char));
    if(s == NULL)
        return NULL;

    strcpy(s, strs[0]);
    size_t pos = strlen(s);
    for(size_t i = 1; i < n; i++){
        s[pos++] = delim;
        strcpy(s + pos, strs[i]);
        pos += strlen(strs[i]);
    }

    return s;
}


int main(){
	char *a = join(("hola", "que", "tal"), 3,'');
	printf("%s\n", a);
  return 0;
}
