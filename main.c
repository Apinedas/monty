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

/**
 * main - main function for monty project
 * @argc: argument counter
 * @argv: argument vector
 * Return: always 0
 */

int main(int argc, char **argv)
{
	char *buff, *line, **copied_lines, *exec_line = NULL;
	int fd, lines;
	unsigned int i;
	void (*handling_function)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	if (argc != 2)
		USAGE_ERROR;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		OPEN_ERROR(argv[1]);
	buff = _calloc(1024, sizeof(*buff));
	if (!buff)
		MALLOC_ERROR;
	read(fd, buff, 1024);
	lines = count_lines(buff);
	copied_lines = _calloc((lines + 1), sizeof(*copied_lines));
	if (!copied_lines)
		MALLOC_ERROR;
	replace_emptylines(buff, copied_lines);
	line = strtok(buff, "\n");
	lines_to_array(line, copied_lines);
	for (i = 1; copied_lines[i - 1]; i++)
	{
		exec_line = strtok(copied_lines[i - 1], " ");
		if (!exec_line)
			continue;
		handling_function = getopcode_fun(exec_line);
		if (!handling_function)
			INSTRUCTION_ERROR(i, exec_line);
		handling_function(&stack, i);
	}
	if (stack)
		free_dlistint(stack);
	FREEANDCLOSE(buff, copied_lines, fd);
	return (0);
}
