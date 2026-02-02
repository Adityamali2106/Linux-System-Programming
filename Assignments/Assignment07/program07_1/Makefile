CC = gcc

Myexe: LibPerfect.so Libhelper.so
	$(CC) Program07_1.c -L. -o Myexe

LibPerfect.so:
	$(CC) -fPIC -shared LibPerfect.c -o LibPerfect.so

Libhelper.so:
	$(CC) -fPIC -shared LibHelper.c -o LibHelper.so

clear:
	rm *.so 

run:
	./Myexe