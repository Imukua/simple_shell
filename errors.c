#include "headers.h"
/*void handle_input_error - handles input errors
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
	} else
	{
	perror("readline");
	}
	}
}

/*void check_malloc_er - checks if malloc failed
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


