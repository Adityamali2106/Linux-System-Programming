CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = main.o
TARGET = app

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o:
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	rm $(TARGET)

run:
	./$(TARGET)