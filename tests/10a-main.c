#include "../hsh.h"
#include <limits.h>
/**
 * main - test of _atoi min to max
 * Return: 0
 */
int main(void)
{
	char *str;

	str = "2147483647";
	if (atoi(str) != _atoi(str))
		printf("ERROR: MAX\n");

	str = "10";
	if (atoi(str) != _atoi(str))
		printf("ERROR: poitive\n");

	str = "5";
	if (atoi(str) != _atoi(str))
		printf("ERROR: poitive\n");

	str = "0";
	if (atoi(str) != _atoi(str))
		printf("ERROR: negative\n");

	str = "-5";
	if (atoi(str) != _atoi(str))
		printf("ERROR: negative\n");

	str = "-10";
	if (atoi(str) != _atoi(str))
		printf("ERROR: negative\n");

	str = "-2147483648";
	if (atoi(str) != _atoi(str))
		printf("ERROR: MIN\n");

	return (0);
}
