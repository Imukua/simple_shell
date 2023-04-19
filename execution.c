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
	int status = execute_built_in(argv);

	if (status != -1 && status != 0)
	{
		return;
	}
	char *argvL[2];

	argvL[0] = locatecmd(argv[0]);

	if (access(argvL[0], X_OK) == -1)
	{
		printf("%s: command not found\n", argv[0]);
		return;
	}
	char *execution = NULL;

	pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
		{
			execution = locatecmd(argv[0]);
			execve(execution, argv, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		} else
		{
			int status;

			waitpid(pid, &status, 0);
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
