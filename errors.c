#include "headers.h"
/**
 * handle_input_error - handles input errors
 * @line_value: value returned by getline
 * Return: void
*/
void handle_input_error(int line_value)
{

	if (line_value == -1)
	{
	if (feof(stdin))
	{
	exit(EXIT_SUCCESS);
	}
	if (line_value == -2)
	{
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
void check_malloc_er(void *ptr)
{
	if (ptr == NULL)
	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}
}

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
}

