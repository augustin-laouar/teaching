CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iheaders
LDFLAGS = -lncurses

SRC = main.c src/editor.c src/buffer.c src/io.c src/render.c src/input.c src/test_utils.c
TARGET = nano_nano

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)