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
       perror("speeciify a directory");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("chdir");
        }
    }
    return 1;
}

/**
 * exit_bltn - exits the shell
 * @args: array of pointers to the arguments
 * Return: 0
 */
int exit_bltn(char **args)
{
    (void) args;
    _putstr("*EXITING***\n");
    exit(EXIT_SUCCESS);
}
/**
 * env_bltn - prints the environment
 * @args: array of pointers to the arguments
 * Return: 1
 */
int env_bltn(char **args)
{
    (void) args;
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL)
    {
        _putstr(environ[i]);
        i++;
    }
    return 1;
}