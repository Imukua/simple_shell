#include "headers.h"

/**
 * _putstr - prints a string
 * @str: string to be printed
*/
void _putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
	_putchar(str[i]);
	i++;
	}

}

/**
 * int_to_str - converts an integer to a string
 * @num: integer to be converted
 * Return: pointer to the string
 */
char *int_to_str(int num)
{
    int num_digits = 0;
    int temp = num;
	int i;
	char *str;

	while (temp != 0) {
        num_digits++;
        temp /= 10;
    }

    str = (char *) malloc((num_digits + 1) * sizeof(char));

    if (str == NULL) {
        return NULL;
    }

    i = num_digits - 1;
    while (i >= 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i--;
    }
    str[num_digits] = '\0';
    return str;
}


/**
 * mystr_tok - tokenizes a string
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: pointer to the token
 */
char *mystr_tok(char *str, const char *delim)
{
    static char *last = NULL;
    char *token;

    if (str != NULL) {
        last = str;
    } else if (last == NULL || *last == '\0') {
        return NULL;
    }

    token = last;

    while (*last != '\0') {
        if (my_strchr(delim, *last) != NULL) {
            *last++ = '\0';
            break;
        }
        last++;
    }

    return token;
}

/**
 * my_strchr - finds a character in a string
 * @st: string to be searched
 * @ct: character to be found
 * Return: pointer to the character
 */
char *my_strchr(const char *st, int ct)
{
    while (*st != '\0') {
        if (*st == ct) {
            return (char*)st;
        }
        st++;
    }
    if (*st == ct) {
        return (char*)st;
    }
    return NULL;
}

/**
 * my_isdigit - checks if a character is a digit
 * @digit: character to be checked
 * Return: 1 if digit, 0 otherwise
 */
int my_isdigit(char digit) {
    return digit >= '0' && digit <= '9';
}
