CC = cc
CFLAGS = -Wall -g
OBJECTS = main.o printBoard.o handleBoard.o connectFour.o

all: ex2

ex2: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o ex2
	rm -rf *.o

%.o : %.c
	$(CC) $(CFLAGS) -c $<

%.c : %.h

clean:
	rm -rf ex2 *.dSYM

.PHONY: all clean
