#include "holberton.h"
#define TRUE 1
#define MAGENTA "\033[35m"
#define RESETFMT "\033[0m"
#define PROMPT MAGENTA"#jgsh$ "RESETFMT
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

#define BUFSIZE 1
#define nargs 16
#define splitchars " \t"
/**
 * loop - shell loop
 */
void loop(void)
{

	char *line;
	char **args;
	size_t n = BUFSIZE;
	int i;
	ssize_t nbytes;
	char *PS1 = PROMPT; /* prompt */


	args = malloc(nargs * sizeof(*args));

	line = malloc(n * sizeof(*line));
	while (TRUE)
	{
		_puts(PS1);
		nbytes = getline(&line, &n, stdin);
		if (nbytes == EOF)
		{
			_putchar('\n');
			break;
		}
		line[nbytes - 1] = 0;
		printf("(%d) %s\n", (int)nbytes, line);

		/* cmd */
		args[0] = strtok(line, splitchars);

		i = 1;
		while ((args[i] = strtok(NULL, splitchars)) != NULL)
		{
			i++;
		}
		i = 0;
		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}
	}
	free(line);
	free(args);
	(void)args;
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
