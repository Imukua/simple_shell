#include "headers.h"
/**
 * main - executes a simple UNIX CLI.
 * @argv[]: array of pointers to the arguments.
 *
 * Return: return value of the last executed command.
 */
int main(void)
{
	char *prompt = "cocoon--> ", *line_ptr = NULL, *line_ptrcp = NULL, *argv[TMAX];
	const char *delim = " \n";
	size_t line_size = 0;
	ssize_t line_value;

	while (1)
	{
	print_prompt(prompt);
	line_value = getline(&line_ptr, &line_size, stdin);
	handle_input_error(line_value);
	line_ptrcp = malloc(sizeof(char) * line_size);
	check_malloc_er(line_ptrcp);
	_strcopy(line_ptrcp, line_ptr);
	int token_count = tokenize_input(line_ptrcp, argv, delim, TMAX);

	argv[token_count] = NULL;
	execmd(argv);

	}
	
	free(line_ptrcp);
	free(line_ptr);
	return (0);
}