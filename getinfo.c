#include "shell.h"

/**
 * clear_info - initializes info_s structure in the code
 * @info: This target the structure  address of the code
 *
 * Author : Kingsley and Kofo
 * Date: 24th May 2023
 * Project: Simole Shell
 *
 */
void clear_info(info_s *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initializes infost structure in the code
 * @info: structure address of the code
 * @av: argument vector of the code
 */
void set_info(info_s *info, char **av)
{
	int d = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \s");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (d = 0; info->argv && info->argv[d]; d++)
			;
		info->argc = d;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - This mainly frees info_s structure fields
 * @info: structure  address in the code
 * @all: true if freeing all fields in the entire
 */
void free_info(info_s *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_bufa)
			free(info->arg);
		if (info->environment)
			free_list(&(info->environment));
		if (info->hist)
			free_list(&(info->hist));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environment);
			info->environment = NULL;
		bfree((void **)info->cmd_bufa);
		if (info->readfdec > 2)
			close(info->readfdec);
		_putchar(BUFA_FLUSH);
	}
}
