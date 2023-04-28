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
 * @line_ptrcp: copy of the input string
 * Return: return value of the last executed command
*/
void execmd(char **argv, char **progname, char *line_ptrcp)
{
	int status, times;
	char *argvL[2];
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
		print_error(progname[0], argv[0], 1);
		return;
	}
	if (access(argvL[0], X_OK) == -1)
	{
		print_error(progname[0], argv[0], 1);
		return;
	}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			checkf(argvL, argv, line_ptrcp);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(argvL[0], argv, environ);
			perror("execve");
			checkf(argvL, argv, line_ptrcp);
			exit(EXIT_FAILURE);
		} else
		{
			checkf2(argvL, argv);
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
	char *token, *comment_ptr = NULL;
	int token_count = 0, meets;

	meets = starts_with_echo_and_double_quote(input_str);
	if (meets == 0)
	{
	comment_ptr = strchr(input_str, '#');
	}

	if (comment_ptr != NULL)
	{
	*comment_ptr = '\0';
	}


	token = mystr_tok(input_str, delim);
	while (token != NULL && token_count < max_tokens)
	{
	int len = strlen(token);

	if (len > 0)
	{
	while (my_isspace(*token))
	{
	token++;
	len--;
	}
	while (len > 0 && my_isspace(token[len - 1]))
	{
	token[--len] = '\0';
	}
	if (len > 0)
	{
	tokens[token_count] = token;
	token_count++;
	}
	}
	token = mystr_tok(NULL, delim);
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

/**
 * checkf - checks if the command is in the current directory
 * @argvL: array of pointers to the arguments
 * @argv: array of pointers to the arguments
 * @line_ptrcp: copy of the input string
 * Return: void
*/
void checkf(char **argvL, char **argv, char *line_ptrcp)
{
	if (_strcmp(argvL[0], argv[0]) != 0)
	{
		free(argvL[0]);
	}
	free(line_ptrcp);
}

