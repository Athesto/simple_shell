#include "../hsh.h"
#include <string.h>

/**
 * main - test of _strlen, empty string
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *msg = "";
	int a;
	int b;

	a = strlen(msg);
	b = _strlen(msg);
	if (a != b)
		perror("ERROR: strlen not equal");
	return (0);
}
