#include "shell.h"

/**
 * _myenviro - This prints the current environment of the Directory
 * @info: Structure containing potential arguments which is to maintain
 *          constant function prototype in the shell.
 *
 * Authors: Kingsley and Kofoworla
 * Date: 15th May 2023
 *
 * Return: Always 0 at the end
 */
int _myenviro(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenviro - This code is mainly to gets the value of environment variable
 * @info: Structure containing potential arguments which is to be to maintain
 * @name: The enviroment  variable name of the code
 *
 * Return: the value
 */
char *_getenviro(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *c;

	while (node)
	{
		c = starts_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenviro - This mainly Set orInitialize a new environment variable,
 *             or modify an existing Variable Enivronment
 * @info: Structure containing potential arguments which is to maintain
 *        constant function prototype of the code
 *  Return: Always 0 when Successful
 */
int _mysetenviro(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Please it is Incorrect number of arguements\n");
		return (1);
	}
	if (_setenviro(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenviro - This code mainly Remove an environment variable  in shell
 * @info: Structure containing potential arguments which  to maintain
 *        constant function prototype in the variable enviroment.
 *  Return: Always 0 when it is successful
 */
int _myunsetenviro(info_t *info)
{
	int d;

	if (info->argc == 1)
	{
		_eputs("Please it is Too few arguements.\n");
		return (1);
	}
	for (d = 1; d <= info->argc; d++)
		_unsetenviro(info, info->argv[d]);

	return (0);
}

/**
 * pop_enviro_list - This main function is to populates the
 		environment linked list
 * @info: This isStructure containing potential arguments which is to maintain
 *          constant function prototype in the variable environment
 * Description: Populating Environment List.
 * Return: Always 0 when it is success
 */
int pop_enviro_list(info_t *info)
{
	list_t *node = NULL;
	size_t d;

	for (d = 0; environ[d]; d++)
		add_node_end(&node, environ[d], 0);
	info->env = node;
	return (0);
}
