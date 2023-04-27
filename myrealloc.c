#include "headers.h"

/**
 * myrealloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @size: new size, in bytes of the new memory block
 * Return: pointer to the newly allocated memory, NULL if it fails
 */
char *myrealloc(char *ptr, size_t size)
{
	char *newptr;
	size_t i;

	if (size == 0)
	{
	free(ptr);
	return (NULL);
	}


	newptr = malloc(size);
	if (newptr == NULL)
	{
	return (NULL);
	}


	if (ptr != NULL)
	{
	for (i = 0; i < size && ptr[i] != '\0'; i++)
	{
	newptr[i] = ptr[i];
	}
	free(ptr);
	}

	return (newptr);
}

/**
 * str_to_int - converts an integer to a string
 * @str: integer to convert
 * Return: pointer to the string
 */
int str_to_int(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int len = 0;

	if (str[i] == '-')
	{
	sign = -1;
	i++;
	}
	else if (str[i] == '+')
	{
	i++;
	}

	while (my_isdigit(str[i]))
	{
	if (result > (INT_MAX / 10) || (result == (INT_MAX / 10)
	&& (str[i] - '0') > (INT_MAX % 10)))
	{
	perror("Error: integer overflow");
	return (0);
	}

	result = (result * 10) + (str[i] - '0');
	i++;
	len++;
	}

	if (i != (int)_strlen(str, TMAX) || len == 0)
	{
		_putstr(": exit: ");
		_putstr(": numeric argument required\n");

	return (0);
	}
	return (result * sign);
}

/**
 * my_strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @no: number of bytes to compare
 * Return: 0 if the strings are equal, -1
 * if s1 is less than s2, 1 if s1 is greater than s2
 */
int my_strncmp(const char *s1, const char *s2, size_t no)
{
	size_t i;

	for (i = 0; i < no; i++)
	{
	if (s1[i] != s2[i])
	return (s1[i] < s2[i] ? -1 : 1);
	if (s1[i] == '\0')
	return (i == no - 1 || s2[i + 1] == '\0' ? 0 : -1);
	if (s2[i] == '\0')
	return (i == no - 1 || s1[i + 1] == '\0' ? 0 : 1);
	}
	return (0);
}


