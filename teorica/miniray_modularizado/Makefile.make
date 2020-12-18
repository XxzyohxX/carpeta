PROGRAM=instrucciones
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
LDFLAGS=-lm

all: $(PROGRAM)

$(PROGRAM): instrucciones.o ej3.o diccionario.o direccionamiento.o ejecutar.o
	$(CC) $(CFLAGS) instrucciones.o ej3.o -o $(PROGRAM)

direccionamiento.o: direccionamiento.c direccionamiento.h
	$(CC) $(CFLAGS) -c direccionamiento.c

ejecutar.o: ejecutar.c diccionario.c
	$(CC) $(CFLAGS) -c ejecutar.c 

diccionario.o: diccionario.c instrucciones.h ej3.h direccionamiento.h
	$(CC) $(CFLAGS) -c diccionario.c

instrucciones.o: instrucciones.c instrucciones.h ej3.h
	$(CC) $(CFLAGS) -c instrucciones.c

ej3.o: ej3.c ej3.h
	$(CC) $(CFLAGS) -c ej3.c 