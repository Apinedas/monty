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
		free_dlistint(*stack);
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

/**
 * op_pchar - prints the value at the top of the
 * stack as a character, followed by a new line.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if (((*stack)->n) > 127 || ((*stack)->n) < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - prints stack as a string.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void op_pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	size_t lenght = 0;
	stack_t *aux;

	aux = *stack;
	while (aux)
	{
		if ((aux)->n > 0 && (aux)->n < 127)
		{
			printf("%c", (aux)->n);
			lenght++;
			aux = (aux)->next;
		}
		else
			break;
	}
	printf("\n");
}
