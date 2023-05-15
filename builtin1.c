#include "shell.h"

/**
 * _myhist - This code displays the hist list, one command by line, preceded
 *              with  numbers,which can start at 0.
 * @info: Struct are containing potential arguments. which is Used to maintain
 *        constant function prototype.
 * AUTHOUR: kofoworola and kingsley.
 * DATE:15/05/2023.
 *
 *  Return: Always 0
 */
int _myhist(info_t *info)
{
	print_list(info->hist);
	return (0);
}

/**
 * unset_alias - This code  sets alias to string
 * @info: This is the parameter structure
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *c, p;
	int ret;

	C = _strchr(str, '=');
	if (!c)
		return (1);
	p = *c;
	*c = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*c = p;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *c;

	C = _strchr(str, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *c = NULL, *j = NULL;

	if (node)
	{
		c = _strchr(node->str, '=');
		for (j = node->str; j <= c; j++)
			_putchar(*j);
		_putchar('\'');
		_puts(c + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int d = 0;
	char *c = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (d = 1; info->argv[d]; d++)
	{
		C = _strchr(info->argv[d], '=');
		if (c)
			set_alias(info, info->argv[d]);
		else
			print_alias(node_starts_with(info->alias, info->argv[d], '='));
	}

	return (0);
}
