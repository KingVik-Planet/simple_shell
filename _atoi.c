#include "shell.h"

/**
 * interactive - This program returns true if shell is in the interactive mode.
 * @info: This is the Struecture address of this code
 *
 * Authors: Kingsley and Kofoworola
 * Date: 14th may 2023
 *
 * Return: 1 if the program is in interactive mode, 0 if it is then otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - This Check if character are a delimeter
 * @p: the char to check in the program or code
 * @delim: the delimeter string in the code
 * Return: 1 if it turn out to be true, 0 if it turn out to be false
 */
int is_delim(char p, char *delim)
{
	while (*delim)
		if (*delim++ == p)
			return (1);
	return (0);
}


/**
 *_isalpha - This Check and verify for alphabetic character in the code
 *@p: The character to input in the code or program
 *Return: 1 if p inputted is alphabetic, 0 otherwise when it turns out diff
 */

int _isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - This converts string to an integer in the code
 *@t: the string to be converted in the program
 *Return: 0 if no numbers in string in de code,then converted number otherwise.
 */

int _atoi(char *t)
{
	int d, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (d = 0;  t[d] != '\0' && flag != 2; d++)
	{
		if (t[d] == '-')
			sign *= -1;

		if (t[d] >= '0' && t[d] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[d] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
