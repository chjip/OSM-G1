CC=gcc
CFLAGS=-g -pedantic -std=c99 -Wall -Wextra

calc: stack.o calc.o
	$(CC) $(CFLAGS) list.o calc.o stack.o -o calc

listtest: list.o test.c
	$(CC) $(CFLAGS) list.o -o listtest test.c

calc.o: calc.c stack.h
	$(CC) $(CFLAGS) -c calc.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

stack.o: list.o stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o
	rm -f calc
	rm -f listtest

all: calc

