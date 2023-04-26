#include "headers.h"


ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

static ssize_t read_buffer(char **lineptr, size_t *n,
char **buffer_pos, int *buffer_size, FILE *stream);

static ssize_t extend_line(char **lineptr, size_t *n, size_t line_len);

static int is_end_of_input(ssize_t read_result, size_t line_len);


/**
 * my_getline - reads an entire line from a stream
 * @lineptr: pointer to a buffer that will contain the line
 * @n: pointer to the size of the buffer
 * @stream: stream to read from
 *
 * Return: the number of characters read, or -1 on error
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer_pos = NULL;
	ssize_t read_result;
	int buffer_size = 0;
	size_t line_len = 0;

	if (*lineptr == NULL)
	{
	*n = INITIAL_BUFFER_SIZE;
	*lineptr = (char *) malloc(*n);
	if (*lineptr == NULL)
	{
	return (-1);
	}
	}

	read_result = read_buffer(lineptr, n, &buffer_pos, &buffer_size, stream);
	if (read_result < 0)
	{
	return (read_result);
	}

	while (1)
	{
	char c = *buffer_pos++;

	if (c == '\n')
	{
	break;
	}

	line_len++;

	if (line_len + 1 >= *n)
	{
	ssize_t extend_result = extend_line(lineptr, n, line_len);

	if (extend_result < 0)
	{
	return (extend_result);
	}
	}

	(*lineptr)[line_len - 1] = c;

	if (buffer_pos >= *lineptr + *n)
	{
	read_result = read_buffer(lineptr, n, &buffer_pos, &buffer_size, stream);
	if (read_result < 0)
	{
	return (read_result);
	}
	}
	}

	(*lineptr)[line_len] = '\0';

	if (is_end_of_input(read_result, line_len))
	{
	return (-1);
	}

	return ((ssize_t) line_len);
}

/**
 * read_buffer - read from the stream into the buffer
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * @buffer_pos: pointer to the position in the buffer
 * @buffer_size: pointer to the size of the buffer
 * @stream: the stream to read from
 * Return: 0 on success, -1 on failure
 */

static ssize_t read_buffer(char **lineptr, size_t *n,
char **buffer_pos, int *buffer_size, FILE *stream)
{
	int last_char_index;
	ssize_t read_result = read(fileno(stream), *lineptr, BUFFER_SIZE);
	(void) n;
	
	if (read_result < 0)
	{
	if (errno == EINTR)
	{
	return (0);
	}
	return (-1);
	}
	else if (read_result == 0)
	{
	return (-2);
	}

	last_char_index = read_result - 1;

    if ((*lineptr)[last_char_index] != '\n')
	{
        (*lineptr)[last_char_index + 1] = '\n';
        (*lineptr)[last_char_index + 2] = '\0';

        return (read_result + 1);
	}

	*buffer_pos = *lineptr;
	*buffer_size = read_result;

	return (read_result);
}

/**
 * extend_line - extend the line buffer
 * @lineptr: pointer to the line buffer
 * @n: pointer to the size of the line buffer
 * @line_len: length of the line
 * Return: 0 on success, -1 on failure
 */
static ssize_t extend_line(char **lineptr, size_t *n, size_t line_len)
{
	char *new_line;
	*n *= 2;
	new_line = (char *) realloc(*lineptr, *n);
	(void) line_len;
	if (new_line == NULL)
	{
	free(*lineptr);
	*lineptr = NULL;
	return (-1);
	}

	*lineptr = new_line;

	return (0);
}

/**
 * is_end_of_input - checks fro end
 * @read_result: read result
 * @line_len: Line length read
 * Return: value
*/
static int is_end_of_input(ssize_t read_result, size_t line_len)
{
	return (read_result == (-2) && line_len == 0);
}
