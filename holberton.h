#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>	/* malloc, exit, free */
#include <stdio.h>	/* getline, stdin */
#include <sys/types.h> /* ssize_t */
#include <sys/wait.h> /* wait */
#include <unistd.h>  /* size_t, write */
#include <string.h> /* strtok */
#include <signal.h> /* signal */
#include <sys/stat.h> /* stat */
#include <limits.h> /* MIN_INT */
#include <errno.h>
extern char **environ;

typedef struct stat stat_t;

/**
 * struct builtins - commands
 * @cmd: command;
 * @cmd_f: command funtion;
 */
typedef struct builtins
{
	const char *cmd;
	int (*cmd_f)(char **args);
} builtins_t;

int _getline(char **lineptr, size_t *n, FILE *stream);
void _puts(char *str);
void _fputs(int fd, char *str);
int _putchar(char c);
char *_getpath(void);
int exec_cmd(char *cmd, char **args);
int loop(char *argv);
void handler(int);
int get_env(char **nothing);
int get_exit(char **args);
int _operator(char **args);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
int isanum(char *str);
unsigned int _strspn(char *s, char *accept);
int _atoi(char *str);
char *strcatnum(char *str, int num);
#endif /* _HOLBERTON_H_ */
