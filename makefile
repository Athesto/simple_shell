flags=-g -Wall -Wextra -Werror -pedantic
mainpath=test/main.c
header=
args=

%:
	@test ! -e a.out || rm a.out		#if a.out exist, delete it
	betty *.c $(mainpath) $(header)
	gcc $(flags) *.c $(mainpath)
	./a.out

v:
	valgrind ./a.out $(args)

g:
	gdb ./a.out $(args)

c:
	clear

clear:
	rm a.out

1: mainpath=test/main.c

man:
	clear
	man ./man_shell
