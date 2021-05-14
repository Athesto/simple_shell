#include "../hsh.h"
#include <string.h>

void test_equals(void);
void test_msg1_less(void);
void test_a_minus(void);
/**
 * main - test of _strncmp
 * Return: always 0
 */

int main(void)
{

	char *msg1;
	char *msg2;
	int a, _a;
	size_t i;

	msg1 = msg2 = "betty";

	for (i = strlen(msg1) - 2; i < strlen(msg2) + 4; i++)
	{
		a = strncmp(msg1, msg2, i);
		_a = _strncmp(msg1, msg2, i);
		if (a != _a)
			printf("equals: %s\n", (a == _a) ? "OK" : "KO");
	}

	msg1 = "betty";
	msg2 = "betty-holberton";
	for (i = strlen(msg1) - 2; i < strlen(msg2) + 4; i++)
	{
		a = strncmp(msg1, msg2, i);
		_a = _strncmp(msg1, msg2, i);

		if (a != _a)
			printf("m1 < m2 n%+ld: %s\n",
					i - strlen(msg1), (a == _a) ? "OK" : "KO");
	}

	msg1 = "betty-holberton";
	msg2 = "betty";
	for (i = strlen(msg2) - 2; i < strlen(msg1) + 4; i++)
	{
		a = strncmp(msg1, msg2, i);
		_a = _strncmp(msg1, msg2, i);

		if (a != _a)
			printf("m1 > m2 n%+ld: %s\n",
					i - strlen(msg2), (a == _a) ? "OK" : "KO");
	}

	return (0);
}

