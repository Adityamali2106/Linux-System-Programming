CC = gcc

Myexe: LibAddition.so LibSubstraction.so
	$(CC) program07_2.c -L. -o Myexe

LibAddition.so:
	$(CC) -fPIC -shared LibAddition.c -o LibAddition.so

LibSubstraction.so:
	$(CC) -fPIC -shared LibSubstraction.c -o LibSubstraction.so

clear:
	rm *.so Myexe
run:
	./Myexe