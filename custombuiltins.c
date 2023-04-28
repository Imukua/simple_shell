#include "headers.h"

/**
 * cd_bltn - changes the current directory
 * @args: array of pointers to the arguments
 * Return: 1
 */
int cd_bltn(char **args)
{
	static char *previous_dir;
	char *current_dir = NULL, *cwd;
	const char *home_dir = "PWD";

	if (args[1] == NULL)
	{
	current_dir = my_getenv("HOME");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
	if (previous_dir == NULL)
	{
	_putstr("cd: no previous directory\n");
	return (1);
	}
	current_dir = previous_dir;
	}
	else
	{
	current_dir = args[1];
	}
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
	perror("cd");
	return (1);
	}
	if (chdir(current_dir) != 0)
	{
	perror("cd");
	free(cwd);
	return (1);
	}
	if (previous_dir != NULL)
	{
	free(previous_dir);
	}
	previous_dir = cwd;
	my_setenv(home_dir, previous_dir, 1);
	return (1);
}


/**
 * exit_bltn - exits the shell
 *@args: arguments
 *@line_ptrcp: pointer to the line
 * Return: 0
 */
int exit_bltn(char **args, char *line_ptrcp)
{
	int status = 0;
	int argum = 0;

	argum = count_args(args);

	if (argum > 2)
	{
		print_error(args[TMAX], args[0], 1);
		return (1);
	}
	if (args[1] == NULL)
	{
		free(line_ptrcp);
		exit(0);
	}
	status = str_to_int((const char *)args[1], args[TMAX]);
	if (status == 0)
	{
		return (1);
	}
	free(line_ptrcp);
	exit(status);
}
/**
 * env_bltn - prints the environment
 * @args: array of pointers to the arguments
 * Return: 1
 */
int env_bltn(char **args)
{
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

/**
 * setenv_builtn - set an environment variable
 * @args: arguments
 * Return: 1
*/
int setenv_builtn(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
	_putstr("Error: setenv: Too few arguments\n");
	return (1);
	}
	my_setenv(args[1], args[2], 1);
	return (1);
}

/**
 * unsetenv_builtn - unset an environment variable
 * @args: arguments
 * Return: 1
*/
int unsetenv_builtn(char **args)
{
	int result;

	if (args[1] == NULL)
	{
	_putstr("Error: unsetenv: Too few arguments\n");
	return (1);
	}
	if (my_getenv(args[1]) == NULL)
	{
	_putstr("Error: unsetenv: Variable does not exist\n");
	return (1);
	}
	result = my_unsetenv(args[1]);
	if (result == 0)
	{
	_putstr("succesfully unset variable: ");
	_putstr(args[1]);
	_putchar('\n');
	return (1);
	}
	return (1);
}
