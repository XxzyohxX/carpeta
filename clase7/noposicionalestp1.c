#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {CICLOS, LOG, _LAST};

const char *diccionario[] = {
    "-ciclos",
    "-log",
};


int main(int argc, char *argv[]) {
    bool flags[_LAST] = {0};

    if(argc == 1) {
        printf("Uso:\n");
        for(size_t i = 0; i < _LAST; i++)
            printf("\t%s %s\n", argv[0], diccionario[i]);
        return 1;
    }


    for(size_t i = 1; i < argc; i++) {
        for(size_t j = 0; j < _LAST; j++)
            if(!strcmp(argv[i], diccionario[j])) {
                flags[j] = true;
            }
    }


    if(flags[LOG]) {
        printf("Me pidieron que ordenara por tiempo...\n");
    }

    return 0;

}
