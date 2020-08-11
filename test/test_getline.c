#include "../holberton.h"
#define BUFSIZE 1024
/**
 * main - test getline
 * Return: 0 Success
 */
int main(void)
{
	char *buffer; /* We create Buffer, size for the entry parameters for _getline */
	size_t size = BUFSIZE; /* BUFSIZE is size 1024 asigned to variable size */
	size_t charct;

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("ERROR: Unabled to allocate memory");
		exit(1);
	}

	printf(">$ ");
	charct = _getline(&buffer, &size, stdin);
	printf("the characters printed are %u.\n", (unsigned int) charct);
	printf("type: %s", buffer);

	return (0);
}
