#ifndef HEADERS_H
#define HEADERS_H
#define TMAX 1024
#define INT_MAX 2147483647
#define INITIAL_BUFFER_SIZE 1024
#define BUFFER_SIZE 1024
#define MAX_ENV_VAR_LENGTH 1000
extern char **environ;

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
int exit_bltn(char **args, char *line_ptrcp);
int env_bltn(char **args);
int setenv_builtn(char **args);
int unsetenv_builtn(char **args);


/*helpers of environment builtins*/
char *my_getenv(const char *name);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
int my_putenv(char *str);


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
char *mystr_tok(char *str, const char *delim);
char *my_strchr(const char *st, int ct);
int my_isdigit(char digit);
int str_to_int(const char *str, char *progname);
int my_strncmp(const char *s1, const char *s2, size_t no);
int my_isspace(int ch);
int starts_with_echo_and_double_quote(const char *str);
/*functions from execution.c - for executing commands*/
void print_prompt(char *prompt);
void execmd(char **argv, char **progname, char *line_ptrcp);
char *locatecmd(char *execute);
void check_argv(char **argv);
void interactivecheck(void);
char *myrealloc(char *ptr, size_t size);
char *line_stuff(void);
int run_n_return(char *line_ptrcp, char **progname);
int count_args(char **argv);
void checkf(char **argvL, char **argv, char *line_ptrcp);
void checkf2(char **argvL, char **argv);

/*functions from getlinefunc.c - for getting the line from the user*/
ssize_t my_getline(char **nlptr, size_t *n, FILE *stream);

/*functions for handling environment variables*/
int get_env_var_index(char **envp, const char *var_name);
int unsetenv_builtin(char **args, char ***envp);
size_t get_envp_size(char **envp);

/*functions for error handling*/
void handle_input_error(int line_value, char *line_ptr);
void check_malloc_er(char *ptr);
void print_error(char *program_name, char *command, int times);
#endif
