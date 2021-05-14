#include "../hsh.h"
#include <string.h>

/**
 * main - test of _strcmp
 * Return: always 0
 */

int main(void)
{
	char *msg1;
	char *msg2;
	int a, _a;


	msg1 = msg2 = "betty";
	a = strcmp(msg1, msg2);
	_a = _strcmp(msg1, msg2);
	printf("equals: %s\n", (a == _a) ? "OK" : "KO");

	msg1 = "betty";
	msg2 = "be";
	a = strcmp(msg1, msg2);
	_a = _strcmp(msg1, msg2);
	printf("m1 > m2: %s\n", (a == _a) ? "OK" : "KO");

	msg1 = "betty";
	msg2 = "betty-holberton";
	a = strcmp(msg1, msg2);
	_a = _strcmp(msg1, msg2);
	printf("m1 < m2: %s\n", (a == _a) ? "OK" : "KO");


	return (0);
}
