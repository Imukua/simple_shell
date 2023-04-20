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
	_putchar('\n');
}
