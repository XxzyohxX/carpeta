CFLAGS=-g -Wall -pedantic -std=c99 -O3
LFLAGS=-lm

all: main_en main_es

main_en: main.o mensajes_en.o
	gcc main.o mensajes_en.o -o main_en $(LFLAGS)

main_es: main.o mensajes_es.o
	gcc main.o mensajes_es.o -o main_es $(LFLAGS)

main.o: main.c mensajes.h
	gcc main.c -c $(CFLAGS)

mensajes_en.o: mensajes_en.c mensajes.h
	gcc mensajes_en.c -c $(CFLAGS)

mensajes_es.o: mensajes_es.c mensajes.h
	gcc mensajes_es.c -c $(CFLAGS)

clean:
	rm *.o
