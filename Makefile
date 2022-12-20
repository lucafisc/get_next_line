FILES = get_next_line.c get_next_line_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
B_SIZE = 800
OUTPUT = get_next_line.out

all: $(OBJECTS)
	$(CC) -D BUFFER_SIZE=$(B_SIZE) $(CFLAGS) $(FILES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

re: clean all
