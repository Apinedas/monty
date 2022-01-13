#include "monty.h"

/**
 * op_nop - Does nothing.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
}

/**
 * op_add - adds the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
        delete_dnodeint_at_index(stack, 0);
	}
}
