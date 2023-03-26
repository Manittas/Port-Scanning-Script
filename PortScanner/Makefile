# Makefile for the Port Scanner script

# Macros
CC = gcc
CFLAGS = -Wall -g
DEPS = Header.h

# Compilation
%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

portscanner: PortScanner.o
		$(CC) -o portscanner PortScanner.o

# Cleans the files created
clean:
		rm -f PortScanner.o portscanner