#include "holberton.h"
#define TRUE 1
#define PROMPT "\033[35m#jgsh$\033[0m "
void loop(void);
void handler(int);
/**
 * main - basic shell
 * Return: ?
 */
int main(void)
{
	/* Redirect Interrupt signal to handler function */
	signal(SIGINT, handler);

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
/**
 * handler - interruption routine
 * @num: ?
 */
void handler(int num)
{
	char *PS1 = PROMPT; /* prompt */

	_putchar('\n');
	_puts(PS1);
	(void)num;
}
