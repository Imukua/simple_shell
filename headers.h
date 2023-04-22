#ifndef HEADERS_H
#define HEADERS_H
#define TMAX 1024

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

/*objects for our builtins*/
typedef int (*built_in_func)(char **);
typedef struct built_in
{
char *name;
built_in_func func;
} built_in;

int execute_built_in(char **args);

/*functions for executing builtins*/
int cd_bltn(char **args);
int exit_bltn(char **args);
int env_bltn(char **args);

/*functions from strfunctions.c - for string manipulation*/
int _putchar(char c);
void _putstr(char *str);
char _strcopy(char *to_str, char *from_str);
int tokenize_input(char *input_str, char **tokens,
const char *delim, int max_tokens);
size_t _strlen(const char *strn, size_t maxlen);
int _strcmp(char *string2, char *string1);
char *_strcat(char *to_str, char *from_str);
char *int_to_str(int num);



/*functions from execution.c - for executing commands*/
void print_prompt(char *prompt);
void execmd(char **argv, char **progname);
char *locatecmd(char *execute);
void check_argv(char **argv);
void interactivecheck(void);


/*functions for error handling*/
void handle_input_error(int line_value);
void check_malloc_er(void *ptr);
void print_error(char *program_name, char *command, int times);
#endif
