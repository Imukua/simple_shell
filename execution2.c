#include "headers.h"
/**
 * *locatecmd - locates the command in the PATH.
 * @execute: command to be located.
 * Return: pointer to the command.
 */
char *locatecmd(char *execute)
{
	char *path = NULL;
	char *pathcpy = NULL;
	char *token = NULL;
	char *cmd = NULL;
	struct stat st;

	path = my_getenv("PATH");
	pathcpy = malloc(sizeof(char) * _strlen(path, TMAX));
	_strcopy(pathcpy, path);
	token = strtok(pathcpy, ":");
	while (token != NULL)
	{
	cmd = malloc(sizeof(char) *
	(_strlen(token, TMAX) + _strlen(execute, TMAX) + 2));
	_strcopy(cmd, token);
	_strcat(cmd, "/");
	_strcat(cmd, execute);
	_strcat(cmd, "\0");
	if (stat(cmd, &st) == 0)
	{
	free(pathcpy);
	return (cmd);
	}
	free(cmd);
	token = strtok(NULL, ":");
	}
	free(pathcpy);
	if (stat(execute, &st) == 0)
	{
	return (execute);
	}

	return (NULL);
}

/**
 * line_stuff - gets the line from the user.
 * Return: pointer to the line.
 */
char *line_stuff(void)
{
	char *line_ptr = NULL, *line_ptrcp = NULL;
	size_t line_size = 0;
	ssize_t line_value;

	line_value = my_getline(&line_ptr, &line_size, stdin);
	if (line_value == -2)
	{
		_putchar('\n');
		exit(EXIT_SUCCESS);
	}

	handle_input_error(line_value);

	line_ptrcp = malloc(sizeof(char) * line_size);
	check_malloc_er(line_ptrcp);
	_strcopy(line_ptrcp, line_ptr);

	return (line_ptrcp);
}

/**
 * *run_n_return - runs the command and returns 1.
 * @line_ptrcp: pointer to the line.
 * @progname: name of the program.
 * Return: 1.
 */
int run_n_return(char *line_ptrcp, char **progname)
{
	char *argv[TMAX], *subline[TMAX];
	int token_count;
	int sub_token_count;
	int i;
	const char *delim = " \n";

	token_count = tokenize_input(line_ptrcp, subline, ";", TMAX);
	argv[token_count] = NULL;
	for (i = 0; i < token_count; i++)
	{
	sub_token_count = tokenize_input(subline[i], argv, delim, TMAX);
	argv[sub_token_count] = NULL;

	if (argv[0] == NULL || _strcmp(argv[0], "\0") == 0)
	{
		continue;
	}
	execmd(argv, progname);
	}
	return (1);
}

/**
 * my_getenv - gets the environment variable.
 * @name: name of the variable.
 * Return: pointer to the variable.
 */
char *my_getenv(const char *name)
{
	extern char **environ;
	size_t namelen = _strlen(name, TMAX);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (my_strncmp(name, *env, namelen) == 0 && (*env)[namelen] == '=')
		{
			return (*env + namelen + 1);
		}
	}
	return (NULL);
}
