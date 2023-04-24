#include "headers.h"

/**
 * myrealloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @size: new size, in bytes of the new memory block
 * Return: pointer to the newly allocated memory, NULL if it fails
 */
char *myrealloc(char *ptr, size_t size) {
    char *newptr;
    size_t i;

    if (size == 0) {
        free(ptr);
        return NULL;
    }


    newptr = malloc(size);
    if (newptr == NULL) {
        return NULL;
    }


    if (ptr != NULL) {
        for (i = 0; i < size && ptr[i] != '\0'; i++) {
            newptr[i] = ptr[i];
        }
        free(ptr);
    }

    return newptr;
}


int str_to_int(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int len = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (my_isdigit(str[i])) {
        if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && (str[i] - '0') > (INT_MAX % 10)))
        {
            perror ("Error: integer overflow");
            return (0);
        }

        result = (result * 10) + (str[i] - '0');
        i++;
        len++;
    }

    if (i != (int)_strlen(str,TMAX) || len == 0)
    {
		_putstr(": exit: ");
		_putstr(": numeric argument required\n");
    
        return (0);
    }
    return result * sign;
}
