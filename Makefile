CC = gcc

CFLAGS = -Wall

SOURCE_DIR = ./src
SOURCES = $(SOURCE_DIR)/lexer.c $(SOURCE_DIR)/parser.c $(SOURCE_DIR)/lup.c

INCLUDE_DIR = ./include
INCLUDES = $(INCLUDE_DIR)/lexer.h $(INCLUDE_DIR)/parser.h

all:
	$(CC) -I $(CFLAGS) $(INCLUDES) $(SOURCES) -o lup

clean:
	rm -rf src/*.o
	rm lup


