#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>	/* malloc, exit */
#include <stdio.h>	/* printf, getline, stdin */
#include <sys/types.h>
#include <sys/wait.h>

int _getline(char **lineptr, size_t *n, FILE *stream);
void _puts(char *str);
int _putchar(char c);
#endif /* _HOLBERTON_H_ */
