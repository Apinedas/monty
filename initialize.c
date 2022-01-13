#include "monty.h"

/**
 * initialize_buffer - sets all the elements of the buffer to 0
 * @s: buffer to initialize
 * @size: buffer's size
 */

void initialize_buffer(char *s, int size)
{
	int i;

	for (i = 0; i < size; i++)
		s[i] = 0;
}

/**
 * initialize_array - sets all the elements of the array to NULL
 * @s: array to initialize
 * @size: array's size
 */

void initialize_array(char **s, int size)
{
	int i;

	for (i = 0; i < size; i++)
		s[i] = NULL;
}
