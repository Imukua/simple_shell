#include "headers.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _strcopy - copies a string
 * @to_str: destination string
 * @from_str: source string
 *
 * Return: pointer to the destination string
 */
char _strcopy(char *to_str, char *from_str)
{
    int i = 0;
    while (from_str[i] != '\0')
    {
        to_str[i] = from_str[i];
        i++;
    }
    to_str[i] = '\0';
    return (*to_str);
}

/**
 * _strnlen - returns the length of a string
 * @strn: string
 * @maxlen: maximum length of the string
 *
 * Return: length of the string
 */
/*
size_t _strnlen(const char *strn, size_t maxlen)
{
    size_t length;

    for (length = 0; length < maxlen; length++);
    return (length);
}
*/
