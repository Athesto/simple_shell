#include "../hsh.h"
#include <string.h>
#define LEN 999

/**
 * main - test of _strlen, 999 char len
 * Return: always 0
 */

int main(void)
{
	char msg[LEN];
	int i;

	for (i = 0; i < LEN; i++)
		msg[i] = '@';
	msg[i] = '\0';

	if (strlen(msg) != _strlen(msg))
		perror("ERROR: _strlen -> 999");
	return (0);
}
