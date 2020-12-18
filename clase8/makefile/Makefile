CC=gcc
CFLAGS=-Wall -ansi -pedantic -O3 -c
LFLAGS=-Wall
DEBUG=-g

all: app

app: main.o netpbm.o color.o
	$(CC) $(LFLAGS) $(DEBUG) -o app main.o netpbm.o color.o

main.o: main.c color.h netpbm.h
	$(CC) $(CFLAGS) $(DEBUG) -o main.o main.c

netpbm.o: netpbm.c netpbm.h netpbm_private.h
	$(CC) $(CFLAGS) $(DEBUG) -o netpbm.o netpbm.c

color.o: color.c color.h common.h 
	$(CC) $(CFLAGS) $(DEBUG) -o color.o color.c

color.h: common.h

netpbm.h: color.h

netpbm_private.h: netpbm.h

clean:
	rm *.o
