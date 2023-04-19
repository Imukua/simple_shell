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
 * _strlen - returns the length of a string
 * @strn: string
 * @maxlen: maximum length of the string
 * Return: length of the string
 */
size_t _strlen(const char *strn, size_t maxlen)
{
	size_t i = 0;

	while (strn[i] != '\0' && i < maxlen)
	{
	i++;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @to_str: destination string
 * @from_str: source string
 *
 * Return: pointer to the destination string
 */
char *_strcat(char *to_str, char *from_str)
{
	int i = 0;
	int j = 0;

	while (to_str[i] != '\0')
	{
	i++;
	}
	while (from_str[j] != '\0')
	{
	to_str[i] = from_str[j];
	i++;
	j++;
	}
	to_str[i] = '\0';
	return (to_str);
}


/**
 * _strcmp - compares two strings
 * @string1: first string
 * @string2: second string
 *
 * Return: 0 if the strings are equal, -1 if s1 < s2, 1 if s1 > s2
 */
int _strcmp(char *string2, char *string1)
{
	int i = 0;

	while (string1[i] != '\0' && string2[i] != '\0')
	{
	if (string1[i] != string2[i])
	{
		return (string1[i] - string2[i]);
	}
	i++;
	}
	if (string1[i] == '\0' && string2[i] == '\0')
	{
	return (0);
	}
	else if (string1[i] == '\0')
	{
	return (-1);
	}
	else
	{
	return (1);
	}
}
