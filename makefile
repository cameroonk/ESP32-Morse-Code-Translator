CC = gcc
CFLAGS = -g
OBJ = tests.o

tests: tests/tests.c
	$(CC) -o tests/tests.c tests.o

