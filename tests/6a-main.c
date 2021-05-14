#include "../hsh.h"
#include <string.h>

/**
 * main - test of _strcpy
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *msg = "betty-holberton";
	char copy[10];

	_strcpy(copy, msg);

	printf("%ld %s\n", _strlen(msg), msg);
	strcpy(copy, msg);
	printf("%ld %s\n", _strlen(msg), msg);
	return (0);
}
