#include "headers.h"

/**
* print_prompt - prints the prompt
* @prompt: the prompt to be printed
*
* Return: void
*/
void print_prompt(char *prompt)
{
	int i;

	for (i = 0; prompt[i] != '\0'; i++)
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
void execmd(char **argv,char **progname)
{
	int status;
	char *argvL[2];
	char *execution = NULL;
	pid_t pid;


	status = execute_built_in(argv);
	if (status != -1 && status != 0)
	{
		return;
	}

	argvL[0] = locatecmd(argv[0]);

	if (access(argvL[0], X_OK) == -1)
	{
		print_error(progname[0], argv[0]);
		return;
	}
		pid = fork();

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
	char *token;
	int token_count = 0;

	token = strtok(input_str, delim);
	while (token != NULL && token_count < max_tokens)
	{
		tokens[token_count] = token;
		token = strtok(NULL, delim);
		token_count++;
	}
	return (token_count);
}


void interactivecheck(void)
{
	char *prompt = "cocoon--> ";
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		print_prompt(prompt);
	}
	{
		return;
	}
}
