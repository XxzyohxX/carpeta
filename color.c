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

char **leer_lineas(size_t *n) {
   *n = 0;

   char aux[MAX_STR];
   size_t i = 0;
   char **ss = NULL;

   while(fgets(aux, MAX_STR, stdin) != NULL) {
      char **auxaux = realloc(ss, (i + 1) * sizeof(char *));
      if(auxaux == NULL) {
          liberar_lineas(ss, i);
          return NULL;
      }
      ss = auxaux;

      ss[i] = malloc((strlen(aux) + 1) * sizeof(char));
      if(ss[i] == NULL) {
          liberar_lineas(ss, i);
          return NULL;
      }

      strcpy(ss[i], aux);
      i++;
   }

   *n = i;
   return ss;
}




int main(){
  return 0;
}