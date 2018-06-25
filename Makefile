EXEC = pruebas
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes
CFILES = pruebas.c strutil.c

all:
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC)
