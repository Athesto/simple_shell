#include <stdio.h>
#include "../holberton.h"

int main(void)
{
	char *args1[] = 
	{
		"exit",
		""
	};
	char *args2[] = 
	{
		"env", 
		""
	};

	_operator(args2);
	puts("============");

	_operator(args1);
	puts("hello");

	return (0);
}
