#include "shell.h"

/**
 * _letsexit - This completely exits the shell.
 * @info: This is a Structure that house arguments.which is used
 *          in serviceing the constant function prototype.
 *
 * Authors: Kingsley and Kofoworola
 * Project: The Simple Shell Project
 * Date: 14th May of 2023
 *
 *  Return: this Happens when exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _letsexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* This Verifys If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Forbidden number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycdir - This Command changes the current dir of the process completely
 * @info: This wholly Struct containing PE  arguments. which mainly maintain
 *          The constant function prototype in the program.
 *  Return: Always 0
 */
int _mycdir(info_t *info)
{
	char *t, *dir, buffer[1024];
	int chdir_ret;

	t = getcwd(buffer, 1024);
	if (!t)
		_puts("FIXME: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* FIXME: Please what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(t);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* FIXME:Please what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "Please can't Change Directory to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _letshelp - This completely changes the current dir of the process
 * @info: This is a Structure containing PE arguments.whcih is used to bal
 *          the whole constant function prototype.
 *  Return: Always 0
 */
int _letshelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works here. As Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp attempted_unused workaround */
	return (0);
}
