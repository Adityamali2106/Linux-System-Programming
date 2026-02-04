CC = gcc
AR = ar

app: libmath.a main.o helper.o 
	$(CC) main.o libmath.a -o app

libmath.a:	helper.o
	$(AR) rcs libmath.a helper.o

main.o:
	$(CC) -c main.c -L. libmath.a -o main.o

helper.o:
	$(CC) -c helper.c -o helper.o

run:
	./app

clear:
	rm *.a *.o app

