CC = cc
CFLAGS = -Wall

all: qrwpa

qrwpa: qr.c qrwpa.c
	$(CC) $(CFLAGS) -o qrwpa qr.c qrwpa.c
