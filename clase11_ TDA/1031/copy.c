#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Uso: %s <origen> <destino>\n", argv[0]);
        return 1;
    }

    FILE *fi, *fo;

    fi = fopen(argv[1], "rb");
    if(fi == NULL) {
        fprintf(stderr, "No se puede abrir %s\n", argv[1]);
        return 1;
    }

    fo = fopen(argv[2], "wb");
    if(fo == NULL) {
        fclose(fi);
        fprintf(stderr, "No se puede abrir %s\n", argv[2]);
        return 1;
    }

    int c;
    while((c = fgetc(fi)) != EOF) {
        fputc(c, fo);
    }

    fclose(fi);
    if(fclose(fo) == EOF) {
        fprintf(stderr, "Hubo algun error con el archivo de salida\n"); 
        return 1;
    }

    return 0;
}
