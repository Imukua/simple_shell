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
