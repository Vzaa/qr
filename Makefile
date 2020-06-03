CC = gcc
CFLAGS = -std=c99 -pedantic -Wall

all: qrwpa

qrwpa: qr.c qrwpa.c
	$(CC) $(CFLAGS) -o qrwpa qrwpa.c qr.c
