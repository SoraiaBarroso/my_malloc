CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SOURCE = utility.c my_realloc.c my_calloc.c my_free.c main.c my_malloc.c my_malloc.h
TARGET = my_malloc

all : $(TARGET)

$(TARGET) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
