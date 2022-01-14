#include "monty.h"

/**
 * main - main function for monty project
 * @argc: argument counter
 * @argv: argument vector
 * Return: always 0
 */

int main(int argc, char **argv)
{
	char buff[10000], *line, *copied_lines[10000], *exec_line = NULL;
	int fd;
	unsigned int i;
	void (*handling_function)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	initialize_buffer(buff, 10000);
	initialize_array(copied_lines, 10000);
	if (argc != 2)
		USAGE_ERROR;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		OPEN_ERROR(argv[1]);
	read(fd, buff, 10000);
	close(fd);
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
			INSTRUCTION_ERROR(i, exec_line, stack);
		handling_function(&stack, i);
	}
	if (stack)
		free_dlistint(stack);
	return (0);
}
