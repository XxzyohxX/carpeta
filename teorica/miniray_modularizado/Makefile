PROGRAM=miniray
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
LDFLAGS=-lm

all: $(PROGRAM)

$(PROGRAM): miniray.o vec3.o
	$(CC) $(CFLAGS) $(LDFLAGS) miniray.o vec3.o -o $(PROGRAM)

miniray.o: miniray.c vec3.h
	$(CC) $(CFLAGS) -c miniray.c

vec3.o: vec3.c vec3.h
	$(CC) $(CFLAGS) -c vec3.c

clean:
	rm -vf *.o $(PROGRAM)
