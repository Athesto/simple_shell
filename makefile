flags=-g -Wall -Wextra -Werror -pedantic
mainpath=test/main.c
header=
args=
out_file=hsh

%:
	@test ! -e $(out_file) || rm $(out_file)			#if $(out_file) exist, delete it
	betty *.c $(mainpath) $(header)
	#Use as argument: run=v for run (v)algrind with the program or run=g for (g)db
	gcc $(flags) *.c $(mainpath) -o $(out_file)
	@if [ "$(run)" = "v" ]; then \
		echo valgrind ./$(out_file) $(args); \
		valgrind ./$(out_file) $(args); \
	elif [ "$(run)" = "g" ]; then \
		echo gdb --args ./$(out_file) $(args); \
		gdb --args ./$(out_file) $(args); \
	else \
		echo ./$(out_file) $(args); \
		./$(out_file) $(args); \
	fi

c:
	clear

clear:
	@test ! -e $(out_file) || rm $(out_file)			#if $(out_file) exist, delete it

1: mainpath=test/main.c

man:
	clear
	man ./man_shell
