#ifndef _HSH_H_
#define _HSH_H_
#include <stdio.h> /* printf/puts */
#include <stdlib.h> /* malloc/free/exit */
#include <unistd.h> /* access/execve/fork/isatty */
#include <sys/wait.h> /* wait  */

#define MAGENTA "\033[35m"
#define RSTFMT "\033[0m"
#define PROMPT MAGENTA "jgsh$ " RSTFMT

extern char **environ;

char *_getenv(const char *);
int _loop(char **);
int _runcmd(char const *, char *const *);
void _siginthandler(int);
int _strcmp(const char *, const char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
int _strncmp(const char *, const char *, size_t);
char *_strtok(char *, const char *);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t _strlen(const char *);
char *_which(char *);
char **_strsplit(char *);

#endif /* _HSH_H_ */
