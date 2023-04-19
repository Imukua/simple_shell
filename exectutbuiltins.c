#include "headers.h"
/**
 * built_in - struct for built in functions
 * @name: name of the built in function
 * @func: pointer to the function
 */
built_in built_ins [] = {
    {"cd", cd_bltn},
    {"exit", exit_bltn},
    {"env", env_bltn}
};
/**
 * num_built_ins - returns the number of built in functions
 * Return: number of built in functions
 */
int num_built_ins(void)
{
    return (sizeof(built_ins) / sizeof(built_in));
}
/**
 * get_built_ins - returns the built in functions
 * Return: pointer to the built in functions
 */
built_in *get_built_ins(void)
{
    return (built_ins);
}
/**
 * execute_built_in - executes a built in function
 * @args: array of pointers to the arguments
 * Return: 1 if the function is not a built in, 0 if it is
 */
int execute_built_in(char **args)
{
    int i;
    int j;
    built_in *built_ins = get_built_ins();
    j = num_built_ins();

    for (i = 0; i < j; i++)
    {
        if (_strcmp(args[0], built_ins[i].name) == 0)
        {
            return (built_ins[i].func(args));
        }
    }
    return (-1);
}