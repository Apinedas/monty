#include "monty.h"

/**
 * op_push - push action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	int value_to_add = 0, isint;
	char *value;

	value = strtok(NULL, " ");
	isint = string_is_int(value);
	if (isint == 0)
	{
		value_to_add = atoi(value);
		add_dnodeint(stack, value_to_add);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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
