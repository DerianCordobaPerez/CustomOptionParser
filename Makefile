PROGRAM_NAME=custom_option_parser
OUTPUT_BIN=bin/$(PROGRAM_NAME)
CC=gcc
CFLAGS=-O3 -Wall
LIBS=-fsanitize=address

app: app.c
	$(CC) -o $(OUTPUT_BIN) app.c $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OUTPUT_BIN)