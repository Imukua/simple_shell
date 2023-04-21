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

void print_error(char *program_name, char *command)
{
	char *real_program_name = program_name;
	 char *error_message = "bad interpreter: No such file or directory";
    char *not_found[] = {"/usr/bin/python3", "-m", "/usr/lib/command-not-found", NULL, NULL, NULL};
	char *dirrl = "/usr/lib/command-not-found: ";
	not_found[3] = real_program_name;
	not_found[4] = command;
	execve(not_found[0], not_found, NULL);

	
	_putstr(real_program_name);
	_putstr(": ");
	_putstr(dirrl);
	_putstr(not_found[0]);
	_putstr(": ");
	_putstr(error_message);
	_putchar('\n');
}
