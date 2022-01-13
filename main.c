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
		if (s[i] == ' ' || s[i] == '	')
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
 * linetoarray - transforms line into an array
 * @line: Line to transform
 * Return: Built array, or NULL in failure
 */

char **linetoarray(char *line)
{
	int words, i = 0;
	char **ret, *act_word;

	words = count_words(line);
	if (words == 0)
		return (NULL);
	ret = malloc((sizeof(*ret) * words) + 1);
	if (!ret)
		return (NULL);
	replacetabs(line);
	act_word = strtok(line, " ");
	while (act_word)
	{
		ret[i] = act_word;
		i++;
		act_word = strtok(NULL, " ");
	}
	ret[i] = NULL;
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
	char *buff, *line, **exec_array, **copied_lines;
	int fd, lines, len_read = 1, i = 0;
	void (*handling_function)(stack_t **, unsigned int);

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", _strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: Can't open file ", _strlen("Error: Can't open file "));
		write(2, argv[1], _strlen(argv[1]));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	buff = _calloc(1024, sizeof(*buff));
	if (buff == NULL)
	{
		write(2, "Error: malloc failed\n", _strlen("Error: malloc failed\n"));
		exit(EXIT_FAILURE);
	}
	while (len_read > 0)
		len_read = read(fd, buff, 1024);
	lines = count_lines(buff);
	copied_lines = malloc(sizeof(*copied_lines) * (lines + 2));
	if (!copied_lines)
		exit(EXIT_FAILURE);
	line = strtok(buff, "\n");
	while (line)
	{
		copied_lines[i] = line;
	    i++;
	    line = strtok(NULL, "\n");
	}
	copied_lines[i] = NULL;
	for(i = 0; copied_lines[i] != NULL; i++)
	{
		exec_array = linetoarray(copied_lines[i]);
		handling_function = getopcode_fun(exec_array[0]);
		if (!handling_function)
			exit(EXIT_FAILURE);
	}
	free(copied_lines);
	free(buff);
	close(fd);
	return (0);
}
