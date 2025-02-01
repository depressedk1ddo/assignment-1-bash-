CC=gcc
CROSS_COMPILE ?=
CFLAGS=-Wall -Werror
TARGET=writer

all: $(TARGET)

$(TARGET): writer.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o $(TARGET) writer.c

clean:
	rm -f $(TARGET) *.o
