#include "holberton.h"
/**
 * _puts - put string
 * @str: input string
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}

/**
 * _fputs - put string
 * @fd: file descriptor
 * @str: input string
 */
void _fputs(int fd, char *str)
{
	int s_idx;

	s_idx = 0;
	while (str[s_idx])
	{
		s_idx++;
	}
	write(fd, str, s_idx);
}
