#include "monty.h"

/**
 * getopcode_fun - gets the function for a given opcode
 * @opcode: operation code to search
 * Return: Pointer to opcode function
 */

void (*getopcode_fun(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t made_opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
	};

	while (i <= 1)
	{
		if (_strcmp(made_opcodes[i].opcode, opcode) == 0)
			return (made_opcodes[i].f);
		i++;
	}
	return (NULL);
}
