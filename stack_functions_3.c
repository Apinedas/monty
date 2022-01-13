#include "monty.h"

/**
 * op_mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = ((*stack)->next)->n % (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}
