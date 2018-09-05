CC = cc
CFLAGS = -Wall -g

all: ex1

ex1: ex1.o
	$(CC) $(CFLAGS) ex1.o -o ex1

ex1.o: ex1.c
	$(CC) $(CFLAGS) -c ex1.c

clean:
	rm -rf ex1 ex1.o *.dSYM

.PHONY: all clean
