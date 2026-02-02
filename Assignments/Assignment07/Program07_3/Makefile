CC = gcc

Myexe: LibDisplay.so
	$(CC) program07_3.c -L. -o Myexe

LibDisplay.so:
	$(CC) -fPIC -shared LibDisplay.c -o LibDisplay.so

clear:
	rm *.so Myexe

run:
	./Myexe