#include "shell.h"

/**
 *_eputs - This mainly prints an input string in the program
 * @str: This collect or house the string to be printed in the program
 *
 * Author: Kingsley Chika CHUKWU and Kofoworola M.
 * Date: 5th of May 2023
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int d = 0;

	if (!str)
		return;
	while (str[d] != '\0')
	{
		_eputchar(str[d]);
		d++;
	}
}

/**
 * _eputchar - This majorly writes the character c program
 * @p: The character to be printed i nthe program
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set approprate
 */
int _eputchar(char p)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (p == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(2, buf, d);
		d = 0;
	}
	if (p != BUF_FLUSH)
		buf[d++] = p;
	return (1);
}

/**
 * _putfdec - This writes the character c to given File descriptor
 * @p: This is the character to be printed
 * @fdec: The filedescriptor to write to in the program
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfdec(char p, int fdec)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (p == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(fdec, buf, d);
		d = 0;
	}
	if (p != BUF_FLUSH)
		buf[d++] = p;
	return (1);
}

/**
 *_putsfdec - This majorly prints an input string in the program
 * @str: this is string to be printed
 * @fdec: the filedescriptor to write to in the code
 *
 * Return: the number of chars put
 */
int _putsfdec(char *str, int fdec)
{
	int d = 0;

	if (!str)
		return (0);
	while (*str)
	{
		d += _putfdec(*str++, fdec);
	}
	return (i);
}
