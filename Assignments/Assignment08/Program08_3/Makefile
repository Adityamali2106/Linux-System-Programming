CC = gcc

app: main.o
	$(CC) main.o -o app

main.o:
	$(CC) -c main.c

clear:
	rm app

run:
	./app

help:
	@echo "Usage: "
	@echo "To run the application just write command as 'make'"
	@echo "To run the appliccation write command ans "make run""
	@echo "To clean the executable and .o files hit command as 'make clear' "
