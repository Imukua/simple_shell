#include "headers.h"

/**
 * cd_bltn - changes the current directory
 * @args: array of pointers to the arguments
 * Return: 1
 */
int cd_bltn(char **args)
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else
	{
	if (chdir(args[1]) != 0)
	{
	_putstr(args[TMAX]);
	_putstr(": ");
	_putstr(args[0]);
	_putstr(": ");
	_putstr(args[1]);
	_putstr(": No such file or directory\n");
	}
	}
	return (1);
}

/**
 * exit_bltn - exits the shell
 *
 * Return: 0
 */
int exit_bltn(char **args)
{
	int status;
	(void) args;

	if (args[2] != NULL)
	{
		_putstr("exit: too many arguments\n");
		return (1);
	}

	status = str_to_int(args[1]);
	if (status == 0)
	{
		return (1);
	}

	if (status > 255)
	{
		_putstr("exit: status out of range (0-255)\n");
		return (1);
	}

	_putstr("****EXITING");
	_putchar('(');
	_putstr(args[1]);
	_putchar(')');
	_putstr("****\n");
	exit(status);
}
/**
 * env_bltn - prints the environment
 * @args: array of pointers to the arguments
 * Return: 1
 */
int env_bltn(char **args)
{
	extern char **environ;
	int i = 0;
	(void) args;

	while (environ[i] != NULL)
	{
	_putstr(environ[i]);
	_putchar('\n');
	i++;
	}
	return (1);
}
