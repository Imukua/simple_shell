#include "headers.h"

/**
 * starts_with_echo_and_double_quote - checks if a string starts with
 * the word echo and a double quote
 * @str: the string to be checked
 * Return: 1 if true, 0 if false
 */
int starts_with_echo_and_double_quote(const char *str) {
    const char *prefix = "echo ";
    size_t prefix_len = strlen(prefix);
    if (strncmp(str, prefix, prefix_len) != 0) {
        return 0;
    }
    if (str[prefix_len] != '"') {
        return 0;
    }
    return 1;
}
