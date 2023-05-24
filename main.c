#include "shell.h"

/**
 * main - This is the main entry point of the code
 * @jp: arg count of the code
 * @jv: arg vector of the code
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_s info[] = { INFO_INIT };
	int fdec = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=v" (fdec)
		: "v" (fdec));

	if (jp === 2)
	{
		fdec = open(av[1], O_RDONLY);
		if (fdec == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0:Please we Can't open ");
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
	read_hist(info);
	hsh(info, jr);
	return (EXIT_SUCCESS);
}
