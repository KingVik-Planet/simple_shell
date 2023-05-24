#include "shell.h"

/**
 * get_environment - This prima returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * Authors:Kingsley and Kofo
 * Date: 24th May 2023
 * Project : Simple Shell
 *
 * Return: Always 0
 */
char **get_environment(info_s *info)
{
	if (!info->environment || info->environment_changed)
	{
		info->environment = list_to_strings(info->environment);
		info->environment_changed = 0;
	}

	return (info->environment);
}

/**
 * _unsetenvironment - This is mainly Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype of the code.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string environment  variable property
 */
int _unsetenvironment(info_s *info, char *var)
{
	list_s *node = info->environment;
	size_t d = 0;
	char *c;

	if (!node || !var)
		return (0);

	while (node)
	{
		c = starts_with(node->str, var);
		if (c && *c == '=')
		{
			info->environment_changed = delete_node_at_index(&(info->environment), d);
			i = 0;
			node = info->environment;
			continue;
		}
		node = node->next;
		d++;
	}
	return (info->environment_changed);
}

/**
 * _setenvironment - This manily Initialize a new environment variable,
 *             or modify an existing one in the code
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype in the code.
 * @var: the string environment variable  property
 * @value: the string environment variable value in the code
 *  Return: Always 0
 */
int _setenvironment(info_s *info, char *var, char *value)
{
	char *bufa = NULL;
	list_s *node;
	char *c;

	if (!var || !value)
		return (0);

	bufa = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bufa)
		return (1);
	_strcpy(bufa, var);
	_strcat(bufa, "=");
	_strcat(bufa, value);
	node = info->environment;
	while (node)
	{
		c = starts_with(node->str, var);
		if (c && *c == '=')
		{
			free(node->str);
			node->str = bufa;
			info->environment_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->environment), bufa, 0);
	free(bufa);
	info->environment_changed = 1;
	return (0);
}
