#include "../holberton.h"
/**
 * main - testing funtion _getpath()
 * Return: Always 0
 */
int main (void)
{
	char *myPATH; 	/* PATH */

	myPATH = _getpath();
	puts(myPATH);
	return (0);
}
