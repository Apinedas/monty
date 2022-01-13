#include "monty.h"

/**
 * replace_emptylines - fill the array with an space
 * when an empty line is found
 * @buff: initial buffer
 * @copy: copy array
 */

void replace_emptylines(char *buff, char **copy)
{
	int i = 0, lines = 0;

	while (buff[i] == '\n')
	{
		copy[lines] = " ";
		i++;
		lines++;
	}
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			lines++;
			if (buff[i + 1] == '\n')
				copy[lines] = " ";
		}
		i++;
	}
}

/**
 * count_lines - Count lines of a string
 * @s: String to count lines
 * Return: Number of lines
 */

int count_lines(char *s)
{
	int ret, i;

	ret = 1;
	if (s == NULL)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '\n')
			ret++;
	}
	return (ret);
}

/**
 * lines_to_array - fills an array with tokenized lines
 * @line: first token
 * @copy: array to fill
 */

void lines_to_array(char *line, char **copy)
{
	int i = 0;

	while (line)
	{
		if (!copy[i])
		{
			copy[i] = line;
			i++;
			line = strtok(NULL, "\n");
		}
		else
			i++;
	}
}
