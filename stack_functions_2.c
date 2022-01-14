#include "monty.h"

/**
 * op_nop - Does nothing.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
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
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}

/**
 * op_sub - substract the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = ((*stack)->next)->n - (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}

/**
 * op_div - divides the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = ((*stack)->next)->n / (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}

/**
 * op_mul - multiplies the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = ((*stack)->next)->n * (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}
