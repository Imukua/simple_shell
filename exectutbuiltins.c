#include "headers.h"

/**
 * execute_built_in - executes a built in function
 * @args: array of pointers to the arguments
 * Return: 1 if the function is not a built in, 0 if it is
 */
int execute_built_in(char **args)
{
	int i;
	int j;

	built_in built_ins[] = {
	{"cd", cd_bltn},
	{"exit", exit_bltn},
	{"env", env_bltn}
	};

	j = sizeof(built_ins) / sizeof(built_in);

	for (i = 0; i < j; i++)
	{
	if (_strcmp(args[0], built_ins[i].name) == 0)
	{
	return (built_ins[i].func(args));
	}
	}
	return (-1);
}
