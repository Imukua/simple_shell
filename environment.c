#include "headers.h"

/**
 * my_setenv - adds or changes an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: 1 to overwrite an existing variable, 0 to keep it
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	int result = 0;
	char *env_var = my_getenv(name);

	if (env_var != NULL && !overwrite)
	{
	_putstr("Error: Environment variable already exists\n");
	result = (-1);
	}
	else
	{
	char *new_env_var = malloc(_strlen(name, TMAX) + _strlen(value, TMAX) + 2);

	if (new_env_var == NULL)
	{
	_putstr("Error: Failed to allocate memory\n");
	result = -1;
	}
	else
	{
	_strcopy(new_env_var, (char *) name);
	_strcat(new_env_var, "=");
	_strcat(new_env_var, (char *) value);
	if (my_putenv(new_env_var) != 0)
	{
	_putstr("Error: Failed to add environment variable\n");
	result = -1;
	}
	}
	free(new_env_var);
	}

	return (result);
}

/**
*my_putenv - adds or changes an environment variable
*@str: string to add to the environment
*Return: 0 on success, -1 on failure
*/
int my_putenv(char *str)
{
	char **new_environ, *new_str;
	size_t num_vars = 0, i;

	for (i = 0; environ[i] != NULL; i++)
	{
	num_vars++;
	}

	new_environ = (char **) malloc((num_vars + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
	return (-1);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
	new_environ[i] = environ[i];
	}

	new_str = (char *) malloc(_strlen(str, TMAX) + 1);
	if (new_str == NULL)
	{
	free(new_environ);
	return (-1);
	}
	_strcopy(new_str, str);

	new_environ[i++] = new_str;
	new_environ[i] = NULL;

	environ = new_environ;

	return (0);
}

/**
 * my_unsetenv - removes an environment variable
 * @name: name of the variable
 * Return: 0 on success, -1 on failure
 */
int my_unsetenv(const char *name)
{
	char **envp;
	size_t len;
	int found;

	if (name[0] == '\0' || my_strchr(name, '=') != NULL)
	{
	_putstr("Error: Invalid environment variable name\n");
	return (-1);
	}

	envp = environ;
	len = strlen(name);
	found = 0;

	while (*envp != NULL)
	{
	if (my_strncmp(name, *envp, len) == 0 && (*envp)[len] == '=')
	{
	char **dst = envp;
	char **src = envp + 1;

	while (*src != NULL)
	{
	*dst++ = *src++;
	}
	*dst = NULL;
	found = 1;
	break;
	}
	envp++;
	}

	return (found ? 0 : -1);
}
