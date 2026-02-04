CC = gcc
CFLAGS = -Wall -FPIC

app: libmath.so main.o helper.o 
	$(CC) main.c -L. libmath.so -o app

libmath.so:
	$(CC) -fPIC -shared helper.c -o libmath.so

main.o:
	$(CC) -c main.c -L. libmath.so -o main.o

run:
	LD_LIBRARY_PATH=. ./app

clear:
	rm -f *.so *.o app

