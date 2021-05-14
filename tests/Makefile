CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pedantic
SRC=$*-*.c ../_*.c
OUT=a.out

%:
	@rm -rf $(OUT)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@valgrind -q ./a.out 1> /dev/null
	@betty-style $(SRC)
	@betty-doc $(SRC) 1> /dev/null

