flags=-g -Wall -Wextra -Werror -pedantic
header=holberton.h
args=
in_files=*.c
out_file=hsh
run=

build:
	@test ! -e $(out_file) || rm $(out_file)			#if $(out_file) exist, delete it
	betty $(in_files) $(header)
	gcc $(flags) $(in_files) -o $(out_file)
	@if [ "$(run)" = "v" ]; then \
		echo valgrind ./$(out_file) $(args); \
		valgrind ./$(out_file) $(args); \
	elif [ "$(run)" = "g" ]; then \
		echo gdb --args ./$(out_file) $(args); \
		gdb --args ./$(out_file) $(args); \
	elif [ "$(run)" = "norun" ]; then \
		exit 0; \
	else \
		echo ./$(out_file) $(args); \
		./$(out_file) $(args); \
	fi

c:
	clear

clear:
	@test ! -e $(out_file) || rm $(out_file)			#if $(out_file) exist, delete it

man:
	clear
	man ./man_shell
