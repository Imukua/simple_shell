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

#include <stdlib.h>

char *int_to_str(int num) {
    int num_digits = 0;
    int temp = num;
	int i;
	char *str = (char *) malloc((num_digits + 1) * sizeof(char));

	while (temp != 0) {
        num_digits++;
        temp /= 10;
    }

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


