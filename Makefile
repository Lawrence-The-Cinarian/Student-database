CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/flush.c src/main.c src/database.c
OBJ = $(SRC:.c=.o)
TARGET = out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
