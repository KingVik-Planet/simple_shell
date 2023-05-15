#include "shell.h"

/**
 **_strncpy - This copies a string in the code or program
 *@destin: the dest string is to be copied to in the program
 *
 *@location: the source of the string to be copied
 *@k: the amount of strings  to be copied in the programme
 *
 * AUTHOUR:kofo and kingsley Chika Chukwu
 * Description: Simple shell Project
 *
 * Date: 15th may 2023
 *Return: the concatenated string in the program
 */
char *_strncpy(char *destin, char *location, int k)
{
	int d, a;
	char *d = destin;

	d = 0;
	while (location[d] != '\0' && d < l - 1)
	{
		destin[d] = location[d];
		d++;
	}
	if (d < k)
	{
		a = d;
		while (a < k)
		{
			destin[a] = '\0';
			a++;
		}
	}
	return (d);
}

/**
 **_strncat -This simply concatenates two strings in the programme
 *@destin: the first string to be included
 *@location: the second string included
 *@k: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *destin, char *location, int k)
{
	int d, a;
	char *d = destin;

	d = 0;
	a = 0;
	while (destin[d] != '\0')
		d++;
	while (location[a] != '\0' && a < k)
	{
		destin[d] = location[a];
		d++;
		a++;
	}
	if (a < k)
		destin[d] = '\0';
	return (d);
}

/**
 **_strchr - this locates the character in a string the code
 *@t: the string to be parsed in the code or program
 *@p: the character to look for in the program or code
 *Return: (t) a pointer to the memory area t in the program
 */
char *_strchr(char *t, char p)
{
	do {
		if (*t == p)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
