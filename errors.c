#include "headers.h"
/**
 * handle_input_error - handles input errors
 * @line_value: value returned by getline
 * @line_ptr: pointer to the line
 * Return: void
*/
void handle_input_error(int line_value, char *line_ptr)
{

	if (line_value == -1)
	{
	if (feof(stdin))
	{
	write(STDOUT_FILENO, "\n", 1);
	free(line_ptr);
	exit(EXIT_SUCCESS);
	}
	if (line_value == -2)
	{
	free(line_ptr);
	exit(EXIT_FAILURE);
	}
	else
	{
	perror("readline");
	}
	}
}

/**
 * check_malloc_er - checks if malloc failed
 * @ptr: pointer to the memory allocated
 * Return: void
 */
void check_malloc_er(char *ptr)
{
	if (ptr == NULL)
	{
	free(ptr);
	perror("malloc");
	exit(EXIT_FAILURE);
	}
}

/**
 * print_error - prints error message
 * @program_name: name of the program
 * @command: command that failed
 * @times: number of times the command failed
 * Return: void
 */
void print_error(char *program_name, char *command, int times)
{
	char *real_program_name = program_name;
	char *not_found[] = {"/usr/bin/python3", " ",
	"command not found", NULL, NULL, NULL};
	char *conv_int [] = {" ", NULL};

	not_found[3] = real_program_name;
	not_found[4] = command;
	conv_int[0] = int_to_str(times);
	_putstr(real_program_name);
	_putstr(": ");
	_putstr(conv_int[0]);
	_putstr(": ");
	_putstr(not_found[4]);
	_putstr(": ");
	_putstr(not_found[2]);
	_putchar('\n');
	free(conv_int[0]);
}

