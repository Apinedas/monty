#include "monty.h"

/**
 * replacetabs - Replaces tabs with spaces on a line
 * @line: Line to replace tabs in
 */

void replacetabs(char *line)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
}

/**
 * count_words - Count words of a string, and words are separated by spaces
 * @s: String to count words
 * Return: Number of words
 */

int count_words(char *s)
{
	int ret, i;

	ret = 0;
	if (s == NULL)
		return (ret);
	for (i = 0; s[i]; i++)
	{
		if ((s[i] == ' ' && s[i + 1] != ' ') || (s[i] != ' ' && i == 0))
			ret++;
	}
	return (ret);
}

/**
 * count_lines - Count lines of a string
 * @s: String to count lines
 * Return: Number of lines
 */

int count_lines(char *s)
{
	int ret, i;

	ret = 0;
	if (s == NULL)
		return (ret);
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '\n')
			ret++;
	}
	return (ret);
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
	int fd, lines, i = 0;
	unsigned int j;
	void (*handling_function)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	if (argc != 2)
		USAGE_ERROR;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		OPEN_ERROR(argv[1]);
	buff = _calloc(1024, sizeof(*buff));
	if (buff == NULL)
		MALLOC_ERROR;
	read(fd, buff, 1024);
	lines = count_lines(buff);
	copied_lines = _calloc((lines + 2), sizeof(*copied_lines));
	if (!copied_lines)
		MALLOC_ERROR;
	line = strtok(buff, "\n");
	while (line)
	{
		copied_lines[i] = line;
		i++;
		line = strtok(NULL, "\n");
	}
	for (j = 1; copied_lines[j - 1]; j++)
	{
		exec_line = strtok(copied_lines[j - 1], " ");
		if (!exec_line)
			continue;
		handling_function = getopcode_fun(exec_line);
		if (!handling_function)
			INSTRUCTION_ERROR(j, exec_line);
		handling_function(&stack, j);
	}
	if (stack)
		free_dlistint(stack);
	FREEANDCLOSE(buff, copied_lines, fd);
	return (0);
}
