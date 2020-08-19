#include <stdio.h>
int main(int argc, char *argv[], char *env[])
{
	extern char **environ;
	int i;

	i = 0;
	while(env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	puts("\n\n\n\n\n==============\n\n\n\n");
	i = 0;
	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	(void)argc;
	(void)argv;
	return (0);
}
