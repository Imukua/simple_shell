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
 * @progname: the program name
 * Return: return value of the last executed command
*/
void execmd(char **argv, char **progname)
{
	static int no_times = 1;
	int status, times;
	char *argvL[2], *execution = NULL;
	pid_t pid;

	argv[TMAX] = progname[0];
	times = execute_built_in(argv);
	if (times != -1 && times != 0)
	{
		return;
	}
	argvL[0] = locatecmd(argv[0]);

	if (argvL[0] == NULL)
	{
		print_error(progname[0], argv[0], no_times);
		no_times++;
		return;
	}
	
	if (access(argvL[0], X_OK) == -1)
	{
		print_error(progname[0], argv[0], 1);
		no_times++;
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
			execve(execution, argv, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		} else
		{
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

	token = mystr_tok(input_str, delim);
	while (token != NULL && token_count < max_tokens)
	{
		tokens[token_count] = token;
		token = mystr_tok(NULL, delim);
		token_count++;
	}
	return (token_count);
}


/**
 * interactivecheck - checks if the program is running in interactive mode
 *
 * Return: void
*/
void interactivecheck(void)
{
	char *prompt = "$ ";
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		print_prompt(prompt);
	}
	{
		return;
	}
}
