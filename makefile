CC = gcc
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
OUTPUT = outputFile
SRCS= main.c extra.c
HEADERS = extra.h

$(OUTPUT): $(SRCS) $(HEADERS)
	$(CC) -o $@ $^ $(CFLAGS)

all: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)
