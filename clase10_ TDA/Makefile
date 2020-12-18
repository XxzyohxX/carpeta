CFLAGS=-g -Wall -pedantic -std=c99
LFLAGS=-lm

all:vector

vector: vector.o vector_barbara.o
	gcc $(CFLAGS) $(LFLAGS) vector.o vector_barbara.o -o vector

vector.o: vector.c vector.h
	gcc $(CFLAGS) -c vector.c

vector_barbara.o: vector_barbara.c vector.h
	gcc $(CFLAGS) -c vector_barbara.c