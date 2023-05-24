#include "shell.h"

/**
 * main - This is the entry point of the code
 * @jp: arg count of the code
 * @jr: arg vector of the code
 *
 * Authors: Kingsley and Kofo
 * Date: 25th May 2023
 * Project: Simple Shell
 *
 * Return: 0 on success, 1 on error
 */
int main(int jp, char **jr)
{
	info_t info[] = { INFO_INIT };
	int fdec = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fdec)
		: "r" (fdec));

	if (jp == 2)
	{
		fdec = open(jr[1], O_RDONLY);
		if (fdec == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Please this Can't open ");
				_eputs(jr[1]);
				_eputchar('\n');
				_eputchar(BUFA_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfdec = fdec;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, jr);
	return (EXIT_SUCCESS);
}
