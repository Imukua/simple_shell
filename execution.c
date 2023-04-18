#include "headers.h"

/**
* print_prompt - prints the prompt
* @prompt: the prompt to be printed
*
* Return: void
*/
void print_prompt(char *prompt)
{
	for (int i = 0; prompt[i] != '\0'; i++)
	{
	_putchar(prompt[i]);
	}
}

/**
 * execmd - executes a command
 * @argv: array of pointers to the arguments
 *
 * Return: return value of the last executed command
*/
void execmd(char **argv)
{
	char *execution = NULL;

	if (argv)
	{
	execution = argv[0];

	/* execute the command with execve */
	if (execve(execution, argv, NULL) == -1)
	{
	perror("Error:");
	}
	}
}

/**
 * tokenize_input - tokenizes the input string
 * @input_str: input string
 * @tokens: array of pointers to the tokens
 * @delim: delimiter
 * @max_tokens: maximum number of tokens
 *
 * Return: number of tokens
*/
int tokenize_input(char *input_str, char **tokens,
const char *delim, int max_tokens)
{
	char *token = strtok(input_str, delim);
	int token_count = 0;

	while (token != NULL && token_count < max_tokens)
	{
		tokens[token_count] = token;
		token = strtok(NULL, delim);
		token_count++;
	}
	return (token_count);
}
