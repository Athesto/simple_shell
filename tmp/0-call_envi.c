#include <stdio.h>
void printenv();

int main(int c, char **v, char **e)
{
	printf("%p\n", e);
	printenv();
	(void) c;
	(void) v;
	return (0);
}

void printenv(void)
{
	extern char **environ;
	char **ptr = environ;

	printf("%p\n", environ);
	while(*ptr)
	{
		puts(*ptr);
		ptr++;
	}
}