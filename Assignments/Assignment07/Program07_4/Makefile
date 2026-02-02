CC = gcc

Myexe: LibDisplay.so
	$(CC) program07_4.c -L. -o Myexe

LibDisplay.so:
	$(CC) -fPIC -shared LibMystrlen.c -o LibMystrlen.so

clear:
	rm *.so Myexe

run:
	./Myexe