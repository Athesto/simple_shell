#include "../holberton.h"

int main(void)
{
	_fputs(STDOUT_FILENO, "message\n");
	_fputs(STDERR_FILENO, "ERROR MESSAGE\n");
	return (0);
}