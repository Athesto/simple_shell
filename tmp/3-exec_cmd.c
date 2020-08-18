#include "../holberton.h"
int exec_cmd(char *cmd, char **args);
/**
 * main - ?
 * Return: ?
 */
int main(void)
{
        char *cmds[] = {"ls", "-l"};
        exec_cmd(cmds[0],cmds);
        return (0);
}
