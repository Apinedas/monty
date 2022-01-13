#include "monty.h"

/**
 * op_push - push action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	int value_to_add = 0;
	char *value;

	value = strtok(NULL, " ");
	if (string_is_int(value) == 0)
	{
		value_to_add = atoi(value);
		add_dnodeint(stack, value_to_add);
	}
	else
		exit(line_number);
}

/**
 * op_pall - pall action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	print_dlistint(*stack);
}
