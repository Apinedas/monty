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
	ret = malloc(sizeof(*ret) * words);
	if (!ret)
		return (NULL);
	replacetabs(line);
	act_word = strtok(line, " ");
	while(act_word)
	{
		ret[i] = act_word;
		i++;
		act_word = strtok(NULL, " ");
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
	char *buff, *line;
	int fd, len_read = 1;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Can't open file");
		perror(argv[1]);
		perror("\n");
		exit(EXIT_FAILURE);
	}
	buff = _calloc(1024, sizeof(*buff));
	if (buff == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (len_read > 0)
		len_read = read(fd, buff, 1024);
	line = strtok(buff, "\n");
	while (line)
	{
		printf("%s\n", line);
		line = strtok(NULL, "\n");
	}
	free(buff);
	close(fd);
	return (0);
}
