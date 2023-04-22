#include "headers.h"

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
