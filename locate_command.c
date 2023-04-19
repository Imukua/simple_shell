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

	path = getenv("PATH");
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
