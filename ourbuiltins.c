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
	perror("chdir");
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
	(void) args;
	_putstr("****EXITING***\n");
	exit(EXIT_SUCCESS);
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
