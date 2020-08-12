#include "holberton.h"
#define TRUE 1
void loop(void);
/**
 * main - basic shell
 * Return: ?
 */
int main(void)
{
	loop(); /*infinitive command loop*/

	return (EXIT_SUCCESS);
}
/**
 * loop - shell loop
 */
void loop(void)
{
	char *PS1 = "#jgsh$ "; /* prompt */

	char *line;
	size_t n = 1024;
	ssize_t nbytes;

	line = malloc(32);

	while (TRUE)
	{
		_puts(PS1);
		nbytes = getline(&line, &n, stdin);
		if (nbytes == EOF)
			break;
		printf("(%d) %s\n", (int)nbytes, line);
	}

	free(line);
}
