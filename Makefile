CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic
SRC=*.c
OUT=hsh

all:

	@rm -rf $(OUT)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	valgrind -q ./$(OUT)
	@betty-style $(SRC) *.h
	@betty-doc $(SRC) *.h 1> /dev/null

