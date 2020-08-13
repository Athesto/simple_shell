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

	loop(); /*infinite command loop*/

	return (EXIT_SUCCESS);
}

#define BUFSIZE 1
#define NARGS 16
#define SPLITCHARS " \t"
/**
 * loop - shell loop
 */
void loop(void)
{
	char *line; /* Line pointer for getline funct */
	char **args; /* Arguments variable */
	size_t bufsize = BUFSIZE; /*Variable size of buffer*/
	int i;
	ssize_t nbytes; /* Number of bytes for getline funct */
	char *PS1 = PROMPT; /* Char variable for prompt */
	

	/* Allocate memory for listing arguments */
	args = malloc(NARGS * sizeof(*args));
	/* Allocate memory for input data */
	line = malloc(bufsize * sizeof(*line));

	while (TRUE) /* Infinite while */
	{
		_puts(PS1); /* Print prompt */

		/* Get the number of bytes from getline */
		nbytes = getline(&line, &bufsize, stdin);
		if (nbytes == EOF) /* Checking for <C-d> */
		{
			_putchar('\n'); /* go to new line */
			break; /* Exit infinite while */
		}
		line[nbytes - 1] = 0; /* Removing '\n' */
		printf("(%d) %s\n", (int)nbytes, line);

		/* args[0] pointing to the input program */
		args[0] = strtok(line, SPLITCHARS);

		i = 1; /* starting from arg 1 */
		/* args array pointng to the program arguments */
		while ((args[i] = strtok(NULL, SPLITCHARS)) != NULL)
		{
			i++; /* Increasing step */
		}

		child_pid = fork();
		if (child_pid > 0)
		{
			wait(0);
		}
		else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror();
			}
			
		}
		


		/* Printing arguments if it exist */
		i = 0;
		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}
	}
	free(line);
	free(args); /* Free malloc */
	(void)args;
}
/**
 * handler - Interruption routine
 * @num: unused variable
 */
void handler(int num)
{
	char *PS1 = PROMPT; /* prompt */

	_putchar('\n');
	_puts(PS1);
	(void)num;
}
