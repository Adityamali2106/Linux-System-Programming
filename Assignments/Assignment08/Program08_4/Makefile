CC = gcc
CFLAGS = -Wall -Wextra -O2

app: main.o helper.o
	$(CC) main.o helper.o -o app 

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c -w

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c	

help:
	@echo "Usage: "
	@echo "To run the application just write command as 'make'"
	@echo "To run the appliccation write command ans "make run""
	@echo "To clean the executable and .o files hit command as 'make clear' " 

run:
	./app

clear:
	rm -f *.o app

.PHONY: clear
