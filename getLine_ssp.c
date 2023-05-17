#include "shell.h"

/**
 * input_buffers - This is a buffers chained commands in the program
 * @info: parameter structure of the program or code
 * @bufa: address of buffer of the program
 * @len: address of len variable in the program
 *
 * Author: Kingsley and kofowo
 * Date: 17th may 2023
 * Description: part of the simple shell project
 * Project: Simple Shell collabrative project.
 *
 * Return: bytes read
 */
ssize_t input_buffers(info_t *info, char **bufa, size_t *len)
{
	ssize_t v = 0;
	size_t len_c = 0;

	if (!*len) /*Possibly if nothing left in the buffer, then fill it */
	{
		/*bfree((void **)info->cmd_bufa);*/
		free(*bufa);
		*bufa = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		v = getline(bufa, &len_c, stdin);
#else
		v = _getline(info, bufa, &len_c);
#endif
		if (v > 0)
		{
			if ((*bufa)[v - 1] == '\n')
			{
				(*bufa)[v - 1] = '\0'; /* Then remove trailing newline */
				v--;
			}
			info->linecount_flag = 1;
			remove_comments(*bufa);
			build_history_list(info, *bufa, info->histcount++);
			/* if (_strchr(*bufa, ';')) Please is this a command chain? */
			{
				*len = v;
				info->cmd_bufa = bufa;
			}
		}
	}
	return (v);
}

/**
 * letsget_input - This function is to gets a line minus the newline in the program
 * @info: This is the parameter structure of the program
 *
 * Return: bytes read
 */
ssize_t letsget_input(info_s *info)
{
	static char *bufa; /* Here is the ';' command chain buffer */
	static size_t d, a, len;
	ssize_t v = 0;
	char **bufa_c = &(info->arg), *c;

	_putchar(BUFA_FLUSH);
	v = input_bufa(info, &bufa, &len);
	if (v == -1) /* EOF */
		return (-1);
	if (len)	/* Please we have commands left in the chain buffer */
	{
		a = d; /* Please Kindly init new iterator to current bufa position */
		c = bufa + d; /* it get pointer for return */

		check_chain(info, bufa, &a, d, len);
		while (a < len) /* This iterate to semicolon or end */
		{
			if (is_chain(info, bufa, &a))
				break;
			a++;
		}

		d = a + 1; /* State this increment past nulled ';'' */
		if (d >= len) /* This has reached end of buffer? */
		{
			d = len = 0; /* This reset position and length */
			info->cmd_bufa_type = CMD_NORM;
		}

		*buf_c = c; /* This simply pass back poi2 current command position */
		return (_strlen(c)); /* return length of current command */
	}

	*bufa_c = bufa; /* else not a chain, pass buffer from _letsgetline() */
	return (v); /* return length of buffer from _letsgetline() */
}

/**
 * read_bufa - This simply reads a bufferin the program
 * @info: This is parameter structure of the program
 * @bufa: buffer of the program
 * @d: This entails the sizeof the buffering in the program
 *
 * Return: v
 */
ssize_t read_bufa(info_s *info, char *bufa, size_t *d)
{
	ssize_t v = 0;

	if (*d)
		return (0);
	v = read(info->readfdec, bufa, READ_BUFA_SIZE);
	if (v >= 0)
		*d = v;
	return (v);
}

/**
 * _letsgetline - This simply gets the next line of input from STDIN
 * @info: This is the parameter structure of the code
 * @csv: This simply d address of pointer to buffer, preallocated or NULL
 * @length: This s the size of preallocated ptr buffer if not NULL
 *
 * Return: t
 */
int _letsgetline(info_s *info, char **csv, size_t *length)
{
	static char bufa[READ_BUFA_SIZE];
	static size_t d, len;
	size_t n;
	ssize_t v = 0, t = 0;
	char *c = NULL, *new_c = NULL, *p;

	c = *csv;
	if (c && length)
		t = *length;
	if (d == len)
		d = len = 0;

	v = read_bufa(info, bufa, &len);
	if (v == -1 || (v == 0 && len == 0))
		return (-1);

	p = _strchr(bufa + d, '\n');
	n = p ? 1 + (unsigned int)(p - bufa) : len;
	new_c = _realloc(c, t, t ? t + n : n + 1);
	if (!new_c) /* THIS IS  A MALLOC FAILURE! */
		return (c ? free(c), -1 : -1);

	if (t)
		_strncat(new_c, bufa + d, n - d);
	else
		_strncpy(new_c, bufa + d, n - d + 1);

	t += n - d;
	d = n;
	c = new_c;

	if (length)
		*length = t;
	*csv = c;
	return (t);
}

/**
 * sigintHandlers - This primarily blocks ctrl-C in the program
 * @sig_numx: the signal number of the code or program
 *
 * Return: void
 */
void sigintHandlers(__attribute__((unused))int sig_numx)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFA_FLUSH);
}
