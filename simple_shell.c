#include "holberton.h"
#define TRUE 1
#define MAGENTA "\033[35m"
#define RSTFMT "\033[0m"
#define PROMPT MAGENTA "#jgsh$ " RSTFMT

char *strcatnum(char *str, int num);
/**
 * main - basic shell
 * @argc: argument counter
 * @argv: argument values
 * Return: ?
 */
int main(int argc, char *argv[])
{
	/* Redirect Interrupt signal to handler function */
	signal(SIGINT, handler);

	loop(argv[0]); /*infinite command loop*/
	(void)argc;
	return (EXIT_SUCCESS);
}

#define BUFSIZE 1
#define NARGS 16
#define SPLITCHARS " \t"
/**
 * loop - shell loop
 * @shellname: name of shell
 */
void loop(char *shellname)
{
	char *line;			/* Line pointer for getline funct */
	char **args;		/* List of Arguments */
	int i;				/* Arguments' counter */
	size_t bufsize = BUFSIZE; /* Size of buffer (line) */
	ssize_t nbytes;		/* Number of bytes for getline funct */
	char *PS1 = PROMPT;	/* Char variable for prompt */
	int counter = 0;	/* loop counter */
	char errmsg[64];	/* error message */
	pid_t child_pid;
	int istty;

	/* Allocate memory for listing arguments */
	args = malloc(NARGS * sizeof(*args));
	/* Allocate memory for input data */
	line = malloc(bufsize * sizeof(*line));

	while (TRUE) /* Infinite while */
	{
		counter++;
		istty = isatty(STDIN_FILENO);
		if (istty == 1)
			_puts(PS1); /* Print prompt */

		/* Get the number of bytes from getline */
		nbytes = getline(&line, &bufsize, stdin);
		if (nbytes == EOF) /* Checking for <C-d> */
		{
			if (istty == 1)
				_putchar('\n'); /* go to new line */
			break;			/* Exit infinite while */
		}
		line[nbytes - 1] = 0; /* Removing '\n' */
		/* printf("(%d) %s\n", (int)nbytes, line); */

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
			if (args && *args && _strcmp(args[0], "exit") == 0)
				exit(EXIT_SUCCESS);
		}
		else if (child_pid == 0)
		{
			if (exec_cmd(args[0], args) == -1)
			{
				_strcat(errmsg, shellname);
				_strcat(errmsg, ": ");
				strcatnum(errmsg, counter);
				_strcat(errmsg, ": ");
				_strcat(errmsg, args[0]);
				_strcat(errmsg, ": not found\n");
				_fputs(STDERR_FILENO, errmsg);
				/*fprintf(stderr, "%s", errmsg);*/

				exit(EXIT_FAILURE);
			}
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

/**
 * strcatnum - concat int number in string
 * @str: destination string
 * @num: source integer
 * Return: pointer to destination string
 */
char *strcatnum(char *str, int num)
{
	int s_idx = 0;
	int tens = 1;
	unsigned int tmp;

	while (str[s_idx])
		s_idx++;

	if (num < 0)
	{
		str[s_idx] = '-';
		num = -num;
	}
	tmp = num;
	if (num == INT_MIN)
	{
		tmp++;
	}
	while (tmp > 9)
	{
		tens = tens * 10;
		tmp = tmp / 10;
	}

	tmp = num;
	while (tens > 0)
	{
		str[s_idx] = ('0' + tmp / tens);
		s_idx++;
		tmp %= tens;
		tens /= 10;
	}

	return (str);
}
