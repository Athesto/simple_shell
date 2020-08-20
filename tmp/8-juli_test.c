#include "../holberton.h"

char *error_m(int status);
/**
 * main - error funtions;
 */
int main (void)
{
char *argv[] = { "/bin/ls", "lnkh" };
	pid_t my_pid;
	int status;
	int val;

	my_pid = fork();
	if (my_pid == 0) /* child process*/
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		val = waitpid(my_pid, &status, WCONTINUED | WUNTRACED);
		printf("1.out wait: %i\n", val);
		val = WEXITSTATUS(status);
		printf("2.val: %i\n", val);
		printf("3.Exit status: %d\n", WEXITSTATUS(status));
	}
	if (WEXITSTATUS(status) == ENOENT)
	{
		printf("Aqui\n");
	}
	printf("hello\n");
	

	return (0);
}

char *error_m(int status)
{
	/* ./hsh: 2: asf: not found (127) */ 
	/* /bin/sh: 1: exit: Illegal number: asdfasdfafadf (2) */

	/* %s: %d: %s: not found */
	/* %s: %d: exit: Illegal number: %s */
	
	char buf[129] = "error: msg";
	(void)status;
	(void)buf;
	return (NULL);
}

/**
	if (args == 2)
	{

	}
	if (args == 127)
	{
		notfound(args);
	}

 wait(0);
			if (args && *args && _strcmp(args[0], "exit") == 0)
			{
				if (!args[1])
				{
					free(args);
					exit(EXIT_SUCCESS);
				}
				error_m(args);
			}
*/
/**
int notfound()
{
	char *errmsg[60];

	_strcat(errmsg, shellname);
	_strcat(errmsg, ": ");
	strcatnum(errmsg, counter);
	_strcat(errmsg, ": ");
	_strcat(errmsg, args[0]);
	_strcat(errmsg, ": not found\n");
	_fputs(STDERR_FILENO, errmsg);
}
*/
