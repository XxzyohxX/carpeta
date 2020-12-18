CFLAGS=-g -Wall -pedantic -std=c99
LFLAGS=-lm



instrucciones.o: instruccionestp.c instruccionestp.h ej3.h estructuras.h
	gcc instruccionestp.c -c $(CFLAGS)

ej3.o: ej3.c ej3.h
	gcc ej3.c -c $(CFLAGS)

clean:
	rm *.o