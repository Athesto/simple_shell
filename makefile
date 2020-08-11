flags=-g -Wall -Wextra -Werror -pedantic
header=holberton.h
args=
in_files=*.c
out_file=hsh
run=

1:
2: in_files=test/main.c
3: in_files=_getline.c test/test_getline.c

%:
	@test ! -e $(out_file) || rm $(out_file)			#if $(out_file) exist, delete it
	betty $(in_files) $(header)
	#Use as argument: run=v for run (v)algrind with the program or run=g for (g)db
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
