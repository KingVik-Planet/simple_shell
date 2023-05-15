#include "shell.h"

/**
 * _errsatoi - This majorly converts a string to an integer in the program
 * @t: the string to be converted in the program
 *
 * Date:15thh May 2023
 * Authors: Kingsley and Kofo
 *
 * Return: 0 if no numbers in string,thenthe converted number otherwise
 *       -1 on error
 */
int _errsatoi(char *t)
{
	int d = 0;
	unsigned long int result = 0;

	if (*t == '+')
		t++;  /* FIXME: on this, why does this make main return 255? */
	for (d = 0;  t[d] != '\0'; i++)
	{
		if (t[d] >= '0' && t[d] <= '9')
		{
			result *= 10;
			result += (t[d] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * prints_errors - This mainly prints an error message in the code
 * @info: the parameter & return info structure of the code
 * @estrs: string containing specified errors typeof the code
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on errors
 */
void prints_errors(info_t *info, char *estrs)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estrs);
}

/**
 * prints_ds - This is the function prints a decimal (integer) number (base 10)
 * @input: the input or collect an inputs
 * @fdec: the filedescriptor to write to the code
 *
 * Return: number of characters to be printed
 */
int prints_ds(int input, int fdec)
{
	int (*__putchar)(char) = _putchar;
	int d, count = 0;
	unsigned int _abs_, current;

	if (fdec == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (d = 1000000000; d > 1; d /= 10)
	{
		if (_abs_ / d)
		{
			__putchar('0' + current / d);
			count++;
		}
		current %= d;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_numbers - This is primarily converter function,
 *	a clone of itoa above
 * @numx: The number to be converted
 * @basex: base to be convereted
 * @flags: argument flags where neccessary
 *
 * Return: string
 */
char *convert_numbers(long int numx, int basex, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = numx;

	if (!(flags & CONVERT_UNSIGNED) && numx < 0)
	{
		n = -numx;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % basex];
		n /= basex;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rm_comments - This function replaces first instance of '#' with '\0'in
 * @bufx: This Mainly store and locate address of the string to modify
 *	code perfectly
 *
 * Return: Always 0;
 */
void rm_comments(char *bufx)
{
	int d;

	for (d = 0; bufx[d] != '\0'; d++)
		if (bufx[d] == '#' && (!d || bufx[d - 1] == ' '))
		{
			bufx[d] = '\0';
			break;
		}
}
