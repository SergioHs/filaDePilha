# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -03 gcc version
CFLAGS  = -g -Wall -O3

default: main

fila.o: fila.c fila_publico.h fila_privado.h
	$(CC) $(CFLAGS) -c fila.c -o fila.o

pilha.o: pilha.c pilha_publico.h pilha_privado.h
	$(CC) $(CFLAGS) -c pilha.c -o pilha.o

filaPilha.o: filaPilha.c filaPilha_publico.h filaPilha_privado.h
	$(CC) $(CFLAGS) -c filaPilha.c -o filaPilha.o

main: main.c fila.o pilha.o filaPilha.o
	$(CC) $(CFLAGS) main.c fila.o pilha.o filaPilha.o -o main

run: clean main
	./main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main