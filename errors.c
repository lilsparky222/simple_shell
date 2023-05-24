#include "shell.h"

/**
 * _eputs - tring print out.
 *
 * @str: print string
 *
 * Return: None
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - a characted 'c' is stored
 * @c: the characted to be printed
 *
 * Return: 1 or -1 otherwise
 */
int _eputchar(char c)
{
	static int i;
	static char buf [WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - character 'c' is stared in fd
 * @c:character to be printed.
 * @fd: field discriptor
 *
 * Return: 1 or -1 otherwise.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - output a string
 * @str: printed string
 * @fd: field discribtor
 *
 * Return: No. character
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

