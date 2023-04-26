#include "headers.h"
/**
 * main - executes a simple UNIX CLI.
 * @argc: array of pointers to the arguments.
 * @argv: name of the program.
 * Return: return value of the last executed command.
 */
int main(int argc, char *argv[])
{
	char *line_ptrcp = NULL;
	char *progname[2];

	(void) argc;
	progname[0] = argv[0];
	while (1)
	{
	interactivecheck();
	line_ptrcp = line_stuff();
	run_n_return(line_ptrcp, progname);

	}

	free(line_ptrcp);
	return (0);
}
