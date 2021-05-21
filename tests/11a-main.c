#include "../hsh.h"
void set1(void);
void set2(void);
/**
 * main - test of _strclear2
 * Return: 0
 */
int main(void)
{
	set1();
	set2();

	return (0);
}
/**
 * set1 - test 1
 *
 */
void set1(void)
{
	char str[100];


	_strcpy(str, "hello");
	_strclear2(str);
	if (_strcmp(str, "hello"))
		printf("ERROR: idieal case [%s]\n", str);

	_strcpy(str, "    d");
	_strclear2(str);
	if (_strcmp(str, "d"))
		printf("ERROR: before space [%s]\n", str);

	_strcpy(str, "d   ");
	_strclear2(str);
	if (_strcmp(str, "d"))
		printf("ERROR: tailing space [%s]\n", str);

	_strcpy(str, " betty holberton welcome ");
	_strclear2(str);
	if (_strcmp(str, "betty holberton welcome"))
		printf("ERROR: 3 words [%s]\n", str);

	_strcpy(str, "hello\tworld\tbetty");
	_strclear2(str);
	if (_strcmp(str, "hello world betty"))
		printf("ERROR: 3 words tab case [%s]\n", str);

}

/**
 * set2 - test 2
 *
 */
void set2(void)
{
	char str[100];


	_strcpy(str, "\thello\tworld\tbetty\t");
	_strclear2(str);
	if (_strcmp(str, "hello world betty"))
		printf("ERROR: 3 words tab case [%s]\n", str);

	_strcpy(str, "hello            world              betty");
	_strclear2(str);
	if (_strcmp(str, "hello world betty"))
		printf("ERROR: middle case [%s]\n", str);

	_strcpy(str, "  \t\t     hello \t \t \t \t \t \t world               ");
	_strclear2(str);
	if (_strcmp(str, "hello world"))
		printf("ERROR: beginer space [%s]\n", str);

	_strcpy(str, "     \t \t \t  hello       world         betty\t\t\t    ");
	_strclear2(str);
	if (_strcmp(str, "hello world betty"))
		printf("ERROR: tailing space [%s]\n", str);
}

