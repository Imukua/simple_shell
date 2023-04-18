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


//functions from strfunctions.c - for string manipulation
int _putchar(char c);
char _strcopy(char *to_str, char *from_str);
int tokenize_input(char *input_str, char **tokens, const char *delim, int max_tokens) ;
size_t _strnlen(const char *strn, size_t maxlen);

//functions from execution.c - for executing commands
void print_prompt(char *prompt);
void execmd(char **argv);


//functions for error handling
void handle_input_error(int line_value);
void check_malloc_er(void *ptr);
#endif